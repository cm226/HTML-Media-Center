#pragma once 

#include "../../Files/Files.h"

#include <memory>
#include <string>
#include <functional>
#include <string>

class IHTTPUrlRouter
{
    public:
        class IConnection {

            public:

                virtual void Write(std::string) = 0;
                virtual std::string RequestBody() = 0;
                virtual std::map<std::string, std::string> RequestParams() = 0;

        };

        typedef std::function<void(std::shared_ptr<IConnection>)> URLHandle;


        virtual void MapURLRequest(std::string url, URLHandle handler) = 0;
        virtual void RegisterWidgit(std::string widgit) = 0;

};