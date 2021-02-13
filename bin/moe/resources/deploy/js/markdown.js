
var active = Documents.ActiveDoc;

var Controller = {

	getActive : function() {
	
		return Documents.ActiveDoc;
	}
};

var html = Documents.OpenHtmlFrame( moe.Config.ConfigPath + "\\" + "forms\\markdown.html");
html.Model.onDocumentLoad = function(){
	html.Model.addExternalObject("Controller",Controller);
	View.Tile();
};

html.onClose = function() {
	Quit();
}

Wait();
