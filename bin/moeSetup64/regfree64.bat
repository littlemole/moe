xcopy /Y /S /E /I /EXCLUDE:exclude.txt "..\moe\resources\deploy" ".\regfree\Unicode Debug 64"

copy /Y "ui.xmo" ".\regfree\Unicode Debug 64"

copy /Y "..\moe\resources\moe.ico" ".\regfree\Unicode Debug 64"


copy /Y "..\moe\x64\Unicode Debug 64\moe.exe" ".\regfree\Unicode Debug 64"
copy /Y "..\prw\prw\x64\Unicode Debug 64\prw.exe" ".\regfree\Unicode Debug 64"
copy /Y "..\..\ax\io\x64\Unicode Debug 64\io.dll" ".\regfree\Unicode Debug 64"
copy /Y "..\..\ax\process\x64\Unicode Debug 64\pipedprocess.dll" ".\regfree\Unicode Debug 64"
copy /Y "..\..\ax\comtypes\x64\Unicode Debug 64\comtypes.dll" ".\regfree\Unicode Debug 64"
copy /Y "..\..\ax\scintillax\x64\Unicode Debug 64\scintillax.dll" ".\regfree\Unicode Debug 64"
copy /Y "..\..\ax\setting\x64\Unicode Debug 64\setting.dll" ".\regfree\Unicode Debug 64"
copy /Y "..\..\ax\shellctrl\x64\Unicode Debug 64\shellctrl.dll" ".\regfree\Unicode Debug 64"
copy /Y "..\..\ax\shellfolder\x64\Unicode Debug 64\shellfolder.dll" ".\regfree\Unicode Debug 64"


mt.exe -manifest .\regfree\moe.exe.isolated64.manifest -outputresource:".\regfree\Unicode Debug 64\moe.exe;#1" -hashupdate -validate_manifest -verbose

mt.exe -manifest .\regfree\io.dll.isolated.manifest -outputresource:".\regfree\Unicode Debug 64\io.dll;#2" 

mt.exe -manifest .\regfree\comtypes.dll.isolated.manifest -outputresource:".\regfree\Unicode Debug 64\comtypes.dll;#2" 

mt.exe -manifest .\regfree\setting.dll.isolated.manifest -outputresource:".\regfree\Unicode Debug 64\setting.dll;#2" 

mt.exe -manifest .\regfree\pipedprocess.dll.isolated.manifest -outputresource:".\regfree\Unicode Debug 64\pipedprocess.dll;#2" 

mt.exe -manifest .\regfree\shellctrl.dll.isolated.manifest -outputresource:".\regfree\Unicode Debug 64\shellctrl.dll;#2" 

mt.exe -manifest .\regfree\scintillax.dll.isolated.manifest -outputresource:".\regfree\Unicode Debug 64\scintillax.dll;#2" 

mt.exe -manifest .\regfree\shellfolder.dll.isolated.manifest -outputresource:".\regfree\Unicode Debug 64\shellfolder.dll;#2" 
