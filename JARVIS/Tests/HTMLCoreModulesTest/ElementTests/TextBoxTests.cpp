#include "../stdafx.h"
#include "../../../JARVISCoreModules/CoreModules/HTMLRendere/Elements/TextBox.h"
#include <vector>
#include <string>

BOOST_AUTO_TEST_CASE(TextBoxConstructor)
{
	BOOST_CHECK_NO_THROW(TextBox textBox(""));
	BOOST_CHECK_NO_THROW(TextBox textBox("test"));

}

BOOST_AUTO_TEST_CASE(textBoxRender)
{
	TextBox textBox("testbox");

	std::string textBoxStr = textBox.getText();
	BOOST_CHECK_EQUAL(textBoxStr.compare("<input id=\"testbox\" type=\"text\"></input>"), 0);

	textBox.addAttribute("class=\"class1\"");
	textBoxStr = textBox.getText();
	BOOST_CHECK_EQUAL(textBoxStr.compare("<input id=\"testbox\" type=\"text\" class=\"class1\"></input>"), 0);


	textBox.addOnclickCallbackAttribute(1,0,"TESPLUGIN");
	textBoxStr = textBox.getText();
	BOOST_CHECK_EQUAL(textBoxStr.compare("<input id=\"testbox\" type=\"text\" class=\"class1\" onClick=\"window.location='../pluginInteraction/0/TESPLUGIN'\"></input>"), 0);


	textBox = TextBox("testbox");
	std::vector<std::string> contextArgs;
	contextArgs.push_back("contxAra1");
	contextArgs.push_back("contxAra%202");

	textBox.addOnclickCallbackAttribute(1,0,"TESPLUGIN",contextArgs);
	textBoxStr = textBox.getText();
	BOOST_CHECK_EQUAL(textBoxStr.compare("<input id=\"testbox\" type=\"text\" onClick=\"window.location='../pluginInteraction/0/TESPLUGIN/contxAra1/contxAra%202'\"></input>"), 0);

	textBox = TextBox("testbox");
	contextArgs.clear();

	textBox.addOnclickCallbackAttribute(1,0,"TESPLUGIN",contextArgs);
	textBoxStr = textBox.getText();
	BOOST_CHECK_EQUAL(textBoxStr.compare("<input id=\"testbox\" type=\"text\" onClick=\"window.location='../pluginInteraction/0/TESPLUGIN'\"></input>"), 0);

	
}
