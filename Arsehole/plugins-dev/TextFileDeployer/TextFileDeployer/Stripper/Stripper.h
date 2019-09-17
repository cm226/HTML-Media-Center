#pragma once

#include <sstream>
#include <queue>

#include "../Selections/Selection.h"
#include "../InputWrapper.h"


class Stripper
{
private:
	InputWrapper& input;
	std::ostringstream output;

	void copyUntill(std::streampos end);
public:
	Stripper(InputWrapper& input);
	virtual ~Stripper(void);
	std::ostringstream& getOutput();

	void strip(std::queue<Selection>& selections);

};

