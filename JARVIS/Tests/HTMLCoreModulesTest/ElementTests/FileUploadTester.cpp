#include "../stdafx.h"
#include "../../../JARVISCoreModules/CoreModules/HTMLRendere/Elements/FileUpload.h"


BOOST_AUTO_TEST_CASE(FileUploadConstructorTests)
{
	BOOST_CHECK_NO_THROW(FileUpload fileUploadElement("fileUpload"));
}

BOOST_AUTO_TEST_CASE(FileUploadgetTextTest)
{
	FileUpload fileUploadElement("fileUpload");
	std::string html = fileUploadElement.getText();
	std::string teargetHTML ="<div class=\"fileUpload\"><div id=\"drop-files\" ondragover=\"return false\"> <!-- ondragover for firefox -->"
				"Drop Files Here"
			"</div>"
			"<div id=\"uploaded-holder\">"
				"<div id=\"dropped-files\">"
					"<div id=\"upload-button\">"
						"<a href=\"#\" class=\"upload\"><i class=\"ss-upload\"> </i> Upload!</a>"
						"<a href=\"#\" class=\"delete\"><i class=\"ss-delete\"> </i></a>"
						"<span>0 Files</span>"
					"</div>"
				"</div>"
				"<div id=\"extra-files\">"
					"<div class=\"number\">"
						"0"
					"</div>"
					"<div id=\"file-list\">"
						"<ul></ul>"
					"</div>"
				"</div>"
			"</div>"
			"<div id=\"loading\">"
				"<div id=\"loading-bar\">"
					"<div class=\"loading-color\"> </div>"
				"</div>"
				"<div id=\"loading-content\">Uploading file.jpg</div>"
			"</div></div>";

	BOOST_CHECK_EQUAL(0,html.compare(teargetHTML));
}
