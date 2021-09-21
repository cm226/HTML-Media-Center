#pragma once

#include "Devices/AudioDevice.h"
#include "MusicPlaylist.h"
#include "exportMacros.h"
#include "Devices/DeviceList.h"

#include "Devices/DeviceList.h"

class DLLMEDIA_STREAM_API MediaStreamer
{
private:
	#pragma warning( disable : 4251)
	Devices::DeviceList _device_List;
	#pragma warning( default : 4251)

public:
	MediaStreamer(void);
	~MediaStreamer(void);


	void Resend_Agent_Handshake_Message();
	void Get_Audio_Devices(std::list<AudioDevice>& devices);
	bool Try_Get_Audio_Device_From_ID(AudioDevice& device, int id);
};

