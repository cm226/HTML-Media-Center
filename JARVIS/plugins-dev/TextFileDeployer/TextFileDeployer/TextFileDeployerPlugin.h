#pragma once
#include "../../../JARVIS/Framework/Plugin/Plugin.h"

class TextFileDeployerPlugin : public Plugin
{
public:
	TextFileDeployerPlugin(CoreModules* coreMod);
	~TextFileDeployerPlugin(void);

	bool whatDoYouLookLike(Page*);
	const char* pluginName();
};

