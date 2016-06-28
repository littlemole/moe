#include "stdafx.h"
#include "UserForm.h"

#include "ole/dll.h"
#include "userform_i.c"

#include "ole/ole.h"
#include "ole/com.h"
#include "ole/obj.h"
#include "ole/Bstr.h"
#include "ole/typeinfo.h"
#include "ole/Factory.h"
#include "ole/Factorypolicy.h"
#include "ole/aut.h"
#include "ole/cp.h"
#include "win/path.h"
#include "win/file.h"
#include "util/istr.h"
/*
class userFormDll : 
	public mol::Dll,
	public mol::exports<userFormDll,UserForm>
{};

DLL_COCLASS_EXPORTS(userFormDll)
*/

class UserFormApp :

	public mol::local_server<mol::win::Loop>,
	public mol::exports< UserFormApp, UserForm>
{
public:

	UserFormApp()
	{}

	~UserFormApp()
	{}

};

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	ODBGS("useform startup");
	ODBGS(lpCmdLine);

	//::DebugBreak();
	//::MessageBoxA(0,"startup","JRE",0);
	//::CoInitializeEx(0, COINIT_MULTITHREADED);
	::CoInitializeEx(0, COINIT_APARTMENTTHREADED);
	try
	{
		mol::run<UserFormApp>(lpCmdLine);
	}
	catch (mol::X& x)
	{
		::MessageBoxA(0, x.what(), "error", 0);
		::CoUninitialize();
		return 1;
	}
	::CoUninitialize();
	return 0;
}

std::string resolvePath(const std::string& p);

std::wstring findFile(const std::wstring& f)
{
	ODBGS(f);

	if (mol::Path::exists(f))
	{
		ODBGS("FOUND");
		return f;
	}

	std::wstring modulePath = mol::Path::pathname(mol::app<mol::win::AppBase>().getModulePath());

	modulePath = mol::Path::addBackSlash(modulePath);

	modulePath.append(f);
	ODBGS(modulePath);
	if (mol::Path::exists(modulePath))
	{
		ODBGS("FOUND");
		return modulePath;
	}

	return mol::towstring(resolvePath(mol::tostring(f)));
}

std::string resolvePath(const std::string& p)
{
	if (mol::Path::exists(mol::towstring(p)))
	{
		return p;
	}

	std::ostringstream oss;
	for (size_t i = 0; i < p.size(); i++)
	{
		if (p[i] == '/')
			oss << '\\';
		else
			oss << p[i];
	}

	std::vector<std::string> v = mol::split(oss.str(), "\\");

	std::vector<std::string> v2;
	if (!v.empty())
		v2.push_back(v[0]);

	for (size_t i = 1; i < v.size(); i++)
	{
		if (i < v.size() - 1 && v[i + 1] == "..")
		{
			continue;
		}
		if (v[i] == "..")
		{
			continue;
		}

		if (v[i] == ".")
		{
			continue;
		}
		if (v[i] == "")
		{
			continue;
		}

		v2.push_back(v[i]);
	}

	std::ostringstream oss2;
	if (!v2.empty())
	{
		oss2 << v2[0];
	}
	for (size_t i = 1; i < v2.size(); i++)
	{
		oss2 << "\\" << v2[i];
	}

	std::string s = oss2.str();

	const std::string cygdrive("\\cygdrive\\");

	size_t pos = s.find(cygdrive);
	if (pos == 0)
	{
		return s.substr(cygdrive.size(), 1) + ":\\" + s.substr(cygdrive.size() + 2);
	}

	if (mol::Path::exists(mol::towstring(s)))
	{
		return s;
	}

	char buf[MAX_PATH];
	::GetCurrentDirectoryA(MAX_PATH, buf);

	std::ostringstream oss3;
	oss3 << buf << "\\" << s;

	std::string path = oss3.str();
	if (mol::Path::exists(mol::towstring(path)))
	{
		return path;
	}
	return "";
}