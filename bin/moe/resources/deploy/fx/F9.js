var doc = moe.ActiveDoc;
if ( doc )
{
  var d = doc.Document;
  if ( d )
  {
	var f = d.Filename; 
	moe.ShowForm("MoeEvalForm", 
                  f,
				  moe.left+25,moe.top+25,700,450,5);
  }
}
