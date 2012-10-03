
#include <stdio.h>


#include "Framework/FrameWork.h"
/*int main()
{
	JARVISFramework framework;
	framework.testEvents();

	return 0;
}*/

#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
        in(std::cin), in(), std::cout << (_1 * 3) << " " );
}
