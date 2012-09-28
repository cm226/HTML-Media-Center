/*
 * TextBox.cpp
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#include "TextBox.h"

using namespace std;

TextBox::TextBox(string name) : IElement(name) {

}

TextBox::~TextBox() {

}

std::string TextBox::getText()
{
	return std::string("<input name="+this->name+" type=\"text\" />");
}
