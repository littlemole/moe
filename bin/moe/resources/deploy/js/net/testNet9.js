var net = new NET();

//Dialogs.MsgBox( "init", "test:1",0);

net.Runtime.My.Test = { 
	x   : 42,
	Value : net.Runtime.System.String,
	Value2 : net.Runtime.System.Int32,
	SubObject : {
		key : net.Runtime.System.String
	}
};

function MyTest(x,val1,val2,key) 
{
	var that = new net.Runtime.My.Test();
	that.Value = val1;
	that.Value2 = val2;
	that.x = x;
	that.SubObject = new net.Runtime.My.Test$SubObject();
	that.SubObject.key = key;
	return that;
}


var o = new MyTest(42,"aaa",123,"madness");

Dialogs.MsgBox( o.Value, o.Value2,0);
Dialogs.MsgBox( o.x, o.SubObject.key,0);

o = new MyTest(23,"bbb",4711,"mad2");

Dialogs.MsgBox( o.Value, o.Value2,0);
Dialogs.MsgBox( o.x, o.SubObject.key,0);

net.Exit();
