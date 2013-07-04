#include "SelectorsRunner.h"


SelectorsRunner::SelectorsRunner(Selector& rootSelectorm, InputWrapper input) : selector(rootSelectorm), input(input)
{
}


SelectorsRunner::~SelectorsRunner(void)
{
}


std::queue<Selection>& SelectorsRunner::run(std::queue<Selection>& selections)
{
	while(!input.isAtEnd())
		selector.select(selections, InputCharWrapper(input.nextChar(), input.getRawInput().tellg()));

	return selections;

}
