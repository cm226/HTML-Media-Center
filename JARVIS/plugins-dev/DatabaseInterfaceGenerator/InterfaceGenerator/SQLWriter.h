/*
 * SQLWriter.h
 *
 *  Created on: 11 May 2013
 *      Author: craig
 */

#ifndef SQLWRITER_H_
#define SQLWRITER_H_

#include "Table.h"
#include "CodeGenerators/OOGenerators/GenericClass.h"
#include "CodeGenerators/OOGenerators/C++/CppCodeGenerator.h"

class SQLWriter {

private:

	void createBaseClass(CodeGenerators::GenericClass* table, Table*t);
	void createNamespaces(CodeGenerators::GenericClass* table, Table*t);
	void createTableClassDependanceys(CodeGenerators::GenericClass* table, Table*t);
	void createGetUpdateQueryMethod(CodeGenerators::GenericClass* table, Table*t);
	void createGetInsertQueryMethod(CodeGenerators::GenericClass* table, Table*t);
	void createGetPrimaryKeyMethod(CodeGenerators::GenericClass* table, Table*t);
	void createTableNameMethod(CodeGenerators::GenericClass* table, Table*t);


	void createFields(CodeGenerators::GenericClass* table, Table* t, CodeGenerators::AbstractOOCodeGenerator* generator,
			CodeGenerators::Method* getFieldsMethod);
	std::string getResWrapperFunc(CodeGenerators::Types type);
	CodeGenerators::Types remapSQLType(Field::sqlFieldType sqlType);

public:
	SQLWriter();
	virtual ~SQLWriter();

	void writeTable(Table* t, std::string location);
};

#endif /* SQLWRITER_H_ */
