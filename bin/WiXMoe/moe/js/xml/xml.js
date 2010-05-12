/////////////////////////////////////////////////////////////////
// XML helper lib
/////////////////////////////////////////////////////////////////

mol.NAMESPACE("mol.xml");

/////////////////////////////////////////////////////////////////
// XML error object
/////////////////////////////////////////////////////////////////
mol.xml.Error = mol.CLASS (

{
   CONSTRUCTOR : function( xmlDoc )
   {
	if ( !xmlDoc )
			return this;
		
	if ( xmlDoc.parseError )
	{
		if ( xmlDoc.parseError.errorCode == 0 )
	    return this;

		this.errorCode = xmlDoc.parseError.errorCode;
		this.filePos   = xmlDoc.parseError.filePos;
		this.line 	   = xmlDoc.parseError.line;
		this.linePos   = xmlDoc.parseError.linePos;
		this.reason    = xmlDoc.parseError.reason;
		this.srcText   = xmlDoc.parseError.srcText;
		this.url 	   = xmlDoc.parseError.url;

		return this;
	}

	if ( xmlDoc == null || xmlDoc.firstChild == null )
	{
		this.errorCode = 1;
		this.reason    = "error loading XML";
		return this;
	}

	if ( xmlDoc.firstChild.tagName != "parsererror" )
	{
	   return this;
	}

    var xml = serializeDOM(xmlDoc);
	if ( xml.match(/>([\s\S]*?)Location:([\s\S]*?)Line Number (\d+), Column (\d+):<sourcetext>([\s\S]*?)(?:\-*\^)/ ) )
	{
		this.errorCode = 1;
		this.filePos   = 0;
		this.line 	   = RegExp.$3;
		this.linePos   = RegExp.$4;
		this.reason    = RegExp.$1;
		this.srcText   = RegExp.$5;
		this.url 	   = RegExp.$2;
	}
	
	return this;
 },

 errorCode : 0,
 filePos : 0,
 line : 0,
 linePos : 0,
 reason : 0,
 srcText : "",
 url : ""
}

);

/////////////////////////////////////////////////////////////////
// XML doc creation
/////////////////////////////////////////////////////////////////

mol.xml.CreateDoc = function( singleThreaded )
{
  if ( window.ActiveXObject )
  {
	if ( singleThreaded )
		return new ActiveXObject("Msxml2.DOMDocument.3.0");
	return new ActiveXObject("Msxml2.FreeThreadedDOMDocument.3.0");
  }
  else
  {
	return document.implementation.createDocument("","",null);
  }
}

/////////////////////////////////////////////////////////////////
// load XML document from URI, sync or async
/////////////////////////////////////////////////////////////////

mol.xml.load = function(xml,cb)
{
  var doc = mol.xml.CreateDoc();
  doc.async = false;

  if ( cb != null )
  {
	 doc.async = true;

     if ( isDefined (doc.onreadystatechange) ) 
	 {
		  doc.onreadystatechange = function() 
		  {
			  if ( doc.readyState == 4 )
			  {	
				cb(doc);
			  }
		  }
     }
	 else
	 {
		  doc.onload = function() 
		  {
			  cb(doc);
		  }
	 }
  }

  doc.load(xml);
  return doc;
}

/////////////////////////////////////////////////////////////////
// parse string to XML document
/////////////////////////////////////////////////////////////////

mol.xml.parse = function(xml)
{
  if ( window.ActiveXObject )
  {
	var doc = mol.xml.CreateDoc(true);
	doc.async = false;

	doc.loadXML(xml);
  
	if (doc.parseError.errorCode != 0) 
	{
	  var myErr = doc.parseError;
	  alert("error: " + myErr.reason);
	}
	return doc;
  }
  else
  {
    var parser = new DOMParser()
    return parser.parseFromString(xml, "text/xml");
  }
}

