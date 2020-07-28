#include "config.h"
#include "../../ErrorLogger/Errors/ErrorLogger.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

std::shared_ptr<Config> Config::m_instance = nullptr;

Config::Config(){
    
    // initialise the default config
    m_host = "localhost";
    m_logLocation = ".";
    m_tempLoc = ".";
    m_workingFiles = ".";
    m_dbName = "db_name";
    m_dbUser = "db_user";
    m_dbPassword = "db_pw";
    m_version = "0";
}

bool Config::Initialise(std::string configLocation){
    
    try{
        boost::property_tree::ptree pt;
        boost::property_tree::ini_parser::read_ini(configLocation, pt);
        
        m_host = pt.get<std::string>("urls.hostIP");
        pt.get<std::string>("urls.HTMLMediaRoot");
        pt.get<std::string>("urls.HTMLMediaPublic");

        m_live = pt.get<bool>("stuff.live");
        m_logLocation = pt.get<std::string>("stuff.logLocation");
        m_tempLoc = pt.get<std::string>("stuff.tempLoc");
        m_workingFiles = pt.get<std::string>("stuff.WorkingFiles");
        m_version = pt.get<std::string>("stuff.Version");

        m_dbName = pt.get<std::string>("database.DatabaseName");
        m_dbUser = pt.get<std::string>("database.DatabaseUser");
        m_dbPassword = pt.get<std::string>("database.DatabasePassword");

        m_metoffice_API_key = pt.get<std::string>("weather.metOfficeKey");

        m_google_search_key = pt.get<std::string>("google.key");
        m_google_search_engine = pt.get<std::string>("google.searchEngine");

    } catch(std::exception& e){
        ErrorLogger::logError(std::string("Failed to read config file :") 
        + e.what());
        return false;
    }

    return true;
    
}

bool Config::ReadConfig(
    std::string configLocation
) {

    m_instance = std::unique_ptr<Config>(new Config());
    return m_instance->Initialise(configLocation);
}

std::shared_ptr<Config> Config::GetInstance(
) {
    return Config::m_instance;
}