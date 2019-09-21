cmake_minimum_required (VERSION 3.5)
project (CoreModules)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++14 -stdlib=libstdc++ -pthread -g -Wno-c++17-extensions -Wno-macro-redefined")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -fPIC -ldl -lcurl -lssl -lcrypto -lstdc++ /usr/lib/x86_64-linux-gnu/libstdc++.so.6")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

find_package(Boost 1.58.0 EXACT COMPONENTS system filesystem signals thread)


#include_directories (/home/boss_man/Projects/cpp-netlib )
include_directories (/home/craig/Programming/cpp_netlib/cpp-netlib-0.13.0-rc1)


include_directories(${Boost_INCLUDE_DIR})

SET(USING_MYSQL OFF)

#include_directories (/home/boss_man/Projects/mariadb_connector/mariadb-connector-c-3.0.6-src/include)
include_directories (/home/craig/Programming/MySql/mariadb-connector-c-3.0.6-linux-x86_64/include/mariadb)
include_directories (/home/craig/Programming/rapidJSON/include)

add_definitions(-DBOOST_NETWORK_ENABLE_HTTPS)

set(SRCS 
CoreModules/CoreModules.cpp
File.cpp
CoreModules/config.cpp
CoreModules/Database/Querys/Descriptor/Descriptor.cpp
CoreModules/Database/Querys/Descriptor/Limit.cpp
CoreModules/Database/Querys/Query.cpp
CoreModules/Database/Querys/NoBullshitQuery.cpp
CoreModules/Database/ResultWrapper.cpp
CoreModules/Database/Database.cpp
CoreModules/Database/Tables/DatabaseTable.cpp
CoreModules/Database/ExtendedPluginDB/SubCatagory.cpp
CoreModules/Database/ExtendedPluginDB/Serialisers/Serializer.cpp
CoreModules/Database/ExtendedPluginDB/FieldReader.cpp
CoreModules/Database/ExtendedPluginDB/Field.cpp
CoreModules/Database/ExtendedPluginDB/Catagory.cpp
CoreModules/Database/ExtendedPluginDB/FieldWriter.cpp
CoreModules/CoreModules.cpp
CoreModules/Files/Directory.cpp
CoreModules/Files/File/File.cpp
CoreModules/Files/File/IFileSource.cpp
CoreModules/Files/File/Base64FileDataURLSource.cpp
CoreModules/Files/File/TxtFileSource.cpp
CoreModules/Files/FileSystem.cpp
CoreModules/Comms/HTTPServer/POSTRequestHandler.cpp
CoreModules/Comms/HTTPServer/HTTPUrlRouter.cpp
CoreModules/Comms/HTTPServer/HTTPServer.cpp
CoreModules/Comms/Broadcaster.cpp
CoreModules/Comms/IPGetter.cpp
CoreModules/Comms/GetLanIPLinux.cpp
CoreModules/Comms/CURL/CurlManager.cpp
CoreModules/Comms/Transever/ITranseverConnection.cpp
CoreModules/Comms/Transever/ArseholeTranseverConnection.cpp
CoreModules/Comms/Transever/ITranseverConnectionFactory.cpp
CoreModules/Comms/Transever/TranseverConnectionFactory.cpp
CoreModules/Comms/Transever/Exceptions/TimeoutExpiredException.cpp
CoreModules/Comms/Transever/MessageChunker.cpp
CoreModules/Comms/Transever/TCPAsyncTransever.cpp
CoreModules/Comms/MessageTranslaters/Translater.cpp
CoreModules/Comms/MessageTranslaters/MessageSubject/MessageSubject.cpp
CoreModules/Comms/MessageTranslaters/MessageSubject/MessageSubjectEvent.cpp
CoreModules/Comms/MessageTranslaters/TranslationFilters/BaseTranslationFilter.cpp
CoreModules/Comms/MessageTranslaters/TranslationFilters/PluginPageTranslationFilter.cpp
CoreModules/Comms/MessageTranslaters/TranslationFilters/PluginInteractionFilter.cpp
CoreModules/Comms/MessageTranslaters/TranslationFilters/MediaStreamRequestFilter.cpp
CoreModules/Comms/MessageTranslaters/TranslationFilters/RequestDiagnosticMessageFilter.cpp
CoreModules/Comms/MessageTranslaters/TranslationFilters/AgentPollRequestFilter.cpp
CoreModules/Comms/MessageTranslaters/TranslationFilters/MobilePluginPageTranslationFilter.cpp
CoreModules/Comms/MessageTranslaters/TranslationFilters/PluginPollTranslationFilter.cpp
CoreModules/Comms/MessageTranslaters/TranslationFilters/CommandAndcontrolTranslationFilter.cpp
CoreModules/Comms/MessageTranslaters/TranslatedMessages/RequestDisagnosticsMessage.cpp
CoreModules/Comms/MessageTranslaters/TranslatedMessages/ComandAndControlMessage.cpp
CoreModules/Comms/MessageTranslaters/TranslatedMessages/AgentRequestReplyMessage.cpp
CoreModules/Comms/MessageTranslaters/TranslatedMessages/PluginPageMessage.cpp
CoreModules/Comms/MessageTranslaters/TranslatedMessages/AbstractMessage.cpp
CoreModules/Comms/MessageTranslaters/TranslatedMessages/AgentRequestMessage.cpp
CoreModules/Comms/MessageTranslaters/TranslatedMessages/RequestNextDataChunkMessage.cpp
CoreModules/Comms/MessageTranslaters/TranslatedMessages/MediaStreamRequestMessage.cpp
CoreModules/Comms/MessageTranslaters/TranslatedMessages/ReplyMessage.cpp
CoreModules/Comms/MessageTranslaters/TranslatedMessages/MobilePluginPageMessage.cpp
CoreModules/Comms/MessageTranslaters/TranslatedMessages/ListPluginsMessage.cpp
CoreModules/Comms/MessageTranslaters/TranslatedMessages/PluginInteractionRequestMessage.cpp
CoreModules/Comms/JSON/JSONCURLRequest.cpp
CoreModules/Comms/Comms.cpp
CoreModules/Comms/Protocals/StringMessageSerializer.cpp
CoreModules/Comms/Protocals/ChunckedTwoByteMsgLen.cpp
CoreModules/Comms/Protocals/IProtocal.cpp
CoreModules/Comms/Protocals/TwoByteMsgLen.cpp
CoreModules/TaskList/TaskList.cpp
CoreModules/TaskList/Scheduler.cpp
CoreModules/MediaStreaming/MediaStreaming/MusicPlaylist.cpp
CoreModules/MediaStreaming/MediaStreaming/Song.cpp
CoreModules/MediaStreaming/MediaStreaming/VLCTelnetInterface.cpp
CoreModules/MediaStreaming/MediaStreaming/MediaStreamer.cpp
CoreModules/MediaStreaming/MediaStreaming/Devices/DeviceList.cpp
CoreModules/MediaStreaming/MediaStreaming/Devices/AudioDevice.cpp
CoreModules/MediaStreaming/MediaStreaming/telnet.cpp
CoreModules/Sensors/MotionSensor.cpp
CoreModules/Sensors/Sensors.cpp
../ErrorLogger/Errors/ErrorLogger.cpp
../ErrorLogger/Errors/MyStackWalker.cpp

)

#link_directories(/home/boss_man/Projects/mariadb_connector/mariadb-connector-c-3.0.6-src/build/libmariadb)
link_directories(/home/craig/Programming/MySql/mariadb-connector-c-3.0.6-linux-x86_64/lib/mariadb)

link_directories(../bin)

add_library(CoreModules SHARED ${SRCS})

target_link_libraries( CoreModules cppnetlib-server-parsers)
target_link_libraries( CoreModules ${Boost_LIBRARIES} )
target_link_libraries( CoreModules libmariadbclient.a )

install(TARGETS CoreModules LIBRARY DESTINATION bin)