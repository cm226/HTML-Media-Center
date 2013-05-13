/*
 * Translater.h
 *
 *  Created on: Oct 1, 2012
 *      Author: craig
 */

#ifndef TRANSLATER_H_
#define TRANSLATER_H_

#include "TranslatedMessages/AbstractMessage.h"
#include "TranslationFilters/MessageTranslationFilters.h"

class Translater {

	TranslationFilters::BaseTranslationFilter* translationFilter;

public:
	Translater();
	virtual ~Translater();

	AbstractMessage* translateMessage(char* message, unsigned int messagelength);

private:
	AbstractMessage* messageFactory(std::string msgHeader,char* data, unsigned int messageLength);

	void buildTranslationFilterPipeline();
};

#endif /* TRANSLATER_H_ */
