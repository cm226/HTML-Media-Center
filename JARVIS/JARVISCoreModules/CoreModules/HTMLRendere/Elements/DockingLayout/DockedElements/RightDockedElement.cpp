#include "RightDockedElement.h"
#include <sstream>

namespace htmlrendere {
namespace elements {
namespace DockingLayoutElements
{

RightDockedElement::RightDockedElement(int size, IElement* element)
{
	this->setSize(size);
	this->element = element;
}


RightDockedElement::~RightDockedElement(void)
{
}



RightDockedElement::RightDockedElement()
{
	this->setSize(0);
	this->element = NULL;
}


void RightDockedElement::setElement(IElement* element)
{
	this->element = element;
}
void RightDockedElement::setSize(int size)
{
	if(size > 100) size = 100;
	if(size < 0) size = 0;
	this->size = size;
}

IElement* RightDockedElement::getElement()
{
	return this->element;
}


int RightDockedElement::getSize()
{
	return this->size;
}

std::string RightDockedElement::writeHTML()
{
	std::stringstream ss;
	ss << "<div class=\"RightDock\" style=\"float:left; height:100%; width:" << this->size << "%; \"";
	ss << ">" << this->element->getText() << "</div>";

	return ss.str();
}

}
}
}