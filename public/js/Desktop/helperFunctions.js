

function shuffle()
{
	if(shuffleOn)
		shuffleOn = false;
	else
		shuffleOn = true;
}

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
		
			if(fillID != null)
		    document.getElementById(fillID).innerHTML=xmlhttp.responseText;
		}
	}

	if(arguments != null){
		xmlhttp.open("GET",target+'/'+(arguments.toString()).replace(",","/"),true);}
	else{
		xmlhttp.open("GET",target,true);}
	xmlhttp.send();
}


function getElementsByClass( searchClass, domNode, tagName) { 
	if (domNode == null) domNode = document;
	if (tagName == null) tagName = '*';
	var el = new Array();
	var tags = domNode.getElementsByTagName(tagName);
	var tcl = " "+searchClass+" ";
	for(i=0,j=0; i<tags.length; i++) { 
		var test = " " + tags[i].className + " ";
		if (test.indexOf(tcl) != -1) 
			el[j++] = tags[i];
	} 
	return el;
}


function displayPictureList(ArtistSelectID, imageDivID)
{
	var artistName = document.getElementById(ArtistSelectID).value;
	sendAJAXRequest("../Admin/getArtistBackgrounds", new Array (artistName),imageDivID);
}

function removeByID(id)
{
	var element = document.getElementById(id);
	element.parentNode.removeChild(element);
}


