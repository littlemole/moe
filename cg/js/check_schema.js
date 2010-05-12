var shell = new ActiveXObject("WScript.Shell");

function validateFile( file )
{
    // Create a schema cache and add books.xsd to it.
    var xs = new ActiveXObject("MSXML2.XMLSchemaCache.4.0");
    xs.add("urn:Moe.Xmoe", "..\\xml\\resource.xsd");

    // Create an XML DOMDocument object.
    var x = new ActiveXObject("MSXML2.DOMDocument.4.0");

	//x.schemas = xs;

    // Set first-level DOM properties.
    x.async = false;
    x.validateOnParse = true;
    x.resolveExternals = true;

    // Configure DOM properties for namespace selection.
    x.setProperty("SelectionLanguage", "XPath");
    ns = "xmlns:mol='urn:Moe.Xmoe'";
    x.setProperty("SelectionNamespaces", ns);

    // Load and validate the specified file into the DOM.
    x.load(file);

    // Return validation results in message to the user.
    if (x.parseError.errorCode != 0)
    {
        return("Validation failed on " + file + 
            "\n=====================" +
            "\nReason: " + x.parseError.reason + 
            "\nSource: " + x.parseError.srcText + 
            "\nLine: " + x.parseError.line + "\n");
    }
    else
        return("Validation succeeded for " + file + "\n");
}

var result = validateFile("..\\xml\\resource.xml");

shell.popup(result,0,"result");

