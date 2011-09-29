#ifndef MOE_DOCFACTORY_DEF_GUARD_
#define MOE_DOCFACTORY_DEF_GUARD_

#include "Docs.h"

/////////////////////////////////////////////////////////////////////////////////////////////
// the document collection automation impl
/////////////////////////////////////////////////////////////////////////////////////////////

class DocFactory 
{
public:

	DocFactory() {}
	virtual ~DocFactory(); 

	virtual HRESULT __stdcall newDocument(MOE_DOCTYPE type , IMoeDocument** doc);
	virtual HRESULT __stdcall openDocument( const mol::string& dir, MOE_DOCTYPE type, long enc, bool readOnly, IMoeDocument** doc  );

private:

	mol::MdiChild* documentFactory( const mol::string& dir, MOE_DOCTYPE type, long enc, bool readOnly);

	template<class E>
	HRESULT createFile(const mol::string& p, IMoeDocument** doc)
	{
		E::Instance* edit = E::CreateInstance( p );
		if (!edit)
			return E_FAIL;

		mol::MdiChild* c = dynamic_cast<mol::MdiChild*>(edit);

		updateUI(p,c);

		if (doc)
			return edit->QueryInterface(IID_IMoeDocument,(void**)doc);
		return S_OK;
	}

	void updateUI(const mol::string& p, mol::MdiChild* c);
}; 


#endif