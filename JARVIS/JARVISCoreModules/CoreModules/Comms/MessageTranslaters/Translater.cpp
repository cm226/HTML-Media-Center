/*
 * Translater.cpp
 *
 *  Created on: Oct 1, 2012
 *      Author: craig
 */

#include "Translater.h"

#include "../../Errors/ErrorLogger.h"
#include "TranslatedMessages/TranslatedMessages.h"
#include <stdexcept>

Translater::Translater()
{
	this->protocal = NULL;
	this->translationFilter = NULL;
}

Translater::~Translater()
{
	delete this->translationFilter;
}

void Translater::setProtocal(coremodules::comms::protocals::IProtocal* protocal)
{
	this->protocal = protocal;
	if(this->translationFilter != NULL)
		delete this->translationFilter;

	this->buildTranslationFilterPipeline();
}

AbstractMessage* Translater::translateMessage(char* message, unsigned int messageLength)
{
	if(this->protocal == NULL)
	{
		throw std::runtime_error("Message Protocall not set before message translation attrempt");
	}

	unsigned int offset = 0;
	while(offset < messageLength && message[offset] != '$')
	{
		offset++;
	}
	if(offset >= messageLength)
	{
		ErrorLogger::logError("Header in message missing");
		return NULL;
	}

	std::string header(message,offset);

	AbstractMessage* translatedMessage = this->messageFactory(header,message,messageLength);
	if(translatedMessage == NULL)
	{
		ErrorLogger::logError("Unrecognized message Header:"+header);
	}
	return translatedMessage;
}

AbstractMessage* Translater::messageFactory(std::string msgHeader, char* data, unsigned int messageLength)
{
	return this->translationFilter->translateMessage(msgHeader,data,messageLength);
}

void Translater::buildTranslationFilterPipeline()
{
	TranslationFilters::PluginPollTranslationFilter* pluginPollFilter = new TranslationFilters::PluginPollTranslationFilter(this->protocal);
	TranslationFilters::CommandAndcontrolTranslationFilter* commandAndcontrolFilter = new TranslationFilters::CommandAndcontrolTranslationFilter(this->protocal);
	TranslationFilters::PluginPageTranslationFilter* pluginPageFilter = new TranslationFilters::PluginPageTranslationFilter(this->protocal);
	TranslationFilters::PluginInteractionFilter* pluginInteractionFilter = new TranslationFilters::PluginInteractionFilter(this->protocal);

	pluginPollFilter->setNextFilter(commandAndcontrolFilter);
	commandAndcontrolFilter->setNextFilter(pluginPageFilter);
	pluginPageFilter->setNextFilter(pluginInteractionFilter);


	this->translationFilter = pluginPollFilter;
}



