var java = new Java();
var JFrame = java.Runtime.javax.swing.JFrame;
var frame =  new JFrame();


var closing = function(arg1,arg2)
{
  moe.Dialogs.MsgBox("he" + arg2,"hehe",0);
  java.Exit();
  Quit();
}

frame.setTitle("Simple example");
frame.setSize(300, 200);
frame.setLocationRelativeTo(null);
//frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
frame.setVisible(true);
frame.setAlwaysOnTop(true);

frame.addWindowListener(closing);

Wait();
//Java.Exit();
