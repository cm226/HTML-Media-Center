window.onload = eventHook;

var selectedIndex = [0,0];

function eventHook()
{
	leftButtonHit.addHandler(moveSelectLeft);
	rightButtonHit.addHandler(moveSelectRight);
	upButtonHit.addHandler(moveSelectUp);
	downButtonHit.addHandler(moveSelectdown);
	selectButtonHit.addHandler(select);
}

function moveSelectLeft()
{
	document.getElementById(selectionMatrix[selectedIndex[1]][selectedIndex[0]]).setAttribute("class", "tile");
	if(selectedIndex[0] > 0)
		selectedIndex[0] = (selectedIndex[0] - 1) % selectionMatrix[selectedIndex[1]].length;
	
	document.getElementById(selectionMatrix[selectedIndex[1]][selectedIndex[0]]).setAttribute("class", "selectedTile");
}

function moveSelectRight()
{
	document.getElementById(selectionMatrix[selectedIndex[1]][selectedIndex[0]]).setAttribute("class", "tile");
	selectedIndex[0] = (selectedIndex[0] + 1) % selectionMatrix[selectedIndex[1]].length;
	document.getElementById(selectionMatrix[selectedIndex[1]][selectedIndex[0]]).setAttribute("class", "selectedTile");
}

function moveSelectUp()
{
	document.getElementById(selectionMatrix[selectedIndex[1]][selectedIndex[0]]).setAttribute("class", "tile");
	
	if(selectedIndex[1] > 0)
	selectedIndex[1] = (selectedIndex[1] - 1) % selectionMatrix.length;
	
	document.getElementById(selectionMatrix[selectedIndex[1]][selectedIndex[0]]).setAttribute("class", "selectedTile");
}

function moveSelectdown()
{
	document.getElementById(selectionMatrix[selectedIndex[1]][selectedIndex[0]]).setAttribute("class", "tile");
	
	selectedIndex[1] =  (selectedIndex[1] + 1) % selectionMatrix.length;
	
	if(selectedIndex[0] > selectionMatrix[selectedIndex[1]].length-1)
		selectedIndex[0] = selectionMatrix[selectedIndex[1]].length-1;
		
	document.getElementById(selectionMatrix[selectedIndex[1]][selectedIndex[0]]).setAttribute("class", "selectedTile");
}

function select()
{
	document.getElementById(selectionMatrix[selectedIndex[1]][selectedIndex[0]]).click();
}