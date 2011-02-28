building moe
------------

a) setup the env

call env.bat specifying configuration and platform:

either of:
	env uni_debug /x86
	env uni_release /x86
	env uni_debug /x64
	env uni_release /x64

env.bat is a simple batch file which calls SetEnv.cmd from the PLATFORM SDK

it expects the platform sdk at the default location, modify if necessary:
"C:\Program Files\Microsoft SDKs\Windows\v7.1\bin\SetEnv.Cmd"


b) optional: use msbuild to (re)build 3dparty libs

	cd 3dParty
	msbuild build.xml /t:Clean
	msbuild build.xml
	cd ..

c) build moe

	msbuild build.xml /t:Clean
	msbuild build.xml


pre-requisites:

	* Win 7.1 SDK
	* boost 
	* activestate perl
