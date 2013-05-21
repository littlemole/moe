var net = new NET();

//moe.Dialogs.MsgBox("hu","ha",0);

var Drawing = net.Import("System.Drawing");
var Forms   = net.Import("System.Windows.Forms");


// construct GUI

// main form

var form   = new Forms.Form();
form.SuspendLayout();

// event handler
var callback = function() {	
	moe.Dialogs.MsgBox("button1_Click","event",0);
    form.Close();
};

form.ClientSize =  new Drawing.Size(284, 262);
form.Text = "Form1";

// button
var button = new Forms.Button();
button.Location =  new Drawing.Point(46, 51);
button.Size =  new Drawing.Size(180, 104);
button.Text = "button1";

// connect event handler
button.On("Click",callback);

form.Controls.Add(button);
form.ResumeLayout(false);
form.Show();
form.Activate();

// run application
Forms.Application.Run(form);

