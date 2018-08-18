cmake_minimum_required (VERSION 3.7)
project (CoreModules)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++17 -pthread -g")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -fPIC -ldl -lcurl -lmysqlcppconn")

find_package(Boost COMPONENTS system filesystem signals REQUIRED)


include_directories (/home/boss_man/Projects/cpp-netlib )

include_directories(${Boost_INCLUDE_DIR})
include_directories (~/Projects/mpsqlConnector/mysql-connector-c++-8.0.12-linux-glibc2.12-x86-64bit/include/jdbc)

set(SRCS 
../CoreModules/CoreModules.cpp
../File.cpp
../CoreModules/Database/Querys/Descriptor/Descriptor.cpp
../CoreModules/Database/Querys/Descriptor/Limit.cpp
../CoreModules/Database/Querys/Query.cpp
../CoreModules/Database/Querys/Constraints/Equals.cpp
../CoreModules/Database/Querys/Constraints/GreaterThan.cpp
../CoreModules/Database/Querys/Constraints/LessThan.cpp
../CoreModules/Database/Querys/Constraints/LessThanEqualToo.cpp
../CoreModules/Database/Querys/Constraints/GreatherThanEqualTo.cpp
../CoreModules/Database/Querys/Constraints/ConstraintGroup/ConstraintGroup.cpp
../CoreModules/Database/Querys/Constraints/ConstraintGroup/ORConstraintGroup.cpp
../CoreModules/Database/Querys/Constraints/Like.cpp
../CoreModules/Database/Querys/UpdateQuery.cpp
../CoreModules/Database/ResultWrapper.cpp
../CoreModules/Database/Database.cpp
../CoreModules/Database/Tables/Episode/Fields/episodeID.cpp
../CoreModules/Database/Tables/Episode/Fields/episodePlayCount.cpp
../CoreModules/Database/Tables/Episode/Fields/episodeName.cpp
../CoreModules/Database/Tables/Episode/Fields/seasonID.cpp
../CoreModules/Database/Tables/Episode/Fields/episodeNumber.cpp
../CoreModules/Database/Tables/Episode/Fields/filePath.cpp
../CoreModules/Database/Tables/Episode/Episode.cpp
../CoreModules/Database/Tables/Picture/Fields/picURL.cpp
../CoreModules/Database/Tables/Picture/Fields/albumName2.cpp
../CoreModules/Database/Tables/Picture/Fields/picName.cpp
../CoreModules/Database/Tables/Picture/Picture.cpp
../CoreModules/Database/Tables/PictureAlbum/Fields/albumName1.cpp
../CoreModules/Database/Tables/PictureAlbum/PictureAlbum.cpp
../CoreModules/Database/Tables/Song/Fields/albumID1.cpp
../CoreModules/Database/Tables/Song/Fields/songID.cpp
../CoreModules/Database/Tables/Song/Fields/playCount.cpp
../CoreModules/Database/Tables/Song/Fields/songName.cpp
../CoreModules/Database/Tables/Song/Fields/songRating.cpp
../CoreModules/Database/Tables/Song/Fields/songURL.cpp
../CoreModules/Database/Tables/Song/Song.cpp
../CoreModules/Database/Tables/Season/Season.cpp
../CoreModules/Database/Tables/Season/Fields/seriesName1.cpp
../CoreModules/Database/Tables/Season/Fields/seriesNumber.cpp
../CoreModules/Database/Tables/Season/Fields/seasonID1.cpp
../CoreModules/Database/Tables/PlaylistSong/Fields/playlistName2.cpp
../CoreModules/Database/Tables/PlaylistSong/Fields/songID1.cpp
../CoreModules/Database/Tables/PlaylistSong/Fields/playlistSongID.cpp
../CoreModules/Database/Tables/PlaylistSong/PlaylistSong.cpp
../CoreModules/Database/Tables/Artist/Fields/genre.cpp
../CoreModules/Database/Tables/Artist/Fields/artistID.cpp
../CoreModules/Database/Tables/Artist/Fields/artistRating.cpp
../CoreModules/Database/Tables/Artist/Fields/artistName.cpp
../CoreModules/Database/Tables/Artist/Artist.cpp
../CoreModules/Database/Tables/IDatabaseTableField.cpp
../CoreModules/Database/Tables/Album/Fields/artistID1.cpp
../CoreModules/Database/Tables/Album/Fields/albumID.cpp
../CoreModules/Database/Tables/Album/Fields/albumRating.cpp
../CoreModules/Database/Tables/Album/Fields/albumName.cpp
../CoreModules/Database/Tables/Album/Album.cpp
../CoreModules/Database/Tables/Series/Fields/seriesGenre.cpp
../CoreModules/Database/Tables/Series/Fields/seriesIMDB.cpp
../CoreModules/Database/Tables/Series/Fields/seriesName.cpp
../CoreModules/Database/Tables/Series/Series.cpp
../CoreModules/Database/Tables/Playlist/Fields/playlistPlayCount.cpp
../CoreModules/Database/Tables/Playlist/Fields/playlistName1.cpp
../CoreModules/Database/Tables/Playlist/Playlist.cpp
../CoreModules/Database/Tables/Movie/Fields/movieGenre.cpp
../CoreModules/Database/Tables/Movie/Fields/movieURL.cpp
../CoreModules/Database/Tables/Movie/Fields/movieName.cpp
../CoreModules/Database/Tables/Movie/Fields/movieIMDB.cpp
../CoreModules/Database/Tables/Movie/Fields/thumbnailURL.cpp
../CoreModules/Database/Tables/Movie/Fields/movieID.cpp
../CoreModules/Database/Tables/Movie/Movie.cpp
../CoreModules/Database/Tables/DatabaseTable.cpp
../CoreModules/Database/ExtendedPluginDB/SubCatagory.cpp
../CoreModules/Database/ExtendedPluginDB/Serialisers/Serializer.cpp
../CoreModules/Database/ExtendedPluginDB/FieldReader.cpp
../CoreModules/Database/ExtendedPluginDB/Field.cpp
../CoreModules/Database/ExtendedPluginDB/Catagory.cpp
../CoreModules/Database/ExtendedPluginDB/FieldWriter.cpp
../CoreModules/CoreModules.cpp
../CoreModules/Files/Directory.cpp
../CoreModules/Files/File/File.cpp
../CoreModules/Files/File/IFileSource.cpp
../CoreModules/Files/File/Base64FileDataURLSource.cpp
../CoreModules/Files/File/TxtFileSource.cpp
../CoreModules/Files/FileSystem.cpp
../CoreModules/Comms/HTTPServer/HTTPServer.cpp
../CoreModules/Comms/Broadcaster.cpp
../CoreModules/Comms/IPGetter.cpp
../CoreModules/Comms/GetLanIPLinux.cpp
../CoreModules/Comms/CURL/CurlManager.cpp
../CoreModules/Comms/Transever/ITranseverConnection.cpp
../CoreModules/Comms/Transever/JARVISTranseverConnection.cpp
../CoreModules/Comms/Transever/ITranseverConnectionFactory.cpp
../CoreModules/Comms/Transever/TranseverConnectionFactory.cpp
../CoreModules/Comms/Transever/Exceptions/TimeoutExpiredException.cpp
../CoreModules/Comms/Transever/MessageChunker.cpp
../CoreModules/Comms/Transever/TCPAsyncTransever.cpp
../CoreModules/Comms/MessageTranslaters/Translater.cpp
../CoreModules/Comms/MessageTranslaters/MessageSubject/MessageSubject.cpp
../CoreModules/Comms/MessageTranslaters/MessageSubject/MessageSubjectEvent.cpp
../CoreModules/Comms/MessageTranslaters/TranslationFilters/BaseTranslationFilter.cpp
../CoreModules/Comms/MessageTranslaters/TranslationFilters/PluginPageTranslationFilter.cpp
../CoreModules/Comms/MessageTranslaters/TranslationFilters/PluginInteractionFilter.cpp
../CoreModules/Comms/MessageTranslaters/TranslationFilters/MediaStreamRequestFilter.cpp
../CoreModules/Comms/MessageTranslaters/TranslationFilters/RequestDiagnosticMessageFilter.cpp
../CoreModules/Comms/MessageTranslaters/TranslationFilters/AgentPollRequestFilter.cpp
../CoreModules/Comms/MessageTranslaters/TranslationFilters/MobilePluginPageTranslationFilter.cpp
../CoreModules/Comms/MessageTranslaters/TranslationFilters/PluginPollTranslationFilter.cpp
../CoreModules/Comms/MessageTranslaters/TranslationFilters/CommandAndcontrolTranslationFilter.cpp
../CoreModules/Comms/MessageTranslaters/TranslatedMessages/RequestDisagnosticsMessage.cpp
../CoreModules/Comms/MessageTranslaters/TranslatedMessages/ComandAndControlMessage.cpp
../CoreModules/Comms/MessageTranslaters/TranslatedMessages/AgentRequestReplyMessage.cpp
../CoreModules/Comms/MessageTranslaters/TranslatedMessages/PluginPageMessage.cpp
../CoreModules/Comms/MessageTranslaters/TranslatedMessages/AbstractMessage.cpp
../CoreModules/Comms/MessageTranslaters/TranslatedMessages/AgentRequestMessage.cpp
../CoreModules/Comms/MessageTranslaters/TranslatedMessages/RequestNextDataChunkMessage.cpp
../CoreModules/Comms/MessageTranslaters/TranslatedMessages/MediaStreamRequestMessage.cpp
../CoreModules/Comms/MessageTranslaters/TranslatedMessages/ReplyMessage.cpp
../CoreModules/Comms/MessageTranslaters/TranslatedMessages/MobilePluginPageMessage.cpp
../CoreModules/Comms/MessageTranslaters/TranslatedMessages/ListPluginsMessage.cpp
../CoreModules/Comms/MessageTranslaters/TranslatedMessages/PluginInteractionRequestMessage.cpp
../CoreModules/Comms/JSON/JSONCURLRequest.cpp
../CoreModules/Comms/Comms.cpp
../CoreModules/Comms/Protocals/StringMessageSerializer.cpp
../CoreModules/Comms/Protocals/ChunckedTwoByteMsgLen.cpp
../CoreModules/Comms/Protocals/IProtocal.cpp
../CoreModules/Comms/Protocals/TwoByteMsgLen.cpp
../CoreModules/EventModel/EventHandler/EventHandler.cpp
../CoreModules/EventModel/EventHandler/EvntHandlerBase.cpp
../CoreModules/EventModel/Events/Event.cpp
../CoreModules/EventModel/Events/EventSig.cpp
../CoreModules/EventModel/EventManager.cpp
../CoreModules/HTMLRendere/PageBuilders/DesktopPageBuilder.cpp
../CoreModules/HTMLRendere/PageBuilders/MobilePageBuilder.cpp
../CoreModules/HTMLRendere/Containers/ElementList.cpp
../CoreModules/HTMLRendere/Containers/IContainer.cpp
../CoreModules/HTMLRendere/Containers/Form.cpp
../CoreModules/HTMLRendere/Elements/Lable.cpp
../CoreModules/HTMLRendere/Elements/CheckBox.cpp
../CoreModules/HTMLRendere/Elements/DockingLayout/DockingLayout.cpp
../CoreModules/HTMLRendere/Elements/DockingLayout/DockedElements/TopDockedElement.cpp
../CoreModules/HTMLRendere/Elements/DockingLayout/DockedElements/RightDockedElement.cpp
../CoreModules/HTMLRendere/Elements/DockingLayout/DockedElements/LeftDockedElement.cpp
../CoreModules/HTMLRendere/Elements/DockingLayout/DockedElements/BottomDockedElement.cpp
../CoreModules/HTMLRendere/Elements/TextBox.cpp
../CoreModules/HTMLRendere/Elements/LineBreak.cpp
../CoreModules/HTMLRendere/Elements/FormSubmit.cpp
../CoreModules/HTMLRendere/Elements/Hyperlink.cpp
../CoreModules/HTMLRendere/Elements/HTMLImage.cpp
../CoreModules/HTMLRendere/Elements/FileUpload.cpp
../CoreModules/HTMLRendere/Elements/MusicPlayer/MusicPlayer.cpp
../CoreModules/HTMLRendere/Elements/MusicPlayer/MusicPlaylist.cpp
../CoreModules/HTMLRendere/Elements/MusicPlayer/HTMLSong.cpp
../CoreModules/HTMLRendere/Elements/Dropdown/Dropdown.cpp
../CoreModules/HTMLRendere/Elements/Dropdown/DropdownElement.cpp
../CoreModules/HTMLRendere/Elements/MenuList/MenuList.cpp
../CoreModules/HTMLRendere/IElement.cpp
../CoreModules/HTMLRendere/Page.cpp
../CoreModules/HTMLRendere/URL/IURLBuilder.cpp
../CoreModules/HTMLRendere/URL/URLBuilder.cpp
../CoreModules/HTMLRendere/URL/URLBuilderFactory.cpp
../CoreModules/TaskList/TaskList.cpp
../../MediaStreaming/MediaStreaming/MusicPlaylist.cpp
../../MediaStreaming/MediaStreaming/Song.cpp
../../MediaStreaming/MediaStreaming/VLCTelnetInterface.cpp
../../MediaStreaming/MediaStreaming/MediaStreamer.cpp
../../MediaStreaming/MediaStreaming/Devices/DeviceList.cpp
../../MediaStreaming/MediaStreaming/Devices/AudioDevice.cpp
../../MediaStreaming/MediaStreaming/telnet.cpp
../../ErrorLogger/Errors/ErrorLogger.cpp
../../ErrorLogger/Errors/MyStackWalker.cpp

)

link_directories(/home/boss_man/Projects/mpsqlConnector/mysql-connector-c++-8.0.12-linux-glibc2.12-x86-64bit/lib64)
link_directories(/home/boss_man/Projects/cpp-netlib/build/libs/network/src)

add_library(CoreModules SHARED ${SRCS})

target_link_libraries( CoreModules ${Boost_LIBRARIES} )
target_link_libraries( CoreModules libcppnetlib-server-parsers.so )