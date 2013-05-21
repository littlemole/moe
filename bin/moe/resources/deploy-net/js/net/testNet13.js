var net = new NET();
var System = net.Import("System");
var Drawing = net.Import("System.Drawing");
var Forms = net.Import("System.Windows.Forms");
var Design = net.Import("System.Drawing.Design");

net.Import("System.Core");


var ClassFactory = net.Runtime.org.oha7.dotnet.ClassFactory;

var defaultValues = System.Array.CreateInstance( System.String, 3 );
defaultValues.SetValue("a",0);
defaultValues.SetValue("b",1);
defaultValues.SetValue("c",2);


var TypeConverter = System.ComponentModel.TypeConverter;
var StandardValuesCollection = TypeConverter.StandardValuesCollection;

Dialogs.MsgBox(StandardValuesCollection.ToString(),"ha",0);
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
*/
//var mc = new MyConverter();
//Dialogs.MsgBox(mc.ToString(),"ha",0);

var MyConverter = net.Declare(
	"MyConverter", 
	{
		inherits : System.ComponentModel.StringConverter , 
		implements : [  ], 
		attributes : [],
		properties : {},
		methods : {
			GetStandardValuesSupported : [ System.Boolean, [System.ComponentModel.ITypeDescriptorContext]],
			GetStandardValues : [ StandardValuesCollection, [System.ComponentModel.ITypeDescriptorContext]],
		}
	},
	{
		GetStandardValuesSupported : function(c) {
//Dialogs.MsgBox("hu","ha",0);
			return true;
		},
		GetStandardValues : function(c) {
Dialogs.MsgBox("hu","ha",0);
			return new StandardValuesCollection(defaultValues);
		}
	}
);


var MyType = net.Declare(
	"TestClass", 
	{
		//inherits : System.Object, 
		implements : [  ], 
		attributes : [[System.ComponentModel.DefaultPropertyAttribute,"value2"]],
		properties : {
				value  : [ System.Int32, [
							[System.ComponentModel.DescriptionAttribute,"some description"] 
						 ]],
				value2 : [ System.String, [
							[System.ComponentModel.CategoryAttribute,"cat1"],
							[System.ComponentModel.DescriptionAttribute,"another description"] 
						 ]],
				wahr : [ System.Boolean, [
							[System.ComponentModel.CategoryAttribute,"cat2"],
							[System.ComponentModel.DescriptionAttribute,"a boolean"] 
						 ]],
				schrift : [ Drawing.Font, [
							[System.ComponentModel.CategoryAttribute,"cat2"],
							[System.ComponentModel.DescriptionAttribute,"a font"] 
						 ]],				

				name : [ System.String, [
//							[System.ComponentModel.CategoryAttribute,"cat2"],
//							[System.ComponentModel.DescriptionAttribute,"a font"],
							//[System.ComponentModel.EditorAttribute, Design.FontNameEditor, Design.UITypeEditor]        
							
						 ]],			

				color : [ Drawing.Color, [
							[System.ComponentModel.CategoryAttribute,"cat2"],
							[System.ComponentModel.DescriptionAttribute,"a color"] 
						 ]],				
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
			this.value2 = "changed!";
		},
		OnLoad : function(e) {
			Dialogs.MsgBox("here","Ontest()",0);
		}
	}
);

var MyForm = net.Declare(
	"MyForm", 
	{
		inherits : Forms.Form, 
		implements : [  ], 
		attributes : [],
		properties : {},
		methods : {
			OnLoad : [ undefined, [System.EventArgs]]
		}
	},
	{
		OnLoad : function(e) {
			Dialogs.MsgBox("here!!!!!!!!!!!!!!!!!","Ontest()",0);
		}
	}
);

var t = new net.Runtime.TestClass();

var form = new MyForm();// Forms.Form();
form.ClientSize = Drawing.Size(384, 262);

var propGrid = new Forms.PropertyGrid();
propGrid.Dock = Forms.DockStyle.Fill;
propGrid.SelectedObject = t;

form.Controls.Add(propGrid);


/*
net.Runtime.TestClass.ScriptHandler = {
	test : function() {
		//Dialogs.MsgBox("here","Ontest()",0);
		//return that.ToString();
		return "KILLROY WAS HERE! ";// + that.value;
	}
};
*/

t.On("PropertyChanged", function(s,e) {
	if ( t[e.PropertyName] )
		form.Text = "" + (t[e.PropertyName]);
	propGrid.Refresh();
});



form.Show();
form.Activate();

t.value = 42;
Sleep(1000);
t.value2 = "harhar";
form.Text = t.test();
Sleep(1000);

form.Text = t.test2("huhu");
Sleep(1000);

form.Text = t.test3("huhu",4711);
Sleep(1000);

form.Text = t.test4();
Sleep(1000);



Forms.Application.Run(form);


