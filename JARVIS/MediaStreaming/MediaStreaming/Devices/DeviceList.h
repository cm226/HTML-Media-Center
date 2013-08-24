/*
 * DeviceList.h
 *
 *  Created on: 24 Aug 2013
 *      Author: craig
 */

#ifndef DEVICELIST_H_
#define DEVICELIST_H_


#include "AudioDevice.h"
#include <list>

namespace Devices {

class DeviceList {
private:

		std::list<AudioDevice> _audio_devices;
public:
	DeviceList();
	virtual ~DeviceList();

	void Initalise_device_List();
	std::list<AudioDevice>& Get_Audio_Devices();

};

} /* namespace Devices */
#endif /* DEVICELIST_H_ */
