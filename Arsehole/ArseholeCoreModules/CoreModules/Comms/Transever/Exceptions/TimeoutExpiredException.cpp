/*
	Author : Craig Matear
*/
#include "TimeoutExpiredException.h"



namespace coremodules {
namespace comms {
namespace transever {
namespace exceptions {



TimeoutExpiredException::TimeoutExpiredException(const std::string& error_message) :std::runtime_error(error_message)
{

}



TimeoutExpiredException::~TimeoutExpiredException() throw()
{
}






}
}
}
}



