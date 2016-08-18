#include "Stdafx.h"
#include <sstream>

#include "../TextFileDeployer/TextfileDeployer/Stripper/Stripper.h"

BOOST_AUTO_TEST_CASE(StripperTestNormalCase)
{
	std::string input = "this is some test input";
	std::string expectedOutput = "thisissometestinput";

	std::stringstream inputss;
	std::queue<Selection> selections;
	
	inputss << input;
	selections.push(Selection(4,5));
	selections.push(Selection(7,8));
	selections.push(Selection(12,13));
	selections.push(Selection(17,18));

	InputWrapper inputWrapper(inputss);
	Stripper stripper(inputWrapper);

	stripper.strip(selections);
	
	std::ostringstream& output = stripper.getOutput();
	std::string outputStr = output.str();

	BOOST_CHECK_EQUAL(expectedOutput .compare(outputStr),0);
}


BOOST_AUTO_TEST_CASE(StripperTestSelectionOverlap)
{
	std::string input = "this is some test /*  blargh  */ input";
	std::string expectedOutput = "thisissometestinput";

	std::stringstream inputss;
	std::queue<Selection> selections;
	
	inputss << input;
	selections.push(Selection(4,5));
	selections.push(Selection(7,8));
	selections.push(Selection(12,13));
	selections.push(Selection(17,18));
	selections.push(Selection(32,33));
	selections.push(Selection(18,32));

	InputWrapper inputWrapper(inputss);
	Stripper stripper(inputWrapper);

	stripper.strip(selections);
	
	std::ostringstream& output = stripper.getOutput();
	std::string outputStr = output.str();

	BOOST_CHECK_EQUAL(expectedOutput .compare(outputStr),0);
}

