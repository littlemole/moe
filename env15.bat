@echo off

rem ###################################################
rem configuration - usually no need to check anything
rem but the boost path
rem ###################################################

rem boost
rem set boost=C:\boost\boost_1_61_0\

rem compiler version
set MSBUILDTREATALLTOOLSVERSIONSASCURRENT 
set PlatformToolset=v141

rem initialise VC environment
set VCVARSBAT="%ProgramFiles(x86)%\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build\vcvarsall.bat"

rem ribbon toolbar compiler
set UICC="%ProgramFiles(x86)%\Windows Kits\8.1\bin\x86\uicc.exe"

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
