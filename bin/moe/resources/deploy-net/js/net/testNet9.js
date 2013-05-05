var net = new NET();

Dialogs.MsgBox( "init", "test:1",0);

var obj = { 
	Value : net.Runtime.System.String,
	Value2 : net.Runtime.System.Int32
 };

Dialogs.MsgBox( "init", "test:2",0);

net.Prototype("My.Test",obj);

var o =  new net.Runtime.My.Test();

o.Value = "aaa";//net.String("test");
o.Value2 = 123;

Dialogs.MsgBox( o.Value, o.Value2,0);
net.Exit();
