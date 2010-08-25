rem call "C:\Program Files (x86)\Microsoft Visual Studio 9.0\VC\vcvarsall.bat" x86

rem goto skip

cd 3dParty

call build.bat
IF ERRORLEVEL 1 GOTO 3dPartyHell

cd ..

:skip

echo ----clean-------------------------------

call make.bat "Debug" "/clean"
IF ERRORLEVEL 1 GOTO hell

call make.bat "Release" "/clean"
IF ERRORLEVEL 1 GOTO hell

call make.bat "Unicode Debug" "/clean"
IF ERRORLEVEL 1 GOTO hell

call make.bat "uni_release" "/clean"
IF ERRORLEVEL 1 GOTO hell


echo ----compile-------------------------------

set TARGET=""

call make.bat "Debug" 
IF ERRORLEVEL 1 GOTO hell

call make.bat "Release" 
IF ERRORLEVEL 1 GOTO hell

call make.bat "Unicode Debug" 
IF ERRORLEVEL 1 GOTO hell

call make.bat "uni_release" 
IF ERRORLEVEL 1 GOTO hell

echo "SUCCESS"
goto end


echo ----package-------------------------------

call vdp.bat "Debug|Win32" "Debug" "moeSetup"
IF ERRORLEVEL 1 GOTO hell

call vdp.bat "Unicode Debug|Win32" "Unicode Debug" "moeSetup"
IF ERRORLEVEL 1 GOTO hell

call vdp.bat "Release|Win32" "Release" "moeSetup"
IF ERRORLEVEL 1 GOTO hell

call vdp.bat "uni_release|Win32" "uni_release" "moeSetup"
IF ERRORLEVEL 1 GOTO hell


echo "SUCCESS"
goto end




:3dPartyHell

cd ..




:hell

echo "BUILD FAILED!"


exit 1

:end

exit 0