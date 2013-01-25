/*
 * CurlManager.cpp
 *
 *  Created on: Jan 20, 2013
 *      Author: craig
 */

#include "CurlManager.h"
#include <sstream>

namespace CommsNS {

static std::string DownloadedResponse = "";

CurlManager::CurlManager() {

}

CurlManager::~CurlManager() {

}

static int writer(char *data, size_t size, size_t nmemb, std::string *buffer_in)
{

    // Is there anything in the buffer?
    if (buffer_in != NULL)
    {
        // Append the data to the buffer
        buffer_in->append(data, size * nmemb);

        // How much did we write?
        DownloadedResponse = *buffer_in;

        return size * nmemb;
    }

    return 0;
}

static int fileWriter(char *data, size_t size, size_t nmemb, FILE *stream)
{
	return fwrite(data, size, nmemb, stream);
}

bool CurlManager::makeJASONRequest(ICURLRequest & req, std::string & responce)
{
	CURL* curl;

	CURLcode res;
	struct curl_slist *headers=NULL; // init to NULL is important
	std::ostringstream oss;

	curl_slist_append(headers, "Accept: application/json");
	curl_slist_append( headers, "Content-Type: application/json");
	curl_slist_append( headers, "charsets: utf-8");
	curl = curl_easy_init();
	bool worked = false;

	if (curl)
	    {
			std::string URL;
			req.getRequestURL(URL);

			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str() );
	        curl_easy_setopt(curl, CURLOPT_HTTPGET,1);
	        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
	        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,&writer);

	        res = curl_easy_perform(curl);

	        if (CURLE_OK == res)
	        {
	            char *ct;
	            res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
	            if((CURLE_OK == res) && ct)
	            {
	            	responce = DownloadedResponse;
	            	worked = true;
	            }
	        }
	    }


	curl_easy_cleanup(curl);
	return worked;
}


bool CurlManager::downloadItemToFile(std::string internetURL, std::string outputFile)
{
	CURL *curl;
    FILE *fp;
    CURLcode res;
	const char *url = internetURL.c_str();
	const char* outfilename = outputFile.c_str();
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fileWriter);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
    }

    return true;
}




}



/* namespace Comms */
