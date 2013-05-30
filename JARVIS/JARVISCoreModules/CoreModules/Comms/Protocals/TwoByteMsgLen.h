/*
 * TwoByteMsgLen.h
 *
 *  Created on: 21 May 2013
 *      Author: craig
 */

#ifndef TWOBYTEMSGLEN_H_
#define TWOBYTEMSGLEN_H_

#include <boost/asio.hpp>
#include <list>
#include "../MessageTranslaters/Translater.h"
#include "IProtocal.h"


class TwoByteMsgLen : public coremodules::comms::protocals::IProtocal
{
private:
	boost::asio::ip::tcp::socket& socket;
	Translater messageTranslater;

	void sendMessageChunks(std::list<std::string>& chunks);
	bool isRequestNextDataMessage(AbstractMessage* msg);

public:
	TwoByteMsgLen(boost::asio::ip::tcp::socket& socket);
	virtual ~TwoByteMsgLen();

	AbstractMessage* getMessageOrTimeout(unsigned timoutMiliseconds);
	void sendMessage( AbstractMessage* data);

};

#endif /* TWOBYTEMSGLEN_H_ */
