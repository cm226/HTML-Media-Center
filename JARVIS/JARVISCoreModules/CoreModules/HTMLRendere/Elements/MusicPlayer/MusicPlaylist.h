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

class DLLCORE_API MusicPlaylist : public IElement
{
private:
	#pragma warning( disable : 4251)
	std::list<Song> _songs;
	#pragma warning( default : 4251)

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
