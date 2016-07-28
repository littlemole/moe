var net = new NET();

net.Import("System.Drawing");
net.Import("System.Windows.Forms")

var form = net.Runtime.System.Windows.Forms.Form.New();

var button1_Click = function (e,s) {
	
   //net.Runtime.System.Windows.Forms.Application.Exit();
   form.Close();
};

var button1 = net.Runtime.System.Windows.Forms.Button.New();

form.SuspendLayout();

button1.Location = net.Runtime.System.Drawing.Point.New(46, 51);
button1.Size = net.Runtime.System.Drawing.Size.New(180, 104);
button1.Text = "button1";

net.connect(button1_Click,"Click",button1);

form.ClientSize = net.Runtime.System.Drawing.Size.New(284, 262);
form.Controls.Add(button1);
form.Text = "Test Form1";

form.ResumeLayout(false);
form.Show();
form.Activate();

net.Runtime.System.Windows.Forms.Application.Run(form);

