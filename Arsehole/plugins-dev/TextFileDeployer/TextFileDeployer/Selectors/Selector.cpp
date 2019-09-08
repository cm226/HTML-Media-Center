#include "Selector.h"


Selector::Selector(void) : decorating(NULL)
{
}


Selector::~Selector(void)
{
}

std::queue<Selection>& Selector::select(std::queue<Selection>& selections, InputCharWrapper& input)
{
	//TODO make parallel may need to look at the queue for prarell opperations
	if(this->decorating ==NULL)
		return nextChar(selections, input);
	else
		return nextChar(this->decorating->select(selections, input), input);
}

std::queue<Selection>& Selector::endInput(std::queue<Selection>& selections, std::streampos at)
{
	//TODO make parallel may need to look at the queue for prarell opperations
	if(this->decorating ==NULL)
		return inputFinished(selections, at);
	else
		return inputFinished(this->decorating->endInput(selections, at), at);
}

void Selector::decorate(Selector* selector)
{
	decorating = selector;
}