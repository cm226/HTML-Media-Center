#include "../../JARVIS/Framework/Plugin/IPluginDLLFactory.h"
#include "MediaImagesPlugin.h"

extern"C"
{
	Plugin* makePlugin(CoreModules* framework)
	{
		return new MediaImagesPlugin(framework);
	}

	bool releasePlugin(Plugin* plugin)
	{
		delete plugin;
		return true;
	}
}
