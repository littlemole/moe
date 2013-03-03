
if ( ActiveDoc )
{
    var anno = ActiveDoc.Object.Annotation;
	var xml = new ActiveXObject("MSXML2.DOMDocument.6.0");
	var name = ActiveDoc.FilePath;

	xml.async = false;
	xml.validateOnParse = true;
	xml.resolveExternals = true;

	xml.load(name);

	if (xml.parseError.errorCode != 0)
	{
		anno.ClearAll();
		var line = xml.parseError.line;
		if ( line > 0 ) line--;
		anno.SetText(line,xml.parseError.reason);
		ActiveDoc.Object.Line.Goto(line);
/*		Dialogs.MsgBox( "Validation failed on " + name + 
		"\nReason: " + xml.parseError.reason + 
		"\nSource: " + xml.parseError.srcText + 
		"\nLine: " + xml.parseError.line + "\n",
		"XML Validation failed",Dialogs.ICONERROR);
*/
	}
	else
	{
		Dialogs.MsgBox("Schema validation passed!","XML Schema Validation",Dialogs.ICONINFORMATION);
	}
}
