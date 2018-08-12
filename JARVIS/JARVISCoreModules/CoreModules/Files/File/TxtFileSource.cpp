#include "TxtFileSource.h"

#include <fstream>

TxtFileSource::TxtFileSource(std::string path){
    m_path = path;
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

    char* tmp_buffer = new char[length];

    file.seekg(0);
    file.read(tmp_buffer, length);

    buffer = std::string(tmp_buffer, length);

    delete[] tmp_buffer;
    return true;
}

size_t TxtFileSource::GetDataSize(){
    std::ifstream file(m_path);
    if(!file){
        return 0;
    }

    return file.tellg();
}