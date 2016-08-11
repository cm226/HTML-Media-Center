#pragma once

#include "Selectors/Selector.h"
#include "InputWrapper.h"

class SelectorsRunner
{
private:
	InputWrapper input;
	Selector& selector;

public:
	SelectorsRunner(Selector& rootSelectorm, InputWrapper input);
	~SelectorsRunner(void);

	std::queue<Selection>& run(std::queue<Selection>& selections);
};

