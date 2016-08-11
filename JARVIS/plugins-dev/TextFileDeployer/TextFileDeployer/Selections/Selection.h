#pragma once
#include <istream>

class Selection
{
private:
	std::streampos selection_Start;
	std::streampos selection_End;

public:
	Selection(std::streampos selection_start, std::streampos selection_len);
	~Selection(void);

	std::streampos getSelectionStart();
	std::streampos getSelectionEnd();
};

