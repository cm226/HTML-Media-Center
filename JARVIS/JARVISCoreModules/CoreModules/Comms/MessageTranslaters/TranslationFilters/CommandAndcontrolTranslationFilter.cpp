/*
 * CommandAndcontrolTranslationFilter.cpp
 *
 *  Created on: Oct 14, 2012
 *      Author: craig
 */

#include "CommandAndcontrolTranslationFilter.h"

namespace TranslationFilters {

CommandAndcontrolTranslationFilter::CommandAndcontrolTranslationFilter() {
	// TODO Auto-generated constructor stub

}

CommandAndcontrolTranslationFilter::~CommandAndcontrolTranslationFilter() {
	// TODO Auto-generated destructor stub
}

AbstractMessage* CommandAndcontrolTranslationFilter::translateMessage(std::string header, char* bytes, unsigned int bytesLength)
{
	if(header.compare(ComandAndControlMessage::getHeader()) == 0)
		{
			return new ComandAndControlMessage(bytes, bytesLength);
		}

		return this->forwardMessage(header,bytes,bytesLength);

}

} /* namespace TranslationFilters */
