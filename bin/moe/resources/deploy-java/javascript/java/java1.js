//var java = moe.Script.CreateObject("JRE.Java");

var java = new Java();
if(java) Dialogs.MsgBox("hu","ha",0);

var JOptionPane = java.Runtime.javax.swing.JOptionPane;

JOptionPane.showMessageDialog(
				null, 
				"Test", 
				"Test Titel", 
				JOptionPane.OK_CANCEL_OPTION
			);

java.Exit();