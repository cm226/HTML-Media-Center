#ifndef _JSONREQUEST_H
#define _JSONREQUEST_H

#include <string>

namespace CommsNS {
	class IJSONRequest
	{
	public:
		IJSONRequest() {};
		virtual ~IJSONRequest() {};

		virtual void requestURL(std::string& url) = 0;
		virtual bool makeRequest(std::string& reply) =0;

	};
}


#endif
