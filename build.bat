set TARGETPATH=%1
set TARGETPATH=%TARGETPATH:"=%

SET NAME=%2
SET NAME=%NAME:"=%

SET MODE=%3
SET MODE=%MODE:"=%

SET PLATFORM=%4
SET PLATFORM=%PLATFORM:"=%

SET TARGET=%5
if NOT %5!==! SET TARGET=%TARGET:"=%

rem if %5!==! SET TARGET=/rebuild



SET CONF="%MODE%|%PLATFORM%"

set TARGETDIR="%TARGETPATH%\%NAME%"
set SOLUTION=%NAME%.sln
set VCPROJ=%NAME%.vcproj




set OLDDIR=%CD%

cd %TARGETDIR%


IF NOT EXIST xml\cmd.xml goto compile
IF NOT %5!==! goto compile

cscript "%OLDDIR%\cg\js\make.js" "%MODE%"

IF ERRORLEVEL 0 GOTO compile

goto hell


:compile

vcbuild "%VCPROJ%" %CONF% %TARGET% /platform:%PLATFORM%

IF ERRORLEVEL 1 GOTO hell

rem SUCCESS

goto end

:hell

chdir /d %OLDDIR% &rem restore current directory

echo on

rem FAILURE :-(

exit /B 1

:end

chdir /d %OLDDIR% &rem restore current directory

exit /B 0