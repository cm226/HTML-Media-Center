#pragma once

#include<string>
#include "MusicPlaylist.h"
#include "telnet.h"

class VLCTelnetInterface
{
private:
	void writeString(std::string msg, telnet_client& client);
	void startup_VLC();

public:
	VLCTelnetInterface(void);
	~VLCTelnetInterface(void);

	void Play_Playlist(std::string ip, std::string deviceName,  MusicPlaylist& playlist);


};

