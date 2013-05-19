var net = new NET();
var System = net.Import("System");
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
			{ name : "test", type : System.String, args : [] }
		]
	},
	{
		test : function(that) {
			return "KILLROY WAS HERE! " + that.value;
		}
	}
);

/*
var MyType = net.Declare(

	"TestClass", {

	    def : {
			base 		: System.Object, // optional, default System.Object
			interfaces  : [ System.Type, ], // optional, INotifyPropertyChanged auto
			attributes  : [ { type: System.Attribute, args : [ System.Type ]  }, ] // optional
			properties  : {			// optional
				"propertyName" : {
					type: System.Type,
					attributes : [ { type: System.Attribute, args : [ System.Type ]  }, ] // optional
				},
			},
			methods     : {
				"methodName" : {
					type : System.Type, 		// return type
					args : [ System.Type, ] 	// parameter types
				},
			}
	    },

	    impl : {

			"methodName" : function( that, args... ) {
				return ; // System.Type 
			},
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

Dialogs.MsgBox(t.ToString(),"Ontest()",0);
t.value = 42;

var r = t.test();

Dialogs.MsgBox(r,"t.test()",0);


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



