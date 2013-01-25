/*
 * Comms.h
 *
 *  Created on: Sep 26, 2012
 *      Author: craig
 */

#ifndef COMMS_H_
#define COMMS_H_

#include <string>
#include "../Errors/ErrorLogger.h"

#include "Transever/AbstractTransever.h"
#include "MessageTranslaters/Translater.h"
#include "IComms.h"
#include "CURL/CurlManager.h"


class Comms : public CommsNS::IComms{
private:
	AbstractTransever* transever;
	Translater* messageTranslater;
	CommsNS::CurlManager curlMan;

	bool listening;
	void connectionListener();

public:

	Comms();
	virtual ~Comms();

	void startComms();
	void stopComms();

	CommsNS::IJSONRequest* createJSONRequest();
	bool downloadFile(std::string const& URL, std::string const& fileName);


};

#endif /* COMMS_H_ */
