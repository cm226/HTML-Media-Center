#pragma once

#include <queue>
#include "../Selection.h"
#include "../InputWrapper.h"
#include "../InputCharWrapper.h"

class Selector
{
private:
	Selector* decorating;

protected:
	virtual std::queue<Selection>& nextChar(std::queue<Selection>& selections, InputCharWrapper c) = 0;
public:
	Selector(void);
	Selector(Selector* decorator);

	virtual ~Selector(void);

	std::queue<Selection>& select(std::queue<Selection>& selections, InputCharWrapper& input);
};

