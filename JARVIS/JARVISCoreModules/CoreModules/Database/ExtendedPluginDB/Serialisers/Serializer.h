/*
 * Serializer.h
 *
 *  Created on: 8 Jul 2013
 *      Author: craig
 */

#ifndef SERIALIZER_H_
#define SERIALIZER_H_

#include <stdexcept>

namespace ExtendedDatabase {

template <class V> class Serializer {
public:
	Serializer(){};
	virtual ~Serializer(){};


	V deSerialise(const char* c, int length)
	{
		V value = 0;
		int nullPaddingBytes = (sizeof(V) - length)-1;
		for(int i = 0; i < length; i++)
		{
			char valByte = c[i];
			value = value | valByte;
			if(i < length-1)
				value = value << 8;
		}
		return value;
	}

	char* serialise(V value, int& len)
	{
		char* serialisedVal = new char[sizeof(V)];
		len = sizeof(V);
		mempcpy(serialisedVal, &value, sizeof(V));
		return serialisedVal;
	}

};

} /* namespace ExtendedDatabase */
#endif /* SERIALIZER_H_ */
