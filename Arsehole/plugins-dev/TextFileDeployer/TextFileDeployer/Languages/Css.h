#pragma once
#include "Language.h"

class Css : Language
{
private:
	SpaceSelector spaceSelector;
	NewlineSelector newLineSelector;
	CommentSelector commentSelector;

public:
	Css(void);
	~Css(void);

	SpaceSelector& getSpaceSelector();
	NewlineSelector& getNewlineSelector();
	CommentSelector& getCommentSelector();
};

