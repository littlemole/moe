
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

