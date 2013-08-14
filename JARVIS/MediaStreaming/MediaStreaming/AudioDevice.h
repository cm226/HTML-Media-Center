#pragma once

#include <string>

#include "MusicPlaylist.h"

class AudioDevice
{
public:
	enum DEVICE_STATE{BUSSY, READY};

private:
	static int id_counter;
	int myID;

	DEVICE_STATE getState();
	void setID();

public:
	AudioDevice(void);
	~AudioDevice(void);

	void Start_Audio_Stream(MusicPlaylist& playlist);
	int getID();

	void Pause_CurrentStream();
	void Play_CurrentStream();
	void Vol_UP();
	void Vol_Down();


};



