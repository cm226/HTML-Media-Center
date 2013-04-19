#include "MovieImageGetter.h"


#include "../../../../JARVISCoreModules/CoreModules/config.h"
#include "../../../../JARVISCoreModules/CoreModules/Errors/ErrorLogger.h"
#include <functional>
#include <boost\bind.hpp>
#include <sstream>

MovieImageGetter::MovieImageGetter(CoreModules* cm) : imgGetter(cm)
{
	this->coreMod = cm;
}


MovieImageGetter::~MovieImageGetter(void)
{
}

void MovieImageGetter::registerFunctions(Plugin* registerer)
{
	boost::function2<bool ,Page*,PageCallbackContext* > f = boost::bind(&MovieImageGetter::onImageSelected,this, _1, _2);
	registerer->subscribeHTMLCallback(f, this->ImageSelected);
	this->registereName = registerer->pluginName();

}

bool MovieImageGetter::assertContextArguments(std::vector<std::string>& contextarguments)
{
	int numContextAttributes = contextarguments.size();

	if(numContextAttributes <2)
	{
		ErrorLogger::logError("Media Images Plugin: not enough data in context array, missing the selected Image value");
		std::cout << "Not Enough data see JARVIS log for more";
		return false;
	}

	if(numContextAttributes > 2)
	{
		ErrorLogger::logWarn("Media Images Plugin: additional arguments in context string");
	}

	return true;
}

int MovieImageGetter::readImageIndex(std::vector<std::string>& contextarguments)
{
	return this->imgGetter.readInt(contextarguments,0);
}
int MovieImageGetter::readMovieID(std::vector<std::string>& contextarguments)
{
	return this->imgGetter.readInt(contextarguments,1);
}

void MovieImageGetter::generateOnImageSelectedReplay(Page* page)
{
	Lable* allWentWell = new Lable("Image Set, all is well");
	Hyperlink* hyperlink = new Hyperlink("nextLink", "http://localhost/HTML-Media-Center/Desktop/Plugin/pluginInteraction/3/Media%20Images","Next Movie");

	page->addElement(allWentWell);
	page->addElement(hyperlink);

}

bool MovieImageGetter::onImageSelected(Page* page, PageCallbackContext* context)
{
	std::vector<std::string> contextInfo = context->getAdditionalContext();
	if(!assertContextArguments(contextInfo)) return false;

	int index = this->readImageIndex(contextInfo);
	int movieIDint = this->readMovieID(contextInfo);
	if(index <= -1 || movieIDint <= -1) return false;
	if((unsigned int)index > this->curImgSet.size())
	{
		ErrorLogger::logError("Image Set Value out of range");
		return false;
	}

	std::string imageURL = this->curImgSet.at(index);

	bool worked = handleImageSelected(movieIDint, this->getMovieNameFromID(movieIDint),imageURL);
	if(!worked)
	{
		ErrorLogger::logError("Unable to process selected Image");
		return false;
	}

	this->generateOnImageSelectedReplay(page);

	return true;
}

bool MovieImageGetter::handleMovieSelected(Page* page, PageCallbackContext* context)
{
	DatabaseTables::Movie movie;
	
	
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
	this->imgGetter.doGoogleSearch(curImgSet,movie.name->getStrValue() +" Poster");


	Form* chooseMediaForm = new Form("mediaForm");
	FormSubmit* submitFormBtt = new FormSubmit("find");
	Lable* movieNameLable = new Lable("MovieName");
	movieNameLable->setText("For Movie: "+movie.name->getStrValue());
	page->addElement(movieNameLable);

	std::vector<std::string>::iterator resultIt = curImgSet.begin();
	int i =0;
	for(resultIt; resultIt!= curImgSet.end(); resultIt++)
	{
		HTMLImage* image = new HTMLImage("img",*resultIt);
		std::stringstream attributeStream;
		attributeStream << i << "/" << movie.movieID->getValue();

		std::vector<std::string> args;
		args.push_back(attributeStream.str());
		

		image->addOnclickCallbackAttribute(2, this->ImageSelected,this->registereName,args);
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

	bool downloaded = this->imgGetter.downloadAndCopyImage(imgURL,"\\img\\Movie\\Thumbs\\",thumbNameStriped.str(),200,280);

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

	if(!movieNameQuery.nextLine())
		return false;

	std::string movieName = movieNameField.getValue();
	return movieName;

}
