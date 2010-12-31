
function onSearch()
{
  var what    = document.getElementById("what").value;
  var word    = document.getElementById("word").checked;
  var useCase = document.getElementById("case").checked;
  var results = document.getElementById("results");
  
  if ( !what || what == "" )
    return false;

  var name = external.Moe.ActiveDoc.FilePath;
  var sci = external.Moe.ActiveDoc.Object;
  if ( sci )
  {
    var txt = sci.Text;
	var pos = 0;
	var p   = 0;
	var s   = what;

	var flags = "g";

	if ( useCase )
		flags += "i";

	if ( word )
		s = "\\b" + what + "\\b";

	var s = new RegExp ( s, flags  );

	var out = "<small><b>filename: " + sci.Properties.Filename + "</b></small>";
	
	while ( -1 != ( p = txt.substring(pos).search(s) ) )
	{
	  var line   = sci.Line.LineFromPos(pos+p);
	  var linend = sci.Line.LineEndPos(line);
	  var start  = pos+p;
	  var end    = pos+p+what.length;
      var m = txt.substring(start,end);

	  out += "<div class='moe'><a class='moe' href='#result' ";
	  out += "onClick='JumpTo(";
	  out += start + ", " + end;
	  out += ");'><b>";
	  out += " line: " + line;
	  out += "</b></a><small class='moe'>";
	  
	  var l = htmlEncode(sci.Line.LineText(line));
	  var r = new RegExp( what, flags + "g" );
	  l = l.replace( s, "<i class='match'>" + what + "</i>" );
	  out += l;
	  out += "</small></div><br><br>\r\n";

	  pos = end+1;
	}
//alert(out);
	results.innerHTML = out;
  }
  return false;
}


function onSearchAll()
{
  var what    = document.getElementById("whatAll").value;
  var word    = document.getElementById("wordAll").checked;
  var useCase = document.getElementById("caseAll").checked;
  var results = document.getElementById("resultsAll");

  if ( !what || what == "" )
    return false;

  var out = "";

  for ( i = 0; i < external.Moe.Documents.Count; i++ )
  {
    var doc = external.Moe.Documents(i);
    if ( doc.type == 1 )
	{
	  var sci = doc.Object;
	  var txt = sci.Text;
	  var pos = 0;
	  var p   = 0;
	  var s   = what;

	  var flags = "g";

	  if ( useCase )
		flags += "i";

	  if ( word )
	    s = "\\b" + what + "\\b";

	  var s = new RegExp ( s, flags  );

	  out += "<small><b>filename: " + sci.Properties.Filename + "</b></small>";
	
	  while ( -1 != ( p = txt.substring(pos).search(s) ) )
	  {
		var line   = sci.Line.LineFromPos(pos+p);
		var linend = sci.Line.LineEndPos(line);
		var start  = pos+p;
		var end    = pos+p+what.length;
		var m = txt.substring(start,end);
		
		out += "<div class='moe'><a class='moe' href='#result' ";
		out += "onClick='GoTo( " + i + ", " + start;
		out += ", " + end + ")' ><b>";
		out += " line: " + line;
		out += "</b></a><small class='moe'>";
		
		var l = htmlEncode(sci.Line.LineText(line));
		var r = new RegExp( what, flags + "g" );
		l = l.replace( s, "<i class='match'>" + what + "</i>" );
		out += l;
		out += "</small></div><br><br>\r\n";
		
  	    pos = end+1;
			
	  } // end while search
	} // endif docType == 1
  } // end for docs

  //alert(out);
  results.innerHTML = out;
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
			sci.Selection.SetSelection( start, end );
			sci.Position.ScrollIntoView();
		}
	}
}

function GoTo( index, start, end )
{
	var d = external.Moe.Documents(index);
	if ( d )
	{
		if ( d.Type == 1 )
		{
			d.View.Activate();
			var sci = d.Object;
			sci.Selection.SetSelection( start, end );
			sci.Position.ScrollIntoView();
		}
	}
}

function init()
{
	setupPanes("container", "tab1");
	draggable("tabs");
}

window.onload = init;