
var Java = new ActiveXObject("JRE.Java");

var URL = Java("java.net.URL");
var URLConnection = Java("java.net.URLConnection");
var BufferedReader = Java("java.io.BufferedReader");
var InputStreamReader = Java("java.io.InputStreamReader");
var InputStream = Java("java.io.InputStream");

//moe.Dialogs.MsgBox("java up and running","ha",0);

var url = URL.New("http://www.amazon.de/");

var urlConnection = url.openConnection();
var stream = urlConnection.getInputStream();
//var reader = InputStreamReader.New( stream );//, "UTF-8");
var bufferedReader = BufferedReader.New( InputStreamReader.New( stream ) );

var buffer = "";
var inputLine = bufferedReader.readLine();

while ( inputLine != null )
{
	buffer += inputLine + "\r\n";
    inputLine = bufferedReader.readLine();
}
bufferedReader.close();

var txt = "" + buffer;

var doc = moe.Documents.New();
doc.Object.Text = txt;

Java.Exit();
