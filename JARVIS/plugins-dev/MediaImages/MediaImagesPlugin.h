/*
 * MediaImagesPlugin.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef MEDIAIMAGESPLUGIN_H_
#define MEDIAIMAGESPLUGIN_H_

#include "../../JARVIS/Framework/Plugin/Plugin.h"
#include "../../JARVISCoreModules/CoreModules/Database/Tables/Movie/Movie/Movie.h"
#include "ImageGetters\Movie\MovieImageGetter.h"
#include "ImageGetters\Music\MusicImageGetter.h"

#include <string>
#include <vector>

class MediaImagesPlugin: public Plugin {
private :

	static const CALLBACk_HANDLE musicISelected = 1;
	static const CALLBACk_HANDLE tvSelected = 2;
	static const CALLBACk_HANDLE movieImageSelected = 3;

	std::string name;
	MovieImageGetter movieImageGetter;
	MusicImageGetter musicImageGetter;
	
	bool handleImageSelected(int movieID,std::string tbhumbName, std::string imageURL);


	bool handleMovieSelected(Page* page, PageCallbackContext* context);
	bool handleMusicSelected(Page* page, PageCallbackContext* context);
	bool handleTvSelected(Page* page, PageCallbackContext* context);

public:
	MediaImagesPlugin(CoreModules* framework);
	virtual bool whatDoYouLookLike(Page*);
	virtual const char* pluginName();
	virtual ~MediaImagesPlugin();
};

#endif /* MEDIAIMAGESPLUGIN_H_ */
