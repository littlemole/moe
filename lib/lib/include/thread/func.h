#ifndef MOL_DEF_GUARD_FUNCTOR_H
#define MOL_DEF_GUARD_FUNCTOR_H

#include "util/signature.h"

namespace mol {

namespace threading {

///////////////////////////////////////////////////////////////////////////////
// Return Type Traits or do we habe a return type at all ?
///////////////////////////////////////////////////////////////////////////////

template<class T>
struct IsParamVoid
{
public:
	enum { True = 0, False = 1 };
};


template<>
struct IsParamVoid<void>
{
public:
	enum { True = 1, False = 0 };
};


template<class T>
struct ReturnTypeTraits
{
public:
	enum { IsVoid = 0 };
	T Retval;
};


template<>
struct ReturnTypeTraits<void>
{
public:
	enum { IsVoid = 1 };

};


///////////////////////////////////////////////////////////////////////////////
// Fun Traits or are we a plain-old c-style function
///////////////////////////////////////////////////////////////////////////////

template<class T>
struct FunTraits
{
	 enum { IsMemFun = 1 };
};

template<>
struct FunTraits<void>
{
	 enum { IsMemFun = 0 };
};

/////////////////////////////////////////////////////////////////////////////////////
// Functions
/////////////////////////////////////////////////////////////////////////////////////

template<class T, 
		 class R  = void, 
		 class P1 = void, 
		 class P2 = void, 
		 class P3 = void, 
		 class P4 = void, 
		 class P5 = void, 
		 class P6 = void,
		 class CallType = mol::THISCALL
>
class Func
{
public:

	enum { NPARAMS = IsParamVoid<P1>::True +
					 IsParamVoid<P2>::True +
					 IsParamVoid<P3>::True +
					 IsParamVoid<P4>::True +
					 IsParamVoid<P5>::True +
					 IsParamVoid<P6>::True 
	};

	typedef P1 								Param1Type;
	typedef P2 								Param2Type;
	typedef P3 								Param3Type;
	typedef P4 								Param4Type;
	typedef P5 								Param5Type;
	typedef P6 								Param6Type;
	
	typedef FunTraits<T>					FunClass;
	typedef ReturnTypeTraits<R>				RetTypeClass;
	typedef typename 
		mol::Signature<T,R,P1,P2,P3,P4,P5,P6>::Function 
			Function;

	Func(  Function f )
		:function(f)
	{}

	Function function;
};

#ifdef _WIN32

template<class T, 
		 class R  , 
		 class P1 , 
		 class P2 , 
		 class P3 , 
		 class P4 , 
		 class P5 , 
		 class P6 
>
class Func<T,R,P1,P2,P3,P4,P5,P6,mol::STDCALL>
{
public:

	enum { NPARAMS = IsParamVoid<P1>::True +
					 IsParamVoid<P2>::True +
					 IsParamVoid<P3>::True +
					 IsParamVoid<P4>::True +
					 IsParamVoid<P5>::True +
					 IsParamVoid<P6>::True 
	};

	typedef P1 								Param1Type;
	typedef P2 								Param2Type;
	typedef P3 								Param3Type;
	typedef P4 								Param4Type;
	typedef P5 								Param5Type;
	typedef P6 								Param6Type;
	
	typedef FunTraits<T>					FunClass;
	typedef ReturnTypeTraits<R>				RetTypeClass;
	typedef typename 
		mol::StdCallSignature<T,R,P1,P2,P3,P4,P5,P6>::Function 
			Function;

	Func(  Function f )
		:function(f)
	{}

	Function function;
};
#endif

} // end namespace threading

} // end namespace mol

#endif
