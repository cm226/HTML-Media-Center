/*
 * TextBox.cpp
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#include "TextBox.h"

using namespace std;

TextBox::TextBox(string name) : IElement(name) {
	this->addAttribute("type=\"text\"");
}

TextBox::~TextBox() {

}
