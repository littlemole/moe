
var doc = moe.ActiveDoc;
if ( doc )
{
	var xml = new ActiveXObject("MSXML2.DOMDocument.4.0");
	var name = doc.FileName;

	xml.async = false;
	xml.validateOnParse = true;
	xml.resolveExternals = true;

	xml.load(name);

	if (xml.parseError.errorCode != 0)
	{
		moe.MsgBox( "Validation failed on " + name + 
		"\nReason: " + xml.parseError.reason + 
		"\nSource: " + xml.parseError.srcText + 
		"\nLine: " + xml.parseError.line + "\n",
		"XML Validation failed",16);
	}
	else
	{
		moe.SetStatus("XML Validation passed :)");
	}
}


//var shell = new ActiveXObject("WScript.Shell");
//shell.Popup("msxml says: this xml document is well-formed");

//var result = validateFile("C:\\Users\\mike\\Documents\\Visual Studio 2008\\Projects\\molib8\\bin\\moe\\resource.xml");

//var name = moe.ActiveDoc.Name;
//var sci = moe.ActiveDoc.Document;
//shell.Popup(moe.ActiveDoc == null);
//moe.SetStatus("hihoo");

/*
if ( sci )
{
	var txt = sci.GetText();

	// Create a schema cache and add books.xsd to it.
	//var xs = new ActiveXObject("MSXML2.XMLSchemaCache.4.0");
	//xs.add("urn:Moe.Xmoe", "C:\\Users\\mike\\Documents\\Visual Studio 2008\\Projects\\molib8\\bin\\moe\\resource.xsd");

	// Create an XML DOMDocument object.
	var xml = new ActiveXObject("MSXML2.DOMDocument.4.0");

	//x.schemas = xs;

	// Set first-level DOM properties.
	xml.async = false;
	xml.validateOnParse = true;
	xml.resolveExternals = true;

	// Configure DOM properties for namespace selection.
	//x.setProperty("SelectionLanguage", "XPath");
	//ns = "xmlns:mol='urn:Moe.Xmoe'";
	//x.setProperty("SelectionNamespaces", ns);

	// Load and validate the specified file into the DOM.
	//xml.parse(txt);

	// Return validation results in message to the user.
	if (xml.parseError.errorCode != 0)
	{
		moe.MsgBox( "Validation failed on " + name + 
		"\nReason: " + xml.parseError.reason + 
		"\nSource: " + xml.parseError.srcText + 
		"\nLine: " + xml.parseError.line + "\n",
		"XML Validation failed",16);
	}
	else
	{
		moe.SetStatus("XML Validation passed :)");
	}

}
*/



