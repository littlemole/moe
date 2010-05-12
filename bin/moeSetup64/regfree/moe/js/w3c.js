var shell = new ActiveXObject("WScript.Shell");
var xmlHttp = new ActiveXObject("MSXML2.XMLHTTP.3.0");

var doc = moe.ActiveDoc;
if ( doc && doc.Document )
{
  shell.Popup("file://" + moe.modulePath + "\\forms\\w3c.html#" + encodeURI(doc.Document.Filename));
  var d = moe.OpenHtmlFrame( "file://" + moe.modulePath + "\\forms\\w3c.html#" + encodeURI(doc.Document.Filename) );
}

