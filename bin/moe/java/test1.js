var jre = new ActiveXObject("JRE.JRE");
var shell = new ActiveXObject("WScript.Shell");

jre.Classpath = "D:\\dev\\workspace\\jmoeTest\\jmoetest.jar;D:\\dev\\workspace\\jmoe\\jmoe.jar;D:\\dev\\workspace\\com4j\\build\\dist\\com4j.jar";

var x = new function(){};

var doc = moe.Docs.Item("file://Z:/public_html/index.html");

if ( doc )
{
//shell.Popup("found doc!");
	var f = doc.HtmlFrame;
	//shell.Popup("found doc!");
    if ( f )
	{
		jre.Extension("mol.moeTest.moeTest",moe,f);	    
		//shell.Popup("found doc!");

	}
}
