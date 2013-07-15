/*
 * FieldWriter.h
 *
 *  Created on: 14 Jul 2013
 *      Author: craig
 */

#ifndef FIELDWRITER_H_
#define FIELDWRITER_H_

#include <map>
#include <string>
#include <fstream>
#include "Serialisers/Serializer.h"

namespace ExtendedDatabase {

class FieldWriter {
private:
	std::string _Filename;
	std::ofstream _Output;

public:
	FieldWriter(std::string filename);
	virtual ~FieldWriter();

	template<class K, class V>
	void writeFields(Serializer<K> keySerialiser, Serializer<V> valueAreialiser, const std::map<K,V>& fields)
	{
		_Output.open(_Filename.c_str(), std::ofstream::binary);


		typename std::map<K, V>::const_iterator fieldIt = fields.begin();
		for(; fieldIt != fields.end(); fieldIt++)
		{
			K key = fieldIt->first;
			V value = fieldIt->second;

			int keyLen = 0, valueLen = 0;
			char* serialisedKey = keySerialiser.serialise(key, keyLen);
			char* serialisedValue = valueAreialiser.serialise(value, valueLen);

			_Output <<serialisedKey << ',' << serialisedValue << '\n';


			delete[] serialisedKey;
			delete[] serialisedValue;
		}

		_Output.close();
	}
};

} /* namespace ExtendedDatabase */
#endif /* FIELDWRITER_H_ */
