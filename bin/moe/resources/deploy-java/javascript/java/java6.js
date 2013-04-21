
var Java = new ActiveXObject("JRE.Java");


//moe.Dialogs.MsgBox("java up and running","ha",0);

var Client = Java("org.oha7.test.Client");
if (!Client)
{
	moe.Dialogs.MsgBox("no client","ha",0);
}

//var client = Client.New();

var handler = function(txt) {
  moe.Dialogs.MsgBox(txt,"ha",0);
}

Client.test(handler);

Client.test2(moe);


Java.Exit();
