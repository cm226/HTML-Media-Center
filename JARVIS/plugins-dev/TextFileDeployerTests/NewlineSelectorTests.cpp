#include "Stdafx.h"
#include "../TextFileDeployer/TextfileDeployer/Selectors/NewlineSelector.h"

BOOST_AUTO_TEST_CASE(NewlineSelectorNormalCase)
{
	std::string testInput = "this \n is a multy\nline string\n";

	std::queue<Selection> selections;

	NewlineSelector selector;
	int counter = 0;
	for(std::string::iterator inputIt = testInput.begin(); inputIt != testInput.end(); inputIt++)
	{
		selector.select(selections,InputCharWrapper(*inputIt,counter));
		counter++;
	}
	selector.endInput(selections,counter);

	BOOST_CHECK_EQUAL(selections.size(), 3);
	
	std::deque<Selection> vec =  selections._Get_container();

	BOOST_CHECK_EQUAL((int)vec[0].getSelectionStart(), 5);
	BOOST_CHECK_EQUAL((int)vec[0].getSelectionEnd(), 6);

	BOOST_CHECK_EQUAL((int)vec[1].getSelectionStart(), 17);
	BOOST_CHECK_EQUAL((int)vec[1].getSelectionEnd(), 18);

	BOOST_CHECK_EQUAL((int)vec[2].getSelectionStart(), 29);
	BOOST_CHECK_EQUAL((int)vec[2].getSelectionEnd(), 30);

}

BOOST_AUTO_TEST_CASE(NewlineSelectorNoNewlines)
{
	std::string testInput = "this is a multy line string";

	std::queue<Selection> selections;

	NewlineSelector selector;
	int counter = 0;
	for(std::string::iterator inputIt = testInput.begin(); inputIt != testInput.end(); inputIt++)
	{
		selector.select(selections,InputCharWrapper(*inputIt,counter));
		counter++;
	}
	selector.endInput(selections,counter);

	BOOST_CHECK_EQUAL(selections.size(), 0);
	
	
}

BOOST_AUTO_TEST_CASE(NewlineSelectorEmptyString)
{
	std::string testInput = "";

	std::queue<Selection> selections;

	NewlineSelector selector;
	int counter = 0;
	for(std::string::iterator inputIt = testInput.begin(); inputIt != testInput.end(); inputIt++)
	{
		selector.select(selections,InputCharWrapper(*inputIt,counter));
		counter++;
	}
	selector.endInput(selections,counter);

	BOOST_CHECK_EQUAL(selections.size(), 0);
	
	
}