#pragma once
#ifndef _MESSAGE_CHUNKER_
#define _MESSAGE_CHUNKER_

#include <string>
#include <list>

class MessageChunker
{
private:
	std::string& _message;
	int _chunkSize;
	unsigned _messageLength;

	unsigned _current_chunk_begin_char;
	unsigned _current_chunk_end_char;

	void increment_chunk();
	std::string take_chunk();

public:
	MessageChunker(int chunksize, std::string& message);
	~MessageChunker(void);

	void Chunk_Message(std::list<std::string>& chunks);
	
};

#endif