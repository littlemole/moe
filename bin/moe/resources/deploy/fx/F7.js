var doc = moe.ActiveDoc;
if ( doc )
{
  var d = doc.Object;
  if ( d )
  {
    var mode = d.Properties.SysType;
    if ( mode == 0 )
      d.Properties.SysType = 1;
    else
      d.Properties.SysType = 0;
    doc.View.Activate();  
  }
}