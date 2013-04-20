

var Java = new ActiveXObject("JRE.Java");
if (!Java)
{
  moe.Dialogs.MsgBox("no jre","ba",0);
}

var JOptionPane = Java.LoadClass("javax.swing.JOptionPane");
moe.Dialogs.MsgBox("hu","ha",0);
JOptionPane.showMessageDialog(null, "Test", "Test Titel", JOptionPane.OK_CANCEL_OPTION);

Java.Exit();