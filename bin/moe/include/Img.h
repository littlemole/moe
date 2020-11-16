#ifndef IMG_VIEWER_DEF_GUARD_
#define IMG_VIEWER_DEF_GUARD_

#include "mdichild.h"
#include "resource.h"


//////////////////////////////////////////////////////////////////////////////////
// img viewer
//////////////////////////////////////////////////////////////////////////////////

class ImgViewer 
	: public MoeChild<
				ImgViewer,
				mol::MdiChild,
				MOE_DOCTYPE_PIC,
				IDM_MOE_IMG
			>
{
public:

	ImgViewer();
	virtual ~ImgViewer();

	static Instance* CreateInstance( const std::wstring& p );

	void OnMDIActivate(HWND activated);
	void OnCreate();
	LRESULT OnDestroy();
	LRESULT OnNcDestroy();
	void OnPaint();

	/////////////////////////////////////////////////////////////////////

   virtual HRESULT __stdcall get_Object( IDispatch **d);

	// dummy
	mol::punk<IUnknown> oleObject;

private:
	mol::Picture							pic_;

	bool load(const std::wstring& path);
	void updateUI();

};

#endif