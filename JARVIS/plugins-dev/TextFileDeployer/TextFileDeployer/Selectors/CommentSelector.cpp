#include "CommentSelector.h"


CommentSelector::CommentSelector(std::string commentStart, std::string commentEnd):
	curState(NOT_IN_COMMENT)
{
	commentMarkerStart = commentStart;
	commentMarkerEnd = commentEnd;
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


void CommentSelector::gotCommentEnd(std::queue<Selection>& selections, InputCharWrapper c)
{
	selections.push(Selection(commentStart, c.getPos()));
	curState = NOT_IN_COMMENT;
}

void CommentSelector::checkCommentStartMarker(InputCharWrapper c)
{
	startMarkerMoniter.next(c);
	if(startMarkerMoniter.gotMarker())
		curState = IN_COMMENT;
}

void CommentSelector::checkCommentEndMarker(std::queue<Selection>& selections,InputCharWrapper c)
{
	endMarkerMoniter.next(c);
	if(endMarkerMoniter.gotMarker())
	{
		selections.push(Selection(startMarkerMoniter.getStartPos(), endMarkerMonitor.getEndPos()));
		startMarkerMonitor.clear();
		endMarkerMonitor.clear();

		curState = NOT_IN_COMMENT;
	}
}


