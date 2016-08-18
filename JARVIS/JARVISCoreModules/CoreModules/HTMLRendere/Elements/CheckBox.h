#pragma once

#include "../IElement.h"

class DLLCORE_API Checkbox : public IElement
{
private:
protected:
	virtual std::string getTagText();
	virtual std::string getTagContent();

public:
	Checkbox(std::string name);
	virtual ~Checkbox();
};