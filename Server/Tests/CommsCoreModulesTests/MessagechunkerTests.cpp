#include "stdafx.h"
#include "../../ServerCoreModules/CoreModules/Comms/Transever/MessageChunker.h"


BOOST_AUTO_TEST_CASE(MessageChunkerConstructorTests)
{
	std::string message("a testMessage");
	MessageChunker chuker(10,message);

	std::string aLongMessage(100000,'a');
	MessageChunker chuker1(10,aLongMessage);

	std::string aShortMessage;
	MessageChunker chuker2(10,aShortMessage);
}

BOOST_AUTO_TEST_CASE(MessageChunkerChunkTestsNormal)
{
	std::list<std::string> output;
	
	std::string message("a testMessage");
	MessageChunker chuker(1,message);

	chuker.Chunk_Message(output);
	BOOST_CHECK_EQUAL(13, output.size());


}

BOOST_AUTO_TEST_CASE(MessageChunkerChunkTestsLargeString)
{

	std::list<std::string> output;

	std::string aLongMessage(100000,'a');
	MessageChunker chuker(10,aLongMessage);

	chuker.Chunk_Message(output);
	BOOST_CHECK_EQUAL(10000, output.size());

}


BOOST_AUTO_TEST_CASE(MessageChunkerChunkTestsEmptyString)
{
	std::list<std::string> output;

	std::string aShortMessage;
	MessageChunker chuker(10,aShortMessage);

	chuker.Chunk_Message(output);
	BOOST_CHECK_EQUAL(0, output.size());
}

BOOST_AUTO_TEST_CASE(MessageChunkerChunkTestsMediumSize)
{
	std::list<std::string> output;

	std::string aMessage(3700, 'a');
	MessageChunker chuker(2048,aMessage);

	chuker.Chunk_Message(output);
	BOOST_CHECK_EQUAL(2, output.size());

	std::list<std::string>::iterator output_chunks = output.begin();
	std::string first_chunk = *output_chunks;
	std::string second_chunk = *(++output_chunks);
	BOOST_CHECK_EQUAL(2048, first_chunk.size());
	BOOST_CHECK_EQUAL(1652, second_chunk.size());

}



