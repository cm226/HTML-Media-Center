/*
 * MusicPlaylist.h
 *
 *  Created on: 16 Jul 2013
 *      Author: craig
 */

#ifndef MUSICPLAYLIST_H_
#define MUSICPLAYLIST_H_

#include <list>

#include "../../IElement.h"
#include "../../../exportMacros.h"
#include "Song.h"


namespace coremodules {
namespace htmlrendere {
namespace elements {

class MusicPlaylist : public IElement
{
private:
	std::list<Song> _songs;

	void writeSongLength(Song& song, std::stringstream& ss);
protected:
	std::string getTagText();
	std::string getTagContent();

public:
	MusicPlaylist();
	virtual ~MusicPlaylist();

	void addSong(Song& song);
	std::list<Song>& getSongs();

	std::string getText();

};

} /* namespace elements */
} /* namespace htmlrendere */
} /* namespace coremodules */
#endif /* MUSICPLAYLIST_H_ */
