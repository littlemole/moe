
var mode = "Scintilla";
var tab = "main";

var api = {

	init : function() {

		// get encodings
	},

	getSetting : function() {

		let json = window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.JSON;
		return JSON.parse(json);
	},


	getEncondings : function() {

		let json = window.chrome.webview.hostObjects.sync.external.Moe.Config.GetEncodings();
		return JSON.parse(json);
	},

	openFileMenu : function() {

		window.chrome.webview.hostObjects.sync.external.Moe.Script.ShowHtmlForm(
			"C:\\Users\\mike\\source\\repos\\windot\\file.html",
			window.chrome.webview.hostObjects.sync.external.Moe.View.Left+20,
			window.chrome.webview.hostObjects.sync.external.Moe.View.Top+60,
			600,
			400,
			0
		);
	},

	newFile : function() {

		window.chrome.webview.hostObjects.sync.external.Moe.Documents.New();
	},

	openFile : function() {

		window.chrome.webview.hostObjects.sync.external.Moe.Dialogs.Open("");
	},

	openFolder : function() {

		window.chrome.webview.hostObjects.sync.external.Moe.Dialogs.OpenDir();
	},

	openUrl : function() {

		// TODO not impl
		//window.chrome.webview.hostObjects.sync.external.Moe.Dialogs.OpenUrl();
	},

	save : function() {
		window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Save();
	},

	saveAs : function() {

		// Todo: not impl, existinf api requires filepath. have a saveTo and a saveAs api in future!
		//window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.SaveAs();
	},

	cut : function() {

		window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Cut();
	},

	copy : function() {

		window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Paste();
	},

	paste : function() {

		window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Paste();
	},

	pasteAs : function() {

		// todo : not impl
		//window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Paste();
	},


	find : function() {

		// todo : not impl
		//window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Paste();
	},

	replace : function() {

		// todo : not impl
		//window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Paste();
	},

	color : function() {

		window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.ShowInsertColorDialog();
	},

	color : function() {

		window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.ShowInsertColorDialog();
	},

	print : function() {

		window.chrome.webview.hostObjects.sync.external.Moe.Print();		
	},

	syntax : function() {

		let s = document.getElementById("syntax").value;
		window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Syntax(s);		
	},

	eol : function() {

		let e = document.getElementById("eol").value;
		window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Eol(e);		
	},

	encoding : function() {

		let e = document.getElementById("encoding").value;
		window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Syntax(e);		
	},

	properties : function() {

		// ??
	},

	showExplorer : function(b) {

		window.chrome.webview.hostObjects.sync.external.Moe.View.ShowTreeView(b);		

	},

	close : function() {

		window.chrome.webview.hostObjects.sync.external.Moe.Documents.Close(b);		
	},

	closeAll : function() {

		window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.View.Close();		
	},

	quit : function() {

		window.chrome.webview.hostObjects.sync.external.Moe.Exit();	
	},

	insertTemplate : function() {

		//window.chrome.webview.hostObjects.sync.external.Moe.Exit();	

	},

	formatJSON : function() {

		//window.chrome.webview.hostObjects.sync.external.Moe.Exit();	

	},

	formatXML : function() {

		//window.chrome.webview.hostObjects.sync.external.Moe.Exit();	

	},

	encodeBase64 : function() {

	},

	decodeBase64 : function() {

	},

	encodeURIcomponent : function() {

	},

	runScript : function() {
	},

	debugScript : function () {
	},

	pauseScript : function () {
	},

	stopScript : function () {
	},

	stepScript : function () {
	},

	stepInScript : function () {
	},

	stepOutScript : function () {
	},
	
	showHTML : function() {
	},

	admin : function() {
	},

	certificates : function() {
	},

	mapDrive : function()  {
	},

	writeBOM : function() {
	},

	showLineEndings : function(b) {
	},

	settings : function(b) {
	},

	useTabse : function() {
	},

	tabIndents : function() {
	},

	backspaceUnindents : function() {
	},

	tabSize : function() {
	},

	convertTabs : function() {
	},

	parentDir : function() {
	},

	execute : function() {
	},

	createFolder : function() {
	},

	reload : function() {
	},

	back : function() {
	},

	next : function() {
	},

	showBytes : function() {
	},
};


function setApplicationMode(m,t)
{
	mode = m;
	tab = t;

	let nodes = document.querySelectorAll("*[modes]");
	nodes.forEach(function(n) 
	{
		//alert(n.getAttribute("modes"));
		let modes = n.getAttribute("modes").split(" ");
		if(modes.includes(m))
		{
			let clazzes = Array.from(n.classList);
			let isFlex = clazzes.includes("flex");
			let s = isFlex ? "flex" : "block";

			tabs = n.getAttribute("tab");
			if(tabs)
			{
				tabs = tabs.split(" ");
				if(!tabs.includes(tab)) s = "none";
			}
			console.log(mode,tabs, tab);
			n.style.display = s;
		}		
		else 
		{
			n.style.display = "none";
		}
	});



  tablinks = document.getElementsByClassName("tablinks");
  for (i = 0; i < tablinks.length; i++) {
    tablinks[i].className = tablinks[i].className.replace(" active", "");
  }

  document.getElementById(tab).style.display = "flex";
  document.getElementById(tab).className += " active";
}


function onToggle(el)
{
	console.log(el);
	let status = el.getAttribute("status");

	if(status === "true" )
	{
		el.className = el.className.replace("active", "");
		el.setAttribute("status","false");
	}
	else
	{
		el.className += " active";
		el.setAttribute("status","true");
	}	
}


window.onload = function() {

	var modus = document.getElementById("mode");
	modus.onchange = function(e) {
		var m = modus.value;
		setApplicationMode(m,"main");
	};

	let toggles = Array.from(document.getElementsByClassName("toggle"));
	toggles.forEach(function(t)
	{
		t.onclick=function(){onToggle(this)};
	});


	document.getElementById("file").onclick = function() { api.openFileMenu(); };
	document.getElementById("main").onclick = function() { setApplicationMode(mode,'main'); };
	document.getElementById("run").onclick = function() { setApplicationMode(mode,'run')};
	document.getElementById("tools").onclick = function() { setApplicationMode(mode,'tools')};
	document.getElementById("document").onclick = function() { setApplicationMode(mode,'document')};

	setApplicationMode("Scintilla","main");
	document.getElementById("ribbon").style.display="block";
};



