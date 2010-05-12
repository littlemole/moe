@rem OpenSSL with Mingw32
@rem --------------------

@rem Makefile
@rem perl util\mkfiles.pl >MINFO
@rem perl util\mk1mf.pl Mingw32 >ms\mingw32.mak
@rem DLL definition files
@rem perl util\mkdef.pl 32 libeay >ms\libeay32.def
@rem if errorlevel 1 goto end
@rem perl util\mkdef.pl 32 ssleay >ms\ssleay32.def
@rem if errorlevel 1 goto end

@rem goto end

@rem Build the libraries
C:\gnu\usr\local\wbin\make -f .\ms\mingw32.mak
if errorlevel 1 goto end

@rem Generate the DLLs and input libraries
dllwrap --dllname libeay32.dll --output-lib outMinGw\libeay32.a --def ms\libeay32.def outMinGw\libcrypto.a -lwsock32 -lgdi32
if errorlevel 1 goto end
dllwrap --dllname libssl32.dll --output-lib outMinGw\libssl32.a --def ms\ssleay32.def outMinGw\libssl.a outMinGw\libeay32.a
if errorlevel 1 goto end

echo Done compiling OpenSSL

:end

