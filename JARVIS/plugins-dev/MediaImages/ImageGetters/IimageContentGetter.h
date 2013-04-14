/*
	Author : Craig Matear
*/
#pragma once
#ifndef IMAGEGETTERS_IIMAGECONTENTGETTER_H
#define IMAGEGETTERS_IIMAGECONTENTGETTER_H

#include "../../../JARVIS/Framework/Plugin/Plugin.h"
namespace imagegetters {


/**
	IimageContentGetter
*/
class IimageContentGetter
{
public:
	/**
		ctor
	*/
	IimageContentGetter();

	/**
		dtor
	*/
	~IimageContentGetter();
	virtual void registerFunctions(Plugin* registerer){};

};




}


#endif



