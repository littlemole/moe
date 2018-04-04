rem ###################################################
rem do a single full build
rem ###################################################

echo "building the moe universe"
echo %1 %2 %3

rem ###################################################
rem prepare environment
rem ###################################################

call env %1 %2

echo %Platform% %Configuration%

rem ###################################################
rem lauch msbuild
rem ###################################################

msbuild build.xml /t:%3

if ERRORLEVEL 1 GOTO hell


rem ###################################################
rem error handler
rem ###################################################

:done
exit /B 0

:hell
exit /B 1
