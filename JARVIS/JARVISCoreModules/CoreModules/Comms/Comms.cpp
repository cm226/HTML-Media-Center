/*
 * Comms.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: craig
 */


#include "Comms.h"
#include "Transever/TCPTransever.h"
#include "JSON/JSONCURLRequest.h"

#include <boost/thread.hpp>



Comms::Comms(){
	this->transever = new TCPTransever(45001);
	this->listening = false;
}

Comms::~Comms() {
	delete this->transever;
}

void Comms::startComms()
{
	this->listening = true;

	boost::thread listenForConnectionThread(boost::bind(&Comms::connectionListener, this));

}

void Comms::stopComms()
{
	this->listening = false;
	this->transever->shutdown();

}

void Comms::connectionListener()
{
	while(this->listening)
	{
		int haveConnection = this->transever->listenForConnection(5);
		if(haveConnection)
		{
			AbstractMessage* recevedMessage = this->transever->getMessageOrTimeout(5000);
			if(recevedMessage != NULL)
			{
				AbstractMessage* reply =  recevedMessage->actionMessage();
				this->transever->sendMessage(reply);
				delete reply;
			}
		}

	}
}

CommsNS::IJSONRequest* Comms::createJSONRequest()
{
	CommsNS::CurlManager &manager = this->curlMan;

	return new CommsNS::JSONCURLRequest(manager);
}

bool Comms::downloadFile(std::string const& URL, std::string const& fileName)
{
	return this->curlMan.downloadItemToFile(URL,fileName);
}




