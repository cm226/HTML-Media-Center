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

	this->messageTranslater = new Translater();
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
			std::string message;
			this->transever->getMessage(&message);
			unsigned int msgLen = (unsigned int)message.length();
			AbstractMessage* msg = this->messageTranslater->translateMessage(message.c_str(),msgLen);

			if(msg != NULL)
			{
				std::string messageReply;
				msg->actionMessage(&messageReply);
				this->transever->sendMessage(&messageReply);
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




