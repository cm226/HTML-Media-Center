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
	BOOST_CHECK_EQUAL(dbConn.Connect(DATABSEUSER,DATABASEPASSWORD,"mediaServerTests","localhost"),true);

	imagegetters::music::MusicMissingImageContentFinder contentFinder(&dbConn);
	std::string artistName; 
	int artistID;
	bool isMissingContent = false;

	contentFinder.setImageContentURL(std::string(HTMLMEDIAROOT).append("\\JARVIS\\TestDF\\ICT\\Music"));
	isMissingContent = contentFinder.searchDBforMissingArtistThumbImage(artistName,artistID);

	bool isCorrect = false;
	if(artistName.compare("testArtist2") == 0 && artistID==2) isCorrect = true;
	else if (artistName.compare("testArtist1") == 0 && artistID==1) isCorrect = true;

	BOOST_CHECK_EQUAL(isCorrect, true);
	BOOST_CHECK_EQUAL(isMissingContent,true);

	contentFinder.setImageContentURL(std::string(HTMLMEDIAROOT).append("\\JARVIS\\TestDF\\ICT2\\Music"));
	isMissingContent = contentFinder.searchDBforMissingArtistThumbImage(artistName,artistID);

	BOOST_CHECK_EQUAL(artistName.compare("testArtist2"), 0);
	BOOST_CHECK_EQUAL(artistID, 2);
	BOOST_CHECK_EQUAL(isMissingContent,true);

	contentFinder.setImageContentURL(std::string(HTMLMEDIAROOT).append("\\JARVIS\\TestDF\\ICT3\\Music"));
	isMissingContent = contentFinder.searchDBforMissingArtistThumbImage(artistName,artistID);

	BOOST_CHECK_EQUAL(isMissingContent,false);

}


BOOST_AUTO_TEST_CASE(ArtistImageTests)
{
	DatabaseTables::Database dbConn;
	BOOST_CHECK_EQUAL(dbConn.Connect(DATABSEUSER,DATABASEPASSWORD,"mediaServerTests","localhost"),true);

	imagegetters::music::MusicMissingImageContentFinder contentFinder(&dbConn);
	std::string artistName; 
	int artistID;
	bool isMissingContent = false;

	contentFinder.setImageContentURL(std::string(HTMLMEDIAROOT).append("\\JARVIS\\TestDF\\ICT\\Music"));
	isMissingContent = contentFinder.searchDBforMissingArtistImage(artistName,artistID);

	bool isCorrect = false;
	if(artistName.compare("testArtist2") == 0 && artistID==2) isCorrect = true;
	else if (artistName.compare("testArtist1") == 0 && artistID==1) isCorrect = true;

	BOOST_CHECK_EQUAL(isCorrect, true);
	BOOST_CHECK_EQUAL(isMissingContent,true);

	contentFinder.setImageContentURL(std::string(HTMLMEDIAROOT).append("\\JARVIS\\TestDF\\ICT2\\Music"));
	isMissingContent = contentFinder.searchDBforMissingArtistImage(artistName,artistID);

	BOOST_CHECK_EQUAL(artistName.compare("testArtist2"), 0);
	BOOST_CHECK_EQUAL(artistID, 2);
	BOOST_CHECK_EQUAL(isMissingContent,true);

	contentFinder.setImageContentURL(std::string(HTMLMEDIAROOT).append("\\JARVIS\\TestDF\\ICT3\\Music"));
	isMissingContent = contentFinder.searchDBforMissingArtistImage(artistName,artistID);

	BOOST_CHECK_EQUAL(isMissingContent,false);

	
}

BOOST_AUTO_TEST_CASE(AlbumTests)
{
	DatabaseTables::Database dbConn;
	BOOST_CHECK_EQUAL(dbConn.Connect(DATABSEUSER,DATABASEPASSWORD,"mediaServerTests","localhost"),true);

	imagegetters::music::MusicMissingImageContentFinder contentFinder(&dbConn);
	std::string artistName, albumName; 
	int albumID;
	bool isMissingContent = false;

	contentFinder.setImageContentURL(std::string(HTMLMEDIAROOT).append("\\JARVIS\\TestDF\\ICT\\Music"));
	isMissingContent = contentFinder.searchDBforMissingAlbumImage(albumName,artistName,albumID);

	BOOST_CHECK_EQUAL(artistName.compare("testArtist1"), 0);
	BOOST_CHECK_EQUAL(albumName.compare("testAlbum"), 0);
	BOOST_CHECK_EQUAL(albumID == 1 || albumID==2,true);
	BOOST_CHECK_EQUAL(isMissingContent,true);

	contentFinder.setImageContentURL(std::string(HTMLMEDIAROOT).append("\\JARVIS\\TestDF\\ICT2\\Music"));
	isMissingContent = contentFinder.searchDBforMissingAlbumImage(albumName,artistName,albumID);

	BOOST_CHECK_EQUAL(artistName.compare("testArtist1"), 0);
	BOOST_CHECK_EQUAL(albumName.compare("testAlbum"), 0);
	BOOST_CHECK_EQUAL(albumID == 1,true);
	BOOST_CHECK_EQUAL(isMissingContent,true);

	contentFinder.setImageContentURL(std::string(HTMLMEDIAROOT).append("\\JARVIS\\TestDF\\ICT3\\Music"));
	isMissingContent = contentFinder.searchDBforMissingAlbumImage(albumName,artistName,albumID);

	BOOST_CHECK_EQUAL(isMissingContent,false);

}




