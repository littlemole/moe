var java = new Java();

var url = java.Runtime.java.net.URL("http://www.google.de/");

var connection = url.openConnection();
var stream = connection.getInputStream();

moe.Dialogs.MsgBox(
		connection.getContentLength() + 
		"/" + 
		connection.getContentType() 
		+ "/" + 
		connection.getContentEncoding(),
		"ba",0);

var reader = new java.Runtime.java.io.InputStreamReader( stream ) ;
var bufferedReader = new java.Runtime.java.io.BufferedReader( reader );

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
