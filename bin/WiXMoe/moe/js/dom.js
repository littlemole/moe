
////////////////////////////////////////////////////////////////////
// general helpers
////////////////////////////////////////////////////////////////////

mol.NAMESPACE("mol.dom");

mol.dom.Event = mol.CLASS(
{
  CONSTRUCTOR : function ( e )
  {
	if ( window.event )
	{
	  this.event = window.event;
	  this.offsetX = this.event.offsetX;
	  this.offsetY = this.event.offsetY;
	  this.keyCode = this.event.keyCode;
	}
	else
	{
	  this.event = e;
	  var p = mol.dom.getElementPosition(e.target);
	  this.offsetX = this.event.pageX - p.left;
	  this.offsetY = this.event.pageY - p.top;
  
	  this.keyCode = this.event.which;
	}
	return this;
  },

  event   : null,	// native browser event obj
  offsetX : 0,		// mouse x pos relative to target obj
  offsetY : 0,		// mouse y pos relative to target obj
  keyCode : 0		// keyboard Code for event
}

);

mol.$ = function( id )
{
  return document.getElementById(id);
}

mol.$F = function( name )
{
  return document.forms[name];
}

mol.$FE = function( name )
{
	for ( var i = 0; i < document.forms.length; i++ )
	{
		for ( var j = 0; j < document.forms[i].length; j++ )
		{
			if ( document.forms[i][j].name == name )
				return document.forms[i][j];
		}
	}
	return null;
}

mol.dom.formname = function ( element )
{
	if ( element.form )
		return element.form.name;
	return element.getAttribute("name");
}

mol.dom.isForm = function( element )
{
	if ( element.name && document.forms[element.name] )
		return true;
	return false;
}

mol.dom.isFormElement = function( element )
{
	var n = element.name;
	if (!n)
	{
	  if ( !(element.length && element[0].name) )
		return false;
	  n = element[0].name;
	}

	for ( var i = 0; i < document.forms.length; i++ )
	{
		if ( document.forms[i][n] )
			return true;
	}
	return false;
}

mol.dom.id = function( element )
{
  return element.getAttribute("id");
}


mol.dom.isIE6CSS = function() 
{
	return ( document.compatMode && document.compatMode.indexOf("CSS1") >= 0) ? true : false;
}
 
////////////////////////////////////////////////////////////////////
// get element position
////////////////////////////////////////////////////////////////////

mol.dom.getWindowHeight = function()
{
  if ( window.innerHeight )
     return window.innerHeight;
  else if ( mol.dom.isIE6CSS())
  {
     return document.body.parentElement.clientHeight;
  }
  else if ( document.body && document.body.clientHeight) {
     return document.body.clientHeight;
  }
  return 0;
}

mol.dom.getWindowWidth = function()
{
  if ( window.innerWidth )
     return window.innerWidth;
  else if ( mol.dom.isIE6CSS())
  {
     return document.body.parentElement.clientWidth;
  }
  else if ( document.body && document.body.clientWidth) {
     return document.body.clientWidth;
  }
  return 0;
}

mol.dom.getElementPosition = function(elem){ 

 var offsetTrail = elem;
 var offsetLeft  = 0; 
 var offsetTop   = 0; 

 while (offsetTrail)
 {
   offsetLeft += offsetTrail.offsetLeft; 
   offsetTop += offsetTrail.offsetTop; 
   offsetTrail = offsetTrail.offsetParent; 
 } 

 if ( navigator.userAgent.indexOf('Mac') != -1 
      && typeof document.body.leftMargin != 'undefined')
 { 
   offsetLeft += document.body.leftMargin; 
   offsetTop += document.body.topMargin; 
 } 

 return {left:offsetLeft,top:offsetTop}; 
} 


mol.dom.isDocument = function( obj )
{
	if ( mol.js.isDefined(obj) && 
         mol.js.isDefined(obj.nodeType) 
         && obj.nodeType == 9 )
	    return true;

	return false;
}

mol.dom.isElement = function( obj )
{
	if ( mol.js.isDefined(obj) && 
         mol.js.isDefined(obj.nodeType) 
         && obj.nodeType == 1 )
	    return true;

	return false;
}

mol.dom.isText = function( obj )
{
	if ( mol.js.isDefined(obj) && 
         mol.js.isDefined(obj.nodeType) 
         && obj.nodeType == 3 )
	    return true;

	return false;
}

/////////////////////////////////////////////////////////////////
// Element Node Info helpers
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
// start tag for a node
/////////////////////////////////////////////////////////////////

mol.dom.getStartTag = function( node )
{
  var tag = "";

  if ( node.nodeValue )
    return tag;

  tag = "<" + tag.nodeName;
  if ( tag.attributes )
  for ( var i = 0; i < tag.attributes.length; i++ )
  {
    tag += " " + tag.attributes[i].nodeName;
    tag += "=\"" + tag.attributes[i].nodeValue; + "\"";
  }
  tag += ">";
  return tag;
}

/////////////////////////////////////////////////////////////////
// end tag for a node
/////////////////////////////////////////////////////////////////

mol.dom.getEndTag = function(node)
{
  var tag = "";

  if ( node.nodeValue )
    return tag;

  tag = "</" + tag.nodeName + ">";
  return tag;
}

/////////////////////////////////////////////////////////////////
// Element Child Helpers ( note: only children of type Element! )
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
// Child *Elements* count
/////////////////////////////////////////////////////////////////

mol.dom.countElements = function( node )
{
	var c = 0;

	if (!node.hasChildNodes())
		return c;

	for ( var i = 0; i < node.childNodes.length; i++ )
    {
		if ( mol.dom.isElement( node.childNodes[i] ) ) 
			c++;
    }
    return c;
}

/////////////////////////////////////////////////////////////////
// Child *Elements* returned as js Array
/////////////////////////////////////////////////////////////////

mol.dom.childElements = function( node )
{
	var c = new Array();

	if (!node.hasChildNodes())
		return c;

	for ( var i = 0; i < node.childNodes.length; i++ )
    {
		if ( mol.dom.isElement( node.childNodes[i] ) )
			c[c.length] = node.childNodes[i];
    }
    return c;
}

/////////////////////////////////////////////////////////////////
// first Child *Element* node, if any
/////////////////////////////////////////////////////////////////

mol.dom.firstChildElement = function( node )
{
	if ( node.nodeType != 1 )
		return null;

	if (!node.hasChildNodes())
		return null;

	for ( var i = 0; i < node.childNodes.length; i++ )
    {
		if ( mol.dom.isElement(node.childNodes[i]) ) 
			return node.childNodes[i];
    }
    return null;
}

/////////////////////////////////////////////////////////////////
// next *Elements* Sibling Node, if any
/////////////////////////////////////////////////////////////////

mol.dom.nextElement = function( node )
{
   if ( !mol.dom.isElement(node) ) 
   {
     return null;
   }

   var n = node.nextSibling;

   if ( n == null )
	  return null;

   while ( !mol.dom.isElement(n) ) 
   {
      n = n.nextSibling;
	  if ( n == null )
	  {
	    return null;
	  }
   } 
   return n;
}

/////////////////////////////////////////////////////////////////
// getElementById for a element node
/////////////////////////////////////////////////////////////////

mol.dom.getElementById  = function( node, id )
{
  if ( mol.dom.isDocument(node) ) 
	node = node.documentElement;

  if ( !mol.dom.isElement(node) ) 
    return null;

  var href = node.getAttribute("id");
  if ( href ) 
  {
    if ( href == id )
		return node;
  }
  if ( node.hasChildNodes() )
  {
    for ( var i = 0; i < node.childNodes.length; i++ )
    {
       var n = mol.dom.getElementById( node.childNodes[i], id );
       if ( n )
	     return n;
    }
  }
  return null;
}

/////////////////////////////////////////////////////////////////
// namespace helpers
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
// localname (basename) for an element node
/////////////////////////////////////////////////////////////////

mol.dom.localName = function( node )
{
	if ( !node || node.nodeType != 1 )
		return "";

	if ( mol.js.isDefined(node.baseName) ) 
    {
		return node.baseName;
    }
	if ( node.localName == null )
		return node.nodeName;
	return node.localName;		
}

/////////////////////////////////////////////////////////////////
// split a qualified name 
/////////////////////////////////////////////////////////////////

mol.dom.QName = function( name )
{
	var o = new Object;
	o.prefix = "";
    o.name   = "";

	if ( !name || name == "" )
	    return o;

	if ( name.match(/([^:]*):([^:]*)/) )
	{
	    o.prefix = RegExp.$1;
        o.name   = RegExp.$2;
		return o;
	}
	o.name = name;
	return o;		
}

/////////////////////////////////////////////////////////////////
// string serialization (XML/HTML)
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
// DOM to string
/////////////////////////////////////////////////////////////////

mol.dom.serialize = function( node )
{
  if ( window.ActiveXObject )
  {
	if ( mol.js.isDefined( node.innerHTML ) ) 
    {
		return node.innerHTML;
    }
	else
	{
		return node.xml;
	}	
  }
  else
  {
	if ( mol.dom.isDocument(node) ) //node.nodeType == 9 )
		node = node.documentElement;

	if ( mol.js.isDefined(node.innerHTML) ) 
    {
		return mol.dom.getStartTag(node) + node.innerHTML + mol.dom.getEndTag(node);
    }
	else
	{
		var s = new XMLSerializer();
		return s.serializeToString(node);
	}
  }
}


