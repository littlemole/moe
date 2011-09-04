var DotNet = new ActiveXObject("Net.DotNet");

DotNet.Import("System.Drawing");
DotNet.Import("System.Windows.Forms")

// types
var Application   = DotNet("System.Windows.Forms.Application");
var Form          = DotNet("System.Windows.Forms.Form");
var Button        = DotNet("System.Windows.Forms.Button");
var Point         = DotNet("System.Drawing.Point");
var Size		  = DotNet("System.Drawing.Size");
var SizeF		  = DotNet("System.Drawing.SizeF");
var AutoScaleMode = DotNet("System.Windows.Forms.AutoScaleMode");

// event handler
var callback = function() {	
	moe.Dialogs.MsgBox("button1_Click","event",0);
    Application.Exit();
};

// construct GUI

// main form
var form   = Form.New();
form.SuspendLayout();

form.AutoScaleDimensions = SizeF.New(6.0, 13.0);
form.AutoScaleMode = AutoScaleMode.Font;
form.ClientSize = Size.New(284, 262);
form.Name = "Form1";
form.Text = "Form1";

// button
var button = Button.New();
button.Location = Point.New(46, 51);
button.Name = "button1";
button.Size = Size.New(180, 104);
button.Text = "button1";

// connect event handler
DotNet.connect(callback,"Click",button);

form.Controls.Add(button);
form.ResumeLayout(false);
form.Show();
form.SetTopLevel(1);

// run application
Application.Run(form);

// clean up
DotNet.Exit();