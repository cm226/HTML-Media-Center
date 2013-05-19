#include "stdafx.h"
#include "../MediaImages/ImageGetters/Music/MusicMissingImageContentFinder.h"
#include "../../JARVISCoreModules/CoreModules/config.h"
#include "../../JARVISCoreModules/CoreModules/Database/Database.h"

BOOST_AUTO_TEST_CASE(MusicImagecontentGetterconstructor)
{
	BOOST_CHECK_NO_THROW(imagegetters::music::MusicMissingImageContentFinder contentFinder());
}

BOOST_AUTO_TEST_CASE(ArtistThumbnailTests)
{

	DatabaseTables::Database dbConn;
	BOOST_CHECK_EQUAL(dbConn.Connect(DATABSEUSER,DATABASEPASSWORD,"mediaServerTests",""),true);

	imagegetters::music::MusicMissingImageContentFinder contentFinder(&dbConn);
	std::string artistName; 
	int artistID;
	bool someLeft = false;

	contentFinder.setImageContentURL(std::string(HTMLMEDIAROOT).append("\\JARVIS\\TestDataFolder\\ImageContentTests\\Music\\Artists"));
	someLeft = contentFinder.searchDBforMissingArtistThumbImage(artistName,artistID);

	bool isCorrect = false;
	if(artistName.compare("testArtist2") == 0 && artistID==2) isCorrect = true;
	else if (artistName.compare("testArtist1") == 0 && artistID==1) isCorrect = true;

	BOOST_CHECK_EQUAL(isCorrect, true);
	BOOST_CHECK_EQUAL(someLeft,true);

	contentFinder.setImageContentURL(std::string(HTMLMEDIAROOT).append("\\JARVIS\\TestDataFolder\\ImageContentTests1\\Music\\Artists"));
	someLeft = contentFinder.searchDBforMissingArtistThumbImage(artistName,artistID);

	BOOST_CHECK_EQUAL(artistName.compare("testArtist2"), 0);
	BOOST_CHECK_EQUAL(artistID, 2);
	BOOST_CHECK_EQUAL(someLeft,true);

	contentFinder.setImageContentURL(std::string(HTMLMEDIAROOT).append("\\JARVIS\\TestDataFolder\\ImageContentTests2\\Music\\Artists"));
	someLeft = contentFinder.searchDBforMissingArtistThumbImage(artistName,artistID);

	BOOST_CHECK_EQUAL(someLeft,false);

}


BOOST_AUTO_TEST_CASE(ArtistTests)
{

}

BOOST_AUTO_TEST_CASE(AlbumTests)
{

}



