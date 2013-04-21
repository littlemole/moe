

var Java = new ActiveXObject("JRE.Java");
if (!Java)
{
  moe.Dialogs.MsgBox("no jre","ba",0);
}

var JOptionPane = Java.Runtime.javax.swing.JOptionPane;//Java.LoadClass("javax.swing.JOptionPane");
moe.Dialogs.MsgBox("hu","ha",0);
//var x = Java.Runtime.javax.swing.JOptionPane;

//var x = new JOptionPane();
//var x = Java["javax.swing.JOptionPane"];
JOptionPane.showMessageDialog(null, "Test", "Test Titel", JOptionPane.OK_CANCEL_OPTION);

Java.Exit();