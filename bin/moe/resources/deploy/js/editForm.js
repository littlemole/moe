

var Controller = {

	Form_Load :function() {
	},

	Form_Close : function() {

		Quit();
	}
};

var file = Dialogs.ChooseFile();

var form = Script.CreateObject("MoeUserForm.UserFormRunner"); 
form.Load( Controller,file,true);

wait(0);
