/*
 * Song.h
 *
 *  Created on: 16 Jul 2013
 *      Author: craig
 */

#pragma once
#include <string>
#include "exportMacros.h"

class DLLMEDIA_STREAM_API Song {

private:
	#pragma warning( disable : 4251)
	std::string _name;
	std::string _url;
	#pragma warning( default : 4251)

public:
	Song(std::string name,std::string url);
	virtual ~Song();


	std::string getName(){return _name;}
	std::string getURL(){return _url;}
};

