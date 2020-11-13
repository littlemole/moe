Dim WshShell
Set WshShell = WScript.CreateObject("WScript.Shell")
WScript.Echo WshShell.CurrentDirectory

Set objArgs = WScript.Arguments
For I = 0 to objArgs.Count - 1
   WScript.Echo objArgs(I)
Next

ZipFile = ""
ExtractTo = ""

if objArgs.Count > 0 then
  ZipFile = WshShell.CurrentDirectory + "\" + objArgs(0)
end if

if objArgs.Count > 1 then
  ExtractTo = WshShell.CurrentDirectory +"\" +objArgs(1)
end if

WScript.Echo ZipFile
WScript.Echo ExtractTo

'If the extraction location does not exist create it.
Set fso = CreateObject("Scripting.FileSystemObject")
If NOT fso.FolderExists(ExtractTo) Then
   fso.CreateFolder(ExtractTo)
End If

'Extract the contants of the zip file.
set objShell = CreateObject("Shell.Application")
set FilesInZip=objShell.NameSpace(ZipFile).items
objShell.NameSpace(ExtractTo).CopyHere(FilesInZip)
Set fso = Nothing
Set objShell = Nothing



