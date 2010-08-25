#ifndef MOE_DOCS_DEF_GUARD_
#define MOE_DOCS_DEF_GUARD_

#include "win/res.h"
#include "win/wnd.h"
#include "shared.h"
#include "widgets.h"

/////////////////////////////////////////////////////////////////////////////////////////////
// the document collection automation impl
/////////////////////////////////////////////////////////////////////////////////////////////

class Docs : 
	public mol::Dispatch<IMoeDocumentCollection>,
	public mol::interfaces< Docs, 
				mol::implements< IDispatch, IMoeDocumentCollection> >
{
STACKSINGLETON(Docs);
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

	virtual HRESULT __stdcall OpenUTF8( BSTR fPath, IMoeDocument** d);
	virtual HRESULT __stdcall OpenDir(BSTR dir,  IMoeDocument** d);
	virtual HRESULT __stdcall OpenHexEditor(  BSTR f, VARIANT_BOOL vbReadOnly, IMoeDocument** hex);
	virtual HRESULT __stdcall OpenHtmlFrame(  BSTR f,  IMoeDocument** htmlWnd);
	virtual HRESULT __stdcall OpenUserForm(  BSTR pathname, IMoeDocument** form );	
	virtual HRESULT __stdcall NewUserForm(  IMoeDocument** form );	

	virtual HRESULT __stdcall SaveAll();
	virtual HRESULT __stdcall CloseAll();

	// helpers

	enum InFiles {
	  PREF_TXT,
	  PREF_UTF8,
	  PREF_HTML,
	  PREF_HEX,
	  PREF_FORM
	};

	bool open( int index, const mol::string& dir, InFiles pref, bool readOnly, IMoeDocument** doc  );

	mol::MdiChild* child( const mol::string& path);
	
private:

	Docs() {}
	virtual ~Docs(); 

	mol::string getNewFileName(const mol::string& ext);

	bool newFile(IMoeDocument** doc);
	bool newUFSFile(IMoeDocument** doc);

	mol::MdiChild* openPath( const mol::string& dir, InFiles pref, bool readOnly);


	// file opening helpers
	mol::MdiChild* openPathText( const mol::string& file, bool readOnly );
	mol::MdiChild* openPathUTF8( const mol::string& file, bool readOnly );
	mol::MdiChild* openPathHex ( const mol::string& file, bool readOnly );
	mol::MdiChild* openPathHtml( const mol::string& file );
	mol::MdiChild* openPathOle ( const mol::string& file );
	mol::MdiChild* openPathImg ( const mol::string& file );
	mol::MdiChild* openPathDir ( const mol::string& file );
	mol::MdiChild* openPathForm( const mol::string& file );

	typedef std::list<std::pair<mol::variant,mol::MdiChild*> > childlist;
	childlist	children_;

	childlist::iterator iterator(VARIANT& index);
	int key2index( VARIANT& index );
};

class Documents : public mol::stack_obj<Docs>
{};

#endif