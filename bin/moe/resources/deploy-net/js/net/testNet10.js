var net = new NET();

Dialogs.MsgBox("hi","hu",1);

var Drawing = net.Import("System.Drawing");
var Forms   = net.Import("System.Windows.Forms");
var System  = net.Runtime.System;

net.Runtime.My.Style = { 
	Id : System.Int32,
	Description : System.String,
	Bold : System.Boolean,
	Italic : System.Boolean,
	Eol : System.Boolean,
	Fontname : System.String,
	Fontsize : System.Int32,
	Forecolor : System.String,
	Backcolor : System.String
};

function makeStyleList( styleSet, index) 
{
	var list = new System.Collections.ArrayList();
	for ( var i = 0; i < styleSet.Count; i++)
	{
		var s = new net.Runtime.My.Style();
		net.Runtime.org.oha7.dotnet.Prototype.copyTo(styleSet.Item(i),s);
		list.Add(s);
	}
	return list;
}

function updateTextControl()
{
	var style = "Regular";
	if ( bs.Current.Bold )
		style += ", Bold";
	if ( bs.Current.Italic )
		style +=", Italic";

	var s = System.Enum.Parse(Drawing.FontStyle,style);
	font.Value = new Drawing.Font(bs.Current.Fontname, parseFloat(bs.Current.Fontsize), s);

	text.ForeColor = Drawing.ColorTranslator.FromHtml(bs.Current.Forecolor);
	text.BackColor = Drawing.ColorTranslator.FromHtml(bs.Current.Backcolor);
}

var bs = new Forms.BindingSource();
bs.DataSource = makeStyleList(moe.Config.StyleSets(0),0);

var font = new net.Runtime.org.oha7.dotnet.Property();
font.Value = new Drawing.Font("Courier New", 8.0); // need some initial value

var form = new Forms.Form();
var button = new Forms.Button();
var combo = new Forms.ComboBox();
var text = new Forms.TextBox();
var data = new Forms.DataGridView();

form.SuspendLayout();

combo.Location = new Drawing.Point(29, 30);
combo.Size = new Drawing.Size(100, 21);

var list = new net.Runtime.System.Collections.ArrayList();
list.Add("text");
list.Add("html");
list.Add("css");
list.Add("vb");
list.Add("js");
list.Add("sql");
list.Add("shell");
list.Add("perl");
list.Add("c++");
list.Add("java");
list.Add("c#");

combo.DataSource = list;
combo.On("SelectedIndexChanged", function() {
	bs.Position = 0;
	bs.DataSource = makeStyleList(moe.Config.StyleSets(combo.SelectedIndex), combo.SelectedIndex);
});

text.Location = new Drawing.Point(150, 30);
text.Size = new Drawing.Size(197, 20);

var binding = new Forms.Binding("Text", bs, "Description", false);
text.DataBindings.Add(binding);

binding = new Forms.Binding("Font", font, "Value", false);
text.DataBindings.Add(binding);

data.Location = new Drawing.Point(29,60);
data.Size = new Drawing.Size(545, 140);
data.RowHeadersVisible = false;
data.DataSource = bs;
data.AllowUserToAddRows = false;
data.AllowUserToDeleteRows = false;
data.MultiSelect = false;
data.Refresh();

data.On( "SelectionChanged", function(s,e) {

	updateTextControl();
});

data.On(  "CellContentClick", function(s,e) {

	if(2 <= e.ColumnIndex && e.ColumnIndex <= 4 ) {
		data.EndEdit();
	}
	updateTextControl();
});

button.Location = new Drawing.Point(476,211);
button.Size = new Drawing.Size(180,44);
button.Text = "click me";

button.On("Click",function() {
	bs.DataSource = makeStyleList(moe.Config.StyleSets(bs.Position), bs.Position);
});

form.ClientSize = new Drawing.Size(684, 262);
form.Controls.Add(button);
form.Controls.Add(combo);
form.Controls.Add(text);
form.Controls.Add(data);
form.Text = "Form1";
form.ResumeLayout(false);

form.Show();

data.Columns.get_Item(0).Visible = false;
data.AutoResizeColumns(Forms.DataGridViewAutoSizeColumnsMode.AllCells);

form.Activate();
Forms.Application.Run(form);


