#ifndef _AUDIO_CLASS
#define _AUDIO_CLASS


#include "../../../Framework/Plugin/Plugin.h"
#include <string>

namespace plugins
{


	enum AudioClasses // keep it general
	{
		ROCK, METTAL, ELECTRONIC
	};

	class AudioClasifier : Plugin
	{
	public:
		AudioClasifier(){}
		~AudioClasifier(){}

		AudioClasses clasify(std::string filename);
	private:


	};

}

#endif
