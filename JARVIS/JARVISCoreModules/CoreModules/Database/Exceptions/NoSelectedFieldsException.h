/*
 * NoSelectedFieldsException.h
 *
 *  Created on: Jan 20, 2013
 *      Author: craig
 */

#ifndef NOSELECTEDFIELDSEXCEPTION_H_
#define NOSELECTEDFIELDSEXCEPTION_H_

#include <stdexcept>
#include <string>

namespace Exceptions {

class NoSelectedFieldsException : public std::runtime_error{
public:
	NoSelectedFieldsException(std::string const& msg) : std::runtime_error(msg){};
};

} /* namespace Comms */
#endif /* NOSELECTEDFIELDSEXCEPTION_H_ */
