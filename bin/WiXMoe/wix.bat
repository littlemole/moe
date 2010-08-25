rem ---------------------------------------
rem BUILDING MSI INSTALLER THE WIX WAY
rem ---------------------------------------

set WIXBIN=%WIX%\bin

set CANDLE=%WIXBIN%\candle.exe
set LIGHT=%WIXBIN%\light.exe
SET HEAT=%WIXBIN%\heat.exe

set UIEXT=%WIXBIN%\WixUIExtension.dll

rem --set-targets-------------------------------------

set SRCDIR=.\moe

set MODE=%1
set MODE=%MODE:"=%

set TARGET=%2
set TARGET=%TARGET:"=%

set PLATFORM=%3
set PLATFORM=%PLATFORM:"=%

if %PLATFORM%==Win32 SET PLATFORM=x86

set GENOBJ=obj\%MODE%\gen.wixobj
set MOEOBJ=obj\%MODE%\moe.wixobj
set MONDOBJ=obj\%MODE%\mondo.wixobj

SET SRC=%MODE%

if "%PLATFORM%"=="x64" SET SRC=%PLATFORM%\%MODE%

rem --copy-last-compiler-run-output-------------------

del .\moe\*.* /Q /S

mkdir .\moe

xcopy /Y /S /E /I /EXCLUDE:exclude.txt "..\moe\resources\deploy" ".\moe"

copy /Y "..\moe\resources\moe.ico" ".\moe"
copy /Y "..\moe\%SRC%\moe.exe" ".\moe"
copy /Y "..\prw\prw\%SRC%\prw.exe" ".\moe"
copy /Y "..\..\ax\io\%SRC%\io.dll" ".\moe"
copy /Y "..\..\ax\process\%SRC%\pipedprocess.dll" ".\moe"
copy /Y "..\..\ax\comtypes\%SRC%\comtypes.dll" ".\moe"
copy /Y "..\..\ax\scintillax\%SRC%\scintillax.dll" ".\moe"
copy /Y "..\..\ax\setting\%SRC%\setting.dll" ".\moe"
copy /Y "..\..\ax\shellctrl\%SRC%\shellctrl.dll" ".\moe"
copy /Y "..\..\ax\shellfolder\%SRC%\shellfolder.dll" ".\moe"


rem ---scan-elements-for-gen.wxs-----------------------------

cd moe

"%HEAT%" dir . -gg -cg "MoeCompGroup" -dr INSTALLLOCATION -var var.SourceDir  -o ..\gen.wxs

IF ERRORLEVEL 1 GOTO hell

cd ..


rem --compile-wix-------------------------------------


"%CANDLE%" -o "%GENOBJ%" gen.wxs -dSourceDir="%SRCDIR%" -dBuildArch=%PLATFORM% -ext "%UIEXT%" -arch %PLATFORM%

IF ERRORLEVEL 1 GOTO hell

"%CANDLE%" -o "%MOEOBJ%" moe.wxs -dSourceDir="%SRCDIR%" -dBuildArch=%PLATFORM% -ext "%UIEXT%" -arch %PLATFORM%

IF ERRORLEVEL 1 GOTO hell

"%CANDLE%" -o "%MONDOBJ%" MondoNoLicense.wxs -dSourceDir="%SRCDIR%" -dBuildArch=%PLATFORM% -ext "%UIEXT%" -arch %PLATFORM%

IF ERRORLEVEL 1 GOTO hell

rem --link-wix-------------------------------------


"%LIGHT%" -ext "%UIEXT%" -out "bin\%MODE%\%TARGET%" -cultures:en-us -loc en-us.wxl "%GENOBJ%" "%MOEOBJ%" "%MONDOBJ%"

IF ERRORLEVEL 1 GOTO hell


rem ---------------------------------------


goto end



:hell

exit /B 1

:end

exit /B 0
