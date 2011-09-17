#ifndef MOE_DOCFACTORY_DEF_GUARD_
#define MOE_DOCFACTORY_DEF_GUARD_

#include "widgets.h"

/////////////////////////////////////////////////////////////////////////////////////////////
// the document collection automation impl
/////////////////////////////////////////////////////////////////////////////////////////////

class DocFactory 
{
public:

	DocFactory() {}
	virtual ~DocFactory(); 

	virtual HRESULT __stdcall newDocument(Docs::InFiles inf , IMoeDocument** doc);
	virtual HRESULT __stdcall openDocument( const mol::string& dir, Docs::InFiles pref, bool readOnly, IMoeDocument** doc  );

private:

	mol::MdiChild* documentFactory( const mol::string& dir, Docs::InFiles pref, bool readOnly);

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