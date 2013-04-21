var NET = new ActiveXObject("Net.DotNet");
NET.Import("System.Drawing");
NET.Import("System.Windows.Forms")

var form = NET("System.Windows.Forms.Form").New();
if (!form)
{
  moe.Dialogs.MsgBox("no","form",0);
}

var button1_Click = function (e,s) {
	
   NET("System.Windows.Forms.Application").Exit();
};



var button1 = NET("System.Windows.Forms.Button").New();

form.SuspendLayout();
var POINT = NET("System.Drawing.Point");
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
var s = NET("System.Drawing.Size").New(180, 104);
button1.Size = s;
button1.TabIndex = 0;
button1.Text = "button1";
button1.UseVisualStyleBackColor = true;

NET.connect(button1_Click,"Click",button1);

form.AutoScaleDimensions = NET("System.Drawing.SizeF").New(6.0, 13.0);
form.AutoScaleMode = NET("System.Windows.Forms.AutoScaleMode").Font;
form.ClientSize = NET("System.Drawing.Size").New(284, 262);
form.Controls.Add(button1);
form.Name = "Form1";
form.Text = "Form1";
form.ResumeLayout(false);
form.SetTopLevel(1);

form.Show();
NET("System.Windows.Forms.Application").Run(form);

NET.Exit();
