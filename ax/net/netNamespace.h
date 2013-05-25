#ifndef _MOL_JSERVER_DEF_NAMESPACE_DEFINE_GUARD_
#define _MOL_JSERVER_DEF_NAMESPACE_DEFINE_GUARD_

#include "netserver.h"

////////////////////////////////////////////////////////////////////////

class Namespace : 
	public IDispatch, 
	public mol::interfaces<
				Namespace,
				mol::implements<IDispatch>>
{
public:

	typedef mol::com_obj<Namespace> Instance;
	static HRESULT CreateInstance( const std::string& path, INet* inet,IDispatch** d);

	void virtual dispose() 
	{
		clr_.release();
		inet_.release();
		id2name_.clear();
		name2id_.clear();
	};

	HRESULT virtual __stdcall GetTypeInfoCount (unsigned int FAR*  pctinfo ) 
    { 
        *pctinfo = 0;
        return S_OK; 
    }

    HRESULT virtual __stdcall GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo ) 
    { 
		*ppTInfo = 0;
        return E_NOTIMPL; 
    }

    HRESULT virtual __stdcall GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId );

    HRESULT virtual __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i);

private:

	DWORD lastId_;
	std::string path_;
	std::map<DWORD,std::string> id2name_;
	std::map<std::string,DWORD> name2id_;
	mol::punk<INet> inet_;
	mol::punk<_Net> clr_;
};

////////////////////////////////////////////////////////////////////////


#endif