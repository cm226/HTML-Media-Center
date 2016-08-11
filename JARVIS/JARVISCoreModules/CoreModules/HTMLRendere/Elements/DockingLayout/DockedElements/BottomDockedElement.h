/*
	Author : Craig Matear
*/
#pragma once
#ifndef DOCKINGLAYOUT_BOTTOMDOCKEDELEMENT_H
#define DOCKINGLAYOUT_BOTTOMDOCKEDELEMENT_H

#include "../../../IElement.h"

namespace htmlrendere {
namespace elements {
namespace DockingLayoutElements{


class BottomDockedElement
{
private:
	int size;
	IElement* element;

public:
	BottomDockedElement(int size, IElement* element);
	BottomDockedElement();
	~BottomDockedElement();


	void setElement(IElement* element);
	void setSize(int size);

	IElement* getElement();
	int getSize();

	std::string writeHTML(int widthPadding);
};




}
}
}



#endif



