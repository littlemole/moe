////////////////////////////////////////////////////
// generic js class - little.mol 2006/2007
//
// usage:
//
// var MyBaseClass = CLASS(
//  {
//    CONSTRUCTOR : function(v) { if ( v ) this.val = v; return this; },
// 
//    val         : "a def value",
//    doIt        : function(v) {  return v + " " + this.val; } 
//  }
// );
//
// var MyDerivedClass = CLASS(
//  {
//    SUPER       : 'MyBaseClass',
//    CONSTRUCTOR : function(v) { return this.MyBaseClass(v); },
// 
//    doIt        : function(v) { return "overridden: " + this.MyBaseClass_do(v); } 
//  }
// );
//
// var bc = new MyBaseClass("hello");
// var dc = new MyDerivedClass("world");
//
// alert( bc.doIt("test base") );
// alert( dc.doIt("test derived") );
//
////////////////////////////////////////////////////

if ( !window.mol ) window.mol = new Object();

mol.CLASS = function( definition )
{
  // default constructor if none given
  var base        = null;
  var base_name   = null;
  var constructor = null;

  // check for specified constructor
  if ( definition['CONSTRUCTOR'] != undefined )
  {
    constructor = definition['CONSTRUCTOR'];
  }
  else //default
  {
    constructor = new Function( "return this;" );
  }

  // check if BASE class specified
  if ( definition['SUPER'] != undefined )
  {
    // base_name might be namespace qualified
    base_name = definition['SUPER'];

    // eval base_name and get ref to constructor
	base      = eval(base_name);

	// inherit methods and members
	constructor.prototype = new base;

    // strip trailing namespace from base classname	
	var a = base_name.split('.');
    base_name = a[a.length-1];

	// save a ref to the base class constructor
    constructor.prototype[base_name] = base;  
  }

  // add members and methods to class
  for (var key in definition) 
  {    
    if ( (key != "CONSTRUCTOR") && (key != "SUPER") )
    {
      // add member to class prototype
      constructor.prototype[key] = definition[key];

	  // check if it's a method and if it exists in base class
      if ( ( base ) &&
           ( typeof( definition[key] ) == "function" ) &&
           ( base.prototype[key] != undefined ) )
      {
        // add a 'SUPER_'... method to call base method
        var SUPER = base_name + "_" + key;
        constructor.prototype[SUPER] = function() {

			  var base_call = "base.prototype['" + key + "'].call( this ";
			  for ( var i = 0; 
                    i < constructor.prototype[SUPER].arguments.length; 
                    i++ )
			  {
				base_call += ", constructor.prototype." + SUPER;
				base_call += ".arguments[" + i + "] ";
			  }
			  base_call += "); ";
	
			  return eval(base_call);
		  }
      } // end if base func
    } // end if member
  } // next for

  // return reference to Class Constructor
  // so we can use operator 'new'
  return constructor;
}

////////////////////////////////////////////////////
// define a namespace, if not yet defined
// expects ns as string
////////////////////////////////////////////////////

mol.NAMESPACE = function(n)
{
  var a  = n.split(".");
  var ns = "";

  for ( var i = 0; i < a.length; i++ )
  {
	eval( "if ( !window." + ns + a[i] + " ) { window." + ns + a[i] + " = new function() {}; }" );
    ns += a[i] + ".";
  }
}

////////////////////////////////////////////////////
// import namespace into window (=top level) obj
// expects ns as object ref
////////////////////////////////////////////////////

mol.USING_NAMESPACE = function(n)
{
  for ( var member in n )
  {
    window[member] = n[member];
  }
}