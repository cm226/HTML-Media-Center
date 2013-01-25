/*
 * IElement.h
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#ifndef IELEMENT_H_
#define IELEMENT_H_

#include <string>
#include <vector>

class IElement {
private:
	std::vector<std::string> attributes;
	std::string name;

protected:
	virtual std::string getTagText() = 0;
	virtual std::string getTagContent() = 0;

public:
	IElement(std::string name);
	virtual ~IElement();

	void addAttribute(std::string att);
	virtual std::string getText();

};

#endif /* IELEMENT_H_ */
