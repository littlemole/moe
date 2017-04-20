@echo off

set CONF=%1
if %1!==! SET CONF=x86-windows

IF EXIST %VCPKG%\vswhere.exe GOTO alreadyhavevswhere

cscript /nologo winget.js https://github.com/Microsoft/vswhere/releases/download/1.0.62/vswhere.exe vswhere.exe

:alreadyhavevswhere

for /f "usebackq tokens=1* delims=: " %%i in (`vswhere -latest`) do (
  if /i "%%i"=="installationPath" set VSROOT=%%j
)

echo VSROOT=%VSROOT%

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

