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
						mol::AxClientWnd<MoeTreeWnd,RTree>,
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

	HWND createWindow( const std::wstring& windowName, HMENU id, const mol::Rect& r, HWND parent );

	bool hasFocus()  ;

};



#endif