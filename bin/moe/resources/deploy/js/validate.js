var shell = new ActiveXObject("WScript.Shell");
var doc = moe.ActiveDoc;

if ( doc && doc.Object )
{
  var xml = doc.Object.getText();
  var doc = new ActiveXObject("Msxml2.DOMDocument.3.0");
  
  doc.async = false;

  doc.loadXML(xml);
  
  if (doc.parseError.errorCode != 0) 
  {
	var err = doc.parseError.line + "\r\n";
	err += doc.parseError.reason + "\r\n";
	err += doc.parseError.srcText + "\r\n";

	shell.Popup("error line " + err);
  }
  else
  {
	shell.Popup("msxml says: this xml document is well-formed");
  }
  
}

