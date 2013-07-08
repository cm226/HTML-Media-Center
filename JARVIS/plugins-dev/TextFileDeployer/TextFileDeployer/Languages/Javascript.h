#pragma once

#include "Language.h"

class Javascript : public Language
{
private:
	SpaceSelector spaceSelector;
	NewlineSelector newLineSelector;
	CommentSelector commentLineSelector;
	CommentSelector commentBlockSelector;

public:
	Javascript(void);
	~Javascript(void);

	SpaceSelector& getSpaceSelector();
	NewlineSelector& getNewlineSelector();
	CommentSelector& getCommentSelector();
};

