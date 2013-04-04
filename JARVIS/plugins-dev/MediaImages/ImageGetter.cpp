#include "ImageGetter.h"
#include <sstream>
#include "../../JARVISCoreModules/CoreModules/config.h"
#include "../../JARVISCoreModules/CoreModules/Comms/Comms.h"

ImageGetter::ImageGetter(CoreModules* cm)
{
	this->coreMod = cm;
}


ImageGetter::~ImageGetter(void)
{
}

bool ImageGetter::downloadAndCopyImage(std::string const& url, std::string const&  location, std::string const& name)
{
	std::string pubFolder = HTMLMEDIAPUBLIC;
	if(!this->coreMod->getComms()->downloadFile(url,pubFolder+location+name))
	{
		ErrorLogger::logError("Failed to Download Movie Thumb");
		return false;
	}
	return true;
}

void ImageGetter::doGoogleSearch(std::vector<std::string>& result, std::string const &query)
{
	std::string queryOriginal = query;
	std::stringstream queryStriped;

	std::string::iterator queryStripedIt;
	for(queryStripedIt = queryOriginal.begin(); queryStripedIt != queryOriginal.end(); queryStripedIt++)
	{
		char c = (*queryStripedIt);
		if(c == ' ')
			queryStriped << "%20";
		else
		queryStriped << c;
	}

	std::string googleImgURL = "http://ajax.googleapis.com/ajax/services/search/images?v=1.0&q="+queryStriped.str();
	std::string jsonReply;


	CommsNS::IJSONRequest* req = this->coreMod->getComms()->createJSONRequest();

	req->requestURL(googleImgURL);
	req->makeRequest(jsonReply);

	std::string urlMarker = "\"url\":\"";
	std::string::size_type startOfURL = 1;
	std::string::size_type endURL;
	std::string::size_type jsonLength = jsonReply.length();
	std::string::size_type markerLength = urlMarker.length();

	while (true)
	{
		startOfURL = jsonReply.find(urlMarker,startOfURL);
		std::string::size_type markerURLLen = startOfURL+markerLength;

		endURL = jsonReply.find("\"",markerURLLen+1);

		if(startOfURL < jsonLength && endURL < jsonLength)
			result.push_back(jsonReply.substr(markerURLLen, endURL-markerURLLen));
		else break;

		startOfURL ++;
	}
	delete req;

}
