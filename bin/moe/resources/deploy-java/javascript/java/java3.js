var Java = new ActiveXObject("JRE.Java");

var JFrame = Java.Runtime.javax.swing.JFrame;
var frame = new JFrame();

var panel = new Java.Runtime.javax.swing.JPanel();

var handler = function() 
{
  moe.Dialogs.MsgBox("he","hehe",0);
  Java.Exit();
  Quit();
}

frame.getContentPane().add(panel);

var quitButton = new Java.Runtime.javax.swing.JButton("Exit");
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
