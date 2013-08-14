/*
 * Song.h
 *
 *  Created on: 16 Jul 2013
 *      Author: craig
 */

#pragma once

#include <string>
#include "../../../exportMacros.h"


namespace coremodules {
namespace htmlrendere {
namespace elements {

class DLLCORE_API Song {

private:
	#pragma warning( disable : 4251)
	std::string _name;
	std::string _artits;
	std::string _url;
	#pragma warning( default : 4251)

	int _len_hour, _len_min, _len_sec;

public:
	Song(std::string name,std::string url, std::string artist);
	virtual ~Song(){};

	void setLength(int hours, int mins, int sec);

	std::string getName(){return _name;}
	std::string getArtist(){return _artits;}
	std::string getURL(){return _url;}

	void getLength(int& hour, int& min, int&sec)
	{
		hour = _len_hour;
		min = _len_min;
		sec = _len_sec;
	}

};

} /* namespace elements */
} /* namespace htmlrendere */
} /* namespace coremodules */
