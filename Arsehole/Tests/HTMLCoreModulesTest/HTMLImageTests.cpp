#include "stdafx.h"
#include "../../ArseholeCoreModules/CoreModules/HTMLRendere/Elements/HTMLImage.h"

BOOST_AUTO_TEST_CASE(HTMLImageConstructor)
{
	BOOST_CHECK_NO_THROW(HTMLImage img("name", "www.test.com"));
}


BOOST_AUTO_TEST_CASE(HTMLImageRender)
{
	HTMLImage image("imgName","imageURL");

	std::string imgTxt = image.getText();

	BOOST_CHECK_EQUAL(imgTxt.compare("<img id=\"imgName\" src=\"imageURL\"></img>"), 0);

	image.addAttribute("class=\"class1\"");
	imgTxt = image.getText();
	BOOST_CHECK_EQUAL(imgTxt.compare("<img id=\"imgName\" src=\"imageURL\" class=\"class1\"></img>"), 0);
}

BOOST_AUTO_TEST_CASE(HTMLImageCallbackTests)
{
	HTMLImage image("imgName","imageURL");
	image.addOnclickCallbackAttribute(1,0,"TESPLUGIN");
	std::string typerLinkTxt = image.getText();
	BOOST_CHECK_EQUAL(typerLinkTxt.compare("<img id=\"imgName\" src=\"imageURL\" onClick=\"window.location='../pluginInteraction/0/TESPLUGIN'\"></img>"), 0);


	HTMLImage image1("imgName","imageURL");
	std::vector<std::string> contextArgs;
	contextArgs.push_back("contxAra1");
	contextArgs.push_back("contxAra%202");

	image1.addOnclickCallbackAttribute(1,0,"TESPLUGIN",contextArgs);
	typerLinkTxt = image1.getText();
	BOOST_CHECK_EQUAL(typerLinkTxt.compare("<img id=\"imgName\" src=\"imageURL\" onClick=\"window.location='../pluginInteraction/0/TESPLUGIN/contxAra1/contxAra%202'\"></img>"), 0);

	HTMLImage image2("imgName","imageURL");
	contextArgs.clear();

	image2.addOnclickCallbackAttribute(1,0,"TESPLUGIN",contextArgs);
	typerLinkTxt = image2.getText();
	BOOST_CHECK_EQUAL(typerLinkTxt.compare("<img id=\"imgName\" src=\"imageURL\" onClick=\"window.location='../pluginInteraction/0/TESPLUGIN'\"></img>"), 0);

}
