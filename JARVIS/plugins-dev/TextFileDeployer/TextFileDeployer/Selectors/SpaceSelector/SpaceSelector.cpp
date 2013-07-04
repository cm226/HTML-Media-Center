#include "SpaceSelector.h"


SpaceSelector::SpaceSelector(void) :
	ignoreSpaceStart('\0'),
	ignoreSpaceEnd('\0'),
	insideIgnoreSequence(false)
{
}

SpaceSelector::SpaceSelector(char ignoreSpaceStart, char ignoreSpaceEnd) :
	ignoreSpaceEnd(ignoreSpaceEnd), 
	ignoreSpaceStart(ignoreSpaceStart),
	insideIgnoreSequence(false)
{

}


SpaceSelector::~SpaceSelector(void)
{
}



std::queue<Selection>& SpaceSelector::nextChar(std::queue<Selection>& selections, InputCharWrapper c)
{	
	if(c.getChar()== ignoreSpaceStart)
	{
		insideIgnoreSequence = true;
		return selections;
	}

	if(insideIgnoreSequence && c.getChar() == ignoreSpaceEnd)
	{
		insideIgnoreSequence = false;
		return selections;
	}

	if(c.getChar() == ' ')
		selectionCreator.space(c.getPos());
	else 
		selectionCreator.notSpace(c.getPos());

	if(selectionCreator.selectionCreated())
			selections.push(selectionCreator.getSelection());
	
}

