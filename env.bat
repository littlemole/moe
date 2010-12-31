set CONF=%1
if %1!==! SET CONF=uni_debug

set PLAT=%2
if %2!==! set PLAT=/x86

if "%CONF%"=="uni_debug" goto debug

set CONFIG=/Release
goto psdk

:debug
set CONFIG=/Debug


:psdk
call "C:\Program Files\Microsoft SDKs\Windows\v7.1\bin\SetEnv.Cmd" %CONFIG% %PLAT%

set Configuration=%CONF%

echo Configuration: %Configuration%
exit /B
