var net = new NET();
var System = net.Import("System");
net.Import("System.Core");

var ListOfString = System.Collections.Generic.List.of(System.String);
var list = new ListOfString();
list.Add("11");
list.Add("2");


Dialogs.MsgBox(list.Item(0),"hm",0);

var a = System.Array.CreateInstance( System.String, 2 );

a.SetValue("a",0);
a.SetValue("b",1);

Dialogs.MsgBox(a.GetValue(1),"hm",0);




