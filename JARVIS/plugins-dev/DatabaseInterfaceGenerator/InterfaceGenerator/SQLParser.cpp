#include "SQLParser.h"

#include <boost/config/warning_disable.hpp>
#include <boost/fusion/adapted.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/tokenizer.hpp>

#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/find.hpp>


#include <fstream>
#include <sstream>
#include <exception>


namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

struct sqlfield
{
	std::string fieldName;
	std::string fieldType;
};

struct sqlCreateTable
{
	std::string tableNam;
	std::list<sqlfield> tabelCollumns;
};

BOOST_FUSION_ADAPT_STRUCT(
		sqlfield,
    (std::string, fieldName)
    (std::string, fieldType)
);


BOOST_FUSION_ADAPT_STRUCT(
		sqlCreateTable,
    (std::string, tableNam)
    (std::list<sqlfield>, tabelCollumns)
);

template <typename Iterator>
struct sql_createTable_Parser : qi::grammar<Iterator, sqlCreateTable(), ascii::space_type>
{
	sql_createTable_Parser() : sql_createTable_Parser::base_type(start)
    {
        using qi::lit;
        using qi::lexeme;
        using ascii::char_;

        field_string %= lexeme[+(char_ - ' ')]
        		>> lexeme[+(char_ - ',')];

        fieldList %= (field_string  % ',');

        start %=
            lit("CREATE TABLE ") >> +(char_ - '(')
            >> '('
            >>  fieldList
            ;
    }

    qi::rule<Iterator, sqlfield(), ascii::space_type> field_string;
    qi::rule<Iterator, std::vector<sqlfield>(), ascii::space_type> fieldList;
    qi::rule<Iterator, sqlCreateTable(), ascii::space_type> start;
};

SQLParser::SQLParser(std::string file)
{
	this->fileName = file;
	this->tokenizeSQLStatements();

}
SQLParser::~SQLParser()
{

}

void SQLParser::tokenizeSQLStatements()
{
	 typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
	  boost::char_separator<char> sep(";");
	  int len;
	  char* fileArray = this->readEntireFileIntoCharArray(this->fileName,&len);

	  std::string fileArrayStr = fileArray;
	  tokenizer tokens(fileArrayStr, sep);

	  for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter)
	  {
		  std::string statement = *tok_iter;
		  this->sqlStatements.push_back(statement);
	  }

	  delete[] fileArray;
}

char* SQLParser::readEntireFileIntoCharArray(std::string fileName, int* len)
{
	using namespace std;
	ifstream infile(fileName);

	infile.seekg(0,ios::end);

	*len = infile.tellg();

	char* getdata = new char[*len];
	infile.seekg(0,ios::beg);
	infile.read(getdata,*len);

	return getdata;

}

void SQLParser::getTables(std::list<Table>& tables)
{	
	 std::string sqlStatement;
	 std::list<std::string>::iterator sqlStatementsIt;
	 for(sqlStatementsIt = this->sqlStatements.begin();
			 sqlStatementsIt != this->sqlStatements.end(); sqlStatementsIt++)
	 {
		 Table t;
		 if(parseTable(*sqlStatementsIt, t))
			 tables.push_back(t);
	 }
}

bool SQLParser::parseTable(std::string sqlStatement, Table& t)
{
	 using boost::spirit::ascii::space;
	 typedef std::string::const_iterator iterator_type;
	 typedef sql_createTable_Parser<iterator_type> sql_create_parser;

	sql_create_parser g;
	sqlCreateTable sqlCreateTablestruct;

	 std::string::const_iterator iter = sqlStatement.begin();
	 std::string::const_iterator end = sqlStatement.end();

	bool r = boost::spirit::qi::phrase_parse(
							iter,
							end,
			 	 	 	    g,
			 	 	 	    space,
			 	 	 	    sqlCreateTablestruct
			 	 	 	    );
	if(r)
	{
		tableFromParsedSQL(t,sqlCreateTablestruct);
		return true;
	}
	return false;

}

void SQLParser::tableFromParsedSQL(Table& t, sqlCreateTable& parsedSQL)
{
	t.tableName = parsedSQL.tableNam;
	std::list<sqlfield>::iterator fieldIt = parsedSQL.tabelCollumns.begin();
	std::string varName, typeName;
	for(;fieldIt != parsedSQL.tabelCollumns.end(); fieldIt++)
	{
		varName = (*fieldIt).fieldName;
		typeName = (*fieldIt).fieldType;

		if(isPrimaryKeyType(typeName))
			addPrimaryKeyField(t,varName, typeName);
		else if(!isForeignKeyReferenceType(typeName))
			addField(t, varName, typeName);
	}
}

bool SQLParser::isPrimaryKeyType(std::string type)
{
	if(boost::find_first(type,"PRIMARY"))
		return true;

	return false;
}
bool SQLParser::isForeignKeyReferenceType(std::string type)
{
	if(boost::find_first(type,"KEY"))
			return true;

		return false;
}

void SQLParser::addPrimaryKeyField(Table& t, std::string fieldName, std::string fieldType)
{
	Field::sqlFieldType fieldTypeEnum = resolveBaseFieldType(fieldType);
	t.primaryKey = Field(fieldName, fieldTypeEnum);
	addField(t,fieldName, fieldType);
}

void SQLParser::addField(Table& t, std::string fieldName, std::string fieldType)
{
	Field::sqlFieldType fieldTypeEnum = resolveBaseFieldType(fieldType);
	t.fields.push_back(Field(fieldName, fieldTypeEnum));
}

Field::sqlFieldType SQLParser::resolveBaseFieldType(std::string fieldType)
{
	if(boost::starts_with(fieldType,"VARCHAR"))
			return Field::sqlFieldType::VARCHAR;
	else if(boost::starts_with(fieldType,"INT"))
			return Field::sqlFieldType::INT;
	else if(boost::starts_with(fieldType,"DATE"))
				return Field::sqlFieldType::DATE;
	else if(boost::starts_with(fieldType,"TIME"))
					return Field::sqlFieldType::TIME;

	else return Field::sqlFieldType::UNKNOWN;

}


