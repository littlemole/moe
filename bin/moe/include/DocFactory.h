#ifndef MOE_DOCFACTORY_DEF_GUARD_
#define MOE_DOCFACTORY_DEF_GUARD_

#include "commons.h"

/////////////////////////////////////////////////////////////////////////////////////////////
// creates some document
/////////////////////////////////////////////////////////////////////////////////////////////

class IMoeDocumentFactory
{
public:

	IMoeDocumentFactory() {}
	virtual ~IMoeDocumentFactory()
	{}

	virtual mol::MdiChild* openDocument( const std::wstring& dir) = 0;

private:

};

/////////////////////////////////////////////////////////////////////////////////////////////
// the factory for factories
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeDocumentFactory
{
public:

	static IMoeDocumentFactory* getOpenDocumentFactory( const std::wstring& dir, MOE_DOCTYPE type, long enc, bool readOnly);
};


/////////////////////////////////////////////////////////////////////////////////////////////
// create document facade:
// create new or open document
/////////////////////////////////////////////////////////////////////////////////////////////


class DocFactory 
{
public:

	DocFactory() {}
	virtual ~DocFactory(); 

	virtual HRESULT __stdcall newDocument(MOE_DOCTYPE type , IMoeDocument** doc);
	virtual HRESULT __stdcall openDocument( const std::wstring& dir, MOE_DOCTYPE type, long enc, bool readOnly, IMoeDocument** doc  );

private:

	template<class E>
	HRESULT createFile(const std::wstring& p, IMoeDocument** doc)
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

	void updateUI(const std::wstring& p, mol::MdiChild* c);
}; 


#endif