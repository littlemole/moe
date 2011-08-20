#include "ole/dragdrop.h"
#include "ole/enum.h"
#include "win/shell.h"
#include "ole/storage.h"
#include "util/str.h"

namespace mol {

//////////////////////////////////////////////////////////////////////////////
//
// get vector of strings from dataobject
//
//////////////////////////////////////////////////////////////////////////////

UINT CF_SHELLIDLIST = ::RegisterClipboardFormat(CFSTR_SHELLIDLIST);

struct format_etc_shellpidl : public format_etc
{
	format_etc_shellpidl() : format_etc( CF_SHELLIDLIST, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL ) 	{}
};

#define molGetPIDLFolder(pida) (LPCITEMIDLIST)(((LPBYTE)pida)+(pida)->aoffset[0])
#define molGetPIDLItem(pida, i) (LPCITEMIDLIST)(((LPBYTE)pida)+(pida)->aoffset[i+1])


std::vector<mol::string> vectorFromDataObject(IDataObject* ido)
{
	ODBGS("vectorFromDataObject");

	format_etc_dropfile			fe;
	STGMEDIUM					sm;
	mol::TCHAR*					fname  = 0;
	int							len		= 0;
	int							n		= 0;
	
	std::vector<mol::string>	v;

	if (!ido)
		return v;
	
	if ( S_OK != ido->GetData( &fe, &sm ) )
	{
		format_etc_shellpidl spidl;
		if ( S_OK != ido->GetData( &spidl, &sm ) )
		  return v;

		CIDA* cida = 0;
		mol::global glob(sm.hGlobal);
		cida = (CIDA*)glob.lock();

		LPCITEMIDLIST folder = molGetPIDLFolder(cida);		
		mol::io::ShellFolder sf( (LPITEMIDLIST)folder);
		mol::string parent = mol::io::desktop().getDisplayNameOf((LPITEMIDLIST)folder);
		if ( sf )
		{
			int n = cida->cidl;
			for ( int i = 0; i < n; i++ )
			{
				LPCITEMIDLIST item = molGetPIDLItem(cida,i);
				mol::string s = mol::io::desktop().getDisplayNameOf((LPITEMIDLIST)item,SHGDN_FORPARSING);
				//mol::io::ShellFolder  f = sf.subFolder((LPITEMIDLIST)item);
				//mol::io::ShellFolder f((LPITEMIDLIST)item);
				
				mol::string s2 = sf.getDisplayNameOf((LPITEMIDLIST)item,SHGDN_INFOLDER);
				mol::string s3 = sf.getDisplayNameOf((LPITEMIDLIST)item,SHGDN_FORPARSING);
				v.push_back(s3);
			}
		}
		return v;
	}

	if ( sm.tymed != TYMED_HGLOBAL )
		return v;

	mol::global glob(sm.hGlobal);
	HDROP hDrop = (HDROP) glob.lock();
	if ( hDrop )
	{
		n   = ::DragQueryFile( hDrop, 0xFFFFFFFF,0,0);
		int i = 0;
		while(true)
		{
			len = ::DragQueryFile( hDrop, i, 0, 0 );
			if (!len )
				break;
			fname = new mol::TCHAR[len+1];
			::DragQueryFile( hDrop, i, fname, len+1 );
			v.push_back(fname);
			delete[] fname;
			i++;
		}
		glob.unLock();
	}
	glob.detach();
	::ReleaseStgMedium(&sm);
	return v;
}

namespace ole {


//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

HRESULT  __stdcall DropTargetBase::DragEnter( IDataObject* , DWORD , POINTL , DWORD* pEffect )
{
    ODBGS("DropTargetImpl::DragEnter");
    *pEffect = DROPEFFECT_COPY;
    return S_OK;
}

//////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DropTargetBase::DragOver( DWORD, POINTL, DWORD* pEffect )
{
    //ODBGS("DropTargetImpl::DragOver");
    *pEffect = DROPEFFECT_COPY;
    return S_OK;
}

//////////////////////////////////////////////////////////////////////////////////

HRESULT  __stdcall DropTargetBase::DragLeave()
{
    ODBGS("DropTargetImpl::DragLeave");
    return S_OK;
}

//////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DropTargetBase::Drop( IDataObject* , DWORD , POINTL  , DWORD* )
{
	ODBGS("DropTargetImpl::Drop - empty base stub called ?");
    return S_OK;
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DropSrcBase::QueryContinueDrag( BOOL fEscapePressed,  DWORD grfKeyState )
{
	//ODBGS("DropSourceImpl::QueryContinueDrag");
	if ( fEscapePressed )
		return DRAGDROP_S_CANCEL;
	if ( !(grfKeyState & MK_LBUTTON) )
		return DRAGDROP_S_DROP;
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DropSrcBase::GiveFeedback( DWORD dwEffect )
{
	//ODBGS("DropSourceImpl::GiveFeedback");
	return DRAGDROP_S_USEDEFAULTCURSORS ;
}

} // end namespace ole
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

UINT format_etc_dropeffect::format()
{
	static UINT ui = ::RegisterClipboardFormat(CFSTR_PERFORMEDDROPEFFECT);
	return ui;
}

//////////////////////////////////////////////////////////////////////////////////

UINT format_etc_pref_dropeffect::format()
{
	static UINT ui = ::RegisterClipboardFormat(CFSTR_PREFERREDDROPEFFECT);
	return ui;
}


//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////


} // end namespace mol
