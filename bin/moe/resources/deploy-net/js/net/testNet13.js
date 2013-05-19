var net = new NET();
var System = net.Import("System");
var Drawing = net.Import("System.Drawing");
var Forms = net.Import("System.Windows.Forms");

net.Import("System.Core");

var ClassFactory = net.Runtime.org.oha7.dotnet.ClassFactory;

//var DOT = net.Runtime.org.oha7.dotnet.Net();
/*
var arrayEmptyTypes = System.Array.CreateInstance( System.Type, 0 );
var arrayAttributes = System.Array.CreateInstance( net.Runtime.org.oha7.dotnet.AttributeDef, 1 );

var arrayStringArgs1 = System.Array.CreateInstance( System.String, 1 );
arrayStringArgs1.SetValue( "value", 0 );
var arrayStringArgs2 = System.Array.CreateInstance( System.String, 1 );
arrayStringArgs2.SetValue( "a category", 0 );

Dialogs.MsgBox(ClassFactory.ToString(),"Ontest()",0);
var cat = new net.Runtime.org.oha7.dotnet.AttributeDef(System.ComponentModel.CategoryAttribute,arrayStringArgs2);
//Dialogs.MsgBox(cat.ToString(),"Ontest()",0);

arrayAttributes.SetValue( cat, 0 );
*/
//arrayStringArgs.SetValue( "a category", 0 );
//Dialogs.MsgBox(DOT.ToString(),"Ontest()",0);

Dialogs.MsgBox("go","Ontest()",0);

var MyType = net.Declare(
	"TestClass", 
	{
		//inherits : System.Object, 
		implements : [  ], 
		attributes : [ { type : System.ComponentModel.DefaultPropertyAttribute, args : [ "value" ] } ],
		properties : [
			{ name : "value", type : System.Int32, attributes : [] },
			{ name : "value2", type : System.String, attributes : [{ type : System.ComponentModel.CategoryAttribute, args : [ "cat1" ] }] }
			],
		methods : [
			{ name : "test", type : System.String, args : [] },
			{ name : "test2", type : System.String, args : [System.String] },
			{ name : "test3", type : System.String, args : [System.String,System.Int32] },
			{ name : "test4", type : undefined, args : [] }
		]
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
		}
	}
);

/*
var MyType = net.Declare(
	"TestClass", 
	{
		//inherits : System.Object, 
		implements : [  ], 
		attributes : [[System.ComponentModel.DefaultPropertyAttribute, "value" ]],
		properties : {
				value  : [ System.Int32 ],
				value2 : [ System.String, [[System.ComponentModel.CategoryAttribute,"cat1"]] ],
			},
		methods : {
			test  : [ System.String, [] ],
			test2 : [ System.String, [System.String] ],
			test3 : [ System.String, [System.String,System.Int32] ],
			test4 : [ ]
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
		}
	}
);
*/

//Dialogs.MsgBox(MyType.ToString(),"Ontest()",0);

//var t = new MyType();
var t = new net.Runtime.TestClass();
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

	Forms.MessageBox.Show("killroy was here!");
};

Dialogs.MsgBox(t.ToString(),"Ontest()",0);
t.value = 42;
t.value2 = "harhar";

var r = t.test();

Dialogs.MsgBox(r,"t.test()",0);

r = t.test2("huhu");

Dialogs.MsgBox(r,"t.test2()",0);

r = t.test3("huhu",4711);
Dialogs.MsgBox(r,"t.test3()",0);

t.test4();
Dialogs.MsgBox(t.value2,"t.test4()",0);

/*
var ListOfString = System.Collections.Generic.List.of(System.String);
var list = new ListOfString();
list.Add("11");
list.Add("2");


Dialogs.MsgBox(list.Item(0),"hm",0);

var a = System.Array.CreateInstance( System.String, 2 );

a.SetValue("a",0);
a.SetValue("b",1);

Dialogs.MsgBox(a.GetValue(1),"hm",0);
*/

var form = new Forms.Form();
form.ClientSize = Drawing.Size(284, 262);

var propGrid = new Forms.PropertyGrid();
propGrid.Size = Drawing.Size.New(264, 252);
propGrid.Dock = Forms.DockStyle.Fill;
propGrid.SelectedObject = t;

form.Controls.Add(propGrid);
form.Show();
form.Activate();
Forms.Application.Run(form);

