var Controller = {

	Form_Load :function() {

		var s = form("CommandButton1").Name;  
		form.Controls.TextBox1 = s;
	},


	CommandButton1_Click : function() {
		Dialogs.MsgBox("click hu","clik ha",0);
		form.Close();
	},

	Form_Close : function() {

		Quit();
	}

};

var form = Script.CreateObject("MoeUserForm.UserFormRunner"); 
form.Load( Controller, "forms\\test.ucs", false);

wait();
