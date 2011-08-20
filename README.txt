building moe
------------

a) pre-requisites:


	* Win 7.1 SDK
	* boost 
	* activestate perl
        * ant ( for extensions )



b) setup paths


check master.props for paths to external dependencies:

  * boost
  * java (for extentions, see below)



c) setup the env


call env.bat specifying configuration and platform:

either of:
	env uni_debug /x86
	env uni_release /x86
	env uni_debug /x64
	env uni_release /x64

env.bat is a simple batch file which calls SetEnv.cmd from the PLATFORM SDK

it expects the platform sdk at the default location, modify if necessary:
"C:\Program Files\Microsoft SDKs\Windows\v7.1\bin\SetEnv.Cmd"



d) optional: use msbuild to (re)build 3dparty libs


	cd 3dParty
	msbuild build.xml /t:Clean
	msbuild build.xml
	cd ..


e) build moe

	msbuild build.xml /t:Clean
	msbuild build.xml



f) building moe extension (jre and net)

	* moe must be installed in the version (win32/x64) matching the
	  build environment
        * ant must be in the path (for java)


        msbuild build.xml /t:cleanjre
        msbuild build.xml /t:jre

        msbuild build.xml /t:cleannet
        msbuild build.xml /t:net