
var selection = ActiveDoc.Object.Selection;
if (selection) {
    var txt = "" + selection.Text;
    var encoded = decodeURI(txt);
    selection.Text = encoded ;
}