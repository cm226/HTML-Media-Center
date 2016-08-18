#include "Stdafx.h"
#include "../TextFileDeployer/TextfileDeployer/Selectors/CommentSelector.h"

BOOST_AUTO_TEST_CASE(CommentSelectorNormalCase)
{
	std::string testInput = "this // is a string with \n a line comment // and another on the end \n";
	
	std::queue<Selection> selections;

	CommentSelector selector("//", "\n");
	int counter = 0;
	for(std::string::iterator inputIt = testInput.begin(); inputIt != testInput.end(); inputIt++)
	{
		selector.select(selections,InputCharWrapper(*inputIt,counter));
		counter++;
	}
	selector.endInput(selections,counter);

	BOOST_CHECK_EQUAL(selections.size(), 2);
	
	std::deque<Selection> vec =  selections._Get_container();

	BOOST_CHECK_EQUAL((int)vec[0].getSelectionStart(), 5);
	BOOST_CHECK_EQUAL((int)vec[0].getSelectionEnd(), 25);

	BOOST_CHECK_EQUAL((int)vec[1].getSelectionStart(), 42);
	BOOST_CHECK_EQUAL((int)vec[1].getSelectionEnd(), 68);

}


BOOST_AUTO_TEST_CASE(CommentSelectorCommentExtendsToEnd)
{
	std::string testInput = "this // is a string with \n a line comment // and another on the end";

	std::queue<Selection> selections;

	CommentSelector selector("//", "\n");
	int counter = 0;
	for(std::string::iterator inputIt = testInput.begin(); inputIt != testInput.end(); inputIt++)
	{
		selector.select(selections,InputCharWrapper(*inputIt,counter));
		counter++;
	}
	selector.endInput(selections,counter);

	BOOST_CHECK_EQUAL(selections.size(), 2);
	
	std::deque<Selection> vec =  selections._Get_container();

	BOOST_CHECK_EQUAL((int)vec[0].getSelectionStart(), 5);
	BOOST_CHECK_EQUAL((int)vec[0].getSelectionEnd(), 25);

	BOOST_CHECK_EQUAL((int)vec[1].getSelectionStart(), 42);
	BOOST_CHECK_EQUAL((int)vec[1].getSelectionEnd(), 67);
}