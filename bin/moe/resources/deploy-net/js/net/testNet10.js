var net = new NET();

var Drawing = net.Import("System.Drawing");
var Forms   = net.Import("System.Windows.Forms");
var System  = net.Runtime.System;

net.Runtime.My.Style = { 
	Id 			: System.Int32,
	Description : System.String,
	Bold 		: System.Boolean,
	Italic 		: System.Boolean,
	Eol 		: System.Boolean,
	Fontname 	: System.String,
	Fontsize 	: System.Int32,
	Forecolor 	: System.String,
	Backcolor 	: System.String
};

var Model = (function() {

	var initialSyntax = ActiveDoc.Object.Properties.Syntax;

	var initialFont = new net.Runtime.org.oha7.dotnet.Property();
	initialFont.Value = new Drawing.Font("Courier New", 8.0); // need some initial value

	var bs = new Forms.BindingSource();

	var syntaxList = new net.Runtime.System.Collections.ArrayList();
	syntaxList.Add("text");
	syntaxList.Add("html");
	syntaxList.Add("css");
	syntaxList.Add("vb");
	syntaxList.Add("js");
	syntaxList.Add("sql");
	syntaxList.Add("shell");
	syntaxList.Add("perl");
	syntaxList.Add("c++");
	syntaxList.Add("java");
	syntaxList.Add("c#");

	var self = {

		styles		: null,
		syntax  	: initialSyntax,
		font 		: initialFont,
		datasource	: bs,
		modes		: syntaxList,

		htmlColor : function(col) {

			return System.String.Format("#{0:X2}{1:X2}{2:X2}", col.R, col.G, col.B);
		},

		makeStyleList : function( styleSet ) {

			var list = new System.Collections.ArrayList();
			for ( var i = 0; i < styleSet.Count; i++)
			{
				var s = new net.Runtime.My.Style();
				net.Runtime.org.oha7.dotnet.Prototype.copyTo(styleSet.Item(i),s);
				list.Add(s);
			}
			Model.styles = list;
			return list;
		},

		updateDatasource : function( index ) {

			this.datasource.Position = 0;
			this.datasource.DataSource = this.makeStyleList(moe.Config.StyleSets(index) );
		},

		updateFont : function() {

			var style = "Regular";
			if ( this.datasource.Current.Bold )
				style += ", Bold";
			if ( this.datasource.Current.Italic )
				style +=", Italic";

			var s = System.Enum.Parse(Drawing.FontStyle,style);
			this.font.Value = new Drawing.Font(
									this.datasource.Current.Fontname, 
									parseFloat(this.datasource.Current.Fontsize), 
									s);
		}
	};

	return self;
}());

var View = {

	form 			: new Forms.Form(),
	buttonApply 	: new Forms.Button(),
	buttonDefault 	: new Forms.Button(),
	combo 			: new Forms.ComboBox(),
	text 			: new Forms.TextBox(),
	data 			: new Forms.DataGridView(),
	panelTop 		: new Forms.Panel(),
	panelBottom 	: new Forms.Panel(),


	updateTextControl : function(dataSource) {

		this.text.ForeColor = Drawing.ColorTranslator.FromHtml(dataSource.Current.Forecolor);
		this.text.BackColor = Drawing.ColorTranslator.FromHtml(dataSource.Current.Backcolor);
	},

	updateColor : function(color) {

		var colDialog = new Forms.ColorDialog();
		colDialog.Color = Drawing.ColorTranslator.FromHtml(color);	

		var r = colDialog.ShowDialog();
		if (r.Equals(Forms.DialogResult.OK)) {		
			return Model.htmlColor(colDialog.Color);
		}
		return color;
	},

	init : function(syntax) {

		this.form.SuspendLayout();

		this.combo.Location = new Drawing.Point(29, 10);
		this.combo.Size = new Drawing.Size(100, 21);
		this.combo.DataSource = Model.modes;

		this.text.Location = new Drawing.Point(150, 10);
		this.text.Size = new Drawing.Size(197, 20);

		this.data.Location = new Drawing.Point(0,0);
		this.data.RowHeadersVisible = false;
		this.data.AllowUserToAddRows = false;
		this.data.AllowUserToDeleteRows = false;
		this.data.MultiSelect = false;
		this.data.Dock = Forms.DockStyle.Fill;

		this.buttonApply.Anchor = System.Enum.Parse(Forms.AnchorStyles,"Top,Right");
		this.buttonApply.Location = new Drawing.Point(60,10);
		this.buttonApply.Size = new Drawing.Size(120,20);
		this.buttonApply.Text = "Apply";

		this.buttonDefault.Location = new Drawing.Point(10,10);
		this.buttonDefault.Size = new Drawing.Size(120,20);
		this.buttonDefault.Text = "Make Default";

		this.panelTop.Controls.Add(this.combo);
		this.panelTop.Controls.Add(this.text);
		this.panelTop.Dock = Forms.DockStyle.Top;
		this.panelTop.Location = new Drawing.Point(0, 0);
		this.panelTop.Size = new Drawing.Size(504, 42);

		this.panelBottom.Controls.Add(this.buttonApply);
		this.panelBottom.Controls.Add(this.buttonDefault);
		this.panelBottom.Dock = Forms.DockStyle.Bottom;
		this.panelBottom.Location = new Drawing.Point(0, 0);
		this.panelBottom.Size = new Drawing.Size(504, 34);

		this.form.ClientSize = new Drawing.Size(504, 264);
		this.form.Controls.Add(this.data);
		this.form.Controls.Add(this.panelBottom);
		this.form.Controls.Add(this.panelTop);
		this.form.Text = "Customize Styles";
		this.panelTop.PerformLayout();
		this.panelBottom.PerformLayout();

		this.form.ResumeLayout(false);

		this.form.Show();

		this.combo.SelectedIndex = syntax;

		this.form.Activate();
	}
};

var Controller = {

	onSelectedIndexChanged : function() {

		Model.updateDatasource(View.combo.SelectedIndex);
	},

	onSelectionChanged : function() {

		Model.updateFont();
		View.updateTextControl(Model.datasource);
	},

	onCellContentClick : function(s,e) {

		switch(e.ColumnIndex)
		{
			case 0 : {
				break;
			}
			case 2 :
			case 3 :
			case 4 : {
				View.data.EndEdit();
				break;
			}
			case 5 : 
			case 6 : {
				break;
			}
			case 7 : {
				Model.datasource.Current.Forecolor = View.updateColor(Model.datasource.Current.Forecolor);
				break;
			}
			case 8 : {
				Model.datasource.Current.Backcolor = View.updateColor(Model.datasource.Current.Backcolor);
				break;
			}
		}

		Model.updateFont();
		View.updateTextControl(Model.datasource);
	},

	onApplyClick : function() {

		var styleSet = ActiveDoc.Object.Properties.StyleSets(View.combo.SelectedIndex);
		for ( var i = 0; i < Model.styles.Count; i++)
		{		
			net.copyTo(Model.styles.Item(i),styleSet.Item(i));
		}
		ActiveDoc.Object.Properties.Syntax = ActiveDoc.Object.Properties.Syntax;
	},

	onDefaultClick : function() {

		var styleSet = moe.Config.StyleSets(View.combo.SelectedIndex);
		net.copyTo(Model.datasource.Current, styleSet.Item(View.combo.SelectedIndex));
	},

	bindData : function() {

		var binding = new Forms.Binding("Text", Model.datasource, "Description", false);
		View.text.DataBindings.Add(binding);

		binding = new Forms.Binding("Font", Model.font, "Value", false);
		View.text.DataBindings.Add(binding);

		View.data.DataSource = Model.datasource;		
	},

	bindEvents : function() {

		View.combo.On("SelectedIndexChanged", Controller.onSelectedIndexChanged );

		View.data.On( "SelectionChanged", Controller.onSelectionChanged );
		View.data.On( "CellContentClick", Controller.onCellContentClick );

		View.buttonApply.On("Click", Controller.onApplyClick );
		View.buttonDefault.On("Click", Controller.onDefaultClick );		
	},

	layout : function() {

		View.data.Columns.get_Item(0).Visible = false;
		View.data.Columns.get_Item(1).Width=120;
		View.data.AutoResizeColumns(Forms.DataGridViewAutoSizeColumnsMode.ColumnHeader);		
		View.data.Refresh();
	},

	run : function() {

		Model.updateDatasource(Model.syntax);
		View.init(Model.syntax);
		this.bindData();
		this.bindEvents();
		this.layout();

		Forms.Application.Run(View.form);
	}
};

Controller.run();