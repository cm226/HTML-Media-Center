#pragma once
#ifndef DOCKINGLAYOUT_LEFTDOCKEDELEMENT_H
#define DOCKINGLAYOUT_LEFTDOCKEDELEMENT_H


#include "../../../IElement.h"


namespace htmlrendere {
namespace elements {
namespace DockingLayoutElements
{

class LeftDockedElement
{
public:
	LeftDockedElement(int size, IElement* element);
	LeftDockedElement();
	~LeftDockedElement(void);

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