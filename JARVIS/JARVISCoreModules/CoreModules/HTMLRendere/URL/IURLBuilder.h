#pragma once

#include <string>

#include "../../exportMacros.h"
namespace URL
{

class DLLCORE_API IURLBuilder
{
public:
	IURLBuilder(void);
	virtual ~IURLBuilder(void);

	virtual IURLBuilder* Web_Root() = 0;
	virtual IURLBuilder* Web_Public() =0;

	virtual void Append(std::string url) = 0;
	virtual void Append(IURLBuilder& url) =0;

	virtual std::string Get_URL() = 0;
};

}

