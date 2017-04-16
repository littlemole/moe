
echo "building the moe universe"
echo %1 %2 %3

if "%2"=="x86" goto x86

call boot x64-windows-static
goto start

:x86
call boot x86-windows-static

:start
call env15 %1 %2

echo %Platform% %Configuration%
msbuild build.xml /t:%3
if ERRORLEVEL 1 GOTO hell


:done
exit /B 0

:hell
exit /B 1
