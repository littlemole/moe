var doc = moe.ActiveDoc;
if ( doc )
{
  var d = doc.Document;
  if ( d )
  {
    var txt = d.GetText();
    moe.Eval(txt,"javascript");
  }
}
