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
						mol::AxWnd<
								MoeTreeWnd,
								RTree,
								&CLSID_ShellTree> , 
					    WS_CHILD|WS_VISIBLE|WS_CLIPSIBLINGS|
					    WS_CLIPCHILDREN|WS_THICKFRAME,
					    WS_EX_STATICEDGE >
{
public:

	~MoeTreeWnd();

	//msg_handler(WM_CREATE,OnCreate)
	//LRESULT OnCreate();

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
	HRESULT virtual __stdcall OnTreeDblClick(BSTR filename);
	HRESULT virtual __stdcall OnTreeOpen(BSTR filename); 
	HRESULT virtual __stdcall OnContextMenu(BSTR filename); 
private:
	TreeWndSink() {}
	~TreeWndSink() {}
};


#endif