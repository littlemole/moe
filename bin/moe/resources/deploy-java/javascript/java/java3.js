var java = new Java();

var JFrame = java.Runtime.javax.swing.JFrame;
var frame = new JFrame();

var panel = new java.Runtime.javax.swing.JPanel();

var handler = function() 
{
//  moe.Dialogs.MsgBox("he","hehe",0);
  java.Exit();
  Quit();
}



frame.getContentPane().add(panel);

var quitButton = new java.Runtime.javax.swing.JButton("Exit");
quitButton.setBounds(50, 60, 80, 30);
quitButton.addActionListener(handler);

panel.add(quitButton);

frame.setTitle("Simple example");
frame.setSize(300, 200);
frame.setLocationRelativeTo(null);
frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
frame.setVisible(true);
//frame.setAlwaysOnTop(true);

Wait();
