
var selection = ActiveDoc.Object.Selection;
if (selection) {
    var txt = "" + selection.Text;
    var encoded = unescape(txt);
    selection.Text = encoded ;
}