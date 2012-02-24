@echo off

rem syntax:
rem call release.bat [source dir] [remote parent dir] [remote sub dir] 
rem

call release.bat bin\WiXMoe\deploy\uni_debug moe uni_debug
call release.bat bin\WiXMoe\deploy\uni_release moe uni_release
call release.bat bin\WiXMoe\deploy\x64\uni_debug moe x64_uni_debug
call release.bat bin\WiXMoe\deploy\x64\uni_release moe x64_uni_release

call release.bat bin\WixMoeEx\deploy\uni_debug moe-ex uni_debug
call release.bat bin\WixMoeEx\deploy\uni_release moe-ex uni_release
call release.bat bin\WixMoeEx\deploy\x64\uni_debug moe-ex x64_uni_debug
call release.bat bin\WixMoeEx\deploy\x64\uni_release moe-ex x64_uni_release


call release.bat bin\WiXMoe\deploy\regfree\uni_debug moe-regfree uni_debug
call release.bat bin\WiXMoe\deploy\regfree\uni_release moe-regfree uni_release
call release.bat bin\WiXMoe\deploy\regfree\x64\uni_debug moe-regfree x64_uni_debug
call release.bat bin\WiXMoe\deploy\regfree\x64\uni_release moe-regfree x64_uni_release