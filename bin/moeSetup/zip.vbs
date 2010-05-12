Dim WshShell
Set WshShell = WScript.CreateObject("WScript.Shell")
WScript.Echo WshShell.CurrentDirectory

Set objArgs = WScript.Arguments
For I = 0 to objArgs.Count - 1
   WScript.Echo objArgs(I)
Next

zip = "moe.zip"
src = "Unicode Debug"

if objArgs.Count > 0 then
  zip = objArgs(0)
end if

if objArgs.Count > 1 then
  src = objArgs(1)
end if


Const FOF_CREATEPROGRESSDLG = &H0&

MyZip = WshShell.CurrentDirectory &"\regfree\" & zip

Target = WshShell.CurrentDirectory & "\regfree\moe"

Set fso = CreateObject("Scripting.FileSystemObject")

If fso.FolderExists(Target) Then
    fso.DeleteFolder Target
    fso.CreateFolder Target
End If

if fso.FileExists(MyZip) then
   fso.DeleteFile(MyZip)
end if

fso.copyFolder WshShell.CurrentDirectory &"\regfree\" & src, Target 


'-------------- create empty zip file ---------

'Create the basis of a zip file.
CreateObject("Scripting.FileSystemObject") _
.CreateTextFile(MyZip, True) _
.Write "PK" & Chr(5) & Chr(6) & String(18, vbNullChar)


'-------------- zip ---------------------------

'get ready to add files to zip
With CreateObject("Shell.Application")

'add files
'.NameSpace(MyZip).CopyHere File1, FOF_CREATEPROGRESSDLG

.NameSpace(MyZip).CopyHere WshShell.CurrentDirectory & "\regfree\moe"

End With
wScript.Sleep 2000
