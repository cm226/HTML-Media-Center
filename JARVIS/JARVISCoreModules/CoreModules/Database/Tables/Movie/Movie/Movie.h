#ifndef _MOVIE_H_
#define _MOVIE_H_

#include "../../DatabaseTable.h"

#include "Fields\movieGenra.h"
#include "Fields\movieIMDB.h"
#include "Fields\movieLength.h"
#include "Fields\MovieName.h"
#include "Fields\movieURL.h"
#include "Fields\movieID.h"
#include "Fields\thumbnailURL.h"

#include "../../../../exportMacros.h"


namespace DatabaseTables
{

class DLLCORE_API Movie : public DatabaseTable
{
public:

	movieGenra* genra;
	movieIMDB* imdb;
	//movieLength* length;
	MovieName* name;
	movieURL* url;
	thumbnailURL* thumb;
	movieID* movieID;

	Movie(void);
	virtual ~Movie(void);

	std::string getUpdateQuery();
	std::string getInsertQuery(){return NULL;};
	void getFields(std::vector<IDatabaseTableField*>* fields);
	IDatabaseTableField* getPrimaryKey(){return this->movieID;};

	std::string tableName(){return "Movie";};
};
}
#endif
