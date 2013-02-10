@echo off

set PlatformTools=v110
set UICC="C:\Program Files (x86)\Windows Kits\8.0\bin\x86\uicc.exe"

set CONF=%1
if %1!==! SET CONF=uni_debug

set PLAT=%2
if %2!==! set PLAT=x86

if "%CONF%"=="uni_debug" goto debug

set CONFIG=/Release
goto psdk

:debug
set CONFIG=/Debug


:psdk
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" %PLAT%

set Configuration=%CONF%

if "%PLAT%"=="x86" goto x86
set Platform=x64
goto end

:x86
set Platform=Win32

:end

echo Configuration: %Configuration%
echo Platform: %Platform%
echo %PLAT%
echo %PlatformTools%
exit /B
