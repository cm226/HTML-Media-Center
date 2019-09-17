/*
 * AbstractClass.cpp
 *
 *  Created on: 3 Jan 2013
 *      Author: craig
 */

#include "AbstractClass.h"

namespace CodeGenerators {



AbstractClass::AbstractClass(const std::string* name){


	this->name = std::string(*name);
}

AbstractClass::~AbstractClass() {

}




} /* namespace CodeGenerators */
