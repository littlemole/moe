call "C:\Program Files\Microsoft Visual Studio 9.0\VC\vcvarsall.bat" x86_amd64

cd 3dParty

call build64.bat
IF ERRORLEVEL 1 GOTO 3dPartyHell

cd ..

call make.bat "Unicode Debug 64" "/clean"
IF ERRORLEVEL 1 GOTO hell

call make.bat "uni_release_64" "/clean"
IF ERRORLEVEL 1 GOTO hell

call make.bat "Unicode Debug 64" 
IF ERRORLEVEL 1 GOTO hell

call make.bat "uni_release_64" 
IF ERRORLEVEL 1 GOTO hell


call vdp.bat "Unicode Debug 64|x64" "Unicode Debug 64" "moeSetup64"
IF ERRORLEVEL 1 GOTO hell

call vdp.bat "uni_release_64|x64" "uni_release_64" "moeSetup64"
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