building moe
------------

run from a 32bit or 64bit Visual C++ command line


make.bat
--------


builds a 32 or 64 bit moe build, depending on the 
Visual C++ Environment chosen

usage: make.bat [CONF] [(optional:TARGET)] 

with
	CONF : (Debug|Release|"Unicode Debug"|uni_release) on 32bit
               ("Unicode Debug 64"|uni_release_64) for 64bit

	TARGET : "/clean" - just cleans files
                 "/rebuild" - rebuild all

if TARGET is ommited, an incremental build is done, compiling only
changed files






build.bat
---------

used to build a single project

usage: build.bat [BUILDPATH] [PROJECTNAME] [CONF] [PLATFORM] [(optional:TARGET)]

with
	BUILDPATH : path to project, ie "bin\moe"

	PROJECTNAME : project name without extension, ie "moe"

	CONF : (Debug|Release|"Unicode Debug"|uni_release) on 32bit
               ("Unicode Debug 64"|uni_release_64) for 64bit

	PLATFORM : (Win32|x64)

	TARGET : "/clean" - just cleans files
                 "/rebuild" - rebuild all

if TARGET is ommited, an incremental build is done, compiling only
changed files
	




wix.bat
-------

used to build moe installers the wix way

usage: wix.bat [CONF] [MSINAME] [PLATFORM] [(optional:TARGET)]

	CONF : (Debug|Release|"Unicode Debug"|uni_release) on 32bit
               ("Unicode Debug 64"|uni_release_64) for 64bit

	PROJECTNAME : msi name without extension, ie "moeSetup"

	PLATFORM : (Win32|x64)

	TARGET : "/clean" - just cleans files


if TARGET is ommited or not "/clean", an fresh package-build is done






vdp.bat (deprecated)
-------


builts a msi installer from a .vdproj

usage: vdp.bat [CONF] [MODE] [MSINAME]

	CONF : (Debug|Release|"Unicode Debug"|uni_release)|Win32 on 32bit
               ("Unicode Debug 64"|uni_release_64)|x64 for 64bit

	MODE : (Debug|Release|"Unicode Debug"|uni_release) on 32bit
               ("Unicode Debug 64"|uni_release_64) for 64bit

	[MSINAME]: msi name without extension, ie "moeSetup"

note CONF is followed by |Win32 or |x64
while MODE is not, thats the point here




nb32.bat / nb64.bat
-------------------

"nightly build" scripts. to be started from a fresh, non vc command line
will compile REALLY all

both take no arguments


################################


batchfiles in subdirs:
----------------------



molib/3dParty
-------------

build.bat          - builds 32bit prerequisites
build64.bat        - builds 64bit prerequisites

both take no arguments



build.openssl.bat     - builds openssl for 32bit windows
build.openssl64.bat   - builds openssl for 64bit windows

both take no arguments and are called from molib/3dParty/build(64).bat




molib/lib
molib/ax
molib/bin
---------

build.bat  	- calls molib/build.bat for each lib/ax supported in win32

usage: 
	lib\build.bat [CONF] [PLATFORM] [TARGET]
	ax\build.bat  [CONF] [PLATFORM] [TARGET]
	bin\build.bat [CONF] [PLATFORM] [TARGET]

with
	CONF : (Debug|Release|"Unicode Debug"|uni_release) on 32bit
               ("Unicode Debug 64"|uni_release_64) for 64bit

	PLATFORM : (Win32|x64)

	TARGET : "/clean" - just cleans files
                 "/rebuild" - rebuild all

if TARGET is ommited, an incremental build is done, compiling only
changed files





