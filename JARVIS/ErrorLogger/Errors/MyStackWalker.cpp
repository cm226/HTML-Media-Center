#ifdef _WINDOWS

#include "MyStackWalker.h"
#include <iostream>



MyStackWalker::MyStackWalker(void) : StackWalker()
{
}

void MyStackWalker::OnOutput(LPCSTR szText)
{
	std::cerr << (szText);
	StackWalker::OnOutput(szText); 
 }

#endif
