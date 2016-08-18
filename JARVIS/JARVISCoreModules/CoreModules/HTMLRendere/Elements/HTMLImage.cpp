#include "HTMLImage.h"


HTMLImage::HTMLImage(std::string name, std::string url) : IElement(name), url(url)
{
	this->addAttribute("src=\""+this->url+"\"");
}

HTMLImage::~HTMLImage()
{

}
