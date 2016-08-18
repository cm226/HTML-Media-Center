#include "TextFileDeployerPlugin.h"


TextFileDeployerPlugin::TextFileDeployerPlugin(CoreModules* coreMod) : Plugin(coreMod)
{

}


TextFileDeployerPlugin::~TextFileDeployerPlugin(void)
{

}

bool TextFileDeployerPlugin::whatDoYouLookLike(Page* p )
{
	return true;
}

const char* TextFileDeployerPlugin::pluginName()
{
	return "Text File Deployer";
}
