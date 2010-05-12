/////////////////////////////////////////////////////////////////
// XPATH
/////////////////////////////////////////////////////////////////

mol.NAMESPACE("mol.xpath");

/////////////////////////////////////////////////////////////////
// single node xpath
/////////////////////////////////////////////////////////////////

mol.xpath.getNode = function( xpath, node, ns )
{
   if ( mol.dom.isDocument(node) ) 
	  node = node.documentElement;

   var doc = node.ownerDocument;

   if ( !mol.js.isArray(ns) )
   {
	  var tmp  = new Array();
	  tmp[0] = ns;
      ns = tmp;
   }

   if ( typeof (doc.setProperty) != "undefined" )
   {
     var list = "";
     for ( i = 0; i < ns.length; i++ )
	 {
	   list += ns[i] + " ";
	   
	 }
     doc.setProperty("SelectionNamespaces", list );
     doc.setProperty("SelectionLanguage", "XPath");
     return node.selectSingleNode( xpath );
   }
   else
   {
      var prefix = "";
	  var uri    = "";
      var obj = new Object();
       
      if ( ns.length > 0 && ns[0] != null )
      {
		for ( i = 0; i < ns.length; i++ )
		{
		  var n = ns[i];

		  if ( n.match(/^xmlns:(.*)?='[^']*'/) )
		  {
			prefix = RegExp.$1;
		  }

		  if ( n.match(/^xmlns:.*?='([^']*)'/) )
		  {
			uri = RegExp.$1;
		  }
		  obj[prefix] = uri;
		}
	  }
	  var xpathResult = doc.evaluate( xpath, 
									  node, 
                                      function( p ) 
									  { 
										return obj[p]; 
                                      }, 
									  XPathResult.FIRST_ORDERED_NODE_TYPE , 
									  null );
	  return xpathResult.singleNodeValue;
   }
}

/////////////////////////////////////////////////////////////////
// nodelist xpath. returns js array of DOM objs
/////////////////////////////////////////////////////////////////

mol.xpath.getNodes = function ( xpath, node, ns )
{
   if (  mol.dom.isDocument(node) ) 
	  node = node.documentElement;

   var doc = node.ownerDocument;

   if ( !mol.js.isArray(ns) )
   {
	  var tmp  = new Array();
	  tmp[0] = ns;
      ns = tmp;
   }

   var ret = new Array();

   if ( typeof doc.setProperty != "undefined" )
   {
     var list = "";
     for ( i = 0; i < ns.length; i++ )
	 {
	   list += ns[i] + " ";
	   
	 }
	 doc.setProperty("SelectionNamespaces", list );
     doc.setProperty("SelectionLanguage", "XPath");
     var nodes = node.selectNodes( xpath ); 
     for ( var i = 0; i < nodes.length; i++ )
     {
		  ret[ret.length] = nodes.item(i);
     }
   }
   else
   {
      var prefix = "";
	  var uri    = "";
	  var obj = new Object();

      if ( ns.length > 0 && ns[0] != null )
      {
        
		for ( i = 0; i < ns.length; i++ )
		{
		  var n = ns[i];

		  if ( n.match(/^xmlns:(.*)?='[^']*'/) )
		  {
			prefix = RegExp.$1;
		  }

		  if ( n.match(/^xmlns:.*?='([^']*)'/) )
		  {
			uri = RegExp.$1;
		  }
		  obj[prefix] = uri;
		}
	  }
	  var it = doc.evaluate( xpath, 
							 node, 
							 function( p ) 
							 { 
								return obj[p]; 
							 }, 
							 XPathResult.ORDERED_NODE_ITERATOR_TYPE, 
							 null );

	  var n = it.iterateNext();
      while (n) {
        ret[ret.length] = n;
		n = it.iterateNext();
      }
   }
   return ret;
}