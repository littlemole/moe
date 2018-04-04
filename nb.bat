rem ###################################################
rem make both x86 and x64 builds
rem syntax:
rem 		nb.bat [clean|build|kosmos|armageddon]
rem defaults to build. see build.xml for a full list
rem of targets.
rem ###################################################


rem cmd /Q /C nbs.bat uni_debug x86 %1
rem if ERRORLEVEL 1 GOTO hell
rem 
rem cmd /Q /C nbs.bat uni_debug x64 %1
rem if ERRORLEVEL 1 GOTO hell

cmd /Q /C nbs.bat uni_release x86 %1
if ERRORLEVEL 1 GOTO hell

cmd /Q /C nbs.bat uni_release x64 %1
if ERRORLEVEL 1 GOTO hell

:done
echo "SUCCESS"
exit /B 0

:hell
echo BUILD FAILED

exit /B 1

