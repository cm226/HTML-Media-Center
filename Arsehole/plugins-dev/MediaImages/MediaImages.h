#ifndef MEDIA_IMAGES_
#define MEDIA_IMAGES_

#include "../../arsehole/Framework/Plugin/IPluginDLLFactory.h"
#include "MediaImagesPlugin.h"


DLLHELL_API Plugin* makePlugin(CoreModules* framework)
{
	return new MediaImagesPlugin(framework);
}

DLLHELL_API bool releasePlugin(Plugin* plugin)
{
	delete plugin;
	return true;
}

#endif