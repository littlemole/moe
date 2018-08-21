
var active = Documents.ActiveDoc;

var html =  Documents.OpenHtmlFrame("C:\\Users\\mike\\Desktop\\test.html");

Wait(100);

html.object.document.parentWindow.init(active);   
