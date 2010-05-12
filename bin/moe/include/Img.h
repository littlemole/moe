#ifndef IMG_VIEWER_DEF_GUARD_
#define IMG_VIEWER_DEF_GUARD_

#include "shared.h"

using namespace mol;

//////////////////////////////////////////////////////////////////////////////////
// img viewer
//////////////////////////////////////////////////////////////////////////////////

class ImgViewer : 
	public MdiChildFrame<ImgViewer,MdiChild>,
	public DispatchMidiWindow<ImgViewer,IDoc>,
	public ProvideClassInfo<ImgViewer>,
	public interfaces< ImgViewer, 
			implements< 
				IDispatch, 
				IDoc, 
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
	virtual HRESULT __stdcall get_Filename( BSTR* filename);
	virtual HRESULT __stdcall get_Path( BSTR* dirpath);
	virtual HRESULT __stdcall get_Type( long* type);
	virtual HRESULT __stdcall Close();
	virtual HRESULT __stdcall Activate();

	/////////////////////////////////////////////////////////////////////

	// dummy
	punk<IUnknown> oleObject;

private:
	Picture							pic_;

	bool load(const mol::string& path);
	void updateUI();
};

#endif