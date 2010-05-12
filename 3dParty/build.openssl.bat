
cd openssl

perl Configure VC-WIN32

call ms\do_ms

nmake -f ms\ntd.mak clean
nmake -f ms\ntd.mak


If Errorlevel 1 goto hell

nmake -f ms\ntmoe.mak clean

nmake -f ms\ntmoe.mak


If Errorlevel 1 goto hell

cd ..

exit /B 0

:hell 

cd ..

exit /B 1








