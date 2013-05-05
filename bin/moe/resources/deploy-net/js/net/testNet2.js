var net = new NET();
net.Import("System.Windows.Forms");

var f = net.Runtime.System.Windows.Forms.Form.New();
f.StartPosition = net.Runtime.System.Windows.Forms.FormStartPosition.Manual;
f.Left = 10000;
f.Show();
f.Activate();

var msgBox = net.Runtime.System.Windows.Forms.MessageBox;
if (!msgBox)
{
  moe.Dialogs.MsgBox("no","msgBox",0);
}

msgBox.Show(f,"a .NET string!","Title");
