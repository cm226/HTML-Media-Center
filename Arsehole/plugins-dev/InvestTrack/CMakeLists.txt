cmake_minimum_required (VERSION 3.2)
project (InvestTracker)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread -g -Wno-c++17-extensions")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -ldl -lcurl -lstdc++ /usr/lib/x86_64-linux-gnu/libstdc++.so.6")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")
SET(BUILD_SHARED_LIBS ON)

find_package(Boost 1.58.0 REQUIRED COMPONENTS system filesystem signals thread)

include_directories (/home/craig/Programming/MySql/mariadb-connector-c-3.0.6-linux-x86_64/include/mariadb)
include_directories(${Boost_INCLUDE_DIR})
include_directories (/home/craig/Programming/rapidJSON/include)

set(SRCS 
InvestTracker.cpp
)

link_directories(../../bin)
link_directories(/home/craig/Programming/cpp_netlib_build/Debug)

add_library(InvestTracker ${SRCS})
target_link_libraries( InvestTracker ${Boost_LIBRARIES} )
target_link_libraries( InvestTracker  libCoreModules.so)

install(TARGETS InvestTracker DESTINATION .)
