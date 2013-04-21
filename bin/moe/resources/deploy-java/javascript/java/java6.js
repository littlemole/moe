var Java = new ActiveXObject("JRE.Java");

var Client = Java.Runtime.org.oha7.test.Client;


var handler = function(txt) {
  moe.Dialogs.MsgBox(txt,"ha",0);
}

Client.test(handler);

Client.test2(moe);


Java.Exit();
