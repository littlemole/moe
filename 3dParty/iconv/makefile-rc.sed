s,$[({]top_builddir[)}]/intl/libintl.a,-lintl,
s/^iconv_OBJECTS.*=/& iconv-rc.o/
s/^libcharset_1_OBJECTS.*=/& libcharset-1-rc.o/
s/^libiconv_3_OBJECTS.*=/& libiconv-3-rc.o/
/^.cc*.o:/i\
# Rule to make compiled resource (Windows)\
%-rc.o: %.rc\
	windres -i $< -o $@
s,/cygdrive/\([^/]*\)/,\1:/,g
