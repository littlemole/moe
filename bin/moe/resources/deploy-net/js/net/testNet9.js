var net = new NET();

Dialogs.MsgBox( "init", "test:1",0);

var obj = { 
	x   : 42,
	//string : "hello wurld",
	Value : net.Runtime.System.String,
	Value2 : net.Runtime.System.Int32
 };

Dialogs.MsgBox( "init", "test:2",0);

//net.Prototype("My.Test",obj);
net.Runtime.My.Test = obj;

var o =  new net.Runtime.My.Test();

o.Value = "aaa";//net.String("test");
o.Value2 = 123;
o.x = 42;
//o.string = "tralala";

Dialogs.MsgBox( o.Value, o.Value2,0);
Dialogs.MsgBox( o.x, o.x,0);
net.Exit();
