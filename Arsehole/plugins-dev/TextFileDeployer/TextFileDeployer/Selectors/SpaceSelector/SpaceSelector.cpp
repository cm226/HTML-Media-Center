#include "SpaceSelector.h"


SpaceSelector::SpaceSelector(void) :
	escapedSpaceStart("\0"),
	escapedSpaceEnd("\0"),
	insideIgnoreSequence(false),
	usingEscapedSpaces(false)
{
}

SpaceSelector::SpaceSelector(std::string ignoreSpaceStart, std::string ignoreSpaceEnd) :
	escapedSpaceStart(ignoreSpaceStart), 
	escapedSpaceEnd(ignoreSpaceEnd),
	insideIgnoreSequence(false),
	usingEscapedSpaces(true)
{

}


SpaceSelector::~SpaceSelector(void)
{
}



std::queue<Selection>& SpaceSelector::nextChar(std::queue<Selection>& selections, InputCharWrapper c)
{	
	
	if(usingEscapedSpaces)
		handleEscapedSpaces(c);

	if((c.getChar() == ' ' || c.getChar() == '\t') && !insideIgnoreSequence)
		selectionCreator.space(c.getPos());
	else 
		notSpace(selections,c.getPos());
	
	return selections;
}

void SpaceSelector::handleEscapedSpaces(InputCharWrapper c)
{
	if(!insideIgnoreSequence)
	{
		escapedSpaceStart.nextChar(c);

		if(escapedSpaceStart.haveToken())
		{
			insideIgnoreSequence = true;
		}
	}

	if(insideIgnoreSequence)
	{
		escapedSpaceEnd.nextChar(c);
		if(escapedSpaceEnd.haveToken())
		{
			insideIgnoreSequence = false;
		}
	}
}

std::queue<Selection>& SpaceSelector::inputFinished(std::queue<Selection>& selections, std::streampos end)
{
	notSpace(selections, end);
	return selections;
}

void SpaceSelector::notSpace(std::queue<Selection>& selections, std::streampos at)
{
	selectionCreator.notSpace(at);

	if(selectionCreator.selectionCreated())
			selections.push(selectionCreator.getSelection());
}

