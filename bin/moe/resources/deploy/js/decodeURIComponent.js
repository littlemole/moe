
var doc = moe.Documents.ActiveDoc;
var obj = doc.Object;
var selection = moe.Documents.ActiveDoc.Object.Selection;
if (selection) {
    var txt = "" + selection.Text;
    var encoded = decodeURIComponent(txt);
    selection.Text = encoded ;
}