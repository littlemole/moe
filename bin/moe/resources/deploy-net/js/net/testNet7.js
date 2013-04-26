var net = new NET();

var wpf = new net.Runtime.org.oha7.dotnet.WPFLauncher();
wpf.load("test.xaml");
var butt = wpf.get("button1");
var edit = wpf.get("textbox");
var disp = butt.Dispatcher;
var x = "ba";

net.connect( 
	function(e,f) {
		x = disp.Invoke( edit.Text, null );
		//Dialogs.MsgBox(,"haha",0);
		wpf.exit();
	}, 
	"Click", 
	butt 
);

wpf.run();

Dialogs.MsgBox(y,"haha",0);
//Wait(0);
