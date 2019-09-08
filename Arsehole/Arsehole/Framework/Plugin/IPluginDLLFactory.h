#ifndef _IPLUGINDLLFACTORY_
#define _IPLUGINDLLFACTORY_

#include "Plugin.h"


#ifdef _WINDOWS


#ifndef _arsehole
#define DLLHELL_API  __declspec(dllexport)
#else
#define DLLHELL_API __declspec(dllimport)
#endif

extern "C"
{

	DLLHELL_API Plugin* makePlugin(CoreModules* framework);
	DLLHELL_API bool releasePlugin(Plugin* plugin);
}

#else

#define DLLHELL_API
extern"C"
{
	Plugin* makePlugin(CoreModules* framework);
	bool releasePlugin(Plugin* plugin);
}

#endif

#endif

