@echo off

rem ###################################################
rem bootstrap 3dparty deps and locate vc++
rem ###################################################

if "%2"=="x86" goto x86

call boot x64-windows-static
goto start

:x86
call boot x86-windows-static


rem ###################################################
rem initialize environment
rem ###################################################

:start

rem compiler version
set MSBUILDTREATALLTOOLSVERSIONSASCURRENT 
set PlatformToolset=v141

rem initialise VC environment
set VCVARSBAT="%VSROOT%\VC\Auxiliary\Build\vcvarsall.bat"

rem java includes
set java=%JAVA_HOME%\include\win32;%JAVA_HOME%\include;


rem ###################################################
rem figure out how to call vcvarsall.bat
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


rem ###################################################
rem finally make the call to vcvarsall.bat
rem ###################################################

:psdk
call %VCVARSBAT% %PLAT%


rem ###################################################
rem set some final vars
rem ###################################################

set Configuration=%CONF%

if "%PLAT%"=="x86" goto x86
set Platform=x64
goto end

:x86
set Platform=Win32


rem ###################################################
rem ouput some diagnostics
rem ###################################################

:end

echo Configuration: %Configuration%
echo Platform: %Platform%
echo %PLAT%
echo %PlatformToolset%
exit /B
