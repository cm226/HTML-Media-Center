/*
 * FileUpload.cpp
 *
 *  Created on: 16 May 2013
 *      Author: craig
 */

#include "FileUpload.h"

#include "../../config.h"

FileUpload::FileUpload(std::string name, CALLBACk_HANDLE handl, std::string pluginName) : IElement(name)
{
	std::string uploadLocationString = buildCallbackLocationString(handl,pluginName);

	this->appendEmbeddedJSCode("var uploadLocation = \""+uploadLocationString+"\";");

	this->includeCSS("http://" + std::string(HOST) + "/HTML-Media-Center/public/css/HTMLRendereCSS/UploadElementStyle.css");

	this->includeJS("http://" + std::string(HOST) + "/HTML-Media-Center/public/js/HTMLRendereJS/UploadSingleElementJavascript.js");
	//this->includeJS("http://" + std::string(HOST) + "/HTML-Media-Center/public/js/HTMLRendereJS/UploadElementJavascript.js");
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



