#include "FileSystem.h"
#include "../config.h"
#include "../../../ErrorLogger/Errors/ErrorLogger.h"



FileSystem::FileSystem()
{
	std::string tempLocation(HTMLMEDIAPUBLIC);
	tempLocation.append(TEMPLOC);

	this->_watched_dirs.push_back(Directory(WORKING_FILES));
	this->_watched_dirs.push_back(Directory(tempLocation));
	
}

FileSystem::~FileSystem()
{

}



void FileSystem::RetrieveNewFiles(std::string extention,
									std::list<std::wstring>& files)
{
	std::list<Directory>::iterator directorys = this->_watched_dirs.begin();
	for (; directorys != this->_watched_dirs.end();
	directorys++)
	{
		directorys->Search(extention, files);
	}

}
