//////////////////////////////////////////////////////////////////////////////
// initialize .NET
//////////////////////////////////////////////////////////////////////////////

var net = new NET();

var System = net.Import("System");
net.Import("System.Core");
net.Import("PresentationFramework");

//////////////////////////////////////////////////////////////////////////////
// load XAML and start wpf
//////////////////////////////////////////////////////////////////////////////

var xaml =  new net.Runtime.org.oha7.dotnet.XAML();
xaml.load("test.xaml");

//////////////////////////////////////////////////////////////////////////////
// type declarations
//////////////////////////////////////////////////////////////////////////////

// generic collection Type declaration used for data binding
var ObservableCollection = System.Collections.ObjectModel.ObservableCollection.of(System.Object);

// declare .NET type for View Model data binding
net.Runtime.Moe.Setting = { 
	key      : System.String,
	value    : System.String,
	path     : System.String,
	children : ObservableCollection,
	parent   : System.Object
};

// handy javascript constructor for above .NET type
// arguments:
// 		- item - COM Setting object to initialize values from
//		- root - .NET parent element for this setting, pass null to indicate root

var Setting = function(item,root) {

	var entry = new net.Runtime.Moe.Setting();
	entry.key = item.Key;
	entry.value = item.Value;
	entry.children = new ObservableCollection();
	entry.parent = root;
	if ( root ) {
		entry.path = root.path + "/" + item.Key ;
	}
	else {
		entry.path = "";
	}
	return entry;
};

//////////////////////////////////////////////////////////////////////////////
// the Model
//////////////////////////////////////////////////////////////////////////////

var Model = (function() {

	// populate View Data model from moe COM Config
	var fetch = function(conf,parent)
	{
		for ( var i = 0; i < conf.Count(); i++ ) {

			var item = conf(i);
			var entry = new Setting(item,parent);

			if ( item.Count() > 0 )	{
				fetch( item, entry );
			}
			parent.children.Add(entry);
		}
	};

	// persist ViewModel and update moe COM Config
	var persist = function(conf,root)
	{
		if ( !conf.KeyReadOnly ) { 
			conf.Key = root.key;
		}

		if ( !conf.ValueReadOnly ) {
			conf.Value = root.value;
		}

		root.path = root.parent.path + "/" + root.key;

		for ( var i = 0; i < conf.Count(); i++ ) {			
			persist( conf(i), root.children.Item(i) );
		}
	};

	// initial data preparation
	var config = new Setting(Config.Settings,null);
	fetch( Config.Settings, config);

	// return the public Model interface
	return {
		Config 	: config,
		persist : persist,
		fetch 	: fetch
	};
}());

//////////////////////////////////////////////////////////////////////////////
// The View
//////////////////////////////////////////////////////////////////////////////

var View = {

	page  		:	xaml.get("page"),
	buttClose  	: 	xaml.get("buttonClose"),
	buttNew  	:	xaml.get("buttonNew"),
	buttDelete  : 	xaml.get("buttonDelete"),
	tree  		:	xaml.get("tree"),
	textKey		:	xaml.get("textKey"),
	textValue	:	xaml.get("textValue"),

	init : function(conf) {

		xaml.window.Width  = 500;
		xaml.window.Height = 300;
		xaml.window.Title = "Edit Moe User Settings";

		this.page.DataContext = conf;
	}
};

//////////////////////////////////////////////////////////////////////////////
// The Controller
//////////////////////////////////////////////////////////////////////////////

var Controller = {

	// main function. hook up view with controller and run the whole thing
	run : function() {	

		View.init( Model.Config );	

		View.buttNew.On(	"Click", Controller.onNewSetting );
		View.buttDelete.On(	"Click", Controller.onDeleteSetting );
		View.buttClose.On(	"Click", Controller.onClose );

		View.textKey.On(	"LostFocus", Controller.onLostFocus );
		View.textValue.On(	"LostFocus", Controller.onLostFocus );

		xaml.run();
	},

	// Controller event handlers:

	onNewSetting : function(s,e) {

		var item = Config.Settings.Find(View.tree.SelectedItem.path );
		if ( !item.ChildrenAllowed )
			return;

		var set = item.New("new key","");

		var entry = new Setting(set, View.tree.SelectedItem);
		View.tree.SelectedItem.children.Add(entry);
	},

	onDeleteSetting : function(s,e) {

		var item = Config.Settings.Find(View.tree.SelectedItem.path);
		if ( item.KeyReadOnly || item.ValueReadOnly )
			return;

		var r = System.Windows.MessageBox.Show( 
						"really delete <" + item.Key + "> ?",
						"confirm delete",
						System.Windows.MessageBoxButton.OKCancel,
						System.Windows.MessageBoxImage.Question
					);

		if ( r.Equals(System.Windows.MessageBoxResult.OK) ) {

			View.tree.SelectedItem.parent.children.Remove(View.tree.SelectedItem);
			item.Remove();
		}
	},

	onClose : function(s,e) {

		xaml.exit();
	},

	onLostFocus : function(s,e) {

		var item = Config.Settings.Find(View.tree.SelectedItem.path );
		if ( item.KeyReadOnly || item.ValueReadOnly )
			return;		

		Model.persist(item, View.tree.SelectedItem);
	}
};

// call controller main function now
Controller.run();
