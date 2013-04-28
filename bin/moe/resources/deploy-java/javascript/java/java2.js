var java = new Java();
var JFrame = java.Runtime.javax.swing.JFrame;
var frame =  new JFrame();

frame.setTitle("Simple example");
frame.setSize(300, 200);
frame.setLocationRelativeTo(null);
frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
frame.setVisible(true);
frame.setAlwaysOnTop(true);


Wait(2000);
Java.Exit();
