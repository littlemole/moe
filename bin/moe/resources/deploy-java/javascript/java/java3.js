
//moe.Dialogs.MsgBox("hu","ha",0);

var Java = new ActiveXObject("JRE.Java");
if (!Java)
{
  moe.Dialogs.MsgBox("no jre","ba",0);
}
var JFrame = Java.Runtime.javax.swing.JFrame;// Java.LoadClass("javax.swing.JFrame");
var frame = new JFrame(); //JFrame.New();

//var JPanel = Java.Runtime.javax.swing.JPanel;//  Java.LoadClass("javax.swing.JPanel");
var panel = new Java.Runtime.javax.swing.JPanel(); //JPanel();

var handler = function() 
{
  moe.Dialogs.MsgBox("he","hehe",0);
  Java.Exit();
  Quit();
}

frame.getContentPane().add(panel);

//var JButton = Java.LoadClass("javax.swing.JButton");
moe.Dialogs.MsgBox("hu","ha",0);

var quitButton = new Java.Runtime.javax.swing.JButton("Exit");// JButton.New("Quit");
quitButton.setBounds(50, 60, 80, 30);
quitButton.addActionListener(handler);

panel.add(quitButton);

frame.setTitle("Simple example");
frame.setSize(300, 200);
frame.setLocationRelativeTo(null);
frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
frame.setVisible(true);
frame.setAlwaysOnTop(true);

Wait(0);
//Java.Exit();