#include "../stdafx.h"
#include "../../../JARVISCoreModules/CoreModules/Database/ExtendedPluginDB/Catagory.h"


BOOST_AUTO_TEST_CASE(CatagoryListSubs)
{
	ExtendedDatabase::Catagory catagory("/var/www/HTML-Media-Center/JARVIS/Tests/ExtendedDatabaseTests/TestData");

	const std::list<ExtendedDatabase::SubCatagory> subCatagorys = catagory.ListSubCatagories();

	BOOST_CHECK_EQUAL(subCatagorys.size(), 2);

	std::list<ExtendedDatabase::SubCatagory>::const_iterator subIt = subCatagorys.begin();
	ExtendedDatabase::SubCatagory firstSubCat = *subIt;
	BOOST_CHECK_EQUAL(firstSubCat.getName().compare("Movie"), 0);

	subIt++;
	ExtendedDatabase::SubCatagory secondSubCat = *subIt;
	BOOST_CHECK_EQUAL(secondSubCat.getName().compare("Music"), 0);
}

BOOST_AUTO_TEST_CASE(CatagoryLookupSubCat)
{
	ExtendedDatabase::Catagory catagory("/var/www/HTML-Media-Center/JARVIS/Tests/ExtendedDatabaseTests/TestData");
	ExtendedDatabase::SubCatagory subCat("","");

	bool foindit = catagory.tryLookupSubcatagoryFromName("Music", subCat);

	BOOST_CHECK_EQUAL(foindit, true);
	BOOST_CHECK_EQUAL(subCat.getName().compare("Music"), 0);

}

BOOST_AUTO_TEST_CASE(CatagoryNonExsitantLookupSubCat)
{
	ExtendedDatabase::Catagory catagory("/var/www/HTML-Media-Center/JARVIS/Tests/ExtendedDatabaseTests/TestData");
	ExtendedDatabase::SubCatagory subCat("","");

	bool foindit = catagory.tryLookupSubcatagoryFromName("BLARGH", subCat);

	BOOST_CHECK_EQUAL(foindit, false);

}


BOOST_AUTO_TEST_CASE(CatagoryCreateSubCat)
{
	std::string subCatName = "createdSubCat";
	std::string subCatToCreateDir = "/var/www/HTML-Media-Center/JARVIS/Tests/ExtendedDatabaseTests/TestData/"+subCatName;

	if(boost::filesystem::exists(subCatToCreateDir))
		boost::filesystem::remove(subCatToCreateDir);

	ExtendedDatabase::Catagory catagory("/var/www/HTML-Media-Center/JARVIS/Tests/ExtendedDatabaseTests/TestData/");

	catagory.addSubCatagory(subCatName);

	ExtendedDatabase::SubCatagory subcat("","");
    BOOST_CHECK_EQUAL(catagory.tryLookupSubcatagoryFromName(subCatName,subcat),true);
    BOOST_CHECK_EQUAL(subcat.getName().compare(subCatName), 0);

    BOOST_CHECK_EQUAL(boost::filesystem::exists(subCatToCreateDir), true);
}
