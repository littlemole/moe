////////////////////////////////////////////////////////////////////////
// XML transformations
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
// slurp a file
////////////////////////////////////////////////////////////////////////

var preamble = "// generated file - do not edit //\r\n\r\n";

function loadFile(file)
{
    var ret = "";
    try {
      var f = fso.OpenTextFile(file, 1);
      ret = f.ReadAll();
      f.Close();
    }
    catch(e)
    {
        WScript.StdOut.WriteLine( file + " " + e.message );
    }
    return ret;
}

////////////////////////////////////////////////////////////////////////
// save a file if modified
////////////////////////////////////////////////////////////////////////

function saveFile( output, file )
{
    // retrieve current file   
    try {
    
        var current = loadFile(file);
        if ( current == output )
        {
            //WScript.StdOut.WriteLine( output );
            WScript.StdOut.WriteLine( file + " not changed, skipping ...");    
            return;
        }
    }
    catch(e)
    {}

    // create text file for output
    var f = fso.CreateTextFile(file, true);

    // write transformation result to file
    f.Write(output);
    f.Close();
}

////////////////////////////////////////////////////////////////////////
// transform xml document via xslSrc, return result
////////////////////////////////////////////////////////////////////////

function transform( xslSrc, arg )
{
    // load the xsl stylesheet
    var xsl = new ActiveXObject("Msxml2.FreeThreadedDOMDocument.3.0");
    xsl.async = false;
    xsl.load(xslSrc);

    // create xsl template from xsl document
    var xslt = new ActiveXObject("Msxml2.XSLTemplate.3.0");
    xslt.stylesheet = xsl;

    // create processor and feed xml
    var processor = xslt.createProcessor();		
    processor.input = xml;
    
    if ( typeof(arg) != "undefined" ) 
    {
        processor.addParameter("OUTPUTPATH",arg);
    }

    // do the magic
    processor.transform();

    return processor.output;
}

////////////////////////////////////////////////////////////////////////
// transform xml document via xslSrc and save to file if modified
////////////////////////////////////////////////////////////////////////

function transmorph( xslSrc, file )
{
    var result = transform( xslSrc );
    saveFile( result, file );
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

function make_ribbon( file )
{
    WScript.StdOut.WriteLine("Ribbon support " + file);
    WScript.StdOut.WriteLine("--------------------------------------------------");
    
    var f = loadFile(file);
    if ( f.length == 0 )
    {
      WScript.StdOut.WriteLine("no ribbon xml found - skipping");
      return;
    }

//  var oExec = shell.Exec("C:\\Program Files\\Windows Kits\\8.0\\bin\\x86\\uicc.exe  " + file + " ribbon.bml /header:ribbonres.h.tmp /res:ribbonres.rc.tmp");
    var uicc = shell.ExpandEnvironmentStrings("%UICC%");
    WScript.StdOut.WriteLine(uicc);
    var oExec = shell.Exec( uicc +" " + file + " ribbon.bml /header:ribbonres.h.tmp /res:ribbonres.rc.tmp");
    
    

    while (oExec.Status == 0)
    {
         WScript.Sleep(100);
    }
    WScript.StdOut.WriteLine("uicc.exe returned " + oExec.ExitCode);
     
    WScript.StdOut.WriteLine("generating ribbonres.h");
    var resh = loadFile("ribbonres.h.tmp");
    saveFile( resh, "ribbonres.h" );
    fso.DeleteFile("ribbonres.h.tmp");
    
    WScript.StdOut.WriteLine("generating ribbonres.rc");
    var resrc = loadFile("ribbonres.rc.tmp");
    resrc = resrc.replace(/ribbonres\.h\.tmp/gi,"ribbonres\.h");
    saveFile( resrc, "ribbonres.rc" );
    fso.DeleteFile("ribbonres.rc.tmp");

}

// filter IDs already defined by windows.h

function filter_id( id )
{
    var ids = [ "IDOK", "IDCANCEL", "IDABORT", "IDRETRY", "IDIGNORE", "IDYES", "IDNO", "IDCLOSE", "IDHELP", "IDTRYAGAIN", "IDCONTINUE" ]; 
    
    for ( var i = 0; i < ids.length; i++ ) 
    {
      if ( ids[i] == id ) 
      {      
         return true;
      }
    }
    return false;
}    

////////////////////////////////////////////////////////////////////////
// main
////////////////////////////////////////////////////////////////////////

// filesystem access
var fso = new ActiveXObject("Scripting.FileSystemObject");

// shell support
var shell = new ActiveXObject("WScript.Shell");

// load the xml resource to transform
var xml = new ActiveXObject("Msxml2.DOMDocument.3.0");
xml.async = false;

var arg = WScript.Arguments.Item(0);

WScript.StdOut.WriteLine("running in " + arg + " mode");



////////////////////////////////////////////////////////////////////////
// STEP A)
////////////////////////////////////////////////////////////////////////

WScript.StdOut.WriteLine("--------------------------------------------------");
WScript.StdOut.WriteLine("starting XSLT code generation from resource.xml");
WScript.StdOut.WriteLine("--------------------------------------------------");

// xslt transform resource.xml to xmlid.h
// generates unique Windows IDs for identifiers in resource.xml
WScript.StdOut.WriteLine("");
WScript.StdOut.WriteLine("A) generating xmlrc.cpp");
WScript.StdOut.WriteLine("");

WScript.StdOut.WriteLine("   xml/include.xml -> xsl->include.xsl");
xml.load("xml/include.xml");
var result = transform( "../../cg/xsl/include.xsl" );


WScript.StdOut.WriteLine("   xml/cmd.xml -> xsl->uicmd.xsl");
xml.load("xml/cmd.xml");
result += transform( "../../cg/xsl/uicmd.xsl" );


WScript.StdOut.WriteLine("   xml/resource.xml -> xsl/uires.xsl");
xml.load("xml/resource.xml");
result += transform( "../../cg/xsl/uires.xsl" );


WScript.StdOut.WriteLine("   xml/menu.xml -> xsl/uimenu.xsl");
xml.load("xml/menu.xml");
result += transform( "../../cg/xsl/uimenu.xsl" );

WScript.StdOut.WriteLine("   xml/msg.xml -> xsl/msg.xsl");
xml.load("xml/msg.xml");
result += transform( "../../cg/xsl/msg.xsl" );


WScript.StdOut.WriteLine("   xml/persist.xml -> xsl/persist.xsl");
xml.load("xml/persist.xml");
result += transform("../../cg/xsl/persist.xsl");

saveFile( result, "src/xmlrc.cpp" );


////////////////////////////////////////////////////////////////////////
// STEP B)
////////////////////////////////////////////////////////////////////////

// xslt transform resource.xml to moe.rc
// generates moe.rc script from resource.xml
WScript.StdOut.WriteLine("");
WScript.StdOut.WriteLine("--------------------------------------------------");
WScript.StdOut.WriteLine("B) generating moe.rc (including mol.rc.inc)");
WScript.StdOut.WriteLine("");

xml.load("xml/resource.xml");
var result = transform( "../../cg/xsl/uirc.xsl", arg );

// create text file for output
var f = fso.OpenTextFile("resources/mol.rc.tmp", 8, true);

// write transformation result to file
f.Write(result);

var inc = fso.OpenTextFile("resources/mol.rc.inc");

f.Write(inc.ReadAll());

f.Close();
inc.Close();

f = loadFile("resources/mol.rc.tmp");
saveFile(f,"resources/mol.rc");

fso.DeleteFile("resources/mol.rc.tmp");

////////////////////////////////////////////////////////////////////////
// STEP C)
////////////////////////////////////////////////////////////////////////

// xslt transform resource.xml to xmlui.cpp
// generates main GUI setup boilderplate implementation
WScript.StdOut.WriteLine("");
WScript.StdOut.WriteLine("--------------------------------------------------");
WScript.StdOut.WriteLine("C) generating xmlui.cpp");
WScript.StdOut.WriteLine("");

WScript.StdOut.WriteLine("   xml/include.xml -> xsl->include.xsl");
xml.load("xml/include.xml");
var result = transform( "../../cg/xsl/include.xsl" );


WScript.StdOut.WriteLine("   xml/ui.xml -> xsl->uicmd.xsl");
xml.load("xml/ui.xml");
result += transform( "../../cg/xsl/uicpp.xsl" );


saveFile(result,"src/xmlui.cpp");


////////////////////////////////////////////////////////////////////////
// STEP D)
////////////////////////////////////////////////////////////////////////

// xslt transform resource.xml to xmlui.h
// generates main GUI setup boilderplate definition
WScript.StdOut.WriteLine("");
WScript.StdOut.WriteLine("--------------------------------------------------");
WScript.StdOut.WriteLine("D) generating xmlui.h");
WScript.StdOut.WriteLine("");

transmorph( "../../cg/xsl/uih.xsl", "include/xmlui.h" );

////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////
// STEP E)
////////////////////////////////////////////////////////////////////////

// xslt transform cmd.xml to xmlrib.h
// generates ribbon GUI setup boilderplate definition
WScript.StdOut.WriteLine("");
WScript.StdOut.WriteLine("--------------------------------------------------");
WScript.StdOut.WriteLine("E) generating xmlrib.h");
WScript.StdOut.WriteLine("");

xml.load("xml/cmd.xml");
transmorph( "../../cg/xsl/rib.xsl", "src/xmlrib.cpp" );

////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

var padding = "                                        ";

////////////////////////////////////////////////////////////////////////
// F) 
////////////////////////////////////////////////////////////////////////

WScript.StdOut.WriteLine("");
WScript.StdOut.WriteLine("--------------------------------------------------");
WScript.StdOut.WriteLine("E) starting resource.h generation via XPATH");
WScript.StdOut.WriteLine("");

var xml_files = [ 
					"xml/cmd.xml" , 
					"xml/resource.xml", 
					"xml/menu.xml", 
					"xml/ui.xml" 
				];

var ids = {};
var counter = 500;

for ( f = 0; f < xml_files.length; f++ )
{
	WScript.StdOut.WriteLine(xml_files[f] + "\r\n");
	xml.load(xml_files[f]);
	xml.setProperty("SelectionLanguage", "XPath");

	var result = xml.selectNodes("//*/@id");

	for ( r = 0; r < result.length; r++ )
	{
	    var value = result[r].nodeValue;

	    if (filter_id(value)) 
	    {
	        continue;
	    }

		if( typeof ids[value] !='undefined')
		{
			WScript.StdOut.WriteLine("ALERT: id " + value + " used more than once!");
		}	
		var fixed  = xml.selectSingleNode("//*[@id='"+value+"']/@value");
		if( fixed!=null && typeof fixed !='undefined')
		{
			ids[value] = fixed.nodeValue;		
            //WScript.StdOut.WriteLine("id:" + fixed.nodeValue );
		}
		else
        {
			ids[value] = counter++;		
           // WScript.StdOut.WriteLine("id:" + fixed.nodeValue );
        }
	}
    
} 

var output = "#ifndef MOL_MOE_XML_GENERATED_RESOURCE_ID_DEFINES_DEF_GUARD_DEFINE\r\n";
output += "#define MOL_MOE_XML_GENERATED_RESOURCE_ID_DEFINES_DEF_GUARD_DEFINE\r\n\r\n\r\n";

for ( i in ids )
{
	output += "#define " + i;
	if ( i.length < 40 )
		output += padding.substring(0,40-i.length);
	output += " " + ids[i] + "\r\n";
}

output += "\r\n\r\n#endif\r\n";


saveFile(output,"include/xmlid.h");

////////////////////////////////////////////////////////////////////////

WScript.StdOut.WriteLine("--------------------------------------------------");
WScript.StdOut.WriteLine("finished XSLT code generation ");
WScript.StdOut.WriteLine("");
WScript.StdOut.WriteLine("--------------------------------------------------");
WScript.StdOut.WriteLine("");



make_ribbon("xml/ribbon.xml");
WScript.StdOut.WriteLine("--------------------------------------------------");