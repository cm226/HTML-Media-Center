#pragma once
#include "Selector.h"

class NewlineSelector : public Selector
{
protected:
	std::queue<Selection>& nextChar(std::queue<Selection>& selections, InputCharWrapper c);
	std::queue<Selection>& inputFinished(std::queue<Selection>& selections, std::streampos end);

public:
	NewlineSelector(void);
	~NewlineSelector(void);
};

