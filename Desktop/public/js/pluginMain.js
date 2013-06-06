$(document).ready(function()
	{
	    $('.collapableFolder').click(function()
		    {
			if($(this).css("width") != "50px")
				collapsFolder($(this));
			else
				uncollapsFolder($(this));
		    }
	     );

	     $('#newFolderAddBttn').click(function()
		{
			$('#newFolderName').toggle('fast');
		});


	     $('#newFolderAddBttnComplete').click(function()
		{
			var folderName = $("#newFolderNameVal").val();
			insertNewfolder(folderName);
			$('#newFolderName').fadeOut(); 
		});
	     
	}
);

function collapsFolder(folder)
{
	var pluginHolder = folder.find(".pluginHolder");
	pluginHolder.find('.plugin').fadeOut();
	folder.animate({
		width: '50px'
		},500); 
}

function uncollapsFolder(folder)
{
	var pluginHolder = folder.find(".pluginHolder");
	folder.animate({
		width: '250px'
		},500); 
	pluginHolder.find('.plugin').fadeIn();
}

function insertNewfolder(folderName)
{
	$('#content').append("<div class=\"collapableFolder\"> \
				<div class=\"collapsableFolderHeader\"> \
					<h4 class=\"widgetHeader\">" + folderName+ "</h4> \
				</div> \
			      </div>");
}
