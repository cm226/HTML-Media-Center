cmake_minimum_required (VERSION 3.2)
project (arsehole)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -stdlib=libstdc++ -pthread -g -Wno-c++17-extensions -Wno-macro-redefined")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -ldl -lcurl -lstdc++ /usr/lib/x86_64-linux-gnu/libstdc++.so.6")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

find_package(Boost 1.58.0 REQUIRED COMPONENTS system filesystem signals thread)
find_package(OpenSSL REQUIRED)

include_directories (/home/craig/Programming/cpp_netlib/cpp-netlib-0.13.0-rc1)
include_directories(${Boost_INCLUDE_DIR})
include_directories (/home/craig/Programming/MySql/mariadb-connector-c-3.0.6-linux-x86_64/include/mariadb)

set(SRCS 
arsehole.cpp
Framework/FrameWork.cpp
Framework/MediaStreamResponder.cpp
Framework/PluginPageResponder.cpp
Framework/Plugin/Loader/Loader.cpp
Framework/Plugin/Plugin.cpp
Framework/Plugin/PageCallbackContext.cpp
)

link_directories(../bin)

add_executable(arsehole ${SRCS})
target_link_libraries( arsehole ${Boost_LIBRARIES} )

target_link_libraries( arsehole cppnetlib-server-parsers)
target_link_libraries( arsehole  libCoreModules.so)
target_link_libraries( arsehole OpenSSL::SSL)

install(TARGETS arsehole DESTINATION bin)
