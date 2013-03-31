#ifndef MOE_REBAR_DEF_GUARD_
#define MOE_REBAR_DEF_GUARD_

#include "widgets.h"

/////////////////////////////////////////////////////////////////////////////////////////////
// widgets for moe
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
// the document selector tab control
/////////////////////////////////////////////////////////////////////////////////////////////

class  MoeTabControl : public mol::Control< 
									mol::TabCtrl, 
									WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|TCS_BOTTOM|TCS_TOOLTIPS,
									0  > 
{
friend class Docs;
public:

	//typedef mol::TabCtrl BaseWindowType;

	MoeTabControl();
	virtual ~MoeTabControl();

	void select( HWND d );
	
	// msg handlers
	void OnSelect();
	void OnRightClick();

	void OnMouseDown();
	void OnMouseUp();

	void OnTimer(int id,int unused);
	void OnGetObject(NMOBJECTNOTIFY* notify);

private:

	virtual void OnCtrlCreated();

	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	int  index ( HWND d );
	void remove( HWND d );
	void move  ( HWND what, HWND to );
	void rename( HWND d,const mol::string& newpath, const mol::string& name );

	
	// Drag&Drop COM Callback
	class MoeTabControl_Drop : public mol::stack_obj<mol::ole::DropTargetBase>
    {
        public : 
			HRESULT virtual __stdcall Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect);
			HRESULT virtual __stdcall DragEnter( IDataObject*, DWORD, POINTL, DWORD* );
			HRESULT virtual __stdcall DragOver( DWORD, POINTL, DWORD* );
			HRESULT virtual __stdcall DragLeave();
    } Drop;


	bool				isMouseDown_;
	CLIPFORMAT			dragTabFormat_;
};


/////////////////////////////////////////////////////////////////////////////////////////////
// customizable toolbar
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeToolBar : public mol::Control< mol::CustomToolBar,
					  WS_CHILD|CCS_NORESIZE |CCS_NOPARENTALIGN|
					  CCS_NODIVIDER|TBSTYLE_FLAT|
					  WS_CLIPCHILDREN|TBSTYLE_TOOLTIPS|CCS_ADJUSTABLE ,
					  TBSTYLE_EX_MIXEDBUTTONS  >
{
public:

//	typedef mol::CustomToolBar BaseWindowType;

	// msg handler
	void OnRightClick(NMHDR* notify);

    LRESULT virtual wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)		
    {																					
            return mol::msgMap<MoeToolBar>().call(this,message,wParam,lParam);							
    }	
};

/////////////////////////////////////////////////////////////////////////////////////////////
// the syntax selector cobox control
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeComboBox : public mol::Control< mol::ComboBox, 
					  WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|
					  CBS_DROPDOWNLIST |CBS_HASSTRINGS,
					  0 > 
{};

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


/////////////////////////////////////////////////////////////////////////////////////////////




#endif
