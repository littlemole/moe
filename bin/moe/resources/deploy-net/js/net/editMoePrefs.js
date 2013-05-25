
var net = new NET();

////////////////////////////////////////////////////////////

var System 	= net.Import("System");
var Drawing = net.Import("System.Drawing");
var Design 	= net.Import("System.Drawing.Design");
var Forms 	= net.Import("System.Windows.Forms");
net.Import("System.Design");

var COM = System.ComponentModel;
var TypeConverter = System.ComponentModel.TypeConverter;
var StandardValuesCollection = TypeConverter.StandardValuesCollection;
var ITypeDescriptorContext = System.ComponentModel.ITypeDescriptorContext;

var ListOfInts = System.Collections.Generic.List.of(System.Int32);


////////////////////////////////////////////////////////////


var TabulatorConverter = net.Declare(
	"TabulatorConverter", 
	{
		inherits : TypeConverter , 
		methods : {
			GetStandardValuesSupported 	: [ System.Boolean, [ ITypeDescriptorContext ]],
			GetStandardValues 			: [ StandardValuesCollection, [ ITypeDescriptorContext ]],
			CanConvertFrom 				: [ System.Boolean, [ ITypeDescriptorContext, System.Type ]],
			ConvertFrom 				: [ System.Object, [ ITypeDescriptorContext, 
															 System.Globalization.CultureInfo, 
															 System.Object ]]
		}
	},
	{
		GetStandardValuesSupported : function(c) {

			return true;
		},

		GetStandardValues : function(c) {

			return new StandardValuesCollection(Model.defaultTabValues);
		},

		CanConvertFrom : function(ctx,type) {

			if ( type.Equals(System.String) )
				return true;
			return false;
		},

		ConvertFrom : function(ctx,culture,value) {

			if ( typeof(value) == "string")	{
				return System.Int32.Parse(value);
			}
			return void(0);
		}
	}
);

var CommandEditor = net.Declare(
	"CommandEditor", 
	{
		inherits : Design.UITypeEditor, 
		methods : {
			GetEditStyle 	: [ Design.UITypeEditorEditStyle, [ITypeDescriptorContext] ],
			EditValue 		: [ System.Object, [ ITypeDescriptorContext,
												 System.IServiceProvider,
												 System.Object ]]
		}
	},
	{
		GetEditStyle : function( ctx ) {

			return Design.UITypeEditorEditStyle.Modal;
		},

		EditValue : function( ctx, provider, value ) {

			if ( Controller["On" + ctx.PropertyDescriptor.Name] ) {
				return Controller["On" + ctx.PropertyDescriptor.Name](value);
			}
			return value;
		}
	}
);

var Settings = net.Declare( "Moe.Settings", {
	attributes : [[COM.DefaultPropertyAttribute,"Key"]], 
	properties : {
		Key  : [ System.String, [
				[COM.DescriptionAttribute,"Key of this user Setting Item."],
				[COM.CategoryAttribute,"Edit selected key"]
			 ]],
		Value : [ System.String, [
				[COM.CategoryAttribute,"Edit selected key"],
				[COM.DescriptionAttribute,"The Value of this User Setting Item."],
				[System.ComponentModel.EditorAttribute, COM.Design.MultilineStringEditor, Design.UITypeEditor] 
			 ]],
		Path : [ System.String, [
				[COM.CategoryAttribute,"Selection Path"],
				[COM.DisplayNameAttribute,"Key Path"],
				[COM.DescriptionAttribute,"The Path to this Key in the Settings tree."],
				[COM.ReadOnlyAttribute,true]
			 ]]
		}
	},
	{}
);


var DocumentDefaults = net.Declare( "Moe.DocumentDefaults", {
	attributes : [[COM.DefaultPropertyAttribute,"TabWidth"]], 
	properties : {
		TabUsage  : [ System.Boolean, [
				[COM.DescriptionAttribute,"Specify whether to use tabulators or to convert tab strokes to whitespace rightaway."],
				[COM.DisplayNameAttribute,"Use Tabulators"],
				[COM.CategoryAttribute,"New Document Defaults"]
			 ]],
		TabIndents : [ System.Boolean, [
				[COM.CategoryAttribute,"New Document Defaults"],
				[COM.DisplayNameAttribute,"Tabulator Indents"],
				[COM.DescriptionAttribute,"Sets if tabulator will indent based on last line or not."]
			 ]],
		BackSpaceUnindents : [ System.Boolean, [
				[COM.CategoryAttribute,"New Document Defaults"],
				[COM.DisplayNameAttribute,"Tabulator Unindents"],
				[COM.DescriptionAttribute,"Sets if backspace unindents or just removes last character."] 
			 ]],
		TabWidth : [ System.Int32, [
				[COM.CategoryAttribute,"New Document Defaults"],
				[COM.DisplayNameAttribute,"Tabulator Width"],
				[COM.TypeConverterAttribute, TabulatorConverter],
				[COM.DescriptionAttribute,"Number of whitespaces charactes that corresponds to one tab character."] 
			 ]],
		ShowLineNumbers : [ System.Boolean, [
				[COM.CategoryAttribute,"New Document Defaults"],
				[COM.DisplayNameAttribute,"Show Linenumbers"],
				[COM.DescriptionAttribute,"Display Line Numbers or not."] 
			 ]],

		Exports : [ System.Object, [
				[COM.CategoryAttribute,"Import / Export"],
				[COM.DisplayNameAttribute,"Export Settings"],
				[COM.DescriptionAttribute,"Export User Settings as XML to file."] ,
				[COM.EditorAttribute, CommandEditor, Design.UITypeEditor]
			 ]],
		Imports : [ System.Object, [
				[COM.CategoryAttribute,"Import / Export"],
				[COM.DisplayNameAttribute,"Import Settings"],
				[COM.DescriptionAttribute,"Import User Settings as XML from file."] ,
				[COM.EditorAttribute, CommandEditor, Design.UITypeEditor]
			 ]],
		Fileassoc : [ System.Object, [
				[COM.CategoryAttribute,"File Associations"],
				[COM.DisplayNameAttribute,"File Associations"],
				[COM.DescriptionAttribute,"Edit moe File Associations."] ,
				[COM.EditorAttribute, CommandEditor, Design.UITypeEditor]
			 ]]
		}
	},
	{}
);


/*
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
*/

var Style = net.Declare( "Moe.Style", {
	attributes : [[COM.DefaultPropertyAttribute,"Fontname"]], 
	properties : {
		Id  : [ System.Int32 ],
		Description : [ System.String, [
				[COM.DescriptionAttribute,"Style Name"],
				[COM.ReadOnlyAttribute,true]
			 ]],
		Bold : [ System.Boolean],
		Italic : [ System.Boolean],
		Eol : [ System.Boolean],
		Fontname 	: [ System.String ],
		Fontsize 	: [ System.Int32, [[COM.DisplayNameAttribute,"Size"]] ],
		Forecolor 	: [ System.String ],
		Backcolor 	: [ System.String ]
		}
	},
	{}
);


////////////////////////////////////////////////////////////


var Model = (function(){

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

	var model = {

		styles		: null,
		syntax  	: initialSyntax,
		font 		: initialFont,
		datasource	: bs,
		modes		: syntaxList,

		defaults : new DocumentDefaults(),
		defaultTabValues : net.Array( System.Int32, [2,4,6,8] ),
//selectedConfig : null,
		selectedSetting : null,

		fetch : function(conf,path,parent,handler)
		{
			for ( var i = 0; i < conf.Count(); i++ ) {

				var item = conf(i);
				var entry = handler(item,path,parent);

				if ( item && item.Count() > 0 )	{
					Model.fetch( item, path + "/" + item.key, entry, handler );
				}
			}
		},

		selectPath : function(path) {

			var conf = Config.Settings.Find(path);

			var set = new Settings();
			set.Key = conf.Key;
			set.Value = conf.Value;
			set.Path = path;

			this.selectedSetting = set;
			return set;
		},

		persistSelectedSettings : function() {

			var conf = Config.Settings.Find(this.selectedSetting.Path);
			conf.Key = this.selectedSetting.Key;
			conf.Value = this.selectedSetting.Value;
		},

		persistDefaultProperty : function(name) {
				
			moe.Config[name] = this.defaults[name];
		},

		htmlColor : function(col) {

			return System.String.Format("#{0:X2}{1:X2}{2:X2}", col.R, col.G, col.B);
		},

		makeStyleList : function( styleSet ) {

			var list = new System.Collections.ArrayList();
			for ( var i = 0; i < styleSet.Count; i++)
			{
				var s = new net.Runtime.Moe.Style();
				net.copyTo(styleSet.Item(i),s);
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

	model.defaults.TabUsage = Config.TabUsage;
	model.defaults.TabIndents=Config.TabIndents;
	model.defaults.BackSpaceUnindents=Config.BackSpaceUnindents;
	model.defaults.TabWidth=Config.TabWidth;
	model.defaults.ShowLineNumbers=Config.ShowLineNumbers;

	return model;
}());

var View = {

	form 			: new Forms.Form(),
	propGrid 		: new Forms.PropertyGrid(),
	tabControl  	: new Forms.TabControl(),
	tabPage1		: new Forms.TabPage(),
	tabPage2		: new Forms.TabPage(),
	tabPage3		: new Forms.TabPage(),
    treeView 		: new Forms.TreeView(),
    splitter 		: new Forms.Splitter(),
	panelSetting	: new Forms.Panel(),
	propGridSetting : new Forms.PropertyGrid(),
	panelButtons	: new Forms.Panel(),
	buttonNew		: new Forms.Button(),
	buttonDelete	: new Forms.Button(),
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

	init : function(data,syntax) {

		Forms.Application.EnableVisualStyles();
		this.form.SuspendLayout();
		this.form.ClientSize = Drawing.Size(484, 362);
		this.tabControl.Dock = Forms.DockStyle.Fill;
		//this.tabControl.Padding = Forms.Padding(5,5,5,5);

		this.tabPage1.Text = "Options";
		this.tabPage1.Padding = Forms.Padding(10);

		this.propGrid.Dock = Forms.DockStyle.Fill;
		this.propGrid.SelectedObject = data;
		this.propGrid.ToolbarVisible = false;
		this.tabPage1.Controls.Add(this.propGrid);

		this.tabPage2.Text = "User Settings";
		this.tabPage2.Padding = Forms.Padding(10);
		this.treeView.Dock = Forms.DockStyle.Left;
		this.treeView.HideSelection = false;
		this.splitter.Dock = Forms.DockStyle.Left;

		this.panelSetting.Dock = Forms.DockStyle.Fill;

		this.panelButtons.Dock = Forms.DockStyle.Bottom;
		this.panelButtons.Size = Drawing.Size(200, 40);

		this.buttonNew.Text="New";
		this.buttonNew.Anchor = Forms.AnchorStyles.Right;
		this.buttonNew.Location = Drawing.Point(50,10);
		this.buttonNew.Size = Drawing.Size(60,24);

		this.buttonDelete.Text="Delete";
		this.buttonDelete.Anchor = Forms.AnchorStyles.Right;
		this.buttonDelete.Location = Drawing.Point(130,10);
		this.buttonDelete.Size = Drawing.Size(60,24);

		this.propGridSetting.Dock = Forms.DockStyle.Fill;
		this.propGridSetting.ToolbarVisible = false;

		this.tabPage3.Text = "Editor Styles";
		this.tabPage3.Padding = Forms.Padding(10,0,10,10);
		this.combo.Location = new Drawing.Point(0, 10);
		this.combo.Size = new Drawing.Size(100, 21);
		this.combo.DataSource = Model.modes;

		this.text.Location = new Drawing.Point(150, 10);
		this.text.Size = new Drawing.Size(305, 20);

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

		this.tabPage3.Controls.Add(this.data);
		this.tabPage3.Controls.Add(this.panelBottom);
		this.tabPage3.Controls.Add(this.panelTop);

		this.panelButtons.Controls.Add(this.buttonNew);
		this.panelButtons.Controls.Add(this.buttonDelete);
		this.panelSetting.Controls.Add(this.propGridSetting);
		this.panelSetting.Controls.Add(this.panelButtons);
		this.tabPage2.Controls.Add(this.panelSetting);

		this.tabPage2.Controls.Add(this.splitter);
		this.tabPage2.Controls.Add(this.treeView);

		this.tabControl.Controls.Add(this.tabPage1);
		this.tabControl.Controls.Add(this.tabPage2);
		this.tabControl.Controls.Add(this.tabPage3);

		this.form.Controls.Add(this.tabControl);
		this.form.ResumeLayout(false);
		this.form.Show();
		this.form.Activate();
		this.form.Refresh();

		this.combo.SelectedIndex = syntax;
	}
};

var Controller = {

	run : function() {

		Model.updateDatasource(Model.syntax);

		View.init(Model.defaults,Model.syntax);

		Model.fetch( moe.Config.Settings, "", View.treeView, function(item,path,parent) {

			var node = new Forms.TreeNode(item.Key);
			node.Tag = path + "/" + item.Key;
			parent.Nodes.Add( node );
			return node;
		});

		var binding = new Forms.Binding("Text", Model.datasource, "Description", false);
		View.text.DataBindings.Add(binding);

		binding = new Forms.Binding("Font", Model.font, "Value", false);
		View.text.DataBindings.Add(binding);

		View.data.DataSource = Model.datasource;		

		View.combo.On("SelectedIndexChanged", Controller.OnSelectedIndexChanged );
		View.data.On( "SelectionChanged", Controller.OnSelectionChanged );
		View.data.On( "CellContentClick", Controller.OnCellContentClick );

		View.buttonApply.On("Click", Controller.OnApplyClick );
		View.buttonDefault.On("Click", Controller.OnDefaultClick );		

		Model.defaults.On("PropertyChanged", Controller.OnDefaultPropertyChanged);
		View.buttonNew.On("Click", Controller.OnNewTreeItem);
		View.buttonDelete.On("Click", Controller.OnDeleteTreeItem);
		View.treeView.On("AfterSelect", Controller.OnSelectTreeItem);

		View.data.Columns.get_Item(0).Visible = false;
		View.data.Columns.get_Item(1).Width=100;
		View.data.Columns.get_Item(2).Width=40;
		View.data.Columns.get_Item(3).Width=40;
		View.data.Columns.get_Item(4).Width=40;
		View.data.Columns.get_Item(5).Width=80;
		View.data.Columns.get_Item(6).Width=25;
		View.data.Columns.get_Item(7).Width=55;
		View.data.Columns.get_Item(8).Width=55;

		View.data.AutoResizeColumns(Forms.DataGridViewAutoSizeColumnsMode.ColumnHeader);		
		View.data.Refresh();

		Forms.Application.Run(View.form);
	},

	OnSelectTreeItem : function() {

		var path = View.treeView.SelectedNode.Tag;

		var set = Model.selectPath(path);
		set.On("PropertyChanged", Controller.OnTreePropertyChanged );
		View.propGridSetting.SelectedObject = set;
	},

	OnNewTreeItem : function() {

		if(!Model.selectedSetting)
			return;

		var conf = Config.Settings.Find(Model.selectedSetting.Path);

		var item = conf.New("New Key","");

		var set = new Settings();
		set.Key = item.Key;
		set.Value = item.Value;
		set.Path = Model.selectedSetting.Path + "/" + set.Key;

		var node = new Forms.TreeNode(item.Key);
		node.Tag = set.Path;
		View.treeView.SelectedNode.Nodes.Add( node );

		Model.selectedSetting = set;
	},

	OnDeleteTreeItem : function() {

		if(!Model.selectedSetting)
			return;

		var conf = Config.Settings.Find(Model.selectedSetting.Path);

		if ( conf.KeyReadOnly || conf.ValueReadOnly )
			return;

		var r = Forms.MessageBox.Show(  View.form,
						"really delete <" + conf.Key + "> ?",
						"confirm delete",
						Forms.MessageBoxButtons.OKCancel,
						Forms.MessageBoxIcon.Question
					);		

		if ( r.Equals(Forms.DialogResult.OK) ) {

			conf.Remove();
			View.treeView.SelectedNode.Parent.Nodes.Remove(View.treeView.SelectedNode);
		}
	},

	OnDefaultPropertyChanged : function(s,e) {

		Model.persistDefaultProperty(e.PropertyName);
	},

	OnTreePropertyChanged : function(s,e) {

		Model.persistSelectedSettings();
		View.form.Text = e.PropertyName;
	},

	OnExports : function(value) {

		var saveFileDialog = new Forms.SaveFileDialog();
		if(saveFileDialog.ShowDialog().Equals(Forms.DialogResult.OK))
		{
			moe.Config.ExportSettings(saveFileDialog.FileName);
			value = saveFileDialog.FileName;
		}
		return value;
	},

	OnImports : function(value) {

		var openFileDialog = new Forms.OpenFileDialog();
		if(openFileDialog.ShowDialog().Equals(Forms.DialogResult.OK))
		{
			moe.Config.ImportSettings(openFileDialog.FileName);
			value = openFileDialog.FileName;
		}
		return value;
	},

	OnFileassoc : function(value) {

		moe.Config.EditFileAssociations();
		return value;
	},

	OnSelectedIndexChanged : function() {

		Model.updateDatasource(View.combo.SelectedIndex);
	},

	OnSelectionChanged : function() {

		Model.updateFont();
		View.updateTextControl(Model.datasource);
	},

	OnCellContentClick : function(s,e) {

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

	OnApplyClick : function() {

		var styleSet = ActiveDoc.Object.Properties.StyleSets(View.combo.SelectedIndex);
		for ( var i = 0; i < Model.styles.Count; i++)
		{		
			net.copyTo(Model.styles.Item(i),styleSet.Item(i));
		}
		ActiveDoc.Object.Properties.Syntax = ActiveDoc.Object.Properties.Syntax;
	},

	OnDefaultClick : function() {

		var styleSet = moe.Config.StyleSets(View.combo.SelectedIndex);
		net.copyTo(Model.datasource.Current, styleSet.Item(View.combo.SelectedIndex));
	}
};

Controller.run();

