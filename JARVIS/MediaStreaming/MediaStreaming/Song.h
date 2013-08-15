/*
 * Song.h
 *
 *  Created on: 16 Jul 2013
 *      Author: craig
 */

#pragma once
#include <string>


class Song {

private:
	std::string _name;
	std::string _url;

public:
	Song(std::string name,std::string url);
	virtual ~Song();


	std::string getName(){return _name;}
	std::string getURL(){return _url;}
};

