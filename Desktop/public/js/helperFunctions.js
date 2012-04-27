
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

function updateAlbumList(ArtistName,AlbumListID)
{
	var xmlhttp;
	xmlhttp=new XMLHttpRequest();

	xmlhttp.onreadystatechange=function()
	{
		if (xmlhttp.readyState==4 && xmlhttp.status==200)
		{
		    document.getElementById(AlbumListID).innerHTML=xmlhttp.responseText;
		}
	}

	xmlhttp.open("GET","../Admin/getArtistAlbums/"+ArtistName,true);
	xmlhttp.send();
	
}
