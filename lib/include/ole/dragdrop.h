#ifndef MOL_DRAG_DROP_DEF_GUARD_DEFINE_
#define MOL_DRAG_DROP_DEF_GUARD_DEFINE_

#include "util/uni.h"
#include "ole/dataobj.h"
#include "win/wnd.h"
#include <vector>

namespace mol {
namespace ole {

//////////////////////////////////////////////////////////////////////////////////

class DropTargetBase  : 
	public IDropTarget,
	public interfaces< DropTargetBase, implements<IDropTarget> >
{
public:
    virtual ~DropTargetBase() 
	{  }

	virtual void dispose() {}

    HRESULT virtual __stdcall DragEnter( IDataObject*, DWORD, POINTL, DWORD* );
    HRESULT virtual __stdcall DragOver( DWORD, POINTL, DWORD* );
    HRESULT virtual __stdcall DragLeave();
    HRESULT virtual __stdcall Drop( IDataObject* , DWORD, POINTL, DWORD* );
};

} // end namespace ole

typedef com_obj<mol::ole::DropTargetBase> DropTarget;

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

namespace ole {

class DropSrcBase : 
	public IDropSource,
	public interfaces< DropSrcBase, implements< IDropSource> >
{
public:
    virtual ~DropSrcBase() {  }
	
	virtual void dispose() {}

	HRESULT virtual __stdcall QueryContinueDrag(   BOOL fEscapePressed,  DWORD grfKeyState );
	HRESULT virtual __stdcall GiveFeedback( DWORD dwEffect );
};

} // end namespace mol::ole

typedef com_obj<mol::ole::DropSrcBase> DropSrc;

//////////////////////////////////////////////////////////////////////////////////


} // end namespace mol

#endif