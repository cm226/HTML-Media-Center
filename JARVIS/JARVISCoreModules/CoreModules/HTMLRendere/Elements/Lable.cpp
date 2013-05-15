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
}

Lable::~Lable() {
}


void Lable::setText(std::string text)
{
	this->text = text;
}
