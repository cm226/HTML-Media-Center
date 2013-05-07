/*
	Author : Craig Matear
*/
#include "BottomDockedElement.h"
#include <sstream>


namespace htmlrendere {
namespace elements {
namespace DockingLayoutElements
{


BottomDockedElement::BottomDockedElement(int size, IElement* element)
{
	this->setSize(size);
	this->element = element;
}

BottomDockedElement::~BottomDockedElement()
{
}

BottomDockedElement::BottomDockedElement()
{
	this->setSize(0);
	this->element = NULL;
}


void BottomDockedElement::setElement(IElement* element)
{
	this->element = element;
}
void BottomDockedElement::setSize(int size)
{
	if(size > 100) size = 100;
	if(size < 0) size = 0;
	this->size = size;
}

IElement* BottomDockedElement::getElement()
{
	return this->element;
}


int BottomDockedElement::getSize()
{
	return this->size;
}

std::string BottomDockedElement::writeHTML(int widthPadding)
{
	std::stringstream ss;
	ss << "<div class=\"bottomDock\" style=\"float:left; height:" << this->size << "%; width:"<< widthPadding<< "%; \"";
	ss << ">" << this->element->getText() << "</div>";

	return ss.str();
}

}
}
}



