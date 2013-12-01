building moe
------------

a) pre-requisites:


	* Win 7.1 SDK
        * WIX 3.5
	* boost 
	* activestate perl
        * java jdk
        * ant ( for extensions )



b) setup paths


check master.props for paths to external dependencies:

  * boost
  * java (for extentions, see below)

perl and ant are supposed to be in the path


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

	* (should be obsolete requirement:) moe must be installed in the version (win32/x64) matching the
	  build environment
        * ant must be in the path (for java)


        msbuild build.xml /t:cleanjre
        msbuild build.xml /t:jre

        msbuild build.xml /t:cleannet
        msbuild build.xml /t:net



issues (when running without vs studio 2010 installed, only winsdk. probably occurs when .NET 4.5+ and/or VC 2012/2013 installed on a win7 box):

1)

http://stackoverflow.com/questions/10888391/error-link-fatal-error-lnk1123-failure-during-conversion-to-coff-file-inval


find installed versions of cvtres.exe in your PATH using where cvtres.exe
Delete/rename the ones installed into vc2010 subdirs, use the ones from .NET 4.5 instead

2)

Windows Update KB2455033 breaks build with missing ammintrin.h

Install KB2519277 first, then install KB2455033 (only avail via windows update).



http://blogs.msdn.com/b/vcblog/archive/2011/03/31/10148110.aspx


3)

from http://blogs.msdn.com/b/vcblog/archive/2011/03/31/10148110.aspx

Our recommended install order is:

    Visual Studio 2010
    Windows SDK 7.1
    Visual Studio 2010 SP1
    Visual C++ 2010 SP1 Compiler Update for the Windows SDK 7.1

