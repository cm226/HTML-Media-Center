#include "../../JARVIS/Framework/Plugin/IPluginDLLFactory.h"
#include "EmailCheckerPlugin.h"

extern"C"
{
	Plugin* makePlugin(CoreModules* framework)
	{
		return new EmailCheckerPlugin(framework);
	}

	bool releasePlugin(Plugin* plugin)
	{
		delete plugin;
		return true;
	}
}
