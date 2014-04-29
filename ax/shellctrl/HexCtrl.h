#ifndef _MOL_SHELL_HEX_DEF_H_
#define _MOL_SHELL_HEX_DEF_H_

#include "win/IO.h"
#include "win/file.h"
#include "win/CoCtrl.h"
#include "ole/DragDrop.h"
#include "ole/Ctrl.h"
#include "ole/punk.h"
#include "shellCtrl_h.h"
#include "win/Layout.h"
#include "resource.h"
#include "win/msghandler.h"
#include "win/msg_macro.h"

using namespace mol;
using namespace mol::io;

#define DISPID_HexCtrl_READONLY				1
#define DISPID_HexCtrl_DISPLAYCOLUMNS		2
#define DISPID_HexCtrl_FILENAME				3
#define DISPID_HexCtrl_SHOWTOOLBAR			5

///////////////////////////////////////////////////////////////////////////////////
class HexCtrl;
///////////////////////////////////////////////////////////////////////////////////

typedef 
mol::Control< mol::EditBox, 
				   WS_CHILD|WS_VISIBLE|
				   WS_BORDER, 
				   WS_EX_CLIENTEDGE > 
ToolEdit;

typedef 
mol::Control< mol::EditBox, 
				   WS_CHILD|WS_VISIBLE|
				   WS_BORDER|ES_LOWERCASE, 
				   WS_EX_CLIENTEDGE > 
ToolEditLc;
///////////////////////////////////////////////////////////////////////////////////

typedef 
mol::Control< mol::StaticCtrl,
				   WS_CHILD|WS_VISIBLE,
				   0> 
Label;

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

class HexToolBar : 
	public mol::Control<mol::ToolBar,WS_CHILD|WS_VISIBLE|CCS_NODIVIDER,0>
{
public:

	HexToolBar(HexCtrl* wnd);
	~HexToolBar();

	void enable(bool b);
	void setValue( const std::wstring& address, const std::wstring& val );

	LRESULT virtual wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:

	HWND createWindow(  const std::wstring& wndName, HMENU hMenu, const mol::Rect& r, HWND parent );

	void setByteValue( ToolEditLc& edit, const std::wstring& byte );
	void setCharValue( ToolEdit& edit, const std::wstring& byte );

	HexCtrl*	hexCtrl_;
	bool		updating_;
	ToolEditLc	offsetEdit_;
	ToolEditLc	hexEdit_;
	ToolEditLc	byteEdit1_;
	ToolEditLc	byteEdit2_;
	ToolEditLc	byteEdit3_;
	ToolEditLc	byteEdit4_;
	ToolEdit	charEdit1_;
	ToolEdit	charEdit2_;
	ToolEdit	charEdit3_;
	ToolEdit	charEdit4_;
	Label		offsetLabel1_;
	Label		offsetLabel2_;
	Label		offsetLabel3_;
	Label		offsetLabel4_;
};

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////


class HexWnd : 
	public mol::Frame< HexWnd,
							mol::ScrollWnd,
							WS_HSCROLL|WS_VSCROLL|
							WS_CHILD|WS_VISIBLE|
							WS_CLIPSIBLINGS|WS_CLIPCHILDREN,
							WS_EX_CLIENTEDGE>
{
public:

	HexWnd(HexCtrl* wnd);
	~HexWnd();

	// load file, get filename
	bool load(const std::wstring& filename, bool readOnly);
	const std::wstring& getFilename();

	// set view columns, get fileinfo
	void setCols(unsigned int c);
	unsigned int getCols();
	unsigned int getFileSize();
	bool getReadOnly();

	// update current offset, get offset and get offset value as string
	void updateOffset();
	unsigned int getOffset();
	std::wstring value(unsigned int index);

	// set current offset value, as hex string (4bytes), as 
	// byte string (1byte) or as char (1byte)
	void setOffsetValue( const std::wstring& val);
	void setByteOffsetValue( const std::wstring& val, int off, bool hex);
	void setCharOffsetValue( const char& c, int off);

	// scroll to offset, given as hex string (4bytes) or unsigned int
	void scrollTo(const std::wstring& off);
	void scrollTo(unsigned int off,bool adjust=true);

	// search support
	size_t getSearchPos();
	void setSearchPos(unsigned int p);
	bool search(const std::wstring& txt, DWORD flags = FR_DOWN);

	// window messages
    LRESULT virtual wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:

	// track scroll events
	void onHScroll(unsigned int pos);
	void onVScroll(unsigned int pos);

	// search upwards
	bool searchUp(const std::wstring& txt, int flags);

	// set and update offset 
	void updateOffset(unsigned int offset);

	// set new offset after mouse click
	void setOffsetByMousePos(unsigned int mx, unsigned int my);

	// draw offset helper
	void drawOffset(mol::win::DCbase& dc, unsigned int off, bool erase = false);

	// parent back pointer
	HexCtrl*			hexCtrl_;

	//behaviour
	bool				readOnly_;
	bool				showToolBar_;

	// file and file mapping info
	std::wstring			filename_;
	mol::FileMapping	map_;
	unsigned int		fsize_;
	unsigned int		offset_;

	// current value as hex string (4 bytes)
	std::wstring			currentOffsetValue_;

	// caret and search position info
	unsigned int		caretX_;
	unsigned int		caretY_;
	size_t		searchPos_;

	// layout info
	unsigned int		cols_;
	unsigned int		ttwidth_;
	unsigned int		ttheight_;
	
	// GDI references
	COLORREF			col_;
	HBRUSH				br_;
};


class HexCtrl: 
	public ax_ctrl<HexCtrl,CLSID_HexCtrl,false,mol::Window,WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,0>,
	public Dispatch<IHexCtrl>,
	public ctrl_events<HexCtrl,_IHexCtrlEvents>,
	public ProvideClassInfo2<HexCtrl,DIID__IHexCtrlEvents>,
	public interfaces< HexCtrl, 
			 implements<
				IDispatch,
				IHexCtrl,
				IOleObject,
				IDataObject,
				interface_ex<IPersist,IPersistStreamInit>,
				interface_ex<IPersistStream,IPersistStreamInit>,
				IPersistStreamInit,
				IPersistStorage,
				IPersistPropertyBag,
				IRunnableObject,
				IViewObject,
				IViewObject2,
				interface_ex<IOleWindow,IOleInPlaceObjectWindowless>,
				interface_ex<IOleInPlaceObject,IOleInPlaceObjectWindowless>,
				IOleControl,
				IConnectionPointContainer,
				IProvideClassInfo,
				IProvideClassInfo2>
		>
{
friend class HexWnd;
friend class HexToolBar;
public:
    HexCtrl();
	virtual ~HexCtrl();

	// COM properties

	HRESULT virtual __stdcall get_ReadOnly	( VARIANT_BOOL* vb );
	HRESULT virtual __stdcall put_ReadOnly	( VARIANT_BOOL vb  );

	HRESULT virtual __stdcall get_DisplayColumns( long* c );
	HRESULT virtual __stdcall put_DisplayColumns( long  c );

	HRESULT virtual __stdcall get_Filename		( BSTR* fn );
	HRESULT virtual __stdcall put_Filename		( BSTR  fn );

	HRESULT virtual __stdcall get_HasFocus	( VARIANT_BOOL* vb );

	HRESULT virtual __stdcall get_ShowToolbar	( VARIANT_BOOL* vb );
	HRESULT virtual __stdcall put_ShowToolbar	( VARIANT_BOOL vb  );

	HRESULT virtual __stdcall get_ScrollPos	( long* p );
	HRESULT virtual __stdcall put_ScrollPos	( long  p );

	HRESULT virtual __stdcall get_ScrollMax	( long* p );

	HRESULT virtual __stdcall get_Offset( long* o );
	HRESULT virtual __stdcall put_Offset( long  o );

	HRESULT virtual __stdcall get_FileSize( long* s );

	HRESULT virtual __stdcall get_SearchPos( long* o );
	HRESULT virtual __stdcall put_SearchPos( long  o );

// COM methods

	HRESULT virtual __stdcall Open( BSTR file, VARIANT_BOOL* vbSuccess);
	HRESULT virtual __stdcall OpenReadOnly( BSTR file, VARIANT_BOOL* vbSuccess );
	HRESULT virtual __stdcall SetOffsetDWORD( long offset, BSTR val );
	HRESULT virtual __stdcall SetOffsetByte( long offset, BSTR val );
	HRESULT virtual __stdcall SetOffsetChar( long offset, long val );
	HRESULT virtual __stdcall Search( BSTR what, long flags);
	HRESULT virtual __stdcall Value( long off, BSTR* value);

	HRESULT virtual __stdcall Load( LPSTREAM pStm);
	HRESULT virtual __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);

	HRESULT virtual __stdcall Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog);
	HRESULT virtual __stdcall Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties);

	virtual HRESULT OnDraw( HDC hdcDraw, LPCRECTL lprcBounds, LPCRECTL lprcMFBounds);

	virtual void initAmbientProperties( IDispatch* disp)
	{}

protected:

	msg_handler( WM_CREATE, OnCreate )
		LRESULT virtual OnCreate( UINT, WPARAM, LPARAM );

	RECT					clientRect_;

	HexWnd					hex_;
	HexToolBar				toolBar_;
	VARIANT_BOOL			vbReadOnly_;
	VARIANT_BOOL			vbShowToolBar_;
};



#endif
