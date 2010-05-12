
call build.bat bin moe %1 %2 %3
IF ERRORLEVEL 1 GOTO hell

call build.bat bin\prw prw %1 %2 %3
IF ERRORLEVEL 1 GOTO hell


rem IF %3!==! GOTO wix

GOTO end

:wix

call wix.bat %1 moeSetup
IF ERRORLEVEL 1 GOTO hell

rem SUCCESS

goto end

:hell

echo on

rem FAILURE :-(

exit /B 1

:end

exit /B 0