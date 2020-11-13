@echo off

set CONF=%1
if %1!==! SET CONF=x86-windows

IF EXIST .\vswhere.exe GOTO alreadyhavevswhere

@echo "download wshere.exe"
cscript /nologo winget.js "https://github.com/Microsoft/vswhere/releases/download/1.0.62/vswhere.exe" vswhere.exe

@echo "download webview SDK"
cscript /nologo winget.js "https://www.nuget.org/api/v2/package/Microsoft.Web.WebView2/1.0.622.22" bin/moe/packages/webview.zip
cscript /nologo cg\bin\unzip.vbs bin\moe\packages\webview.zip bin\moe\packages\Microsoft.Web.WebView2.1.0.622.22

@echo "download webview runtime web installer"
cscript /nologo winget.js https://go.microsoft.com/fwlink/p/?LinkId=2124703  bin/moeBundle/prereq/MicrosoftEdgeWebview2Setup.exe

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


.\vcpkg install zlib:%CONF%-static
rem .\vcpkg install bzip2:%CONF%-static
rem .\vcpkg install boost:%CONF%-static

.\vcpkg install openssl:%CONF%-static
.\vcpkg install expat:%CONF%-static
.\vcpkg install gtest:%CONF%-static
.\vcpkg install libiconv:%CONF%-static
.\vcpkg install pcre:%CONF%-static

.\vcpkg install libssh:%CONF%-static
.\vcpkg install scintilla:%CONF%-static
.\vcpkg install utf8:%CONF%-static
.\vcpkg install dtl:%CONF%-static
.\vcpkg install jsoncpp:%CONF%-static

copy /y nul %CONF%-bootstrapped.txt

cd ..


:alreadybootsrapped

