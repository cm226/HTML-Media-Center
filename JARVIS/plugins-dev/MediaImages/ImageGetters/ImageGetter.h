#ifndef _IMAGE_GETTER_H
#define _IMAGE_GETTER_H

#include <string>
#include <vector>
#include "../../../JARVISCoreModules/CoreModules/CoreModules.h"
#include "../../../JARVIS/Framework/Plugin/Plugin.h"

class ImageGetter
{
protected:

	CoreModules* coreMod;

	void doGoogleSearch(std::vector<std::string>& result, std::string const &query);
	bool downloadAndCopyImage(std::string const& url, std::string const&  location, std::string const& name);

	int readInt(std::vector<std::string>& contextarguments, int index);

public:
	ImageGetter(CoreModules* cm);
	~ImageGetter(void);

	virtual void registerFunctions(Plugin* registerer){};

};
#endif
