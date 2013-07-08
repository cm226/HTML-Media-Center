#pragma once

#include "Selector.h"
#include "Commen\TokenFinder.h"
#include <string>

class CommentSelector : public Selector
{
private:
	enum State{IN_COMMENT,NOT_IN_COMMENT};
	State curState;

	TokenFinder startMarkerMoniter;
	TokenFinder endMarkerMoniter;

	void checkCommentStartMarker(InputCharWrapper c);
	void checkCommentEndMarker(std::queue<Selection>&,InputCharWrapper c);

protected:
	std::queue<Selection>& nextChar(std::queue<Selection>& selections, InputCharWrapper c);
	std::queue<Selection>& inputFinished(std::queue<Selection>& selections, std::streampos end);

public:
	CommentSelector(std::string commentStart, std::string commentEnd);
	~CommentSelector(void);
};

