#include "CommentSelector.h"


CommentSelector::CommentSelector(std::string commentStart, std::string commentEnd):
	curState(NOT_IN_COMMENT), 
	startMarkerMoniter(commentStart), 
	endMarkerMoniter(commentEnd)
{

}


CommentSelector::~CommentSelector(void)
{
}

std::queue<Selection>& CommentSelector::nextChar(std::queue<Selection>& selections,
		InputCharWrapper c)
{
	if(curState == IN_COMMENT)
		checkCommentEndMarker(selections, c);
	else
		checkCommentStartMarker(c);

	return selections;
}


void CommentSelector::checkCommentStartMarker(InputCharWrapper c)
{
	startMarkerMoniter.nextChar(c);
	if(startMarkerMoniter.haveToken())
		curState = IN_COMMENT;
}

void CommentSelector::checkCommentEndMarker(std::queue<Selection>& selections,InputCharWrapper c)
{
	endMarkerMoniter.nextChar(c);
	if(endMarkerMoniter.haveToken())
	{
		selections.push(Selection(startMarkerMoniter.getTokenStart(), c.getPos()));
		curState = NOT_IN_COMMENT;
	}
}

std::queue<Selection>& CommentSelector::inputFinished(std::queue<Selection>& selections, std::streampos end)
{
	if(curState == IN_COMMENT)
	{
		selections.push(Selection(startMarkerMoniter.getTokenStart(), end));
		curState = NOT_IN_COMMENT;
	}
	return selections;
}


