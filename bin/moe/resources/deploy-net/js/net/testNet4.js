var Net = new ActiveXObject("Net.DotNet");

var Drawing = Net.Import("System.Drawing");
var Forms   = Net.Import("System.Windows.Forms")

// types
var Application   = Forms.Application;
var Form          = Forms.Form;
var Button        = Forms.Button;
var Point         = Drawing.Point;
var Size		  = Drawing.Size;
var SizeF		  = Drawing.SizeF;
var AutoScaleMode = Forms.AutoScaleMode;

// event handler
var callback = function() {	
	moe.Dialogs.MsgBox("button1_Click","event",0);
    Application.Exit();
};

// construct GUI

// main form
var form   = new Form();
form.SuspendLayout();

form.AutoScaleDimensions = new SizeF(6.0, 13.0);
form.AutoScaleMode = AutoScaleMode.Font;
form.ClientSize = new Size(284, 262);
form.Name = "Form1";
form.Text = "Form1";

// button
var button = new Button();
button.Location = new Point(46, 51);
button.Name = "button1";
button.Size = new Size(180, 104);
button.Text = "button1";

// connect event handler
Net.connect(callback,"Click",button);

form.Controls.Add(button);
form.ResumeLayout(false);
form.Show();
form.SetTopLevel(1);

// run application
Application.Run(form);

// clean up
Net.Exit();