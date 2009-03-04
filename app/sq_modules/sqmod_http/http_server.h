// http_server.h

#pragma once

class CHttpServerImpl
{
public:

	CHttpServerImpl()
	{
		m_pMsgQueue = oexNULL;
	}

	void SetCallback( sqbind::CSqMsgQueue *x_pMsgQueue, const sqbind::stdString &sServer, const sqbind::stdString &sSession );

	virtual int Start( int nPort );

	/// Server callback
	static oex::oexINT _OnServerEvent( oex::oexPVOID x_pData, oex::oexINT x_nEvent, oex::oexINT x_nErr,
								       oex::THttpServer< oex::os::CIpSocket, oex::THttpSession< oex::os::CIpSocket > > *x_pServer );
	oex::oexINT OnServerEvent( oex::oexPVOID x_pData, oex::oexINT x_nEvent, oex::oexINT x_nErr,
						       oex::THttpServer< oex::os::CIpSocket, oex::THttpSession< oex::os::CIpSocket > > *x_pServer );

	/// Session callback
	static oex::oexINT _OnSessionCallback( oex::oexPVOID x_pData, oex::THttpSession< oex::os::CIpSocket > *x_pSession );
	oex::oexINT OnSessionCallback( oex::oexPVOID x_pData, oex::THttpSession< oex::os::CIpSocket > *x_pSession );

private:

	// The server
	oex::THttpServer< oex::os::CIpSocket, oex::THttpSession< oex::os::CIpSocket > > m_server;

	// Callback
	sqbind::CSqMsgQueue		*m_pMsgQueue;

	// Server callback function
	sqbind::stdString		m_sServer;

	// Session callback function
	sqbind::stdString		m_sSession;
};

class CHttpServer
{
public:

	CHttpServer()
	{
		m_pServer = oexNULL;
		Init();
	}

	~CHttpServer()
	{
		if ( m_pServer )
		{	
			OexAllocDelete( m_pServer );
//			delete m_pServer;
			m_pServer = oexNULL;
		} // end if
	}

	void Init()
	{	if ( !m_pServer )
			m_pServer = OexAllocConstruct< CHttpServerImpl >();
//			m_pServer = new CHttpServerImpl();
	}

	void SetCallback( sqbind::CSqMsgQueue *x_pMsgQueue, const sqbind::stdString &sServer, const sqbind::stdString &sSession )
	{
		m_pServer->SetCallback( x_pMsgQueue, sServer, sSession );
	}

	int Start( int nPort )
	{
		return m_pServer->Start( nPort );
	}

private:

	/// Pointer to server object
	CHttpServerImpl		*m_pServer;

};