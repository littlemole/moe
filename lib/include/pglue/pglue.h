#ifndef _MOL_DEF_GUARD_DEFINE_PERL_GLUE_HELPER_DEF_
#define _MOL_DEF_GUARD_DEFINE_PERL_GLUE_HELPER_DEF_

#include <map>
#include <list>
#include <vector>
#include <string>
#include <sstream>


#ifdef __cplusplus
extern "C" {
#endif

#include <EXTERN.h>
#include <perl.h>
#include "XSUB.h"

#ifdef __cplusplus
}
#endif

namespace PerlGlue {

//////////////////////////////////////////////////////////////////
//
// perlglue c++ template lib - the mole 2007
//
// glue for embedding the Perl interpreter into C++ programs
// and injecting custom c++ objects into the script engine.
// intended to be used for making application automation
// possible by using Perl as the end user scripting language
// and exposing a custom object model and providing a bridge
// between (User Scripting) Perl and C++ (Application) code
//
// example code:
/*

#include "pglue.h"

class Test 
{
public:
	// mark class as exposed to Perl
	perl_exposed(Test);

	// mark method as exported to Perl
	perl_export(test)
	int terror( const std::string& s, double d )
	{
		std::cout << s << " : " << d << std::endl;
		return 42;
	}
};

int main(int argc, char **argv, char **env)
{
	PerlInit pi(argc, argv, env);

	Test t;

	Perl perl;
	perl.addClassDef<Test>();
	
	// use this to run and parse a file:
	//perl.parse( argc, argv, env );
	//perl.run();

	// or feed the interpreter manually:
	perl.embed();

	// set a perl variable $val to 42:
	//perl.set_val(42,"val");

    // inject C++ Test object into Perl engine, named $test:
	perl.inject(&t, "test");

	// or construct from perl. only empty constructors 
	// (no parameters) allow in this case:
	//perl.eval( "$t = new Test;" );

	// eval arbitary perl code:
	perl.eval( "print $test->test("huhu",3.12);" );
}
*/
//////////////////////////////////////////////////////////////////
//
// restriction for exposed C++ classes:
// - must have default constructor. from perl, only this is callable
// - exposed methods may not have more than 8 parameters
// - return values are supposed to be simple ints, doubles, char*s
//   or std::strings
//
//////////////////////////////////////////////////////////////////
//
// perl to c++ type mappings for function signatures:
//
// Perl          C++
//  skalar       int,double, (const) char*, const std::string&
//  skalar ref   int&,double&, (const)char*&, std::string&
//
//use the ref type if you want to modify parameters using [in/out]
//behaviour. 
//
// array support:
//
// Perl          C++
// @array        std::vector< int|double|char*|std::string >&
// \@array-ref   std::vector< int|double|char*|std::string >*
//
// hash support:
//
// Perl          C++
// %hash         std::map<std::string, int|double|char*|std::string >&
// \%hash-ref    std::map<std::string, int|double|char*|std::string >*
//
// passing c++ objects back and forth to/from perl:
//
// Perl          C++
// $object       T*
// \$object-ref  T**/T*&
//
// declaring the type of the C++ object as T** or T*& gives you
// pass-by-value [in/out] behaviour. Use it if you want to
// modify (ie replace) the passed object
//
// for lower level access, define your functions parameters of type SV*
// that will give you Perls native C Scalar-Value-Representation to play
// with.
//
// for even lower access, define your functions static with this signature:
//
// static void testLowLevel(PerlInterpreter*,CV* cv);
//
// now you have a static global function like in XSUB programming,
// you now can define dXSARGS; and access the Stach via ST(x).
// note the first param will be the this pointer, which you have
// to extract yourself, you are now in a global function!
//
//////////////////////////////////////////////////////////////////
// compilation:
// g++ yourapp.cpp `perl -MExtUtils::Embed -e ccopts -e ldopts`
//
//
//////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////
// dereference an SV*
//////////////////////////////////////////////////////////////////

inline SV* dereference( SV* sv )
{
	SV* tmp = sv;
	while( SvROK(tmp) ) 
	{
		tmp = (SV*)SvRV(tmp);
	}
	return tmp;
}

//////////////////////////////////////////////////////////////////
// get a c++ pointer from SV*
//////////////////////////////////////////////////////////////////

template<class T>
T get_obj( SV* sv )
{
	return (T)(I32)SvIV(dereference(sv));
}

//////////////////////////////////////////////////////////////////
// get std::string from SV*
//////////////////////////////////////////////////////////////////

inline std::string str_val( SV* sv )
{
	STRLEN len;
	const char* c = (const char*)SvPV(dereference(sv),len);
	return std::string(c,len);
}

//////////////////////////////////////////////////////////////////
// get int from SV*
//////////////////////////////////////////////////////////////////

inline int int_val( SV* sv )
{
	return SvIV(dereference(sv));
}

//////////////////////////////////////////////////////////////////
// get double from SV*
//////////////////////////////////////////////////////////////////

inline double double_val( SV* sv )
{
	return SvNV(dereference(sv));
}

//////////////////////////////////////////////////////////////////
// get HV* from SV*
//////////////////////////////////////////////////////////////////

inline HV* hash_val(SV* sv)
{
	return (HV*)(dereference(sv));
}

//////////////////////////////////////////////////////////////////
// get AV* from SV*
//////////////////////////////////////////////////////////////////

inline AV* array_val(SV* sv)
{
	return (AV*)(dereference(sv));
}

//////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////
// bless an SV* into a package
//////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////

inline SV* bless( SV* sv, const char* classname )
{
	SV* ref   = sv;
	if ( !SvROK(ref) )
		ref   = newRV_inc( sv );

	HV* stash = gv_stashpv( classname, 1);
	return sv_bless( ref, stash );
}

//////////////////////////////////////////////////////////////////
// inside a blessed method, Self retrieves a SV* to "this"
//////////////////////////////////////////////////////////////////

#define Self dereference( (SV*)ST(0) )

//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// generate mortal SV*
//////////////////////////////////////////////////////////////////

template<class T>
SV* mortal( T* t )
{
	SV* sv = sv_newmortal();	
	sv_setref_iv( sv, (char*)T::PerlClassName(), (I32)t );
	return sv;
}

inline SV* mortal( )
{
	return sv_newmortal();
}

inline SV* mortal( int i )
{
	return sv_2mortal(newSViv(i));
}

inline SV* mortal( double d )
{
	return sv_2mortal(newSVnv(d));
}

inline SV* mortal( const char* c )
{
	return sv_2mortal(newSVpv(c,0));
}


inline SV* mortal( char* c )
{
	return sv_2mortal(newSVpvn(c,strlen(c)));
}

inline SV* mortal( const std::string& s )
{
	return sv_2mortal(newSVpv(s.c_str(),s.size()));
}


inline SV* mortal( SV* sv )
{
	return sv_2mortal(sv);
}


inline SV* mortal( AV* av )
{
	return sv_2mortal((SV*)av);
}


inline SV* mortal( HV* hv )
{
	return sv_2mortal((SV*)hv);
}


inline SV* mortal( CV* cv )
{
	return sv_2mortal((SV*)cv);
}

//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// get a reference to a SV*
//////////////////////////////////////////////////////////////////

inline SV* ref( SV* sv )
{
	return newRV_inc(sv);
}


inline SV* ref( AV* av )
{
	return newRV_inc((SV*)av);
}


inline SV* ref( HV* hv )
{
	return newRV_inc((SV*)hv);
}


inline SV* ref( CV* cv )
{
	return newRV_inc((SV*)cv);
}


//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// convert T to a scalar value
//////////////////////////////////////////////////////////////////

template<class T>
SV* scalar( T* t )
{
	SV* sv = sv_newmortal();	
	sv_setref_iv( sv, (char*)T::PerlClassName(), (I32)t );
	return sv;
}

inline SV* scalar( int i )
{
	return newSViv(i);
}

inline SV* scalar( double d )
{
	return newSVnv(d);
}

inline SV* scalar( const char* c )
{
	return newSVpv(c,0);
}

inline SV* scalar( const std::string& s )
{
	return newSVpv(s.c_str(),s.size());
}

inline SV* scalar( SV* s )
{
	return newSVsv(s);
}


//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// two parameter form sets a scalar value to existing SV
//////////////////////////////////////////////////////////////////

template<class T>
void scalar( SV* sv, T* t )
{
	sv_setref_iv( sv, (char*)T::PerlClassName(), (I32)t );
}

inline void scalar( SV* sv, int i)
{
	sv_setiv( dereference(sv), (I32)i );
}

inline void scalar( SV* sv, double d)
{
	sv_setnv( dereference(sv), d );
}

inline void scalar( SV* sv, const char* c)
{
	sv_setpv( dereference(sv), c );
}

inline void scalar( SV* sv, const std::string& s)
{
	sv_setpv( dereference(sv), s.c_str() );
}

//////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// Init helpers
//////////////////////////////////////////////////////////////////


EXTERN_C void boot_DynaLoader (pTHX_ CV* cv);

class PerlInit
{
public:
	PerlInit(int argc = 0, char **argv = 0, char **env = 0)
	{
		PERL_SYS_INIT3(&argc,&argv,&env);
	}

	~PerlInit()
	{
		fprintf(stderr,"~PerlInit()\r\n");
		//PERL_SYS_TERM();
		fprintf(stderr,"~PerlInit() done\r\n");
	}
};

//////////////////////////////////////////////////////////////////

struct xs_init_helper
{
	typedef void (*xs_func) (pTHX_ CV* cv);

	xs_init_helper( const std::string& n, void (*fun) (pTHX_ CV* cv), const std::string& f )
		: name(n), func(fun), file(f)
	{}

	std::string name;
	xs_func func;
	std::string file;
};

//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// Perl Array wrapper
//////////////////////////////////////////////////////////////////

class Array
{
public:

	Array()
	{
		av = newAV();
	}

	Array( SV* sv)
	{
		av = (AV*)dereference(sv);
	}

	Array( AV* a)
	{
		av = a;
	}

	void undef()
	{
		av_undef(av);
	}

	int size()
	{
		return av_len(av);
	}

	SV* item( int i )
	{
		SV** svp = av_fetch( av, i, 0 );
		if (!svp)
			return 0;
		return dereference(*svp);
	}

	void set( int i, SV* sv )
	{
		av_store( av, i, sv );
	}

	void clear()
	{
		av_clear(av);
	}

	void extend(int i )
	{
		av_extend(av,i);
	}

	void push(SV* sv)
	{
		av_push(av,sv);
	}

	SV* pop(SV* sv)
	{
		av_pop(av);
	}

	SV* shift(SV* sv)
	{
		av_shift(av);
	}

	void unshift(SV* sv)
	{
		av_unshift(av,1);
		av_store(av,0,sv);
	}

	operator SV*()
	{	
		return (SV*)av;
	}

	AV* av;
};

//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// Perl Hash wrapper
//////////////////////////////////////////////////////////////////

class Hash
{
public:
	Hash()
	{
		hv = newHV();
	}

	Hash( SV* sv )
	{
		hv = (HV*)dereference(sv);
	}

	Hash( HV* h )
	{
		hv = h;
	}

	void undef()
	{
		hv_undef(hv);
	}

	bool exists( const char* key )
	{
		return hv_exists( hv, key, strlen(key) );
	}

	SV* item( const char* key )
	{
		SV** psv = hv_fetch( hv, key, strlen(key), 0 );
		if ( psv )
		{
			return dereference(*psv);
		}
		return 0;
	}

	void store( const char* key, SV* sv )
	{
		hv_store( hv, key, strlen(key), sv, 0 );
	}

	void erase( const char* key )
	{
		SV** psv = hv_fetch( hv, key, strlen(key), 1 );
		if ( psv )
		{
			hv_delete( hv, key, strlen(key), G_DISCARD );
		}	
	}

	int clear()
	{
		hv_clear(hv);
	}

	int each()
	{
		return hv_iterinit(hv);
	}

	SV* next( int iter, char** key )
	{
		iter--;
		if ( iter <= 0 )
			return 0;
		I32 len;
		SV* val = hv_iternextsv( hv, key, &len );
		return dereference(val);
	}

	operator SV*()
	{	
		return (SV*)hv;
	}

	HV* hv;
};

////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// invoke perl functions by SV*
//////////////////////////////////////////////////////////////////


inline void invoke( SV* handler)
{
	dSP;
	ENTER;
	SAVETMPS;
	
	PUSHMARK(SP);	
	PUTBACK;
	
	call_sv(handler,G_VOID|G_DISCARD);
	
	FREETMPS;
	LEAVE;
}

inline void invoke( SV* handler,  SV* sv )
{
	dSP;
	ENTER;
	SAVETMPS;
	
	PUSHMARK(SP);	
	XPUSHs( sv );
	PUTBACK;
	
	call_sv(handler,G_VOID|G_DISCARD);
	
	FREETMPS;
	LEAVE;
}

inline void invoke( SV* handler,  SV* sv1, SV* sv2 )
{
	dSP;
	ENTER;
	SAVETMPS;
	
	PUSHMARK(SP);	
	XPUSHs( sv1 );
	XPUSHs( sv2 );
	PUTBACK;
	
	call_sv(handler,G_VOID|G_DISCARD);
	
	FREETMPS;
	LEAVE;
}

inline void invoke( SV* handler,  SV* sv1, SV* sv2, SV* sv3 )
{
	dSP;
	ENTER;
	SAVETMPS;
	
	PUSHMARK(SP);	
	XPUSHs( sv1 );
	XPUSHs( sv2 );
	XPUSHs( sv3 );
	PUTBACK;
	
	call_sv(handler,G_VOID|G_DISCARD);
	
	FREETMPS;
	LEAVE;
}

inline void invoke( SV* handler,  SV* sv1, SV* sv2, SV* sv3, SV* sv4 )
{
	dSP;
	ENTER;
	SAVETMPS;
	
	PUSHMARK(SP);	
	XPUSHs( sv1 );
	XPUSHs( sv2 );
	XPUSHs( sv3 );
	XPUSHs( sv4 );
	PUTBACK;
	
	call_sv(handler,G_VOID|G_DISCARD);
	
	FREETMPS;
	LEAVE;
}

//////////////////////////////////////////////////////////////////
// call perl functions by SV*
//////////////////////////////////////////////////////////////////

inline SV* call( SV* handler)
{
	SV* ret = 0;

	dSP;
	ENTER;
	SAVETMPS;
	
	PUSHMARK(SP);	
	PUTBACK;
	
	int cnt = call_sv(handler,G_SCALAR);
	
	SPAGAIN;
	if ( cnt == 1 )
		ret =  mortal(scalar(POPs));
	PUTBACK;
	
	FREETMPS;
	LEAVE;
	return ret;
}


inline SV* call( SV* handler, SV* sv )
{
	SV* ret = 0;

	dSP;
	ENTER;
	SAVETMPS;
	
	PUSHMARK(SP);	
	XPUSHs( sv );
	PUTBACK;
	
	int cnt = call_sv(handler,G_SCALAR);
	
	SPAGAIN;
	if ( cnt == 1 )
		ret =  mortal(scalar(POPs));
	PUTBACK;
	
	FREETMPS;
	LEAVE;
	return ret;
}

inline SV* call( SV* handler, SV* sv1, SV* sv2 )
{
	SV* ret = 0;

	dSP;
	ENTER;
	SAVETMPS;
	
	PUSHMARK(SP);	
	XPUSHs( sv1 );
	XPUSHs( sv2 );
	PUTBACK;
	
	int cnt = call_sv(handler,G_SCALAR);
	
	SPAGAIN;
	if ( cnt == 1 )
		ret =  mortal(scalar(POPs));
	PUTBACK;
	
	FREETMPS;
	LEAVE;
	return ret;
}


inline SV* call( SV* handler, SV* sv1, SV* sv2, SV* sv3 )
{
	SV* ret = 0;

	dSP;
	ENTER;
	SAVETMPS;
	
	PUSHMARK(SP);	
	XPUSHs( sv1 );
	XPUSHs( sv2 );
	XPUSHs( sv3 );
	PUTBACK;
	
	int cnt = call_sv(handler,G_SCALAR);
	
	SPAGAIN;
	if ( cnt == 1 )
		ret =  mortal(scalar(POPs));
	PUTBACK;
	
	FREETMPS;
	LEAVE;
	return ret;
}


inline SV* call( SV* handler, SV* sv1, SV* sv2, SV* sv3, SV* sv4 )
{
	SV* ret = 0;

	dSP;
	ENTER;
	SAVETMPS;
	
	PUSHMARK(SP);	
	XPUSHs( sv1 );
	XPUSHs( sv2 );
	XPUSHs( sv3 );
	XPUSHs( sv4 );
	PUTBACK;
	
	int cnt = call_sv(handler,G_SCALAR);
	
	SPAGAIN;
	if ( cnt == 1 )
		ret =  mortal(scalar(POPs));
	PUTBACK;
	
	FREETMPS;
	LEAVE;
	return ret;
}

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
// Perl/C++ Bindings
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// get typed perl_value functions for templates
//////////////////////////////////////////////////////////////////

template<class T>
void get_perl_value( SV* sv , T** t)
{
	*t = (T*)(I32)SvIV(dereference(sv));
}

inline void get_perl_value( SV* sv, const char** c )
{
	STRLEN na;
	*c = (const char*)SvPV(dereference(sv),na);
}

inline void get_perl_value( SV* sv, char** c )
{
	STRLEN na;
	*c = (char*)SvPV(dereference(sv),na);
}

inline void get_perl_value( SV* sv, std::string* s )
{
	STRLEN na;
	*s = (const char*)SvPV(dereference(sv),na);
}

inline void get_perl_value( SV* sv, int* i )
{
	*i = SvIV(dereference(sv));
}

inline void get_perl_value(SV* sv, double* d )
{
	*d = SvNV(dereference(sv));
}

inline void get_perl_value(SV* sv, AV** av )
{
	*av = (AV*)(dereference(sv));
}


inline void get_perl_value(SV* sv, HV** hv )
{
	*hv = (HV*)(dereference(sv));
}


//////////////////////////////////////////////////////////////////
// typed xsreturn functions for templates
//////////////////////////////////////////////////////////////////

inline void xs_return( const I32 ax )
{
	XSRETURN(0);
}

inline void xs_return(const I32 ax, int i)
{
	ST(0) = sv_newmortal();
	sv_setiv( ST(0), (I32)i );
	XSRETURN(1);
}


inline void xs_return(const I32 ax, double d)
{
	ST(0) = sv_newmortal();
	sv_setnv( ST(0), d );
	XSRETURN(1);
}

inline void xs_return(const I32 ax, const char* c)
{
	ST(0) = sv_newmortal();
	sv_setpv( ST(0), c );
	XSRETURN(1);
}


inline void xs_return(const I32 ax, const std::string& s)
{
	ST(0) = sv_newmortal();
	sv_setpv( ST(0), s.c_str() );
	XSRETURN(1);
}

template<class T>
void xs_return( const I32 ax, T* t)
{
	ST(0) = sv_newmortal();
	sv_setref_iv( ST(0), T::PerlClassName(), (I32)t );
	XSRETURN(1);
}

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
// Param Types used by Perl/C++ bindings
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////


template<class T>
class PerlParamType 
{
public:
	typedef T StackType;

	static void get_value( SV* sv, T* t)
	{
		get_perl_value(sv,t);
	}

	static void set_ref_value( SV* sv, T* t)
	{
	}

	static T ParamValue( T* t )
	{
		return *t;
	}
};

//////////////////////////////////////////////////////////////////


template<class T>
class PerlParamType<T&>
{
public:
	typedef T StackType;

	static void get_value( SV* sv, T* t)
	{
		get_perl_value(sv,t);
	}

	static void set_ref_value( SV* sv, T* t)
	{
		set_perl_value( sv, *t );
	}

	static T& ParamValue( T* t )
	{
		return *t;
	}
};

//////////////////////////////////////////////////////////////////

template<>
class PerlParamType<void>
{
public:

	typedef void* StackType;

	static void get_value( SV* sv, void** t)
	{
	}

	static void set_ref_value( SV* sv, void** t)
	{
	}

	static void* ParamValue( void* t )
	{
		return t;
	}
};

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

template<class T>
class PerlParamType<T*>
{
public:

	typedef T* StackType;

	static void get_value( SV* sv, T** t)
	{
		get_perl_value<T>( sv,t  );
	}

	static void set_ref_value( SV* sv, T** t)
	{
	}

	static T* ParamValue( T** t )
	{
		return *t;
	}
};

//////////////////////////////////////////////////////////////////

template<class T>
class PerlParamType<T*&>
{
public:

	typedef T* StackType;

	static void get_value( SV* sv, T** t)
	{
		get_perl_value<T>( sv,t);
	}

	static void set_ref_value( SV* sv, T** t)
	{
		SV* tmp = dereference(sv);
		I32 old = (I32)SvIV(tmp);
		if ( *t != (T*)old)
		{
			delete (T*)old;
			sv_setiv( tmp, (I32)(void*)(*t) );	
		}
	}

	static T*& ParamValue( T**& t )
	{
		return *t;
	}
};

//////////////////////////////////////////////////////////////////

template<class T>
class PerlParamType<T**>
{
public:

	typedef T* StackType;

	static void get_value( SV* sv, T** t)
	{
		get_perl_value<T>( sv, t );
	}

	static void set_ref_value( SV* sv, T** t)
	{
		SV* tmp = dereference(sv);
		I32 old = (I32)SvIV(tmp);
		if ( *t != (T*)old)
		{
			delete (T*)old;
			sv_setiv( tmp, (I32)(void*)(*t) );	
		}
	}

	static T** ParamValue( T** t )
	{
		return t;
	}
};

//////////////////////////////////////////////////////////////////



template<>
class PerlParamType<SV*>
{
public:
	typedef SV* StackType;

	static void get_value( SV* sv, SV** t)
	{
		*t = sv;
	}

	static void set_ref_value( SV* sv, SV** t)
	{		
	}

	static SV* ParamValue( SV** t )
	{
		return *t;
	}
};

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

template<>
class PerlParamType<char*> 
{
public:

	typedef char* StackType;

	static void get_value( SV* sv, char** c)
	{
		get_perl_value( sv, c );
	}

	static void set_ref_value( SV* sv, char** c)
	{
	}

	static char* ParamValue( char** c )
	{
		return *c;
	}
};

//////////////////////////////////////////////////////////////////

template<>
class PerlParamType<char*&> 
{
public:

	typedef char* StackType;

	static void get_value( SV* sv, char** c)
	{
		get_perl_value( sv, c );
	}

	static void set_ref_value( SV* sv, char** c)
	{
		sv_setpv( dereference(sv), *c );
	}

	static char*& ParamValue( char** c )
	{
		return *c;
	}
};

//////////////////////////////////////////////////////////////////	
//////////////////////////////////////////////////////////////////	

template<>
class PerlParamType<const char*> 
{
public:

	typedef char* StackType;

	static void get_value( SV* sv, char** c)
	{
		get_perl_value( sv, c );
	}

	static void set_ref_value( SV* sv, char** c)
	{
	}

	static const char* ParamValue( char** c )
	{
		return *c;
	}
};

//////////////////////////////////////////////////////////////////	

template<>
class PerlParamType<const char*&> 
{
public:

	typedef const char* StackType;

	static void get_value( SV* sv, const char** c)
	{
		get_perl_value( sv, c );
	}

	static void set_ref_value( SV* sv, const char** c)
	{
		sv_setpv( dereference(sv), *c );
	}

	static const char*& ParamValue( const char** c )
	{
		return *c;
	}
};


//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

template<>
class PerlParamType<const std::string&> 
{
public:

	typedef std::string StackType;

	static void get_value( SV* sv, std::string* s)
	{
		get_perl_value( sv, s );
	}

	static void set_ref_value( SV* sv, std::string* s)
	{
	}

	static StackType& ParamValue( StackType* t )
	{
		return *t;
	}
};

//////////////////////////////////////////////////////////////////

template<>
class PerlParamType<std::string&> 
{
public:

	typedef std::string StackType;

	static void get_value( SV* sv, std::string* s)
	{
		get_perl_value( sv, s );
	}

	static void set_ref_value( SV* sv, std::string* s)
	{
		sv_setpv( dereference(sv), (char*)s->c_str() );
	}

	static StackType& ParamValue( StackType* t )
	{
		return *t;
	}
};


//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////


template<class T>
class PerlParamType<std::vector<T>& > 
{
public:

	typedef std::vector<T> StackType;
	typedef T ItemType;

	static void get_value( SV* sv, std::vector<T>* v)
	{
		SV* tmp = dereference(sv);
		if ( SvTYPE(tmp) != SVt_PVAV )
			return;

		Array array( (AV*)tmp );
		int len = array.size();
		for ( int i = 0; i <= len; i++ )
		{
			T it;
			SV* sv = array.item( i );
			get_perl_value( sv, &it );
			v->push_back(it);
		}
	}

	static void set_ref_value( SV* sv,std::vector<T>* v)
	{
	}

	static StackType& ParamValue( StackType* t )
	{
		return *t;
	}
};

//////////////////////////////////////////////////////////////////

template<class T>
class PerlParamType<std::vector<T>* > 
{
public:
	typedef std::vector<T> StackType;
	typedef T ItemType;

	static void get_value( SV* sv, std::vector<T>* v)
	{
		PerlParamType<std::vector<T>&>::get_value( sv, v );
	}

	static void set_ref_value( SV* sv, std::vector<T>* v)
	{
		SV* tmp = dereference(sv);
		if ( SvTYPE(tmp) != SVt_PVAV )
			return;

		Array array( (AV*)tmp );
		array.clear();
		array.extend(v->size() );
		for ( int i = 0; i < v->size(); i++ )
		{
			array.push( scalar( v->at(i) ) );
		}
	}

	static StackType* ParamValue( StackType* t )
	{
		return t;
	}
};

//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

template<class T>
class PerlParamType<std::map<std::string,T>& > 
{
public:

	typedef std::map<std::string,T> StackType;
	typedef T ItemType;

	static void get_value( SV* sv, std::map<std::string,T>* m)
	{
		SV* tmp = dereference(sv);
		if ( SvTYPE(tmp) != SVt_PVHV )
			return;

		Hash hash( (HV*)tmp );

		int it = hash.each();
		char* key;
		while( SV* sv = hash.next(it,&key) )
		{
			T it;
			get_perl_value( sv, &it );
			m->insert( std::make_pair( std::string(key), it ) );
		}
	}

	static void set_ref_value( SV* sv,std::map<std::string,T>* v)
	{
	}

	static StackType& ParamValue( StackType* t )
	{
		return *t;
	}
};

//////////////////////////////////////////////////////////////////

template<class T>
class PerlParamType<std::map<std::string,T>* > 
{
public:

	typedef std::map<std::string,T> StackType;
	typedef T ItemType;

	static void get_value( SV* sv, std::map<std::string,T>* m)
	{
		PerlParamType<std::map<std::string,T>&>::get_value( sv, m );
	}

	static void set_ref_value( SV* sv,std::map<std::string,T>* m)
	{
		SV* tmp = dereference(sv);
		if ( SvTYPE(tmp) != SVt_PVHV )
			return;

		Hash hash( (HV*)tmp );
		hash.clear();

		typename std::map<std::string,T>::iterator it = m->begin();
		for ( it; it != m->end(); it++ )
		{
			hash.store( (*it).first.c_str(), scalar( (*it).second ) );
		}
	}

	static StackType* ParamValue( StackType* t )
	{
		return t;
	}

};

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
// Signatures for Perl/C++ bindings
//////////////////////////////////////////////////////////////////

template< class R, 
		  class T, 
		  class P1 = void, 
		  class P2 = void, 
		  class P3 = void, 
		  class P4 = void, 
		  class P5 = void, 
		  class P6 = void, 
		  class P7 = void, 
		  class P8 = void >
class Signature
{
public:
	typedef R (T::*signature)(P1,P2,P3,P4,P5,P6,P7,P8);
};

template<class R, class T, class P1, class P2, class P3, class P4, class P5, class P6, class P7>
class Signature<R,T,P1,P2,P3,P4,P5,P6,P7,void>
{
public:
	typedef R (T::*signature)(P1,P2,P3,P4,P5,P6,P7);
};

template<class R, class T, class P1, class P2, class P3, class P4, class P5, class P6>
class Signature<R,T,P1,P2,P3,P4,P5,P6,void,void>
{
public:
	typedef R (T::*signature)(P1,P2,P3,P4,P5,P6);
};

template<class R, class T, class P1, class P2, class P3, class P4, class P5>
class Signature<R,T,P1,P2,P3,P4,P5,void,void,void>
{
public:
	typedef R (T::*signature)(P1,P2,P3,P4,P5);
};

template<class R, class T, class P1, class P2, class P3, class P4>
class Signature<R,T,P1,P2,P3,P4,void,void,void,void>
{
public:
	typedef R (T::*signature)(P1,P2,P3,P4);
};


template<class R, class T, class P1, class P2, class P3>
class Signature<R,T,P1,P2,P3,void,void,void,void,void>
{
public:
	typedef R (T::*signature)(P1,P2,P3);
};



template<class R, class T, class P1, class P2>
class Signature<R,T,P1,P2,void,void,void,void,void,void>
{
public:
	typedef R (T::*signature)(P1,P2);
};

template<class R, class T, class P1>
class Signature<R,T,P1,void,void,void,void,void,void,void>
{
public:
	typedef R (T::*signature)(P1);
};


template<class R, class T>
class Signature<R,T,void,void,void,void,void,void,void,void>
{
public:
	typedef R (T::*signature)();
};

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// Invokers for Perl/C++ bindings
//////////////////////////////////////////////////////////////////

template<class R, class T, class P1, class P2, class P3, class P4, class P5, class P6, class P7, class P8>
class Invoker
{
public:

	typedef typename Signature<R,T,P1,P2,P3,P4,P5,P6,P7,P8>::signature Member;

	static void invoke8( const I32 ax, T* t, Member member, 
						 typename PerlParamType<P1>::StackType* p1, 
						 typename PerlParamType<P2>::StackType* p2, 
						 typename PerlParamType<P3>::StackType* p3, 
						 typename PerlParamType<P4>::StackType* p4, 
						 typename PerlParamType<P5>::StackType* p5, 
						 typename PerlParamType<P6>::StackType* p6, 
						 typename PerlParamType<P7>::StackType* p7, 
						 typename PerlParamType<P8>::StackType* p8 )
	{
		R retval = (t->*member)( 
								 PerlParamType<P1>::ParamValue(p1),
								 PerlParamType<P2>::ParamValue(p2),
								 PerlParamType<P3>::ParamValue(p3),
								 PerlParamType<P4>::ParamValue(p4),
								 PerlParamType<P5>::ParamValue(p5),
								 PerlParamType<P6>::ParamValue(p6),
								 PerlParamType<P7>::ParamValue(p7),
								 PerlParamType<P8>::ParamValue(p8)
							    );
		xs_return( ax, retval );
	}

	static void invoke7( const I32 ax, T* t, Member member, 
						 typename PerlParamType<P1>::StackType* p1, 
						 typename PerlParamType<P2>::StackType* p2, 
						 typename PerlParamType<P3>::StackType* p3, 
						 typename PerlParamType<P4>::StackType* p4, 
						 typename PerlParamType<P5>::StackType* p5, 
						 typename PerlParamType<P6>::StackType* p6, 
						 typename PerlParamType<P7>::StackType* p7 )
	{
		R retval = (t->*member)( 
								 PerlParamType<P1>::ParamValue(p1),
								 PerlParamType<P2>::ParamValue(p2),
								 PerlParamType<P3>::ParamValue(p3),
								 PerlParamType<P4>::ParamValue(p4),
								 PerlParamType<P5>::ParamValue(p5),
								 PerlParamType<P6>::ParamValue(p6),
								 PerlParamType<P7>::ParamValue(p7)
							    );
		xs_return( ax, retval );
	}


	static void invoke6( const I32 ax, T* t, Member member, 
						 typename PerlParamType<P1>::StackType* p1, 
						 typename PerlParamType<P2>::StackType* p2, 
						 typename PerlParamType<P3>::StackType* p3, 
						 typename PerlParamType<P4>::StackType* p4, 
						 typename PerlParamType<P5>::StackType* p5, 
						 typename PerlParamType<P6>::StackType* p6 ) 
	{
		R retval = (t->*member)( 
								 PerlParamType<P1>::ParamValue(p1),
								 PerlParamType<P2>::ParamValue(p2),
								 PerlParamType<P3>::ParamValue(p3),
								 PerlParamType<P4>::ParamValue(p4),
								 PerlParamType<P5>::ParamValue(p5),
								 PerlParamType<P6>::ParamValue(p6)
							    );
		xs_return( ax, retval );
	}


	static void invoke5( const I32 ax, T* t, Member member, 
						 typename PerlParamType<P1>::StackType* p1, 
						 typename PerlParamType<P2>::StackType* p2, 
						 typename PerlParamType<P3>::StackType* p3, 
						 typename PerlParamType<P4>::StackType* p4, 
						 typename PerlParamType<P5>::StackType* p5 ) 
	{
		R retval = (t->*member)( 
								 PerlParamType<P1>::ParamValue(p1),
								 PerlParamType<P2>::ParamValue(p2),
								 PerlParamType<P3>::ParamValue(p3),
								 PerlParamType<P4>::ParamValue(p4),
								 PerlParamType<P5>::ParamValue(p5)
							    );
		xs_return( ax, retval );
	}


	static void invoke4( const I32 ax, T* t, Member member, 
						 typename PerlParamType<P1>::StackType* p1, 
						 typename PerlParamType<P2>::StackType* p2, 
						 typename PerlParamType<P3>::StackType* p3, 
						 typename PerlParamType<P4>::StackType* p4 ) 
	{
		R retval = (t->*member)( 
								 PerlParamType<P1>::ParamValue(p1),
								 PerlParamType<P2>::ParamValue(p2),
								 PerlParamType<P3>::ParamValue(p3),
								 PerlParamType<P4>::ParamValue(p4)
							    );
		xs_return( ax, retval );
	}


	static void invoke3( const I32 ax, T* t, Member member, 
						 typename PerlParamType<P1>::StackType* p1, 
						 typename PerlParamType<P2>::StackType* p2, 
						 typename PerlParamType<P3>::StackType* p3 ) 
	{
		R retval = (t->*member)( 
								 PerlParamType<P1>::ParamValue(p1),
								 PerlParamType<P2>::ParamValue(p2),
								 PerlParamType<P3>::ParamValue(p3)
							    );
		xs_return( ax, retval );
	}

	static void invoke2( const I32 ax, T* t, Member member, typename PerlParamType<P1>::StackType* p1, typename PerlParamType<P2>::StackType* p2 )
	{
		R retval = (t->*member)(PerlParamType<P1>::ParamValue(p1),PerlParamType<P2>::ParamValue(p2));
		xs_return( ax, retval );
	}

	static void invoke1( const I32 ax, T* t, Member member, typename PerlParamType<P1>::StackType* p1 )
	{
		R retval = (t->*member)(PerlParamType<P1>::ParamValue(p1));
		xs_return( ax, retval );
	}

	static void invoke0( const I32 ax, T* t, Member member)
	{
		R retval = (t->*member)();
		xs_return( ax, retval );
	}
};

//////////////////////////////////////////////////////////////////

template<class T, class P1, class P2, class P3, class P4, class P5, class P6, class P7, class P8>
class Invoker<void,T,P1,P2,P3,P4,P5,P6,P7,P8>
{
public:

	typedef typename Signature<void,T,P1,P2,P3,P4,P5,P6,P7,P8>::signature Member;

	static void invoke8( const I32 ax, T* t, Member member, 
						 typename PerlParamType<P1>::StackType* p1, 
						 typename PerlParamType<P2>::StackType* p2, 
						 typename PerlParamType<P3>::StackType* p3, 
						 typename PerlParamType<P4>::StackType* p4, 
						 typename PerlParamType<P5>::StackType* p5, 
						 typename PerlParamType<P6>::StackType* p6, 
						 typename PerlParamType<P7>::StackType* p7, 
						 typename PerlParamType<P8>::StackType* p8 )
	{
		(t->*member)( 
				 PerlParamType<P1>::ParamValue(p1),
				 PerlParamType<P2>::ParamValue(p2),
				 PerlParamType<P3>::ParamValue(p3),
				 PerlParamType<P4>::ParamValue(p4),
				 PerlParamType<P5>::ParamValue(p5),
				 PerlParamType<P6>::ParamValue(p6),
				 PerlParamType<P7>::ParamValue(p7),
				 PerlParamType<P8>::ParamValue(p8)
				);
		xs_return( ax );
	}

	static void invoke7( const I32 ax, T* t, Member member, 
						 typename PerlParamType<P1>::StackType* p1, 
						 typename PerlParamType<P2>::StackType* p2, 
						 typename PerlParamType<P3>::StackType* p3, 
						 typename PerlParamType<P4>::StackType* p4, 
						 typename PerlParamType<P5>::StackType* p5, 
						 typename PerlParamType<P6>::StackType* p6, 
						 typename PerlParamType<P7>::StackType* p7 )
	{
		(t->*member)( 
				 PerlParamType<P1>::ParamValue(p1),
				 PerlParamType<P2>::ParamValue(p2),
				 PerlParamType<P3>::ParamValue(p3),
				 PerlParamType<P4>::ParamValue(p4),
				 PerlParamType<P5>::ParamValue(p5),
				 PerlParamType<P6>::ParamValue(p6),
				 PerlParamType<P7>::ParamValue(p7)
				);
		xs_return( ax );
	}

	static void invoke6( const I32 ax, T* t, Member member, 
						 typename PerlParamType<P1>::StackType* p1, 
						 typename PerlParamType<P2>::StackType* p2, 
						 typename PerlParamType<P3>::StackType* p3, 
						 typename PerlParamType<P4>::StackType* p4, 
						 typename PerlParamType<P5>::StackType* p5, 
						 typename PerlParamType<P6>::StackType* p6 ) 
	{
		(t->*member)( 
				 PerlParamType<P1>::ParamValue(p1),
				 PerlParamType<P2>::ParamValue(p2),
				 PerlParamType<P3>::ParamValue(p3),
				 PerlParamType<P4>::ParamValue(p4),
				 PerlParamType<P5>::ParamValue(p5),
				 PerlParamType<P6>::ParamValue(p6)
				);
		xs_return( ax );
	}

	static void invoke5( const I32 ax, T* t, Member member, 
						 typename PerlParamType<P1>::StackType* p1, 
						 typename PerlParamType<P2>::StackType* p2, 
						 typename PerlParamType<P3>::StackType* p3, 
						 typename PerlParamType<P4>::StackType* p4, 
						 typename PerlParamType<P5>::StackType* p5 ) 
	{
		(t->*member)( 
				 PerlParamType<P1>::ParamValue(p1),
				 PerlParamType<P2>::ParamValue(p2),
				 PerlParamType<P3>::ParamValue(p3),
				 PerlParamType<P4>::ParamValue(p4),
				 PerlParamType<P5>::ParamValue(p5)
				);
		xs_return( ax );
	}

	static void invoke4( const I32 ax, T* t, Member member, 
						 typename PerlParamType<P1>::StackType* p1, 
						 typename PerlParamType<P2>::StackType* p2, 
						 typename PerlParamType<P3>::StackType* p3, 
						 typename PerlParamType<P4>::StackType* p4 ) 
	{
		(t->*member)( 
				 PerlParamType<P1>::ParamValue(p1),
				 PerlParamType<P2>::ParamValue(p2),
				 PerlParamType<P3>::ParamValue(p3),
				 PerlParamType<P4>::ParamValue(p4)
				);
		xs_return( ax );
	}

	static void invoke3( const I32 ax, T* t, Member member, 
						 typename PerlParamType<P1>::StackType* p1, 
						 typename PerlParamType<P2>::StackType* p2, 
						 typename PerlParamType<P3>::StackType* p3 ) 
	{
		(t->*member)( 
				 PerlParamType<P1>::ParamValue(p1),
				 PerlParamType<P2>::ParamValue(p2),
				 PerlParamType<P3>::ParamValue(p3)
				);
		xs_return( ax );
	}
				
	static void invoke2( const I32 ax, T* t, Member member, typename PerlParamType<P1>::StackType* p1, typename PerlParamType<P2>::StackType* p2 )
	{
		(t->*member)(PerlParamType<P1>::ParamValue(p1),PerlParamType<P2>::ParamValue(p2));
		xs_return( ax );
	}

	static void invoke1( const I32 ax, T* t, Member member, typename PerlParamType<P1>::StackType* p1 )
	{
		(t->*member)(PerlParamType<P1>::ParamValue(p1));
		xs_return( ax );
	}

	static void invoke0( const I32 ax, T* t, Member member)
	{
		(t->*member)();
		xs_return( ax );
	}
};

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

class PerlClassCallBase
{
public:
	virtual ~PerlClassCallBase() {}
	virtual void jump(pTHX_ CV* cv) = 0;
};

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

template< class R, 
	      class T,
		  class P1 = void,
		  class P2 = void,
		  class P3 = void,
		  class P4 = void,
		  class P5 = void,
		  class P6 = void,
		  class P7 = void,
		  class P8 = void >
class PerlClassCall : public PerlClassCallBase
{
public:

	typedef T PerlClass;
	typedef typename Signature<R,T,P1,P2,P3,P4,P5,P6,P7,P8>::signature Member;

	PerlClassCall( Member m )
	 : member(m)
	{}

	void jump(pTHX_ CV* cv)
	{
		dXSARGS;
		if ( items > 0 )
		{
			T* t;
			get_perl_value(ST(0),&t);

			typename PerlParamType<P1>::StackType p1;
			typename PerlParamType<P2>::StackType p2;
			typename PerlParamType<P3>::StackType p3;
			typename PerlParamType<P4>::StackType p4;
			typename PerlParamType<P5>::StackType p5;
			typename PerlParamType<P6>::StackType p6;
			typename PerlParamType<P7>::StackType p7;
			typename PerlParamType<P8>::StackType p8;

			if ( items > 1 ) PerlParamType<P1>::get_value( ST(1), &p1 );
			if ( items > 2 ) PerlParamType<P2>::get_value( ST(2), &p2 );
			if ( items > 3 ) PerlParamType<P3>::get_value( ST(3), &p3 );
			if ( items > 4 ) PerlParamType<P4>::get_value( ST(4), &p4 );
			if ( items > 5 ) PerlParamType<P5>::get_value( ST(5), &p5 );
			if ( items > 6 ) PerlParamType<P6>::get_value( ST(6), &p6 );
			if ( items > 7 ) PerlParamType<P7>::get_value( ST(7), &p7 );
			if ( items > 8 ) PerlParamType<P8>::get_value( ST(8), &p8 );

			Invoker<R,T,P1,P2,P3,P4,P5,P6,P7,P8>::invoke8( ax, t, member, &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8 );

			if ( items > 1 ) PerlParamType<P1>::set_ref_value( ST(1), &p1 );
			if ( items > 2 ) PerlParamType<P2>::set_ref_value( ST(2), &p2 );
			if ( items > 3 ) PerlParamType<P3>::set_ref_value( ST(3), &p3 );
			if ( items > 4 ) PerlParamType<P4>::set_ref_value( ST(4), &p4 );
			if ( items > 5 ) PerlParamType<P5>::set_ref_value( ST(5), &p5 );
			if ( items > 6 ) PerlParamType<P6>::set_ref_value( ST(6), &p6 );
			if ( items > 7 ) PerlParamType<P7>::set_ref_value( ST(7), &p7 );
			if ( items > 8 ) PerlParamType<P8>::set_ref_value( ST(8), &p8 );

			return;
		}
		xs_return(ax);
	}

	Member member;
};

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

template< class R, class T, class P1, class P2, class P3, class P4, class P5, class P6, class P7 >
class PerlClassCall<R,T,P1,P2,P3,P4,P5,P6,P7,void> : public PerlClassCallBase
{
public:

	typedef T PerlClass;
	typedef typename Signature<R,T,P1,P2,P3,P4,P5,P6,P7,void>::signature Member;

	PerlClassCall( Member m )
	 : member(m)
	{}

	void jump(pTHX_ CV* cv)
	{
		dXSARGS;
		if ( items > 0 )
		{
			T* t;
			get_perl_value(ST(0),&t);

			typename PerlParamType<P1>::StackType p1;
			typename PerlParamType<P2>::StackType p2;
			typename PerlParamType<P3>::StackType p3;
			typename PerlParamType<P4>::StackType p4;
			typename PerlParamType<P5>::StackType p5;
			typename PerlParamType<P6>::StackType p6;
			typename PerlParamType<P7>::StackType p7;

			if ( items > 1 ) PerlParamType<P1>::get_value( ST(1), &p1 );
			if ( items > 2 ) PerlParamType<P2>::get_value( ST(2), &p2 );
			if ( items > 3 ) PerlParamType<P3>::get_value( ST(3), &p3 );
			if ( items > 4 ) PerlParamType<P4>::get_value( ST(4), &p4 );
			if ( items > 5 ) PerlParamType<P5>::get_value( ST(5), &p5 );
			if ( items > 6 ) PerlParamType<P6>::get_value( ST(6), &p6 );
			if ( items > 7 ) PerlParamType<P7>::get_value( ST(7), &p7 );

			Invoker<R,T,P1,P2,P3,P4,P5,P6,P7,void>::invoke7( ax, t, member, &p1, &p2, &p3, &p4, &p5, &p6, &p7 );

			if ( items > 1 ) PerlParamType<P1>::set_ref_value( ST(1), &p1 );
			if ( items > 2 ) PerlParamType<P2>::set_ref_value( ST(2), &p2 );
			if ( items > 3 ) PerlParamType<P3>::set_ref_value( ST(3), &p3 );
			if ( items > 4 ) PerlParamType<P4>::set_ref_value( ST(4), &p4 );
			if ( items > 5 ) PerlParamType<P5>::set_ref_value( ST(5), &p5 );
			if ( items > 6 ) PerlParamType<P6>::set_ref_value( ST(6), &p6 );
			if ( items > 7 ) PerlParamType<P7>::set_ref_value( ST(7), &p7 );

			return;
		}
		xs_return(ax);
	}

	Member member;
};


//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

template< class R, class T, class P1, class P2, class P3, class P4, class P5, class P6>
class PerlClassCall<R,T,P1,P2,P3,P4,P5,P6,void,void> : public PerlClassCallBase
{
public:

	typedef T PerlClass;
	typedef typename Signature<R,T,P1,P2,P3,P4,P5,P6,void,void>::signature Member;

	PerlClassCall( Member m )
	 : member(m)
	{}

	void jump(pTHX_ CV* cv)
	{
		dXSARGS;
		if ( items > 0 )
		{
			T* t;
			get_perl_value(ST(0),&t);

			typename PerlParamType<P1>::StackType p1;
			typename PerlParamType<P2>::StackType p2;
			typename PerlParamType<P3>::StackType p3;
			typename PerlParamType<P4>::StackType p4;
			typename PerlParamType<P5>::StackType p5;
			typename PerlParamType<P6>::StackType p6;

			if ( items > 1 ) PerlParamType<P1>::get_value( ST(1), &p1 );
			if ( items > 2 ) PerlParamType<P2>::get_value( ST(2), &p2 );
			if ( items > 3 ) PerlParamType<P3>::get_value( ST(3), &p3 );
			if ( items > 4 ) PerlParamType<P4>::get_value( ST(4), &p4 );
			if ( items > 5 ) PerlParamType<P5>::get_value( ST(5), &p5 );
			if ( items > 6 ) PerlParamType<P6>::get_value( ST(6), &p6 );

			Invoker<R,T,P1,P2,P3,P4,P5,P6,void,void>::invoke6( ax, t, member, &p1, &p2, &p3, &p4, &p5, &p6 );

			if ( items > 1 ) PerlParamType<P1>::set_ref_value( ST(1), &p1 );
			if ( items > 2 ) PerlParamType<P2>::set_ref_value( ST(2), &p2 );
			if ( items > 3 ) PerlParamType<P3>::set_ref_value( ST(3), &p3 );
			if ( items > 4 ) PerlParamType<P4>::set_ref_value( ST(4), &p4 );
			if ( items > 5 ) PerlParamType<P5>::set_ref_value( ST(5), &p5 );
			if ( items > 6 ) PerlParamType<P6>::set_ref_value( ST(6), &p6 );

			return;
		}
		xs_return(ax);
	}

	Member member;
};


//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

template< class R, class T, class P1, class P2, class P3, class P4, class P5>
class PerlClassCall<R,T,P1,P2,P3,P4,P5,void,void,void> : public PerlClassCallBase
{
public:

	typedef T PerlClass;
	typedef typename Signature<R,T,P1,P2,P3,P4,P5,void,void,void>::signature Member;

	PerlClassCall( Member m )
	 : member(m)
	{}

	void jump(pTHX_ CV* cv)
	{
		dXSARGS;
		if ( items > 0 )
		{
			T* t;
			get_perl_value(ST(0),&t);

			typename PerlParamType<P1>::StackType p1;
			typename PerlParamType<P2>::StackType p2;
			typename PerlParamType<P3>::StackType p3;
			typename PerlParamType<P4>::StackType p4;
			typename PerlParamType<P5>::StackType p5;

			if ( items > 1 ) PerlParamType<P1>::get_value( ST(1), &p1 );
			if ( items > 2 ) PerlParamType<P2>::get_value( ST(2), &p2 );
			if ( items > 3 ) PerlParamType<P3>::get_value( ST(3), &p3 );
			if ( items > 4 ) PerlParamType<P4>::get_value( ST(4), &p4 );
			if ( items > 5 ) PerlParamType<P5>::get_value( ST(5), &p5 );

			Invoker<R,T,P1,P2,P3,P4,P5,void,void,void>::invoke5( ax, t, member, &p1, &p2, &p3, &p4, &p5 );

			if ( items > 1 ) PerlParamType<P1>::set_ref_value( ST(1), &p1 );
			if ( items > 2 ) PerlParamType<P2>::set_ref_value( ST(2), &p2 );
			if ( items > 3 ) PerlParamType<P3>::set_ref_value( ST(3), &p3 );
			if ( items > 4 ) PerlParamType<P4>::set_ref_value( ST(4), &p4 );
			if ( items > 5 ) PerlParamType<P5>::set_ref_value( ST(5), &p5 );

			return;
		}
		xs_return(ax);
	}

	Member member;
};

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

template< class R, class T, class P1, class P2, class P3, class P4 >
class PerlClassCall<R,T,P1,P2,P3,P4,void,void,void,void> : public PerlClassCallBase
{
public:

	typedef T PerlClass;
	typedef typename Signature<R,T,P1,P2,P3,P4,void,void,void,void>::signature Member;

	PerlClassCall( Member m )
	 : member(m)
	{}

	void jump(pTHX_ CV* cv)
	{
		dXSARGS;
		if ( items > 0 )
		{
			T* t;
			get_perl_value(ST(0),&t);

			typename PerlParamType<P1>::StackType p1;
			typename PerlParamType<P2>::StackType p2;
			typename PerlParamType<P3>::StackType p3;
			typename PerlParamType<P4>::StackType p4;

			if ( items > 1 ) PerlParamType<P1>::get_value( ST(1), &p1 );
			if ( items > 2 ) PerlParamType<P2>::get_value( ST(2), &p2 );
			if ( items > 3 ) PerlParamType<P3>::get_value( ST(3), &p3 );
			if ( items > 4 ) PerlParamType<P4>::get_value( ST(4), &p4 );

			Invoker<R,T,P1,P2,P3,P4,void,void,void,void>::invoke4( ax, t, member, &p1, &p2, &p3, &p4  );

			if ( items > 1 ) PerlParamType<P1>::set_ref_value( ST(1), &p1 );
			if ( items > 2 ) PerlParamType<P2>::set_ref_value( ST(2), &p2 );
			if ( items > 3 ) PerlParamType<P3>::set_ref_value( ST(3), &p3 );
			if ( items > 4 ) PerlParamType<P4>::set_ref_value( ST(4), &p4 );

			return;
		}
		xs_return(ax);
	}

	Member member;
};


//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

template< class R, class T, class P1, class P2, class P3>
class PerlClassCall<R,T,P1,P2,P3,void,void,void,void,void> : public PerlClassCallBase
{
public:

	typedef T PerlClass;
	typedef typename Signature<R,T,P1,P2,P3,void,void,void,void,void>::signature Member;

	PerlClassCall( Member m )
	 : member(m)
	{}

	void jump(pTHX_ CV* cv)
	{
		dXSARGS;
		if ( items > 0 )
		{
			T* t;
			get_perl_value(ST(0),&t);

			typename PerlParamType<P1>::StackType p1;
			typename PerlParamType<P2>::StackType p2;
			typename PerlParamType<P3>::StackType p3;

			if ( items > 1 ) PerlParamType<P1>::get_value( ST(1), &p1 );
			if ( items > 2 ) PerlParamType<P2>::get_value( ST(2), &p2 );
			if ( items > 3 ) PerlParamType<P3>::get_value( ST(3), &p3 );

			Invoker<R,T,P1,P2,P3,void,void,void,void,void>::invoke3( ax, t, member, &p1, &p2, &p3 );

			if ( items > 1 ) PerlParamType<P1>::set_ref_value( ST(1), &p1 );
			if ( items > 2 ) PerlParamType<P2>::set_ref_value( ST(2), &p2 );
			if ( items > 3 ) PerlParamType<P3>::set_ref_value( ST(3), &p3 );

			return;
		}
		xs_return(ax);
	}

	Member member;
};


//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

template< class R, class T, class P1, class P2>
class PerlClassCall<R,T,P1,P2,void,void,void,void,void,void> : public PerlClassCallBase
{
public:

	typedef T PerlClass;
	typedef typename Signature<R,T,P1,P2,void,void,void,void,void,void>::signature Member;

	PerlClassCall( Member m )
	 : member(m)
	{}

	void jump(pTHX_ CV* cv)
	{
		dXSARGS;
		if ( items > 0 )
		{
			T* t;
			get_perl_value(ST(0),&t);

			typename PerlParamType<P1>::StackType p1;
			typename PerlParamType<P2>::StackType p2;

			if ( items > 1 ) PerlParamType<P1>::get_value( ST(1), &p1 );
			if ( items > 2 ) PerlParamType<P2>::get_value( ST(2), &p2 );

			Invoker<R,T,P1,P2,void,void,void,void,void,void>::invoke2( ax, t, member, &p1, &p2 );

			if ( items > 1 ) PerlParamType<P1>::set_ref_value( ST(1), &p1 );
			if ( items > 2 ) PerlParamType<P2>::set_ref_value( ST(2), &p2 );

			return;
		}
		xs_return(ax);
	}

	Member member;
};



//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

template< class R, class T, class P1>
class PerlClassCall<R,T,P1,void,void,void,void,void,void,void> : public PerlClassCallBase
{
public:

	typedef T PerlClass;
	typedef typename Signature<R,T,P1,void,void,void,void,void,void,void>::signature Member;

	PerlClassCall( Member m )
	 : member(m)
	{}

	void jump(pTHX_ CV* cv)
	{
		dXSARGS;
		if ( items > 0 )
		{
			T* t;
			get_perl_value(ST(0),&t);

			typename PerlParamType<P1>::StackType p1;

			if ( items > 1 ) PerlParamType<P1>::get_value( ST(1), &p1 );

			Invoker<R,T,P1,void,void,void,void,void,void,void>::invoke1( ax, t, member, &p1 );

			if ( items > 1 ) PerlParamType<P1>::set_ref_value( ST(1), &p1 );

			return;
		}
		xs_return(ax);
	}

	Member member;
};

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

template< class R, class T>
class PerlClassCall<R,T,void,void,void,void,void,void,void,void> : public PerlClassCallBase
{
public:

	typedef T PerlClass;
	typedef typename Signature<R,T,void,void,void,void,void,void,void,void>::signature Member;

	PerlClassCall( Member m )
	 : member(m)
	{}

	void jump(pTHX_ CV* cv)
	{
		dXSARGS;
		if ( items > 0 )
		{
			T* t;
			get_perl_value(ST(0),&t);

			Invoker<R,T,void,void,void,void,void,void,void,void>::invoke0( ax, t, member );

			return;
		}
		xs_return(ax);
	}

	Member member;
};

//////////////////////////////////////////////////////////////////
// PerlInterpreter* pp, CV* cv
//////////////////////////////////////////////////////////////////

template<>
class PerlClassCall<void,void,PerlInterpreter*,CV*,void,void,void,void,void,void> : public PerlClassCallBase
{
public:

	typedef void PerlClass;
	typedef void (*Member)(PerlInterpreter*,CV* cv);

	PerlClassCall( Member m )
	 : member(m)
	{}

	void jump(PerlInterpreter* pp, CV* cv)
	{
		(*member)(pp,cv);
	}

	Member member;
};

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
// template functions to use template argument deduction for
// perl/c++ bindings
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

template<class R, class T, class P1, class P2, class P3, class P4, class P5, class P6, class P7, class P8>
PerlClassCallBase* make_perl_class_call( R (T::*member)(P1,P2,P3,P4,P5,P6,P7,P8) )
{
	return new PerlClassCall<R,T,P1,P2,P3,P4,P5,P6,P7,P8>(member);
}

//////////////////////////////////////////////////////////////////

template<class R, class T, class P1, class P2, class P3, class P4, class P5, class P6, class P7>
PerlClassCallBase* make_perl_class_call( R (T::*member)(P1,P2,P3,P4,P5,P6,P7) )
{
	return new PerlClassCall<R,T,P1,P2,P3,P4,P5,P6,P7>(member);
}


//////////////////////////////////////////////////////////////////

template<class R, class T, class P1, class P2, class P3, class P4, class P5, class P6>
PerlClassCallBase* make_perl_class_call( R (T::*member)(P1,P2,P3,P4,P5,P6) )
{
	return new PerlClassCall<R,T,P1,P2,P3,P4,P5,P6>(member);
}


//////////////////////////////////////////////////////////////////

template<class R, class T, class P1, class P2, class P3, class P4, class P5>
PerlClassCallBase* make_perl_class_call( R (T::*member)(P1,P2,P3,P4,P5) )
{
	return new PerlClassCall<R,T,P1,P2,P3,P4,P5>(member);
}


//////////////////////////////////////////////////////////////////

template<class R, class T, class P1, class P2, class P3, class P4>
PerlClassCallBase* make_perl_class_call( R (T::*member)(P1,P2,P3,P4) )
{
	return new PerlClassCall<R,T,P1,P2,P3,P4>(member);
}


//////////////////////////////////////////////////////////////////

template<class R, class T, class P1, class P2, class P3>
PerlClassCallBase* make_perl_class_call( R (T::*member)(P1,P2,P3) )
{
	return new PerlClassCall<R,T,P1,P2,P3>(member);
}

//////////////////////////////////////////////////////////////////

template<class R, class T, class P1, class P2>
PerlClassCallBase* make_perl_class_call( R (T::*member)(P1,P2) )
{
	return new PerlClassCall<R,T,P1,P2>(member);
}

//////////////////////////////////////////////////////////////////

template<class R, class T, class P1>
PerlClassCallBase* make_perl_class_call( R (T::*member)(P1) )
{
	return new PerlClassCall<R,T,P1>(member);
}

//////////////////////////////////////////////////////////////////

template<class R, class T>
PerlClassCallBase* make_perl_class_call( R (T::*member)() )
{
	return new PerlClassCall<R,T>(member);
}

//////////////////////////////////////////////////////////////////
// low level support case
//////////////////////////////////////////////////////////////////

inline PerlClassCallBase* make_perl_class_call( void (*member)(PerlInterpreter*,CV*) )
{
	return new PerlClassCall<void,void,PerlInterpreter*,CV*>(member);
}

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
// hacky Meta Data Class Def Insertion Macros
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

#define perl_exposed_as(type,classname) 					\
typedef type PerlClassType;									\
static const char* PerlClassName() { return classname; }	\
static void xs_init()										\
{															\
	type t;													\
	for ( std::list<PerlGlue::xs_init_helper>::iterator it = xs_inits().begin(); it != xs_inits().end(); it++ )	\
	{														\
		newXS( (char*)(*it).name.c_str(), (*it).func, (char*)(*it).file.c_str() );		\
	}														\
}															\
static std::list<PerlGlue::xs_init_helper>& xs_inits()		\
{															\
	static std::list<PerlGlue::xs_init_helper> xi;			\
	return xi;												\
}															\
static void static_##type##_new(pTHX_ CV* cv)				\
{															\
	dXSARGS;												\
	if ( items == 1 )										\
	{														\
		STRLEN na;											\
		char* CLASS;										\
		PerlGlue::get_perl_value( ST(0), &CLASS );			\
		type* t = new type;									\
		PerlGlue::xs_return( ax, t );						\
		return;												\
	}														\
	XSRETURN(0);											\
}															\
static void static_##type##_DESTROY(pTHX_ CV* cv)			\
{															\
	dXSARGS;												\
	if ( items == 1 )										\
	{														\
		type* t;											\
		PerlGlue::get_perl_value(ST(0),&t);					\
		delete t;											\
	}														\
	XSRETURN(0);											\
}															\
class inner_perl_meta_class									\
{															\
public:														\
	inner_perl_meta_class()									\
	{														\
		static int i = init();								\
	}														\
	int init()												\
	{														\
		std::ostringstream oss1;							\
		oss1 << PerlClassType::PerlClassName() << "::new";	\
		xs_inits().push_back( 								\
				PerlGlue::xs_init_helper( oss1.str(), 		\
								&PerlClassType::static_##type##_new, \
								__FILE__ ) );				\
		std::ostringstream oss2;							\
		oss2 << PerlClassType::PerlClassName() << "::DESTROY";	\
		xs_inits().push_back( 								\
				PerlGlue::xs_init_helper( oss2.str(),		\
								&PerlClassType::static_##type##_DESTROY, \
								__FILE__ ) );				\
		return 1;											\
	}														\
} inner_perl_meta_class_member;								

#define perl_exposed(type) perl_exposed_as(type,#type)									

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

#define perl_boot_as(Type,Name)								\
extern "C"	{												\
XS(boot_##Name);											\
XS(boot_##Name)												\
{															\
    dXSARGS;												\
    XS_VERSION_BOOTCHECK ;									\
	Type::xs_init();										\
    XSRETURN_YES;											\
} }

#define perl_boot(Type)	perl_boot_as(Type,#Type)

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

#define perl_export(member)												\
class inner_perl_callable_##member##_class								\
{																		\
public:																	\
	inner_perl_callable_##member##_class()								\
	{																	\
		static int i = init();											\
	}																	\
	int init()															\
	{																	\
		std::ostringstream oss;											\
		oss << PerlClassType::PerlClassName() << "::" << #member;		\
		xs_inits().push_back( 											\
				PerlGlue::xs_init_helper( oss.str(), 					\
								&PerlClassType::static_##member##_trampoline, \
								__FILE__ ) );							\
		return 1;														\
	}																	\
} inner_perl_callable_##member##_class_member;							\
																		\
static void static_##member##_trampoline(PerlInterpreter* pp, CV* cv)	\
{																		\
	static PerlGlue::PerlClassCallBase* pccb = 							\
		PerlGlue::make_perl_class_call( &PerlClassType::member); 		\
	pccb->jump(pp,cv);													\
}

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
// embedded perl interpreter
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

class Perl 
{
public:

	typedef void (*initializer)();

	Perl(int argc = 0, char **argv = 0, char **env = 0)
	{
		init();
	}

	~Perl()
	{
		destroy();
	}

	void init()
	{
		my_perl = perl_alloc();
		PL_perl_destruct_level = 1;
		perl_construct(my_perl);
		PL_exit_flags |= PERL_EXIT_DESTRUCT_END;	
		theMap().insert(std::make_pair(my_perl,this));
	}

	void destroy()
	{
		theMap().erase(my_perl);
		perl_destruct(my_perl);
		perl_free(my_perl);
	}

	// parse, then run or call
	void parse( int argc, char** argv, char** env = NULL)
	{
		perl_parse(my_perl, &Perl::xs_init, argc, argv, env);
	}

	void run()
	{
		perl_run(my_perl);
	}

	void call( const std::string& fun, int opts = G_DISCARD | G_NOARGS, char** args = 0 )
	{
		call_argv( fun.c_str(), opts, args);
	}

	// embedd, then eval
	void embed( char** env = NULL )
	{
		char *embedding[] = { "", "-e", "0" };
		parse( 3, embedding, env );
	}

	void eval( const std::string& code , bool croak_on_err = true)
	{
		eval_pv( code.c_str(), croak_on_err );
	}

	// get/set global Perl vars

	template<class T>
	void get_val( T& t, const std::string& name )
	{
		SV* sv = 0;
		sv = perl_get_sv( name.c_str(), TRUE );
		get_perl_value( sv, &t );
	}

	template<class T>
	void set_val(const T& t, const std::string& name )
	{
		SV* sv = 0;
		sv = perl_get_sv( name.c_str(), TRUE );
		set_perl_value( sv, t );
	}

	// inject some c++ obj into perl

	// inject a pointer to obj. Perl will own and delete it
	template<class T>
	void inject(T* t, const std::string& name)
	{
		SV* sv = 0;
		sv = perl_get_sv( name.c_str(), TRUE );
		set_perl_value( sv, t );
	}

	// inject a reference to obj. Perl will NOT own and NOT delete it
	template<class T>
	void inject(T& t, const std::string& name)
	{
		SV* sv = 0;
		sv = perl_get_sv( name.c_str(), TRUE );
		set_perl_value( sv, &t );
		SvREFCNT_inc(dereference(sv));
	}

	// make perl aware of a class definition in c++
	template<class T>
	void addClassDef()
	{
		xs_inits_.push_back((initializer)&T::xs_init);
	}

	// main xs_init hook
	static void xs_init(PerlInterpreter* pi)
	{
		if ( theMap().count(pi) > 0 )
		{
			theMap()[pi]->xs_init_impl();
		}
	}

	void set_ctx()
	{
		PERL_SET_CONTEXT(my_perl);
	}

private:

	void xs_init_impl()
	{
		newXS( "DynaLoader::boot_DynaLoader", boot_DynaLoader, __FILE__ );	
		for ( std::list<initializer>::iterator it = xs_inits_.begin(); it != xs_inits_.end(); it++ )
		{
			(*it)();
		}
	}

	PerlInterpreter* my_perl;  
	std::list<initializer> xs_inits_;

	typedef std::map<PerlInterpreter*,Perl*> MapType;

	static MapType& theMap()
	{
		static MapType theMap_;
		return theMap_;
	}
};

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

} // end namespace PerlGlue

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

#endif


//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////







