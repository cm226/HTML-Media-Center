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


	V deSerialise(char* c)
	{
		return (V)c;
	}
	/*
	char* serialise(int i)
	{
		union IntUnion
		{
			int val;
			char* cval;
		};
		char* serialisedVal = new char[sizeof(int)];
		IntUnion iu;
		iu.val = i;
		mempcpy(serialisedVal, iu.cval, sizeof(int));
		return serialisedVal;
	}
	char* serialise(float f)
	{
		union floatUnion
		{
			float val;
			char* cval;
		};
		char* serialisedVal = new char[sizeof(float)];
		floatUnion fu;
		fu.val = f;
		mempcpy(serialisedVal, fu.cval, sizeof(float));
		return serialisedVal;
	}

	char* serialise(double d)
	{
		union doubleUnion
		{
			double val;
			char* cval;
		};
		char* serialisedVal = new char[sizeof(double)];
		doubleUnion du;
		du.val = d;
		mempcpy(serialisedVal, du.cval, sizeof(double));
		return serialisedVal;
	}*/
	char* serialise(V value)
	{
		union valUnion
		{
			V val;
			char* cval;
		};
		char* serialisedVal = new char[sizeof(V)];
		valUnion du;
		du.val = value;
		mempcpy(serialisedVal, du.cval, sizeof(V));
		return serialisedVal;
	}

};

} /* namespace ExtendedDatabase */
#endif /* SERIALIZER_H_ */
