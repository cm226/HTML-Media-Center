#ifndef _HTML_IMAGE_H
#define _HTML_IMAGE_H

#include "../IElement.h"
#include "../../exportMacros.h"

class DLLCORE_API HTMLImage : public IElement
{
private:
	#pragma warning( disable : 4251)
	std::string url;
	#pragma warning( default : 4251)

protected:
	virtual std::string getTagText() {return "img";};
	virtual std::string getTagContent() { return ""; };

public:
	HTMLImage(std::string name, std::string url);
	virtual ~HTMLImage();



};

#endif