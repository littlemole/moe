
echo "building the moe universe"
echo %1 %2 %3

call env %1 %2

echo %Platform% %Configuration%
msbuild build.xml /t:%3
if ERRORLEVEL 1 GOTO hell


:done
exit /B 0

:hell
exit /B 1
