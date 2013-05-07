#include "stdafx.h"
#include "../../MediaImagesPlugin.h"

BOOST_AUTO_TEST_CASE(PluginEntryPoint)
{

	CoreModules cm;
	CoreModules* cmref = &cm;

	MediaImagesPlugin mediaImagesPlugin(cmref);
	Page page;
	std::string pageString;
	mediaImagesPlugin.whatDoYouLookLike(&page);

	page.buildPage(&pageString);

	BOOST_CHECK_GT(pageString.size(),0);
	page.freePage();

}