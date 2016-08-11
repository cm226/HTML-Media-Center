#include "Css.h"


Css::Css(void) : commentSelector("/*", "*/")
{

}


Css::~Css(void)
{
}

SpaceSelector& Css::getSpaceSelector()
{
	return spaceSelector;
}

NewlineSelector& Css::getNewlineSelector()
{
	return newLineSelector;
}

CommentSelector& Css::getCommentSelector()
{
	return commentSelector;
}
