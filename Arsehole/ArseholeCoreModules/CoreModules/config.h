#pragma once

#include <memory>

class Config{

public:
    static bool ReadConfig(std::string configFile);
    static std::shared_ptr<Config> GetInstance();

    std::string Host() {return m_host;}
    bool Live(){return m_live;}
    std::string LogLocation(){return m_logLocation;}
    std::string TempLoc(){return m_tempLoc;}
    std::string WorkingFiles(){return m_workingFiles;}

    std::string DBName(){return m_dbName;}
    std::string DBUser(){return m_dbUser;}
    std::string DBPw(){return m_dbPassword;}
    
    std::string Version(){return m_version;}

    std::string MetOfficeAPIKey(){return m_metoffice_API_key;}
    std::string GoogleSearchKey(){return m_google_search_key;}
    std::string GoogleSearchEngine(){return m_google_search_engine;}

private:
    Config();
    bool Initialise(std::string);

    std::string m_host;
    std::string m_logLocation;
    std::string m_tempLoc;
    std::string m_workingFiles;
    std::string m_dbName;
    std::string m_dbUser;
    std::string m_dbPassword;
    std::string m_version;
    std::string m_metoffice_API_key;
    std::string m_google_search_key;
    std::string m_google_search_engine;

    bool m_live;

    static std::shared_ptr<Config> m_instance;

};