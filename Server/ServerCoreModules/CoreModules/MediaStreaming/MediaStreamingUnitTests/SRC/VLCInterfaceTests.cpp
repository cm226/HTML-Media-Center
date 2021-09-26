#include "stdafx.h"
#include "../../MediaStreaming/VLCTelnetInterface.h"

#include <boost/asio.hpp>

enum { max_length = 1024 };

BOOST_AUTO_TEST_CASE(Play_Playlist)
{
	VLCTelnetInterface vlc;
	MusicPlaylist playlist;
	Song s("test", "C:\\test.mp3");

	playlist.addSong(s);
	vlc.Play_Playlist("127.0.0.1","1", playlist);
}