


var Java = new ActiveXObject("JRE.Java");
if (!Java)
{
  moe.Dialogs.MsgBox("no jre","ba",0);
}

var URL = Java.LoadClass("java.net.URL");
var URLConnection = Java.LoadClass("java.net.URLConnection");
var BufferedReader = Java.LoadClass("java.io.BufferedReader");
var InputStreamReader = Java.LoadClass("java.io.InputStreamReader");
var InputStream = Java.LoadClass("java.io.InputStream");

var url = URL.New("http://javasourcecode.org/html/open-source/jdk/jdk-6u23/sun/rmi/transport/proxy/HttpInputStream.html");

var urlConnection = url.openConnection();
var stream = urlConnection.getInputStream();
if (!stream)
{
  moe.Dialogs.MsgBox("no stream","ba",0);
}
moe.Dialogs.MsgBox(stream.toString(),"ba",0);
moe.Dialogs.MsgBox(urlConnection.getContentLength() + "/" + urlConnection.getContentType() + "/" + urlConnection.getContentEncoding(),"ba",0);

var s = Java.Cast( stream, "java.io.InputStream" );
if (!s)
{
  moe.Dialogs.MsgBox("no s","ba",0);
}

var reader = InputStreamReader.New( stream , "UTF-8");
if (!reader)
{
  moe.Dialogs.MsgBox("no reader","ba",0);
}
var bufferedReader = BufferedReader.New(reader );
if (!bufferedReader)
{
  moe.Dialogs.MsgBox("no bufferedReader","ba",0);
}

var buffer = "";
var inputLine = bufferedReader.readLine();

while ( inputLine != null )
{
	buffer += inputLine;
    inputLine = bufferedReader.readLine();
}
bufferedReader.close();

moe.Dialogs.MsgBox(buffer ,"ba",0);


Java.Exit();