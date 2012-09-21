#include "../../Framework/Plugin/IPluginDLLFactory.h"
#include "EmailCheckerPlugin.h"

Plugin* makePlugin(JARVISFramework* framework)
{
	return new EmailCheckerPlugin(framework);
}

bool releasePlugin(Plugin* plugin)
{
	delete plugin;

}
