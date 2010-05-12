#ifndef _UTIL_DEF_HELP_DEF_
#define _UTIL_DEF_HELP_DEF_

#include <map>
#include <vector>
#include <string>
#include <algorithm>


namespace mol {

//////////////////////////////////////////////////////////////////////
// Macro for inner class Suppport. define as This() member function
// pointing to your outer class this 
//
// thanx to dan box :)
//////////////////////////////////////////////////////////////////////

//#define outer_this(Outer,Member) Outer* This() { return (Outer*) (((char*)this)-(size_t)&(((Outer*)0)->Member)); }

// oops, that has been improved:

//////////////////////////////////////////////////////////////////////
// Inner class to Outer class this template function
// call it like that in your inner class' member functions:
//
// ::That(this,&Outer::member_)->function(..);
//
// with Outer::member_ specifying a Inner Class Type member of the
// Outer class.
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////

template<class I, class O, class M>
O* That( I* i, M O::*mp )
{
	return (O*)(((char*)i)-(size_t)&(((O*)0)->*(mp)));
}

//////////////////////////////////////////////////////////////////////
// Macro for inner class Suppport. define as This() member function
// pointing to your outer class this - using new template above
//
// still thanx to dan box :)
//////////////////////////////////////////////////////////////////////

#define outer_this(Outer,Member) Outer* This() { return mol::That(this,&##Outer##::##Member); }

//////////////////////////////////////////////////////////////////////
// template version of the famous offset_of() preprocessor macro
//////////////////////////////////////////////////////////////////////

template<typename T, typename S> 
size_t offset_of(T S::*p) 
{ 
    S *t = 0; 
    return (char *)&(t->*p) - (char *)t; 
} 

//////////////////////////////////////////////////////////////////////
// helper to get a reference to the member at given offset 
//////////////////////////////////////////////////////////////////////

template<typename T,typename O> 
T& member_at_offset(O& t, size_t offset) 
{
	T* pt = (T*)(((char*)&t)+offset);
	return *pt;
} 


//////////////////////////////////////////////////////////////////////
// Pointer to class member member
//////////////////////////////////////////////////////////////////////

template<typename T, typename S> 
class MemberPtr
{ 
public:
	typedef T Holder;
	typedef S Owner;
	typedef T S::* MP;
	MemberPtr(MP p) 
		: mp(p)
	{

	}

	MP mp; 

	T& operator()(S& s)
	{
		return s.*mp;
	}

	T* operator()(S* s)
	{
		return &(s->*mp);
	}
}; 


template<typename T, typename S> 
class MemberPtr<std::vector<T>,S>
{ 
public:
	typedef std::vector<T> Holder;
	typedef S Owner;
	typedef std::vector<T> S::* MP;
	MemberPtr(MP p) 
		: mp(p)
	{

	}

	MP mp; 

	std::vector<T>& operator()(S& s)
	{
		return s.*mp;
	}

	std::vector<T>* operator()(S* s)
	{
		return &(s->*mp);
	}
};

//////////////////////////////////////////////////////////////////////
// helper function to return a MemberPtr
//////////////////////////////////////////////////////////////////////

template<typename T, typename S> 
MemberPtr<T,S> member_ptr(T S::*p) 
{
	return MemberPtr<T,S>(p);
}


template<typename T, typename S> 
MemberPtr<std::vector<T>,S> member_ptr(std::vector<T> S::*p) 
{
	return MemberPtr<std::vector<T>,S>(p);
}

//////////////////////////////////////////////////////////////////////
// determine offset from class to base class
//////////////////////////////////////////////////////////////////////

template<class C, class Base>
unsigned int base_offset()
{
	return ((unsigned int)(((Base*)((C*)(0x10000000))))-0x10000000);
}

//////////////////////////////////////////////////////////////////////
// split using stl vectors
//////////////////////////////////////////////////////////////////////
std::vector<std::string> split( const std::string& what, const std::string& delim );


//////////////////////////////////////////////////////////////////////
// helpers to delete stl containers holding pointers
// these routines will reset the container and delete
// all embeded simple object pointers
//
// not to be used with holded pointers to plain old arrays
//////////////////////////////////////////////////////////////////////

template< class C>
void purge(C& c)
{
    for ( typename C::iterator it = c.begin(); it != c.end(); it++ )
    {
        delete *it;
        *it=0;
    }
};

template<class K, class V>
void clear(std::map<K,V>& m)
{
    for ( typename std::map<K,V>::iterator it = m.begin(); it != m.end(); it++ )
    {
        delete (*it).second;
        (*it).second = 0;
    }
};

template<class K, class V>
void clear(std::multimap<K,V>& m)
{
    for ( typename std::multimap<K,V>::iterator it = m.begin(); it != m.end(); it++ )
    {
		if ( (*it).second != 0 )
	        delete (*it).second;
        (*it).second = 0;
    }
};

template< class I>
void purge(I begin, I end)
{
    for ( I it = begin; it != end; it++ )
    {
        delete *it;
        *it=0;
    }
};


} // end namespace mol

#endif


