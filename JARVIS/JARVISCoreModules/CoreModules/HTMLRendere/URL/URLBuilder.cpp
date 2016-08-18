#include "URLBuilder.h"

namespace URL
{

URLBuilder::URLBuilder(std::string web_root, std::string web_public) :
		_web_root_URL(web_root),
		_web_public_URL(web_public)
{

}


URLBuilder::URLBuilder(std::string initialURL) :
	_curent_URL(initialURL)
{

}


URLBuilder::~URLBuilder(void)
{
}

IURLBuilder* URLBuilder::Web_Root()
{
	return new URLBuilder(this->_web_root_URL);
}

IURLBuilder* URLBuilder::Web_Public()
{
	return new URLBuilder(this->_web_public_URL);
}

void URLBuilder::Append(std::string url)
{
	char firstChar =url.at(0);
	if(firstChar != '\\' || firstChar == '/')
		url = '\\' + url;

	this->_curent_URL += url;
}

void URLBuilder::Append(IURLBuilder& url)
{
	this->Append(url.Get_URL());
}

std::string URLBuilder::Get_URL()
{
	return this->_curent_URL;
}

}