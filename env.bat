set CONF=%1
if %1!==! SET CONF=uni_debug

set PLAT=%2
if %2!==! set PLAT=/x86

set PlatformToolset=v100


if "%CONF%"=="uni_debug" goto debug



set CONFIG=/Release
goto psdk

:debug
set CONFIG=/Debug


:psdk
call "C:\Program Files\Microsoft SDKs\Windows\v7.1\bin\SetEnv.Cmd" %CONFIG% %PLAT%

set UICC="C:\Program Files\Microsoft SDKs\Windows\v7.1\Bin\UICC.exe"
set Configuration=%CONF%

if "%PLAT%"=="/x86" goto x86
set Platform=x64
goto end

:x86
set Platform=Win32

:end

echo Configuration: %Configuration%
echo Platform: %Platform%
echo Toolset: %PlatformToolset%
echo %PLAT%
echo %UICC%
exit /B
