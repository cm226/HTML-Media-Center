#include "AudioDevice.h"

int AudioDevice::id_counter;

AudioDevice::AudioDevice(void)
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

void AudioDevice::Start_Audio_Stream(MusicPlaylist& playlist)
{
	
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
