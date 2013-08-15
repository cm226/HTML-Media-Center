#include "VLCTelnetInterface.h"

#include <boost\asio.hpp>

#include <sstream>
#include <stdlib.h>


VLCTelnetInterface::VLCTelnetInterface(void)
{
}


VLCTelnetInterface::~VLCTelnetInterface(void)
{
}

void VLCTelnetInterface::startup_VLC()
{
	system("vlc --ttl 1 -vvv --intf telnet --telnet-port 4212 --telnet-password mediaPWLOL 2>&1");
}

void VLCTelnetInterface::Play_Playlist(std::string ip, std::string deviceName,  MusicPlaylist& playlist)
{
	using namespace boost::asio::ip;

	boost::asio::io_service io_service;
		// resolve the host name and port number to an iterator that can be used to connect to the server
	std::string buffer;
	tcp::resolver resolver(io_service);
	tcp::resolver::query query("localhost", "4212");
	tcp::resolver::iterator iterator = resolver.resolve(query);
	
	telnet_client c(io_service, iterator);

	io_service.run();
	
	writeString("mediaPWLOL", c);
	writeString("new "+deviceName+" broadcast enabled", c);

	std::stringstream inputString;

	inputString << "setup "<< deviceName<< " ";
	for(auto song : playlist.getSongs())
	{
		inputString << "input "<< song.getURL()<< " ";
	}
	writeString(inputString.str(),c);
	writeString("setup "+deviceName+" output #standard{access=http,mux=ts,dst=192.168.1.199:8080/"+deviceName+"}",c);
	writeString("control "+deviceName+" play\r\n",c);

	c.close();
	io_service.stop();
}

void VLCTelnetInterface::writeString(std::string msg, telnet_client& client)
{
	for(auto c : msg)
	{
		client.write(c);
	}
	client.write('\n');
	client.write('\r');
}
