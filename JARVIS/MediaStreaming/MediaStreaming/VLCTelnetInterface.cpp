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

	boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));
	io_service.poll();

	writeString("mediaPWLOL", c);
	io_service.poll();
	io_service.poll();
	writeString("new "+deviceName+" broadcast enabled", c);
	io_service.poll();
	io_service.poll();
	writeString(create_inputString(playlist, deviceName),c);
	io_service.poll();
	io_service.poll();
	writeString("setup "+deviceName+" output #transcode{vcodec=none,acodec=mp3,ab=128,channels=2,samplerate=44100}:http{mux=raw,dst=:8080/"+deviceName+"}",c);
	io_service.poll();
	io_service.poll();
	writeString("control "+deviceName+" play",c);
	io_service.poll();
	io_service.poll();
	c.close();
	t.join();

	// vlc http://localhost:8080/current
}

std::string VLCTelnetInterface::create_inputString(MusicPlaylist& playlist, std::string& deviceName)
{
	std::stringstream inputString;

	inputString << "setup "<< deviceName<< " ";
	for(auto song : playlist.getSongs())
	{
		inputString << "input "<< song.getURL()<< " ";
	}

	return inputString.str();
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
