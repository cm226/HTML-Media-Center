#pragma once

#include "Language.h"

class Xml : public Language
{
private:
	SpaceSelector spaceSelector;
	NewlineSelector newLineSelector;
	CommentSelector commentSelector;

public:
	Xml(void);
	~Xml(void);

	SpaceSelector& getSpaceSelector();
	NewlineSelector& getNewlineSelector();
	CommentSelector& getCommentSelector();
};

