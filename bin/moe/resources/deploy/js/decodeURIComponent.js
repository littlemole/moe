
var selection = ActiveDoc.Object.Selection;
if (selection) {
    var txt = "" + selection.Text;
    var encoded = decodeURIComponent(txt);
    selection.Text = encoded ;
}