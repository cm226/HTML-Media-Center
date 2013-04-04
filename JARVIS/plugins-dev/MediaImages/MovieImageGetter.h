#ifndef MOVIE_IMAGE_GETTER_H
#define MOVIE_IMAGE_GETTER_H

#include "ImageGetter.h"
#include "../../JARVIS/Framework/Plugin/Plugin.h"
#include "../../JARVISCoreModules/CoreModules/Database/Database.h"
#include "../../JARVISCoreModules/CoreModules/Database/Tables/Movie/Movie/Movie.h"

class MovieImageGetter : public ImageGetter
{

private:
	
	std::vector<std::string> curImgSet;
	std::string registereName;
	static const CALLBACk_HANDLE ImageSelected = 11;


	bool getUnallocatedMovie(DatabaseTables::Movie& movie);
	bool notifyDatabaseOfMovieUpdate(int movID, std::string thumbName);
	bool handleImageSelected(int movieID,std::string tbhumbName, std::string imgURL);
	std::string getMovieNameFromID(int movieID);

public:
	MovieImageGetter(CoreModules* cm);
	~MovieImageGetter(void);

	bool imageSelected(Page* page, PageCallbackContext* context);

	bool handleMovieSelected(Page* page, PageCallbackContext* context);
	void registerFunctions(Plugin* registerer);
};

#endif