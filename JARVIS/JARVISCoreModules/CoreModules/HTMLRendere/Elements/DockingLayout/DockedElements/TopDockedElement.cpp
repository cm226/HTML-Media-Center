#include "TopDockedElement.h"
#include <sstream>

namespace htmlrendere {
namespace elements {
namespace DockingLayoutElements
{

TopDockedElement::TopDockedElement(int size, IElement* element)
{
	this->setSize(size);
	this->element = element;
}


TopDockedElement::~TopDockedElement(void)
{
}




TopDockedElement::TopDockedElement()
{
	this->setSize(0);
	this->element = NULL;
}


void TopDockedElement::setElement(IElement* element)
{
	this->element = element;
}
void TopDockedElement::setSize(int size)
{
	if(size > 100) size = 100;
	if(size < 0) size = 0;

	this->size = size;
}

IElement* TopDockedElement::getElement()
{
	return this->element;
}


int TopDockedElement::getSize()
{
	return this->size;
}


std::string TopDockedElement::writeHTML(int elementWidth)
{
	std::stringstream ss;
	ss << "<div class=\"TopDock\" style=\"float:left; height:" << this->size << "%; width:"<< elementWidth<<"%; \"";
	ss << ">" << this->element->getText() << "</div>";

	return ss.str();
}

}
}
}