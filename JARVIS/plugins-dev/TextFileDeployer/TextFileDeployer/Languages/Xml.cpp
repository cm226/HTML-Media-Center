#include "Xml.h"


Xml::Xml(void) : 
	commentSelector("<!-", "->"),
	spaceSelector("<",">")
{
}


Xml::~Xml(void)
{
}


SpaceSelector& Xml::getSpaceSelector()
{
	return spaceSelector;
}

NewlineSelector& Xml::getNewlineSelector()
{
	return newLineSelector;
}

CommentSelector& Xml::getCommentSelector()
{
	return commentSelector;
}
