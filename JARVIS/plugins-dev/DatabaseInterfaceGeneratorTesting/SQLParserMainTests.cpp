#define BOOST_TEST_MODULE SQL_PARSER_Main

#include "stdafx.h"
#include "../SQLParser/SQLParser.h"

BOOST_AUTO_TEST_CASE(constructorTest)
{
	BOOST_CHECK_NO_THROW(SQLParser parser("/home/craig/Programming/workspace/SQLParser/testInput.sql"));
}


BOOST_AUTO_TEST_CASE(parserTablesimple)
{
	SQLParser parser("/home/craig/Programming/workspace/SQLParserTests/testInput1(simepleTables).sql");
	std::list<Table> tables;
	std::list<Table>::iterator tablesIt;
	parser.getTables(tables);


	BOOST_CHECK_EQUAL(tables.size(), 2);
	tablesIt = tables.begin();
	Table t;
	t = *tablesIt;
	BOOST_CHECK_EQUAL(t.tableName.compare("test1"), 0);
	BOOST_CHECK_EQUAL(t.fields.size(),2);

	Field f = t.fields.at(0);
	BOOST_CHECK_EQUAL(f.FieldName().compare("test1"),0);
	BOOST_CHECK_EQUAL(f.VarName(),Field::sqlFieldType::INT);

	f = t.fields.at(1);
	BOOST_CHECK_EQUAL(f.FieldName().compare("test2"),0);
	BOOST_CHECK_EQUAL(f.VarName(),Field::sqlFieldType::VARCHAR);

	tablesIt++;
	t = *tablesIt;

	BOOST_CHECK_EQUAL(t.tableName.compare("test2"), 0);
	BOOST_CHECK_EQUAL(t.fields.size(),2);

	BOOST_CHECK_EQUAL(t.fields.at(0).FieldName().compare("test1"),0);
	BOOST_CHECK_EQUAL(t.fields.at(0).VarName(),Field::sqlFieldType::INT);

	BOOST_CHECK_EQUAL(t.fields.at(1).FieldName().compare("test2"),0);
	BOOST_CHECK_EQUAL(t.fields.at(1).VarName(),Field::sqlFieldType::VARCHAR);

}


BOOST_AUTO_TEST_CASE(parserTableprimaryKey)
{
	SQLParser parser("/home/craig/Programming/workspace/SQLParserTests/testInput2(primaryKeys).sql");
	std::list<Table> tables;
	std::list<Table>::iterator tablesIt;

	Table t;
	parser.getTables(tables);


	BOOST_CHECK_EQUAL(tables.size(), 2);
	tablesIt = tables.begin();

	t = *tablesIt;
	BOOST_CHECK_EQUAL(t.tableName.compare("test1"), 0);
	BOOST_CHECK_EQUAL(t.fields.size(),2);

	Field f =t.fields.at(0);
	BOOST_CHECK_EQUAL(f.FieldName().compare("test1"),0);
	BOOST_CHECK_EQUAL(f.VarName(),Field::sqlFieldType::INT);

	f =t.fields.at(1);
	BOOST_CHECK_EQUAL(f.FieldName().compare("test2"),0);
	BOOST_CHECK_EQUAL(f.VarName(),Field::sqlFieldType::VARCHAR);

	BOOST_CHECK_EQUAL(t.primaryKey.FieldName().compare("test1"),0);

	tablesIt++;
	t = *tablesIt;

	BOOST_CHECK_EQUAL(t.tableName.compare("test2"), 0);
	BOOST_CHECK_EQUAL(t.fields.size(),2);


	BOOST_CHECK_EQUAL(t.fields.at(0).FieldName().compare("test1"),0);
	BOOST_CHECK_EQUAL(t.fields.at(0).VarName(),Field::sqlFieldType::INT);

	BOOST_CHECK_EQUAL(t.fields.at(1).FieldName().compare("test2"),0);
	BOOST_CHECK_EQUAL(t.fields.at(1).VarName(),Field::sqlFieldType::VARCHAR);
	BOOST_CHECK_EQUAL(t.primaryKey.FieldName().compare("test1"),0);
}



BOOST_AUTO_TEST_CASE(parserTableforignKey)
{
	/* We are ignoreing forigen keys at present
	 *
	 */
	/*
	SQLParser parser("/home/craig/Programming/workspace/SQLParserTests/testInput3(foreign key).sql");
	Table t;
	parser.nextTable(&t);

	BOOST_CHECK_EQUAL(t.tableName.compare("test1"), 0);
	BOOST_CHECK_EQUAL(t.fields->size(),2);

	BOOST_CHECK_EQUAL(t.fields->at(0).FieldName().compare("test1"),0);
	BOOST_CHECK_EQUAL(t.fields->at(0).VarName().compare("INT"),0);

	BOOST_CHECK_EQUAL(t.fields->at(1).FieldName().compare("test2"),0);
	BOOST_CHECK_EQUAL(t.fields->at(1).VarName().compare("VARCHAR"),0);

	BOOST_CHECK_EQUAL(t.primaryKey->FieldName().compare("test1"),0);

	parser.nextTable(&t);

	BOOST_CHECK_EQUAL(t.tableName.compare("test2"), 0);
	BOOST_CHECK_EQUAL(t.fields->size(),2);

	BOOST_CHECK_EQUAL(t.fields->at(0).FieldName().compare("test1"),0);
	BOOST_CHECK_EQUAL(t.fields->at(0).VarName().compare("INT"),0);

	BOOST_CHECK_EQUAL(t.fields->at(1).FieldName().compare("test2"),0);
	BOOST_CHECK_EQUAL(t.fields->at(1).VarName().compare("VARCHAR"),0);
	BOOST_CHECK_EQUAL(t.primaryKey->FieldName().compare("test1"),0);

	BOOST_CHECK_EQUAL(parser.nextTable(&t),false);
 */
}
