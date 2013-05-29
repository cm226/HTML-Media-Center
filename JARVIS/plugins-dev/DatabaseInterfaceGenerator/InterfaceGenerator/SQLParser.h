#ifndef _SQLPARSER_
#define _SQLPARSER_

#include "Table.h"
#include "Field.h"

#include <string>
#include <list>

int doParse();
struct sqlCreateTable;

class SQLParser
{

private:

	std::string fileName;
	std::list<std::string> sqlStatements;


	char* readEntireFileIntoCharArray(std::string fileName, int* len);
	void tokenizeSQLStatements();

	bool parseTable(std::string sqlStatement, Table& t);
	void tableFromParsedSQL(Table& t, sqlCreateTable& parsedSQL);

	bool isPrimaryKeyType(std::string type);
	bool isForeignKeyReferenceType(std::string type);

	void addPrimaryKeyField(Table& t, std::string fieldName, std::string fieldType);
	void addField(Table& t, std::string fieldName, std::string fieldType);
	Field::sqlFieldType resolveBaseFieldType(std::string fieldType);

public:
	SQLParser(std::string file);
	virtual ~SQLParser();

	void getTables(std::list<Table>& tables);



};

#endif
