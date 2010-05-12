xcopy /Y /S /E /I /EXCLUDE:exclude.txt "..\moe\resources\deploy" ".\regfree\uni_release"

copy /Y "..\moe\resources\moe.ico" ".\regfree\uni_release"


copy /Y "..\moe\uni_release\moe.exe" ".\regfree\uni_release"
copy /Y "..\prw\prw\uni_release\prw.exe" ".\regfree\uni_release"
copy /Y "..\..\ax\io\uni_release\io.dll" ".\regfree\uni_release"
copy /Y "..\..\ax\process\uni_release\pipedprocess.dll" ".\regfree\uni_release"
copy /Y "..\..\ax\comtypes\uni_release\comtypes.dll" ".\regfree\uni_release"
copy /Y "..\..\ax\scintillax\uni_release\scintillax.dll" ".\regfree\uni_release"
copy /Y "..\..\ax\setting\uni_release\setting.dll" ".\regfree\uni_release"
copy /Y "..\..\ax\shellctrl\uni_release\shellctrl.dll" ".\regfree\uni_release"
copy /Y "..\..\ax\shellfolder\uni_release\shellfolder.dll" ".\regfree\uni_release"

mt.exe -manifest .\regfree\moe.exe.isolated.manifest -outputresource:".\regfree\uni_release\moe.exe;#1" -hashupdate -validate_manifest -verbose

mt.exe -manifest .\regfree\io.dll.isolated.manifest -outputresource:".\regfree\uni_release\io.dll;#2" 

mt.exe -manifest .\regfree\comtypes.dll.isolated.manifest -outputresource:".\regfree\uni_release\comtypes.dll;#2" 

mt.exe -manifest .\regfree\setting.dll.isolated.manifest -outputresource:".\regfree\uni_release\setting.dll;#2" 

mt.exe -manifest .\regfree\pipedprocess.dll.isolated.manifest -outputresource:".\regfree\uni_release\pipedprocess.dll;#2" 

mt.exe -manifest .\regfree\shellctrl.dll.isolated.manifest -outputresource:".\regfree\uni_release\shellctrl.dll;#2" 

mt.exe -manifest .\regfree\scintillax.dll.isolated.manifest -outputresource:".\regfree\uni_release\scintillax.dll;#2" 

mt.exe -manifest .\regfree\shellfolder.dll.isolated.manifest -outputresource:".\regfree\uni_release\shellfolder.dll;#2" 
