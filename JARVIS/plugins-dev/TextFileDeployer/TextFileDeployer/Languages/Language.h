#pragma once
#include "../Selectors/SpaceSelector/SpaceSelector.h"
#include "../Selectors/NewlineSelector.h"
#include "../Selectors/CommentSelector.h"

class Language
{
public:
	Language(void);
	virtual ~Language(void);

	virtual SpaceSelector& getSpaceSelector() = 0;
	virtual NewlineSelector& getNewlineSelector() = 0;
	virtual CommentSelector& getCommentSelector() = 0;
};

