#pragma once

#include <queue>
#include "../Selections/Selection.h"
#include "../InputWrapper.h"
#include "../InputCharWrapper.h"

class Selector
{
private:
	Selector* decorating;

protected:
	virtual std::queue<Selection>& nextChar(std::queue<Selection>& selections, InputCharWrapper c) = 0;
	virtual std::queue<Selection>& inputFinished(std::queue<Selection>& selections, std::streampos end) = 0;

public:
	Selector(void);

	virtual ~Selector(void);

	std::queue<Selection>& select(std::queue<Selection>& selections, InputCharWrapper& input);
	std::queue<Selection>& endInput(std::queue<Selection>& selections, std::streampos at);

	void decorate(Selector* selector);
};

