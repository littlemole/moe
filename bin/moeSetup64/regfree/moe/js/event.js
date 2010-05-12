////////////////////////////////////////////////////////////////////
// Event helper
////////////////////////////////////////////////////////////////////

mol.NAMESPACE("mol.dom");

mol.dom.Event = mol.CLASS (

{
  CONSTRUCTOR : function( e )
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
