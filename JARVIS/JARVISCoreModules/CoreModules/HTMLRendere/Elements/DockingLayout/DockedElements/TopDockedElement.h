#pragma once
#ifndef DOCKINGLAYOUT_TOPDOCKEDELEMENT_H
#define DOCKINGLAYOUT_TOPDOCKEDELEMENT_H


#include "../../../IElement.h"

namespace htmlrendere {
namespace elements {
namespace DockingLayoutElements
{

class TopDockedElement
{
public:
	TopDockedElement(int size, IElement* element);
	TopDockedElement();
	~TopDockedElement(void);

	void setElement(IElement* element);
	void setSize(int size);

	IElement* getElement();
	int getSize();

	std::string writeHTML(int elementWidth);

private:
	int size;
	IElement* element;

};

}
}
}

#endif