var NET = new ActiveXObject("Net.DotNet");
NET.Import("System.Windows.Forms");

var msgBox = NET("System.Windows.Forms.MessageBox");
if (!msgBox)
{
  moe.Dialogs.MsgBox("no","msgBox",0);
}

msgBox.Show("a .NET string!","Title");
