
var active = Documents.ActiveDoc;

var Controller = {

	getActive : function() {
	
		return Documents.ActiveDoc;
	}
};

var html = Documents.OpenHtmlFrame( moe.Config.ModulePath + "\\" + "forms\\markdown.html");
html.Model.onDocumentLoad = function(){
   // Dialogs.MsgBox("load","doc",0);
	html.Model.addExternalObject("Controller",Controller);
};

html.onClose = function() {
	//html.Model.RemoveExternalObject("Controller");
//	setTimeout( function() {Quit();},200);
	Quit();
}

Wait(0);

//html.object.document.parentWindow.init(active);   
