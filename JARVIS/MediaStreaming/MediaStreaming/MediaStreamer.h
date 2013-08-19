#pragma once

#include "AudioDevice.h"
#include "MusicPlaylist.h"
#include "exportMacros.h"

#include <unordered_map>

class DLLMEDIA_STREAM_API MediaStreamer
{
private:
	#pragma warning( disable : 4251)
	std::unordered_map<int,AudioDevice> audioDevices;
	#pragma warning( default : 4251)

public:
	MediaStreamer(void);
	~MediaStreamer(void);


	void Get_Audio_Devices(std::list<AudioDevice>& devices);
	bool Try_Get_Audio_Device_From_ID(AudioDevice& device, int id);
};

