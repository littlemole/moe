var Java = new ActiveXObject("JRE.Java");

var JOptionPane = Java.Runtime.javax.swing.JOptionPane;

JOptionPane.showMessageDialog(
				null, 
				"Test", 
				"Test Titel", 
				JOptionPane.OK_CANCEL_OPTION
			);

Java.Exit();