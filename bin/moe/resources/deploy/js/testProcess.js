var killRoy = new ActiveXObject("ShellCtrls.KillRoy");

if(killRoy)
{
  var file = moe.Dialogs.ChooseFile();
  if (file)
  {
	var pid = killRoy.FindPIDforFile(file);
	if(pid)
	{
	var result = moe.Dialogs.MsgBox(
		"the pid of the process holding\r\n\r\n" + file +"\r\n\r\nis: " + pid + " " + pid.Name, 
		"kill the process?",moe.Dialogs.YESNO|moe.Dialogs.ICONQUESTION
		);
	if ( result == moe.IDYES ) 
	{
	  pid.TerminateProcess();
	}
	}
  }
}

