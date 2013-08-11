var fileCounter = 0;
var highestFileNumber = fileCounter;

function addMp3Box()
{
	fileCounter++;

	if(fileCounter > highestFileNumber)
		highestFileNumber = fileCounter;

	var mp3FileDiv = document.createElement('div');
	var mp3Lable = document.createElement('label');
	var mp3Input = document.createElement('input');
	
	var mp3NameLable = document.createElement('label');
	var mp3NameTxt = document.createElement('input');
	var mp3AlbumLabel = document.createElement('label');
	var mp3AlbumSelect = document.createElement('select');
	var removeMp3Bttn = document.createElement('a');

	mp3Lable.innerHTML = "mp3 file: ";
	mp3NameLable.innerHTML = " name: ";
	mp3AlbumLabel.innerHTML = " album: ";
	removeMp3Bttn.innerHTML = "x";
	
	mp3FileDiv.setAttribute('id','mp3'+fileCounter);
	
	mp3Input.setAttribute('type', 'file');
	mp3Input.setAttribute('name', 'file'+fileCounter);
	mp3Input.setAttribute('class', 'file');

	removeMp3Bttn.setAttribute('class','removeMp3Bttn');
	removeMp3Bttn.setAttribute('onClick','removeMp3Box('+fileCounter+');');

	mp3NameTxt.setAttribute('name','songName'+fileCounter);
	mp3NameTxt.setAttribute('type','text');
	mp3AlbumSelect.setAttribute('name','filealbum'+fileCounter);
	mp3AlbumSelect.setAttribute('class','albumSelect');
	mp3AlbumSelect.setAttribute('id','albumSelect'+fileCounter);
	

	mp3FileDiv.appendChild(mp3Lable);
	mp3FileDiv.appendChild(mp3Input);
	mp3FileDiv.appendChild(mp3NameLable);
	mp3FileDiv.appendChild(mp3NameTxt);
	mp3FileDiv.appendChild(mp3AlbumLabel);
	mp3FileDiv.appendChild(mp3AlbumSelect);
	mp3FileDiv.appendChild(removeMp3Bttn);
	

	document.getElementById('mp3Files').appendChild(mp3FileDiv); 
	document.getElementById('numberOfFiles').setAttribute('value',highestFileNumber);
}

function removeMp3Box(id)
{
	removeByID("mp3"+id);
	fileCounter--;
	document.getElementById('numberOfFiles').setAttribute('value',fileCounter);
	
}

function addNewAlbum()
{
	var e = document.getElementById("artistID");
	var artistID = e.options[e.selectedIndex].value;
	var albumName =  document.getElementById("AlbumName").value;
	
	sendAJAXRequest("../Admin/addNewArtistAlbum", new Array (artistID, albumName),null);
}

function addNewArtist()
{
	var newArtistName = document.getElementById("newArtist").value;
	
	sendAJAXRequest("../Admin/addNewArtist", new Array (newArtistName),null);
}

function updateAlbumList(ArtistName,AlbumListID)
{
	
	sendAJAXRequest("../Admin/getArtistAlbums", new Array (ArtistName),AlbumListID);

}

function updateAllAlbumLists(ArtistName, className)
{
	var listCount = 0;
	var albums = getElementsByClass(className);

	for(i=0; i<albums.length; i++) 
		updateAlbumList(ArtistName,albums[i].getAttribute('id'));
	
}

