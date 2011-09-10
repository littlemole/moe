////////////////////////////////////////////////////////////////////////
// XML transformations
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
// slurp a file
////////////////////////////////////////////////////////////////////////

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
        //WScript.StdOut.WriteLine( e.message + " " + file );
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
   // WScript.StdOut.WriteLine( "finished writting to " + file );
}

////////////////////////////////////////////////////////////////////////
// transform xml document via xslSrc, return result
////////////////////////////////////////////////////////////////////////

function transform( xslSrc, filterKey, filterValue, arg )
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

	processor.addParameter( filterKey, filterValue ) ;
    processor.addParameter( "package", package ) ;


    // do the magic
    processor.transform();

    return processor.output;
}

////////////////////////////////////////////////////////////////////////
// transform xml document via xslSrc and save to file if modified
////////////////////////////////////////////////////////////////////////

function transmorph( xslSrc, file, filterKey, filterValue  )
{
    var result = transform( xslSrc, filterKey, filterValue );
    saveFile( result, file );
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

// command line arguments

var typelib = WScript.Arguments.Item(0);
var package = WScript.Arguments.Item(1);


// generate package structure
WScript.StdOut.WriteLine("generating package " + package);

var packages = package.split(".");
var path = shell.CurrentDirectory + "\\src";
for ( var i = 0; i < packages.length; i++ )
{
	var path = path + "\\" + packages[i];
	try {
		fso.CreateFolder(path);
	}
	catch(e)
	{}
}

WScript.StdOut.WriteLine("generated package path" + package);

// read typeib and generate xml

WScript.StdOut.WriteLine("reading type library from " + typelib);


var a = typelib.split("\\");
var typelibname = a[a.length-1];
var xmlfile = typelibname.substr(0,typelibname.length-3) + "xml";
xmlfile = shell.CurrentDirectory + "\\xml\\" + xmlfile;

var commandline = '..\\..\\..\\..\\cg\\comtyper.exe "' + typelib  +'" "' + xmlfile + '"';
WScript.StdOut.WriteLine(commandline );

var oExec = shell.Exec( commandline );
while (oExec.Status == 0)
{
     WScript.Sleep(100);
}



// transform xml into java src

WScript.StdOut.WriteLine("transforming " + xmlfile );


xml.load(xmlfile );
xml.setProperty("SelectionLanguage", "XPath");
var result = xml.selectNodes("//interface");


for ( var i = 0; i < result.length; i++ )
{
  var iface = result[i].getAttribute("name");
  WScript.StdOut.WriteLine("write interface " + iface);


  var output = transform(shell.CurrentDirectory + "\\jcg-import.xsl", "filter", iface);
  output += transform(shell.CurrentDirectory + "\\jcg.xsl", "filter", iface);


  saveFile(output, path + "\\" + iface + ".java");
}


WScript.StdOut.WriteLine("SUCCESS");
WScript.StdOut.WriteLine("----------------------------------");

WScript.Sleep(1000);

