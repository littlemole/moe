
call build.bat ax io %1 %2 %3
IF ERRORLEVEL 1 GOTO hell

call build.bat ax comtypes %1 %2 %3
IF ERRORLEVEL 1 GOTO hell

call build.bat ax setting %1 %2 %3
IF ERRORLEVEL 1 GOTO hell

call build.bat ax process %1 %2 %3
IF ERRORLEVEL 1 GOTO hell

call build.bat ax ShellCtrl %1 %2 %3
IF ERRORLEVEL 1 GOTO hell

call build.bat ax ShellFolder %1 %2 %3
IF ERRORLEVEL 1 GOTO hell

call build.bat ax ScintillAx %1 %2 %3
IF ERRORLEVEL 1 GOTO hell

rem SUCCESS

goto end

:hell

echo on

rem FAILURE :-(

exit /B 1

:end

exit /B 0