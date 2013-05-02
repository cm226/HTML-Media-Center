#include "ImageGetter.h"

#include <sstream>

#include <boost\filesystem.hpp>
#include <boost/gil/gil_all.hpp>

#include <boost/gil/image.hpp>
#include <boost/gil/typedefs.hpp>
#include <boost/gil/extension/io/jpeg_io.hpp>
//#include <boost\gil\extension\io\png_io.hpp>

#include <boost/gil/extension/numeric/sampler.hpp>
#include <boost/gil/extension/numeric/resample.hpp>


#include "../../../JARVISCoreModules/CoreModules/config.h"
#include "../../../JARVISCoreModules/CoreModules/Comms/Comms.h"

ImageGetter::ImageGetter(CoreModules* cm)
{
	this->coreMod = cm;
}


ImageGetter::~ImageGetter(void)
{
}

int ImageGetter::readInt(std::vector<std::string>& contextarguments, int index)
{
	if(index < 0)
	{
		ErrorLogger::logError("Invalid read index on context array");
		return -1;
	}

	if(contextarguments.size() <= (unsigned int)index)
	{
		ErrorLogger::logError("Invalid read index on context array");
		return -1;
	}

	std::string str = *(contextarguments.begin()+index);

	std::stringstream strs;
	strs << str;
	int nextInt;
	strs >> nextInt;

	return nextInt;
}

bool ImageGetter::downloadAndCopyImage(std::string const& url, std::string const&  location, std::string const& name, int sizex, int sizey)
{
	std::string localFileName = location+name;
	if(!this->coreMod->getComms()->downloadFile(url,localFileName))
	{
		ErrorLogger::logError("Failed to Download Movie Thumb");
		return false;
	}

	this->resizeImage(localFileName,sizex, sizey);
	return true;
}

bool ImageGetter::downloadAndCopyImageToPublicFolder(std::string const& url, std::string const&  relLocationFomPublic, std::string const& name, int sizex, int sizey)
{
	std::string pubFolder = HTMLMEDIAPUBLIC;
	std::string localFileName = pubFolder+relLocationFomPublic;
	return this->downloadAndCopyImage(url,localFileName,name,sizex,sizey);
}

void ImageGetter::resizeImage(std::string const& imageURL, int sixex, int sizey)
{
	std::string extention;
	extention = boost::filesystem::extension(imageURL);

	if(extention.compare(".png"))
		this->resizePNGImage(imageURL,sixex, sizey);
	else if(extention.compare(".jpg"))
		this->resizeJPGImage(imageURL,sixex, sizey);
	else if(extention.compare(".jpeg"))
		this->resizeJPGImage(imageURL,sixex, sizey);
	else
		ErrorLogger::logError("Unexpected file extention in resize: "+extention+" for file "+imageURL);

}

void ImageGetter::resizePNGImage(std::string const& imageURL, int sixex, int sizey)
{
	/*
	boost::gil::rgb8_image_t img;
	png_read_image(imageURL,img);
	

    boost::gil::rgb8_image_t targetImageSize(sixex,sizey);

    resize_view(const_view(img), view(targetImageSize), boost::gil::bilinear_sampler());
    png_write_view(imageURL,const_view(targetImageSize));*/

	ErrorLogger::logError("GET PNG SORTED another trying to use it: " + imageURL);
}
void ImageGetter::resizeJPGImage(std::string const& imageURL, int sixex, int sizey)
{
	boost::gil::rgb8_image_t img;
	jpeg_read_image(imageURL,img);
	

    boost::gil::rgb8_image_t targetImageSize(sixex,sizey);

    resize_view(const_view(img), view(targetImageSize), boost::gil::bilinear_sampler());
    jpeg_write_view(imageURL,const_view(targetImageSize));
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
