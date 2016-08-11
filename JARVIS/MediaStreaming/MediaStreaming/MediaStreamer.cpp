#include "MediaStreamer.h"
#include "../../ErrorLogger/Errors/ErrorLogger.h"



MediaStreamer::MediaStreamer(void)
{
	ErrorLogger::logInfo("Initalising Audio Devices....");
	_device_List.Initalise_device_List();
}


MediaStreamer::~MediaStreamer(void)
{
}


void MediaStreamer::Resend_Agent_Handshake_Message()
{
	ErrorLogger::logInfo("Resending Agent Handshake");
	_device_List.Initalise_device_List();
}

void MediaStreamer::Get_Audio_Devices(std::list<AudioDevice>& devices)
{
	devices.clear();
	_device_List.Get_Audio_Devices(devices);
}

bool MediaStreamer::Try_Get_Audio_Device_From_ID(AudioDevice& device, int id)
{
	return _device_List.Try_Get_Audio_Device_From_ID(device, id);
}

