#include "stdafx.h"

#include "../JARVISCoreModules/CoreModules/Files/File/Base64FileDataURLSource.h"


BOOST_AUTO_TEST_SUITE(base64tests)
	BOOST_AUTO_TEST_CASE(base64Decode_0)
	{
		std::string URLData = "iVBORw0K";
		Base64FileDataURLSource decoder(URLData);

		std::vector<unsigned char> buffer(6);


		BOOST_CHECK_EQUAL(decoder.GetData(buffer), true);


		BOOST_CHECK_EQUAL(buffer[0], char(0x89));
		BOOST_CHECK_EQUAL(buffer[1], char(0x50));
		BOOST_CHECK_EQUAL(buffer[2], char(0x4E));

		BOOST_CHECK_EQUAL(buffer[3], char(0x47));
		BOOST_CHECK_EQUAL(buffer[4], char(0x0d));
		BOOST_CHECK_EQUAL(buffer[5], char(0x0A));
	}

BOOST_AUTO_TEST_CASE(base64decode_1)
{
	std::string URLData = "cmln";
	Base64FileDataURLSource decoder(URLData);

	size_t datasize = decoder.GetDataSize();
	std::vector<unsigned char> buffer(datasize);


	decoder.GetData(buffer);


	BOOST_CHECK_EQUAL(buffer[0], 'r');
	BOOST_CHECK_EQUAL(buffer[1], 'i');
	BOOST_CHECK_EQUAL(buffer[2], 'g');
}


BOOST_AUTO_TEST_CASE(base64BadEncodeing)
{
	std::string URLData = "i,BORw0K";
	Base64FileDataURLSource decoder(URLData);

	std::vector<unsigned char> buffer(6);


	BOOST_CHECK_EQUAL(decoder.GetData(buffer), false);
}

BOOST_AUTO_TEST_SUITE_END()