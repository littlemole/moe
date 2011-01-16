set TARGETDIR=%1
set TARGETDIR=%TARGETDIR:"=%

set MODE=%2
set MODE=%MODE:"=%\moe

set PLAT=%3
set PLAT=%PLAT:"=%

set TARGET=%4

set DEPLOYDIR=%TARGETDIR%\deploy\regfree

if "%TARGET%"=="/clean" goto clean


SET WORKDIR=%DEPLOYDIR%\tmpdir

del /S /Q "%DEPLOYDIR%\moe"
del /S /Q "%WORKDIR%"

rmdir "%DEPLOYDIR%\moe"
rmdir "%WORKDIR%"
mkdir "%WORKDIR%"

xcopy /Y /S /E /I /EXCLUDE:%TARGETDIR%\exclude.txt "%TARGETDIR%\moe" "%WORKDIR%"
IF ERRORLEVEL 1 GOTO hell

rem sleep 3

RENAME "%WORKDIR%" "moe"

SET WORKDIR=%DEPLOYDIR%\moe



mt.exe -manifest %DEPLOYDIR%\moe.exe.isolated.manifest -outputresource:"%WORKDIR%\moe.exe;#1" -hashupdate -validate_manifest -verbose
IF ERRORLEVEL 1 GOTO hell

mt.exe -manifest %DEPLOYDIR%\io.dll.isolated.manifest -outputresource:"%WORKDIR%\io.dll;#2" 
IF ERRORLEVEL 1 GOTO hell

mt.exe -manifest %DEPLOYDIR%\comtypes.dll.isolated.manifest -outputresource:"%WORKDIR%\comtypes.dll;#2" 
IF ERRORLEVEL 1 GOTO hell

mt.exe -manifest %DEPLOYDIR%\setting.dll.isolated.manifest -outputresource:"%WORKDIR%\setting.dll;#2" 
IF ERRORLEVEL 1 GOTO hell

mt.exe -manifest %DEPLOYDIR%\pipedprocess.dll.isolated.manifest -outputresource:"%WORKDIR%\pipedprocess.dll;#2" 
IF ERRORLEVEL 1 GOTO hell

mt.exe -manifest %DEPLOYDIR%\shellctrl.dll.isolated.manifest -outputresource:"%WORKDIR%\shellctrl.dll;#2" 
IF ERRORLEVEL 1 GOTO hell

mt.exe -manifest %DEPLOYDIR%\scintillax.dll.isolated.manifest -outputresource:"%WORKDIR%\scintillax.dll;#2" 
IF ERRORLEVEL 1 GOTO hell

mt.exe -manifest %DEPLOYDIR%\shellfolder.dll.isolated.manifest -outputresource:"%WORKDIR%\shellfolder.dll;#2" 
IF ERRORLEVEL 1 GOTO hell


mkdir "%DEPLOYDIR%\%PLAT%\%MODE%

echo "%TARGETDIR%\zip.vbs" "%DEPLOYDIR%\%PLAT%\%MODE%\moe.zip" "%WORKDIR%"

cscript "%TARGETDIR%\zip.vbs" "%DEPLOYDIR%\%PLAT%\%MODE%\moe.zip" "%WORKDIR%"

IF ERRORLEVEL 1 GOTO hell

rmdir /S /Q  "%WORKDIR%"

goto end




:clean

del "%DEPLOYDIR%\%PLAT%\%MODE%\moe.zip"

goto end




:hell

echo on

rem FAILURE :-(

exit /B 1

:end


exit /B 0