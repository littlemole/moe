#ifndef MOE_REBAR_DEF_GUARD_
#define MOE_REBAR_DEF_GUARD_

#include "win/res.h"
#include "win/wnd.h"
#include "shared.h"
#include "widgets.h"

/////////////////////////////////////////////////////////////////////////////////////////////
// widgets for moe
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
// customizable toolbar
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeToolBar : public mol::Control< mol::CustomToolBar,
					  WS_CHILD|CCS_NORESIZE |CCS_NOPARENTALIGN|
					  CCS_NODIVIDER|TBSTYLE_FLAT|
					  WS_CLIPCHILDREN|TBSTYLE_TOOLTIPS|CCS_ADJUSTABLE ,
					  TBSTYLE_EX_MIXEDBUTTONS  >
{};

/////////////////////////////////////////////////////////////////////////////////////////////
// the document selector tab control
/////////////////////////////////////////////////////////////////////////////////////////////

class  MoeTabControl : public mol::Control< mol::TabCtrl, 
						WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|
					  //TCS_FLATBUTTONS|
					  //TCS_BUTTONS|
					  TCS_BOTTOM|
					  TCS_TOOLTIPS,
					  0  > 
{
friend class Docs;
public:

	MoeTabControl();
	virtual ~MoeTabControl();

	void select( const mol::string& path );

private:

	virtual void OnCtrlCreated();

	int  index ( const mol::string& path );
	void remove( const mol::string& path );
	void move  ( const mol::string& what, const mol::string& to );
	void rename( const mol::string& oldpath,const mol::string& newpath, const mol::string& name );

	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);



	bool				isMouseDown_;
	CLIPFORMAT			dragTabFormat_;
	
	// Drag&Drop COM Callback
	class MoeTabControl_Drop : public mol::stack_obj<mol::ole::DropTargetBase>
    {
        public : 
			HRESULT virtual __stdcall Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect);
			HRESULT virtual __stdcall DragEnter( IDataObject*, DWORD, POINTL, DWORD* );
			HRESULT virtual __stdcall DragOver( DWORD, POINTL, DWORD* );
			HRESULT virtual __stdcall DragLeave();
    } Drop;
};

/////////////////////////////////////////////////////////////////////////////////////////////
// the syntax selector cobox control
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeComboBox : public mol::Control< mol::ComboBox, 
					  WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|
					  CBS_DROPDOWNLIST |CBS_HASSTRINGS,
					  0 > 
{};

 
class CLIControl : public mol::Control<mol::ReditBox<IDM_CLI_RETURN>,WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|WS_BORDER,WS_EX_CLIENTEDGE>
{
public:
	CLIControl();
	~CLIControl();

private:

};


class  MoeTaskbarControl : public mol::ChildFrame<MoeTaskbarControl,mol::Window>
{
public:
	
};


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// the moe rebar
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeBar : public mol::Control< 
						mol::ReBar,
						/*WS_BORDER|*/WS_CHILD|WS_VISIBLE|
						WS_CLIPCHILDREN|WS_CLIPSIBLINGS|CCS_NODIVIDER|
						RBS_BANDBORDERS|/*RBS_VARHEIGHT|CCS_NOPARENTALIGN|*/
						RBS_REGISTERDROP,
						WS_EX_TOOLWINDOW/*|WS_EX_CLIENTEDGE*/ >
{
friend class MoeWnd;
public:
	MoeBar()
	{}

	~MoeBar();

    virtual HRESULT __stdcall Load( LPSTREAM pStm);
    virtual HRESULT __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);

	LRESULT wndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

};

class MoeCLIBar : public mol::Control< 
						mol::ReBar,
						/*WS_BORDER|*/WS_CHILD|WS_VISIBLE|
						WS_CLIPCHILDREN|WS_CLIPSIBLINGS|CCS_NODIVIDER|
						RBS_BANDBORDERS|/*RBS_VARHEIGHT|CCS_NOPARENTALIGN|*/
						RBS_REGISTERDROP,
						WS_EX_TOOLWINDOW/*|WS_EX_CLIENTEDGE*/ >
{
friend class MoeWnd;
public:
	MoeCLIBar()
	{}

	~MoeCLIBar();

//    virtual HRESULT __stdcall Load( LPSTREAM pStm);
  //  virtual HRESULT __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);

	LRESULT wndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

};

/////////////////////////////////////////////////////////////////////////////////////////////




#endif
