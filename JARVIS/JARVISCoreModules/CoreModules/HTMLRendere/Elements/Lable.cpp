/*
 * Lable.cpp
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#include "Lable.h"

using namespace std;
Lable::Lable(string name): IElement(name)
{
	this->addAttribute("style=\"color:white;\"");
}

Lable::~Lable() {
}


void Lable::setText(std::string text)
{
	this->text = text;
}
