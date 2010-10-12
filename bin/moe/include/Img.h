#ifndef IMG_VIEWER_DEF_GUARD_
#define IMG_VIEWER_DEF_GUARD_

#include "shared.h"

using namespace mol;

//////////////////////////////////////////////////////////////////////////////////
// img viewer
//////////////////////////////////////////////////////////////////////////////////

class ImgViewer : 
	public MdiChildFrame<ImgViewer,MdiChild>,
	public DispatchMdiWindow<ImgViewer,IMoeDocument,MOE_DOCTYPE_PIC>,
	public ProvideClassInfo<ImgViewer>,
	public interfaces< ImgViewer, 
			implements< 
				IDispatch, 
				IMoeDocument, 
				IProvideClassInfo> >
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

   virtual HRESULT __stdcall get_Object( IDispatch **d)
   {
	   if ( !d )
		   return E_INVALIDARG;
	   *d = 0;
	   
	   mol::punk<IPictureDisp> disp;
	   HRESULT hr = pic_.copy(&disp);
	   if ( hr != S_OK )
		   return hr;

	   return disp->QueryInterface( IID_IDispatch, (void**)d );
   }

	// dummy
	punk<IUnknown> oleObject;

private:
	Picture							pic_;

	bool load(const mol::string& path);
	void updateUI();
};

#endif