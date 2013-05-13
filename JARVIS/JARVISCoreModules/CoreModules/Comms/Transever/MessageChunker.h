#pragma once
#ifndef _MESSAGE_CHUNKER_
#define _MESSAGE_CHUNKER_

#include <string>
#include <list>

class MessageChunker
{
private:
	std::string& message;
	int chunkSize;
	unsigned messageLength;

public:
	MessageChunker(int chunksize, std::string& message);
	~MessageChunker(void);

	void chunkMessage(std::list<std::string>& chunks);
};

#endif