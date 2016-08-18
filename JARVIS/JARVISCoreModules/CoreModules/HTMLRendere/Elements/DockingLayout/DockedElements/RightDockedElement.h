#pragma once

#ifndef DOCKINGLAYOUT_RIGHTDOCKEDELEMENT_H
#define DOCKINGLAYOUT_LEFTDOCKEDELEMENT_H


#include "../../../IElement.h"

namespace htmlrendere {
namespace elements {
namespace DockingLayoutElements
{

class RightDockedElement
{
public:
	RightDockedElement(int size, IElement* element);
	RightDockedElement();
	~RightDockedElement(void);

		void setElement(IElement* element);
	void setSize(int size);

	IElement* getElement();
	int getSize();

	std::string writeHTML();

private:
	int size;
	IElement* element;

};

}
}
}

#endif