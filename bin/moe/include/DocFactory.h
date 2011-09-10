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
	virtual HRESULT __stdcall openDocument(Docs::InFiles inf , const mol::string& path, bool readOnly, IMoeDocument** doc);

	virtual HRESULT __stdcall open( int index, const mol::string& dir, Docs::InFiles pref, bool readOnly, IMoeDocument** doc  );

private:

	bool newFile(IMoeDocument** doc);
	bool newUFSFile(IMoeDocument** doc);
	bool newRTFFile(IMoeDocument** doc);
	bool openTailFile(const mol::string& fp, IMoeDocument** doc);

	mol::MdiChild* openPath( const mol::string& dir, Docs::InFiles pref, bool readOnly);

	// file opening helpers

	template<class T>
	mol::MdiChild* load( const mol::string& path, bool utf8, bool readOnly )
	{
		typename T::Instance* t = T::CreateInstance( path, utf8, readOnly );
		return dynamic_cast<mol::MdiChild*>(t);
	}

	template<class T>
	mol::MdiChild* load( const mol::string& path, bool readOnly )
	{
		typename T::Instance* t = T::CreateInstance( path, readOnly );
		return dynamic_cast<mol::MdiChild*>(t);
	}

	template<class T>
	mol::MdiChild* load( const mol::string& path)
	{
		typename T::Instance* t = T::CreateInstance( path );
		return dynamic_cast<mol::MdiChild*>(t);
	}

};


#endif