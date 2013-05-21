#include "stdafx.h"
#include "../../JARVISCoreModules/CoreModules/HTMLRendere/Elements/Hyperlink.h"

BOOST_AUTO_TEST_CASE(HyperlinkConstructor)
{
	BOOST_CHECK_NO_THROW(Hyperlink hyperlink("hyperlink","www.google.com","google"));
}


BOOST_AUTO_TEST_CASE(HyperlinkRender)
{
	Hyperlink hyperLink("link","www.test.com","test");

	std::string hyperlinkTxt = hyperLink.getText();
	BOOST_CHECK_EQUAL(hyperlinkTxt.compare("<a id=\"link\" href=\"www.test.com\">test</a>"), 0);

	hyperLink.addAttribute("class=\"class1\"");
	hyperlinkTxt = hyperLink.getText();
	BOOST_CHECK_EQUAL(hyperlinkTxt.compare("<a id=\"link\" href=\"www.test.com\" class=\"class1\">test</a>"), 0);
}

BOOST_AUTO_TEST_CASE(HyperlinkCallbackTests)
{
	Hyperlink hyperlink("link","www.test.com","test");
	hyperlink.addOnclickCallbackAttribute(1,0,"TESPLUGIN");
	std::string textBoxStr = hyperlink.getText();
	BOOST_CHECK_EQUAL(textBoxStr.compare("<a id=\"link\" href=\"www.test.com\" onClick=\"window.location='../pluginInteraction/0/TESPLUGIN'\">test</a>"), 0);


	Hyperlink hyperlink1("link","www.test.com","test");
	std::vector<std::string> contextArgs;
	contextArgs.push_back("contxAra1");
	contextArgs.push_back("contxAra%202");

	hyperlink1.addOnclickCallbackAttribute(1,0,"TESPLUGIN",contextArgs);
	textBoxStr = hyperlink1.getText();
	BOOST_CHECK_EQUAL(textBoxStr.compare("<a id=\"link\" href=\"www.test.com\" onClick=\"window.location='../pluginInteraction/0/TESPLUGIN/contxAra1/contxAra%202'\">test</a>"), 0);

	Hyperlink hyperlink2("link","www.test.com","test");
	contextArgs.clear();

	hyperlink2.addOnclickCallbackAttribute(1,0,"TESPLUGIN",contextArgs);
	textBoxStr = hyperlink2.getText();
	BOOST_CHECK_EQUAL(textBoxStr.compare("<a id=\"link\" href=\"www.test.com\" onClick=\"window.location='../pluginInteraction/0/TESPLUGIN'\">test</a>"), 0);

}
