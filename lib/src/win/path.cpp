#include "win/path.h"
#include "util/istr.h"

namespace mol {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


mol::string Path::ext(const mol::string& path)
{
	mol::string p = Path::removeBackSlash(path);
	size_t pos = p.find_last_of(_T("."));
	if ( (pos != mol::string::npos) && (pos < p.size()-1) )
		return p.substr(pos);
	return _T("");
}

mol::string Path::filename(const mol::string& path)
{
	mol::string p = Path::removeBackSlash(path);
	size_t pos = p.find_last_of(_T("/\\"));
	if ( (pos != mol::string::npos) && (pos < p.size()-2) )
		p = p.substr(pos+1);
	if ( (pos = p.find_first_of(_T("?#"))) != std::string::npos )
	{
		return p.substr(0,pos);
	}
	return p;
}

mol::string Path::pathname(const mol::string& path)
{
	mol::string p = Path::removeBackSlash(path);
	size_t pos = p.find_last_of(_T("/\\"));
	if ( (pos != mol::string::npos) && (pos < p.size()-2) )
		return p.substr(0,pos);
	return p;
}

mol::string Path::stripRoot(const mol::string& fn)
{
	mol::string path(fn);
	size_t pos = path.find_first_of(_T("/\\"));
	if ( (pos != mol::string::npos) && (pos != path.size()) )
	{
		size_t p   = path.find_first_not_of(_T("/\\"),pos);
		if ( (p != mol::string::npos) && (p != path.size()) )
			pos = p;
		path = path.substr(pos);
	}
	return path;	
}

mol::string Path::stripToRoot(const mol::string& fn)
{
	mol::string path(fn);
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
		if ( p != mol::string::npos )
		{
			path = path.substr(0,p);
			return path;
		}
	}
	pos = path.find(_T("://"));
	if ( pos != mol::string::npos )
	{
		size_t p = path.find(_T("/"),pos+3);
		if ( pos != mol::string::npos )
		{
			path = path.substr(0,p);
			return path;
		}
	}
	if ( path.size() > 1 )
	{
		pos = path.find_first_of(_T("/\\"),2);
		if ( pos != mol::string::npos )
		{
			path = path.substr(0,pos);
			return path;
		}
	}
	return path;
}

mol::string Path::addBackSlash(const mol::string& path)
{
	mol::string p(path);
	if ( p.size() > 0 )
		if ( p[p.size()-1] != _T('\\') )
			p += _T("\\");
    return p;
}

mol::string Path::removeBackSlash(const mol::string& path)
{
	mol::string p(path);
	if ( p.size() > 0 )
		if ( p[p.size()-1] == _T('\\') )
			p.erase(p.size()-1,1);
    return p;
}

mol::string Path::addExtension(const mol::string& path,const mol::string& e)
{
	mol::string p(path);
    if ( ext(path) == _T("") )
		p += e;
    return p; 
}

mol::string Path::renameExtension(const mol::string& path,const mol::string& e)
{
	mol::string p(path);
    if ( ext(path) == _T("") )
		p = p.substr(0,p.size()-ext(path).size());
	else
		p += _T(".");
	p += e;
    return p; 
}

mol::string Path::append(const mol::string& path,const mol::string& ap)
{
	mol::string ret = Path::addBackSlash(path);
	mol::string a(ap);
	if ( a[0] == _T('\\') )
		a = a.substr(1);

	ret += a;
    return ret; 
}
bool Path::isNetDrive(const mol::string& path)
{
	return DRIVE_REMOTE == GetDriveType(path.c_str());
}

bool Path::isUNC(const mol::string& path)
{
	return path.substr(0,2) == _T("\\\\");
}

mol::string Path::serviceName(const mol::string& path)
{
	if ( isUNC(path) )
	{
		return path.substr(0,path.find(_T('/'),3));
	}
	mol::string remotename;
	mol::string p(path);
	p = stripToRoot(p);
	p = removeBackSlash(p);
	if ( isNetDrive(p) )
	{		
		mol::string localname(mol::str::toupper(p));
		DWORD len = 0;
		::WNetGetConnection(p.c_str(), 0, &len);
		if ( len )
		{
			mol::TCHAR* buf = new mol::TCHAR[len];
			if (::WNetGetConnection(p.c_str(), buf, &len) )
			{
				remotename = mol::string( buf, len );
			}
			delete[] buf;
		}
	}
	return remotename;
}

std::wstring Path::wpath(const mol::string& path)
{
	std::wstring ws = mol::towstring(path);

	if ( isUNC(path) )
		ws = L"\\\\?\\UNC\\" + ws.substr(2);
	else
		ws = L"\\\\?\\" + ws;

	return ws;
}

bool Path::exists(const mol::string& path)
{
	if ( path.empty() )
		return false;

	DWORD attributes = ::GetFileAttributesW(wpath(path).c_str());
	return (attributes != INVALID_FILE_ATTRIBUTES);
}

bool Path::isDir(const mol::string& path)
{
	if ( path.empty() )
		return false;

	if ( isUNC(path) ) 
	{
		mol::string tmp = path.substr(2);
		size_t p = tmp.find_first_of(_T("/\\"));
		if ( p == mol::string::npos ) 
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

bool Path::isRoot(const mol::string& path)
{
	mol::string p(path);
	p = stripToRoot(p);
	if ( p == path )
		return true;
	return false;
}

mol::string Path::parentDir(const mol::string& path)
{
    mol::string ret = path;

	if ( path.size() == 0 )
		return ret;

    if ( ret[ret.size()-1] == _T('\\') )
      ret.erase(ret.size()-1);

    size_t pos = ret.find_last_of(_T('\\'));
    if ( pos != mol::string::npos )
    {
      ret = ret.substr(0,pos);
    }
    else ret = _T("");

    return ret;
}

bool Path::isSubpath(const mol::string& path,const mol::string& p)
{
	mol::string p1(path);
	mol::string p2(p);

	if ( filename(p1) != p1.c_str() )
	{
		p1 = pathname(p1);
	}

	if ( filename(p2) != p2.c_str() )
	{
		p2 = pathname(p2);
	}

	mol::string  ci1 = mol::str::tolower( p1.c_str() );
	mol::string  ci2 = mol::str::tolower( p2.c_str() );

	if ( ci1 == ci2 )
		return false;

	size_t pos = ci1.find(ci2);
	return ( pos != mol::string::npos ) ;
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////



}

