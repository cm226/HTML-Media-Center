/*
 * FileUpload.h
 *
 *  Created on: 16 May 2013
 *      Author: craig
 */

#ifndef FILEUPLOAD_H_
#define FILEUPLOAD_H_

#include "../IElement.h"
#include "../../exportMacros.h"

class DLLCORE_API FileUpload : public IElement
{
public:
	FileUpload(std::string name,int depth, CALLBACk_HANDLE handl, std::string pluginName);
	virtual ~FileUpload();

	/* IElement Overrides */
protected:
	virtual std::string getTagText();
	virtual std::string getTagContent();
};

#endif /* FILEUPLOAD_H_ */
