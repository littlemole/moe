

var Controller = {

	Form_Load :function() {
	},

	Form_Close : function() {

		Quit();
	},

	CommandButton1_Click : function() {
		Dialogs.MsgBox("hu",form.Controls.TextBox1.Value,0);
		form.Close();
		Quit();
	}
};

var file = Dialogs.ChooseFile();

var form = Script.CreateObject("MoeUserForm.UserFormRunner"); 
form.Load( Controller,file,false);

wait();
