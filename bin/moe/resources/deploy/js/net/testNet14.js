
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
	attributes : [[COM.DefaultPropertyAttribute,"tabWidth"]], 
	properties : {
		useTabs  : [ System.Boolean, [
				[COM.DescriptionAttribute,"Specify whether to use tabulators or to convert tab strokes to whitespace rightaway."],
				[COM.DisplayNameAttribute,"Use Tabulators"],
				[COM.CategoryAttribute,"New Document Defaults"]
			 ]],
		tabIndents : [ System.Boolean, [
				[COM.CategoryAttribute,"New Document Defaults"],
				[COM.DisplayNameAttribute,"Tabulator Indents"],
				[COM.DescriptionAttribute,"Sets if tabulator will indent based on last line or not."]
			 ]],
		backspaceUnindents : [ System.Boolean, [
				[COM.CategoryAttribute,"New Document Defaults"],
				[COM.DisplayNameAttribute,"Tabulator Unindents"],
				[COM.DescriptionAttribute,"Sets if backspace unindents or just removes last character."] 
			 ]],
		tabwidth : [ System.Int32, [
				[COM.CategoryAttribute,"New Document Defaults"],
				[COM.DisplayNameAttribute,"Tabulator Width"],
				[COM.TypeConverterAttribute, TabulatorConverter],
				[COM.DescriptionAttribute,"Number of whitespaces charactes that corresponds to one tab character."] 
			 ]],
		showLineNumbers : [ System.Boolean, [
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

////////////////////////////////////////////////////////////


var Model = (function(){

	var model = {

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
		}
	};

	model.defaults.useTabs=true;
	model.defaults.tabIndents=true;
	model.defaults.backspaceUnindents=false;
	model.defaults.tabwidth=4;
	model.defaults.showLineNumbers=false;

	return model;
}());

var View = {

	form 			: new Forms.Form(),
	propGrid 		: new Forms.PropertyGrid(),
	tabControl  	: new Forms.TabControl(),
	tabPage1		: new Forms.TabPage(),
	tabPage2		: new Forms.TabPage(),
    treeView 		: new Forms.TreeView(),
    splitter 		: new Forms.Splitter(),
	panelSetting	: new Forms.Panel(),
	propGridSetting : new Forms.PropertyGrid(),
	panelButtons	: new Forms.Panel(),
	buttonNew		: new Forms.Button(),
	buttonDelete	: new Forms.Button(),

	init : function(data) {

		Forms.Application.EnableVisualStyles();
		this.form.ClientSize = Drawing.Size(484, 362);
		this.tabControl.Dock = Forms.DockStyle.Fill;

		this.tabPage1.Text = "Options";

		this.propGrid.Dock = Forms.DockStyle.Fill;
		this.propGrid.SelectedObject = data;
		this.propGrid.ToolbarVisible = false;
		this.tabPage1.Controls.Add(this.propGrid);

		this.tabPage2.Text = "User Settings";

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

		this.panelButtons.Controls.Add(this.buttonNew);
		this.panelButtons.Controls.Add(this.buttonDelete);
		this.panelSetting.Controls.Add(this.propGridSetting);
		this.panelSetting.Controls.Add(this.panelButtons);
		this.tabPage2.Controls.Add(this.panelSetting);

		this.tabPage2.Controls.Add(this.splitter);
		this.tabPage2.Controls.Add(this.treeView);

		this.tabControl.Controls.Add(this.tabPage1);
		this.tabControl.Controls.Add(this.tabPage2);

		this.form.Controls.Add(this.tabControl);
		this.form.Show();
		this.form.Activate();
		this.form.Refresh();
	}
};

var Controller = {

	run : function() {

		View.init(Model.defaults);
		Model.fetch( moe.Config.Settings, "", View.treeView, function(item,path,parent) {

			var node = new Forms.TreeNode(item.Key);
			node.Tag = path + "/" + item.Key;
			parent.Nodes.Add( node );
			return node;
		});

		Model.defaults.On("PropertyChanged", Controller.OnDefaultPropertyChanged);
		View.buttonNew.On("Click", Controller.OnNewTreeItem);
		View.buttonDelete.On("Click", Controller.OnDeleteTreeItem);
		View.treeView.On("AfterSelect", Controller.OnSelectTreeItem);

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

		View.form.Text = e.PropertyName;
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
	}
};

Controller.run();


