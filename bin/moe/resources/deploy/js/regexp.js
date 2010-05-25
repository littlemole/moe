function onRegExp()
{
  var pattern       = document.getElementById("regExp").value;
  var showGroups    = document.getElementById("showGroups").checked;
  var caseSensitive = document.getElementById("caseSensitive").checked;
  var results 		= document.getElementById("results");
  
  if ( !pattern || pattern == "" )
    return false;

  var name = external.Moe.ActiveDoc.PathName;
  var sci = external.Moe.ActiveDoc.Object;
  if ( sci )
  {
    var txt = sci.GetText();
	var pos = 0;
	var p   = 0;

	var flags = "";

	if (!caseSensitive)
		flags += "i";

	var r;
	
	r = eval( "new RegExp('" + pattern + "', '" + flags + "' );" );

	if ( !r )
        return false;
	var out = "<small><b>filename: " + sci.Filename + "</b></small>";
	
	while ( -1 != ( p = txt.substring(pos).search(r) ) )
	{
	  var line   = sci.LineFromPos(pos+p);
	  var linend = sci.LineEndPos(line);
	  var start  = pos+p;
      var m 	 = RegExp.lastMatch;
	  var end    = start + m.length;


	  out += "<div class='moe'><a class='moe' href='#result' ";
	  out += "onClick='JumpTo(";
	  out += start + ", " + end;
	  out += ");'><b>";
	  out += " line: " + line;
	  out += "</b></a><small class='moe'>";
	  
	  var l = htmlEncode(sci.LineText(line));
	  var rp = new RegExp( pattern, flags + "g"  );
	  l = l.replace( 
			   rp, 
			   "<i class='match'>"
   			   + m
			   + "</i>" );
	  out += l;
	  out += "</small></div><br><br>\r\n";

	  if ( showGroups )
	  for ( x = 1; x < 10; x++ )
	  {
		if ( RegExp["$"+x] != null && RegExp["$"+x] != "" )
		{
			out += x + ": " + RegExp["$"+x] + "<br><br>\r\n";
		}
	  }
	  pos = end+1;
	}
//alert(out);
	results.innerHTML = out;
  }
  return false;
}


function JumpTo(  start, end )
{
	var d = external.Moe.ActiveDoc;
	if ( d )
	{
		if ( d.Type == 1 )
		{
			d.View.Activate();
			var sci = d.Object;
			sci.SetSelection( start, end );
			sci.ScrollIntoView();
		}
	}
}

function init()
{
	setupPanes("container", "tab1");
	draggable("tabs");
}

window.onload = init;