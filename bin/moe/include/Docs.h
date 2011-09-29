#ifndef MOE_DOCS_DEF_GUARD_
#define MOE_DOCS_DEF_GUARD_

#include "mdichild.h"

/////////////////////////////////////////////////////////////////////////////////////////////
// the document collection automation impl
/////////////////////////////////////////////////////////////////////////////////////////////

class Docs : 
	public mol::Dispatch<IMoeDocumentCollection>,
	public mol::interfaces< Docs, 
				mol::implements< IDispatch, IMoeDocumentCollection> >
{
friend mol::Singleton<Docs>; 
friend mol::stack_obj<Docs>;
friend class DocFactory;
public:

	typedef mol::stack_obj<Docs> Instance;

	static Instance* CreateInstance();
	virtual void dispose() {};

	virtual HRESULT __stdcall _NewEnum(IEnumVARIANT** newEnum);
	virtual HRESULT __stdcall Item( VARIANT index, IMoeDocument** item);
	virtual HRESULT __stdcall get_Count( long* cnt);

	virtual HRESULT __stdcall Remove( VARIANT index);
	virtual HRESULT __stdcall Rename( VARIANT index, VARIANT newIndex );
	virtual HRESULT __stdcall Move( VARIANT what, VARIANT to);

	virtual HRESULT __stdcall get_ActiveDoc( IMoeDocument** d );
	virtual HRESULT __stdcall Activate( VARIANT i);

	virtual HRESULT __stdcall New(IMoeDocument** d);

	virtual HRESULT __stdcall Open( BSTR fPath, IMoeDocument** d);

	virtual HRESULT __stdcall OpenEncoding( BSTR fPath, long enc, IMoeDocument** d);
	virtual HRESULT __stdcall OpenDir(BSTR dir,  IMoeDocument** d);
	virtual HRESULT __stdcall OpenHexEditor(  BSTR f, VARIANT_BOOL vbReadOnly, IMoeDocument** hex);
	virtual HRESULT __stdcall OpenHtmlFrame(  BSTR f,  IMoeDocument** htmlWnd);
	virtual HRESULT __stdcall OpenUserForm(  BSTR pathname, IMoeDocument** form );	
	virtual HRESULT __stdcall NewUserForm(  IMoeDocument** form );	
	virtual HRESULT __stdcall NewRTFDocument(IMoeDocument** d);
	virtual HRESULT __stdcall OpenRTFDocument(BSTR pathname, IMoeDocument** d);
	virtual HRESULT __stdcall OpenTailDocument( BSTR pathname, IMoeDocument** doc );	

	virtual HRESULT __stdcall SaveAll();
	virtual HRESULT __stdcall CloseAll();

	// helpers
	
	/*
	enum InFiles {
	  PREF_TXT,
	  PREF_UTF8,
	  PREF_HTML,
	  PREF_HEX,
	  PREF_FORM,
	  PREF_RTF,
	  PREF_TAIL
	};
	*/

	bool open( const mol::string& dir, MOE_DOCTYPE type, long enc, bool readOnly, IMoeDocument** doc  );
	void remove( mol::MdiChild* mdi );
	void rename( mol::MdiChild* mdi, const mol::string& path );
	void move( mol::MdiChild* mdi, int pos );

	mol::string getNewFileName(const mol::string& ext);

	size_t size() { return children_.size(); }

private:

	Docs();
	virtual ~Docs(); 

	
	DocFactory* factory_;
	typedef std::list<mol::MdiChild* > childlist;
	childlist	children_;

	childlist::iterator iterator(VARIANT& index);
	childlist::iterator iterator(mol::MdiChild* mdi);
	int key2index( VARIANT& index );

	void erase(mol::MdiChild* mdi);
	void insert(mol::MdiChild* mdiPos,mol::MdiChild* mdi);
};

class Documents : public mol::stack_obj<Docs>
{};

#endif