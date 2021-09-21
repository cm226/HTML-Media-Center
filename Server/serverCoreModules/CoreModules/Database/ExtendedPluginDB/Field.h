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
#include "../../../../ErrorLogger/Errors/ErrorLogger.h"
#include "FieldReader.h"
#include "FieldWriter.h"

namespace ExtendedDatabase {

template <class T,class V>
class Field {

private:
	std::string filename;

	// flags
	bool dataAquired;
	bool serialisersSet;

	Serializer<T> _KeySerialiser;
	Serializer<V> _ValSerialiser;
	boost::shared_ptr<FieldReader> _FieldReader;

	std::map<T,V> fields;





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
			if(_FieldReader->nextField(_KeySerialiser, _ValSerialiser, key, value))
				fields[key] = value;
		}
		_FieldReader->closeFile();
	};

	bool checkDataIsAquired()
	{
		if(!dataAquired)
			ErrorLogger::logError("getting data before data is Acquired");

		return dataAquired;
	};

public:
	Field(std::string filename)
	:filename(filename),
	 _FieldReader(new FieldReader()),
	 dataAquired(false),
	 serialisersSet(false)
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

	void writeData(T key, V value)
	{
			fields[key] = value;
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

	void save()
	{
		FieldWriter fw(filename);
		fw.writeFields(_KeySerialiser, _ValSerialiser, fields);
	}
};

} /* namespace ExtendedDatabase */
#endif /* FIELD_H_ */
