@echo off
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
echo "###"
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\Common7\Tools\VsDevCmd.bat"
echo "###"
pushd "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC"
rem call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" %PLAT%
echo "###"
call vcvarsall.bat amd64
echo "###"
popd

set Configuration=%CONF%

if "%PLAT%"=="/x86" goto x86
set Platform=x64
goto end

:x86
set Platform=Win32

:end

echo Configuration: %Configuration%
echo Platform: %Platform%
echo %PLAT%
exit /B
