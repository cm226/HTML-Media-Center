
function postwith (to,p, target) {
	if(!target)
		target = "_self";
  var myForm = document.createElement("form");
  myForm.target=target;
  myForm.method="post" ;
  myForm.action = to ;
  for (var k in p) {
    var myInput = document.createElement("input") ;
    myInput.setAttribute("name", k) ;
    myInput.setAttribute("value", p[k]);
    myForm.appendChild(myInput) ;
  }
  document.body.appendChild(myForm) ;
  myForm.submit() ;
  document.body.removeChild(myForm) ;
}

function switchToTextbox(selectionID, selectDivID, inputName, selectItems)
	{
		var inputElement = document.getElementById(selectionID);
		if(inputElement.getAttribute( "type" ) == "text")
		{
			var seriesBox = document.getElementById(selectDivID);
			var selectHTML = '<select name="'+inputName+'" id="'+selectionID+'" >';
			
			for (var i = 0; i < selectItems.length; i++) 
			{
				selectHTML += '<option value="' + selectItems[i] + '">'+ selectItems[i]+ '</option>';
			}
			selectHTML += '</select> ';
			seriesBox.innerHTML = selectHTML;
		}
		else
		{
			var seriesBox = document.getElementById(selectDivID);
			seriesBox.innerHTML = '<input type="text" name="'+inputName+'" id="'+selectionID+'"/> ';
		}
	}

function sendAJAXRequest(target, arguments, fillID)
{
	var xmlhttp;
	xmlhttp=new XMLHttpRequest();

	xmlhttp.onreadystatechange=function()
	{
		if (xmlhttp.readyState==4 && xmlhttp.status==200)
		{
		    document.getElementById(fillID).innerHTML=xmlhttp.responseText;
		}
	}

	if(arguments != null){
		xmlhttp.open("GET",target+'/'+(arguments.toString()).replace(",","/"),true);}
	else{
		xmlhttp.open("GET",target,true);}
	xmlhttp.send();
}

function test(test, anothertest)
{
	
}

function updateAlbumList(ArtistName,AlbumListID)
{
	
	sendAJAXRequest("../Admin/getArtistAlbums", new Array (ArtistName),AlbumListID);
}



function displayPictureList(ArtistSelectID, imageDivID)
{
	var artistName = document.getElementById(ArtistSelectID).value;
	sendAJAXRequest("../Admin/getArtistBackgrounds", new Array ('Nickleback'),imageDivID);
}


