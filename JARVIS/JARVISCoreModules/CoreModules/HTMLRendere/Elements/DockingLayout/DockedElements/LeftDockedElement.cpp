#include "LeftDockedElement.h"
#include <sstream>

namespace htmlrendere {
namespace elements {
namespace DockingLayoutElements
{


LeftDockedElement::LeftDockedElement(int size, IElement* element)
{
	this->setSize(size);
	this->element = element;
}


LeftDockedElement::~LeftDockedElement(void)
{
}


LeftDockedElement::LeftDockedElement()
{
	this->setSize(0);
	this->element = NULL;
}


void LeftDockedElement::setElement(IElement* element)
{
	this->element = element;
}
void LeftDockedElement::setSize(int size)
{
	if(size > 100) size = 100;
	if(size < 0) size = 0;

	this->size = size;
}

IElement* LeftDockedElement::getElement()
{
	return this->element;
}


int LeftDockedElement::getSize()
{
	return this->size;
}

std::string LeftDockedElement::writeHTML()
{
	std::stringstream ss;
	ss << "<div class=\"LeftDock\" style=\"float:left; width:" << this->size << "%; height:100%; \"";
	ss << ">" << this->element->getText() << "</div>";

	return ss.str();
}

}}}