
var p = moe.ModulePath;

var o = p + "\\io.dll";//#Path";
//o = encodeURI(o);// o.replace(/\\/g,"/");

var s = new ActiveXObject("WScript.Shell");
//s.popUp(o);

var doc = moe.OpenHtmlFrame( 
			  "file://" + p + "\\forms\\object.html?" + o /* +
			  o ,
			  //"\\io.dll#Path" * /
			  moe.left+50,moe.top+50,
			  650,550,1
*/
		);

//s.popUp(doc!=0);
var f = doc.HtmlFrame;
//s.popUp(f!=0);
var d = f.Document;
s.popUp(d.location.href);
o = p + "\\pipedprocess.dll";//#Path";
var x = "file://" + p + "\\forms\\object.html?" + o;
x = x.replace(/\\/g,"/");
s.popUp(x);
f.eval("window.location.href='" + x + "';","javascript");
//d.parentWindow.location.href = x;
s.popUp(d.location.href);
