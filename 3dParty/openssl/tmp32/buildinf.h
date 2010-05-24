#ifndef MK1MF_BUILD
  /* auto-generated by Configure for crypto/cversion.c:
   * for Unix builds, crypto/Makefile.ssl generates functional definitions;
   * Windows builds (and other mk1mf builds) compile cversion.c with
   * -DMK1MF_BUILD and use definitions added to this file by util/mk1mf.pl. */
  #error "Windows builds (PLATFORM=VC-WIN32) use mk1mf.pl-created Makefiles"
#endif
#ifdef MK1MF_PLATFORM_VC_WIN32
  /* auto-generated/updated by util/mk1mf.pl for crypto/cversion.c */
  #define CFLAGS "cl  /MD /W3 /WX /G5 /Ox /O2 /Ob2 /Gs0 /GF /Gy /nologo -DOPENSSL_SYSNAME_WIN32 -DWIN32_LEAN_AND_MEAN -DL_ENDIAN -DDSO_WIN32 -DOPENSSL_USE_APPLINK -I. /Fdout32dll -DOPENSSL_NO_RC5 -DOPENSSL_NO_MDC2 -DOPENSSL_NO_KRB5    "
  #define PLATFORM "VC-WIN32"
  #define DATE "Mon May 24 14:29:40 2010"
#endif
#ifdef MK1MF_PLATFORM_VC_CE
  /* auto-generated/updated by util/mk1mf.pl for crypto/cversion.c */
  #define CFLAGS "cl  /MD /W3 /WX /G5 /Ox /O2 /Ob2 /Gs0 /GF /Gy /nologo -DOPENSSL_SYSNAME_WIN32 -DWIN32_LEAN_AND_MEAN -DL_ENDIAN -DDSO_WIN32 -DOPENSSL_USE_APPLINK -I. /Fdout32dll -DOPENSSL_NO_RC5 -DOPENSSL_NO_MDC2 -DOPENSSL_NO_KRB5    "
  #define PLATFORM "VC-CE"
  #define DATE "Mon May 24 14:29:40 2010"
#endif
