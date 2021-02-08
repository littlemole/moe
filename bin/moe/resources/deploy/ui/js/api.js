var api = {
/*
    init: function() {

        // get encodings
        let html = "";
        let encodings = api.getEncodings();
        encodings.forEach(function(enc) {

            var n = enc.name;
            var v = enc.value;
            html += "<option value='" + v + "'>" + n + "</option>";
        });
        document.getElementById("enc").innerHTML = html;
    },

    getSettings: function() {

        let json = window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.JSON;
        return JSON.parse(json);
    },


    getEncodings: function() {

        let json = window.chrome.webview.hostObjects.sync.external.Moe.Config.GetEncodings();
        //alert(json);
        return JSON.parse(json);
    },
*/
    openFileMenu: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.View.ShowFileMenu();
    },

    closeFileMenu: function() {
        window.chrome.webview.hostObjects.sync.external.Frame.View.Hide();
    },

    newFile: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.Documents.New();
    },

    open: function(f) {
        window.chrome.webview.hostObjects.sync.external.Moe.Dialogs.Open(f);
    },

    openFile: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.Dialogs.Open("");
    },

    openFolder: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.Dialogs.OpenDir();
    },

    openUrl: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.Documents.OpenURLDialog();
    },

    save: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Save();
    },

    saveAs: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.SaveAsDialog();
    },

    cut: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.Cut();
    },

    copy: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.Copy();
    },

    paste: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.Paste();
    },

    pasteAs: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.PasteAs();
    },

    undo: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Undo();
    },

    redo: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Redo();
    },

    find: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.Dialogs.Find();
    },

    replace: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.Dialogs.Replace();
    },

    color: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.InsertColorDialog();
    },

    print: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.Dialogs.Print();
    },

    onSyntax: function(s) {

        let syntax = document.getElementById(s).value;
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Properties.Syntax = syntax;
    },

    onEol: function(e) {

        let eol = document.getElementById(e).value;
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.SysType = eol;
    },
/*
    onEncoding: function() {

        let e = document.getElementById("enc").value;

		let msg = { "action" : "enc", "enc" : e };
		window.chrome.webview.postMessage(msg);

//        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Encoding = e;
    },
*/
    properties: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.ShowProperties();
    },

    directoryProperties: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Properties();
    },

    showExplorer: function(b) {

        let dirView = document.getElementById("dirView");
        let showDirView = dirView.getAttribute("status") === "true" ? false : true;
        window.chrome.webview.hostObjects.sync.external.Moe.View.ShowTreeView = showDirView;
        onToggle(dirView);
    },

    close: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.View.Close();
    },

    closeAll: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.Documents.CloseAll();
    },

    quit: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.Exit();
    },

    insertTemplate: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.InsertTemplate()();
    },

    formatJSON: function() {

        //window.chrome.webview.hostObjects.sync.external.Moe.Exit();	
    },

    formatXML: function() {

        //window.chrome.webview.hostObjects.sync.external.Moe.Exit();	
    },

    encodeBase64: function() {

    },

    decodeBase64: function() {

    },

    encodeURIcomponent: function() {

    },

    execScript: function(s) {
        window.chrome.webview.hostObjects.sync.external.Moe.Script.Run(s, "JScript");
    },

    runScript: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.Script.RunScript();
    },

    debugScript: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.Script.DebugScript();
    },

    breakScript: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.Script.BreakScript();
	},

    stopScript: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.Script.StopScript();
	},

    stepScript: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.Script.StepOver();
	},

    stepInScript: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.Script.StepIn();
	},

    stepOutScript: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.Script.StepOut();
	},

    showForm: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.Script.ShowHTML();
    },

    system: function(s) {
        window.chrome.webview.hostObjects.sync.external.Moe.Script.System(s);		
	},

    certificates: function() {},

    mapDrive: function() {},

    writeBOM: function() {
        let bom = document.getElementById("writeBom").checked;
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Properties.WriteBOM = bom;
    },

    showLineNumbers: function() {
        let show = document.getElementById("showLineNumbers").checked;
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Properties.ShowLineNumbers = show;
    },

    settings: function(b) {},

    useTabs: function() {
        let use = document.getElementById("useTabs").checked;
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Properties.TabUsage = use;
    },

    tabIndents: function() {
        let indents = document.getElementById("tabIndents").checked;
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Properties.TabIndents = indents;
    },

    backspaceUnindents: function() {
        let unindents = document.getElementById("backUnindents").checked;
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Properties.BackSpaceUnindents = unindents;
    },

    tabWidth: function() {
        let width = parseInt(document.getElementById("tabWidth").value);
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Properties.TabWidth = width;
    },

    convertTabs: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Properties.ConvertTabs();
    },

    parentDir: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.UpDir();
	},

    execute: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Execute();
	},

    newFolder: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.CreateDir();
	},

    reload: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Reload();		
	},

    back: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Back();		
	},

    next: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Next();		
	},

    showBytes: function(n) {
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.DisplayColumns = n;
	},

    preferences: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.Config.EditPreferences();
    },

    customize: function() {

        window.chrome.webview.hostObjects.sync.external.Moe.Config.EditSettings();
    },

    loadRecentFiles: function() {
        let json = window.chrome.webview.hostObjects.sync.external.Moe.Config.GetRecentFilesJSON();
        return JSON.parse(json);
    },

    selectAll: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.Model.Selection.SetSelection(0, -1);
    },

    closeMenu: function() {
        window.chrome.webview.hostObjects.sync.external.Frame.View.Hide();
    },

    maximize: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.View.Maximize();
    },

    minimize: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.ActiveDoc.View.Minimize();
    },

    tile: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.View.Tile();
    },

    cascade: function() {
        window.chrome.webview.hostObjects.sync.external.Moe.View.Cascade();
    },


	regexSearch : function() {

        window.chrome.webview.hostObjects.sync.external.Moe.Script.ShowHtmlForm(
			"forms\\search.html",
			window.chrome.webview.hostObjects.sync.external.Moe.View.Left+100,
			window.chrome.webview.hostObjects.sync.external.Moe.View.Top+100,
			600,
			400,
			1
		);
	}
};