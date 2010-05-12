/////////////////////////////////////////////////////////////////
// XSLT
/////////////////////////////////////////////////////////////////

mol.NAMESPACE("mol.xslt");

mol.xslt.Processor = mol.CLASS (

{
   CONSTRUCTOR : function( xsl )
   {
	  if (xsl)
		this.stylesheet = xsl;

	  if ( window.ActiveXObject )
	  {
		this.activeX   = new ActiveXObject("Msxml2.XSLTemplate.3.0");
		if ( xsl )
		{
			this.activeX.stylesheet = this.stylesheet;
			this.processor = this.activeX.createProcessor();		
		}
	  }
	  else
	  {
		this.processor = new XSLTProcessor();	
	  }

	  return this;
    },
  
  activeX    : null,
  processor  : null,
  stylesheet : null,
  params     : new Array(),

  addParam   : function ( k, v, ns )
  {
	this.params[this.params.length] = { key : k, val : v, namespace : ns };	
  },

  clearParams : function() 
  { 
    this.params = new Array(); 
  },

  transform  : function ( xml, xsl ) 
  {
	if ( xsl )
		this.stylesheet = xsl;

	if ( window.ActiveXObject )
	{
  	  if ( xsl )
	  {
		this.activeX.stylesheet = this.stylesheet;
		this.processor = this.activeX.createProcessor();		
	  }
	  //this.activeX.stylesheet = this.stylesheet;
	  this.processor.reset();
	  this.processor.input = xml;
	  //alert(this.params.length);
	  for ( var i = 0; i < this.params.length; i++ )
	  {
        var param = this.params[i];
        //alert(param.key + "=!=" + param.val);
		this.processor.addParameter( param.key, param.val );//, param.namespace );
      }
	  this.params = new Array();
      this.processor.transform();
	  
	  return this.processor.output;
	}
	else
	{
	  this.processor.reset();
	  this.processor.importStylesheet(this.stylesheet);

	  for ( var i = 0; i < this.params[i]; i++ )
	  {
        var param = this.params[i];
		this.processor.setParameter( param.namespace, param.key, param.val );
      }
	  this.params = new Array();
	  var doc = this.processor.transformToDocument(xml);
	  return serializeDOM(doc);
	}
  }
}

);
