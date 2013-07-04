#include "Stripper.h"


Stripper::Stripper(InputWrapper& input) :
	input(input)
{

}



Stripper::~Stripper(void)
{
}

std::ostringstream& Stripper::getOutput()
{
	return output;
}
	
void Stripper::strip(std::queue<Selection>& selections)
{
	while(!selections.empty())
	{
		Selection selection = selections.front();
		copyUntill(selection.getSelectionStart());
		input.getRawInput().seekg(selection.getSelectionEnd());
		selections.pop();
	}
}

void Stripper::copyUntill(std::streampos end)
{
	//TODO check for buffer overrun
	int readLen = end - input.getRawInput().tellg();
	char* tempData = new char[readLen];
	input.getRawInput().read(tempData, readLen);
	output << tempData;
	delete[] tempData;
}

