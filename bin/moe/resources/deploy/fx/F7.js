var doc = moe.ActiveDoc;
if ( doc )
{
  var d = doc.Object;
  if ( d )
  {
    var mode = d.SysType;
    if ( mode == 0 )
      d.SysType = 1;
    else
      d.SysType = 0;
    doc.View.Activate();  
  }
}