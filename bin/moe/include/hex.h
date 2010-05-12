#ifndef _MOE_DEF_HEX_EDITOR_DEFINE_
#define _MOE_DEF_HEX_EDITOR_DEFINE_

#include "shared.h"

using namespace mol::win;
using namespace mol::ole;
using namespace mol;

//////////////////////////////////////////////////////////////////////////////////
// Editor Wnd
//////////////////////////////////////////////////////////////////////////////////

class Hex 
	: 
	public MdiChildFrame<Hex,AxWnd<Hex,MdiChild,&CLSID_HexCtrl>>,
	public DispatchMidiWindow<Hex,IDoc>,
	public ProvideClassInfo<Hex>,
	public interfaces< Hex, implements< IDispatch, IDoc, IProvideClassInfo> >
{
public:

	Hex();
	virtual ~Hex();

	static  Instance* CreateInstance(const mol::string& p, bool readOnly);

	void OnMDIActivate(HWND activated);
	void OnMenu( HMENU menu );
	void OnDestroy();
	void OnNcDestroy();
	void OnClose();

	void OnFind( );
	void OnSearch( FINDREPLACE* find );
    void OnHexRange(int code, int id, HWND ctrl);
	void OnBytesShown();

	/////////////////////////////////////////////////////////////////////
	// COM
	/////////////////////////////////////////////////////////////////////

	virtual HRESULT __stdcall get_Filename( BSTR* filename);
	virtual HRESULT __stdcall get_Path( BSTR* dirpath);
	virtual HRESULT __stdcall get_Type( long* type);
	virtual HRESULT __stdcall Close();
	virtual HRESULT __stdcall Activate();

protected:
	bool initialize(const mol::string& p, bool readOnly);
	void updateUI();		


	// hexwnd events sink
    class Hex_sink : public stack_obj<HexCtrlEvents>
    {
        public : outer_this(Hex,sink); 

		HRESULT virtual __stdcall OnNewFile( BSTR fname, VARIANT_BOOL vbReadOnly)
		{
			return S_OK;
		}

		HRESULT virtual __stdcall OnNewOffset(BSTR offset, BSTR val)
		{
			return S_OK;
		}

		HRESULT virtual __stdcall OnNewValue(BSTR offset, BSTR val)
		{
			return S_OK;
		}
    } sink;

};


#endif




