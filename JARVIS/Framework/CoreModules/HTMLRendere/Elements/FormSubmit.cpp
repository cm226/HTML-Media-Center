/*
 * FormSubmit.cpp
 *
 *  Created on: Sep 23, 2012
 *      Author: craig
 */

#include "FormSubmit.h"

FormSubmit::FormSubmit(std::string name): IElement(name) {
	// TODO Auto-generated constructor stub

}

FormSubmit::~FormSubmit() {
	// TODO Auto-generated destructor stub
}

std::string FormSubmit::getText()
{
	return "<input type=\"submit\" value=\"submit\">";
}
