/*
 * FileUpload.cpp
 *
 *  Created on: 16 May 2013
 *      Author: craig
 */

#include "FileUpload.h"

FileUpload::FileUpload(std::string name,int depth, CALLBACk_HANDLE handl, std::string pluginName) : IElement(name)
{
	std::string uploadLocationString = buildCallbackLocationString(depth,handl,pluginName,"Upload");

	this->appendEmbeddedJSCode("var uploadLocation = \""+uploadLocationString+"\";");
	this->includeCSS("../../public/css/HTMLRendereCSS/UploadElementStyle.css");
	this->includeJS("../../public/js/HTMLRendereJS/UploadElementJavascript.js");
}

FileUpload::~FileUpload()
{

}


std::string FileUpload::getTagText()
{
	return "div";
}

std::string FileUpload::getTagContent()
{
	return "<div id=\"drop-files\" ondragover=\"return false\"> <!-- ondragover for firefox -->"
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
			"</div>";
}



