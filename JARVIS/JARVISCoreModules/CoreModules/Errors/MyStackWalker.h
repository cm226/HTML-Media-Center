#pragma once
#include "StackWalker\StackWalker.h"

class MyStackWalker : public StackWalker
{
	public:
		MyStackWalker();

protected:
		virtual void OnOutput(LPCSTR szText);

};

