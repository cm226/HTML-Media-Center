/*
 * Song.cpp
 *
 *  Created on: 16 Jul 2013
 *      Author: craig
 */

#include "HTMLSong.h"

namespace coremodules {
namespace htmlrendere {
namespace elements {

HTMLSong ::HTMLSong (std::string name, std::string url, std::string artist):
	_name(name),
	_artits(artist),
	_url(url),
	_len_hour(0),
	_len_min(0),
	_len_sec(0)
{
	int i = 0;
}


} /* namespace elements */
} /* namespace htmlrendere */
} /* namespace coremodules */
