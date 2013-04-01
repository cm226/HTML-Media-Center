#include "Hyperlink.h"


Hyperlink::Hyperlink(std::string name, std::string url, std::string lable) :  IElement(name) 
{
	this->url = url;
	this->lable = lable;

	this->addAttribute("href=\""+url+"\"");
}


Hyperlink::~Hyperlink(void)
{
}
