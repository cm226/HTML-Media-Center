#pragma once

#include <string>

#include "MusicPlaylist.h"
#include "exportMacros.h"

class DLLMEDIA_STREAM_API AudioDevice
{
public:
	enum DEVICE_STATE{BUSSY, READY};

private:
	static int id_counter;
	int myID;

	#pragma warning( disable : 4251)
	std::string _ip;
	#pragma warning( default : 4251)

	DEVICE_STATE getState();
	void setID();

public:

	AudioDevice();
	~AudioDevice(void);

	void Set_IP(std::string ip);
	void Start_Audio_Stream(MusicPlaylist& playlist);
	int getID();
	std::string Get_Name();

	void Pause_CurrentStream();
	void Play_CurrentStream();
	void Vol_UP();
	void Vol_Down();


};



