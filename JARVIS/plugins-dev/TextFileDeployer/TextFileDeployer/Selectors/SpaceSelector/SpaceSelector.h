#pragma once
#include "../Selector.h"
#include "ConsecutiveSpaceSelectionCreator.h"



class SpaceSelector : public Selector
{
private:
	char ignoreSpaceStart;
	char ignoreSpaceEnd;

	bool insideIgnoreSequence;

	ConsecutiveSpaceSelectionCreator selectionCreator;
	

protected:
	std::queue<Selection>& nextChar(std::queue<Selection>& selections, InputCharWrapper c);

public:
	SpaceSelector(void);
	SpaceSelector(char ignoreSpaceStart, char ignoreSpaceEnd);
	~SpaceSelector(void);
};

