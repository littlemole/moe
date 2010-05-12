devenv "expat\Source\expat.sln" /rebuild "Debug|Win32" /project "expat_static" /projectconfig "Debug|Win32"
If Errorlevel 1 goto hell

devenv ".\expat\Source\expat.sln" /rebuild "Release|Win32" /project "expat_static" /projectconfig "Release|Win32"
If Errorlevel 1 goto hell

devenv ".\expat\Source\expat.sln" /rebuild "Unicode Debug|Win32" /project "expat_static" /projectconfig "Unicode Debug|Win32"
If Errorlevel 1 goto hell

devenv ".\expat\Source\expat.sln" /rebuild "uni_release|Win32" /project "expat_static" /projectconfig "uni_release|Win32"
If Errorlevel 1 goto hell

devenv ".\pcre\pcre.sln" /rebuild "Debug|Win32" /project "pcre.vcproj" /projectconfig "Debug|Win32"
If Errorlevel 1 goto hell

devenv ".\pcre\pcre.sln" /rebuild "Release|Win32" /project "pcre.vcproj" /projectconfig "Release|Win32"
If Errorlevel 1 goto hell

devenv ".\pcre\pcre.sln" /rebuild "Unicode Debug|Win32" /project "pcre.vcproj" /projectconfig "Unicode Debug|Win32"
If Errorlevel 1 goto hell

devenv ".\pcre\pcre.sln" /rebuild "uni_release|Win32" /project "pcre.vcproj" /projectconfig "uni_release|Win32"
If Errorlevel 1 goto hell



call build.openssl.bat
If Errorlevel 1 goto hell



cd scintilla
cd win32

nmake -f scintilla-static.mak clean
del *.o
nmake -f deps.mak

If Errorlevel 1 goto scihell

nmake -f scintilla-static.mak DEBUG=1 

If Errorlevel 1 goto scihell

nmake -f scintilla-static.mak clean
del *.o
nmake -f deps.mak

nmake -f scintilla-static.mak 

If Errorlevel 1 goto scihell

cd ..
cd ..


exit /B  0

:hell

exit /B 1

:scihell

cd ..
cd ..


exit /B 1

