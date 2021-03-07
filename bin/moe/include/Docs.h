#ifndef MOE_DOCS_DEF_GUARD_
#define MOE_DOCS_DEF_GUARD_

#include "commons.h"
#include "widgets.h"
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
	virtual HRESULT __stdcall OpenURLDialog();

	virtual HRESULT __stdcall SaveAll();
	virtual HRESULT __stdcall CloseAll();

	virtual HRESULT __stdcall get_DOCTYPE_NONE(  long* d )		{ if(d) *d =  MOE_DOCTYPE_NULL; return S_OK; }
	virtual HRESULT __stdcall get_DOCTYPE_EDITOR(  long* d )	{ if(d) *d =  MOE_DOCTYPE_DOC; return S_OK; }
	virtual HRESULT __stdcall get_DOCTYPE_DIR(long* d )			{ if(d) *d =  MOE_DOCTYPE_DIR; return S_OK; }
	virtual HRESULT __stdcall get_DOCTYPE_PIC( long* d )		{ if(d) *d =  MOE_DOCTYPE_PIC; return S_OK; }
	virtual HRESULT __stdcall get_DOCTYPE_HEX(  long* d )		{ if(d) *d =  MOE_DOCTYPE_HEX; return S_OK; }

	virtual HRESULT __stdcall get_DOCTYPE_HTML(  long* d )		{ if(d) *d =  MOE_DOCTYPE_HTML; return S_OK; }
	virtual HRESULT __stdcall get_DOCTYPE_OLE(  long* d )		{ if(d) *d =  MOE_DOCTYPE_OLE; return S_OK; }
	virtual HRESULT __stdcall get_DOCTYPE_FORM( long* d )		{ if(d) *d =  MOE_DOCTYPE_FORM; return S_OK; }
	virtual HRESULT __stdcall get_DOCTYPE_SFTP(  long* d )		{ if(d) *d =  MOE_DOCTYPE_SFTP; return S_OK; }

	// helpers

	bool open( const std::wstring& dir, MOE_DOCTYPE type, long enc, bool readOnly, IMoeDocument** doc  );
	void remove( mol::MdiChild* mdi );
	void rename( mol::MdiChild* mdi, const std::wstring& path );
	void move( mol::MdiChild* mdi, int pos );

	std::wstring getNewFileName(const std::wstring& ext);

	size_t size() { return children_.size(); }

private:

	Docs();
	virtual ~Docs(); 

	
	DocFactory* factory_;
	typedef std::list<mol::MdiChild* > childlist;
	childlist	children_;

	childlist::iterator iterator(const VARIANT& index);
	childlist::iterator iterator(mol::MdiChild* mdi);
	int key2index( const VARIANT& index );

	void erase(mol::MdiChild* mdi);
	void insert(mol::MdiChild* mdiPos,mol::MdiChild* mdi);
};

class Documents : public mol::stack_obj<Docs>
{};

#endif