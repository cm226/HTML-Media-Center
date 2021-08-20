/*
 * AgentPollRequestFilter.h
 *
 *  Created on: 23 Aug 2013
 *      Author: craig
 */

#ifndef AGENTPOLLREQUESTFILTER_H_
#define AGENTPOLLREQUESTFILTER_H_

#include "BaseTranslationFilter.h"

namespace TranslationFilters {

class AgentPollRequestFilter : public BaseTranslationFilter
{

public:
	AgentPollRequestFilter(coremodules::comms::protocals::IProtocal* protocal);
	virtual ~AgentPollRequestFilter();

	AbstractMessage* translateMessage(std::string header, char* bytes, unsigned int bytesLength);
};

} /* namespace TranslationFilters */
#endif /* AGENTPOLLREQUESTFILTER_H_ */
