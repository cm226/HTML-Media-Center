/*
 * MusicPlaylist.cpp
 *
 *  Created on: 16 Jul 2013
 *      Author: craig
 */

#include "MusicPlaylist.h"

namespace coremodules {
namespace htmlrendere {
namespace elements {

MusicPlaylist::MusicPlaylist() : IElement("Playlist")
{


}

MusicPlaylist::~MusicPlaylist() {

}


std::string MusicPlaylist::getTagText()
{
	return "";
}
std::string MusicPlaylist::getTagContent()
{
	std::stringstream songHTMLstream;

	for(std::list<HTMLSong >::iterator songsIt = _songs.begin();
			songsIt != _songs.end(); songsIt++)
	{
		songHTMLstream << "{";
		songHTMLstream << "mp3: '" << songsIt->getURL() << "', " << std::endl;
		songHTMLstream << "title: '" << songsIt->getName() << "', "<< std::endl;
		songHTMLstream << "rating:0,"<< std::endl;
		writeSongLength(*songsIt, songHTMLstream);
		songHTMLstream << "cover: '../public/img/Music/Albums/default.png',"<< std::endl;
		songHTMLstream << "},";
	}
	return songHTMLstream.str();
}

std::string MusicPlaylist::getText()
{
	return getTagContent();
}

void MusicPlaylist::addSong(HTMLSong& song)
{
	_songs.push_back(song);
}

std::list<HTMLSong>& MusicPlaylist::getSongs()
{
	return _songs;
}

void MusicPlaylist::writeSongLength(HTMLSong& song, std::stringstream& ss)
{
	int hour, min, sec;
	song.getLength(hour, min, sec);
	ss << "duration: '" << hour << ":" << min << ":" << sec<<"',"<< std::endl;

}

} /* namespace elements */
} /* namespace htmlrendere */
} /* namespace coremodules */
