@echo off

set CONF=%1
if %1!==! SET CONF=x86-windows

set CWD=%CD%
set VCPKG=%CWD%\vcpkg

IF EXIST %VCPKG%\%CONF%-bootstrapped.txt GOTO alreadybootsrapped

git clone https://github.com/littlemole/vcpkg.git

cd vcpkg

git pull

git checkout moe

cmd /Q /C .\bootstrap-vcpkg


.\vcpkg install zlib:%CONF%
rem .\vcpkg install bzip2:%CONF%
rem .\vcpkg install boost:%CONF%

.\vcpkg install openssl:%CONF%
.\vcpkg install expat:%CONF%
.\vcpkg install gtest:%CONF%
.\vcpkg install libiconv:%CONF%
.\vcpkg install pcre:%CONF%

.\vcpkg install libssh:%CONF%
.\vcpkg install scintilla:%CONF%
.\vcpkg install utf8:%CONF%
.\vcpkg install dtl:%CONF%

copy /y nul %CONF%-bootstrapped.txt

cd ..


:alreadybootsrapped

