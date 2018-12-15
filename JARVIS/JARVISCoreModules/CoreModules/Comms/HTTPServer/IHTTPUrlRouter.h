#pragma once 

#include <memory>
#include <string>
#include <functional>

class IHTTPUrlRouter
{
    public:
        class IConnection {

            public:

                virtual void Write(std::string) = 0;

        };

        typedef std::function<void(std::shared_ptr<IConnection>)> URLHandle;


        virtual void MapURLRequest(std::string url, URLHandle handler) = 0;

};