#include "stdafx.h"
#include "../../ArseholeCoreModules/CoreModules/Database/Database.h"
#include "../../ArseholeCoreModules/CoreModules/config.h"


BOOST_AUTO_TEST_CASE(constructorTest)
{
	BOOST_CHECK_NO_THROW(DatabaseTables::Database database());
}

BOOST_AUTO_TEST_CASE(DatabaseConnect)
{
	DatabaseTables::Database database;
	bool connectionSucessful =database.Connect(DATABSEUSER,DATABASEPASSWORD,DATABASENAME,"localhost");
	BOOST_CHECK_EQUAL(connectionSucessful,true);
	BOOST_CHECK_EQUAL(database.isConnected(), true);

	BOOST_CHECK_EQUAL(database.Connect(DATABSEUSER,DATABASEPASSWORD,DATABASENAME,""),true);
	BOOST_CHECK_EQUAL(database.isConnected(), true);
}


BOOST_AUTO_TEST_CASE(DatabaseConnectFail)
{
	DatabaseTables::Database database;
	
	BOOST_CHECK_EQUAL(database.Connect("",DATABASEPASSWORD,DATABASENAME,"localhost"),false);
	BOOST_CHECK_EQUAL(database.isConnected(), false);

	BOOST_CHECK_EQUAL(database.Connect(DATABSEUSER,"",DATABASENAME,"localhost"),false);
	BOOST_CHECK_EQUAL(database.isConnected(), false);

	BOOST_CHECK_EQUAL(database.Connect(DATABSEUSER,DATABASENAME,"","localhost"),false);
	BOOST_CHECK_EQUAL(database.isConnected(), false);
}
