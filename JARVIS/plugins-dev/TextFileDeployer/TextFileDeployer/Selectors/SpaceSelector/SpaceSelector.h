#pragma once
#include "../Selector.h"
#include "../Commen/TokenFinder.h"
#include "ConsecutiveSpaceSelectionCreator.h"



class SpaceSelector : public Selector
{
private:
	TokenFinder escapedSpaceStart;
	TokenFinder escapedSpaceEnd;

	bool usingEscapedSpaces;
	bool insideIgnoreSequence;

	ConsecutiveSpaceSelectionCreator selectionCreator;
	
	void notSpace(std::queue<Selection>& selections, std::streampos at);
	void handleEscapedSpaces(InputCharWrapper c);

protected:
	std::queue<Selection>& nextChar(std::queue<Selection>& selections, InputCharWrapper c);
	std::queue<Selection>& inputFinished(std::queue<Selection>& selections, std::streampos end);

public:
	SpaceSelector(void);
	SpaceSelector(std::string ignoreSpaceStart, std::string ignoreSpaceEnd);
	~SpaceSelector(void);
};

