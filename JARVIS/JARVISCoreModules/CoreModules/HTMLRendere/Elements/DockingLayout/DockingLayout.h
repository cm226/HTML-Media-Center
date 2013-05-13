/*
	Author : Craig Matear
*/
#pragma once
#ifndef COREMODULES_HTMLRENDERE_ELEMENTS_DOCKINGLAYOUT_H
#define COREMODULES_HTMLRENDERE_ELEMENTS_DOCKINGLAYOUT_H

#include "../../IElement.h"
#include "../../../exportMacros.h"
#include "DockedElements\BottomDockedElement.h"
#include "DockedElements\LeftDockedElement.h"
#include "DockedElements\RightDockedElement.h"
#include "DockedElements\TopDockedElement.h"
#include <string>


namespace htmlrendere {
namespace elements {



/**
	DockingLayout
*/
class DLLCORE_API DockingLayout: public IElement
{
private:
	#pragma warning( disable : 4251)
	DockingLayoutElements::LeftDockedElement elementLeft;
	DockingLayoutElements::RightDockedElement elementRight;
	DockingLayoutElements::TopDockedElement elementTop;
	DockingLayoutElements::BottomDockedElement elementBottom;
	#pragma warning( default : 4251)
	int calculateTopBottomWidthPaddingValue();

protected:
	std::string getTagText();
	std::string getTagContent();

public:
	/**
		ctor
	*/
	DockingLayout(std::string name);

	/**
		dtor
	*/
	~DockingLayout();

	void dockLeft(IElement* element, int widthPercent);
	void dockRight(IElement* element, int widthPercent);
	void dockTop(IElement* element, int heightPercent);
	void dockBottom(IElement* element, int heightPercent);

	virtual std::string getText();

};




}
}



#endif



