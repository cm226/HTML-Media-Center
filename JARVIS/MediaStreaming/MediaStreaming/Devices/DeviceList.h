/*
 * DeviceList.h
 *
 *  Created on: 24 Aug 2013
 *      Author: craig
 */

#ifndef DEVICELIST_H_
#define DEVICELIST_H_


#include "AudioDevice.h"
#include <unordered_map>

namespace Devices {

class DeviceList {
private:

	std::unordered_map<int, AudioDevice> _audio_devices;
	std::string build_Broadcast_Message();
public:
	DeviceList();
	virtual ~DeviceList();

	void Initalise_device_List();
	void Get_Audio_Devices(std::list<AudioDevice>& devices);
	bool Try_Get_Audio_Device_From_ID(AudioDevice& device, int id);

};

} /* namespace Devices */
#endif /* DEVICELIST_H_ */
