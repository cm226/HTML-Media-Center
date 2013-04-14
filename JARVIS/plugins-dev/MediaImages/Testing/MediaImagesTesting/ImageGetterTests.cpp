#include "stdafx.h"
#include "../../ImageGetters/ImageGetter.h"

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