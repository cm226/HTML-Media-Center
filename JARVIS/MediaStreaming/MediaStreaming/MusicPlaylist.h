/*
 * MusicPlaylist.h
 *
 *  Created on: 16 Jul 2013
 *      Author: craig
 */

#pragma once

#include <list>

#include "Song.h"


class MusicPlaylist
{
private:
	std::list<Song> _songs;

public:
	MusicPlaylist();
	virtual ~MusicPlaylist();

	void addSong(Song& song);
	std::list<Song>& getSongs();

};


