#include "SelectorsRunner.h"


SelectorsRunner::SelectorsRunner(Selector& rootSelectorm, InputWrapper input) :
	input(input),
	selector(rootSelectorm)
{
}


SelectorsRunner::~SelectorsRunner(void)
{
}


std::queue<Selection>& SelectorsRunner::run(std::queue<Selection>& selections)
{
	while(!input.isAtEnd())
	{
		InputCharWrapper nextChar = InputCharWrapper(input.nextChar(), input.getRawInput().tellg());
		selector.select(selections, nextChar);
	}

	return selections;

}
