/*
 * Song.cpp
 *
 *  Created on: 16 Jul 2013
 *      Author: craig
 */

#include "Song.h"

namespace coremodules {
namespace htmlrendere {
namespace elements {

Song::Song(std::string name, std::string url, std::string artist):
	_len_hour(0),
	_len_min(0),
	_len_sec(0),
	_name(name),
	_artits(artist),
	_url(url)
{
	// TODO Auto-generated constructor stub

}


} /* namespace elements */
} /* namespace htmlrendere */
} /* namespace coremodules */
