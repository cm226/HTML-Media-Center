/*
 * MusicPlayer.h
 *
 *  Created on: 16 Jul 2013
 *      Author: craig
 */

#ifndef MUSICPLAYER_H_
#define MUSICPLAYER_H_

#include "../../IElement.h"
#include "../../../exportMacros.h"
#include "MusicPlaylist.h"

namespace coremodules {
namespace htmlrendere {
namespace elements {

class DLLCORE_API MusicPlayer : public IElement
{
private:
	MusicPlaylist& _playlist;
	CALLBACk_HANDLE _onPlaylistfinished;

	#pragma warning( disable : 4251)
	std::string playlistHTML;
	#pragma warning( default : 4251)

	void buildPlaylistHTML(MusicPlaylist& playlist);

protected:
	std::string getTagText();
	std::string getTagContent();

public:
	MusicPlayer(CALLBACk_HANDLE onPlaylistfinished, MusicPlaylist& playlist);
	virtual ~MusicPlayer();


};

} /* namespace elements */
} /* namespace htmlrendere */
} /* namespace coremodules */
#endif /* MUSICPLAYER_H_ */
