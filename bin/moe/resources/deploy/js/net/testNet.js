
var net = new NET();

// import assembly
var FORMS = net.Import("System.Windows.Forms");
if (!FORMS)
{
  moe.Dialogs.MsgBox("no","FORMS",0);
}

var f = FORMS.Form.New();
f.StartPosition = FORMS.FormStartPosition.Manual;
f.Left = 10000;
f.Show();
f.Activate();

// get type
var msgBox = FORMS.MessageBox;
if (!msgBox)
{
  moe.Dialogs.MsgBox("no","msgBox",0);
}

// call static method
msgBox.Show(f,"a .NET string!","Title");


// or simplified with shortcuts as one-liner ;-)
net.Runtime.System.Windows.Forms.MessageBox.Show(f,"another .NET string!","Title");

