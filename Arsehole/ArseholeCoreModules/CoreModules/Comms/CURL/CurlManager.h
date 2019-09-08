/*
 * CurlManager.h
 *
 *  Created on: Jan 20, 2013
 *      Author: craig
 */

#ifndef CURLMANAGER_H_
#define CURLMANAGER_H_

#include <curl/curl.h>
#include "ICURLRequest.h"
#include <string>

namespace CommsNS {

class CurlManager {
private:
	std::string DownloadedResponse;

public:
	CurlManager();
	virtual ~CurlManager();
	void appendResponce(char* val, size_t len){DownloadedResponse = DownloadedResponse.append(val,len);};


	bool makeJASONRequest(ICURLRequest &, std::string & responce);
	bool downloadItemToFile(std::string internetURL, std::string outputFile);


};

} /* namespace Comms */
#endif /* CURLMANAGER_H_ */
