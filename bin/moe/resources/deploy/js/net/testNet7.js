var net = new NET();
net.Import("PresentationFramework");


var wpf =  new net.Runtime.org.oha7.dotnet.XAML();
wpf.load("test.xaml");

var page  = wpf.get("page");
var butt  = wpf.get("button1");
var edit  = wpf.get("textbox");
var combo = wpf.get("combo");

var Model = (function() 
{
	net.Runtime.My.Model = { 
		list   : net.Runtime.System.Collections.ArrayList,
		value  : net.Runtime.System.String //Object
	};

	var constructor = function() {
		var model = new net.Runtime.My.Model();
		model.value = "test2";

		model.list = new net.Runtime.System.Collections.ArrayList();
		model.list.Add( "test1" );
		model.list.Add( "test2" );
		model.list.Add( "test3" );
		return model;
	}
	return constructor;
}());

var model = new Model();

page.DataContext = model;

//wpf.bind( combo, "SelectedValueProperty", Model );
//wpf.bind( edit, "TextProperty", Model );

var r = "";
butt.On("Click", function(e,f) {
	r = combo.SelectedValue;
	wpf.window.Title = r;
	net.Runtime.System.Windows.MessageBox.Show(r);
	//wpf.exit();
});

/*
combo.On( "SelectionChanged", function(e,f) {
		edit.Text = combo.SelectedValue;
});
*/

wpf.window.Width  = 500;
wpf.window.Height = 300;


wpf.run();

