#include "AudioDevice.h"
#include "VLCTelnetInterface.h"

#include <sstream>

int AudioDevice::id_counter;

AudioDevice::AudioDevice()
{
	setID();
}


AudioDevice::~AudioDevice(void)
{

}


void AudioDevice::setID()
{
	this->myID  = AudioDevice::id_counter++;
}

void AudioDevice::Set_IP(std::string ip)
{
	_ip = ip;
}
int AudioDevice::getID()
{
	return this->myID;
}



void AudioDevice::Start_Audio_Stream(MusicPlaylist& playlist)
{
	VLCTelnetInterface vlc_interafce;
	std::stringstream ss;
	ss << this->myID;

	vlc_interafce.Play_Playlist(_ip, ss.str(), playlist);
}

std::string AudioDevice::Get_Name()
{
	return "Not Implemented";
}

void AudioDevice::Pause_CurrentStream()
{
	//TODO
}

void AudioDevice::Play_CurrentStream()
{
	//TODO
}

void AudioDevice::Vol_UP()
{
	//TODO
}

void AudioDevice::Vol_Down()
{
	//TODO
}
