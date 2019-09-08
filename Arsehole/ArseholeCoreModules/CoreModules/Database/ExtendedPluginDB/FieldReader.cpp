/*
 * FieldReader.cpp
 *
 *  Created on: 9 Jul 2013
 *      Author: craig
 */

#include "FieldReader.h"

namespace ExtendedDatabase {

FieldReader::FieldReader() {
	// TODO Auto-generated constructor stub

}

FieldReader::~FieldReader() {
	// TODO Auto-generated destructor stub
}

bool FieldReader::openFile(std::string filename)
{
	fileStream.open(filename.c_str(), std::ios_base::binary);
	return fileStream.good();
}

void FieldReader::closeFile()
{
	fileStream.close();
}

bool FieldReader::hasMoreFields()
{
	int peekVal = fileStream.peek();
	return !fileStream.eof() || peekVal != -1;
}

} /* namespace ExtendedDatabase */
