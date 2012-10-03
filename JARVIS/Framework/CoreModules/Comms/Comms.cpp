/*
 * Comms.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: craig
 */


#include "Comms.h"
#include "Transever/TCPTransever.h"

#include <boost/thread.hpp>



Comms::Comms() {
	this->transever = new TCPTransever();
	this->PORT = 40051;
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
}

void Comms::connectionListener()
{
	while(this->listening)
	{
		int haveConnection = this->transever->listenForConnection(5);
		if(haveConnection)
		{

		}

	}
}



