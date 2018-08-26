cmake_minimum_required (VERSION 3.7)
project (JARVIS)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -g")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -ldl -lcurl")

find_package(Boost COMPONENTS system filesystem signals thread REQUIRED)


include_directories (/home/boss_man/Projects/cpp-netlib )

include_directories(${Boost_INCLUDE_DIR})
include_directories (/home/boss_man/Projects/mariadb_connector/mariadb-connector-c-3.0.6-src/include)

set(SRCS 
../JARVIS/JARVIS.cpp
../JARVIS/Framework/FrameWork.cpp
../JARVIS/Framework/MediaStreamResponder.cpp
../JARVIS/Framework/PluginPageResponder.cpp
../JARVIS/Framework/Plugin/Loader/Loader.cpp
../JARVIS/Framework/Plugin/Plugin.cpp
../JARVIS/Framework/Plugin/PageCallbackContext.cpp
)

link_directories(/home/boss_man/Projects/cpp-netlib/build/libs/network/src)
link_directories(./)

add_executable(JARVIS ${SRCS})
target_link_libraries( JARVIS ${Boost_LIBRARIES} )
target_link_libraries( JARVIS libcppnetlib-server-parsers.so )
target_link_libraries( JARVIS  libCoreModules.so)