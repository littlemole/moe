var killRoy = new ActiveXObject("ShellCtrls.KillRoy");

if(killRoy)
{
  var file = moe.Dialogs.ChooseFile();
  if (file)
  {
	var pid = killRoy.FindPIDforFile(file);
	var result = moe.Dialogs.MsgBox("the pid of the process holding\r\n\r\n"+ file +"\r\n\r\nis: " + pid, "kill the process?",4);
	if ( result == 6 ) // IDYES
	{
	  pid.TerminateProcess();
	}
  }
}

