/*
 * Song.h
 *
 *  Created on: 16 Jul 2013
 *      Author: craig
 */

#ifndef SONG_H_
#define SONG_H_

#include <string>
#include "../../../exportMacros.h"


namespace coremodules {
namespace htmlrendere {
namespace elements {

class Song {

private:
	std::string _name;
	std::string _artits;

	std::string _url;

	int _len_hour, _len_min, _len_sec;

public:
	Song(std::string name,std::string url, std::string artist);
	virtual ~Song();

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
#endif /* SONG_H_ */
