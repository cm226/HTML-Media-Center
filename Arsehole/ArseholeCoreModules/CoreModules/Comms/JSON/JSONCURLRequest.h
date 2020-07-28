/*
 * JSONRequest.h
 *
 *  Created on: Jan 19, 2013
 *      Author: craig
 */

#include "IJSONRequest.h"
#include "../CURL/CurlManager.h"

#ifndef JSONREQUEST_H_
#define JSONREQUEST_H_

namespace CommsNS {

class JSONCURLRequest : public  IJSONRequest{
private:
	CurlManager& manager;
	std::string url;

public:
	JSONCURLRequest(CurlManager& manager);
	virtual ~JSONCURLRequest();

	void requestURL(const std::string& url);
	bool makeRequest(std::string& reply);

};

class CurlReqImp : public ICURLRequest
{
private:
	std::string url;
public:
	CurlReqImp(std::string url) : url(url){};
	virtual ~CurlReqImp(){}
	void getRequestURL(std::string &url){url = this->url;};

};

} /* namespace Comms */
#endif /* JSONREQUEST_H_ */
