/*
 * TextBox.h
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#ifndef TEXTBOX_H_
#define TEXTBOX_H_

#include "IElement.h"

class TextBox: public IElement {
public:
	TextBox(std::string name);
	virtual ~TextBox();
};

#endif /* TEXTBOX_H_ */
