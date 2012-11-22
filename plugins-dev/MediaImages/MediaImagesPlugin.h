/*
 * MediaImagesPlugin.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef MEDIAIMAGESPLUGIN_H_
#define MEDIAIMAGESPLUGIN_H_

#include "../../JARVIS/Framework/Plugin/Plugin.h"
#include <string>

class MediaImagesPlugin {
private :
	std::string name;
public:
	MediaImagesPlugin(CoreModules* framework);
	virtual bool whatDoYouLookLike(Page*);
	virtual const char* pluginName();
	virtual ~MediaImagesPlugin();
};

#endif /* MEDIAIMAGESPLUGIN_H_ */
