rem @echo off

PROMPT $G

set MODE=%1
if NOT %1!==! set MODE=%MODE:"=%

set TARGET=%2
if NOT %2!==! set TARGET=%TARGET:"=%

set PLATFORM=%3
IF NOT %3!==! goto arch

SET PLATFORM=Win32
IF %3!==! set PLATFORM=Win32

echo %LIB% | find "x64" > NUL
IF ERRORLEVEL 1 GOTO compile

SET PLATFORM=x64


goto compile

:arch
set PLATFORM=%PLATFORM:"=%

:compile

echo ++++++++++++++++++++++++++++++++++++++++++++++++++++
echo "executing for %PLATFORM% mode %MODE%
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++

call lib\build.bat "%MODE%" "%PLATFORM%" %TARGET%
IF ERRORLEVEL 1 GOTO hell

call ax\build.bat "%MODE%" "%PLATFORM%" %TARGET% 
IF ERRORLEVEL 1 GOTO hell

call bin\build.bat "%MODE%" "%PLATFORM%" %TARGET% 
IF ERRORLEVEL 1 GOTO hell


call wix.bat "%MODE%" moeSetup "%PLATFORM%" %TARGET% 
IF ERRORLEVEL 1 GOTO hell

call .\bin\WixMoe\regfree.bat "bin\WixMoe" "%MODE%" %TARGET% 
IF ERRORLEVEL 1 GOTO hell

echo      BUILD SUCCESSFULL

goto end

:fail
cd ..\..
goto hell


:hell


echo     ! BUILD FAILED :-(

PROMPT
exit /B 1

:end

PROMPT
exit /B 0
