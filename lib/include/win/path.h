#ifndef MOL_FILE_LIB_PATH_DEF_GUARD_DEFINE_
#define MOL_FILE_LIB_PATH_DEF_GUARD_DEFINE_

#include "util/str.h"

namespace mol {

class Path
{
public:

public:

	static mol::string ext(const mol::string& path);
    static mol::string filename(const mol::string& path);
	static mol::string pathname(const mol::string& path);

	static mol::string stripRoot(const mol::string& path);
    static mol::string stripToRoot(const mol::string& path);
    static mol::string addBackSlash(const mol::string& path);
    static mol::string removeBackSlash(const mol::string& path);
    static mol::string addExtension(const mol::string& path, const mol::string& ext);
    static mol::string renameExtension(const mol::string& path, const mol::string& ext);
    static mol::string append(const mol::string& path,const mol::string& ap);
	static bool  isSubpath(const mol::string& path, const mol::string& p);

    static bool exists(const mol::string& path);
	static bool isDir(const mol::string& path);
    static bool isRoot(const mol::string& path);
	static bool isUNC(const mol::string& path);
	static bool isNetDrive(const mol::string& path);
	static mol::string parentDir(const mol::string& path);
	static mol::string serviceName(const mol::string& path);
	static std::wstring wpath(const mol::string& path);

private:
	Path(void);
};

}

#endif