var java = new Java();

var url = java.Runtime.java.net.URL("http://www.amazon.de/");

var connection = url.openConnection();
var stream = connection.getInputStream();

moe.Dialogs.MsgBox(
		connection.getContentLength() + 
		"/" + 
		connection.getContentType() 
		+ "/" + 
		connection.getContentEncoding(),
		"ba",0);

var reader = java.Runtime.java.io.InputStreamReader( stream ) ;
var bufferedReader =  java.Runtime.java.io.BufferedReader( reader );

var buffer = "";
var inputLine = bufferedReader.readLine();

while ( typeof(inputLine) != "undefined"  )//!= null )
{
Print(inputLine);
	buffer += inputLine + "\r\n";
    inputLine = bufferedReader.readLine();
}
bufferedReader.close();

var txt = "" + buffer;

var doc = moe.Documents.New();
doc.Object.Text = txt;

java.Exit();
