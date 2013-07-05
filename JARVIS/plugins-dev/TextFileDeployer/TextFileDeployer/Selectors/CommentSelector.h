#pragma once

#include "Selector.h"
#include <string>

class CommentSelector : public Selector
{
private:
	enum State{IN_COMMENT,NOT_IN_COMMENT};
	State curState;

	std::streampos commentStart;

	std::string commentMarkerStart;
	std::string commentMarkerEnd;

	void gotCommentEnd(std::queue<Selection>& selections, InputCharWrapper c);
	void checkCommentStartMarker(InputCharWrapper c);
	void checkCommentEndMarker(std::queue<Selection>&,InputCharWrapper c);

protected:
	std::queue<Selection>& nextChar(std::queue<Selection>& selections, InputCharWrapper c);

public:
	CommentSelector(std::string commentStart, std::string commentEnd);
	~CommentSelector(void);
};

