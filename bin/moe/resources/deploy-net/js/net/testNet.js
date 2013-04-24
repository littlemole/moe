
var net = new NET();

// import assembly
var FORMS = net.Import("System.Windows.Forms");
if (!FORMS)
{
  moe.Dialogs.MsgBox("no","FORMS",0);
}

// get type
var msgBox = FORMS.MessageBox;
if (!msgBox)
{
  moe.Dialogs.MsgBox("no","msgBox",0);
}

// call static method
msgBox.Show("a .NET string!","Title");


// or simplified with shortcuts as one-liner ;-)
net.Runtime.System.Windows.Forms.MessageBox.Show("another .NET string!","Title");

