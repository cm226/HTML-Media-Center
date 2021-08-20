#include "FileSystem.h"
#include "../config.h"
#include "../../../ErrorLogger/Errors/ErrorLogger.h"



FileSystem::FileSystem()
{
	auto config = Config::GetInstance();
	std::string tempLocation(config->TempLoc());

	this->_watched_dirs.push_back(Directory(config->WorkingFiles()));
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
