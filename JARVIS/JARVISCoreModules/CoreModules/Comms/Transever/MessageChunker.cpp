#include "MessageChunker.h"


MessageChunker::MessageChunker(int chunksize, std::string& message)
	: _message(message),
	_chunkSize(chunksize)
{
	_messageLength = _message.size();
}


MessageChunker::~MessageChunker(void)
{

}

void MessageChunker::Chunk_Message(std::list<std::string>& chunks)
{
	_messageLength = _message.size();
	_current_chunk_begin_char = 0;
	_current_chunk_end_char = _chunkSize;

	while(_current_chunk_begin_char < _messageLength)
	{
		chunks.push_back(take_chunk());
		increment_chunk();
	}
}

void MessageChunker::increment_chunk()
{
	_current_chunk_begin_char += _chunkSize;
	_current_chunk_end_char += _chunkSize;

	if(_current_chunk_end_char > _messageLength)
		_current_chunk_end_char = _messageLength;
}


std::string MessageChunker::take_chunk()
{
	return _message.substr(_current_chunk_begin_char, _current_chunk_end_char - _current_chunk_begin_char);
}

