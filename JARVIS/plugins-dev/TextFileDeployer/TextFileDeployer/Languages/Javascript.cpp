#include "Javascript.h"


Javascript::Javascript(void) : 
	commentLineSelector("//","\n"),
	commentBlockSelector("/*","*/"), 
	spaceSelector("var","=")
{
	commentLineSelector.decorate(&commentBlockSelector);
}


Javascript::~Javascript(void)
{

}


SpaceSelector& Javascript::getSpaceSelector()
{
	return spaceSelector;
}

NewlineSelector& Javascript::getNewlineSelector()
{
	return newLineSelector;
}

CommentSelector& Javascript::getCommentSelector()
{
	return commentLineSelector;
}