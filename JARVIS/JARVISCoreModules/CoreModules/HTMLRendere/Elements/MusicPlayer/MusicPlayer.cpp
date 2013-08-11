/*
 * MusicPlayer.cpp
 *
 *  Created on: 16 Jul 2013
 *      Author: craig
 */

#include "MusicPlayer.h"
#include "../../../config.h"

#include <sstream>

namespace coremodules {
namespace htmlrendere {
namespace elements {

MusicPlayer::MusicPlayer(CALLBACk_HANDLE onPlaylistfinished, MusicPlaylist& playlist)
: IElement("MusicPlayer"), _playlist(playlist)
{
	_onPlaylistfinished = onPlaylistfinished;

	std::string playlistText = _playlist.getText();
	buildPlaylistHTML(playlist);

	this->appendJQueryMobileHeaderContent("	<div data-display=\"overlay\" data-position=\"right\" data-theme=\"a\" data-role=\"panel\" id=\"songPanel\">\
			<div id=\"songContainer\">\
			<ul data-role=\"listview\" data-icon=\"false\" data-inset=\"true\" data-filter=\"false\" data-theme=\"a\">"
			+ playlistHTML + "</ul>\
			</div>\
		</div><!-- /panel -->");

	includeJS(HTMLMEDIAPUBLIC + std::string("/js/jquery-1.10.1.min.js"));
	includeJS(HTMLMEDIAPUBLIC + std::string("/js/jquery.mobile-1.3.1.min.js"));

	includeCSS(HTMLMEDIAPUBLIC + std::string("/css/Mobile/jquery.mobile-1.3.1.min.css"));
	includeCSS(HTMLMEDIAPUBLIC + std::string("/css/Mobile/musicViewPlayer.css"));

	appendEmbeddedJSCode("var playlist = [" + playlistText + "];");
	appendEmbeddedJSCode("$( document ).on( \"pageinit\", \"#musicPlayer\", function() {\
    $( document ).on( \"swipeleft swiperight\", \"#musicPlayer\", function( e ) {\
        if ( $.mobile.activePage.jqmData( \"panel\" ) !== \"open\" ) {\
            if ( e.type === \"swipeleft\"  ) {\
                $( \"#songPanel\" ).panel( \"open\" );\
            }\
        }\
       });\
    });");
	includeJS(HTMLMEDIAPUBLIC + std::string("/js/player.js"));

	appendEmbeddedJSCode("$( document ).ready(function() { \n \
							$(\"#playBttn\").click(function(){playOrPause();}); \n \
						    $(\"#playPrev\").click(function(){playPrev();});\n \
						    $(\"#playNext\").click(function(){playNext();});\n \
						    $(\"#songContainer ul li a\").click(function(event) {\n \
							 event.preventDefault();\n \
							 playSong($(this).attr(\"href\"));\n \
							});\n \
			$(\"#volumeSlider\").change(function() {\n \
			  changeVolume($(\"#slider-2\").val());\n \
			});\n \
		});");

	//<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
}

MusicPlayer::~MusicPlayer()
{

}

void MusicPlayer::buildPlaylistHTML(MusicPlaylist& playlist)
{
	std::list<Song> songs =  playlist.getSongs();
	std::stringstream songsHTMLStrm;
	int counter =0;
	for(std::list<Song>::iterator songIt = songs.begin();
			songIt != songs.end(); songIt ++)
	{
		songsHTMLStrm << "<li><a href='"  << counter << "'>"<< songIt->getName()<<"</a></li>";
	}

	playlistHTML = songsHTMLStrm.str();
}

std::string MusicPlayer::getTagText()
{
	return "";
}

std::string MusicPlayer::getTagContent()
{
	std::stringstream player;

	player <<" <div data-role=\"controlgroup\" data-type=\"horizontal\" class=\"localnav\">\
            <a href=\"#\" data-role=\"button\" data-transition=\"fade\" id=\"playPrev\">Previus</a>\
            <a href=\"#\" data-role=\"button\" data-transition=\"fade\" id=\"playBttn\">Play/Pause</a>\
            <a href=\"#\" data-role=\"button\" data-transition=\"fade\" id=\"playNext\">Next</a>\
</div>\
<div id=\"currentSong\">\
	<div id=\"songInfo\">\
		<div id=\"albumImage\">\
		</div>\
		<div id=\"currentSongInfo\">\
			<h5>Album</h5>\
			<h3>Song</h3>\
		</div>\
	</div>\
</div>\
<div id=\"audioControls\">\
</div>\
<div id=\"volumeSlider\">\
  <input type=\"range\" name=\"slider-2\" id=\"slider-2\" data-highlight=\"true\" min=\"0\" max=\"100\" value=\"50\">\
</div>";

	return player.str();
}

} /* namespace elements */
} /* namespace htmlrendere */
} /* namespace coremodules */
