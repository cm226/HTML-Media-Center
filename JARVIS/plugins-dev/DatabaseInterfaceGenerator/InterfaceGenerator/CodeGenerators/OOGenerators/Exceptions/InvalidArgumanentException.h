/*
 * InvalidArgumanentException.h
 *
 *  Created on: 7 Jan 2013
 *      Author: craig
 */

#ifndef INVALIDARGUMANENTEXCEPTION_H_
#define INVALIDARGUMANENTEXCEPTION_H_

#include <exception>

namespace CodeGenerators {

class argumentExeption: public std::exception
{
  virtual const char* what() const throw()
  {
    return "Invalid Argument Exception";
  }
};

} /* namespace CodeGenerators */
#endif /* INVALIDARGUMANENTEXCEPTION_H_ */
