
cd openssl

perl Configure VC-WIN64A

call ms\do_win64a

nmake -f ms\ntd64.mak clean
nmake -f ms\ntd64.mak

If Errorlevel 1 goto hell

nmake -f ms\nt64.mak clean
nmake -f ms\nt64.mak

If Errorlevel 1 goto hell

cd ..

exit /B 0

:hell 

cd ..

exit /B 1








