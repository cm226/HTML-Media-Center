#include "stdafx.h"
#include "../../ArseholeCoreModules/CoreModules/HTMLRendere/Elements/Lable.h"
#include "../../ArseholeCoreModules/CoreModules/HTMLRendere/Containers/Form.h"

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
	BOOST_CHECK_EQUAL(formTxt.compare("<form id=\"test\" action=\"../Shared/genericPluginFormHandler\"><div id=\"lable\">testText</div></form>") ,0);

	form.addElement(l);
	formTxt = form.getText();
	BOOST_CHECK_EQUAL(formTxt.compare("<form id=\"test\" action=\"../Shared/genericPluginFormHandler\"><div id=\"lable\">testText</div><div id=\"lable\">testText</div></form>") ,0);

	form.removeElement(l);
	formTxt = form.getText();
	BOOST_CHECK_EQUAL(formTxt.compare("<form id=\"test\" action=\"../Shared/genericPluginFormHandler\"><div id=\"lable\">testText</div></form>") ,0);

}

