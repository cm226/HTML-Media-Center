#include "Selection.h"


Selection::Selection(std::streampos selection_start, std::streampos selection_end) :
	selection_Start(selection_start),
	selection_End(selection_end)
{
}


Selection::~Selection(void)
{
}

std::streampos Selection::getSelectionStart()
{
	return this->selection_Start;
}
std::streampos Selection::getSelectionEnd()
{
	return this->selection_End;
}
