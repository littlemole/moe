#ifndef MOE_DOCS_DEF_GUARD_
#define MOE_DOCS_DEF_GUARD_

#include "win/res.h"
#include "win/wnd.h"
#include "shared.h"
#include "widgets.h"

/////////////////////////////////////////////////////////////////////////////////////////////
// moe document collection
/////////////////////////////////////////////////////////////////////////////////////////////

using namespace mol;
using namespace mol::ole;
using namespace mol::win;



/////////////////////////////////////////////////////////////////////////////////////////////
// the document collection automation impl
/////////////////////////////////////////////////////////////////////////////////////////////

class Docs : 
	public Dispatch<IDocs>,
	public interfaces< Docs, implements< IDispatch, IDocs> >
{
STACKSINGLETON(Docs);
public:

	typedef stack_obj<Docs> Instance;

	static Instance* CreateInstance();
	virtual void dispose() {};

	virtual HRESULT __stdcall _NewEnum(IEnumVARIANT** newEnum);
	virtual HRESULT __stdcall Item( VARIANT index, IDoc** item);
	virtual HRESULT __stdcall Count( long* cnt);

	virtual HRESULT __stdcall Remove( VARIANT index);
	virtual HRESULT __stdcall Rename( VARIANT index, VARIANT newIndex );
	virtual HRESULT __stdcall Move( VARIANT what, VARIANT to);

	// helpers

	enum InFiles {
	  PREF_TXT,
	  PREF_UTF8,
	  PREF_HTML,
	  PREF_HEX
	};

	bool open( int index, const mol::string& dir, InFiles pref, bool readOnly, IDoc** doc  );
	bool newFile(IDoc** doc);

	mol::MdiChild* child( const mol::string& path);

private:

	Docs() {}
	virtual ~Docs(); 

	mol::string getNewFileName();

	mol::MdiChild* openPath( const mol::string& dir, InFiles pref, bool readOnly);

	// file opening helpers
	mol::MdiChild* openPathText( const mol::string& file, bool readOnly );
	mol::MdiChild* openPathUTF8( const mol::string& file, bool readOnly );
	mol::MdiChild* openPathHex ( const mol::string& file, bool readOnly );
	mol::MdiChild* openPathHtml( const mol::string& file );
	mol::MdiChild* openPathOle ( const mol::string& file );
	mol::MdiChild* openPathImg ( const mol::string& file );
	mol::MdiChild* openPathDir ( const mol::string& file );

	typedef std::list<std::pair<variant,mol::MdiChild*> > childlist;
	childlist	children_;

	childlist::iterator iterator(VARIANT& index);
	int key2index( VARIANT& index );
};

class Documents : public stack_obj<Docs>
{};

#endif