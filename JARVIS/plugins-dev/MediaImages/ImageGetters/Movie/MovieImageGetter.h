#ifndef MOVIE_IMAGE_GETTER_H
#define MOVIE_IMAGE_GETTER_H



#include "../IimageContentGetter.h"
#include "../ImageGetter.h"
#include "../../../../JARVIS/Framework/Plugin/Plugin.h"
#include "../../../../JARVISCoreModules/CoreModules/Database/Database.h"
#include "../../../../JARVISCoreModules/CoreModules/Database/Tables/Movie/Movie.h"

class MovieImageGetter : public imagegetters::IimageContentGetter
{

private:
	
	CoreModules* coreMod;
	ImageGetter imgGetter;
	std::vector<std::string> curImgSet;
	std::string registereName;
	static const CALLBACk_HANDLE ImageSelected = 11;


	bool getUnallocatedMovie(DatabaseTables::Movie::Movie& movie);
	bool notifyDatabaseOfMovieUpdate(int movID, std::string thumbName);
	bool handleImageSelected(int movieID,std::string tbhumbName, std::string imgURL);
	std::string getMovieNameFromID(int movieID);

	bool assertContextArguments(std::vector<std::string>& contextarguments);
	int readImageIndex(std::vector<std::string>& contextarguments);
	int readMovieID(std::vector<std::string>& contextarguments);
	void generateOnImageSelectedReplay(Page*);

public:
	MovieImageGetter(CoreModules* cm);
	virtual ~MovieImageGetter(void);

	bool onImageSelected(Page* page, PageCallbackContext* context);

	bool handleMovieSelected(Page* page, PageCallbackContext* context);
	void registerFunctions(Plugin* registerer);
};

#endif
