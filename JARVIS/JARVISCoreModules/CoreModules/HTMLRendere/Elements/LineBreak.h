#pragma once

#include "../IElement.h"

class DLLCORE_API LineBreak : public IElement
{

private:
protected:
	virtual std::string getTagText();
	virtual std::string getTagContent();

public:
	LineBreak(std::string name);
	virtual ~LineBreak();

};