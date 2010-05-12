#pragma once
#include "util/X.h"
#include "util/uni.h"
#include <windows.h>
#include <shlwapi.h>
#include <string>

namespace mol {


class RegKey
{
public:
	RegKey() 
		:hkey_(0),sam_(0)
	{
		
	}
	RegKey( HKEY hkey, REGSAM sam = KEY_ALL_ACCESS ) 
		:hkey_(hkey),sam_(sam)
	{}

	~RegKey() 
	{
		close();
	}

	LONG close()
	{
		LONG l = 0;
		if ( hkey_ )
			if ( ERROR_SUCCESS != ::RegCloseKey(hkey_) )
				throw mol::X( _T("RegCloseKey failed"));
		hkey_ = 0;
		return l;
	}

	HKEY open( const mol::string& subkey, REGSAM sam = KEY_ALL_ACCESS)
	{
		HKEY sub = 0;
		if ( ERROR_SUCCESS != RegOpenKeyEx( hkey_, subkey.c_str(), 0,  sam, &sub) )
			throw mol::X(subkey.c_str());
		return sub;
	}

	HKEY create( const mol::string& subkey, REGSAM sam = KEY_ALL_ACCESS)
	{
		HKEY sub = 0;
		DWORD disp;
		if ( ERROR_SUCCESS != ::RegCreateKeyEx( hkey_, subkey.c_str(), 0, _T(""), 0, sam, 0, &sub, &disp) )
			throw mol::X(subkey.c_str());
		return sub;
	}

	void del( const mol::string& subkey, REGSAM sam = KEY_ALL_ACCESS)
	{
		if ( ERROR_SUCCESS != ::RegDeleteKey( hkey_, subkey.c_str() ) )
			throw mol::X(_T("RegDeleteKey failed"));
	}

	void erase( const mol::string& subkey )
	{
		if ( ERROR_SUCCESS != ::SHDeleteKey( hkey_, subkey.c_str() ) )
		{
			throw mol::X(_T("erase RegKey failed"));
		}
	}

	void setInt( int i, int type = REG_DWORD )
	{
		setInt ( _T(""), i, type );
	}

	void setInt( const mol::string& name, int i, int type = REG_DWORD )
	{
		if ( ERROR_SUCCESS != RegSetValueEx( hkey_, name.c_str(), 0, type, (const BYTE*)&i, sizeof(DWORD)) )
			throw mol::X(name.c_str());
	}

	void set( const mol::string& value, int type = REG_SZ )
	{
		set( _T(""), value, type );
	}

	void set( const mol::string& name, const mol::string& value, int type = REG_SZ )
	{
		if ( ERROR_SUCCESS != RegSetValueEx( hkey_, name.c_str(), 0, type, (const BYTE*)(value.c_str()), (DWORD)(value.size()+1)*sizeof(mol::TCHAR)) )
			throw mol::X(name.c_str());
	}

	mol::string get( )
	{
		return get( _T("") );
	}

	mol::string get( const mol::string& name )
	{
		mol::TCHAR buf[2048];
		DWORD size=2047;
		DWORD type;
		if ( name == _T("") )
		{
			if ( ERROR_SUCCESS != RegQueryValue( hkey_, 0,buf, (long*)&size) )
				throw mol::X(name.c_str());
			return buf;
		}
		else
		{
			if ( ERROR_SUCCESS != RegQueryValueEx( hkey_, name.c_str(),0 , &type, (BYTE*)buf, &size) )
				throw mol::X(name.c_str());
			return buf;
		}
	}

	operator HKEY()
	{
		return hkey_;
	}

	RegKey& operator=(HKEY key)
	{
		close();
		hkey_ = key;
		return *this;
	}

private:
	HKEY hkey_;
	REGSAM sam_;
};

}

