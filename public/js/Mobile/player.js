

var shuffleOn = false;
var currentSong = 0;
var prevSong = -1;
var allSongsPlayedEvnt = new Event();



function songsFinished()
{
	console.log("test");
	allSongsPlayedEvnt.execute();
}



// player functions


function fillAudio(src)
{
	var audioStr = "<audio controls=\"controls\" id=\"audioPlayer\" onended=\"playNext();\">";
	audioStr += "<source src=\""+ src+"\" type=\"audio/mp3\"/> </audio>";
	
	var audioDiv = document.getElementById('audioControls');
	audioDiv.innerHTML = audioStr;
}

function fillAudioInfo(Name, Artist)
{
	var AudioInfoStr = "<h3>"+Name+"</h3>";
	AudioInfoStr+= "<h5>"+Artist+"</h5>";

	var songInfo = $("#currentSongInfo");
	songInfo.html(AudioInfoStr);
}

function fillAlbumImage(url)
{
	var albumImgStr = "<img src=\""+url+"\" id=\"Albumimgtag\" height=\"50%\" width=\"auto\"/>";

	var albumImg = document.getElementById('albumImage');
	albumImg.innerHTML = albumImgStr;
	
}
function shuffle()
{
	if(shuffleOn)
		shuffleOn = false;
	else
		shuffleOn = true;
}

function playNext()
{
	prevSong = currentSong;
	currentSong++;
	if(currentSong >= numSongs)
		songsFinished();
	else
		play();
}

function playPrev()
{
	if(currentSong <= 1)	
		return;

	prevSong = currentSong 
	currentSong--;
	play();
}

function playSong(number)
{
	prevSong = currentSong 
	currentSong = number;
	play();
}

function play()
{
	if(shuffleOn)
	{
		var randomnumber=Math.floor(Math.random()*numSongs)+1;

		while(randomnumber == currentSong)
			randomnumber = Math.floor(Math.random()*numSongs)+1;
	
		currentSong = randomnumber;
	}

	
	fillAudio(myPlaylist[currentSong].mp3);
	fillAudioInfo(myPlaylist[currentSong].title, myPlaylist[currentSong].artist);
	fillAlbumImage(myPlaylist[currentSong].cover);
	updatePlayingList(prevSong,currentSong);
	
	document.getElementById('audioPlayer').play();
}

function playOrPause()
{
	var player = document.getElementById('audioPlayer');
	if(!player)
	{
		play();	
		return;
	}


	if(player.paused )
		player.play();
	else
		player.pause();
}

function changeVolume(newVolume)
{
	var player = document.getElementById('audioPlayer');
	if(player)
	{
		player.volume = newVolume/100;
	}
}

function downloadSong(songNumber)
{
	var id = myPlaylist[songNumber].id;
	window.location = "../Music/downloadSong/"+String(id);
}

function updatePlayingList(from, to)
{

}

