/*
 * AbstractClass.h
 *
 *  Created on: 3 Jan 2013
 *      Author: craig
 */

#ifndef ICLASSWRITTER_H_
#define ICLASSWRITTER_H_

#include <string>

namespace CodeGenerators {

class IClassWritter {

public:
	virtual void write(std::string* folder) = 0;
	virtual ~IClassWritter(){};

};

} /* namespace CodeGenerators */
#endif /* ABSTRACTCLASS_H_ */
