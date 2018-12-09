/*
 * MusicPlaylist.h
 *
 *  Created on: 16 Jul 2013
 *      Author: craig
 */

#pragma once

#include <list>

#include "exportMacros.h"
#include "Song.h"


class DLLMEDIA_STREAM_API MusicPlaylist
{
private:
	#pragma warning( disable : 4251)
	std::list<Song> _songs;
	#pragma warning( default : 4251)

public:
	MusicPlaylist();
	virtual ~MusicPlaylist();

	void addSong(Song& song);
	std::list<Song>& getSongs();

};


