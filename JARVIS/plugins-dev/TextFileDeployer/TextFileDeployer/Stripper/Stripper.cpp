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
	copyUntill(input.fileLen()); // copy the remainder of the file
}

void Stripper::copyUntill(std::streampos end)
{
	//TODO check for buffer overrun
	int readTo = input.getRawInput().tellg();
	int readLen = (int)end - readTo;
	char* tempData = new char[readLen+1];
	input.getRawInput().read(tempData, readLen);
	tempData[readLen] = '\0';
	output << tempData;
	delete[] tempData;
}

