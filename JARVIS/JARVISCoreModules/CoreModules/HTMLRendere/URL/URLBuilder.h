#pragma once

#include <string>

#include "IURLBuilder.h"
namespace URL
{

class URLBuilder : public IURLBuilder
{
private:
	std::string _web_root_URL;
	std::string _web_public_URL;

	std::string _curent_URL;

	URLBuilder(std::string initialURL);

public:
	URLBuilder(std::string web_root, std::string web_public);
	~URLBuilder(void);

	
	IURLBuilder* Web_Root();
	IURLBuilder* Web_Public();

	void Append(std::string url);
	void Append(IURLBuilder& url);

	std::string Get_URL();
};
}
