/*
	Author : Craig Matear
*/
#include "DockingLayout.h"
#include <sstream>

namespace htmlrendere {
namespace elements {



DockingLayout::DockingLayout(std::string name):  IElement(name)
{

}


DockingLayout::~DockingLayout()
{

}


std::string DockingLayout::getTagText()
{
	return "div";
}
std::string DockingLayout::getTagContent()
{
	return "";
}


void DockingLayout::dockLeft(IElement* element, int widthPx)
{
	if(this->elementLeft.getElement() == NULL)
		delete this->elementLeft.getElement();

	this->elementLeft.setElement(element);
	this->elementLeft.setSize(widthPx);
}

void DockingLayout::dockRight(IElement* element, int widthPx)
{

	if(this->elementRight.getElement() == NULL)
		delete this->elementRight.getElement();

	this->elementRight.setElement(element);
	this->elementRight.setSize(widthPx);

}

void DockingLayout::dockTop(IElement* element, int heightPx)
{

	if(this->elementTop.getElement() == NULL)
		delete this->elementTop.getElement();

	this->elementTop.setElement(element);
	this->elementTop.setSize(heightPx);

}

void DockingLayout::dockBottom(IElement* element, int heightPx)
{

	if(this->elementBottom.getElement() == NULL)
		delete this->elementBottom.getElement();

	this->elementBottom.setElement(element);
	this->elementBottom.setSize(heightPx);
}

std::string DockingLayout::getText()
{
	std::stringstream ss;

	int topAndBottomWidth = calculateTopBottomWidthPaddingValue();
	ss<<"<div" << writeAttributes() << "style=\"float:left; width:100%; min-height:30px; padding-bottom:10px;\">";
	if(this->elementLeft.getSize() > 0) ss << this->elementLeft.writeHTML();
	if(this->elementTop.getSize() > 0) ss << this->elementTop.writeHTML(topAndBottomWidth);
	if(this->elementBottom.getSize() > 0) ss << this->elementBottom.writeHTML(topAndBottomWidth);
	if(this->elementRight.getSize() > 0) ss << this->elementRight.writeHTML();
	ss<<"</div>";
	return ss.str();

}

int DockingLayout::calculateTopBottomWidthPaddingValue()
{
	return 100 - (this->elementLeft.getSize() + this->elementRight.getSize());
}



}
}



