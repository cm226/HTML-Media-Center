#include "stdafx.h"
#include "../../../HTMLRendere/Elements/Lable.h"
#include "../../../HTMLRendere/Containers/Form.h"

BOOST_AUTO_TEST_CASE(formConstructor)
{
	BOOST_CHECK_NO_THROW(Form form(""));
	BOOST_CHECK_NO_THROW(Form form("test"));
}


BOOST_AUTO_TEST_CASE(FormElementChecks)
{

	Lable* l = new Lable("lable");
	l->setText("testText");

	Form form("test");
	form.addElement(l);

	std::string formTxt = form.getText();
	BOOST_CHECK_EQUAL(formTxt.compare("<form id=\"test\" action=\"../Shared/genericPluginFormHandler\"><p id=\"lable\">testText</p></form>") ,0);

	form.addElement(l);
	formTxt = form.getText();
	BOOST_CHECK_EQUAL(formTxt.compare("<form id=\"test\" action=\"../Shared/genericPluginFormHandler\"><p id=\"lable\">testText</p><p id=\"lable\">testText</p></form>") ,0);

	form.removeElement(l);
	formTxt = form.getText();
	BOOST_CHECK_EQUAL(formTxt.compare("<form id=\"test\" action=\"../Shared/genericPluginFormHandler\"><p id=\"lable\">testText</p></form>") ,0);

}

