#include "win/path.h"
#include "util/istr.h"

namespace mol {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


std::wstring Path::ext(const std::wstring& path)
{
	std::wstring p = Path::removeBackSlash(path);
	size_t pos = p.find_last_of(_T("."));
	if ( (pos != std::wstring::npos) && (pos < p.size()-1) )
		return p.substr(pos);
	return _T("");
}

std::wstring Path::filename(const std::wstring& path)
{
	std::wstring p = Path::removeBackSlash(path);
	size_t pos = p.find_last_of(_T("/\\"));
	if ( (pos != std::wstring::npos) && (pos < p.size()-2) )
		p = p.substr(pos+1);
	if ( (pos = p.find_first_of(_T("?#"))) != std::string::npos )
	{
		return p.substr(0,pos);
	}
	return p;
}

std::wstring Path::pathname(const std::wstring& path)
{
	std::wstring p = Path::removeBackSlash(path);
	size_t pos = p.find_last_of(_T("/\\"));
	if ( (pos != std::wstring::npos) && (pos < p.size()-2) )
		return p.substr(0,pos);
	return p;
}

std::wstring Path::stripRoot(const std::wstring& fn)
{
	std::wstring path(fn);
	size_t pos = path.find_first_of(_T("/\\"));
	if ( (pos != std::wstring::npos) && (pos != path.size()) )
	{
		size_t p   = path.find_first_not_of(_T("/\\"),pos);
		if ( (p != std::wstring::npos) && (p != path.size()) )
			pos = p;
		path = path.substr(pos);
	}
	return path;	
}

std::wstring Path::stripToRoot(const std::wstring& fn)
{
	std::wstring path(fn);
	size_t pos = path.find(_T(":\\\\"));
	if ( pos == 1 )
	{
		path = path.substr(0,3);
		return path;
	}

	pos = path.find(_T(":\\"));
	if ( pos == 1 )
	{
		path = path.substr(0,3);
		return path;
	}
	pos = path.find(_T("\\\\"));
	if ( pos == 0 )
	{
		size_t p = path.find(_T("\\"),3);
		if ( p != std::wstring::npos )
		{
			path = path.substr(0,p);
			return path;
		}
	}
	pos = path.find(_T("://"));
	if ( pos != std::wstring::npos )
	{
		size_t p = path.find(_T("/"),pos+3);
		if ( pos != std::wstring::npos )
		{
			path = path.substr(0,p);
			return path;
		}
	}
	if ( path.size() > 1 )
	{
		pos = path.find_first_of(_T("/\\"),2);
		if ( pos != std::wstring::npos )
		{
			path = path.substr(0,pos);
			return path;
		}
	}
	return path;
}

std::wstring Path::addBackSlash(const std::wstring& path)
{
	std::wstring p(path);
	if ( p.size() > 0 )
		if ( p[p.size()-1] != _T('\\') )
			p += _T("\\");
    return p;
}

std::wstring Path::removeBackSlash(const std::wstring& path)
{
	std::wstring p(path);
	if ( p.size() > 0 )
		if ( p[p.size()-1] == _T('\\') )
			p.erase(p.size()-1,1);
    return p;
}

std::wstring Path::addExtension(const std::wstring& path,const std::wstring& e)
{
	std::wstring p(path);
    if ( ext(path) == _T("") )
		p += e;
    return p; 
}

std::wstring Path::renameExtension(const std::wstring& path,const std::wstring& e)
{
	std::wstring p(path);
    if ( ext(path) == _T("") )
		p = p.substr(0,p.size()-ext(path).size());
	else
		p += _T(".");
	p += e;
    return p; 
}

std::wstring Path::append(const std::wstring& path,const std::wstring& ap)
{
	std::wstring ret = Path::addBackSlash(path);
	std::wstring a(ap);
	if ( a[0] == _T('\\') )
		a = a.substr(1);

	ret += a;
    return ret; 
}
bool Path::isNetDrive(const std::wstring& path)
{
	return DRIVE_REMOTE == GetDriveType(path.c_str());
}

bool Path::isUNC(const std::wstring& path)
{
	return path.substr(0,2) == _T("\\\\");
}

std::wstring Path::serviceName(const std::wstring& path)
{
	if ( isUNC(path) )
	{
		return path.substr(0,path.find(_T('/'),3));
	}
	std::wstring remotename;
	std::wstring p(path);
	p = stripToRoot(p);
	p = removeBackSlash(p);
	if ( isNetDrive(p) )
	{		
		std::wstring localname(mol::str::toupper(p));
		DWORD len = 0;
		::WNetGetConnection(p.c_str(), 0, &len);
		if ( len )
		{
			mol::wbuff buf(len);
			if (::WNetGetConnection(p.c_str(), buf, &len) )
			{
				remotename = buf.toString(len);
			}
		}
	}
	return remotename;
}

std::wstring Path::wpath(const std::wstring& path)
{
	std::wstring ws = mol::towstring(path);

	if ( isUNC(path) )
		ws = L"\\\\?\\UNC\\" + ws.substr(2);
	else
		ws = L"\\\\?\\" + ws;

	return ws;
}

bool Path::exists(const std::wstring& path)
{
	if ( path.empty() )
		return false;

	DWORD attributes = ::GetFileAttributesW(wpath(path).c_str());
	return (attributes != INVALID_FILE_ATTRIBUTES);
}

bool Path::isDir(const std::wstring& path)
{
	if ( path.empty() )
		return false;

	if ( isUNC(path) ) 
	{
		std::wstring tmp = path.substr(2);
		size_t p = tmp.find_first_of(_T("/\\"));
		if ( p == std::wstring::npos ) 
		{
			// top level network share
			return true;
		}
	}

	DWORD attributes = ::GetFileAttributesW(wpath(path).c_str());
	if ( attributes == INVALID_FILE_ATTRIBUTES )
	{
		DWORD e = ::GetLastError();
		if (  e == ERROR_BAD_NETPATH )
			return true;
		return false;
	}
	return (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
}

bool Path::isRoot(const std::wstring& path)
{
	std::wstring p(path);
	p = stripToRoot(p);
	if ( p == path )
		return true;
	return false;
}

std::wstring Path::parentDir(const std::wstring& path)
{
    std::wstring ret = path;

	if ( path.size() == 0 )
		return ret;

    if ( ret[ret.size()-1] == _T('\\') )
      ret.erase(ret.size()-1);

    size_t pos = ret.find_last_of(_T('\\'));
    if ( pos != std::wstring::npos )
    {
      ret = ret.substr(0,pos);
    }
    else ret = _T("");

    return ret;
}

bool Path::isSubpath(const std::wstring& path,const std::wstring& p)
{
	std::wstring p1(path);
	std::wstring p2(p);

	if ( filename(p1) != p1.c_str() )
	{
		p1 = pathname(p1);
	}

	if ( filename(p2) != p2.c_str() )
	{
		p2 = pathname(p2);
	}

	std::wstring  ci1 = mol::str::tolower( p1.c_str() );
	std::wstring  ci2 = mol::str::tolower( p2.c_str() );

	if ( ci1 == ci2 )
		return false;

	size_t pos = ci1.find(ci2);
	return ( pos != std::wstring::npos ) ;
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////



}

