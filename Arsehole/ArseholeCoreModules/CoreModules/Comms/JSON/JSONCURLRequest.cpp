/*
 * JSONRequest.cpp
 *
 *  Created on: Jan 19, 2013
 *      Author: craig
 */

#include "JSONCURLRequest.h"

namespace CommsNS {

JSONCURLRequest::JSONCURLRequest(CurlManager& manager) : IJSONRequest(), manager(manager)
{


}

JSONCURLRequest::~JSONCURLRequest()
{

}


void JSONCURLRequest::requestURL(const std::string& url)
{
	 this->url = url;
}

bool JSONCURLRequest::makeRequest(std::string& reply)
{
	CurlReqImp curReq(this->url);
	return this->manager.makeJASONRequest(curReq,reply);
}

} /* namespace Comms */
