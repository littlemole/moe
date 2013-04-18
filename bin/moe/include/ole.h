#ifndef OLE_MOE_DEF_GUARD_
#define OLE_MOE_DEF_GUARD_

#include "shared.h"
#include "mdichild.h"


class MoeWndImpl;
class TaskbarWnd;

///////////////////////////////////////////////////////////////////////////////

class OleChild 
	: public MoeChild<
				OleChild,
				mol::AxClientWnd<OleChild,mol::MdiChild>,
				MOE_DOCTYPE_OLE,
				IDM_MOE
			>
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
	void OnPaint();

	void OnMDIActivate(WPARAM unused,HWND activated);

    virtual HRESULT __stdcall IOleClientSite_SaveObject();

protected:

	virtual void OnLoadProgress(int n);
	bool openFile( const mol::string& path );
	void load(const mol::string& p, CLSID& clsid);


	mol::string			filename_;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#endif