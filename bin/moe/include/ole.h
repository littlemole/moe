#ifndef OLE_MOE_DEF_GUARD_
#define OLE_MOE_DEF_GUARD_

#include "shared.h"

using namespace mol::win;
using namespace mol::ole;
using namespace mol;

class MoeWndImpl;

///////////////////////////////////////////////////////////////////////////////

class OleChild 
: 
	public mol::MdiChildFrame<OleChild, mol::AxClientWnd<OleChild,MdiChild>>,
	public DispatchMidiWindow<OleChild,IDoc>,
	public ProvideClassInfo<OleChild>,
	public interfaces< OleChild, 
			implements< IDispatch, IDoc, IProvideClassInfo> >
{
public:

	OleChild();
	virtual ~OleChild();

	static Instance* CreateInstance( const mol::string& p );
	static Instance* CreateInstance( const mol::string& dir, CLSID& clsid );

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	void OnDestroy();
	void OnNcDestroy();
	LRESULT OnMDIActivate(WPARAM unused,HWND activated);
	LRESULT OnMDIActivateLater(WPARAM unused,HWND activated);

	/////////////////////////////////////////////////////////////////////
	// COM
	/////////////////////////////////////////////////////////////////////

	virtual HRESULT __stdcall get_Filename( BSTR* filename);
	virtual HRESULT __stdcall get_Path( BSTR* dirpath);

	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall get_Type( long* type);

	/////////////////////////////////////////////////////////////////////
	virtual HRESULT __stdcall  Close();
	virtual HRESULT __stdcall  Activate();

    virtual HRESULT __stdcall IOleClientSite_SaveObject();

protected:

	virtual void OnLoadProgress(int n);

	mol::string			filename_;

	bool openFile( const mol::string& path );

};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#endif