var doc = moe.ActiveDoc;
if ( doc )
{
  var d = doc.Object;
  if ( d )
  {
	var f = d.Properties.Filename; 
	moe.Script.ShowHtmlForm(
                  f,
				  moe.View.left+25,moe.View.top+25,700,450,5);
  }
}
