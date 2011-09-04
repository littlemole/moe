#ifndef _MOE_DEF_HEX_EDITOR_DEFINE_
#define _MOE_DEF_HEX_EDITOR_DEFINE_

#include "shared.h"

using namespace mol::win;
using namespace mol::ole;
using namespace mol;

//////////////////////////////////////////////////////////////////////////////////
// Editor Wnd
//////////////////////////////////////////////////////////////////////////////////

class Hex  : public 
	MoeAxChild<
		Hex,
		MOE_DOCTYPE_HEX,
		&CLSID_HexCtrl,
		IDM_MOE_HEX
	>
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

protected:
	bool initialize(const mol::string& p, bool readOnly);
	void updateUI();		


	// hexwnd events sink
    class Hex_sink : 
		public stack_obj<HexCtrlEvents>
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




