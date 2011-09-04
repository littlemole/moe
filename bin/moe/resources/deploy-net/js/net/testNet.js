var NET = new ActiveXObject("Net.DotNet");
if (!NET)
{
  moe.Dialogs.MsgBox("no","NET",0);
}

// import assembly
var FORMS = NET.Import("System.Windows.Forms");
if (!FORMS)
{
  moe.Dialogs.MsgBox("no","FORMS",0);
}

// get type
var msgBox = FORMS.Type("System.Windows.Forms.MessageBox");
if (!msgBox)
{
  moe.Dialogs.MsgBox("no","msgBox",0);
}

// call static method
msgBox.Show("a .NET string!","Title");


// or simplified with shortcuts as one-liner ;-)
NET("System.Windows.Forms.MessageBox").Show("another .NET string!","Title");