#include "MessageChunker.h"


MessageChunker::MessageChunker(int chunksize, std::string& message): message(message)
{
	this->chunkSize = chunksize;
	this->messageLength = this->message.size();
}


MessageChunker::~MessageChunker(void)
{

}

void MessageChunker::chunkMessage(std::list<std::string>& chunks)
{
	unsigned messageLength = this->message.size();
	unsigned nextChunkStart = 0;
	while(nextChunkStart < messageLength)
	{
		unsigned nextChunkEnd = nextChunkStart+this->chunkSize;
		unsigned chunkSize = this->chunkSize;
		if(nextChunkEnd > messageLength)
			chunkSize = nextChunkEnd - messageLength;

		std::string nextChunk = this->message.substr(nextChunkStart,chunkSize);
		chunks.push_back(nextChunk);

		nextChunkStart = nextChunkEnd;
	}
}
