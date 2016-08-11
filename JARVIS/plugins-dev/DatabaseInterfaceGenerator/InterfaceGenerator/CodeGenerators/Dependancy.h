/*
 * Dependancy.h
 *
 *  Created on: 22 Apr 2013
 *      Author: craig
 */

#ifndef DEPENDANCY_H_
#define DEPENDANCY_H_
#include <string>

namespace CodeGenerators {

class Dependancy
{
private:
	std::string standardLibraryDependancy;
	std::string pathToDependacyFile;
	std::string dependancyName;

public:
	Dependancy();
	virtual ~Dependancy();

	void setStandardLibraryDependancy(std::string dep);
	std::string getStandardLibraryDependancy();

	void setPathToDependancy(std::string path);
	std::string getPathToDependancy();

	void setDependancyName(std::string name);
	std::string getDependancyName();
};

} /* namespace CodeGenerators */
#endif /* DEPENDANCY_H_ */
