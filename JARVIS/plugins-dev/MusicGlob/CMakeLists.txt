cmake_minimum_required (VERSION 3.7)
project (MusicGlob)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++17 -pthread -g")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ")

include_directories (~/Projects/mpsqlConnector/mysql-connector-c++-8.0.12-linux-glibc2.12-x86-64bit/include/jdbc)

set(SRCS 
    MusicGlob.cpp
)

link_directories(../../build)

add_library(MusicGlob SHARED ${SRCS})
target_link_libraries( MusicGlob  libCoreModules.so)
