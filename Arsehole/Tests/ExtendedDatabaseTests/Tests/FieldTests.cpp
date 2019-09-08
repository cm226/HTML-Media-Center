#include "../stdafx.h"
#include "../../../arseholeCoreModules/CoreModules/Database/ExtendedPluginDB/Field.h"

BOOST_AUTO_TEST_CASE(FieldWriteNormalCase)
{
	std::string filename = "/var/www/HTML-Media-Center/arsehole/Tests/ExtendedDatabaseTests/TestData/Music/Songs/bpm.edb";
	ExtendedDatabase::Field<int, int> field(filename);

	field.aquireData();
	field.writeData(1, 20);
	field.writeData(2, 22);
	field.save();
	field.releaseData();

	std::ifstream fieldFile;
	fieldFile.open(filename.c_str(), std::ifstream::binary);
	char buf[4];
	char* bufStart = &(buf[0]);

	fieldFile.readsome(bufStart,4);
	std::string line1 = buf;

	fieldFile.readsome(bufStart,4);
	std::string line2 = buf;

	BOOST_CHECK_EQUAL(line1.compare("\001,\024\n"),0);
	BOOST_CHECK_EQUAL(line2.compare("\002,\026\n"),0);


}

BOOST_AUTO_TEST_CASE(FieldReadNormalCase)
{
	ExtendedDatabase::Field<int, int> field("/var/www/HTML-Media-Center/arsehole/Tests/ExtendedDatabaseTests/TestData/Music/Songs/1:20-2:22.edb");

	field.setSerialisers(ExtendedDatabase::Serializer<int>(), ExtendedDatabase::Serializer<int>());
	field.aquireData();
	BOOST_CHECK_EQUAL(field.lookupValue(1), 20);
	BOOST_CHECK_EQUAL(field.lookupValue(2), 22);
	field.releaseData();
}
