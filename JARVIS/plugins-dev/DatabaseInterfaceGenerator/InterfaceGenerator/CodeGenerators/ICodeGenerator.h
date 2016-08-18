/*
 * ICodeGenerator.h
 *
 *  Created on: 3 Jan 2013
 *      Author: craig
 */

#ifndef ICODEGENERATOR_H_
#define ICODEGENERATOR_H_


#include <string>

namespace CodeGenerators {

class ICodeGenerator {

protected:
	std::string fileName;


public:
	ICodeGenerator(std::string fileName);
	virtual ~ICodeGenerator();

	virtual void save() = 0;

	


};

} /* namespace CodeGenerators */
#endif /* ICODEGENERATOR_H_ */
