#include "ConsecutiveSpaceSelectionCreator.h"


ConsecutiveSpaceSelectionCreator::ConsecutiveSpaceSelectionCreator(void) : createingSelection(false), haveSelection(false)
{
}


ConsecutiveSpaceSelectionCreator::~ConsecutiveSpaceSelectionCreator(void)
{
}



void ConsecutiveSpaceSelectionCreator::space(std::streampos at)
{
	if(!createingSelection)
	{
		createingSelection = true;
		temp_Start = at;
	}
}

void ConsecutiveSpaceSelectionCreator::notSpace(std::streampos at)
{
	if(createingSelection)
	{
		createingSelection = false;
		temp_End = at;
		haveSelection = true;
	}
}

bool ConsecutiveSpaceSelectionCreator::selectionCreated()
{
	return haveSelection;
}

Selection ConsecutiveSpaceSelectionCreator::getSelection()
{
	haveSelection = false;
	return Selection(temp_Start, temp_End);
}
