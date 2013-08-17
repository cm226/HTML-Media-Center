#include "URLBuilderFactory.h"
#include "URLBuilder.h"

#include <sstream>

namespace URL
{

std::string URLBuilderFactory::_web_root_URL;
std::string URLBuilderFactory::_public_URL;

URLBuilderFactory::URLBuilderFactory(void)
{
}


URLBuilderFactory::~URLBuilderFactory(void)
{
}

void URLBuilderFactory::Set_Num_lvls_to_root(int levles)
{
	std::stringstream baseURL;

	for(int i = 0; i < levles; i++)
	{
		baseURL << "../";
	}

	_web_root_URL = baseURL.str();

	baseURL << "public/";

	_public_URL = baseURL.str();
}

IURLBuilder* URLBuilderFactory::Create_URL_Builder()
{
	return new URLBuilder(_web_root_URL,_public_URL);
}

void URLBuilderFactory::delete_URL_builder(IURLBuilder* builder)
{
	delete builder;
}

}
