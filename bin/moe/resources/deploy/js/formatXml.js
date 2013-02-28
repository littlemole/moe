if ( ActiveDoc && ActiveDoc.Object )
{
  var text = ActiveDoc.Object.Text; // Documents(2).Object.Text;//
  var xml = text.Value;

  var doc = new ActiveXObject("Msxml2.DOMDocument");  
  doc.async = false;
  doc.loadXML(xml);
  if (doc.parseError.errorCode != 0) 
  {
	var err = doc.parseError.line + "\r\n";
	err += doc.parseError.reason + "\r\n";
	err += doc.parseError.srcText + "\r\n";

	Dialogs.MsgBox(
		"error line " + err, 
		"XML parsing error",
		Dialogs.ICONERROR
	);
  }
  else
  {

	  var saxReader = new ActiveXObject("Msxml2.SAXXMLReader.6.0") ;
	  var xmlWriter = new ActiveXObject("Msxml2.MXXMLWriter.6.0") ;

	  xmlWriter.indent = true;
	  xmlWriter.standalone = true;
	  xmlWriter.omitXMLDeclaration = false;
	  xmlWriter.encoding = "utf-8";
	  var newDoc = new ActiveXObject("Msxml2.DOMDocument");  
	  xmlWriter.output = newDoc;
	  saxReader.contentHandler = xmlWriter;
	  saxReader.dtdHandler = xmlWriter;
	  saxReader.errorHandler = xmlWriter;

	  saxReader.putProperty("http://xml.org/sax/properties/declaration-handler", xmlWriter);
	  saxReader.putProperty("http://xml.org/sax/properties/lexical-handler", xmlWriter);
	  saxReader.parse(doc);

	  xmlWriter.flush();
	  saxReader = null;
	  xmlWrite = null;

	  text.Value = newDoc.xml;
  }
}

