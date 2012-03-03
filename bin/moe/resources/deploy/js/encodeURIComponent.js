
var selection = ActiveDoc.Object.Selection;
if (selection) {
    var txt = "" + selection.Text;
    var encoded = encodeURIComponent(txt);
    selection.Text = encoded ;
}