#ifndef MOL_DEF_SIGNATRURE_GUARD_FUNCTOR_H
#define MOL_DEF_SIGNATRURE_GUARD_FUNCTOR_H

/////////////////////////////////////////////////////////////////////////////////////
// Function Signatures
/////////////////////////////////////////////////////////////////////////////////////

namespace mol {

class THISCALL {};
class STDCALL {};


/////////////////////////////////////////////////////////////////////////////////////

template<class T, class R, 
		 class P1 = void, 
		 class P2 = void, 
		 class P3 = void, 
		 class P4 = void, 
		 class P5 = void, 
		 class P6 = void>
 struct Signature
 {
	typedef R ( T::*Function)(P1,P2,P3,P4,P5,P6);

	typedef T  ObjType;
	typedef R  RetType;
	typedef P1 Param1Type;
	typedef P2 Param2Type;
	typedef P3 Param3Type;
	typedef P4 Param4Type;
	typedef P5 Param5Type;
	typedef P6 Param6Type;

	enum { nParams = 6 };
 };

/////////////////////////////////////////////////////////////////////////////////////

template<class T, class R, 
		 class P1, 
		 class P2, 
		 class P3, 
		 class P4, 
		 class P5>
 struct Signature<T,R,P1,P2,P3,P4,P5,void>
 {
 	typedef R ( T::*Function)(P1,P2,P3,P4,P5);

	typedef T  ObjType;
	typedef R  RetType;
	typedef P1 Param1Type;
	typedef P2 Param2Type;
	typedef P3 Param3Type;
	typedef P4 Param4Type;
	typedef P5 Param5Type;
	typedef void Param6Type;

	enum { nParams = 5 };
 };

/////////////////////////////////////////////////////////////////////////////////////

template<class T, class R, 
		 class P1, 
		 class P2, 
		 class P3, 
		 class P4>
 struct Signature<T,R,P1,P2,P3,P4,void,void>
 {
 	typedef R ( T::*Function)(P1,P2,P3,P4);

	typedef T  ObjType;
	typedef R  RetType;
	typedef P1 Param1Type;
	typedef P2 Param2Type;
	typedef P3 Param3Type;
	typedef P4 Param4Type;
	typedef void Param5Type;
	typedef void Param6Type;

	enum { nParams = 4 };
 };
 
/////////////////////////////////////////////////////////////////////////////////////

template<class T, class R, 
		 class P1, 
		 class P2, 
		 class P3>
struct Signature<T,R,P1,P2,P3,void,void,void>
{
 	typedef R ( T::*Function)(P1,P2,P3);

	typedef T  ObjType;
	typedef R  RetType;
	typedef P1 Param1Type;
	typedef P2 Param2Type;
	typedef P3 Param3Type;
	typedef void Param4Type;
	typedef void Param5Type;
	typedef void Param6Type;

	enum { nParams = 3 };
};

/////////////////////////////////////////////////////////////////////////////////////

template<class T, class R, 
		 class P1, 
		 class P2>
struct Signature<T,R,P1,P2,void,void,void,void>
{
 	typedef R ( T::*Function)(P1,P2);

	typedef T  ObjType;
	typedef R  RetType;
	typedef P1 Param1Type;
	typedef P2 Param2Type;
	typedef void Param3Type;
	typedef void Param4Type;
	typedef void Param5Type;
	typedef void Param6Type;

	enum { nParams = 2 };
};


/////////////////////////////////////////////////////////////////////////////////////

template<class T, class R, class P1>
struct Signature<T,R,P1,void,void,void,void,void>
{
 	typedef R ( T::*Function)(P1);

	typedef T  ObjType;
	typedef R  RetType;
	typedef P1 Param1Type;
	typedef void Param2Type;
	typedef void Param3Type;
	typedef void Param4Type;
	typedef void Param5Type;
	typedef void Param6Type;

	enum { nParams = 1 };
};


/////////////////////////////////////////////////////////////////////////////////////

template<class T, class R>
struct Signature<T,R,void,void,void,void,void,void>
{
 	typedef R ( T::*Function)();

	typedef T  ObjType;
	typedef R  RetType;
	typedef void Param1Type;
	typedef void Param2Type;
	typedef void Param3Type;
	typedef void Param4Type;
	typedef void Param5Type;
	typedef void Param6Type;

	enum { nParams = 0 };
};


/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// C-Function Signatures
/////////////////////////////////////////////////////////////////////////////////////

template<class R, 
		 class P1, 
		 class P2, 
		 class P3, 
		 class P4, 
		 class P5, 
		 class P6>
 struct Signature<void,R,P1,P2,P3,P4,P5,P6>
 {
	typedef R ( *Function)(P1,P2,P3,P4,P5,P6);

	typedef R  RetType;
	typedef P1 Param1Type;
	typedef P2 Param2Type;
	typedef P3 Param3Type;
	typedef P4 Param4Type;
	typedef P5 Param5Type;
	typedef P6 Param6Type;

	enum { nParams = 6 };
 };

/////////////////////////////////////////////////////////////////////////////////////

template<class R, 
		 class P1, 
		 class P2, 
		 class P3, 
		 class P4, 
		 class P5>
 struct Signature<void,R,P1,P2,P3,P4,P5,void>
 {
 	typedef R ( *Function)(P1,P2,P3,P4,P5);

	typedef R  RetType;
	typedef P1 Param1Type;
	typedef P2 Param2Type;
	typedef P3 Param3Type;
	typedef P4 Param4Type;
	typedef P5 Param5Type;
	typedef void Param6Type;

	enum { nParams = 5 };

 };

/////////////////////////////////////////////////////////////////////////////////////

template<class R, 
		 class P1, 
		 class P2, 
		 class P3, 
		 class P4>
 struct Signature<void,R,P1,P2,P3,P4,void,void>
 {
 	typedef R ( *Function)(P1,P2,P3,P4);

	typedef R  RetType;
	typedef P1 Param1Type;
	typedef P2 Param2Type;
	typedef P3 Param3Type;
	typedef P4 Param4Type;
	typedef void Param5Type;
	typedef void Param6Type;

	enum { nParams = 4 };

 };
 
/////////////////////////////////////////////////////////////////////////////////////

template<class R, 
		 class P1, 
		 class P2, 
		 class P3>
struct Signature<void,R,P1,P2,P3,void,void,void>
{
 	typedef R ( *Function)(P1,P2,P3);

	typedef R  RetType;
	typedef P1 Param1Type;
	typedef P2 Param2Type;
	typedef P3 Param3Type;
	typedef void Param4Type;
	typedef void Param5Type;
	typedef void Param6Type;

	enum { nParams = 3 };
};

/////////////////////////////////////////////////////////////////////////////////////

template<class R, 
		 class P1, 
		 class P2>
struct Signature<void,R,P1,P2,void,void,void,void>
{
 	typedef R ( *Function)(P1,P2);

	typedef R  RetType;
	typedef P1 Param1Type;
	typedef P2 Param2Type;
	typedef void Param3Type;
	typedef void Param4Type;
	typedef void Param5Type;
	typedef void Param6Type;

	enum { nParams = 2 };
};


/////////////////////////////////////////////////////////////////////////////////////

template<class R, 
		 class P1>
struct Signature<void,R,P1,void,void,void,void,void>
{
 	typedef R ( *Function)(P1);

	typedef R  RetType;
	typedef P1 Param1Type;
	typedef void Param2Type;
	typedef void Param3Type;
	typedef void Param4Type;
	typedef void Param5Type;
	typedef void Param6Type;

	enum { nParams = 1 };
};

/////////////////////////////////////////////////////////////////////////////////////

template<class R>
struct Signature<void,R,void,void,void,void,void,void>
{
 	typedef R ( *Function)();

	typedef R  RetType;
	typedef void Param1Type;
	typedef void Param2Type;
	typedef void Param3Type;
	typedef void Param4Type;
	typedef void Param5Type;
	typedef void Param6Type;

	enum { nParams = 0 };
};


/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
#ifdef _WIN32

template<class T, class R, 
		 class P1 = void, 
		 class P2 = void, 
		 class P3 = void, 
		 class P4 = void, 
		 class P5 = void, 
		 class P6 = void>
 struct StdCallSignature
 {
	typedef R ( __stdcall T::*Function)(P1,P2,P3,P4,P5,P6);

	typedef T  ObjType;
	typedef R  RetType;
	typedef P1 Param1Type;
	typedef P2 Param2Type;
	typedef P3 Param3Type;
	typedef P4 Param4Type;
	typedef P5 Param5Type;
	typedef P6 Param6Type;

	enum { nParams = 6 };
 };

/////////////////////////////////////////////////////////////////////////////////////

template<class T, class R, 
		 class P1, 
		 class P2, 
		 class P3, 
		 class P4, 
		 class P5>
 struct StdCallSignature<T,R,P1,P2,P3,P4,P5,void>
 {
 	typedef R ( __stdcall T::*Function)(P1,P2,P3,P4,P5);

	typedef T  ObjType;
	typedef R  RetType;
	typedef P1 Param1Type;
	typedef P2 Param2Type;
	typedef P3 Param3Type;
	typedef P4 Param4Type;
	typedef P5 Param5Type;
	typedef void Param6Type;

	enum { nParams = 5 };
 };

/////////////////////////////////////////////////////////////////////////////////////

template<class T, class R, 
		 class P1, 
		 class P2, 
		 class P3, 
		 class P4>
 struct StdCallSignature<T,R,P1,P2,P3,P4,void,void>
 {
 	typedef R ( __stdcall T::*Function)(P1,P2,P3,P4);

	typedef T  ObjType;
	typedef R  RetType;
	typedef P1 Param1Type;
	typedef P2 Param2Type;
	typedef P3 Param3Type;
	typedef P4 Param4Type;
	typedef void Param5Type;
	typedef void Param6Type;

	enum { nParams = 4 };
 };
 
/////////////////////////////////////////////////////////////////////////////////////

template<class T, class R, 
		 class P1, 
		 class P2, 
		 class P3>
struct StdCallSignature<T,R,P1,P2,P3,void,void,void>
{
 	typedef R ( __stdcall T::*Function)(P1,P2,P3);

	typedef T  ObjType;
	typedef R  RetType;
	typedef P1 Param1Type;
	typedef P2 Param2Type;
	typedef P3 Param3Type;
	typedef void Param4Type;
	typedef void Param5Type;
	typedef void Param6Type;

	enum { nParams = 3 };
};

/////////////////////////////////////////////////////////////////////////////////////

template<class T, class R, 
		 class P1, 
		 class P2>
struct StdCallSignature<T,R,P1,P2,void,void,void,void>
{
 	typedef R ( __stdcall T::*Function)(P1,P2);

	typedef T  ObjType;
	typedef R  RetType;
	typedef P1 Param1Type;
	typedef P2 Param2Type;
	typedef void Param3Type;
	typedef void Param4Type;
	typedef void Param5Type;
	typedef void Param6Type;

	enum { nParams = 2 };
};


/////////////////////////////////////////////////////////////////////////////////////

template<class T, class R, class P1>
struct StdCallSignature<T,R,P1,void,void,void,void,void>
{
 	typedef R ( __stdcall T::*Function)(P1);

	typedef T  ObjType;
	typedef R  RetType;
	typedef P1 Param1Type;
	typedef void Param2Type;
	typedef void Param3Type;
	typedef void Param4Type;
	typedef void Param5Type;
	typedef void Param6Type;

	enum { nParams = 1 };
};



/////////////////////////////////////////////////////////////////////////////////////

template<class T, class R>
struct StdCallSignature<T,R,void,void,void,void,void,void>
{
 	typedef R ( __stdcall T::*Function)();

	typedef T  ObjType;
	typedef R  RetType;
	typedef void Param1Type;
	typedef void Param2Type;
	typedef void Param3Type;
	typedef void Param4Type;
	typedef void Param5Type;
	typedef void Param6Type;

	enum { nParams = 0 };
};

#endif 

/*
template<class T, class R, 
		 class P1 = void, 
		 class P2 = void, 
		 class P3 = void, 
		 class P4 = void, 
		 class P5 = void, 
		 class P6 = void>
*/


template<class T, class R, class P1, class P2, class P3, class P4, class P5, class P6>
const Signature<T,R,P1,P2,P3,P4,P5,P6>& signature( R ( T::*Function)(P1,P2,P3,P4,P5,P6) )
{
	static Signature<T,R,P1,P2,P3,P4,P5,P6> sig;
	return sig;
}


template<class T, class R, class P1, class P2, class P3, class P4, class P5>
const Signature<T,R,P1,P2,P3,P4,P5,void>& signature( R ( T::*Function)(P1,P2,P3,P4,P5) )
{
	static Signature<T,R,P1,P2,P3,P4,P5,void> sig;
	return sig;
}


template<class T, class R, class P1, class P2, class P3, class P4>
const Signature<T,R,P1,P2,P3,P4,void,void>& signature( R ( T::*Function)(P1,P2,P3,P4) )
{
	static Signature<T,R,P1,P2,P3,P4,void,void> sig;
	return sig;
}

template<class T, class R, class P1, class P2, class P3>
const Signature<T,R,P1,P2,P3,void,void,void>& signature( R ( T::*Function)(P1,P2,P3) )
{
	static Signature<T,R,P1,P2,P3,void,void,void> sig;
	return sig;
}


template<class T, class R, class P1, class P2>
const Signature<T,R,P1,P2,void,void,void,void>& signature( R ( T::*Function)(P1,P2) )
{
	static Signature<T,R,P1,P2,void,void,void,void> sig;
	return sig;
}


template<class T, class R, class P1>
const Signature<T,R,P1,void,void,void,void,void>& signature( R ( T::*Function)(P1) )
{
	static Signature<T,R,P1,void,void,void,void,void> sig;
	return sig;
}

template<class T, class R>
const Signature<T,R,void,void,void,void,void,void>& signature( R ( T::*Function)() )
{
	static Signature<T,R,void,void,void,void,void,void> sig;
	return sig;
}


} // end namespace mol

#endif
