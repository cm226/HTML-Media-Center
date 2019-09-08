#include "../../Arsehole/Framework/Plugin/IPluginDLLFactory.h"
#include "EmailCheckerPlugin.h"

DLLHELL_API Plugin* makePlugin(CoreModules* framework)
{
	return new EmailCheckerPlugin(framework);
}

DLLHELL_API bool releasePlugin(Plugin* plugin)
{
	delete plugin;
	return true;
}

