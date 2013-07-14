/*
 * Field.h
 *
 *  Created on: 8 Jul 2013
 *      Author: craig
 */

#ifndef FIELD_H_
#define FIELD_H_

#include <string>
#include <map>
#include <boost/shared_ptr.hpp>
#include "Serialisers/Serializer.h"
#include "../../../../JARVISCoreModules/CoreModules/Errors/ErrorLogger.h"
#include "FieldReader.h"

namespace ExtendedDatabase {

template <class T,class V>
class Field {

private:
	std::string filename;

	Serializer<T> _KeySerialiser;
	Serializer<V> _ValSerialiser;
	boost::shared_ptr<FieldReader> _FieldReader;

	std::map<T,V> fields;

	// flags
	bool dataAquired;
	bool serialisersSet;



	void populateAllFields()
	{
		if(!_FieldReader->openFile(filename))
		{
			ErrorLogger::logError("Extended Database field trying to open file that doesn't exist");
			return;
		}

		while(_FieldReader->hasMoreFields())
		{
			T key;
			V value;
			_FieldReader->nextField(_KeySerialiser, _ValSerialiser, key, value);
			fields[key] = value;
		}
		_FieldReader->closeFile();
	}

public:
	Field(std::string filename)
	:filename(filename),
	 dataAquired(false),
	 serialisersSet(false),
	 _FieldReader(new FieldReader())
	{};
	virtual ~Field(){};

	void setSerialisers(Serializer<T> keySerialiser ,Serializer<V> valSerialiser)
	{
		serialisersSet = true;
		_KeySerialiser = keySerialiser;
		_ValSerialiser = valSerialiser;
	}
	const std::map<T,V>& getAllFields()
	{
		checkDataIsAquired();
		return fields;
	};

	V lookupValue(T key)
	{
		checkDataIsAquired();
		//TODO add contains check
		return fields[key];
	};

	bool checkDataIsAquired()
	{
		if(!dataAquired)
			ErrorLogger::logError("getting data before data is Aquired");

		return dataAquired;
	}

	void aquireData()
	{
		if(!serialisersSet)
			ErrorLogger::logError("Extended Database Field aquire data called before serialisers set");
		else
		{
			dataAquired = true;
			populateAllFields();
		}
	};
	void releaseData()
	{
		fields.clear();
	};
};

} /* namespace ExtendedDatabase */
#endif /* FIELD_H_ */
