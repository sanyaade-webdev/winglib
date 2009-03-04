
// cell_connection.cpp

#include "stdafx.h"

CCellConnection::CCellConnection()
{	oexZeroMemory( &m_comm, sizeof( m_comm ) );
	oexZeroMemory( &m_tagsConfig, sizeof( m_tagsConfig ) );
	oexZeroMemory( &m_tagsDetails, sizeof( m_tagsDetails ) );
	m_comm.error = -1;
}

CCellConnection::CCellConnection( const CCellConnection &r )
{	CCellConnection();
}

int CCellConnection::Destroy()
{
	// Close the connection
	if ( m_comm.file_handle )
	{	closesocket( m_comm.file_handle );
		m_comm.file_handle = 0;
	} // end if

	m_comm.hostname = 0;
	m_comm.error = -1;
	m_sIp = "";

	// Lose the tag database
	ReleaseTags();

	return 1;
}

int CCellConnection::Connect( const sqbind::stdString &sIp, int nLoadTags )
{
	// Lose old connection
	Destroy();

	m_sIp = sIp;
	m_comm.hostname = (byte*)m_sIp.c_str();

	int m_nDebug = 0;
	establish_connection( &m_comm, &m_cServices.Obj(), m_nDebug );

	if ( m_comm.error != OK )
	{	SetLastError( oexT( "Unable to connect to device" ) );
		Destroy();
		return 0;
	} // end if

	m_path.device1 = -1;
	m_path.device2 = -1;
	m_path.device3 = -1;
	m_path.device4 = -1;
	m_path.device5 = -1;
	m_path.device6 = -1;
	m_path.device7 = -1;
	m_path.device8 = -1;

	int debug = 0;
	if ( get_backplane_data( &m_comm, &(_backplane_data&)m_cBackplane,
						     &(_rack&)m_cRack, &m_path, debug ) )
	{	SetLastError( oexT( "Failed to read backplane data" ) );
		return 0;
	} // end if

	// Find out who's active
	if ( who( &m_comm, &(_rack&)m_cRack, NULL, debug ) )
	{	SetLastError( oexT( "WHO failed" ) );
		return 0;
	} // end if

	m_path.device1 = 1;
	m_path.device2 = m_cRack.Obj().cpulocation;
	m_path.device3 = -1;
	m_path.device4 = -1;

	// Do we want to load the tags?
	if ( nLoadTags )
		LoadTags();

	return 1;
}

int CCellConnection::ReleaseTags()
{
	// Lose the tag map
	m_mapTags.clear();
/*
	for ( int i = 0; i < m_tagsConfig.count; i++ )
		if ( oexCHECK_PTR( m_tagsConfig.tag[ i ] ) )
			free( m_tagsConfig.tag[ i ] ),
			m_tagsConfig.tag[ i ] = 0;
*/

	// Lose the details tags
	for ( int i = 0; i < m_tagsDetails.count; i++ )
		if ( oexCHECK_PTR( m_tagsDetails.tag[ i ] ) )
			free( m_tagsDetails.tag[ i ] ),
			m_tagsDetails.tag[ i ] = 0;

	return 1;
}

int CCellConnection::LoadTags()
{
	int nStatus = 1;

	// Lose old tags
	ReleaseTags();

//	if ( get_object_config_list( &m_comm, &m_path, 0, &m_tagsConfig, 0 ) )
//		nStatus = 0, SetLastError( oexT( "get_object_config_list() failed" ) );

	// Get device tags
	if ( get_object_details_list( &m_comm, &m_path, 0, &m_tagsDetails, 0 ) )
		nStatus = 0, SetLastError( oexT( "get_object_details_list() failed" ) );
	else
		for ( int i = 0; i < m_tagsDetails.count; i++ )
			if ( !get_object_details( &m_comm, &m_path, m_tagsDetails.tag[ i ], 0 ) )
			{	m_mapTags[ (const char*)m_tagsDetails.tag[ i ]->name ] = m_tagsDetails.tag[ i ];
				m_mapSqTags.set( (const char*)m_tagsDetails.tag[ i ]->name, oexMks( i ).Ptr() );
			} // end if

	// Get program tags
	if ( get_program_list( &m_comm, &m_path, &m_prog_list, 0 ) )
		nStatus = 0, SetLastError( oexT( "get_program_list() failed" ) );

	else
	{
		// Sanity limit
		int nProgs = m_prog_list.count;
		if ( 0 < eMaxProgs && eMaxProgs < nProgs )
			nProgs = eMaxProgs;

		// Allocate memory for program tags
		if ( !m_tagsProgram.OexNew( nProgs ).Ptr() )
		{	SetLastError( oexT( "Out of Memory!" ) ); return 0; }

		// Initialize the memory
		m_tagsProgram.Zero();

		// for each program tag
		for ( int i = 0; i < nProgs; i++ )
		{
			// Get the program details
			if ( get_program_details( &m_comm, &m_path, m_prog_list.prog[ i ], 0 ) )
				nStatus = 0, SetLastError( oexT( "get_program_details() failed" ) );

			else
			{
				// Get program name
				for ( int j = 0; j < m_tagsDetails.count; j++ )
					if ( m_tagsDetails.tag[ j ]->linkid == m_prog_list.prog[ i ]->linkid )
					{	strcpy( (char*)m_prog_list.prog[ i ]->name, (char*)m_tagsDetails.tag[ j ]->name );
						j = m_tagsDetails.count;
					} // end if

				// Get program details
				if ( !get_object_details_list( &m_comm, &m_path, m_prog_list.prog[ i ]->base, &m_tagsProgram[ i ], 0 ) )
				{
					for ( int j = 0; j < m_tagsProgram[ i ].count; j++ )
					{
						if ( !get_object_details( &m_comm, &m_path, m_tagsProgram[ i ].tag[ j ], 0 ) )
						{
							oex::CStr sName = oexMks( (char*)m_prog_list.prog[ i ]->name,
													  oexT( "/" ),
													  (char*)m_tagsProgram[ i ].tag[ j ]->name );

							m_mapTags[ sName.Ptr() ] = m_tagsProgram[ i ].tag[ j ];
							m_mapSqTags.set( sName.Ptr(), oexMks( i, ".", j ).Ptr() );

						} // end if

					} // end for

				} // end if

			} // end else

		} // end for

	} // end else

	return 1;
}

int CCellConnection::IsConnected()
{	return OK == m_comm.error ? 1 : 0; }

#define CIP_PROGRAM 0x69
#define CIP_MAP 0x68
#define CIP_COUNTER 0x82
#define CIP_TIMER 0x83
#define CIP_PID 0x84
#define CIP_BOOL 0xc1
#define CIP_SINT 0xc2
#define CIP_INT 0xc3
#define CIP_DINT 0xc4
#define CIP_LINT 0xc5
#define CIP_USINT 0xc6
#define CIP_UINT 0xc7
#define CIP_UDINT 0xc8
#define CIP_ULINT 0xc9
#define CIP_REAL 0xca
#define CIP_LREAL 0xcb
#define CIP_STIME 0xcc
#define CIP_DATE 0xcd
#define CIP_TIME_OF_DAY 0xce
#define CIP_DATE_AND_TIME 0xcf
#define CIP_STRING 0xd0
#define CIP_BYTE 0xd1
#define CIP_WORD 0xd2
#define CIP_DWORD 0xd3
#define CIP_LWORD 0xd4
#define CIP_STRING2 0xd5
#define CIP_FTIME 0xd6
#define CIP_LTIME 0xd7
#define CIP_ITIME 0xd8
#define CIP_STRINGN 0xd9
#define CIP_SHORT_STRING 0xda
#define CIP_TIME 0xdb
#define CIP_EPATH 0xdc
#define CIP_ENGUNIT 0xdd


sqbind::stdString CCellConnection::GetTagTypeName( _tag_detail &td )
{
	sqbind::stdString sType;

	// Type
	switch( td.type & 0xff )
	{
		case CIP_PROGRAM		: sType += oexT( "PROGRAM" ); break;
		case CIP_MAP 			: sType += oexT( "MAP" ); break;
		case CIP_COUNTER	 	: sType += oexT( "COUNTER" ); break;
		case CIP_TIMER 			: sType += oexT( "TIMER" ); break;
		case CIP_BOOL 			: sType += oexT( "BOOL" ); break;
		case CIP_SINT 			: sType += oexT( "SINT" ); break;
		case CIP_INT 			: sType += oexT( "INT" ); break;
		case CIP_DINT 			: sType += oexT( "DINT" ); break;
		case CIP_LINT 			: sType += oexT( "LINT" ); break;
		case CIP_USINT			: sType += oexT( "USINT" ); break;
		case CIP_UINT			: sType += oexT( "UINT" ); break;
		case CIP_UDINT			: sType += oexT( "UDINT" ); break;
		case CIP_ULINT			: sType += oexT( "ULINT" ); break;
		case CIP_REAL			: sType += oexT( "REAL" ); break;
		case CIP_LREAL			: sType += oexT( "LREAL" ); break;
		case CIP_STIME			: sType += oexT( "STIME" ); break;
		case CIP_DATE			: sType += oexT( "DATE" ); break;
		case CIP_TIME_OF_DAY	: sType += oexT( "TIME_OF_DAY" ); break;
		case CIP_DATE_AND_TIME	: sType += oexT( "DATE_AND_TIME" ); break;
		case CIP_STRING			: sType += oexT( "STRING" ); break;
		case CIP_BYTE			: sType += oexT( "BYTE" ); break;
		case CIP_WORD			: sType += oexT( "WORD" ); break;
		case CIP_DWORD			: sType += oexT( "DWORD" ); break;
		case CIP_LWORD			: sType += oexT( "LWORD" ); break;
		case CIP_STRING2		: sType += oexT( "STRING2" ); break;
		case CIP_FTIME			: sType += oexT( "FTIME" ); break;
		case CIP_LTIME			: sType += oexT( "LTIME" ); break;
		case CIP_ITIME			: sType += oexT( "ITIME" ); break;
		case CIP_STRINGN		: sType += oexT( "STRINGN" ); break;
		case CIP_SHORT_STRING	: sType += oexT( "SHORT_STRING" ); break;
		case CIP_TIME			: sType += oexT( "TIME" ); break;
		case CIP_EPATH			: sType += oexT( "EPATH" ); break;
		case CIP_ENGUNIT		: sType += oexT( "ENGUNIT" ); break;

		default :
			sType += oexT( "" );
			break;

	} // end switch

	return sType;
}

#pragma pack( push, 1 )
struct SStructHeaderItem
{	unsigned short 		type;
	unsigned short		info;
	unsigned long		offset;
};
#pragma pack( pop )

oex::oexBOOL CCellConnection::GetStructValue( _tag_detail &td, sqbind::stdString &sRet )
{
	// Make sure it is a structure
	if ( 0 == ( td.type & 0x8000 ) )
		return oex::oexFALSE;

	// Punt if no data
	if ( !td.datalen || !oexCHECK_PTR( td.data ) )
		return oex::oexFALSE;

	// Get number of dimensions
	int nD = ( td.type & 0x6000 ) >> 13;
	int szA[] = { td.arraysize1, td.arraysize2, td.arraysize3 };

	for ( int b = 0; b < td.datalen; b++ )
	{
		if ( b && !( b & 0x0f ) ) sRet += oexT( "<br>" ), sRet += oexNL;

		sRet += oexFmt( oexT( "%02lX " ), td.data[ b ] ).Ptr();

	} // end for

	return oex::oexTRUE;
}

oex::oexBOOL CCellConnection::GetTagValue( _tag_detail &td, sqbind::stdString &sRet )
{
	// Ensure valid data
	if ( !td.datalen || !oexCHECK_PTR( td.data ) )
		return oex::oexFALSE;

	// Is it a structure?
	if ( td.type & 0x8000 )
		return GetStructValue( td, sRet );

	// Dimensions
//	int nD = ( td.type & 0x6000 ) >> 13;
//	if ( nD )
//		sType += oexMks( nD, oexT( ":" ) ).Ptr();

	int count = td.arraysize1;
	int len = td.size ? td.size : td.datalen;
	char *ptr = (char*)td.data;

	// Ensure there is enough data for the specs
	if ( count && ( count * len ) > td.datalen )
		return oex::oexFALSE;

	do
	{
		switch( td.type & 0xff )
		{
			case 0xc1 :
				if ( 1 > len )
					return oex::oexFALSE;
				sRet += oexMks( (int)( *( (char*)ptr ) ? 1 : 0 ) ).Ptr();
				break;

			case 0xc2 :
				if ( 1 > len )
					return oex::oexFALSE;
				sRet += oexMks( (int)( *( (char*)ptr ) ) ).Ptr();
				break;

			case 0xc3 :
				if ( 2 > len )
					return oex::oexFALSE;
				sRet += oexMks( (int)( *( (short*)ptr ) ) ).Ptr();
				break;

			case 0xc4 :
				if ( 4 > len )
					return oex::oexFALSE;
				sRet += oexMks( (int)( *( (long*)ptr ) ) ).Ptr();
				break;

			case 0xca :
				if ( 4 > len )
					return oex::oexFALSE;
				sRet += oexMks( (float)( *( (float*)ptr ) ) ).Ptr();
				break;

			case 0xd3 :
				if ( 4 > len )
					return oex::oexFALSE;
				sRet += oexMks( (unsigned int)( *( (unsigned long*)ptr ) ) ).Ptr();
				break;

			default :

				for ( int b = 0; b < td.datalen; b++ )
				{	if ( b && !( b & 0x0f ) ) sRet += oexT( "<br>" ), sRet += oexNL;
					sRet += oexFmt( oexT( "%02lX " ), td.data[ b ] ).Ptr();
				} // end for

//				return oex::oexFALSE;
				break;

		} // end switch

		if ( 1 < count )
			sRet += oexT( "," );

		// Next element
		ptr += td.size;

	} while ( 0 < --count );

	return oex::oexTRUE;
}

sqbind::CSqMap CCellConnection::TagToMap( _tag_detail *pTd )
{
	if ( !oexCHECK_PTR( pTd ) )
		return sqbind::CSqMap();

	sqbind::CSqMap mRet;
	mRet.set( oexT( "topbase" ), 		oexMks( (unsigned int)pTd->topbase ).Ptr() );
	mRet.set( oexT( "base" ), 			oexMks( (unsigned int)pTd->base ).Ptr() );
	mRet.set( oexT( "id" ), 			oexMks( (unsigned int)pTd->id ).Ptr() );
	mRet.set( oexT( "linkid" ), 		oexMks( (unsigned int)pTd->linkid ).Ptr() );
	mRet.set( oexT( "type" ), 			oexMks( (unsigned int)( pTd->type & 0x0fff ) ).Ptr() );
	mRet.set( oexT( "dim" ),			oexMks( (unsigned int)( ( pTd->type & 0x6000 ) >> 13 ) ).Ptr() );
	mRet.set( oexT( "struct" ),			oexMks( (unsigned int)( ( pTd->type & 0x8000 ) ? 1 : 0 ) ).Ptr() );
	mRet.set( oexT( "items" ), 			oexMks( (unsigned int)pTd->size ).Ptr() );
	mRet.set( oexT( "memory" ), 		oexMks( (unsigned int)pTd->memory ).Ptr() );
	mRet.set( oexT( "displaytype" ), 	oexMks( (unsigned int)pTd->displaytype ).Ptr() );
	mRet.set( oexT( "name" ), 			oexMbToStrPtr( (const char*)pTd->name ) );
	mRet.set( oexT( "a1_size" ), 		oexMks( (unsigned int)pTd->arraysize1 ).Ptr() );
	mRet.set( oexT( "a2_size" ), 		oexMks( (unsigned int)pTd->arraysize2 ).Ptr() );
	mRet.set( oexT( "a3_size" ),	 	oexMks( (unsigned int)pTd->arraysize3 ).Ptr() );

	mRet.set( oexT( "type_name" ), 		GetTagTypeName( *pTd ).c_str() );

	sqbind::stdString sVal;
	if ( GetTagValue( *pTd, sVal ) )
		mRet.set( oexT( "value" ), 		sVal.c_str() );

	return mRet;
}

sqbind::CSqMap CCellConnection::ReadTag( const sqbind::stdString &sTag )
{
	// Must be connected
	if ( m_comm.error != OK )
		return SetLastError( oexT( "err=Not connected" ) );

	// Ensure we have such a tag
	if ( !m_mapSqTags.isset( sTag ) )
		return SetLastError( oexT( "err=Tag not found" ) );

	int nT, nP;
	oex::CStr sT = m_mapSqTags[ sTag ].c_str();
	oex::CStr sP = sT.Parse( oexT( "." ) );
	if ( *sT == oexT( '.' ) )
		sT++, nP = sP.ToLong();
	else
		nP = -1;
	nT = sT.ToLong();

	// Validate program index
	if ( 0 <= nP && ( nP >= m_prog_list.count || nP >= m_tagsProgram.Size() ) )
		return SetLastError( oexMks( oexT( "err=Invalid program index " ), nP ).Ptr() );

	_tag_data *pTd = &m_tagsDetails;
	if ( 0 <= nP )
		pTd = &m_tagsProgram[ nP ];

	if ( 0 > nT || nT >= pTd->count )
		return SetLastError( oexMks( oexT( "err=Invalid tag index " ), nT ).Ptr() );

	// Get object details
	if ( 0 > read_object_value( &m_comm, &m_path, pTd->tag[ nT ], 0 ) )
		return SetLastError( oexT( "err=read_object_value() failed" ) );

	return TagToMap( pTd->tag[ nT ] );
}

sqbind::stdString CCellConnection::GetBackplaneData()
{
	oex::CStr ret;

	LoadTags();

	return ret.Ptr();


/*
	int debug = 0;

	if ( m_comm.error != OK )
		return SetLastError( oexT( "Not connected" ) );

	// Refresh tags
	LoadTags();

	oex::CStr ret;

	ret << oexNL << oexT( "--- Backplane Data ---" ) << oexNL;
	ret <<         oexT( "RX_Bad_m       : " )			<< m_cBackplane.Obj().rx_bad_m 			<< oexNL;
	ret <<         oexT( "ERR+Threshold  : " ) 			<< m_cBackplane.Obj().err_threshold 	<< oexNL;
	ret <<         oexT( "RX_Bad_CRC     : " )			<< m_cBackplane.Obj().rx_bad_crc 		<< oexNL;
	ret <<         oexT( "RX_Bus_Timeout : " ) 			<< m_cBackplane.Obj().rx_bus_timeout 	<< oexNL;
	ret <<         oexT( "TX_Retry       : " )			<< m_cBackplane.Obj().tx_retry 			<< oexNL;
	ret << oexFmt( oexT( "Status         : %X" ), 		   m_cBackplane.Obj().status )	 		<< oexNL;
	ret << oexFmt( oexT( "Address        : %04X" ), 	   m_cBackplane.Obj().address ) 		<< oexNL;
	ret <<         oexT( "Major Rev      : " ) 			<< m_cBackplane.Obj().rev_major 		<< oexNL;
	ret <<         oexT( "Minor Rev      : " ) 			<< m_cBackplane.Obj().rev_minor 		<< oexNL;
	ret << oexFmt( oexT( "Serial #       : %08lX" ),	   m_cBackplane.Obj().serial_number )	<< oexNL;
	ret <<         oexT( "Backplane size : " ) 			<< m_cBackplane.Obj().rack_size 		<< oexNL;
	ret << oexNL;

	ret << oexNL << oexT( "--- Rack Data ---" ) << oexNL;
	for ( int i = 0; i < m_cBackplane.Obj().rack_size; i++ )
	{
		ret << oexNL;
		ret <<		   oexT( "Rack        : " )			<< i << oexNL;
		ret <<		   oexT( "ID          : " )			<< m_cRack.Obj().identity[ i ]->ID						<< oexNL;
		ret <<		   oexT( "Type        : " )			<< ( ( 32 > m_cRack.Obj().identity[ i ]->type )
													     ? oexMks( PROFILE_Names[ m_cRack.Obj().identity[ i ]->type ] )
													     : oexMks( m_cRack.Obj().identity[ i ]->type ) ) << oexNL;
		ret <<		   oexT( "ProductCode : " )			<< m_cRack.Obj().identity[ i ]->product_code << oexNL;
		ret <<		   oexT( "Revision    : " )			<< m_cRack.Obj().identity[ i ]->rev_lo << oexNL;
		ret << oexFmt( oexT( "Status      : %X" ), 	       m_cRack.Obj().identity[ i ]->status )	<< oexNL;
		ret << oexFmt( oexT( "Serial #    : %08lX" ), 	   m_cRack.Obj().identity[ i ]->serial )	<< oexNL;
		ret << oexNL;

	} // end for

	int nTags = m_tagsDetails.count;
	if ( nTags < m_tagsConfig.count )
		nTags = m_tagsConfig.count;

	ret << oexNL << oexT( "--- Tags ---" ) << oexNL;
	ret << oexT( "Tags Found : " ) << nTags << oexNL;

	int c1 = 0, c68 = 0, c69 = 0;
	for ( int i = 0; i < nTags; i++ )
	{
		if ( i < m_tagsDetails.count )
		{
			if ( get_object_details( &m_comm, &m_path, m_tagsDetails.tag[ i ], debug ) )
				ret << oexT( "get_object_details() failed for tag " ) << i << oexNL;

			if ( i < m_tagsConfig.count )
				if ( get_object_config( &m_comm, &m_path, m_tagsConfig.tag[ i ], debug ) )
					ret << oexT( "get_object_config() failed for tag " ) << i << oexNL;

			switch ( m_tagsDetails.tag[ i ]->type & 255 )
			{
				case 0x68 :
					c68++;
					break;

				case 0x69 :
					c69++;
					break;

				default :

					if ( 0 > read_object_value( &m_comm, &m_path, m_tagsDetails.tag[ i ], debug ) )
						ret << oexT( "read_object_value() failed for tag " ) << i << oexNL;

					ret << oexNL << oexT( "Device Tag " ) << i << oexNL;

					if ( i < m_tagsConfig.count && oexCHECK_PTR( m_tagsConfig.tag ) )
					{
						ret << oexT( "--- Config ---" ) << oexNL;
						ret << oexFmt( oexT( "Top Base     : %08lX" ),	m_tagsDetails.tag[ i ]->topbase ) << oexNL;
						ret << oexFmt( oexT( "Base         : %08lX" ),	m_tagsDetails.tag[ i ]->base ) << oexNL;
						ret << oexFmt( oexT( "Link ID      : %08lX" ),	m_tagsDetails.tag[ i ]->linkid ) << oexNL;
						ret << oexFmt( oexT( "Type         : %04lX" ),	m_tagsDetails.tag[ i ]->type ) << oexNL;
					} // end if

					if ( i < m_tagsDetails.count && oexCHECK_PTR( m_tagsDetails.tag ) )
					{
						ret << oexNL << oexT( "--- Details ---" ) << oexNL;
						ret << oexFmt( oexT( "Top Base     : %08lX" ),	m_tagsDetails.tag[ i ]->topbase ) << oexNL;
						ret << oexFmt( oexT( "Base         : %08lX" ),	m_tagsDetails.tag[ i ]->base ) << oexNL;
						ret << oexFmt( oexT( "ID           : %08lX" ),	m_tagsDetails.tag[ i ]->id ) << oexNL;
						ret << oexFmt( oexT( "Link ID      : %08lX" ),	m_tagsDetails.tag[ i ]->linkid ) << oexNL;
						ret << oexFmt( oexT( "Type         : %04lX" ),	m_tagsDetails.tag[ i ]->type ) << oexNL;
						ret << oexFmt( oexT( "Size         : %04lX" ),	m_tagsDetails.tag[ i ]->size ) << oexNL;
						ret << 	       oexT( "Data Length  : " ) 		<< m_tagsDetails.tag[ i ]->datalen << oexNL;
						ret << oexFmt( oexT( "Memory       : %08lX" ),	m_tagsDetails.tag[ i ]->memory ) << oexNL;
						ret << oexFmt( oexT( "Display      : %04lX" ),	m_tagsDetails.tag[ i ]->displaytype ) << oexNL;
						ret <<         oexT( "Name         : " ) 		<< (const char*)m_tagsDetails.tag[ i ]->name << oexNL;
						ret <<         oexT( "Type Name    : " ) 		<< GetTagTypeName( *m_tagsDetails.tag[ i ] ).c_str() << oexNL;
						sqbind::stdString sVal;
						if ( GetTagValue( *m_tagsDetails.tag[ i ], sVal ) )
							ret <<     oexT( "Value        : " ) 		<< sVal.c_str() << oexNL;
						ret <<         oexT( "ArraySize1   : " ) 		<< (int)m_tagsDetails.tag[ i ]->arraysize1 << oexNL;
						ret <<         oexT( "ArraySize2   : " ) 		<< (int)m_tagsDetails.tag[ i ]->arraysize2 << oexNL;
						ret <<         oexT( "ArraySize3   : " ) 		<< (int)m_tagsDetails.tag[ i ]->arraysize3 << oexNL;

						if ( m_tagsDetails.tag[ i ]->datalen && oexCHECK_PTR( m_tagsDetails.tag[ i ]->data ) )
							for ( int b = 0; b < m_tagsDetails.tag[ i ]->datalen; b++ )
							{	if ( b && !( b & 0x0f ) ) ret << oexNL;
								ret << oexFmt( oexT( "%02lX " ), m_tagsDetails.tag[ i ]->data[ b ] );
							} // end for

						ret << oexNL;

					} // end if

					break;

			} // end switch

		} // end if

	} // end for

	ret << oexNL << oexT( "--- Programs ---" ) << oexNL;
	ret << oexT( "Programs found : " ) << m_prog_list.count << oexNL;

	for ( int i = 0; i < m_prog_list.count; i++ )
	{
		ret << oexNL;
		ret << oexT( "--- Program " ) << i << oexT( " ---" ) << oexNL;
		ret << oexFmt( 				oexT( "Base      : %08lX" ),	m_prog_list.prog[ i ]->base ) << oexNL;

		if ( !get_program_details( &m_comm, &m_path, m_prog_list.prog[ i ], debug ) )
		{
			ret << oexFmt( 			oexT( "Link ID   : %08lX" ),	m_prog_list.prog[ i ]->linkid ) << oexNL;
			for ( int j = 0; j < m_tagsDetails.count; j++ )
				if ( m_tagsDetails.tag[ j ]->linkid == m_prog_list.prog[ i ]->linkid )
				{
					strcpy( (char*)m_prog_list.prog[ i ]->name, (char*)m_tagsDetails.tag[ j ]->name );
					ret << 			oexT( "Name      : " ) 			<< (const char*)m_tagsDetails.tag[ j ]->name << oexNL;

				} // end if

			_oexTRY
			{
				_tag_data td;
				oexZeroMemory( &td, sizeof( td ) );
				if ( !get_object_details_list( &m_comm, &m_path, m_prog_list.prog[ i ]->base, &td, debug ) )
				{
					ret << oexNL;
					ret <<                  oexT( "Program Tags : " ) <<       td.count << oexNL;
					ret << oexNL;

					for ( int j = 0; j < td.count; j++ )
					{
						ret << oexT( "Program Tag " ) << j << oexNL;
						ret << 		oexFmt( oexT( "Base         : %08lX" ),	   td.tag[ j ]->base ) << oexNL;
						ret << 		oexFmt( oexT( "ID           : %08lX" ),	   td.tag[ j ]->id ) << oexNL;

						if ( !get_object_details( &m_comm, &m_path, td.tag[ j ], debug ) )
						{
							if ( 0 > read_object_value( &m_comm, &m_path, td.tag[ j ], debug ) )
								ret << oexT( "read_object_value() failed for tag " ) << j << oexNL;

							ret << 	        oexT( "Name         : " ) 		<< (const char*)td.tag[ j ]->name << oexNL;
							ret << oexFmt(  oexT( "Type         : %04lX" ),	   td.tag[ j ]->type ) << oexNL;
							ret << 	        oexT( "Size         : " ) 		<< td.tag[ j ]->size << oexNL;
							ret << 	        oexT( "Data Length  : " ) 		<< td.tag[ j ]->datalen << oexNL;
							ret <<          oexT( "Type Name    : " ) 		<< GetTagTypeName( *td.tag[ j ] ).c_str() << oexNL;
							sqbind::stdString sVal;
							if ( GetTagValue( *td.tag[ j ], sVal ) )
								ret <<      oexT( "Value        : " ) 		<< sVal.c_str() << oexNL;
							ret << 	        oexT( "ArraySize11  : " ) 		<< (int)td.tag[ j ]->arraysize1 << oexNL;
							ret << 	        oexT( "ArraySize12  : " ) 		<< (int)td.tag[ j ]->arraysize2 << oexNL;
							ret << 	        oexT( "ArraySize13  : " ) 		<< (int)td.tag[ j ]->arraysize3 << oexNL;

							if ( td.tag[ j ]->datalen && oexCHECK_PTR( td.tag[ j ]->data ) )
							{	for ( int b = 0; b < td.tag[ j ]->datalen; b++ )
								{	if ( b && !( b & 0x0f ) ) ret << oexNL;
									ret << oexFmt( oexT( "%02lX " ), td.tag[ j ]->data[ b ] );
								} // end for
								ret << oexNL;
							} // end if

						} // end if

						// Free tag mem
						free( td.tag[ j ] );

						ret << oexNL;

					} // end for

				} // end if
				else
					ret << oexT( "!!! No Tags !!! " ) << oexNL;

			} // end try

			_oexCATCH( ... )
			{
				ret << oexMks( oexT( "!!! Assert on tag " ), (const char*)m_prog_list.prog[ i ]->name, oexNL );

			} // end catch

		} // end if

		ret << oexNL;

	} // end for

	return ret.Ptr();
*/
}
