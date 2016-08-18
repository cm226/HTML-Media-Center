#pragma once

#include <string>

#include "IURLBuilder.h"
#include "../../exportMacros.h"

namespace URL
{

class DLLCORE_API URLBuilderFactory
{
private:
	static std::string _web_root_URL;
	static std::string _public_URL;

public:
	URLBuilderFactory(void);
	~URLBuilderFactory(void);

	static void Set_Num_lvls_to_root(int levles);

	static IURLBuilder* Create_URL_Builder();
	static void delete_URL_builder(IURLBuilder* builder);
};

}

