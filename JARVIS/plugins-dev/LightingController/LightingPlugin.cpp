#include "../../JARVIS/Framework/Plugin/IPluginDLLFactory.h"
#include "LightingController.h"


DLLHELL_API Plugin* makePlugin(CoreModules* framework)
{
	return new LightingController(framework);
}

DLLHELL_API bool releasePlugin(Plugin* plugin)
{
	delete plugin;
	return true;
}
