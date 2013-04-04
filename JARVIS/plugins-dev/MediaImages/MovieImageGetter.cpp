#include "MovieImageGetter.h"


#include "../../JARVISCoreModules/CoreModules/config.h"
#include "../../JARVISCoreModules/CoreModules/Errors/ErrorLogger.h"
#include <functional>
#include <boost\bind.hpp>
#include <sstream>

MovieImageGetter::MovieImageGetter(CoreModules* cm) : ImageGetter(cm)
{
}


MovieImageGetter::~MovieImageGetter(void)
{
}

void MovieImageGetter::registerFunctions(Plugin* registerer)
{
	boost::function2<bool ,Page*,PageCallbackContext* > f = boost::bind(&MovieImageGetter::imageSelected,this, _1, _2);
	registerer->subscribeHTMLCallback(f, this->ImageSelected);
	this->registereName = registerer->pluginName();

}


bool MovieImageGetter::imageSelected(Page* page, PageCallbackContext* context)
{
	std::vector<std::string> contextInfo = context->getAdditionalContext();
	int numContextAttributes = contextInfo.size();

	if(numContextAttributes ==0)
	{
		ErrorLogger::logError("Media Images Plugin: not enough data in context array, missing the selected Image value");
		std::cout << "Not Enough data see JARVIS log for more";
		return false;
	}

	if(numContextAttributes > 1)
	{
		ErrorLogger::logWarn("Media Images Plugin: additional arguments in context string");
	}

	
	std::string imageIndex = *contextInfo.begin();
	contextInfo.erase(contextInfo.begin());
	std::string movieID = *contextInfo.begin();

	std::stringstream ss;
	ss << imageIndex;
	int index;
	ss >> index;

	std::stringstream movieIDss;
	movieIDss << movieID;
	int movieIDint;
	movieIDss >> movieIDint;

	std::string imageURL = this->curImgSet[index];

	bool worked = handleImageSelected(movieIDint, this->getMovieNameFromID(movieIDint),imageURL);
	if(!worked)
	{
		ErrorLogger::logError("Unable to process selected Image");
		return false;
	}

	Lable* allWentWell = new Lable("Image Set, all is well");
	Hyperlink* hyperlink = new Hyperlink("nextLink", "http://localhost/HTML-Media-Center/Desktop/Plugin/pluginInteraction/3/Media%20Images","Next Movie");

	page->addElement(allWentWell);
	page->addElement(hyperlink);


	return true;
}

bool MovieImageGetter::handleMovieSelected(Page* page, PageCallbackContext* context)
{
	DatabaseTables::Movie movie;
	Form* chooseMediaForm = new Form("mediaForm");
	FormSubmit* submitFormBtt = new FormSubmit("find");
	Lable* movieNameLable = new Lable("MovieName");
	
	curImgSet.erase(curImgSet.begin(), curImgSet.end());
	curImgSet.clear();
	
	bool anyMoviesLeft = this->getUnallocatedMovie(movie);
	if(!anyMoviesLeft)
	{
		Lable* l = new Lable("resLable");
		l->setText("No Unalocated Movies Left");
		page->addElement(l);
		return true;
	}
	this->doGoogleSearch(curImgSet,movie.name->getStrValue() +" Poster");

	movieNameLable->setText("For Movie: "+movie.name->getStrValue());
	page->addElement(movieNameLable);

	std::vector<std::string>::iterator resultIt = curImgSet.begin();
	int i =0;
	for(resultIt; resultIt!= curImgSet.end(); resultIt++)
	{
		HTMLImage* image = new HTMLImage("img",*resultIt);
		std::stringstream attributeStream;
		attributeStream << i << "/" << movie.movieID->getValue();

		image->addOnclickCallbackAttribute(2, this->ImageSelected,this->registereName,attributeStream.str());
		chooseMediaForm->addElement(image);
		i++;
	}

	chooseMediaForm->addElement(submitFormBtt);
	page->addElement(chooseMediaForm);

	return true;
}


bool MovieImageGetter::notifyDatabaseOfMovieUpdate(int movID, std::string thumbName)
{
	
	std::stringstream movieID;

	DatabaseTables::Movie movie;
	DatabaseTables::Query q;
	DatabaseTables::UpdateQuery updateMovieq(&movie);
	movieID << movID;

	DatabaseTables::Equals eq(movie.getPrimaryKey(),movieID.str());
	q.addSelectItem(&movie);
	q.addConstraint(&eq);
	this->coreMod->getDatabaseConnection()->runQuery(&q);
		
	if(!q.nextLine())
	{
		ErrorLogger::logError("failed to reterve move with id: "+movieID.str()+" when updateing thumnail");
		return false;
	}

	movie.thumb->setValue(&thumbName);
	if(!this->coreMod->getDatabaseConnection()->runQuery(&updateMovieq))
	{
		ErrorLogger::logError("updateing Movie: "+movie.name->getStrValue()+" Failed ");
		return false;
	}
	
	return true;
}

bool MovieImageGetter::getUnallocatedMovie(DatabaseTables::Movie& movie)
{
	
	DatabaseTables::Query unallocatedMovie;

	DatabaseTables::IDatabaseTableField* movieThumb = movie.thumb;
	DatabaseTables::Equals urlThumConstrint(movieThumb,"");
	DatabaseTables::Descriptors::Limit limit("1");

	unallocatedMovie.addSelectItem(&movie);
	unallocatedMovie.addConstraint(&urlThumConstrint);

	unallocatedMovie.addDescriptor(&limit);

	DatabaseTables::Database *db = this->coreMod->getDatabaseConnection();
	db->runQuery((DatabaseTables::IQuery*)&unallocatedMovie);

	if(!unallocatedMovie.nextLine()) // should only be 1 result 
		return false;
	
	return true;

}

bool MovieImageGetter::handleImageSelected(int movieID,std::string tbhumbName, std::string imgURL)
{	
    std::string::size_type pos = imgURL.rfind('.',imgURL.length()-1);
	if(pos > imgURL.length() || pos == std::string::npos)
	{
		ErrorLogger::logError("Bad URL returned from image Search :" + imgURL);
		return false;
	}

	std::string ext = imgURL.substr(pos);
	std::string thumbName = tbhumbName+ext;
	std::string::iterator thumbNameIt;
	std::stringstream thumbNameStriped;
	for(thumbNameIt = thumbName.begin(); thumbNameIt != thumbName.end(); thumbNameIt++)
	{
		char c = *thumbNameIt;
		if(c == ' ' || c == '/' || c == '\\')
			thumbNameStriped << '.';
		else
		thumbNameStriped << c;
	}

	bool downloaded = this->downloadAndCopyImage(imgURL,"\\img\\Movie\\Thumbs\\",thumbNameStriped.str());

	if(downloaded)
		return this->notifyDatabaseOfMovieUpdate(movieID,thumbNameStriped.str());
	
	return false;

}

std::string MovieImageGetter::getMovieNameFromID(int movieID)
{
	DatabaseTables::Query movieNameQuery;
	DatabaseTables::MovieName movieNameField;
	DatabaseTables::movieID movID;
	std::stringstream movieIDStr;
	movieIDStr << movieID;
	DatabaseTables::Equals idConstraint(&movID,movieIDStr.str());

	movieNameQuery.addSelectItem(&movieNameField);
	movieNameQuery.addConstraint(&idConstraint);

	DatabaseTables::Database *db = this->coreMod->getDatabaseConnection();
	bool worked = db->runQuery((DatabaseTables::IQuery*)&movieNameQuery);
	if(!worked)
	{
		ErrorLogger::logError("Media Image Getter: Unable to get move entry in database for movie ID: "+movieIDStr.str());
		return "";
	}

	if(!movieNameQuery.nextLine()) // should be 1 result 
		return false;

	std::string movieName = movieNameField.getValue();
	return movieName;

}