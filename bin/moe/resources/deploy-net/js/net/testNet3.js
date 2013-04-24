var net = new NET();

net.Import("System.Drawing");
net.Import("System.Windows.Forms")

var form = net.Runtime.System.Windows.Forms.Form.New();
if (!form)
{
  moe.Dialogs.MsgBox("no","form",0);
}

var button1_Click = function (e,s) {
	
   net.Runtime.System.Windows.Forms.Application.Exit();
};



var button1 = net.Runtime.System.Windows.Forms.Button.New();

form.SuspendLayout();
var POINT = net.Runtime.System.Drawing.Point;
if (!POINT)
{
  moe.Dialogs.MsgBox("no","POINT",0);
}

var p = POINT.New(46, 51);
if (!p)
{
  moe.Dialogs.MsgBox("no","Point",0);
}
button1.Location = p;
button1.Name = "button1";
var s = net.Runtime.System.Drawing.Size.New(180, 104);
button1.Size = s;
button1.TabIndex = 0;
button1.Text = "button1";
button1.UseVisualStyleBackColor = true;

net.connect(button1_Click,"Click",button1);

form.AutoScaleDimensions = net.Runtime.System.Drawing.SizeF.New(6.0, 13.0);
form.AutoScaleMode = net.Runtime.System.Windows.Forms.AutoScaleMode.Font;
form.ClientSize = net.Runtime.System.Drawing.Size.New(284, 262);
form.Controls.Add(button1);
form.Name = "Form1";
form.Text = "Form1";
form.ResumeLayout(false);

form.Show();
//form.SetTopLevel(true);
form.Activate();
net.Runtime.System.Windows.Forms.Application.Run(form);

net.Exit();
