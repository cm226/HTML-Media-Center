#include "../Stdafx.h"
#include "../../TextFileDeployer/TextfileDeployer/Selectors/SpaceSelector/SpaceSelector.h"

BOOST_AUTO_TEST_CASE(WhitespaceSelectorNormalCase)
{
	std::string testInput = "this is		a string with		spaces   ";
	std::queue<Selection> selections;

	SpaceSelector spaceSelector;
	int counter = 0;
	for(std::string::iterator inputIt = testInput.begin(); inputIt != testInput.end(); inputIt++)
	{
		spaceSelector.select(selections,InputCharWrapper(*inputIt,counter));
		counter++;
	}
	spaceSelector.endInput(selections,counter);

	BOOST_CHECK_EQUAL(selections.size(), 6);
	
	std::deque<Selection> vec =  selections._Get_container();

	BOOST_CHECK_EQUAL((int)vec[0].getSelectionStart(), 4);
	BOOST_CHECK_EQUAL((int)vec[0].getSelectionEnd(), 5);

	BOOST_CHECK_EQUAL((int)vec[1].getSelectionStart(), 7);
	BOOST_CHECK_EQUAL((int)vec[1].getSelectionEnd(), 9);

	BOOST_CHECK_EQUAL((int)vec[2].getSelectionStart(), 10);
	BOOST_CHECK_EQUAL((int)vec[2].getSelectionEnd(), 11);

	BOOST_CHECK_EQUAL((int)vec[3].getSelectionStart(), 17);
	BOOST_CHECK_EQUAL((int)vec[3].getSelectionEnd(), 18);

	BOOST_CHECK_EQUAL((int)vec[4].getSelectionStart(), 22);
	BOOST_CHECK_EQUAL((int)vec[4].getSelectionEnd(), 24);

	BOOST_CHECK_EQUAL((int)vec[5].getSelectionStart(), 30);
	BOOST_CHECK_EQUAL((int)vec[5].getSelectionEnd(), 33);
	
}

BOOST_AUTO_TEST_CASE(WhitespaceSelectorNoSpaces)
{
	std::string testInput = "thisisaNoSpaceString";
	std::queue<Selection> selections;

	SpaceSelector spaceSelector;
	int counter = 0;
	for(std::string::iterator inputIt = testInput.begin(); inputIt != testInput.end(); inputIt++)
	{
		spaceSelector.select(selections,InputCharWrapper(*inputIt,counter));
		counter++;
	}
	spaceSelector.endInput(selections,counter);

	BOOST_CHECK_EQUAL(selections.size(), 0);
}

BOOST_AUTO_TEST_CASE(WhitespaceSelectorEmptystring)
{
	std::string testInput = "";
	std::queue<Selection> selections;

	SpaceSelector spaceSelector;
	int counter = 0;
	for(std::string::iterator inputIt = testInput.begin(); inputIt != testInput.end(); inputIt++)
	{
		spaceSelector.select(selections,InputCharWrapper(*inputIt,counter));
		counter++;
	}
	spaceSelector.endInput(selections,counter);

	BOOST_CHECK_EQUAL(selections.size(), 0);
}


BOOST_AUTO_TEST_CASE(WhitespaceSelectorEscapedSpace)
{
	
	std::string testInput = "this <is		a string> with escaped 	spaces   ";
	std::queue<Selection> selections;

	SpaceSelector spaceSelector("<", ">");
	int counter = 0;
	for(std::string::iterator inputIt = testInput.begin(); inputIt != testInput.end(); inputIt++)
	{
		spaceSelector.select(selections,InputCharWrapper(*inputIt,counter));
		counter++;
	}
	spaceSelector.endInput(selections,counter);

	BOOST_CHECK_EQUAL(selections.size(), 5);
	
	std::deque<Selection> vec =  selections._Get_container();

	BOOST_CHECK_EQUAL((int)vec[0].getSelectionStart(), 4);
	BOOST_CHECK_EQUAL((int)vec[0].getSelectionEnd(), 5);

	BOOST_CHECK_EQUAL((int)vec[1].getSelectionStart(), 19);
	BOOST_CHECK_EQUAL((int)vec[1].getSelectionEnd(), 20);

	BOOST_CHECK_EQUAL((int)vec[2].getSelectionStart(), 24);
	BOOST_CHECK_EQUAL((int)vec[2].getSelectionEnd(), 25);

	BOOST_CHECK_EQUAL((int)vec[3].getSelectionStart(), 32);
	BOOST_CHECK_EQUAL((int)vec[3].getSelectionEnd(), 34);

	BOOST_CHECK_EQUAL((int)vec[4].getSelectionStart(), 40);
	BOOST_CHECK_EQUAL((int)vec[4].getSelectionEnd(), 43);

	
}