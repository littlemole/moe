#ifndef _MOL_CORE_DEF_GUARD_
#define _MOL_CORE_DEF_GUARD_

#include "util/uni.h"
#include <cmath>
#include <map>
#include <string>

namespace mol  {

void* dllFunc( const mol::string& dll, const mol::string& f );
void* dllFunc( HMODULE module, const mol::string& f );


template<class T>
class point
{
public:
    T x;
    T y;
    point()					{ x = y = 0; };
    point( T X, T Y  )		{ x = X; y = Y; };
    point( const point& p )	{ x = p.x; y = p.y; }
    inline T distance( T X, T Y )
    {
        T dx = (X-x);
        T dy = (Y-y);
        long s = ( dx >= 0 ? 1 : -1) * ( dy >= 0 ? 1 : -1 );
        return (T)(sqrt( dx*dx + dy*dy )*s);
    }
    inline T distance( const point<T>& p ) { return distance( p.x, p.y); };
    inline T fast_distance( T X, T Y )
    {
        T ax = fabs(X-x);
        T ay = fabs(Y-y);
        long min = ( ax < ay ) ? ax : ay;
        return ( ax+ay-(T)(min>>1)-(T)(min>>2)+(T)(min>>4));
    }
    inline T fast_distance( const point<T>& p ) { return fast_distance( p.x, p.y); };
    inline point<T> normal() { T l = distance(0,0); return point<T>( ((l!=0) ? (T)(x/l) : 0), ((l!=0)?(T)(y/l):0) ); };
    inline point<T> fast_normal() { T l = fast_distance(0,0); return point<T>( ((l>0) ? (T)(x/l) : 0), ((l>0)?(T)(y/l):0) ); };

    inline point<T> operator+( const point<T>& p ) { return point<T>( this->x+p.x, this->y+p.y ); };
    inline point<T> operator-( const point<T>& p ) { return point<T>( this->x-p.x, this->y-p.y ); };
    inline point<T> operator*( const T t ) { return point<T>( this->x*t, this->y*t ); };
    inline point<T> operator/( const T t ) { return point<T>( (t != 0 ? this->x/t :0), (t != 0 ? this->y/t : 0) ); };
};

template<>
class point<long> : public POINT
{
public:
    point() { x = y = 0; }
    point(const POINT& p) { x = p.x; y = p.y; }
    point(const point& p) { x = p.x; y = p.y; }
    point( int X, int Y)  { x = X;   y = Y; }
    point& operator=(const POINT& p)
    {
        x = p.x;
        y = p.y;
        return *this;
    }
    point& operator=(const point& p)
    {
        x = p.x;
        y = p.y;
        return *this;
    }
    template<class T>
        inline T distance( T X, T Y )
    {
        T dx = (X-x);
        T dy = (Y-y);
        long s = ( dx >= 0 ? 1 : -1) * ( dy >= 0 ? 1 : -1 );
        return (T)(sqrt( (float)(dx*dx + dy*dy) )*s);
    }
    inline long distance( long X, long Y )
    {
        long dx = (X-x);
        long dy = (Y-y);
        long s = ( dx >= 0 ? 1 : -1) * ( dy >= 0 ? 1 : -1 );
        return (long)(std::sqrt( (long double)(dx*dx + dy*dy )*s));
    }
    template<class T>
        inline T distance( const point<T>& p ) { return distance<T>( p.x, p.y); };

    inline long fast_distance( long X, long Y )
    {
        long ax = (long)std::fabs((double)(X-x));
        long ay = (long)std::fabs((long double)(Y-y));
        long min = ( ax < ay ) ? ax : ay;
        return ( ax+ay-(min>>1)-(min>>2)+(min>>4));
    }
    inline long fast_distance( const point& p ) { return fast_distance( p.x, p.y); };

    inline point normal()	   { long l = distance(0,0);	  return point( ((l!=0) ? (long)(x/l) : 0), ((l!=0)?(long)(y/l):0) ); };
    inline point fast_normal() { long l = fast_distance(0,0); return point( ((l>0)  ? (long)(x/l) : 0), ((l>0) ?(long)(y/l):0) ); };

    inline point operator+( const point& p ) { return point( x+p.x, y+p.y ); };
    inline point operator-( const point& p ) { return point( x-p.x, y-p.y ); };
    inline point operator*( const long t ) { return point( x*t, y*t ); };
    inline point operator/( const long t ) { return point( (t != 0 ? x/t :0), (t != 0 ? y/t : 0) ); };
};

typedef point<float> FPoint;
typedef point<long>  Point;

class Rect : public RECT
{
public:
    Rect()
    {	left=top=right=bottom=0; }
    Rect( const Point& p)
    {	top=left=0; right=p.x; bottom=p.y; }
    Rect( int r, int b)
    {	top=left=0; right=r; bottom=b; }
    Rect( int l, int t, int r, int b)
    {	left=l; top=t; right=r; bottom=b; }
    Rect( RECT& r )
    {
        top=r.top;
        left=r.left;
        bottom=r.bottom;
        right=r.right;
    }
    Rect( const RECT& r )
    {
        top=r.top;
        left=r.left;
        bottom=r.bottom;
        right=r.right;
    }
    Rect( const Rect& r)
    {
        top=r.top;
        left=r.left;
        bottom=r.bottom;
        right=r.right;
    }
    Rect( const POINT& p1, const POINT& p2 )
    { left=p1.x; top=p1.y; right=p2.x, bottom=p2.y; };
    Rect( const Point& p1, const Point& p2 )
    { left=p1.x; top=p1.y; right=p2.x, bottom=p2.y; };
    BOOL ptInRect( Point p )
    {
        return ::PtInRect(this, p );
    }
    BOOL intersect( const Rect& r, Rect& result )
    {
        return ::IntersectRect( &result, &r, this );
    }
    BOOL intersect( const Rect& r )
    {
        static Rect result;
        return ::IntersectRect( &result, &r, this );
    }
    BOOL equalRect( const Rect& r )
    {
        return ::EqualRect( this, &r );
    }

    BOOL isempty() { return ::IsRectEmpty(this); }

    Rect& operator=( const Rect& r )
    {
        left=r.left;
        top=r.top;
        right=r.right;
        bottom=r.bottom;
        return *this;
    }

    Rect& operator=( const RECT& r )
    {
        left=r.left;
        top=r.top;
        right=r.right;
        bottom=r.bottom;
        return *this;
    }

    mol::string dump()
    {
		mol::TCHAR buf[256];
        wsprintf(buf,_T("l:%d t:%d r:%d b:%d"),left,top,right,bottom);
        return mol::string(buf);
    }
};

extern const Rect stdRect;

template<class T>
class Timer
{
public:
    Timer()
    {
        id_=0;
    }
    ~Timer()
    {
        kill();
    }
    void set(int delay, T* p )
    {
        kill();
        id_ = ::SetTimer( 0,0, delay, TimerProc );
        map()[id_] = p;
    }

    void kill()
    {
        if ( id_ )
        {
            ::KillTimer(0,id_);
            map().erase(id_);
            id_ = 0;
        }
    }

protected:
    int id_;
    static void CALLBACK TimerProc(  HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime )
    {
        if ( map().count(idEvent) )
        {
            T* p  = map()[idEvent];
            if ( p )
                (*p)();
        }
    }
    static std::map<int, T*>& map()
    {
        static std::map<int, T*> theMap;
        return theMap;
    }
};

enum SUPPORTED_OSTYPE {
	UNSUPPORTED,
	WIN2K,
	WINXP,
	WINVISTA,
	WIN7
};

class OS
{
public:

	static bool has_uac();
	static SUPPORTED_OSTYPE version();

};


} // endnamespace mol


#endif

