var net = new NET();

var wpf =  new net.Runtime.org.oha7.dotnet.WPFLauncher();
wpf.load("test.xaml");
var butt = wpf.get("button1");
var edit = wpf.get("textbox");
var text = "";

net.connect( 
	function(e,f) {
		text = edit.Text;
		wpf.exit();
	}, 
	"Click", 
	butt 
);

wpf.run();

Dialogs.MsgBox(text,"haha",0);
