
if ( ActiveDoc && ActiveDoc.Object )
{
  var xml = ActiveDoc.Object.Text;
  var anno = ActiveDoc.Object.Annotation;
  var doc = new ActiveXObject("Msxml2.DOMDocument.3.0");  
  doc.async = false;
  doc.loadXML(xml);

  if (doc.parseError.errorCode != 0) 
  {
	var err = doc.parseError.line + "\r\n";
	err += doc.parseError.reason + "\r\n";
	err += doc.parseError.srcText + "\r\n";

	anno.ClearAll();
	var line = doc.parseError.line;
	if ( line > 0 ) line--;
	anno.SetText(line,doc.parseError.reason);
	ActiveDoc.Object.Line.Goto(line);
/*
	Dialogs.MsgBox(
		"error line " + err, 
		"XML parsing error",
		Dialogs.ICONERROR
	);
*/
  }
  else
  {
	
	Dialogs.MsgBox(
		"this xml document is well-formed",
		"msxml says:",
		Dialogs.ICONINFORMATION
	);
  }
  
}

