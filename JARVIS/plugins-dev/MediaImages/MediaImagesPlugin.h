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
#include <string>
#include <vector>

class MediaImagesPlugin: public Plugin {
private :
	std::string name;
	void doGoogleSearch(std::vector<std::string>& result, std::string const &query);
	bool getUnallocatedMovie(DatabaseTables::Movie& movie);
	bool downloadAndCopyImage(std::string const& url,std::string const& movieName);

public:
	MediaImagesPlugin(CoreModules* framework);
	virtual bool whatDoYouLookLike(Page*);
	virtual const char* pluginName();
	virtual ~MediaImagesPlugin();
};

#endif /* MEDIAIMAGESPLUGIN_H_ */
