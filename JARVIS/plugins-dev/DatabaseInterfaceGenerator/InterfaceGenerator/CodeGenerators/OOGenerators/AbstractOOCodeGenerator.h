/*
 * AbstractOOCodeGenerator.h
 *
 *  Created on: 3 Jan 2013
 *      Author: craig
 */

#ifndef ABSTRACTOOCODEGENERATOR_H_
#define ABSTRACTOOCODEGENERATOR_H_

#include <string>
#include <type_traits>

#include "../ICodeGenerator.h"
#include "GenericClass.h"

namespace CodeGenerators {


class AbstractOOCodeGenerator : public ICodeGenerator {


public:
	AbstractOOCodeGenerator(std::string fileName);
	virtual ~AbstractOOCodeGenerator();


	virtual void addClass(GenericClass gclass) = 0;

	virtual void save() = 0;

};

} /* namespace CodeGenerators */
#endif /* ABSTRACTOOCODEGENERATOR_H_ */
