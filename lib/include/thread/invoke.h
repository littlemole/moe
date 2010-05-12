#ifndef MOL_ASYNC_CALL_INVOKE_POLICY_DEF_GUARD_DEF_
#define MOL_ASYNC_CALL_INVOKE_POLICY_DEF_GUARD_DEF_

#include "thread/func.h"

namespace mol {

namespace threading {

///////////////////////////////////////////////////////////////////////////////
// CallbackPolicy defines invoke policy for the completion-handler (ret-functions)
///////////////////////////////////////////////////////////////////////////////

template<class T,bool isMemFun, bool isVoidRet>
struct CallbackPolicy
{
	static void callback(T* t)
	{
		(t->retObj->*(t->retFunc->function))();
	}
};

///////////////////////////////////////////////////////////////////////////////
// CallbackPolicy for non void Callbacks
///////////////////////////////////////////////////////////////////////////////

template<class T,bool isMemFun>
struct CallbackPolicy<T,isMemFun,false>
{
	static void callback(T* t)
	{
		(t->retObj->*(t->retFunc->function))(t->Retval.Retval);
	}
};

///////////////////////////////////////////////////////////////////////////////
// CallbackPolicy for void Callbacks, c-func style
///////////////////////////////////////////////////////////////////////////////

template<class T,bool isVoidRet>
struct CallbackPolicy<T,false,isVoidRet>
{
	static void callback(T* t)
	{
		(*(t->retFunc->function))();
	}
};

///////////////////////////////////////////////////////////////////////////////
// CallbackPolicy for non void Callbacks, c-func style
///////////////////////////////////////////////////////////////////////////////

template<class T>
struct CallbackPolicy<T,false,false>
{
	static void callback(T* t)
	{
		(*(t->retFunc->function))(t->Retval.Retval);
	}
};

///////////////////////////////////////////////////////////////////////////////
// Invokepolicies for calling a thread function
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Base Class for Invoke Policies
///////////////////////////////////////////////////////////////////////////////

template<class C>
class InvokePolicyBase
{
public:
	
	// call a thread function
    template<class T>
	static void invoke( T* t);

	// call the completion handler (ret-function)
    template<class T>
	static void callback( T* t);

};


///////////////////////////////////////////////////////////////////////////////
// 6 Params
///////////////////////////////////////////////////////////////////////////////

template<class O, 
		 class R, 		  
		 class P1=void, 
		 class P2=void,
		 class P3=void,
		 class P4=void,
		 class P5=void,
		 class P6=void
		>
class InvokePolicy
	: public InvokePolicyBase< 
					InvokePolicy<O,R,P1,P2,P3,P4,P5,P6> 
				>
{
public:

	// thread on mem-fun, void ret
	template<class T,bool isMemFun, bool isVoidRet>
	struct Invoke
	{
		static void invoke(T* t)
		{
			(t->object->*t->func.function)(t->Param1.Value,t->Param2.Value,t->Param3.Value,t->Param4.Value,t->Param5.Value,t->Param6.Value);
		}
	};

	// thread on mem-fun, non-void ret
	template<class T,bool isMemFun>
	struct Invoke<T,isMemFun,false>
	{
		static void invoke(T* t)
		{
			t->Retval.Retval = (t->object->*t->func.function)(t->Param1.Value,t->Param2.Value,t->Param3.Value,t->Param4.Value,t->Param5.Value,t->Param6.Value);
		}
	};

	// thread on c-fun, void ret
	template<class T, bool isVoidRet>
	struct Invoke<T,false,isVoidRet>
	{
		static void invoke(T* t)
		{
			(*t->func.function)(t->Param1.Value,t->Param2.Value,t->Param3.Value,t->Param4.Value,t->Param5.Value,t->Param6.Value);
		}
	};

	// thread on c-fun, non-void ret
	template<class T>
	struct Invoke<T,false,false>
	{
		static void invoke(T* t)
		{
			t->Retval.Retval = (*t->func.function)(t->Param1.Value,t->Param2.Value,t->Param3.Value,t->Param4.Value,t->Param5.Value,t->Param6.Value);
		}
	};
};

///////////////////////////////////////////////////////////////////////////////
// 5 params
///////////////////////////////////////////////////////////////////////////////

template<class O, 
		 class R, 		  
		 class P1, 
		 class P2,
		 class P3,
		 class P4,
		 class P5
		>
class InvokePolicy<O,R,P1,P2,P3,P4,P5,void>
	: public InvokePolicyBase< 
					InvokePolicy<O,R,P1,P2,P3,P4,P5,void> 
				>
{
public:

	template<class T,bool isMemFun, bool isVoidRet>
	struct Invoke
	{
		static void invoke(T* t)
		{
			(t->object->*t->func.function)(t->Param1.Value,t->Param2.Value,t->Param3.Value,t->Param4.Value,t->Param5.Value);
		}
	};

	template<class T,bool isMemFun>
	struct Invoke<T,isMemFun,false>
	{
		static void invoke(T* t)
		{
			t->Retval.Retval = (t->object->*t->func.function)(t->Param1.Value,t->Param2.Value,t->Param3.Value,t->Param4.Value,t->Param5.Value);
		}
	};

	template<class T, bool isVoidRet>
	struct Invoke<T,false,isVoidRet>
	{
		static void invoke(T* t)
		{
			(*t->func.function)(t->Param1.Value,t->Param2.Value,t->Param3.Value,t->Param4.Value,t->Param5.Value);
		}
	};

	template<class T>
	struct Invoke<T,false,false>
	{
		static void invoke(T* t)
		{
			t->Retval.Retval = (*t->func.function)(t->Param1.Value,t->Param2.Value,t->Param3.Value,t->Param4.Value,t->Param5.Value);
		}
	};
};

///////////////////////////////////////////////////////////////////////////////
// 4 params
///////////////////////////////////////////////////////////////////////////////

template<class O, 
		 class R, 		  
		 class P1, 
		 class P2,
		 class P3,
		 class P4
		>
class InvokePolicy<O,R,P1,P2,P3,P4,void,void>
	: public InvokePolicyBase< 
			InvokePolicy<O,R,P1,P2,P3,P4,void,void> 
		>
{
public:

	template<class T,bool isMemFun, bool isVoidRet>
	struct Invoke
	{
		static void invoke(T* t)
		{
			(t->object->*t->func.function)(t->Param1.Value,t->Param2.Value,t->Param3.Value,t->Param4.Value);
		}
	};

	template<class T,bool isMemFun>
	struct Invoke<T,isMemFun,false>
	{
		static void invoke(T* t)
		{
			t->Retval.Retval = (t->object->*t->func.function)(t->Param1.Value,t->Param2.Value,t->Param3.Value,t->Param4.Value);
		}
	};

	template<class T, bool isVoidRet>
	struct Invoke<T,false,isVoidRet>
	{
		static void invoke(T* t)
		{
			(*t->func.function)(t->Param1.Value,t->Param2.Value,t->Param3.Value,t->Param4.Value);
		}
	};

	template<class T>
	struct Invoke<T,false,false>
	{
		static void invoke(T* t)
		{
			t->Retval.Retval = (*t->func.function)(t->Param1.Value,t->Param2.Value,t->Param3.Value,t->Param4.Value);
		}
	};
};

///////////////////////////////////////////////////////////////////////////////
// 3 params
///////////////////////////////////////////////////////////////////////////////

template<class O, 
		 class R, 		  
		 class P1, 
		 class P2,
		 class P3
		>
class InvokePolicy<O,R,P1,P2,P3,void,void,void>
	: public InvokePolicyBase< 
					InvokePolicy<O,R,P1,P2,P3,void,void,void> 
				>
{
public:

	template<class T,bool isMemFun, bool isVoidRet>
	struct Invoke
	{
		static void invoke(T* t)
		{
			(t->object->*t->func.function)(t->Param1.Value,t->Param2.Value,t->Param3.Value);
		}
	};

	template<class T,bool isMemFun>
	struct Invoke<T,isMemFun,false>
	{
		static void invoke(T* t)
		{
			t->Retval.Retval = (t->object->*t->func.function)(t->Param1.Value,t->Param2.Value,t->Param3.Value);
		}
	};

	template<class T, bool isVoidRet>
	struct Invoke<T,false,isVoidRet>
	{
		static void invoke(T* t)
		{
			(*t->func.function)(t->Param1.Value,t->Param2.Value,t->Param3.Value);
		}
	};

	template<class T>
	struct Invoke<T,false,false>
	{
		static void invoke(T* t)
		{
			t->Retval.Retval = (*t->func.function)(t->Param1.Value,t->Param2.Value,t->Param3.Value);
		}
	};
};

///////////////////////////////////////////////////////////////////////////////
// 2 params
///////////////////////////////////////////////////////////////////////////////

template<class O, 
		 class R, 		  
		 class P1, 
		 class P2
		>
class InvokePolicy<O,R,P1,P2,void,void,void,void>
	: public InvokePolicyBase< 
					InvokePolicy<O,R,P1,P2,void,void,void,void> 
				>
{
public:

	template<class T,bool isMemFun, bool isVoidRet>
	struct Invoke
	{
		static void invoke(T* t)
		{
			(t->object->*t->func.function)(t->Param1.Value,t->Param2.Value);
		}
	};

	template<class T,bool isMemFun>
	struct Invoke<T,isMemFun,false>
	{
		static void invoke(T* t)
		{
			t->Retval.Retval = (t->object->*t->func.function)(t->Param1.Value,t->Param2.Value);
		}
	};

	template<class T, bool isVoidRet>
	struct Invoke<T,false,isVoidRet>
	{
		static void invoke(T* t)
		{
			(*t->func.function)(t->Param1.Value,t->Param2.Value);
		}
	};

	template<class T>
	struct Invoke<T,false,false>
	{
		static void invoke(T* t)
		{
			t->Retval.Retval = (*t->func.function)(t->Param1.Value,t->Param2.Value);
		}
	};
};

///////////////////////////////////////////////////////////////////////////////
// 1 param
///////////////////////////////////////////////////////////////////////////////

template<class O, class R, class P1>
class InvokePolicy<O,R,P1,void,void,void,void,void>
	: public InvokePolicyBase< 
					InvokePolicy<O,R,P1,void,void,void,void,void> 
				>
{
public:

	template<class T,bool isMemFun, bool isVoidRet>
	struct Invoke
	{
		static void invoke(T* t)
		{
			(t->object->*t->func.function)(t->Param1.Value);
		}
	};

	template<class T,bool isMemFun>
	struct Invoke<T,isMemFun,false>
	{
		static void invoke(T* t)
		{
			t->Retval.Retval = (t->object->*t->func.function)(t->Param1.Value);
		}
	};

	template<class T, bool isVoidRet>
	struct Invoke<T,false,isVoidRet>
	{
		static void invoke(T* t)
		{
			(*t->func.function)(t->Param1.Value);
		}
	};

	template<class T>
	struct Invoke<T,false,false>
	{
		static void invoke(T* t)
		{
			t->Retval.Retval = (*t->func.function)(t->Param1.Value);
		}
	};
};

///////////////////////////////////////////////////////////////////////////////
// 0 params
///////////////////////////////////////////////////////////////////////////////

template<class O, class R>
class InvokePolicy<O,R,void,void,void,void,void,void>
	: public InvokePolicyBase< 
					InvokePolicy<O,R,void,void,void,void,void,void> 
				>
{
public:

	template<class T,bool isMemFun, bool isVoidRet>
	struct Invoke
	{
		static void invoke(T* t)
		{
			(t->object->*t->func.function)();
		}
	};

	template<class T,bool isMemFun>
	struct Invoke<T,isMemFun,false>
	{
		static void invoke(T* t)
		{
			t->Retval.Retval = (t->object->*t->func.function)();
		}
	};

	template<class T, bool isVoidRet>
	struct Invoke<T,false,isVoidRet>
	{
		static void invoke(T* t)
		{
			(*t->func.function)();
		}
	};

	template<class T>
	struct Invoke<T,false,false>
	{
		static void invoke(T* t)
		{
			t->Retval.Retval = (*t->func.function)();
		}
	};
};



// call a thread function
template<class C>
template<class T>
void InvokePolicyBase<C>::invoke( T* t)
{
	typedef typename C::template Invoke< T,
			   T::FuncType::FunClass::IsMemFun,
			   T::FuncType::RetTypeClass::IsVoid> Invoke;

	Invoke::invoke(t);
}

// call the completion handler (ret-function)
template<class C>
template<class T>
void InvokePolicyBase<C>::callback( T* t)
{
	if ( t->retFunc )		
		CallbackPolicy< T,
						T::RetFuncType::FunClass::IsMemFun,
						T::FuncType::RetTypeClass::IsVoid>
			::callback(t);
}

} // end namespace threading

} // end namespace mol

#endif
