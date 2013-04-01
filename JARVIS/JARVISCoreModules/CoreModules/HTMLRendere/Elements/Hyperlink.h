#ifndef HYPERLINK_H
#define HYPERLINK_H

#include "../IElement.h"
#include "../../exportMacros.h"

class DLLCORE_API Hyperlink: public IElement 
{

private:
	std::string url, lable;

	virtual std::string getTagText() {return "a";};
	virtual std::string getTagContent() { return this->lable; };

public:
	Hyperlink(std::string name, std::string url, std::string lable);
	~Hyperlink(void);
};

#endif

