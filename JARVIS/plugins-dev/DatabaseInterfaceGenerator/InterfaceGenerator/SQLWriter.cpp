/*
 * SQLWriter.cpp
 *
 *  Created on: 11 May 2013
 *      Author: craig
 */

#include "SQLWriter.h"
#include <sstream>

SQLWriter::SQLWriter() {
	// TODO Auto-generated constructor stub

}

SQLWriter::~SQLWriter() {
	// TODO Auto-generated destructor stub
}


CodeGenerators::Types SQLWriter::remapSQLType(Field::sqlFieldType sqlType)
{
	if(sqlType == Field::sqlFieldType::INT)
		return CodeGenerators::Types::INT;
	else if(sqlType == Field::sqlFieldType::VARCHAR)
		return CodeGenerators::Types::STRING;

	return CodeGenerators::Types::UNSPECIFIED;
}


std::string SQLWriter::getResWrapperFunc(CodeGenerators::Types type)
{
	switch(type.t)
	{
	case CodeGenerators::Types::INT:
		return "getInt";
	case CodeGenerators::Types::STRING:
		return "getString";

	default:
		return "getString";

	}

}

void SQLWriter::createFields(CodeGenerators::GenericClass* table, Table* t, CodeGenerators::AbstractOOCodeGenerator* generator,
		CodeGenerators::Method* getFieldsMethod)
{
	std::vector<Field>::iterator fieldIt;
	for(fieldIt = t->fields.begin(); fieldIt != t->fields.end(); fieldIt++)
	{
		std::string fieldName = fieldIt->FieldName();
		CodeGenerators::GenericClass field(&fieldName);
		CodeGenerators::Member baseClass = CodeGenerators::Member(CodeGenerators::Types("DatabaseTables::DatabaseTableField"),"DatabaseTables::DatabaseTableField");
		CodeGenerators::Member tableMember = CodeGenerators::Member(CodeGenerators::Types("Fields::"+fieldName+"*"),fieldName);
		CodeGenerators::Types fieldType = remapSQLType((fieldIt->VarName()));
		baseClass.setGenericType(fieldType);
		baseClass.ctorArgs.push_back("\""+t->tableName+"\"");

		field.setPostClassModifierString("DLLCORE_API");
		CodeGenerators::Dependancy tableFieldBaseClassDependancy, exportMacroDependancy;
		CodeGenerators::Dependancy stringStreamDep;
		stringStreamDep.setStandardLibraryDependancy("sstream");

		tableFieldBaseClassDependancy.setPathToDependancy("../../DatabaseTableField.h");
		exportMacroDependancy.setPathToDependancy("../../../../exportMacros.h");


		field.dependanceys.push_back(stringStreamDep);
		field.dependanceys.push_back(tableFieldBaseClassDependancy);
		field.dependanceys.push_back(exportMacroDependancy);

		CodeGenerators::Dependancy tableDependancy;
		tableDependancy.setPathToDependancy("Fields/"+fieldName+".h");
		table->dependanceys.push_back(tableDependancy);
		table->publicPropertys.push_back(tableMember);

		CodeGenerators::Method getName("getName"), fieldNamemember("fieldName"), getStrValue("getStrValue");

		getName.setReturnType(CodeGenerators::Types::STRING);
		fieldNamemember.setReturnType(CodeGenerators::Types::STRING);
		getStrValue.setReturnType(CodeGenerators::Types::STRING);

		getName.setContent("return \""+t->tableName+"."+fieldName+"\";");
		fieldNamemember.setContent("return \""+fieldName+"\";");

		getStrValue.setContent(std::string("std::stringstream ss; \n") +
								"ss << this->getValue(); \n"+
								"return ss.str();");

		field.publicMethods.push_back(getName);
		field.publicMethods.push_back(fieldNamemember);
		field.publicMethods.push_back(getStrValue);

		std::string constructorContent;
		table->getConstructor()->getContent(&constructorContent);
		constructorContent += "this->"+fieldName+" = new Fields::"+fieldName+"(); \n";
		table->getConstructor()->setContent(constructorContent);

		std::string deconstructorContent;
		table->getDeConstructor()->getContent(&deconstructorContent);
		deconstructorContent += "delete this->"+fieldName+";\n";
		table->getDeConstructor()->setContent(deconstructorContent);

		std::string getFieldsContent;
		getFieldsMethod->getContent(&getFieldsContent);
		getFieldsContent += "fields->push_back(this->"+fieldName+"); \n";
		getFieldsMethod->setContent(getFieldsContent);

		field.addBaseClass(baseClass);

		CodeGenerators::Method takeVal("takeValue");
		takeVal.addArgs(CodeGenerators::Types("ResultWrapper*"),"resRwapper");
		takeVal.setReturnType(CodeGenerators::Types("void"));

		std::string valueHACK = "";
		if(fieldType.t == CodeGenerators::Types::STRING)
			valueHACK = "std::string";
		else if(fieldType.t == CodeGenerators::Types::INT)
			valueHACK = "int";

		takeVal.setContent(valueHACK+" value = resRwapper->" + getResWrapperFunc(fieldType) +"(\""+fieldName+"\");"+
							"this->setValue(&value);");

		field.publicMethods.push_back(takeVal);
		field.namespaces.push_back("DatabaseTables");
		field.namespaces.push_back(t->tableName);
		field.namespaces.push_back("Fields");

		generator->addClass(field);
	}

}

void SQLWriter::createBaseClass(CodeGenerators::GenericClass* table, Table*t)
{
	CodeGenerators::Member baseClass(CodeGenerators::Types("DatabaseTables::DatabaseTable"),"DatabaseTables::DatabaseTable");
	table->addBaseClass(baseClass);
}

void SQLWriter::createNamespaces(CodeGenerators::GenericClass* table, Table*t)
{
	table->namespaces.push_back("DatabaseTables");
	table->namespaces.push_back(t->tableName);
}

void SQLWriter::createTableClassDependanceys(CodeGenerators::GenericClass* table, Table*t)
{
	CodeGenerators::Dependancy dependancy = CodeGenerators::Dependancy();
	dependancy.setPathToDependancy("../DatabaseTable.h");

	CodeGenerators::Dependancy ssdependancy = CodeGenerators::Dependancy();
	ssdependancy.setStandardLibraryDependancy("sstream");

	CodeGenerators::Dependancy exportMacroDependancy = CodeGenerators::Dependancy();
	exportMacroDependancy.setPathToDependancy("../../../exportMacros.h");

	table->dependanceys.push_back(dependancy);
	table->dependanceys.push_back(ssdependancy);
	table->dependanceys.push_back(exportMacroDependancy);

}

void SQLWriter::createGetUpdateQueryMethod(CodeGenerators::GenericClass* table, Table*t)
{
	CodeGenerators::Method getUpdateq("getUpdateQuery");
	getUpdateq.setReturnType(CodeGenerators::Types::STRING);
	std::stringstream contentSS;
	contentSS <<"std::stringstream update; \n" <<
			"update << \"UPDATE "<<t->tableName<<" SET \";" << std::endl <<
			"return update.str();" << std::endl;

	getUpdateq.setContent(contentSS.str());
	table->publicMethods.push_back(getUpdateq);
}

void SQLWriter::createGetInsertQueryMethod(CodeGenerators::GenericClass* table, Table*t)
{
	CodeGenerators::Method getInsertq("getInsertQuery");
	getInsertq.setReturnType(CodeGenerators::Types(CodeGenerators::Types::STRING));
	getInsertq.setContent("return NULL;");
	table->publicMethods.push_back(getInsertq);
}

void SQLWriter::createGetPrimaryKeyMethod(CodeGenerators::GenericClass* table, Table*t)
{
	CodeGenerators::Method getPrimaryKey("getPrimaryKey");
	getPrimaryKey.setReturnType(CodeGenerators::Types("DatabaseTables::IDatabaseTableField*"));
	getPrimaryKey.setContent("return this->"+t->primaryKey.FieldName()+";");
	table->publicMethods.push_back(getPrimaryKey);
}

void SQLWriter::createTableNameMethod(CodeGenerators::GenericClass* table, Table*t)
{
	CodeGenerators::Method tableName("tableName");
	tableName.setReturnType(CodeGenerators::Types(CodeGenerators::Types::STRING));
	tableName.setContent("return \""+t->tableName+"\";");
	table->publicMethods.push_back(tableName);
}

void SQLWriter::writeTable(Table* t, std::string location)
{

	CodeGenerators::GenericClass table(&t->tableName);
	createNamespaces(&table,t);
	createBaseClass(&table,t);
	createTableClassDependanceys(&table,t);

	createGetInsertQueryMethod(&table,t);
	createGetPrimaryKeyMethod(&table,t);
	createGetUpdateQueryMethod(&table,t);
	createTableNameMethod(&table,t);

	table.setPostClassModifierString("DLLCORE_API");



	CodeGenerators::Method getFields("getFields");
	getFields.addArgs(CodeGenerators::Types("std::vector<IDatabaseTableField*>*"),"fields");
	getFields.setReturnType(CodeGenerators::Types(CodeGenerators::Types::VOID));

	CodeGenerators::CppCodeGenerator cppCodeGen(location);
	createFields(&table,t,&cppCodeGen, &getFields);

	table.publicMethods.push_back(getFields);

	cppCodeGen.addClass(table);
	cppCodeGen.save();

}


