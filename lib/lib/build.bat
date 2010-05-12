
call build.bat lib\src util %1 %2 %3
IF ERRORLEVEL 1 GOTO hell

call build.bat lib\src xml %1 %2 %3
IF ERRORLEVEL 1 GOTO hell

call build.bat lib\src thread %1 %2 %3
IF ERRORLEVEL 1 GOTO hell

call build.bat lib\src tcp %1 %2 %3
IF ERRORLEVEL 1 GOTO hell

call build.bat lib\src ssl %1 %2 %3
IF ERRORLEVEL 1 GOTO hell

call build.bat lib\src http %1 %2 %3
IF ERRORLEVEL 1 GOTO hell

call build.bat lib\src win %1 %2 %3
IF ERRORLEVEL 1 GOTO hell

call build.bat lib\src ole %1 %2 %3
IF ERRORLEVEL 1 GOTO hell


rem SUCCESS

goto end

:hell

echo on

rem FAILURE :-(

exit /B 1

:end

exit /B 0