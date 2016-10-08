#include "stdafx.h"

#include "..\JARVISCoreModules\CoreModules\Files\Files.h"
#include <boost\filesystem.hpp>

BOOST_AUTO_TEST_SUITE(FileTests)
BOOST_AUTO_TEST_CASE(FileSaveTest)
{
	std::string base64Data = "iVBORw0K";
	std::string filename = "fileSaveTest.bin";

	File uploadedFile(std::make_shared<Base64FileDataURLSource>(base64Data));
	uploadedFile.SetLocation(Directory("C:\\Users\\cmate_000\\Documents\\JARVIS_temp\\"), filename);

	bool sucess = uploadedFile.Save();
	BOOST_CHECK_EQUAL(sucess, true);
	BOOST_CHECK_EQUAL(boost::filesystem::exists("C:\\Users\\cmate_000\\Documents\\JARVIS_temp\\fileSaveTest.bin"), true);


}

BOOST_AUTO_TEST_SUITE_END()