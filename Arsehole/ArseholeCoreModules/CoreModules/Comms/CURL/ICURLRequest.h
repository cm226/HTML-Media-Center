#ifndef _ICURLREQUEST_
#define _ICURLREQUEST_

#include <string>

namespace CommsNS
{

	class ICURLRequest
	{
		public:
			virtual ~ICURLRequest(){};
			virtual void getRequestURL(std::string &url) =0;

	};


}


#endif
