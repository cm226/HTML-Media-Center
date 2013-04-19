#ifndef _IMAGE_GETTER_H
#define _IMAGE_GETTER_H

#include <string>
#include <vector>
#include "../../../JARVISCoreModules/CoreModules/CoreModules.h"
#include "../../../JARVIS/Framework/Plugin/Plugin.h"

class ImageGetter
{
private:
	void resizeImage(std::string const& imageURL, int sixex, int sizey);

protected:

	CoreModules* coreMod;

	

public:
	ImageGetter(CoreModules* cm);
	~ImageGetter(void);

	void doGoogleSearch(std::vector<std::string>& result, std::string const &query);
	bool downloadAndCopyImage(std::string const& url, std::string const&  location, std::string const& name, int sizex, int sizey);

	int readInt(std::vector<std::string>& contextarguments, int index);
	

};
#endif