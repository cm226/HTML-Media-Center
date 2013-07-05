#pragma once
#include "Selector.h"

class NewlineSelector : public Selector
{
protected:
	std::queue<Selection>& nextChar(std::queue<Selection>& selections, InputCharWrapper c);

public:
	NewlineSelector(void);
	~NewlineSelector(void);
};

