var net = new NET();

var Drawing = net.Import("System.Drawing");
var Forms   = net.Import("System.Windows.Forms");

var bs = new Forms.BindingSource();

var form = new Forms.Form();
var button = new Forms.Button();
var combo = new Forms.ComboBox();
var text = new Forms.TextBox();

form.SuspendLayout();

button.Location = new Drawing.Point(46,151);
button.Name = "button";
var s = net.Runtime.System.Drawing.Size.New(180, 104);
button.Size = new Drawing.Size(180,104);
button.Text = "click me";

button.On("Click",function() {
	form.Hide();
	Dialogs.MsgBox( bs.Current, "selected:",0);
	form.Close();
});

combo.FormattingEnabled = true;
combo.Location = new Drawing.Point(29, 30);
combo.Name = "comboBox1";
combo.Size = new Drawing.Size(171, 21);

text.Location = new Drawing.Point(30, 110);
text.Name = "textBox1";
text.Size = new Drawing.Size(197, 20);

form.ClientSize = new Drawing.Size(284, 262);
form.Controls.Add(button);
form.Controls.Add(combo);
form.Controls.Add(text);
form.Name = "Form1";
form.Text = "Form1";
form.ResumeLayout(false);

var list = new net.Runtime.System.Collections.ArrayList();
list.Add("test1");
list.Add("test2");
list.Add("test3");


bs.DataSource = list;
combo.DataSource = bs;

var binding = new Forms.Binding("Text", bs, "", false);
text.DataBindings.Add(binding);

form.Show();
form.Activate();

Forms.Application.Run(form);


