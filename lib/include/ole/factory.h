#ifndef MOL_COM_FACTORY_DEFINE_GUARD_DEF_
#define MOL_COM_FACTORY_DEFINE_GUARD_DEF_

#pragma once

#include "factorypolicy.h"
#include "win/app.h"
#include "ole/TypeLib.h"



namespace mol {
namespace ole {

//////////////////////////////////////////////////////////////////////
// class factory impl
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// class factory
//////////////////////////////////////////////////////////////////////

template<class T, class P = ComCreatePolicy<T,AggregationPolicyNonAggregable<T> > >
class ClassFactory : 
	public IClassFactory,
	public interfaces< ClassFactory<T,P>, implements<IClassFactory> >
{
public:

	virtual void dispose() {}

	HRESULT virtual __stdcall CreateInstance( IUnknown* pIUOuter, REFIID riid, void** ppVoid )
	{
		LOCK(mutex_);
		return creationPolicy_.CreateInstance( pIUOuter, riid, ppVoid );
	}

	HRESULT virtual __stdcall LockServer(BOOL fLock)
	{
		LOCK(mutex_);
		if ( fLock )
			mol::App().lock();
		else
			mol::App().unlock();
		return S_OK;
	}

protected:
	P						  creationPolicy_;
	mol::Mutex                mutex_;
};

//////////////////////////////////////////////////////////////////////
// ClassObject - a holder to put class implementations
// into a self-registrate-able object map
//////////////////////////////////////////////////////////////////////

class CreatableObjectHolderBase
{
public:
	CreatableObjectHolderBase()
	{}

	virtual ~CreatableObjectHolderBase()
	{}

	virtual const GUID classId()
	{
		return CLSID_NULL;
	}

	virtual HRESULT __stdcall  GetClassObject( const IID & riid, void ** ppv)
	{
		return S_FALSE;
	}

	virtual HRESULT __stdcall  RegisterClassObject( const IID & riid, void ** ppv)
	{
		return S_FALSE;
	}

	virtual HRESULT __stdcall  Register(void)
	{
		return S_FALSE;
	}

	virtual HRESULT __stdcall Unregister(void)
	{
		return S_FALSE;
	}

	virtual int regcls() { return REGCLS_MULTIPLEUSE; };

};

//////////////////////////////////////////////////////////////////////

template< class T, 
		  class P = ComCreatePolicy<
						T,
						AggregationPolicyNonAggregable<T> >, 
		  const REGCLS cls = REGCLS_SINGLEUSE >

class CreatableObjectHolder 
	: public CreatableObjectHolderBase
{
public:

	CreatableObjectHolder()
	{}

	virtual ~CreatableObjectHolder()
	{}

	virtual const GUID classId()
	{
		return T::getCoClassID();
	}

	virtual HRESULT __stdcall  GetClassObject( const IID & riid, void ** ppv)
	{
		if ( ::IsEqualIID(riid,IID_IClassFactory) || ::IsEqualIID(riid,IID_IUnknown)  )
		{
			typedef com_instance< ClassFactory<T,P> >  Factory;

			punk<Factory> factory = new Factory;
			return factory.queryInterface(riid,ppv);
		}
		*ppv = 0;
		return E_NOINTERFACE;
	}

	virtual HRESULT __stdcall  GetClassObjectNoLock( const IID & riid, void ** ppv)
	{
		if ( ::IsEqualIID(riid,IID_IClassFactory) || ::IsEqualIID(riid,IID_IUnknown)  )
		{
			typedef com_obj< ClassFactory<T,P> >  Factory;

			punk<Factory> factory = new Factory;
			return factory.queryInterface(riid,ppv);
		}
		*ppv = 0;
		return E_NOINTERFACE;
	}

	virtual HRESULT __stdcall  RegisterClassObject( const IID & riid, void ** ppv)
	{
		typedef com_obj< ClassFactory<T,P> >  Factory;

		punk<Factory> factory = new Factory;
		return factory.queryInterface(riid,ppv);
	}

	virtual HRESULT __stdcall  Register(void)
	{
		T::registerObject();
		return S_OK;
	}

	virtual HRESULT __stdcall Unregister(void)
	{
		T::unRegisterObject();
		return S_OK;
	}

	virtual int regcls()
	{
		return cls;
	}
};

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
// Basic COM createable object ( Meta data support )
///////////////////////////////////////////////////////////////

class ComRegisterObjBase
{
public:

	static HRESULT RegisterObject(REFGUID guid, DWORD miscStatus, OLEVERB* oleverbs, int flags, int clsctx, REGCLS cls);
	static HRESULT UnRegisterObject(REFGUID guid, DWORD miscStatus, OLEVERB* oleverbs, int flags, int clsctx, REGCLS cls);

	virtual void dispose() {}

	private:
	static HRESULT RegisterObjectHK( mol::TypeLib& tl, mol::RegKey& root, REFGUID guid, DWORD miscStatus, OLEVERB* oleverbs, int flags, int clsctx, REGCLS cls);

};

///////////////////////////////////////////////////////////

} // end namespace mol

enum COMREGFLAGS { NONE = 0, 
                   CONTROL = 1, 
				   INSERTABLE = 2, 
				   PROGRAMMABLE = 4,
				   MULTITHREADED = 8,
				   APARTMENT	= 16,
				   SAFE_INIT    = 32,
				   SAFE_SCRIPT  = 64,
				   DLL_SURROGATE = 128,
				   CAN_ELEVATE = 256
				 };



///////////////////////////////////////////////////////////


template< class T, 
          REFGUID I, 
		  int clsctx = CLSCTX_INPROC_SERVER, 
		  int regflags = PROGRAMMABLE|APARTMENT,
		  const REGCLS cls = REGCLS_MULTIPLEUSE>

class com_registerobj : public mol::ole::ComRegisterObjBase
{
public:

	typedef T com_creatable_type;

	com_registerobj()
	{}

	~com_registerobj()
	{}

	static REFGUID getCoClassID()
	{
		return I;
	}

	static const int getRegFlags()
	{
		return regflags;
	}

	static const DWORD getClsctx()
	{
		return clsctx;
	}

	static REGCLS getRegCls()
	{
		return cls;
	}
	
	static const REGCLS RegCls = cls;

	static void registerObject()				
	{					
		RegisterObject( T::getCoClassID(),
						0,
						0,
						T::getRegFlags(),				
						T::getClsctx(),			
						T::getRegCls() );			
	}

	static void unRegisterObject()				
	{									
		UnRegisterObject( T::getCoClassID(),
						0,
						0,
						T::getRegFlags(),				
						T::getClsctx(),			
						T::getRegCls() );			
	}

};

// local COM Server App

template<class T>
class local_server : public mol::Application<T>
{
public:
	local_server()
	{
		idThread_ = ::GetCurrentThreadId();
	}

	virtual ~local_server(void)
	{
		for ( std::list<DWORD>::iterator it = registeredObjects_.begin(); it != registeredObjects_.end(); it++ )
		{
			::CoRevokeClassObject(*it);
		}
		mol::purge(objects_);
	}

	virtual int runEmbedded(const mol::string& cmdline)
	{
			RegisterClassObjects(CLSCTX_LOCAL_SERVER );
			return msgLoop_(*this);	
	}

	virtual int runStandalone(const mol::string& cmdline)
	{
			RegisterClassObjects(CLSCTX_LOCAL_SERVER );
			return msgLoop_(*this);	
	}

    virtual int run(const mol::string& cmdline) 
	{ 
		// handle registry command line switches
		if ( _tcsicmp(cmdline.c_str(), _T("/regserver")) == 0 )
		{
			ODBGS("registering xmoe");
			RegisterServer();
			return 0;
		}
		if ( _tcsicmp(cmdline.c_str(), _T("/unregserver")) == 0 )
		{
			UnregisterServer();
			return 0;
		}

        // embedding
		if ( ( _tcsicmp(cmdline.c_str(), _T("-Embedding")) == 0 ) ||
			 ( _tcsicmp(cmdline.c_str(), _T("-Automation")) == 0 ) )
		{
			// create & register Class Object
			//RegisterClassObjects(CLSCTX_LOCAL_SERVER );
			return runEmbedded(cmdline);	
		}

		return runStandalone(cmdline);	
	}


	HRESULT virtual __stdcall  RegisterServer(void)
	{
		TypeLib tl;
		tl.load();
		tl.registerTypelib();

		for ( size_t i = 0; i < objects_.size(); i++ )
		{
			objects_[i]->Register();
		}
		return S_OK;
	}

	HRESULT virtual __stdcall  UnregisterServer(void)
	{
		for ( size_t i = 0; i < objects_.size(); i++ )
		{
			objects_[i]->Unregister();
		}
		
		TypeLib tl;
		tl.load();
		tl.unRegisterTypelib();
		return S_OK;
	}

	HRESULT virtual __stdcall RegisterClassObjects(int ctx)
	{
		for ( size_t i = 0; i < objects_.size(); i++ )
		{
			punk<IClassFactory> factory;
			HRESULT hr = objects_[i]->RegisterClassObject(IID_IClassFactory, (void**)&factory );
			if ( (hr != S_OK) || (!factory) )
				return E_FAIL;

			DWORD id = 0;
			::CoRegisterClassObject(objects_[i]->classId(),factory,ctx,objects_[i]->regcls(),&id);
			registeredObjects_.push_back(id);
		}
		return S_OK;
	}

	void virtual UnLock()
	{
		LOCK(mutex_);
		lockCount_--;
		ODBGS1("local_server::UnLock()",lockCount_);
		if ( lockCount_ == 0 )
			::PostThreadMessage( idThread_, WM_QUIT, 0, 0 );
//			::PostQuitMessage(0);
	}

	std::vector<mol::ole::CreatableObjectHolderBase*>		objects_;

protected:
	std::list<DWORD>										registeredObjects_;
	DWORD idThread_;

	template<class I>
	I* getActiveInstance( CLSID clsid )
	{
		punk<IUnknown> unk;
		HRESULT hr = ::GetActiveObject( clsid,0,&unk );
		if ( (hr == S_OK) )
		{
			I* i = 0;
			HRESULT hr = unk->QueryInterface( mol::uuidof<I>(), (void**)&i);
			if ( S_OK == hr )
				if (i)
				{
					return i;
				}
		}
		return 0;
	}
};

template<class T,class O,class P = mol::ole::ComCreatePolicy<O> >
class exports
{
public:
 exports()
 {
	 ((T*)this)->objects_.push_back(
		 new mol::ole::CreatableObjectHolder< O,
								        P,
										O::RegCls
			                          >				
									  );
 }
};

template<class T,class O>
class exports_aggregable
{
public:
 exports_aggregable()
 {
	 ((T*)this)->objects_.push_back(
			new mol::ole::CreatableObjectHolder< O,
										mol::ole::ComCreatePolicy< O, mol::ole::AggregationPolicyAggregable<O> >,
										O::RegCls
			                          >				
									  );
 }
};


template<class T,class O>
class exports_singleton
{
public:
 exports_singleton()
 {
	 ((T*)this)->objects_.push_back(
			new mol::ole::CreatableObjectHolder< O,
										mol::ole::ComSingletonPolicy<O>,
										O::RegCls
			                          >				
									  );
 }
};



} // end namespace mole

#endif