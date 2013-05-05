var net = new NET();

var wpf =  new net.Runtime.org.oha7.dotnet.XAML();
wpf.load("test.xaml");

var butt  = wpf.get("button1");
var edit  = wpf.get("textbox");
var combo = wpf.get("combo");

var list = new net.Runtime.System.Collections.ArrayList();
list.Add( "test1" );
list.Add( "test2" );

combo.ItemsSource = list;

var Model = wpf.Property();
Model.Value = "test2";

wpf.bind( combo, "SelectedValueProperty", Model );
wpf.bind( edit, "TextProperty", Model );

var r = "";

butt.On("Click", function(e,f) {
	//Model.Value="test1";
	r = edit.Text;
	//wpf.exit();
});

/*
combo.On( "SelectionChanged", function(e,f) {
		edit.Text = combo.SelectedValue;
});
*/

wpf.run();

Dialogs.MsgBox(r,Model.Value,0);
