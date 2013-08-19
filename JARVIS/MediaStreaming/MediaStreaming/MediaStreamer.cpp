#include "MediaStreamer.h"
#include "../../ErrorLogger/Errors/ErrorLogger.h"



MediaStreamer::MediaStreamer(void)
{
	ErrorLogger::logInfo("Initalising Audio Devices....");
	
	ErrorLogger::logWarn("initalising dummy audio device: 192.168.0.198");
	AudioDevice dummy;
	dummy.Set_IP("192.168.0.198");
	this->audioDevices[dummy.getID()] = dummy;

}


MediaStreamer::~MediaStreamer(void)
{
}

void MediaStreamer::Get_Audio_Devices(std::list<AudioDevice>& devices)
{
	devices.clear();
	
	for(auto kv : this->audioDevices)
	{
		devices.push_back(kv.second);
	} 
}

bool MediaStreamer::Try_Get_Audio_Device_From_ID(AudioDevice& device, int id)
{
	if(this->audioDevices.find(id) == this->audioDevices.end())
		return false;

	device = this->audioDevices[id];
	return true;
}

