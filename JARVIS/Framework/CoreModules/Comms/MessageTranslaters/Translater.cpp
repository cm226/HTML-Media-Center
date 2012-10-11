/*
 * Translater.cpp
 *
 *  Created on: Oct 1, 2012
 *      Author: craig
 */

#include "Translater.h"

#include "../../Errors/ErrorLogger.h"
#include "TranslatedMessages/TranslatedMessages.h"

Translater::Translater() {

}

Translater::~Translater() {
}

AbstractMessage* Translater::translateMessage(const char* message, unsigned int messageLength)
{
	unsigned int offset = 0;
	while(message[offset] != '\0' || offset >= messageLength)
	{
		offset++;
	}
	if(offset >= messageLength)
		ErrorLogger::logError("Header in message missing");

	std::string header(message,offset);

	return this->messageFactory(header,message,messageLength);
}

AbstractMessage* Translater::messageFactory(std::string msgHeader, const char* data, unsigned int messageLength)
{
	return this->translationFilter->translateMessage(msgHeader,data,messageLength);

}

void Translater::buildTranslationFilterPipeline()
{
	this->translationFilter = new TranslationFilters::PluginPollTranslationFilter();
}



