#include "stdafx.h"
#include "../../Database.h"
#include "../../Tables/Movie/Movie.h"
#include "../../../config.h"


BOOST_AUTO_TEST_CASE(DatabaseSelect)
{
	DatabaseTables::Database database;
	DatabaseTables::Movie::Movie movie;
	DatabaseTables::Query query;

	database.Connect(DATABSEUSER,DATABASEPASSWORD,DATABASENAME,"localhost");
	
	query.addSelectItem(&movie);
	BOOST_CHECK_EQUAL(database.runQuery(&query),true);

	bool isNextLine = query.nextLine();
	int previusMovieID = -1;
	BOOST_CHECK_EQUAL(isNextLine,true); // should be at least 1 result
	while(isNextLine)
	{
		BOOST_CHECK_NE(movie.movieID->getValue(),previusMovieID);
		previusMovieID = movie.movieID->getValue();
		isNextLine = query.nextLine();
	}

}