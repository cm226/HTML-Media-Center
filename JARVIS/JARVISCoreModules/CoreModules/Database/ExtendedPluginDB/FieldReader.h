/*
 * FieldReader.h
 *
 *  Created on: 9 Jul 2013
 *      Author: craig
 */

#ifndef FIELDREADER_H_
#define FIELDREADER_H_

#include <string>
#include <boost/algorithm/string.hpp>
#include "Serialisers/Serializer.h"
#include <fstream>

namespace ExtendedDatabase {

class FieldReader {
private:
	std::ifstream fileStream;

public:
	FieldReader();
	virtual ~FieldReader();

	bool openFile(std::string filename);
	void closeFile();
	bool hasMoreFields();

	template<class K, class V>
	void nextField(Serializer<K> keyDeserialiser, Serializer<V> valDeserialiser, K& key, V& val)
	{
		int bufferSize =1024;
		char* buffer = new char[bufferSize];
		fileStream.getline(buffer,bufferSize);

		std::string line(buffer);
		delete[] buffer;
		int index = line.find(',');
		std::string value = line.substr(index);
		std::string keyStr = line.substr(0, index);

		key = keyDeserialiser.deSerialise(keyStr.c_str());
		val = valDeserialiser.deSerialise(value.c_str());

	}
};

} /* namespace ExtendedDatabase */
#endif /* FIELDREADER_H_ */
