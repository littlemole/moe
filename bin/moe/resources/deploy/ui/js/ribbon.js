
var mode = "Scintilla";
var tab = "main";

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
	let status = el.getAttribute("status");

	el.className = el.className.replace(" active", "");
	if(status === "true" )
	{
		el.setAttribute("status","false");
	}
	else
	{
		el.className += " active";
		el.setAttribute("status","true");
	}	
}

function onMessage(e) {

	let msg = e.data;

	//console.log(JSON.stringify(msg));
	if("appmode" in msg)
	{
		let appmode = msg["appmode"];
		if(appmode!="Scintilla")
			tab="main";
		setApplicationMode(appmode,tab);
	}
	if("syntax" in msg)
	{
		let syntax = msg["syntax"];
		document.getElementById("syntax").value = syntax;
		document.getElementById("syntax2").value = syntax;
	}
	if("systype" in msg)
	{
		let systype = msg["systype"];
		document.getElementById("eol").value = systype;
		document.getElementById("eol2").value = systype;
	}
	if("encoding" in msg)
	{
		let enc = msg["encoding"];
		document.getElementById("enc").value = enc;
	}
	if("writeBOM" in msg)
	{
		let bom = msg["writeBOM"];
		document.getElementById("writeBom").checked = bom;
	}
	if("showLineNumbers" in msg)
	{
		let showLineNumbers = msg["showLineNumbers"];
		document.getElementById("showLineNumbers").checked = showLineNumbers;
	}
	if("tabUsage" in msg)
	{
		let useTabs = msg["tabUsage"];
		document.getElementById("useTabs").checked = useTabs;
	}
	if("tabIndents" in msg)
	{
		let tabIndents = msg["tabIndents"];
		document.getElementById("tabIndents").checked = tabIndents;
	}
	if("backSpaceUnindents" in msg)
	{
		let backSpaceUnindents = msg["backSpaceUnindents"];
		document.getElementById("backUnindents").checked = backSpaceUnindents;
	}
	if("tabWidth" in msg)
	{
		let tabWidth = msg["tabWidth"];
		document.getElementById("tabWidth").value = "" + tabWidth;
	}
	if("showTreeView" in msg)
	{
		let showTreeView = msg["showTreeView"];

		let dirView = document.getElementById("dirView");
		dirView.setAttribute("status",showTreeView ? "true" : "false");
		dirView.className = dirView.className.replace(" active", "");
		if(showTreeView)
		{
			dirView.className = dirView.className + " active";
		}
	}
	if("showBytes" in msg)
	{
		let showBytes = msg["showBytes"];
		document.getElementById("showBytes").value = showBytes;
	}
	if("action" in msg)
	{
		let action = msg["action"];
		if(action == "enc")
		{
			let html = "";
			let encodings = msg["enc"];
			encodings.forEach(function(enc) {

				var n = enc.name;
				var v = enc.value;
				html += "<option value='" + v + "'>" + n + "</option>";
			});
			document.getElementById("enc").innerHTML = html;
		}
	}
}

window.onload = function() {

	var modus = document.getElementById("mode");
	modus.onchange = function(e) {
		var m = modus.value;
		setApplicationMode(m,"main");
	};

	document.getElementById("file").onclick = function() { api.openFileMenu(); };
	document.getElementById("main").onclick = function() { setApplicationMode(mode,'main'); };
	document.getElementById("run").onclick = function() { setApplicationMode(mode,'run')};
	document.getElementById("tools").onclick = function() { setApplicationMode(mode,'tools')};
	document.getElementById("document").onclick = function() { setApplicationMode(mode,'document')};

	document.getElementById("enc").onchange = function(e) { 
		let msg = { "action" : "enc", "enc" : this.value };
		window.chrome.webview.postMessage(msg);
	};

	var cmds = Array.from(document.querySelectorAll("div[cmd]"));
	cmds.forEach( function(el) {

		el.onclick = function(e) {
			let cmd = this.getAttribute("cmd");
			let msg = { "cmd" : action[cmd] };

			//alert(JSON.stringify(msg));

			window.chrome.webview.postMessage(msg);
		};
	});

	var divActions = Array.from(document.querySelectorAll("div[action]"));
	divActions.forEach( function(el) {

		el.onclick = function(e) {
			let action = this.getAttribute("action");
			let value = this.getAttribute("status");
			let msg = { "action" : action };
			msg[action] = value === "true" ? false : true;
			//alert(JSON.stringify(msg));

			onToggle(this);
			window.chrome.webview.postMessage(msg);
		};
	});

	var selects = Array.from( document.querySelectorAll("select[action]") );
	selects.forEach( function(el) {

		el.onchange = function(e) {
			
			let action = this.getAttribute("action");
			let cmd = this.value;
			let msg = { 
				"action" : action
			};
			msg[action] = cmd;
			window.chrome.webview.postMessage(msg);
		};
	});

	var inputs = Array.from( document.querySelectorAll("input[action]") );
	inputs.forEach( function(el) {

		el.onchange = function(e) {
			let state = this.checked;
			let action = this.getAttribute("action");
			let msg = { "action" : action };
			msg[action] = state;
			window.chrome.webview.postMessage(msg);
		};
	});

	var scripts = Array.from( document.querySelectorAll("div[script]") );
	scripts.forEach( function(el) {

		el.onclick = function(e) {
			let script = this.getAttribute("script");
			let msg = { "action" : "script" };
			msg["script"] = script;
			window.chrome.webview.postMessage(msg);
		};
	});

	var clis = Array.from( document.querySelectorAll("div[cli]") );
	clis.forEach( function(el) {

		el.onclick = function(e) {
			let cli = this.getAttribute("cli");
			let msg = { "action" : "system" };
			msg["system"] = cli;
			window.chrome.webview.postMessage(msg);
		};
	});

	setApplicationMode("Img","main");
	document.getElementById("ribbon").style.display="block";

	window.chrome.webview.addEventListener('message', onMessage);

	//api.init();
};



