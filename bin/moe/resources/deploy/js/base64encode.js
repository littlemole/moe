Import("js\\lib\\base64.js");

var selection = ActiveDoc.Object.Selection;
if (selection) {
    var txt = "" + selection.Text;
    var encoded = Base64.encode(txt);
    selection.Text = encoded ;
}

