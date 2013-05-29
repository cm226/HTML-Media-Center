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
	}
);

function collapsFolder(folder)
{
	folder.find(".pluginHolder").css("visibility","hidden");
	folder.css("width","50px");
}

function uncollapsFolder(folder)
{
	folder.find(".pluginHolder").css("visibility","visible");
	folder.css("width","auto");
}
