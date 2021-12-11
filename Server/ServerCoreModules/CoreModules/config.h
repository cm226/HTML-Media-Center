#pragma once

#include <memory>

class Config{

public:
    static bool ReadConfig(std::string configFile);
    bool WriteConfig();

    static std::shared_ptr<Config> GetInstance();

    bool Live(){return m_live;}
    std::string LogLocation(){return m_logLocation;}
    std::string TempLoc(){return m_tempLoc;}
    std::string WorkingFiles(){return m_workingFiles;}

    std::string DBName(){return m_dbName;}
    void DBName(std::string name){m_dbName = name;}
    std::string DBUser(){return m_dbUser;}
    void DBUser(std::string user){m_dbUser = user;}
    std::string DBPw(){return m_dbPassword;}
    void DBPw(std::string pw){ m_dbPassword = pw;}
    
    std::string Version(){return m_version;}

    std::string MetOfficeAPIKey(){return m_metoffice_API_key;}
    void MetOfficeAPIKey(std::string key){m_metoffice_API_key = key;}

private:
    Config();
    bool Initialise(std::string);

    std::string m_logLocation;
    std::string m_tempLoc;
    std::string m_workingFiles;
    std::string m_dbName;
    std::string m_dbUser;
    std::string m_dbPassword;
    std::string m_version;
    std::string m_metoffice_API_key;

    bool m_live;

    static std::shared_ptr<Config> m_instance;
    std::string m_config_loc;

};