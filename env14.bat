@echo off
set MSBUILDTREATALLTOOLSVERSIONSASCURRENT 

rem compiler version
set PlatformToolset=v140

rem initialise VC environment
set VCVARSBAT="C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat"

rem boost
set boost=C:\boost\boost_1_61_0\

rem ribbon toolbar compiler
set UICC="C:\Program Files (x86)\Windows Kits\8.1\bin\x86\uicc.exe"

rem java includes
set java=%JAVA_HOME%\include\win32;%JAVA_HOME%\include;


rem ###################################################


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
call %VCVARSBAT% %PLAT%

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
echo %PlatformToolset%
exit /B
