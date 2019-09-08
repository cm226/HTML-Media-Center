/*
 * MediaImagesPlugin.h
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#ifndef MEDIAIMAGESPLUGIN_H_
#define MEDIAIMAGESPLUGIN_H_

#include "../../arsehole/Framework/Plugin/Plugin.h"
#include "../../arseholeCoreModules/CoreModules/Database/Tables/Movie/Movie.h"
#include "ImageGetters/Movie/MovieImageGetter.h"
#include "ImageGetters/Music/MusicImageGetter.h"

#include <string>
#include <vector>

class MediaImagesPlugin: public Plugin {
private :

	CALLBACk_HANDLE musicISelected;
	CALLBACk_HANDLE tvSelected;
	CALLBACk_HANDLE movieImageSelected;

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
