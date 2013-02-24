#ifndef MOE_TREE_DEF_GUARD_
#define MOE_TREE_DEF_GUARD_

#include "commons.h"

/////////////////////////////////////////////////////////////////////////////////////////////
// the resizable directory tree widget
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
// resizer
/////////////////////////////////////////////////////////////////////////////////////////////

typedef mol::CtrlResizer< 
						mol::Window , 
                        100,0,
						mol::win::CtrlResizerImpl::RIGHT> 
RTree;


/////////////////////////////////////////////////////////////////////
// TreeWnd
/////////////////////////////////////////////////////////////////////

class MoeTreeWnd : 
	public mol::Frame< 
					MoeTreeWnd,
						mol::AxClientWnd<
								MoeTreeWnd,
								RTree>, //,
								//&CLSID_ShellTree> , 
								//&CLSID_NamespaceTree> , 
					    WS_CHILD|WS_VISIBLE|WS_CLIPSIBLINGS|
					    WS_CLIPCHILDREN|WS_THICKFRAME,
					    WS_EX_STATICEDGE >
{
public:

	~MoeTreeWnd();

	void OnTreeOpen();
	void OnTreeUpdate();

	void OnTreeRename();
	void OnTreeDelete();

	void OnTreeExecute();
	void OnTreeProperties();
	void OnTreeNewDir();

	void OnEditCut();
	void OnEditCopy();
	void OnEditPaste();

	HWND createWindow( const mol::string& windowName, HMENU id, const mol::Rect& r, HWND parent );

	bool hasFocus()  ;
};

/////////////////////////////////////////////////////////////////////
// tree events sink
/////////////////////////////////////////////////////////////////////

class TreeWndSink : public mol::stack_obj<ShellTreeEvents>
{
friend mol::Singleton<TreeWndSink>; 
friend mol::stack_obj<TreeWndSink>;
public :
	HRESULT virtual __stdcall OnTreeSelection(BSTR filename);
	HRESULT virtual __stdcall OnTreeDblClick(BSTR filename,VARIANT_BOOL vb);
	HRESULT virtual __stdcall OnTreeOpen(BSTR filename,VARIANT_BOOL vb); 
	HRESULT virtual __stdcall OnContextMenu(BSTR filename,VARIANT_BOOL vb); 
private:
	TreeWndSink() {}
	~TreeWndSink() {}
};


#endif