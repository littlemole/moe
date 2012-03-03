
var selection = ActiveDoc.Object.Selection;
if (selection) {
    var txt = "" + selection.Text;
    var encoded = encodeURI(txt);
    selection.Text = encoded ;
}