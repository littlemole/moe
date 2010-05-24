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
				mol::implements< IDispatch, IMoeDocument> >
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

	/*

		[id(DISPID_NEWENUM), helpstring("New Enum - enable iteration from script")] 
		HRESULT _NewEnum([out,retval] IEnumVARIANT** newEnum);

		[id(DISPID_VALUE), helpstring("Item - retrieve child document by numeric or string (full document path) index")] 
		HRESULT Item([in] VARIANT i, [out,retval] IMoeDocument** docItem);

		[id(1),propget, helpstring("Count number of child documents")] 
		HRESULT Count([out,retval] long* cnt);

		/////////////////////////////////////////////////////////////////////

		[ 
		  propget, nonbrowsable,requestedit,id(2), 
		  helpstring("Get Active MDI Document Reference")
		]
		HRESULT ActiveDoc( [out,retval] IMoeDocument** d);

		/////////////////////////////////////////////////////////////////////

		[id(3), helpstring("Create new, empty (Text-Editor) MDI Child Document")] 
		HRESULT New([out,retval] IMoeDocument** d);

		[id(4), helpstring("Open existing Document in Text-Editor")] 
		HRESULT Open([in] BSTR fPath,[out,retval] IMoeDocument** d);

		[id(5), helpstring("Open Document in Text-Editor, forcing UTF-8 mode")] 
		HRESULT OpenUTF8([in] BSTR fPath,[out,retval] IMoeDocument** d);

		[id(6), helpstring("Open Directory View as MDI child")] 
		HRESULT OpenDir([in]BSTR dir, [out,retval] IMoeDocument** d);

		[id(7), helpstring("Open document file in Hex Viewer")]
		HRESULT OpenHexEditor( [in] BSTR f, [in] VARIANT_BOOL vbReadOnly, [out,retval] IMoeDocument** hex);

		[id(8), helpstring("Open HTML Document as MDI Child (embedded IE)")] 
		HRESULT OpenHtmlFrame( [in] BSTR f, [out,retval] IMoeDocument** htmlWnd);

		[id(9), helpstring("Edit a User Form")] 
		HRESULT EditUserForm( [in] BSTR pathname, [out,retval] IMoeDocument** form );	

		/////////////////////////////////////////////////////////////////////

		[id(10), helpstring("Activate MDI document with index by number or full-path")]
		HRESULT Activate([in] VARIANT i);

		[id(11), helpstring("Save All open MDI documents")] 
		HRESULT SaveAll();

		[id(12), helpstring("Close All open MDI documents")] 
		HRESULT CloseAll();

		[id(13), helpstring("Remove and close document at index / with given path")] 
		HRESULT Remove( [in] VARIANT index);

		[id(14), helpstring("Rename object at index/path to new path")] 
		HRESULT Rename( [in] VARIANT index, [in]  VARIANT newIndex);

		[id(15), helpstring("Move object from index/path to new index")] 
		HRESULT Move( [in] VARIANT what, [in] VARIANT to);

	*/
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