/*
	Author : Craig Matear
*/
#include "StringMessageSerializer.h"



namespace coremodules {
namespace comms {
namespace messagetranslaters {



StringMessageSerializer::StringMessageSerializer()
{

}



StringMessageSerializer::~StringMessageSerializer()
{

}



std::string StringMessageSerializer::serialize()
{
	return this->msg.str();
}




}
}
}



