#include "Stdafx.h"
#include <strstream>

#include "../TextFileDeployer/TextfileDeployer/Languages/Javascript.h"
#include "../TextFileDeployer/TextfileDeployer/Stripper/Stripper.h"

BOOST_AUTO_TEST_CASE(JavascriptNormalCase)
{
	std::string javascript = "function( event ){ \n var thisvar = 5; \n }; //this comment should be striped \n /* so \n shoudl this one \n */ \
							 function2(){ };";

	std::string slimJS = "function(event){var thisvar=5;};function2(){};";
	
	std::queue<Selection> selections;
	Javascript js;
	Selector& s = js.getCommentSelector();
	s.decorate(&js.getNewlineSelector());
	s.decorate(&js.getSpaceSelector());

	int counter = 0;
	for(std::string::iterator inputIt = javascript.begin(); inputIt != javascript.end(); inputIt++)
	{
		s.select(selections,InputCharWrapper(*inputIt,counter));
		counter++;
	}
	s.endInput(selections,counter);

	std::stringstream inputStream;
	inputStream << javascript;

	InputWrapper input(inputStream);
	Stripper stripper(input);
	stripper.strip(selections);
	
	std::ostringstream& out = stripper.getOutput();

	BOOST_CHECK_EQUAL(slimJS.compare(out.str()), 0);
}