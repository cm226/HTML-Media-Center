/*
 * Lable.h
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#ifndef LABLE_H_
#define LABLE_H_

#include "../IElement.h"
#include "../../exportMacros.h"

class DLLCORE_API Lable: public IElement {
private:
	std::string text;

protected:
	virtual std::string getTagText() {return "p";};
	virtual std::string getTagContent(){ return this->text; };

public:
	Lable(std::string name);

	void setText(std::string text);
	virtual ~Lable();


};

#endif /* LABLE_H_ */
