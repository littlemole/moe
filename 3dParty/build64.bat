devenv ".\expat\Source\expat.sln" /rebuild "Unicode Debug 64|x64" /project "expat_static" /projectconfig "Unicode Debug 64|x64"
If Errorlevel 1 goto hell

devenv ".\expat\Source\expat.sln" /rebuild "uni_release_64|x64" /project "expat_static" /projectconfig "uni_release_64|x64"
If Errorlevel 1 goto hell

devenv ".\pcre\pcre.sln" /rebuild "Unicode Debug 64|x64" /project "pcre" /projectconfig "Unicode Debug 64|x64"
If Errorlevel 1 goto hell

devenv ".\pcre\pcre.sln" /rebuild "uni_release_64|x64" /project "pcre" /projectconfig "uni_release_64|x64"
If Errorlevel 1 goto hell




call build.openssl64.bat
If Errorlevel 1 goto hell




cd scintilla
cd win32

nmake -f scintilla-static64.mak clean
del *.o
nmake -f deps.mak

If Errorlevel 1 goto scihell

nmake -f scintilla-static64.mak DEBUG=1 

If Errorlevel 1 goto scihell

nmake -f scintilla-static64.mak clean
del *.o
nmake -f deps.mak

nmake -f scintilla-static64.mak 

If Errorlevel 1 goto scihell

cd ..
cd ..


exit /B 0




:scihell

cd ..
cd ..



:hell

exit /B 1

