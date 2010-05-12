// test resource.xml
//
// Step A) check well formedness of xml
// Step B) check all id attributes are unique
// Step C) check all cmd attributes map to a known id

var shell = new ActiveXObject("WScript.Shell");
var ids = new Object;

function alert(txt,title,flag)
{
	shell.popup(txt,0,title,flag);
}

function walk_for_ids(parent)
{
	var id = parent.getAttribute("id");
	if (id)
	{
		if ( ids[id] )
		{
			alert("invalid id",id,16);
			return false;
		}
		ids[id] = id;
	}
	for ( var i = 0; i < parent.childNodes.length; i++ )
	{
		if (!walk_for_ids(parent.childNodes(i)))
			return false;
	}
	return true;
}

function walk_for_cmds(parent)
{
	var cmd = parent.getAttribute("cmd");
	if ( cmd )
	{
		if ( !ids[cmd] )
		{
			alert("invalid cmd",cmd,16);
			return false;
		}
	}
	for ( var i = 0; i < parent.childNodes.length; i++ )
	{
		if (!walk_for_cmds(parent.childNodes(i)))
			return false;
	}
	return true;
}

function check()
{
	// load the xml resource to check
	var xml = new ActiveXObject("Msxml2.DOMDocument.3.0");
	xml.async = false;
	xml.setProperty("SelectionLanguage", "XPath");
	
	if (!xml.load("..\\xml\\resource.xml"))
	{
		var myErr = xml.parseError.reason;
		alert(myErr,"loading resource.xml failed",16);
		return;
	}

	alert("parse OK!","wellformedness check");
	var root = xml.documentElement;

	if ( !walk_for_ids(root) )
		return;

	alert("OK!","id check");

	if ( !walk_for_cmds(root))
		return;	

	alert("OK!","cmd check");
}

check();
