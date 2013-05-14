#include "stdafx.h"
#include <boost/filesystem.hpp>

#include "../../JARVISCoreModules/CoreModules/Comms/CURL/CurlManager.h"
#include "../../JARVISCoreModules/CoreModules/Comms/JSON/JSONCURLRequest.h"


BOOST_AUTO_TEST_CASE(CURLManagerConstructorTests)
{

	BOOST_CHECK_NO_THROW(CommsNS::CurlManager curlMan());
}


BOOST_AUTO_TEST_CASE(CURLManagerMakeRequestTests)
{
	CommsNS::CurlManager curlMan;
	CommsNS::CurlReqImp curlRequest("http://ajax.googleapis.com/ajax/services/search/images?v=1.0&q=monkey");
	std::string responce;

	curlMan.makeJASONRequest(curlRequest,responce);
	unsigned numOfResults = 0;
	unsigned lastFoundPos = responce.find("{\"GsearchResultClass\"");
	while(lastFoundPos != std::string::npos)
	{
		numOfResults++;
		lastFoundPos = responce.find("{\"GsearchResultClass\"",lastFoundPos+1);
	}

	BOOST_CHECK_EQUAL(numOfResults,4);
	
}


BOOST_AUTO_TEST_CASE(downloadFileTest)
{
	CommsNS::CurlManager curlMan;
	
	bool worked = curlMan.downloadItemToFile("http://g-ecx.images-amazon.com/images/G/02/gno/beacon/BeaconSprite-UK-02._V397961423_.png","C:\\wamp\\www\\HTML-Media-Center\\JARVIS\\JARVIS\\test.png");
	
	BOOST_CHECK_EQUAL(true,worked);
	BOOST_CHECK_EQUAL(true,boost::filesystem::exists( "C:\\wamp\\www\\HTML-Media-Center\\JARVIS\\JARVIS\\test.png "));
	BOOST_CHECK_EQUAL(true,boost::filesystem::remove("C:\\wamp\\www\\HTML-Media-Center\\JARVIS\\JARVIS\\test.png "));

}


BOOST_AUTO_TEST_CASE(downloadToFileThatExsists)
{
	CommsNS::CurlManager curlMan;
	
	bool worked = curlMan.downloadItemToFile("http://g-ecx.images-amazon.com/images/G/02/gno/beacon/BeaconSprite-UK-02._V397961423_.png","C:\\wamp\\www\\HTML-Media-Center\\JARVIS\\TestDataFolder\\ExistingImage\\test.png");
	
	BOOST_CHECK_EQUAL(true,worked);
	BOOST_CHECK_EQUAL(true,boost::filesystem::exists( "C:\\wamp\\www\\HTML-Media-Center\\JARVIS\\TestDataFolder\\ExistingImage\\test.png"));

}

BOOST_AUTO_TEST_CASE(downloadToBadPath)
{
	CommsNS::CurlManager curlMan;
	
	bool worked = curlMan.downloadItemToFile("http://g-ecx.images-amazon.com/images/G/02/gno/beacon/BeaconSprite-UK-02._V397961423_.png","C:\\C:\\");
	
	BOOST_CHECK_EQUAL(false,worked);

}

BOOST_AUTO_TEST_CASE(downloadFileTestInvalidFile)
{
	CommsNS::CurlManager curlMan;
	
	bool worked = curlMan.downloadItemToFile("invalidLink","C:\\wamp\\www\\HTML-Media-Center\\JARVIS\\JARVIS\\test.png");
	
	BOOST_CHECK_EQUAL(true,worked);
	BOOST_CHECK_EQUAL(true,boost::filesystem::exists( "C:\\wamp\\www\\HTML-Media-Center\\JARVIS\\JARVIS\\test.png "));

}
