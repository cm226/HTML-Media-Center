#include "stdafx.h"
#include "../../JARVISCoreModules/CoreModules/Comms/Transever/MessageChunker.h"


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

	chuker.chunkMessage(output);
	BOOST_CHECK_EQUAL(13, output.size());


}

BOOST_AUTO_TEST_CASE(MessageChunkerChunkTestsLargeString)
{

	std::list<std::string> output;

	std::string aLongMessage(100000,'a');
	MessageChunker chuker(10,aLongMessage);

	chuker.chunkMessage(output);
	BOOST_CHECK_EQUAL(10000, output.size());

}


BOOST_AUTO_TEST_CASE(MessageChunkerChunkTestsEmptyString)
{
	std::list<std::string> output;

	std::string aShortMessage;
	MessageChunker chuker(10,aShortMessage);

	chuker.chunkMessage(output);
	BOOST_CHECK_EQUAL(0, output.size());
}



