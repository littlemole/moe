building moe
------------

I) pre steps
============

a) pre-requisites:

	* Visual Studio 2017
	* WIX 3.8
	* java jdk
	* ant ( for java extensions )
    * git

b) setup environment
	* JAVA_HOME is supposed to point to a java sdk >= 1.6
	* ant is supposed to be on the PATH
	* WIX environment variable points to WIX installation. 
	  (hint: for a fresh WIX install a new login session is needed.)

  

II) compiling moe
================


a) full build

to run a full build open a regular cmd prompt, navigate to molib root folder and type:
C:\molib> nb.bat armageddon

this will do a clean followed by a full release build of moe, its com controls, internal libraries as well as bootsrapping the external dependencies for
both x86 and x64 if not avail yet. It will also compile the installer packages.

replace armageddon with kosmos to skip the clean step. to only clean, replace armageddon with clean.

b) single platform build

to create a debug build only for x64 or x86, specify:
C:\molib> nbs.bat uni_debug x86 armageddon

replace uni_debug with uni_release to crate a release build. replace x86 with x64 to go 64bit.
replace armageddon with kosmos to skip the clean step. to only clean, replace armageddon with clean.

c) only build a specific project

first, from a new cmd line window navigate to molib's root folder and type:
C:\molib> env.bat uni_debug x86

to initialize a debug environment for the x86 platform. 

then use msbuild as follows, to build the win library:
C:\molib> cd lib\src\win
C:\molib\lib\src\win> msbuild build.xml

in order to clean a project, run:
C:\molib\lib\src\win> msbuild build.xml /t:Clean


bootstrap
---------

note that on first run 3dParty dependencies are bootstraped using vcpkg which is checked out from git.

delete the files

- x86-windows-static-bootstrapped.txt
- x64-windows-static-bootstrapped.txt

in the ./vcpkg subfolder and run nb armageddon again to re-bootstrap the 3dParty dependencies.

