#include "../../JARVIS/Framework/Plugin/IPluginDLLFactory.h"
#include "TaskerPlugin.h"

DLLHELL_API Plugin* makePlugin(CoreModules* framework)
{
	return new TaskerPlugin(framework);
}

DLLHELL_API bool releasePlugin(Plugin* plugin)
{
	delete plugin;
	return true;
}

