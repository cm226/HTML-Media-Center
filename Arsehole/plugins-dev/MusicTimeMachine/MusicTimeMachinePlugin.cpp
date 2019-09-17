/*
 * MusicTimeMachinePlugin.cpp
 *
 *  Created on: 23 Jul 2013
 *      Author: craig
 */

#include "MusicTimeMachinePlugin.h"
#include "../../ArseholeCoreModules/CoreModules/HTMLRendere/Elements/MusicPlayer/MusicPlayer.h"

MusicTimeMachinePlugin::MusicTimeMachinePlugin(CoreModules* cm) : Plugin(cm)
{
	myGroup = MUSIC;
}

MusicTimeMachinePlugin::~MusicTimeMachinePlugin() {

}

bool MusicTimeMachinePlugin::whatDoYouLookLike(Page* p)
{
	coremodules::htmlrendere::elements::HTMLSong song1("name1", "url1", "artist1");
	coremodules::htmlrendere::elements::HTMLSong song2("name2", "url2", "artist2");
	coremodules::htmlrendere::elements::HTMLSong song3("name3", "url3", "artist3");

	coremodules::htmlrendere::elements::MusicPlaylist playlist;
	playlist.addSong(song1);
	playlist.addSong(song2);
	playlist.addSong(song3);

	coremodules::htmlrendere::elements::MusicPlayer* player = new coremodules::htmlrendere::elements::MusicPlayer(0, playlist);

	p->addElement(player);

	return true;
}

const char* MusicTimeMachinePlugin::pluginName()
{
	return "Music Time Machine Plugin";
}

