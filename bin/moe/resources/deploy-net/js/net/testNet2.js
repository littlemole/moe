var net = new NET();
net.Import("System.Windows.Forms");

var msgBox = net.Runtime.System.Windows.Forms.MessageBox;
if (!msgBox)
{
  moe.Dialogs.MsgBox("no","msgBox",0);
}

msgBox.Show("a .NET string!","Title");
