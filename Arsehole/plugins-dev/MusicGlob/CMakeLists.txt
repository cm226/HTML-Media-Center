cmake_minimum_required (VERSION 3.7)
project (MusicGlob)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++17 -pthread -g")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ")

include_directories (/home/boss_man/Projects/mariadb_connector/mariadb-connector-c-3.0.6-src/include)
set(SRCS 
    MusicGlob.cpp
)

link_directories(../../build)

add_library(MusicGlob SHARED ${SRCS})
target_link_libraries( MusicGlob  libCoreModules.so)
