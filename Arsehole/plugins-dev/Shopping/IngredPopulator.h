#pragma once 

#include <memory>
#include "../../ArseholeCoreModules/CoreModules/Comms/HTTPServer/IHTTPUrlRouter.h"
#include "../../ArseholeCoreModules/CoreModules/Comms/IComms.h"

class TaskList;

class IngredPopulator{

    public:
        IngredPopulator();

        void Initialise(
            std::shared_ptr<IHTTPUrlRouter> router,
            std::shared_ptr<TaskList> taskList,
            CommsNS::IComms* comms);

    private:
        std::string m_shopping_dir;

};