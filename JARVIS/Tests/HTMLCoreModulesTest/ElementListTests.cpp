#include "stdafx.h"
#include "../../JARVISCoreModules/CoreModules/HTMLRendere/Elements/Lable.h"
#include "../../JARVISCoreModules/CoreModules/HTMLRendere/Containers/ElementList.h"

BOOST_AUTO_TEST_CASE(ElementListConstructor)
{
	BOOST_CHECK_NO_THROW(ElementList form(""));
	BOOST_CHECK_NO_THROW(ElementList form("test"));
}


BOOST_AUTO_TEST_CASE(ElementListElementChecks)
{

	Lable* l = new Lable("lable");
	l->setText("testText");

	ElementList elList("test");
	elList.addElement(l);

	std::string elListTxt = elList.getText();
	BOOST_CHECK_EQUAL(elListTxt.compare("<div id=\"test\"><p id=\"lable\">testText</p></div>") ,0);

	elList.addElement(l);
	elListTxt = elList.getText();
	BOOST_CHECK_EQUAL(elListTxt.compare("<div id=\"test\"><p id=\"lable\">testText</p><p id=\"lable\">testText</p></div>") ,0);

	elList.removeElement(l);
	elListTxt = elList.getText();
	BOOST_CHECK_EQUAL(elListTxt.compare("<div id=\"test\"><p id=\"lable\">testText</p></div>") ,0);

}

