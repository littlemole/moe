var doc = moe.ActiveDoc;
if ( doc )
{
  var d = doc.Object;
  if ( d )
  {
    var txt = d.Text;
    moe.Script.Eval(txt,"javascript");
  }
}
