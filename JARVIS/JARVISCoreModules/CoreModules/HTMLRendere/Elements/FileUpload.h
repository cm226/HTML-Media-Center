/*
 * FileUpload.h
 *
 *  Created on: 16 May 2013
 *      Author: craig
 */

#ifndef FILEUPLOAD_H_
#define FILEUPLOAD_H_

#include "../IElement.h"

class FileUpload : public IElement
{
public:
	FileUpload(std::string name);
	virtual ~FileUpload();
	void setOnUploadCallback(int depth, CALLBACk_HANDLE handl, std::string pluginName);

	/* IElement Overrides */

	std::string getTagText();
	std::string getTagContent();
};

#endif /* FILEUPLOAD_H_ */
