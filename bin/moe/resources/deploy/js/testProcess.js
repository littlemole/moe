var killRoy = new ActiveXObject("ShellCtrls.KillRoy");

if(killRoy)
{
  var file = Dialogs.ChooseFile();
  if (file)
  {
	var pid = killRoy.FindPIDforFile(file);
	var result = Dialogs.MsgBox(
		"the pid of the process holding\r\n\r\n" + file +"\r\n\r\nis: " + pid + " " + pid.Name, 
		"kill the process?",Dialogs.YESNO|Dialogs.ICONQUESTION
		);
	if ( result == IDYES ) 
	{
	  pid.TerminateProcess();
	}
  }
}

