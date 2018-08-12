cmake_minimum_required (VERSION 3.7)
project (JARVIS)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -g")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -ldl -lcurl -lmysqlcppconn")

find_package(Boost COMPONENTS system filesystem signals thread REQUIRED)


include_directories (/home/boss_man/Projects/cpp-netlib )

include_directories(${Boost_INCLUDE_DIR})
include_directories (~/Projects/mpsqlConnector/mysql-connector-c++-8.0.12-linux-glibc2.12-x86-64bit/include/jdbc)

set(SRCS 
../JARVIS/JARVIS.cpp
../JARVIS/Framework/FrameWork.cpp
../JARVIS/Framework/MediaStreamResponder.cpp
../JARVIS/Framework/PluginPageResponder.cpp
../JARVIS/Framework/Plugin/Loader/Loader.cpp
../JARVIS/Framework/Plugin/Plugin.cpp
../JARVIS/Framework/Plugin/PageCallbackContext.cpp

../JARVISCoreModules/CoreModules/CoreModules.cpp
../JARVISCoreModules/File.cpp
../JARVISCoreModules/CoreModules/Database/Querys/Descriptor/Descriptor.cpp
../JARVISCoreModules/CoreModules/Database/Querys/Descriptor/Limit.cpp
../JARVISCoreModules/CoreModules/Database/Querys/Query.cpp
../JARVISCoreModules/CoreModules/Database/Querys/Constraints/Equals.cpp
../JARVISCoreModules/CoreModules/Database/Querys/Constraints/GreaterThan.cpp
../JARVISCoreModules/CoreModules/Database/Querys/Constraints/LessThan.cpp
../JARVISCoreModules/CoreModules/Database/Querys/Constraints/LessThanEqualToo.cpp
../JARVISCoreModules/CoreModules/Database/Querys/Constraints/GreatherThanEqualTo.cpp
../JARVISCoreModules/CoreModules/Database/Querys/Constraints/ConstraintGroup/ConstraintGroup.cpp
../JARVISCoreModules/CoreModules/Database/Querys/Constraints/ConstraintGroup/ORConstraintGroup.cpp
../JARVISCoreModules/CoreModules/Database/Querys/Constraints/Like.cpp
../JARVISCoreModules/CoreModules/Database/Querys/UpdateQuery.cpp
../JARVISCoreModules/CoreModules/Database/ResultWrapper.cpp
../JARVISCoreModules/CoreModules/Database/Database.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Episode/Fields/episodeID.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Episode/Fields/episodePlayCount.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Episode/Fields/episodeName.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Episode/Fields/seasonID.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Episode/Fields/episodeNumber.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Episode/Fields/filePath.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Episode/Episode.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Picture/Fields/picURL.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Picture/Fields/albumName2.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Picture/Fields/picName.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Picture/Picture.cpp
../JARVISCoreModules/CoreModules/Database/Tables/PictureAlbum/Fields/albumName1.cpp
../JARVISCoreModules/CoreModules/Database/Tables/PictureAlbum/PictureAlbum.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Song/Fields/albumID1.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Song/Fields/songID.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Song/Fields/playCount.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Song/Fields/songName.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Song/Fields/songRating.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Song/Fields/songURL.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Song/Song.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Season/Season.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Season/Fields/seriesName1.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Season/Fields/seriesNumber.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Season/Fields/seasonID1.cpp
../JARVISCoreModules/CoreModules/Database/Tables/PlaylistSong/Fields/playlistName2.cpp
../JARVISCoreModules/CoreModules/Database/Tables/PlaylistSong/Fields/songID1.cpp
../JARVISCoreModules/CoreModules/Database/Tables/PlaylistSong/Fields/playlistSongID.cpp
../JARVISCoreModules/CoreModules/Database/Tables/PlaylistSong/PlaylistSong.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Artist/Fields/genre.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Artist/Fields/artistID.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Artist/Fields/artistRating.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Artist/Fields/artistName.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Artist/Artist.cpp
../JARVISCoreModules/CoreModules/Database/Tables/IDatabaseTableField.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Album/Fields/artistID1.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Album/Fields/albumID.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Album/Fields/albumRating.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Album/Fields/albumName.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Album/Album.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Series/Fields/seriesGenre.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Series/Fields/seriesIMDB.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Series/Fields/seriesName.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Series/Series.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Playlist/Fields/playlistPlayCount.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Playlist/Fields/playlistName1.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Playlist/Playlist.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Movie/Fields/movieGenre.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Movie/Fields/movieURL.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Movie/Fields/movieName.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Movie/Fields/movieIMDB.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Movie/Fields/thumbnailURL.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Movie/Fields/movieID.cpp
../JARVISCoreModules/CoreModules/Database/Tables/Movie/Movie.cpp
../JARVISCoreModules/CoreModules/Database/Tables/DatabaseTable.cpp
../JARVISCoreModules/CoreModules/Database/ExtendedPluginDB/SubCatagory.cpp
../JARVISCoreModules/CoreModules/Database/ExtendedPluginDB/Serialisers/Serializer.cpp
../JARVISCoreModules/CoreModules/Database/ExtendedPluginDB/FieldReader.cpp
../JARVISCoreModules/CoreModules/Database/ExtendedPluginDB/Field.cpp
../JARVISCoreModules/CoreModules/Database/ExtendedPluginDB/Catagory.cpp
../JARVISCoreModules/CoreModules/Database/ExtendedPluginDB/FieldWriter.cpp
../JARVISCoreModules/CoreModules/CoreModules.cpp
../JARVISCoreModules/CoreModules/Files/Directory.cpp
../JARVISCoreModules/CoreModules/Files/File/File.cpp
../JARVISCoreModules/CoreModules/Files/File/IFileSource.cpp
../JARVISCoreModules/CoreModules/Files/File/Base64FileDataURLSource.cpp
../JARVISCoreModules/CoreModules/Files/File/TxtFileSource.cpp
../JARVISCoreModules/CoreModules/Files/FileSystem.cpp
../JARVISCoreModules/CoreModules/Comms/HTTPServer/HTTPServer.cpp
../JARVISCoreModules/CoreModules/Comms/Broadcaster.cpp
../JARVISCoreModules/CoreModules/Comms/IPGetter.cpp
../JARVISCoreModules/CoreModules/Comms/GetLanIPLinux.cpp
../JARVISCoreModules/CoreModules/Comms/CURL/CurlManager.cpp
../JARVISCoreModules/CoreModules/Comms/Transever/ITranseverConnection.cpp
../JARVISCoreModules/CoreModules/Comms/Transever/JARVISTranseverConnection.cpp
../JARVISCoreModules/CoreModules/Comms/Transever/ITranseverConnectionFactory.cpp
../JARVISCoreModules/CoreModules/Comms/Transever/TranseverConnectionFactory.cpp
../JARVISCoreModules/CoreModules/Comms/Transever/Exceptions/TimeoutExpiredException.cpp
../JARVISCoreModules/CoreModules/Comms/Transever/MessageChunker.cpp
../JARVISCoreModules/CoreModules/Comms/Transever/TCPAsyncTransever.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/Translater.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/MessageSubject/MessageSubject.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/MessageSubject/MessageSubjectEvent.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslationFilters/BaseTranslationFilter.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslationFilters/PluginPageTranslationFilter.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslationFilters/PluginInteractionFilter.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslationFilters/MediaStreamRequestFilter.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslationFilters/RequestDiagnosticMessageFilter.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslationFilters/AgentPollRequestFilter.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslationFilters/MobilePluginPageTranslationFilter.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslationFilters/PluginPollTranslationFilter.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslationFilters/CommandAndcontrolTranslationFilter.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/RequestDisagnosticsMessage.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/ComandAndControlMessage.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/AgentRequestReplyMessage.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/PluginPageMessage.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/AbstractMessage.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/AgentRequestMessage.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/RequestNextDataChunkMessage.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/MediaStreamRequestMessage.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/ReplyMessage.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/MobilePluginPageMessage.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/ListPluginsMessage.cpp
../JARVISCoreModules/CoreModules/Comms/MessageTranslaters/TranslatedMessages/PluginInteractionRequestMessage.cpp
../JARVISCoreModules/CoreModules/Comms/JSON/JSONCURLRequest.cpp
../JARVISCoreModules/CoreModules/Comms/Comms.cpp
../JARVISCoreModules/CoreModules/Comms/Protocals/StringMessageSerializer.cpp
../JARVISCoreModules/CoreModules/Comms/Protocals/ChunckedTwoByteMsgLen.cpp
../JARVISCoreModules/CoreModules/Comms/Protocals/IProtocal.cpp
../JARVISCoreModules/CoreModules/Comms/Protocals/TwoByteMsgLen.cpp
../JARVISCoreModules/CoreModules/EventModel/EventHandler/EventHandler.cpp
../JARVISCoreModules/CoreModules/EventModel/EventHandler/EvntHandlerBase.cpp
../JARVISCoreModules/CoreModules/EventModel/Events/Event.cpp
../JARVISCoreModules/CoreModules/EventModel/Events/EventSig.cpp
../JARVISCoreModules/CoreModules/EventModel/EventManager.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/PageBuilders/DesktopPageBuilder.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/PageBuilders/MobilePageBuilder.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Containers/ElementList.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Containers/IContainer.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Containers/Form.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/Lable.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/CheckBox.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/DockingLayout/DockingLayout.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/DockingLayout/DockedElements/TopDockedElement.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/DockingLayout/DockedElements/RightDockedElement.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/DockingLayout/DockedElements/LeftDockedElement.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/DockingLayout/DockedElements/BottomDockedElement.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/TextBox.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/LineBreak.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/FormSubmit.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/Hyperlink.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/HTMLImage.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/FileUpload.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/MusicPlayer/MusicPlayer.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/MusicPlayer/MusicPlaylist.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/MusicPlayer/HTMLSong.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/Dropdown/Dropdown.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/Dropdown/DropdownElement.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Elements/MenuList/MenuList.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/IElement.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/Page.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/URL/IURLBuilder.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/URL/URLBuilder.cpp
../JARVISCoreModules/CoreModules/HTMLRendere/URL/URLBuilderFactory.cpp
../JARVISCoreModules/CoreModules/TaskList/TaskList.cpp
../MediaStreaming/MediaStreaming/MusicPlaylist.cpp
../MediaStreaming/MediaStreaming/Song.cpp
../MediaStreaming/MediaStreaming/VLCTelnetInterface.cpp
../MediaStreaming/MediaStreaming/MediaStreamer.cpp
../MediaStreaming/MediaStreaming/Devices/DeviceList.cpp
../MediaStreaming/MediaStreaming/Devices/AudioDevice.cpp
../MediaStreaming/MediaStreaming/telnet.cpp


../ErrorLogger/Errors/ErrorLogger.cpp
../ErrorLogger/Errors/MyStackWalker.cpp

)

link_directories(/home/boss_man/Projects/mpsqlConnector/mysql-connector-c++-8.0.12-linux-glibc2.12-x86-64bit/lib64)
link_directories(/home/boss_man/Projects/cpp-netlib/build/libs/network/src)

add_executable(JARVIS ${SRCS})
target_link_libraries( JARVIS ${Boost_LIBRARIES} )

target_link_libraries( JARVIS libcppnetlib-server-parsers.a )