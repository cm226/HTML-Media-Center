#pragma once
#include "BaseTranslationFilter.h"
#include "../../Protocals/IProtocal.h"

namespace TranslationFilters {

class MediaStreamRequestFilter: public TranslationFilters::BaseTranslationFilter {

public:
	MediaStreamRequestFilter(coremodules::comms::protocals::IProtocal* protocal);
	~MediaStreamRequestFilter(void);

	virtual AbstractMessage* translateMessage(std::string header, char* bytes, unsigned int bytesLength);

};

}

