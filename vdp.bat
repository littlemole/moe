
cd bin\%3
devenv "../moe/moe.sln" /build %1 /project %3

IF ERRORLEVEL 1 GOTO hell


cd %2

SET SRC="%3".msi
SET DEST="%3"Light.msi

SET SRC=%SRC:""=%
SET DEST=%DEST:""=%

copy /Y %SRC% %DEST%

cscript "..\moeEditMSI.wsf" %DEST%

IF ERRORLEVEL 1 GOTO hell

cd ..\..\..

SET BIN=bin\"%3"\"%2"
SET BIN="%BIN:""=%"

SET DEPLOY=bin\"%3"\"%2"\..\deploy\"%2"\
SET DEPLOY="%DEPLOY:""=%"

xcopy /Y /S /I /E %BIN% %DEPLOY%

goto end

:hell


exit /B 1

:end


exit /B 0

