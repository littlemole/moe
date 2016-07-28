var net = new NET();
var System = net.Import("System");
net.Import("System.Core");

//var c = net.Runtime.System.Collections.ObjectModel.ObservableCollection.of(net.Runtime.System.Object);
//var cc = new c();
//moe.Dialogs.MsgBox(c.ToString(),cc.ToString(),0);


var conf = Config.Settings;

var x = conf.Find("/shortcuts");
moe.Dialogs.MsgBox(x.Value,x.Key,0);

var root = {};

function confWalker(root,conf)
{
	for ( var i = 0; i < conf.Count(); i++ )
	{
		var item = conf(i);
		root[item.Key] = { value : item.Value, path : item.KeyName() };
		if ( item.Count() > 0 )
		{
			root[item.Key]= { tag : item, value : {} };
			confWalker( root[item.Key].value, item );
		}
	}
}

confWalker(root,conf);

var json = JSON.stringify(root,null,"  ");
moe.Dialogs.MsgBox(json,"FORMS",0);
moe.Dialogs.MsgBox(root.shortcuts.value.doctype.tag.Key,"FORMS",0);