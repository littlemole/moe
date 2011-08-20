#ifndef IMG_VIEWER_DEF_GUARD_
#define IMG_VIEWER_DEF_GUARD_

#include "shared.h"

using namespace mol;

//////////////////////////////////////////////////////////////////////////////////
// img viewer
//////////////////////////////////////////////////////////////////////////////////

class ImgViewer 
	: public MoeChild<
				ImgViewer,
				mol::MdiChild,
				MOE_DOCTYPE_PIC
			>
{
public:

	ImgViewer();
	virtual ~ImgViewer();

	static Instance* CreateInstance( const mol::string& p );

	void OnMDIActivate(HWND activated);
	void OnCreate();
	LRESULT OnDestroy();
	LRESULT OnNcDestroy();
	void OnPaint();

	/////////////////////////////////////////////////////////////////////

   virtual HRESULT __stdcall get_Object( IDispatch **d);

	// dummy
	punk<IUnknown> oleObject;

private:
	Picture							pic_;

	bool load(const mol::string& path);
	void updateUI();
};

#endif