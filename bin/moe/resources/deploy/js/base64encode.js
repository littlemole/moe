Import("js\\base64.js");

var doc = moe.Documents.ActiveDoc;
var obj = doc.Object;
var selection = moe.Documents.ActiveDoc.Object.Selection;
if (selection) {
    var txt = "" + selection.Text;
    var encoded = Base64.encode(txt);
    selection.Text = encoded ;
}

