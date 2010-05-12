xcopy /Y /S /E /I /EXCLUDE:exclude.txt "..\moe\resources\deploy" ".\regfree\uni_release_64"

copy /Y "..\moe\resources\moe.ico" ".\regfree\uni_release_64"

copy /Y "ui.xmo" ".\regfree\uni_release_64"


copy /Y "..\moe\x64\uni_release_64\moe.exe" ".\regfree\uni_release_64"
copy /Y "..\prw\prw\x64\uni_release_64\prw.exe" ".\regfree\uni_release_64"
copy /Y "..\..\ax\io\x64\uni_release_64\io.dll" ".\regfree\uni_release_64"
copy /Y "..\..\ax\process\x64\uni_release_64\pipedprocess.dll" ".\regfree\uni_release_64"
copy /Y "..\..\ax\comtypes\x64\uni_release_64\comtypes.dll" ".\regfree\uni_release_64"
copy /Y "..\..\ax\scintillax\x64\uni_release_64\scintillax.dll" ".\regfree\uni_release_64"
copy /Y "..\..\ax\setting\x64\uni_release_64\setting.dll" ".\regfree\uni_release_64"
copy /Y "..\..\ax\shellctrl\x64\uni_release_64\shellctrl.dll" ".\regfree\uni_release_64"
copy /Y "..\..\ax\shellfolder\x64\uni_release_64\shellfolder.dll" ".\regfree\uni_release_64"

mt.exe -manifest .\regfree\moe.exe.isolated64.manifest -outputresource:".\regfree\uni_release_64\moe.exe;#1" -hashupdate -validate_manifest -verbose

mt.exe -manifest .\regfree\io.dll.isolated.manifest -outputresource:".\regfree\uni_release_64\io.dll;#2" 

mt.exe -manifest .\regfree\comtypes.dll.isolated.manifest -outputresource:".\regfree\uni_release_64\comtypes.dll;#2" 

mt.exe -manifest .\regfree\setting.dll.isolated.manifest -outputresource:".\regfree\uni_release_64\setting.dll;#2" 

mt.exe -manifest .\regfree\pipedprocess.dll.isolated.manifest -outputresource:".\regfree\uni_release_64\pipedprocess.dll;#2" 

mt.exe -manifest .\regfree\shellctrl.dll.isolated.manifest -outputresource:".\regfree\uni_release_64\shellctrl.dll;#2" 

mt.exe -manifest .\regfree\scintillax.dll.isolated.manifest -outputresource:".\regfree\uni_release_64\scintillax.dll;#2" 

mt.exe -manifest .\regfree\shellfolder.dll.isolated.manifest -outputresource:".\regfree\uni_release_64\shellfolder.dll;#2" 
