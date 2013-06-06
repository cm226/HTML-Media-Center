/*
 * CommandAndcontrolTranslationFilter.cpp
 *
 *  Created on: Oct 14, 2012
 *      Author: craig
 */

#include "CommandAndcontrolTranslationFilter.h"
#include "../../../Errors/ErrorLogger.h"

namespace TranslationFilters {

CommandAndcontrolTranslationFilter::CommandAndcontrolTranslationFilter(coremodules::comms::protocals::IProtocal* protocal): BaseTranslationFilter(protocal) {
	// TODO Auto-generated constructor stub

}

CommandAndcontrolTranslationFilter::~CommandAndcontrolTranslationFilter() {
	// TODO Auto-generated destructor stub
}

AbstractMessage* CommandAndcontrolTranslationFilter::translateMessage(std::string header, char* bytes, unsigned int bytesLength)
{
	if(header.compare(ComandAndControlMessage::getHeader()) == 0)
		{
			ErrorLogger::logInfo("Command And Control Message Receved");
			return new ComandAndControlMessage(bytes, bytesLength);
		}

		return this->forwardMessage(header,bytes,bytesLength);

}

} /* namespace TranslationFilters */
