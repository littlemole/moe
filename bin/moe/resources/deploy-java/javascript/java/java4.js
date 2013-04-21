
var Java = new ActiveXObject("JRE.Java");
if (!Java)
{
  moe.Dialogs.MsgBox("no jre","ba",0);
}

var url = new Java.Runtime.java.net.URL("http://www.google.de/");
var connection = url.openConnection();
var stream = connection.getInputStream();

moe.Dialogs.MsgBox(
		connection.getContentLength() + 
		"/" + 
		connection.getContentType() 
		+ "/" + 
		connection.getContentEncoding(),
		"ba",0);

var bufferedReader = new Java.Runtime.java.io.BufferedReader( 
						new Java.Runtime.java.io.InputStreamReader( stream ) 
					);

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
