#include "stdafx.h"
#include "../../JARVISCoreModules/CoreModules/HTMLRendere/Elements/Lable.h"

BOOST_AUTO_TEST_CASE(LableConstructor)
{
	BOOST_CHECK_NO_THROW(Lable lable(""));
	BOOST_CHECK_NO_THROW(Lable lable("test"));
}


BOOST_AUTO_TEST_CASE(LableBoxRender)
{
	Lable textBox("testLable");

	std::string textBoxStr = textBox.getText();
	BOOST_CHECK_EQUAL(textBoxStr.compare("<div id=\"testLable\"></div>"), 0);

	textBox.addAttribute("class=\"class1\"");
	textBoxStr = textBox.getText();
	BOOST_CHECK_EQUAL(textBoxStr.compare("<div id=\"testLable\" class=\"class1\"></div>"), 0);


	textBox.setText("this is test text");
	textBoxStr = textBox.getText();
	BOOST_CHECK_EQUAL(textBoxStr.compare("<div id=\"testLable\" class=\"class1\">this is test text</div>"), 0);

	textBox.setText("");
	textBoxStr = textBox.getText();
	BOOST_CHECK_EQUAL(textBoxStr.compare("<div id=\"testLable\" class=\"class1\"></div>"), 0);
}

BOOST_AUTO_TEST_CASE(LableCallbackTests)
{
	Lable textBox("testLable");
	textBox.addOnclickCallbackAttribute(1,0,"TESPLUGIN");
	std::string textBoxStr = textBox.getText();
	BOOST_CHECK_EQUAL(textBoxStr.compare("<div id=\"testLable\" onClick=\"window.location='../pluginInteraction/0/TESPLUGIN'\"></div>"), 0);


	textBox = Lable("testLable");
	std::vector<std::string> contextArgs;
	contextArgs.push_back("contxAra1");
	contextArgs.push_back("contxAra%202");

	textBox.addOnclickCallbackAttribute(1,0,"TESPLUGIN",contextArgs);
	textBoxStr = textBox.getText();
	BOOST_CHECK_EQUAL(textBoxStr.compare("<div id=\"testLable\" onClick=\"window.location='../pluginInteraction/0/TESPLUGIN/contxAra1/contxAra%202'\"></div>"), 0);

	textBox = Lable("testLable");
	contextArgs.clear();

	textBox.addOnclickCallbackAttribute(1,0,"TESPLUGIN",contextArgs);
	textBoxStr = textBox.getText();
	BOOST_CHECK_EQUAL(textBoxStr.compare("<div id=\"testLable\" onClick=\"window.location='../pluginInteraction/0/TESPLUGIN'\"></div>"), 0);

}
