#include "MediaStreamer.h"
#include "../../ErrorLogger/Errors/ErrorLogger.h"



MediaStreamer::MediaStreamer(void)
{
	ErrorLogger::logInfo("Initalising Audio Devices....");
	
	/*ErrorLogger::logWarn("initalising dummy audio device: 192.168.0.198");
	AudioDevice dummy;
	dummy.Set_IP("192.168.0.198");
	this->audioDevices[dummy.getID()] = dummy;*/

}


MediaStreamer::~MediaStreamer(void)
{
}

void MediaStreamer::Initalise_Avalabale_Audio_Devices()
{
	audioDevices.Initalise_device_List();
}

void MediaStreamer::Get_Audio_Devices(std::list<AudioDevice>& devices)
{
	devices.clear();
	this->audioDevices.Get_Audio_Devices(devices);
}

bool MediaStreamer::Try_Get_Audio_Device_From_ID(AudioDevice& device, int id)
{
	return this->audioDevices.Try_Get_Audio_Device_From_ID(device,id);
}

