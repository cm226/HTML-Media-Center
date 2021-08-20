/*
 * Translater.h
 *
 *  Created on: Oct 1, 2012
 *      Author: craig
 */

#ifndef TRANSLATER_H_
#define TRANSLATER_H_

#include "../../../../Comms/MessageTranslaters/TranslatedMessages/AbstractMessage.h"
#include "TranslationFilters/MessageTranslationFilters.h"
#include "../../../../Comms/Protocals/IProtocal.h"

class Translater
{

	TranslationFilters::BaseTranslationFilter* translationFilter;
	coremodules::comms::protocals::IProtocal* protocal;

public:
	Translater();
	virtual ~Translater();

	AbstractMessage* translateMessage(char* message, unsigned int messagelength);
	void setProtocal(coremodules::comms::protocals::IProtocal* protocal);

private:
	AbstractMessage* messageFactory(std::string msgHeader,char* data, unsigned int messageLength);

	void buildTranslationFilterPipeline();
};

#endif /* TRANSLATER_H_ */
