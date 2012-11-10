var fileCounter = 0;

function addMp3Box()
{
	fileCounter++;

	var mp3FileDiv = document.createElement('div');
	var mp3Lable = document.createElement('label');
	var mp3Input = document.createElement('input');
	
	var mp3NameLable = document.createElement('label');
	var mp3NameTxt = document.createElement('input');
	var mp3AlbumLabel = document.createElement('label');
	var mp3AlbumSelect = document.createElement('select');

	mp3Lable.innerHTML = "mp3 file: ";
	mp3NameLable.innerHTML = " name: ";
	mp3AlbumLabel.innerHTML = " album: ";
	
	mp3Input.setAttribute('type', 'file');
	mp3Input.setAttribute('name', 'file'+fileCounter);
	mp3Input.setAttribute('class', 'file');

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
	

	document.getElementById('mp3Files').appendChild(mp3FileDiv); 
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

