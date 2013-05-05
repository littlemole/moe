var net = new NET;

var Drawing = net.Import("System.Drawing");
var Forms   = net.Import("System.Windows.Forms")

// types
var Application   = Forms.Application;
var Form          = Forms.Form;
var Button        = Forms.Button;
var Point         = Drawing.Point;
var Size		  = Drawing.Size;

// event handler
var callback = function() {	
	moe.Dialogs.MsgBox("button1_Click","event",0);
    Application.Exit();
};

// construct GUI

// main form
var form   = new Form();
form.SuspendLayout();

form.ClientSize = new Size(284, 262);
form.Text = "Form1";

// button
var button = new Button();
button.Location = new Point(46, 51);
button.Size = new Size(180, 104);
button.Text = "button1";

// connect event handler
net.connect(callback,"Click",button);

form.Controls.Add(button);
form.ResumeLayout(false);
form.Show();
form.Activate();

// run application
Application.Run(form);

