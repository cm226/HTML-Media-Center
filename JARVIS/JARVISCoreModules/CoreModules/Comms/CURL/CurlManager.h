/*
 * CurlManager.h
 *
 *  Created on: Jan 20, 2013
 *      Author: craig
 */

#ifndef CURLMANAGER_H_
#define CURLMANAGER_H_

#include <curl.h>
#include "ICURLRequest.h"

namespace CommsNS {

class CurlManager {
private:
	std::string DownloadedResponse;
	int writer(char *data, size_t size, size_t nmemb, std::string *buffer_in);

public:
	CurlManager();
	virtual ~CurlManager();

	bool makeJASONRequest(ICURLRequest &, std::string & responce);


};

} /* namespace Comms */
#endif /* CURLMANAGER_H_ */
