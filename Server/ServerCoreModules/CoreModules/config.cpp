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

        m_live = pt.get<bool>("stuff.live");
        m_logLocation = pt.get<std::string>("stuff.logLocation");
        m_tempLoc = pt.get<std::string>("stuff.tempLoc");
        m_workingFiles = pt.get<std::string>("stuff.WorkingFiles");
        m_version = pt.get<std::string>("stuff.Version");

        m_dbName = pt.get<std::string>("database.DatabaseName");
        m_dbUser = pt.get<std::string>("database.DatabaseUser");
        m_dbPassword = pt.get<std::string>("database.DatabasePassword");

        m_metoffice_API_key = pt.get<std::string>("weather.metOfficeKey");

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
    m_instance->m_config_loc = configLocation;

    return m_instance->Initialise(configLocation);
}

bool Config::WriteConfig(){
    try{
        boost::property_tree::ptree pt;
        

        pt.put("urls.hostIP", m_host);

        pt.put("stuff.live", m_live);
        pt.put("stuff.logLocation", m_logLocation);
        pt.put("stuff.tempLoc", m_tempLoc);
        pt.put("stuff.WorkingFiles", m_workingFiles);
        pt.put("stuff.Version", m_version);

        pt.put("database.DatabaseName", m_dbName);
        pt.put("database.DatabaseUser", m_dbUser);
        pt.put("database.DatabasePassword", m_dbPassword);

        pt.put("weather.metOfficeKey", m_metoffice_API_key);

        std::ofstream stream(m_config_loc, std::ios::out);
        boost::property_tree::ini_parser::write_ini(
            stream,pt
        );


    } catch(std::exception& e){
        return false;
    }

    return true;
}

std::shared_ptr<Config> Config::GetInstance(
) {
    return Config::m_instance;
}