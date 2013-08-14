#pragma once

#include "AudioDevice.h"
#include "MusicPlaylist.h"

#include <unordered_map>

class MediaStreamer
{
private:
	std::unordered_map<int,AudioDevice> audioDevices;

public:
	MediaStreamer(void);
	~MediaStreamer(void);


	void Get_Audio_Devices(std::list<AudioDevice>& devices);
	bool Try_Get_Audio_Device_From_ID(AudioDevice& device, int id);
};

