xcopy /Y /S /E /I /EXCLUDE:exclude.txt "..\moe\resources\deploy" ".\regfree\Unicode Debug"

copy /Y "..\moe\resources\moe.ico" ".\regfree\Unicode Debug"


copy /Y "..\moe\Unicode Debug\moe.exe" ".\regfree\Unicode Debug"
copy /Y "..\prw\prw\Unicode Debug\prw.exe" ".\regfree\Unicode Debug"
copy /Y "..\..\ax\io\Unicode Debug\io.dll" ".\regfree\Unicode Debug"
copy /Y "..\..\ax\process\Unicode Debug\pipedprocess.dll" ".\regfree\Unicode Debug"
copy /Y "..\..\ax\comtypes\Unicode Debug\comtypes.dll" ".\regfree\Unicode Debug"
copy /Y "..\..\ax\scintillax\Unicode Debug\scintillax.dll" ".\regfree\Unicode Debug"
copy /Y "..\..\ax\setting\Unicode Debug\setting.dll" ".\regfree\Unicode Debug"
copy /Y "..\..\ax\shellctrl\Unicode Debug\shellctrl.dll" ".\regfree\Unicode Debug"
copy /Y "..\..\ax\shellfolder\Unicode Debug\shellfolder.dll" ".\regfree\Unicode Debug"

mt.exe -manifest .\regfree\moe.exe.isolated.manifest -outputresource:".\regfree\Unicode Debug\moe.exe;#1" -hashupdate -validate_manifest -verbose

mt.exe -manifest .\regfree\io.dll.isolated.manifest -outputresource:".\regfree\Unicode Debug\io.dll;#2" 

mt.exe -manifest .\regfree\comtypes.dll.isolated.manifest -outputresource:".\regfree\Unicode Debug\comtypes.dll;#2" 

mt.exe -manifest .\regfree\setting.dll.isolated.manifest -outputresource:".\regfree\Unicode Debug\setting.dll;#2" 

mt.exe -manifest .\regfree\pipedprocess.dll.isolated.manifest -outputresource:".\regfree\Unicode Debug\pipedprocess.dll;#2" 

mt.exe -manifest .\regfree\shellctrl.dll.isolated.manifest -outputresource:".\regfree\Unicode Debug\shellctrl.dll;#2" 

mt.exe -manifest .\regfree\scintillax.dll.isolated.manifest -outputresource:".\regfree\Unicode Debug\scintillax.dll;#2" 

mt.exe -manifest .\regfree\shellfolder.dll.isolated.manifest -outputresource:".\regfree\Unicode Debug\shellfolder.dll;#2" 
