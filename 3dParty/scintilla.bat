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

