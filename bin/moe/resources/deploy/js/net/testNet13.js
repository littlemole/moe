
var net = new NET();

var System = net.Import("System");

var Drawing = net.Import("System.Drawing");
var Forms = net.Import("System.Windows.Forms");
var Design = net.Import("System.Drawing.Design");
net.Import("System.Design");
net.Import("System.Core");

var ListOfStrings = System.Collections.Generic.List.of(System.String);
var ListOfInts = System.Collections.Generic.List.of(System.It32);


var defaultValues= net.Array( System.String, ["a","b","c"] );
var defaultIntValues= net.Array( System.Int32, [2,4,6,8] );

/*
var defaultValues = System.Array.CreateInstance( System.String, 3 );
defaultValues.SetValue("a",0);
defaultValues.SetValue("b",1);
defaultValues.SetValue("c",2);+
*/

var TypeConverter = System.ComponentModel.TypeConverter;
var StandardValuesCollection = TypeConverter.StandardValuesCollection;
var ITypeDescriptorContext = System.ComponentModel.ITypeDescriptorContext;
/*
var ITypeDescriptorContext = System.ComponentModel.ITypeDescriptorContext;
/*
net.Import("MyConverter");
var MyConverter = net.Runtime.MyConverter;

MyConverter.ScriptHandler =	{
		GetStandardValuesSupported : function(c) {
//Dialogs.MsgBox("hu","ha",0);
			return true;
		},
		GetStandardValues : function(c) {
//Dialogs.MsgBox("hu","ha",0);
			return new StandardValuesCollection(defaultValues);
		}
	};

var mc = new MyConverter();
Dialogs.MsgBox("","ha",0);
*/
/*
var cp = Forms.ControlPaint;


*/
var MyConverter = net.Declare(
	"MyConverter", 
	{
		inherits : System.ComponentModel.TypeConverter , 
		methods : {
			GetStandardValuesSupported : [ System.Boolean, [System.ComponentModel.ITypeDescriptorContext]],
			GetStandardValues : [ StandardValuesCollection, [System.ComponentModel.ITypeDescriptorContext]],
		}
	},
	{
		GetStandardValuesSupported : function(c) {
			return true;
		},
		GetStandardValues : function(c) {
			return new StandardValuesCollection(defaultValues);
		}
	}
);

var MyTabConverter = net.Declare(
	"MyTabConverter", 
	{
		inherits : System.ComponentModel.TypeConverter , 
		methods : {
			GetStandardValuesSupported : [ System.Boolean, [System.ComponentModel.ITypeDescriptorContext]],
			GetStandardValues : [ StandardValuesCollection, [System.ComponentModel.ITypeDescriptorContext]],
			CanConvertFrom : [ System.Boolean, [System.ComponentModel.ITypeDescriptorContext,System.Type]],
			ConvertFrom : [ System.Object, [System.ComponentModel.ITypeDescriptorContext,System.Globalization.CultureInfo,System.Object]]
		}
	},
	{
		GetStandardValuesSupported : function(c) {
			return true;
		},
		GetStandardValues : function(c) {
			return new StandardValuesCollection(defaultIntValues);
		},
		CanConvertFrom : function(ctx,type) {
//Dialogs.MsgBox(type.ToString(),"",0);
			if ( type.Equals(System.String) )
				return true;

Dialogs.MsgBox(type.ToString(),"false",0);
			return false;
		},
		ConvertFrom : function(ctx,culture,value) {
		//Dialogs.MsgBox(typeof(value),"",0);
			if ( typeof(value) == "string")
			{
//			var type = value.GetType();
	//		if ( type.Equals(System.String)) {
				return System.Int32.Parse(value);
			}
			return void(0);
		}
	}
);


var MySubType = net.Declare(
	"MySubType", 
	{
		inherits : System.Object, 
		attributes : [ ],//[System.ComponentModel.TypeConverterAttribute, System.ComponentModel.ExpandableObjectConverter] ], 
		properties : {
				avalue  : [ System.Int32//, [
							//[System.ComponentModel.DescriptionAttribute,"some description"] 
						 ]//]
				},
		methods : {}
	},
	{}
);
/*
Dialogs.MsgBox("","ha",0);
var CheckBoxEditorValue = net.Declare(
	"CheckBoxEditorValue", 
	{
		//inherits : Design.UITypeEditor, 
		attributes : [[System.Runtime.InteropServices.ComVisibleAttribute,true]],
		properties : {
					value : [System.Boolean, []]
				},
		methods : {
			ToString : [ System.String, []]
		}
	},
	{
		ToString : function() {
			//if (this.value) {
			//	return "On";
			//}
			return "Off";
		}
	}
);
*/


var CheckBoxEditor = net.Declare(
	"CheckBoxEditor", 
	{
		inherits : Design.UITypeEditor, 
		attributes : [[System.Runtime.InteropServices.ComVisibleAttribute,true]],
		properties : {},
		methods : {
			GetPaintValueSupported : [ System.Boolean, [System.ComponentModel.ITypeDescriptorContext]],
			PaintValue : [ void(0), [Design.PaintValueEventArgs]]
		}
	},
	{
		GetPaintValueSupported : function(c) {
				return true;
		},
		PaintValue : function(a) {

//				cp.DrawBorder3D(e.Graphics,e.Bounds,Forms.ButtonState.Checked);
//x = a;
				form.Text = a.Context.Instance.ToString();
				Forms.ControlPaint.DrawCheckBox(
						a.Graphics,
						a.Bounds,
						a.Context.Value == true ? Forms.ButtonState.Checked : Forms.ButtonState.Normal
					);

						//e.Context.Instance).Cb ? ButtonState.Checked : ButtonState.Normal);
		}
	}
);


var CommandEditor = net.Declare(
	"CommandEditor", 
	{
		inherits : Design.UITypeEditor, 
//		attributes : [[System.Runtime.InteropServices.ComVisibleAttribute,true]],
	//	properties : { },
		methods : {
			GetEditStyle : [ Design.UITypeEditorEditStyle, [ITypeDescriptorContext]],
			EditValue : [ System.Object, [ITypeDescriptorContext,System.IServiceProvider,System.Object]]
		}
	},
	{
		GetEditStyle : function(ctx) {
				return Design.UITypeEditorEditStyle.Modal;
		},
		EditValue : function(ctx,provider,value) {

			var openFileDialog = new Forms.OpenFileDialog();
			openFileDialog.Title = ctx.PropertyDescriptor.Name;
			if(openFileDialog.ShowDialog().Equals(Forms.DialogResult.OK))
			{
				value = openFileDialog.FileName;
			}
			return value;
		}
	}
);

 

var MyType = net.Declare(
	"TestClass", 
	{
		//inherits : System.Object, 
		implements : [  ], 
		attributes : [[System.ComponentModel.DefaultPropertyAttribute,"value2"]], //[System.Runtime.InteropServices.ComVisibleAttribute,true]],
		properties : {
				value  : [ MySubType, [
							[System.ComponentModel.DescriptionAttribute,"some description"],
							[System.ComponentModel.TypeConverterAttribute, System.ComponentModel.ExpandableObjectConverter] 
						 ]],
				value2 : [ System.Boolean, [
							[System.ComponentModel.CategoryAttribute,"cat1"],
							[System.ComponentModel.DescriptionAttribute,"another description"],
							//[System.ComponentModel.TypeConverterAttribute, System.ComponentModel.StringConverter] ,
							[System.ComponentModel.EditorAttribute, CheckBoxEditor, Design.UITypeEditor]
						 ]],
				tabwidth : [ System.Int32, [
							[System.ComponentModel.CategoryAttribute,"cat2"],
							[System.ComponentModel.DescriptionAttribute,"an int32"],
							[System.ComponentModel.TypeConverterAttribute, MyTabConverter] 
						]],
				schrift : [ Drawing.Font, [
							[System.ComponentModel.CategoryAttribute,"cat2"],
							[System.ComponentModel.DescriptionAttribute,"a font"] 
						 ]],		

				name2 : [ System.String, [
							[System.ComponentModel.TypeConverterAttribute,MyConverter],
							[System.ComponentModel.EditorAttribute, System.ComponentModel.Design.MultilineStringEditor, Design.UITypeEditor] 
						 ]],		

				name : [ System.String, [
//							[System.ComponentModel.CategoryAttribute,"cat2"],
//							[System.ComponentModel.DescriptionAttribute,"a font"],
							//[System.ComponentModel.EditorAttribute, Design.FontNameEditor, Design.UITypeEditor]        
							[System.ComponentModel.TypeConverterAttribute,MyConverter]
							
						 ]],			
				collection : [ ListOfStrings, [
							[System.ComponentModel.DisplayNameAttribute,"the list"],
							[System.ComponentModel.CategoryAttribute,"cat2"],
							[System.ComponentModel.DescriptionAttribute,"a collection"] 
						 ]],
				color : [ Drawing.Color, [
							[System.ComponentModel.CategoryAttribute,"cat2"],
							[System.ComponentModel.DescriptionAttribute,"a color"] 
						 ]],
				cmd1 : [ System.Object, [
							[System.ComponentModel.CategoryAttribute,"Commands"],
							[System.ComponentModel.DescriptionAttribute,"a cmd"],
							[System.ComponentModel.EditorAttribute, CommandEditor, Design.UITypeEditor]
						 ]],					
				cmd2 : [ System.Object, [
							[System.ComponentModel.CategoryAttribute,"Commands"],
							[System.ComponentModel.DescriptionAttribute,"another cmd"],
							[System.ComponentModel.EditorAttribute, CommandEditor, Design.UITypeEditor]
						 ]]					
				},

		methods : {
			test  : [ System.String, [] ],
			test2 : [ System.String, [System.String] ],
			test3 : [ System.String, [System.String,System.Int32] ],
			test4 : [],
			OnLoad : [ undefined, [System.EventArgs]]
		}
	},
	{
		test : function() {
			return "1KILLROY WAS HERE! " + this.value;
		},
		test2 : function(txt) {
			return "2KILLROY WAS HERE! " + txt + ":"+ this.value2;
		},
		test3 : function(txt,val) {
			return "3ILLROY WAS HERE! " + txt + ":"+ val + this.value;
		},
		test4 : function() {
			this.value2 = false
		},
		OnLoad : function(e) {
			Dialogs.MsgBox("here","Ontest()",0);
		}
	}
);
Dialogs.MsgBox(typeof(net.Import),"nono",0);
var MyForm = net.Declare(
	"MyForm", 
	{
		inherits : Forms.Form, 
		implements : [  ], 
		attributes : [],
		constructors : { MyForm : [System.String] },
		properties : { value : [System.String] },
		methods : {
			OnLoad : [ undefined, [System.EventArgs]],
			Show : [undefined, [] ],
			OnClose : [ undefined, [] ]
			
		}
	},
	{
		MyForm : function(t) {
			this.value = t;
		},

		OnLoad : function(e) {
			Dialogs.MsgBox(this.value,"Ontest()",0);
		},
		Show : function(e) {
			//Dialogs.MsgBox("no show!","Ontest()",0);
			this.base.Show();
		},
		OnClose : function() {
				Dialogs.MsgBox("close","Ontest()",0);
				net.Exit();
				Quit();
		}
		
	}
);

var t = new net.Runtime.TestClass();


Dialogs.MsgBox(typeof(t),"false",0);

t.collection = new ListOfStrings();
t.collection.Add("one");
t.collection.Add("two");
t.collection.Add("three");

var form = new MyForm("hU");// Forms.Form();
form.ClientSize = Drawing.Size(384, 262);

var propGrid = new Forms.PropertyGrid();
propGrid.Dock = Forms.DockStyle.Fill;
propGrid.SelectedObject = t;
propGrid.ToolbarVisible = false;
propGrid.HelpVisible = false;

form.Controls.Add(propGrid);



t.On("PropertyChanged", function(s,e) {
	if ( t[e.PropertyName] )
		form.Text = "" + (t[e.PropertyName]);
	propGrid.Refresh();
});


t.value = new MySubType();
t.value.avalue = 42;
t.value2 = false;

form.Show();
form.Activate();

Wait();
