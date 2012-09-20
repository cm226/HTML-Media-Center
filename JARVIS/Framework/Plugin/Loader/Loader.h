/*
 * Loader.h
 *
 *  Created on: Sep 20, 2012
 *      Author: craig
 */

#ifndef LOADER_H_
#define LOADER_H_

#include <string>

class Loader {
public:
	Loader(std::string fileDir);

	bool loadPlugin(std::string pluginName);

	void listPlugins(std::string* outBuffer, int outBufferSize);
	int numOfPlugins();

	virtual ~Loader();
};

#endif /* LOADER_H_ */
