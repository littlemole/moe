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
		return v;

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
//////////////////////////////////////////////////////////////////////////////////


ShellDataObj::ShellDataObj( std::vector<mol::string>& v ,bool cut)
: v_(v), cut_(cut)
{
}

ShellDataObj::ShellDataObj(  HWND hwnd, int cmd, std::vector<mol::string>& v ,bool cut)
: v_(v), cut_(cut)
{
    dropEffectEvent_.subscribe(hwnd, cmd);
}



//////////////////////////////////////////////////////////////////////////////////

ShellDataObj::~ShellDataObj()
{
	ODBGS("destroyed ShellDataObject::~DataObject");
}

//////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellDataObj::GetData( FORMATETC * pFormatetc, STGMEDIUM * pmedium )
{
	ODBGS("ShellDataObject::GetData");
	if ( !pFormatetc || !pmedium )
		return E_INVALIDARG;

	if ( pFormatetc->cfFormat == fepDe_.format() )
	{
		ODBGS("ShellDataObject::GetData FormatEtcPrefDropEffect");

		mol::global glob;
		glob.alloc(sizeof(DWORD*),GHND | GMEM_SHARE);
		if ( cut_)
			mol::global::set<DWORD>(glob,DROPEFFECT_MOVE);
		else
			mol::global::set<DWORD>(glob,DROPEFFECT_COPY);

		pmedium->hGlobal = glob;
		pmedium->tymed = TYMED_HGLOBAL;
		pmedium->pUnkForRelease = NULL;

		glob.detach();
		return S_OK;
	}

	if ( pFormatetc->cfFormat == CF_TEXT )
	{
		ODBGS("ShellDataObject::GetData CF_TEXT");

		std::string s;
		for ( unsigned int i = 0; i < v_.size(); i++ )
		{
			s += mol::tostring(v_[i]);
			s += "\r\n";
		}
		mol::global glob;
		glob.alloc( (int)(s.size()+1),GHND | GMEM_SHARE);
		char* c = glob.lock();
		memcpy(c,s.c_str(),(s.size()+1)*sizeof(char));
		glob.unLock();

		pmedium->hGlobal		= glob;
		pmedium->tymed			= TYMED_HGLOBAL;
		pmedium->pUnkForRelease = NULL;

		glob.detach();
		return S_OK;
	}

	if ( pFormatetc->cfFormat == CF_UNICODETEXT )
	{
		ODBGS("ShellDataObject::GetData CF_UNICODETEXT");

		std::wstring s;
		for ( unsigned int i = 0; i < v_.size(); i++ )
		{
			s += mol::towstring(v_[i]);
			s += L"\r\n";
		}
		mol::global glob;
		glob.alloc( (int)(s.size()+1) * sizeof(wchar_t),GHND | GMEM_SHARE);
		char* c = glob.lock();
		memcpy(c,s.c_str(),(s.size()+1)*sizeof(wchar_t));
		glob.unLock();

		pmedium->hGlobal		= glob;
		pmedium->tymed			= TYMED_HGLOBAL;
		pmedium->pUnkForRelease = NULL;

		glob.detach();
		return S_OK;
	}
	if ( pFormatetc->cfFormat == CF_HDROP )
	{
		ODBGS("ShellDataObject::GetData CF_HDROP");

		std::string s;
		int c = 0;
		for ( unsigned int i = 0; i < v_.size(); i++ )
		{
			s += mol::tostring(v_[i]);
			s += '\0';
			c += (int)s.size()+1;
		}

		mol::global glob;
		glob.alloc(c+1+sizeof(DROPFILES),GHND | GMEM_SHARE);
		DROPFILES* drop = (DROPFILES*)glob.lock();
		drop->pFiles = sizeof(DROPFILES);
		drop->fWide = FALSE;
		memcpy( ((char*)drop+sizeof(DROPFILES)), s.c_str(), c+1);
		glob.unLock();

		pmedium->hGlobal = glob;
		pmedium->tymed = TYMED_HGLOBAL;
		pmedium->pUnkForRelease = NULL;

		glob.detach();
		return S_OK;
	}
	return DV_E_FORMATETC ;
}

//////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellDataObj::QueryGetData( FORMATETC * pFormatetc )
{
	ODBGS("ShellDataObject::QueryGetData");

	if ( !pFormatetc )
		return E_INVALIDARG;

	if ( pFormatetc->cfFormat == CF_TEXT )
		return NO_ERROR;
	if ( pFormatetc->cfFormat == CF_UNICODETEXT )
		return NO_ERROR;
	if ( pFormatetc->cfFormat == CF_HDROP )
		return NO_ERROR;
	if ( pFormatetc->cfFormat  == feDe_.format() )
		return NO_ERROR;
	if ( pFormatetc->cfFormat  == fepDe_.format() )
		return NO_ERROR;

	return S_FALSE;
}

//////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellDataObj::EnumFormatEtc(  DWORD dwDirection,  IEnumFORMATETC ** ppenumFormatetc )
{
	ODBGS("ShellDataObject::EnumFormatEtc");

	com_obj<enum_format>* efi = new com_obj<enum_format>;

	efi->add(feDrop_);
	efi->add(fepDe_);
	efi->add(feText_);
	efi->add(feUnicodeText_);
	efi->add(fepDe_);

	efi->QueryInterface(IID_IEnumFORMATETC,(void**)ppenumFormatetc);
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall ShellDataObj::SetData(  FORMATETC * pFormatetc,  STGMEDIUM * pmedium,  BOOL fRelease )
{
	ODBGS("ShellDataObject::SetData");

	if ( pFormatetc->cfFormat  == feDe_.format() )
	{
        dropEffectEvent_.fire((LPARAM)this);
		//return S_OK;
	}
	if ( fRelease )
		::ReleaseStgMedium(pmedium);
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////


} // end namespace mol
