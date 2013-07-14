#include "../stdafx.h"
#include "../../../JARVISCoreModules/CoreModules/Database/ExtendedPluginDB/SubCatagory.h"

BOOST_AUTO_TEST_CASE(SubCatagoryNormalCase)
{
	ExtendedDatabase::SubCatagory subCat("/var/www/HTML-Media-Center/JARVIS/Tests/ExtendedDatabaseTests/TestData/Music","Music");
	BOOST_CHECK_EQUAL(subCat.getName().compare("Music"), 0);

	BOOST_CHECK_EQUAL(subCat.fieldExsits("bpm"),true);
	BOOST_CHECK_EQUAL(subCat.fieldExsits("blargh"),false);

	ExtendedDatabase::Serializer<int> seriaizer;
	ExtendedDatabase::Field<int,int> f = subCat.getField<int,int>("bpm");
}
