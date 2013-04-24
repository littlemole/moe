
var java = new Java();

var URL = java.Runtime.java.net.URL;
var URLConnection = java.Runtime.java.net.URLConnection;
var BufferedReader = java.Runtime.java.io.BufferedReader;
var InputStreamReader = java.Runtime.java.io.InputStreamReader;
var InputStream = java.Runtime.java.io.InputStream;

var url = URL.New("http://www.amazon.de/");
var urlConnection = url.openConnection();

var stream = urlConnection.getInputStream();

var reader = InputStreamReader.New( stream );//, "UTF-8");
var bufferedReader = BufferedReader.New( reader );
Dialogs.MsgBox(bufferedReader.toString(),"hm",0);

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

java.Exit();
