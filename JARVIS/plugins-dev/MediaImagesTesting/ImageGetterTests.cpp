#include "stdafx.h"
#include "../MediaImages/ImageGetters/ImageGetter.h"

#include <string>
#include <boost/filesystem.hpp>
#include <boost/gil/gil_all.hpp>

#include <boost/gil/image.hpp>
#include <boost/gil/typedefs.hpp>
#include <boost/gil/extension/io/jpeg_io.hpp>


BOOST_AUTO_TEST_CASE(ImageGetterconstructor)
{
	
	CoreModules cm;
	CoreModules* cmref = &cm;

	ImageGetter imGetter(cmref);
}



BOOST_AUTO_TEST_CASE(googleSearch)
{

	CoreModules cm;
	CoreModules* cmref = &cm;
	std::vector<std::string> results;
	ImageGetter imgGetter(cmref);

	imgGetter.doGoogleSearch(results, "");
	BOOST_CHECK_EQUAL(results.size(), 0);

	results.clear();
	imgGetter.doGoogleSearch(results, "test space");
	BOOST_CHECK_EQUAL(results.size(), 4);

	results.clear();
	imgGetter.doGoogleSearch(results, "test,comma");
	BOOST_CHECK_EQUAL(results.size(), 4);

	results.clear();
	imgGetter.doGoogleSearch(results, "test/slash");
	BOOST_CHECK_EQUAL(results.size(), 4);

	results.clear();
	imgGetter.doGoogleSearch(results, "test\\escape");
	BOOST_CHECK_EQUAL(results.size(), 4);

}

BOOST_AUTO_TEST_CASE(downloadImage)
{
	CoreModules cm;
	CoreModules* cmref = &cm;
	ImageGetter imgGetter(cmref);


	std::string downloadedFileName = "test.jpg";
	std::string downloadedDirectory = "C:\\wamp\\www\\HTML-Media-Center\\JARVIS\\JARVIS\\";
	std::string downloadedLocation = downloadedDirectory + downloadedFileName;
	BOOST_CHECK_EQUAL(imgGetter.downloadAndCopyImage("http://g-ecx.images-amazon.com/images/G/02/kindle/merch/gw/Device_acc-GW-D-03-uk-600x180._V394748754_.jpg",
													 downloadedDirectory,downloadedFileName,200,250), true);

	BOOST_CHECK_EQUAL(true,(bool)boost::filesystem::exists(downloadedLocation));
	
	boost::gil::rgb8_image_t img;
	jpeg_read_image(downloadedLocation,img);
	BOOST_CHECK_EQUAL(img.height(), 250);
	BOOST_CHECK_EQUAL(img.width(), 200);

	bool fileRemoved = boost::filesystem::remove(downloadedLocation);
	BOOST_CHECK_EQUAL(true,fileRemoved);

}


BOOST_AUTO_TEST_CASE(downloadImageBADURL)
{
	CoreModules cm;
	CoreModules* cmref = &cm;
	ImageGetter imgGetter(cmref);


	std::string downloadedFileName = "test.jpg";
	std::string downloadedDirectory = "C:\\wamp\\www\\HTML-Media-Center\\JARVIS\\JARVIS\\";
	std::string downloadedLocation = downloadedDirectory + downloadedFileName;
	BOOST_CHECK_EQUAL(imgGetter.downloadAndCopyImage("http://google/blarghy.jpg",
													 downloadedDirectory,downloadedFileName,200,250), false);

	bool fileExists = (bool)boost::filesystem::exists(downloadedLocation);
	BOOST_CHECK_EQUAL(false,fileExists );
	if(fileExists)
	{
		bool fileRemoved = boost::filesystem::remove(downloadedLocation);
		BOOST_CHECK_EQUAL(true,fileRemoved);
	}

}
