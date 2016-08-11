/*
 * MusicPlaylist.cpp
 *
 *  Created on: 16 Jul 2013
 *      Author: craig
 */

#include "MusicPlaylist.h"



MusicPlaylist::MusicPlaylist()
{


}

MusicPlaylist::~MusicPlaylist() {

}



void MusicPlaylist::addSong(Song& song)
{
	_songs.push_back(song);
}

std::list<Song>& MusicPlaylist::getSongs()
{
	return _songs;
}

