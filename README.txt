building moe
------------

I) pre steps
============

a) pre-requisites:

	* Visual Studio 2015
    * WIX 3.8
	* boost (recommended: 1.61)
	* perl (recommended: activestate perl)
    * java jdk
    * ant ( for java extensions )

b) setup environment
	* JAVA_HOME is supposed to point to a java sdk >= 1.6
	* ant is supposed to be on the PATH
	* perl is supposed to be on the PATH
	* WIX environment variable points to WIX installation. 
	  (hint: for a fresh WIX install a new login session is needed.)

c) configure paths


check env14.bat for paths to external dependencies and verify the are correct

  * PlatformToolset should be set to v14 for Visual Studio 2015
  * VCVARSBAT should point to the Visual Studio vcvarsall.bat script
  * boost variable should point to a recent boost libraries installation. boost must not be compiled we only use include only libraries.
  * UICC variable should point to the ms ribbon compiler. 8.1 is recommended.
  * java should point to the JDK native c++ include directories. Should work out of the box if JAVA_HOME is set properly.
  

II) compiling moe
================


a) full build

to run a full build open a regular cmd prompt, navigate to molib root folder and type:
C:\molib> nb.bat armageddon

this will do a clean followed by a full release build of moe, its com controls, internal libraries as well as compile the external dependencies for
both x86 and x64. It will also compile the installer packages.

replace armageddon with kosmos to skip the clean step. to only clean, replace armageddon with clean.

b) single platform build

to create a debug build only for x64 or x86, specify:
C:\molib> nbs.bat uni_debug x86 armageddon

replace uni_debug with uni_release to crate a release build. replace x86 with x64 to go 64bit.
replace armageddon with kosmos to skip the clean step. to only clean, replace armageddon with clean.

c) only build a specific project

first, from a new cmd line window navigate to molib's root folder and type:
C:\molib> env14.bat uni_debug x86

to initialize a debug environment for the x86 platform. 

then use msbuild as follows, to build the win library:
C:\molib> cd lib\src\win
C:\molib\lib\src\win> msbuild build.xml

in order to clean a project, run:
C:\molib\lib\src\win> msbuild build.xml /t:Clean
