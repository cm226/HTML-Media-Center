#define TESTING
#include "stdafx.h"

#include "../MediaImages/ImageGetters/Movie/MovieImageGetter.h"
#include "../../JARVISCoreModules/CoreModules/Database/Database.h"
#include "../../JARVISCoreModules/CoreModules/config.h"


BOOST_AUTO_TEST_CASE(MovieGetterconstructor)
{
	CoreModules cm;
	CoreModules* cmref = &cm;
	

	BOOST_CHECK_NO_THROW(MovieImageGetter m(cmref));
}

BOOST_AUTO_TEST_CASE(invalidContext)
{
	
	CoreModules cm;
	CoreModules* cmref = &cm;
	MovieImageGetter m(cmref);

	PageCallbackContext context;
	std::vector<std::string> aditionalContext;
	aditionalContext.push_back("");
	
	context.setAdditionalContext(&aditionalContext);
	BOOST_CHECK_EQUAL(m.onImageSelected(0, &context), false);

	aditionalContext.clear();
	aditionalContext.push_back("");
	aditionalContext.push_back("");
	context.setAdditionalContext(&aditionalContext);
	BOOST_CHECK_EQUAL(m.onImageSelected(0, &context), false);


	aditionalContext.clear();
	aditionalContext.push_back("1");
	aditionalContext.push_back("1");
	context.setAdditionalContext(&aditionalContext);
	BOOST_CHECK_EQUAL(m.onImageSelected(0, &context), false);
}


BOOST_AUTO_TEST_CASE(entryPoint)
{
	DatabaseTables::Database* testDatabase = new DatabaseTables::Database() ;
	BOOST_CHECK_EQUAL(testDatabase->Connect(DATABSEUSER,DATABASEPASSWORD,"mediaServerTests",""), true);

	CoreModules cm(testDatabase);
	CoreModules* cmref = &cm;
	MovieImageGetter m(cmref);

	Page p;
	m.handleMovieSelected(&p,0);
	
	
	p.freePage();
	
}

