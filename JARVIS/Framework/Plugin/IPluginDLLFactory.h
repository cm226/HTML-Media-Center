#include "Plugin.h"

extern"C"
{
	Plugin* makePlugin(CoreModules* framework);
	bool releasePlugin(Plugin* plugin);
}
