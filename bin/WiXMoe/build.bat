rem build both admin and non-privilegded user installers
rem ----------------------------------------------------

set MODE=%1
set MODE=%MODE:"=%

set MSI=%2
set MSI=%MSI:"=%

set PLATFORM=%3

set MSILIGHT=%MSI:"=%light.msi
set MSI=%MSI%.msi

set TARGET=%4
if NOT "%TARGET%"=="/clean" goto compile

if "%TARGET%"=="/clean" goto clean

goto end



:clean

rem ---clean--------------------------------------------


SET DEST="deploy\%MODE%\%MSILIGHT:"=%"
del %DEST%

SET DEST="deploy\%MODE%\%MSI%"
del %DEST%

goto end



:compile

rem ---build-msi----------------------------------------


call wix.bat "%MODE%" %MSI% %PLATFORM%

IF ERRORLEVEL 1 GOTO hell


rem ---non priviledged user-----------------------------


SET SRC="bin\%MODE%\%MSI:"=%"
SET DEST="deploy\%PLATFORM%\%MODE%\%MSILIGHT:"=%"

mkdir "deploy\%MODE%"
mkdir "deploy\%PLATFORM%\%MODE%"
copy /Y %SRC% %DEST%

cscript "moeEditMSI.wsf" %DEST%

IF ERRORLEVEL 1 GOTO hell



rem ---admin install------------------------------------


SET DEST="deploy\%PLATFORM%\%MODE%\%MSI%"

copy /Y %SRC% %DEST%


rem ----------------------------------------------------


goto end



:hell


exit /B 1

:end


exit /B 0