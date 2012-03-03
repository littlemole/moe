
var selection = ActiveDoc.Object.Selection;
if (selection) {
    var txt = "" + selection.Text;
    var encoded = escape(txt);
    selection.Text = encoded ;
}