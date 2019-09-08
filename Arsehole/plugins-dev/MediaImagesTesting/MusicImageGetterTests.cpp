#include "stdafx.h"

#include "../MediaImages/ImageGetters/Music/MusicImageGetter.h"
#include "../../ArseholeCoreModules/CoreModules/config.h"
#include "../../ArseholeCoreModules/CoreModules/Database/Database.h"
#include "../MediaImages/MediaImagesPlugin.h"


#include <boost/regex.hpp>


BOOST_AUTO_TEST_CASE(MusicImageGetterArtistThumbnail)
{
	
	DatabaseTables::Database* dbConn = new DatabaseTables::Database();
	BOOST_CHECK_EQUAL(dbConn->Connect(DATABSEUSER,DATABASEPASSWORD,"mediaServerTests","localhost"),true);
	CoreModules* cm = new CoreModules(dbConn);
	Page p;
	PageCallbackContext context;
	
	MediaImagesPlugin mip(cm);
	MusicImageGetter imgGetter(cm);
	imgGetter.registerFunctions(&mip);

	BOOST_CHECK_EQUAL(imgGetter.handleMusicSelected(&p,&context),true);

	std::string page;

	boost::regex expression("<div id=\"header\">Artist Thumbnail Image for: testArtist[0-9]</div>\
<div id=\"imageResultList\">\
<img id=\"img\" src=\".*\" onClick=\"window\\.location='\\.\\./\\.\\./pluginInteraction/7/Media Images/0/1'\" style=\"height:100px;width:100px;\"></img>\
<img id=\"img\" src=\".*\" onClick=\"window\\.location='\\.\\./\\.\\./pluginInteraction/7/Media Images/1/1'\" style=\"height:100px;width:100px;\"></img>\
<img id=\"img\" src=\".*\" onClick=\"window\\.location='\\.\\./\\.\\./pluginInteraction/7/Media Images/2/1'\" style=\"height:100px;width:100px;\"></img>\
<img id=\"img\" src=\".*\" onClick=\"window\\.location='\\.\\./\\.\\./pluginInteraction/7/Media Images/3/1'\" style=\"height:100px;width:100px;\"></img>\
</div>");


	p.buildPage(&page);

	BOOST_CHECK_EQUAL(boost::regex_match(page,expression), true);
	p.freePage();

	delete cm;

}

BOOST_AUTO_TEST_CASE(MusicImageGetterArtistThumbnailNoCallbacksRegistered)
{

	DatabaseTables::Database* dbConn = new DatabaseTables::Database();
	BOOST_CHECK_EQUAL(dbConn->Connect(DATABSEUSER,DATABASEPASSWORD,"mediaServerTests","localhost"),true);
	CoreModules* cm = new CoreModules(dbConn);
	Page p;
	PageCallbackContext context;
	
	MusicImageGetter imgGetter(cm);
	BOOST_CHECK_EQUAL(imgGetter.handleMusicSelected(&p,&context),false);

	p.freePage();

	delete cm;


}



BOOST_AUTO_TEST_CASE(MusicImageGetterArtistImageTest)
{
	

}