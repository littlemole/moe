
//moe.Dialogs.MsgBox("hu","ha",0);

var Java = new ActiveXObject("JRE.Java");
if (!Java)
{
  moe.Dialogs.MsgBox("no jre","ba",0);
}
moe.Dialogs.MsgBox("hu","ha",0);
var JFrame = Java.LoadClass("javax.swing.JFrame");
var frame = JFrame.New();

var JPanel = Java.LoadClass("javax.swing.JPanel");
var panel = JPanel.New();

var handler = function() 
{
  moe.Dialogs.MsgBox("he","hehe",0);
  Java.Exit();
  Quit();
}

frame.getContentPane().add(panel);

var JButton = Java.LoadClass("javax.swing.JButton");
var quitButton = JButton.New("Quit");
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