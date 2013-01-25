#ifndef _HTML_IMAGE_H
#define _HTML_IMAGE_H

#include "../IElement.h"
#include "../../exportMacros.h"

class DLLCORE_API HTMLImage : public IElement
{
private:
	std::string url;

protected:
	virtual std::string getTagText() {return "img";};
	virtual std::string getTagContent() { return ""; };

public:
	HTMLImage(std::string name, std::string url);
	virtual ~HTMLImage();



};

#endif