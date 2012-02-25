@echo off

SET SRC=%1
SET TARGET=%2
SET MODE=%3

set year=%date:~-4%
rem echo year=%year%

set month=%date:~-7,-5%
if "%month:~0,1%" == " " set month=0%month:~1,1%
rem echo month=%month%

set day=%date:~0,2%
if "%day:~0,1%" == " " set day=0%day:~1,1%
rem echo day=%day%

set TODAY=%year%-%month%-%day%
echo %TODAY%

rem SET TODAY=%date:~-4%-%date:~-7,-5%-%date:~0,2%


SET REMOTE_DIR=/srv/www/htdocs/oha7/moe/%TODAY%/
set SCP="C:\Program Files (x86)\PuTTY\pscp.exe" -i "C:\Users\mike\putty2betty.ppk"
set RC="C:\Program Files (x86)\PuTTY\plink.exe" -i "C:\Users\mike\putty2betty.ppk" mike@knitbits.de

SET MAKEDATE="TODAY=$(date +%Y-%m-%d);"

echo %REMOTE_DIR%
echo %SCP%
echo %RC%


%RC% mkdir %REMOTE_DIR%
%RC% chmod 777 %REMOTE_DIR%
%RC% mkdir %REMOTE_DIR%/%TARGET%
%RC% chmod 777 %REMOTE_DIR%/%TARGET%
%RC% mkdir %REMOTE_DIR%/%TARGET%/%MODE%
%RC% chmod 777 %REMOTE_DIR%/%TARGET%/%MODE%

%SCP% %SRC%\*.* mike@knitbits.de:%REMOTE_DIR%/%TARGET%/%MODE%

%RC% ls %REMOTE_DIR%/%TARGET%/%MODE% -lah
