#pragma once

#include <sstream>
#include <queue>

#include "../Selection.h"
#include "../InputWrapper.h"


class Stripper
{
private:
	InputWrapper& input;
	std::ostringstream output;

public:
	Stripper(InputWrapper& input);
	virtual ~Stripper(void);
	std::ostringstream& getOutput();

	void strip(std::queue<Selection>& selections);
	void copyUntill(std::streampos end);
};

