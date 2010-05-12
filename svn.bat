set OLDDIR=%CD%

C:
cd C:\Cygwin\bin

set WHAT=%1
if NOT "%1!"=="!" SET WHAT=%WHAT:\=/%

set WHERE=%2
SET WHERE=%WHERE:"=%
SET WHERE=%OLDDIR%\%WHERE%
if NOT "%WHERE%!"=="!" SET WHERE=%WHERE:\=/%



svn "%WHAT%" "%WHERE%"

chdir /D %OLDDIR%