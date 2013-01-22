/*
 * FormSubmit.cpp
 *
 *  Created on: Sep 23, 2012
 *      Author: craig
 */

#include "FormSubmit.h"

FormSubmit::FormSubmit(std::string name): IElement(name) {

}

FormSubmit::~FormSubmit() {
}

std::string FormSubmit::getText()
{
	return "<input type=\"submit\" value=\"submit\">";
}
