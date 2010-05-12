/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
// Http request lib
/////////////////////////////////////////////////////////////////

mol.NAMESPACE("mol.http");

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
// Http Headers
/////////////////////////////////////////////////////////////////
mol.http.Header = mol.CLASS (

{
  CONSTRUCTOR : function( key, val )
  {
    this.key = key;
    this.val = val;
    return this;
  }
}

);

/////////////////////////////////////////////////////////////////
// create XmlHttpRequest Obj
/////////////////////////////////////////////////////////////////

mol.http.CreateXmlHttp = function ()
{
  if ( window.ActiveXObject )
  {
	return new ActiveXObject("MSXML2.XMLHTTP.3.0");
  }
  else
  {
	return new XMLHttpRequest();
  }
}

/////////////////////////////////////////////////////////////////
// a general HttpRequest Obj
/////////////////////////////////////////////////////////////////

mol.http.Request = mol.CLASS (

{
  CONSTRUCTOR : function( method, url, mime, contentType, postData, useCache )
  {
    this.xmlHttp = mol.http.CreateXmlHttp();
	this.extraHeaders = new Array();

	if ( method )
      this.method = method;
    if ( url )
      this.url = url;
    if ( mime )
      this.mimeType = mime;
	if ( contentType )
	  this.contentType = contentType;
    if ( postData )
	  this.postData = postData;
	if ( useCache )
		this.useCache = useCache;

	return this;
  },

  /////////////////////////////////////////////////////////////////

  xmlHttp  		: null,
  method   		: "GET",
  url      		: "",
  async    		: true,
  contentType 	: "text/xml",
  mimeType  	: "text/xml",
  useCache 		: false,
  postData      : "",
  callBack 		: null,
  extraHeaders  : null,

  /////////////////////////////////////////////////////////////////
  // send the request
  /////////////////////////////////////////////////////////////////

  send     : function ( cb )
  {
    if ( cb )
		this.callBack = cb;

	if ( !this.callBack )
		this.async = false;

	this.xmlHttp.open( this.method, this.url, this.async );

	if ( this.async )
    {
	  var This = this;
      this.xmlHttp.onreadystatechange = function() { This.onResult(); };
    }
	if ( (this.method == "GET") && (!this.useCache) )
		this.xmlHttp.setRequestHeader("If-Modified-Since", "Sat, 1 Jan 2000 00:00:00 GMT"); 
    if ( this.postData )
		this.xmlHttp.setRequestHeader("Content-Type", this.contentType ); 

    for ( i = 0; i < this.extraHeaders.length; i++ )
	{
		this.xmlHttp.setRequestHeader( this.extraHeaders[i].key, this.extraHeaders[i].val ); 
	}

	if ( !window.ActiveXObject )
    {
	  this.xmlHttp.overrideMimeType(this.mime);
    }
    //alert(this.postData);

	return this.xmlHttp.send( this.postData );
  },

  /////////////////////////////////////////////////////////////////
  // result handler, dispatches to user supplied callback
  /////////////////////////////////////////////////////////////////

  onResult : function () 
  {

    if ( this.xmlHttp.readyState != 4 )
	  return;
    if ( this.callBack )
	  this.callBack(this);
  },

  /////////////////////////////////////////////////////////////////
  // get response string
  /////////////////////////////////////////////////////////////////

  status : function ()
  {
     return this.xmlHttp.status;
  },

  response : function ()
  {
    return this.xmlHttp.responseText;
  },

  /////////////////////////////////////////////////////////////////
  // get response XML DOM
  /////////////////////////////////////////////////////////////////

  responseXML : function ()
  {
	if ( this.xmlHttp.responseXML && this.xmlHttp.responseXML.documentElement )
		return this.xmlHttp.responseXML;
    if ( this.xmlHttp.responseText && this.xmlHttp.responseText != "" )
		return mol.xml.parse(this.xmlHttp.responseText);
	return null;
  } ,

  addHeader : function ( key, val )
  {
	this.extraHeaders[this.extraHeaders.length] = new mol.http.Header( key, val );
  }
}

);

/////////////////////////////////////////////////////////////////
// HTTP Gets
/////////////////////////////////////////////////////////////////

mol.http.Get = mol.CLASS (

{
  SUPER       : "mol.http.Request",
  CONSTRUCTOR : function( url, mime, contentType, postdata, useCache )
  {
	this.Request( "GET", url, mime, contentType, postdata, useCache);
    return this;
  }

}

);

/////////////////////////////////////////////////////////////////
// HTTP Posts
/////////////////////////////////////////////////////////////////

mol.http.Post = mol.CLASS (

{
  SUPER       : "mol.http.Request",
  CONSTRUCTOR : function( url, mime, contentType, postdata, useCache )
  {
    this.Request( "POST", url, mime, contentType, postdata, useCache);
    return this;
  },

  /////////////////////////////////////////////////////////////////
  // add a Post Param. sets content type to form-urlencoded
  // and encodes data value
  /////////////////////////////////////////////////////////////////

  addPostParam : function( key, val )
  {
    this.contentType = "application/x-www-form-urlencoded";
    if ( this.postData )
	  this.postData += "&";
    this.postData += key;
    this.postData += "=";
    this.postData += encodeURIComponent( val );
  }
}

);

/////////////////////////////////////////////////////////////////
// HTTP client site proxy
//
// expects url location of server side POST proxy
// with the endpoint url to be proxied to specified
// as (urlencoded) Query String parameter
/////////////////////////////////////////////////////////////////

mol.http.Proxy = mol.CLASS (

{
   SUPER       : "mol.http.Request",
   CONSTRUCTOR : function( url, endpoint )
   {
    this.proxy    = url;
    this.endpoint = endpoint;
    return this;
   },

   proxy    : "",
   endpoint : "",

   url : function (u) 
   {
      if ( u != null )
			this.endpoint = u;
	  return this.proxy + encodeURIComponent(this.endpoint);
   }
}
);