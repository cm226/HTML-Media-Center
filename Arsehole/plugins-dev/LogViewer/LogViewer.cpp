#ifndef _LOG_VIEWER_H
#define _LOG_VIEWER_H

#include "../../arsehole/Framework/Plugin/IPluginDLLFactory.h"
#include "LogViewerPlugin.h"


DLLHELL_API Plugin* makePlugin(CoreModules* framework)
{
	return new LogViewerPlugin(framework);
}

DLLHELL_API bool releasePlugin(Plugin* plugin)
{
	delete plugin;
	return true;
}


#endif