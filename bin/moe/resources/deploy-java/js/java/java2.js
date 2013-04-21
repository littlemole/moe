

var Java = new ActiveXObject("JRE.Java");
if (!Java)
{
  moe.Dialogs.MsgBox("no jre","ba",0);
}

var JFrame = Java.LoadClass("javax.swing.JFrame");
moe.Dialogs.MsgBox("hu","ha",0);
var frame = JFrame.New();
frame.setTitle("Simple example");
frame.setSize(300, 200);
frame.setLocationRelativeTo(null);
frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
frame.setVisible(true);
frame.setAlwaysOnTop(true);

//Java.Exit();

Wait(2000);