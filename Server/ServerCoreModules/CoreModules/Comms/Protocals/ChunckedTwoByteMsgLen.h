#pragma once

#include <boost/asio.hpp>
#include <list>
#include "../MessageTranslaters/Translater.h"
#include "../../../../Comms/Protocals/IProtocal.h"
#include "TwoByteMsgLen.h"

class ChunckedTwoByteMsgLen : public coremodules::comms::protocals::IProtocal
{
private:
	boost::asio::ip::tcp::socket& socket;
	Translater messageTranslater;

	TwoByteMsgLen _subprotocal;
	void constructWholeMessage(char* wholeMsgBuf, std::vector<std::pair<char*, int>> messages);

public:
	ChunckedTwoByteMsgLen(boost::asio::ip::tcp::socket& socket);
	virtual ~ChunckedTwoByteMsgLen();

	AbstractMessage* getMessageOrTimeout(unsigned timoutMiliseconds);
	void sendMessage(AbstractMessage* data);

};