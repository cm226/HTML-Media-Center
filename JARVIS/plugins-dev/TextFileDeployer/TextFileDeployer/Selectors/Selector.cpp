#include "Selector.h"


Selector::Selector(void) : decorating(NULL)
{
}


Selector::Selector(Selector* decorator) : decorating(decorator)
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
