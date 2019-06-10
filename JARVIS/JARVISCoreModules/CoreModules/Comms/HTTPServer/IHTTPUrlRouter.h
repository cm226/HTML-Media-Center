#pragma once 

#include "../../Files/Files.h"

#include <memory>
#include <string>
#include <functional>

class IHTTPUrlRouter
{
    public:
        class IConnection {

            public:

                virtual void Write(std::string) = 0;
                virtual std::string RequestBody() = 0;

        };

        typedef std::function<void(std::shared_ptr<IConnection>)> URLHandle;


        virtual void MapURLRequest(std::string url, URLHandle handler) = 0;
        virtual void RegisterWidgit(std::shared_ptr<File> widgit) = 0;

};