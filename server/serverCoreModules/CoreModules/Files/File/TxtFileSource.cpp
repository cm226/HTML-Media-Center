#include "TxtFileSource.h"
#include "../../../../ErrorLogger/Errors/ErrorLogger.h"

#include <boost/filesystem.hpp>
#include <fstream>



TxtFileSource::TxtFileSource(
    std::string location,
    std::string defaultExt
) {

    if(location.find(".") == -1){
        location.append("."+defaultExt);
    }


    m_path = location;

    if (!boost::filesystem::exists(m_path))
	{
		ErrorLogger::logWarn("FileSystem: Txt File source created that doesn't exist! : " +
			m_path);
	}

}

TxtFileSource::TxtFileSource(
    Directory dir,
	std::string name,
	std::string defaultExt){
    
    if(name.find(".") == -1){
        name.append("."+defaultExt);
    }


    m_path = dir.toString() + name;

    if (!boost::filesystem::exists(m_path))
	{
		ErrorLogger::logWarn("FileSystem: Txt File source created that doesn't exist! : " +
			m_path);
	}
}

bool TxtFileSource::GetData(std::vector<unsigned char>& buffer){

    std::ifstream file(m_path, std::ios::in|std::ios::binary|std::ios::ate);
    if(!file){
        return false;
    }

    auto length = file.tellg();

    char* tmp_buffer = new char[length];
    file.read(tmp_buffer, length);

    std::copy(tmp_buffer, tmp_buffer + length, std::back_inserter(buffer));

    delete[] tmp_buffer;
    file.close();

    return true;

}

bool TxtFileSource::GetData(std::string& buffer){

    std::ifstream file(m_path, std::ios::in|std::ios::binary|std::ios::ate);
    if(!file){
        return false;
    }

    auto length = file.tellg();

    try {
        char* tmp_buffer = new char[length];

        file.seekg(0);
        file.read(tmp_buffer, length);

        buffer = std::string(tmp_buffer, length);

        delete[] tmp_buffer;
        return true;
    } catch (std::exception& e){

        ErrorLogger::logError("Failed to read file " +
             m_path + " got exception " + e.what());

        return false;
    }
    
}

size_t TxtFileSource::GetDataSize(){
    std::ifstream file(m_path);
    if(!file){
        return 0;
    }

    return file.tellg();
}

std::string TxtFileSource::ext(){
    auto period = m_path.find_last_of(".");
    if(period == std::string::npos){
        return "";
    }

    return m_path.substr(period);

}