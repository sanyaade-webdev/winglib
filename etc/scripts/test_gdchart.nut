
_self.load_module( "http", "" );
_self.load_module( "gdchart", "" );

class CGlobal
{
	quit = 0;
	server = 0;
};

local _g = CGlobal();

function OnServerEvent( server, data )
{

}

function OnProcessRequest( params ) : ( _g )
{
//	_g.quit = 1;

	local mParams = CSqMulti();
	mParams.deserialize( params );
	_self.echo( mParams[ "REQUEST" ][ "REMOTE_ADDR" ].str() + " : " + mParams[ "REQUEST" ][ "REQUEST_STRING" ].str() );

	local mReply = CSqMulti();

	local data = CSqMulti();
	data[ "0" ][ "title" ].set( "Set 0" );
	for ( local i = 0; i < 21; i++ )
		data[ "0" ][ "data" ][ format( "%04d", i ) ].set( ( ( i - 10 ) * ( i - 10 ) ).tostring() );

	local img = CSqImage();
	local gdc = CGdcChart();
	local inf = gdc.CreateChart( "png", "width=400,height=300,type=14", data.serialize(), img );
	if ( !inf.size() || !img.isValid() )
	{	mReply[ "content" ] <- "Error creating chart";
		return mReply.serialize();
	} // end if

	// Write the image to disk
//	CSqFile().put_contents( "w_raw_write.png", img.get( "img" ).str() );

	// Encode the image
	local enc = img.Encode( "png" );
	if ( !enc.getUsed() )
	{	mReply[ "content" ] <- "#err=Error encoding chart";
		return mReply.serialize();
	} // end if

	// Set global buffer
	local id = _self.unique();
	_self.set_binshare( id, enc );

	// Set image info
	mReply[ "binary" ] <- id;
	mReply[ "binary_type" ] <- "png";

	return mReply.serialize();
}

function _init() : ( _g )
{
	_g.server = CSqHttpServer();

	_g.server.SetSessionCallback( _self.queue(), "OnProcessRequest" );

	if ( !_g.server.Start( 1234 ) )
		_self.echo( "Unable to start http server" );
	else
		_self.echo( "server started on http://localhost:1234" );
}

function _idle() : ( _g )
{
//	_self.alert( "Waiting..." );

	return _g.quit;
}

