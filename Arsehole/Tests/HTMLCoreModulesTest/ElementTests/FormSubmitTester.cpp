#include "../stdafx.h"
#include "../../../ArseholeCoreModules/CoreModules/HTMLRendere/Elements/FormSubmit.h"



BOOST_AUTO_TEST_CASE(FormSubmitRender)
{
	FormSubmit submit("submit");

	std::string textBoxStr = submit.getText();
	BOOST_CHECK_EQUAL(textBoxStr.compare("<input id=\"submit\" type=\"submit\" value=\"submit\"></input>"), 0);

	submit.addAttribute("class=\"class1\"");
	textBoxStr = submit.getText();
	BOOST_CHECK_EQUAL(textBoxStr.compare("<input id=\"submit\" type=\"submit\" value=\"submit\" class=\"class1\"></input>"), 0);

}
