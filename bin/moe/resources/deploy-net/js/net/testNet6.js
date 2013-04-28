var net = new NET();

//moe.Dialogs.MsgBox("hu","ha",0);

var Drawing = net.Import("System.Drawing");
var Forms   = net.Import("System.Windows.Forms");

// event handler
var callback = function() {	
	moe.Dialogs.MsgBox("button1_Click","event",0);
    Forms.Application.Exit();
};

// construct GUI

// main form

var form   = new Forms.Form();
form.SuspendLayout();

form.AutoScaleDimensions = new Drawing.SizeF(6.0, 13.0);
form.AutoScaleMode = Forms.AutoScaleMode.Font;
form.ClientSize =  new Drawing.Size(284, 262);
form.Name = "Form1";
form.Text = "Form1";

// button
var button = new Forms.Button();
button.Location =  new Drawing.Point(46, 51);
button.Name = "button1";
button.Size =  new Drawing.Size(180, 104);
button.Text = "button1";

// connect event handler
net.connect(callback,"Click",button);

form.Controls.Add(button);
form.ResumeLayout(false);
form.Show();
form.Activate();
//form.SetTopLevel(1);

// run application
Forms.Application.Run(form);

// clean up
//net.Exit();