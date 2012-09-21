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
	// TODO Auto-generated constructor stub

}

Lable::~Lable() {
	// TODO Auto-generated destructor stub
}

std::string Lable::getText()
{
	return std::string("<p name="+this->name+" />");
}
