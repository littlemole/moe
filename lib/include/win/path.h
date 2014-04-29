#ifndef MOL_FILE_LIB_PATH_DEF_GUARD_DEFINE_
#define MOL_FILE_LIB_PATH_DEF_GUARD_DEFINE_

#include "util/str.h"

namespace mol {

class Path
{
public:

public:

	static std::wstring ext(const std::wstring& path);
    static std::wstring filename(const std::wstring& path);
	static std::wstring pathname(const std::wstring& path);

	static std::wstring stripRoot(const std::wstring& path);
    static std::wstring stripToRoot(const std::wstring& path);
    static std::wstring addBackSlash(const std::wstring& path);
    static std::wstring removeBackSlash(const std::wstring& path);
    static std::wstring addExtension(const std::wstring& path, const std::wstring& ext);
    static std::wstring renameExtension(const std::wstring& path, const std::wstring& ext);
    static std::wstring append(const std::wstring& path,const std::wstring& ap);
	static bool  isSubpath(const std::wstring& path, const std::wstring& p);

    static bool exists(const std::wstring& path);
	static bool isDir(const std::wstring& path);
    static bool isRoot(const std::wstring& path);
	static bool isUNC(const std::wstring& path);
	static bool isNetDrive(const std::wstring& path);
	static std::wstring parentDir(const std::wstring& path);
	static std::wstring serviceName(const std::wstring& path);
	static std::wstring wpath(const std::wstring& path);

private:
	Path(void);
};

}

#endif