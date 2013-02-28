//var shell = new ActiveXObject("WScript.Shell");
var xmlHttp = new ActiveXObject("MSXML2.XMLHTTP.3.0");

var doc = moe.ActiveDoc;
if ( doc && doc.Object )
{
//  shell.Popup("file://" + moe.Config.modulePath + "\\forms\\w3c.html#" + encodeURI(doc.Object.Properties.Filename));
  var d = moe.Documents.OpenHtmlFrame( "file://" + moe.Config.modulePath +"\\forms\\w3c.html#" + encodeURI(doc.Object.Properties.Filename) );
}

