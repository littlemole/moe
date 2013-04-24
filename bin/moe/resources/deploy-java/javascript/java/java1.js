var java = moe.Script.CreateObject("JRE.Java");

var JOptionPane = java.Runtime.javax.swing.JOptionPane;

JOptionPane.showMessageDialog(
				null, 
				"Test", 
				"Test Titel", 
				JOptionPane.OK_CANCEL_OPTION
			);

java.Exit();