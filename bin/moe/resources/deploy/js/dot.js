
var active = Documents.ActiveDoc;

var Controller = {

	getActive : function() {
	
		return active;//Documents.ActiveDoc;
	}
};

var html = Documents.OpenHtmlFrame( moe.Config.ModulePath + "\\" + "forms\\dot.html");
html.Model.onDocumentLoad = function(){
	html.Model.addExternalObject("Controller",Controller);
	View.Tile();
};

html.onClose = function() {
	Quit();
}

Wait();
