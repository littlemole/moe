#ifndef MOL_DEF_MEM_WINDOWS_DEF_GUARD_DEFINE
#define MOL_DEF_MEM_WINDOWS_DEF_GUARD_DEFINE

#pragma once

#include "util/uni.h"

namespace mol {


//////////////////////////////////////////////////////////////////////
// helper for Memory on HGLOBAL management
//////////////////////////////////////////////////////////////////////

class global
{
public:
    global();
	global( HGLOBAL glob );

	global( const std::string& s, int opt = GMEM_MOVEABLE | GMEM_NODISCARD);
	global( const std::wstring& s, int opt = GMEM_MOVEABLE | GMEM_NODISCARD);
	global( void* v, size_t size, int opt = GMEM_MOVEABLE | GMEM_NODISCARD);

	template<class T>
	global( const T& t, int opt = GMEM_MOVEABLE | GMEM_NODISCARD)
	{
		if ( alloc(sizeof(T),opt) )
		{
			T* tmp = (T*)lock();
			if ( tmp )
			{
				*tmp = t;
				unLock();
			}
		}
	}


    ~global();

	BOOL alloc( size_t size, int opt = GMEM_MOVEABLE | GMEM_NODISCARD);
    char* lock();
    void unLock();
    void release();

	size_t size()
	{
		return ::GlobalSize(hGlobal_);
	}

	operator HGLOBAL() { return hGlobal_; }

	void attach(HGLOBAL glob);
	void detach();


	static void get(mol::global& g, mol::string& s)
	{
		s = mol::string( (mol::TCHAR*)g.lock());
		g.unLock();
	}

	static void set(mol::global& g, const mol::string& s)
	{
		mol::TCHAR* c = (mol::TCHAR*)g.lock();
		memcpy( (void*)c, (void*)(s.c_str()), (s.size()+1)*sizeof(mol::TCHAR));
		g.unLock();
	}


	static void get(HGLOBAL g, mol::string& s)
	{
		mol::global glob(g);
		s = mol::string( (mol::TCHAR*)glob.lock());
		glob.unLock();
		glob.detach();
	}

	static void set(HGLOBAL g, const mol::string& s)
	{
		mol::global glob(g);
		mol::TCHAR* c = (mol::TCHAR*)glob.lock();
		memcpy( (void*)c, (void*)s.c_str(), (s.size()+1)*sizeof(mol::TCHAR));
		glob.unLock();
		glob.detach();
	}

	template<class T>
	static void get(mol::global& g, T& t)
	{
		t = *((T*)g.lock());
		g.unLock();
	}

	template<class T>
	static void get(HGLOBAL g, T& t)
	{
		mol::global glob(g);
		get<T>(glob,t);
		glob.detach();
	}

	template<class T>
	static void set(mol::global& g, const T& t)
	{
		T* pt = ((T*)g.lock());
		*pt = t;
		g.unLock();
	}

	template<class T>
	static void set(HGLOBAL g, const T& t)
	{
		mol::global glob(g);
		set<T>(g,t);
		glob.detach();
	}

private:
    HGLOBAL	hGlobal_;
};

//////////////////////////////////////////////////////////////////////
// accessors for Globals
//////////////////////////////////////////////////////////////////////


} // endnamespace mol

#endif