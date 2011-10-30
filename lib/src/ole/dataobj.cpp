#include "ole/ole.h"
#include "ole/dataobj.h"
#include "ole/storage.h"
#include "ole/enum.h"
#include <ShlObj.h>

namespace mol {
namespace ole {

//////////////////////////////////////////////////////////////////////
// DATAObject
//////////////////////////////////////////////////////////////////////

HRESULT __stdcall DataObjBase::GetData( FORMATETC * pFormatetc, STGMEDIUM * pmedium )
{
	ODBGS("IDataObject::Getdata");
	return E_NOTIMPL;
}

HRESULT __stdcall DataObjBase::GetDataHere( FORMATETC * pFormatetc, STGMEDIUM * pmedium  )
{
	ODBGS("IDataObject::GetdataHere");
	return E_NOTIMPL;
}

HRESULT __stdcall DataObjBase::QueryGetData( FORMATETC * pFormatetc )
{
	ODBGS("IDataObject::QueryGetdata");
	return E_NOTIMPL;
}

HRESULT __stdcall DataObjBase::GetCanonicalFormatEtc( FORMATETC * pFormatetcIn, FORMATETC * pFormatetcOut )
{
	ODBGS("IDataObject::GetCanonicalFormatEtc");
	if ( pFormatetcIn!= NULL )
	{
		pFormatetcOut = NULL;
		return DATA_S_SAMEFORMATETC;
	}
	return S_FALSE;
}

HRESULT __stdcall DataObjBase::SetData(  FORMATETC * pFormatetc,  STGMEDIUM * pmedium,  BOOL fRelease )
{
	ODBGS("IDataObject::SetData");
	if ( fRelease )
		::ReleaseStgMedium(pmedium);
	return E_NOTIMPL;
}

HRESULT __stdcall DataObjBase::EnumFormatEtc(  DWORD dwDirection,  IEnumFORMATETC ** ppenumFormatetc )
{
	ODBGS("IDataObject::EnumFormatEtc");
	return E_NOTIMPL;
}

HRESULT __stdcall DataObjBase::DAdvise( FORMATETC * pFormatetc,  DWORD advf, IAdviseSink * pAdvSink, DWORD * pdwConnection )
{
	ODBGS("IDataObject::DAdvise");
	return OLE_E_ADVISENOTSUPPORTED ;
}

HRESULT __stdcall DataObjBase::DUnadvise( DWORD dwConnection )
{
	ODBGS("IDataObject::DUnadvise");
	return OLE_E_ADVISENOTSUPPORTED;
}

HRESULT __stdcall DataObjBase::EnumDAdvise( IEnumSTATDATA ** ppenumAdvise )
{
	ODBGS("IDataObject::EnumDAdvise");
	return OLE_E_ADVISENOTSUPPORTED;
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

}

DataTransferObj::DataTransferObj(bool cut )
: cut_(cut)
{
}

DataTransferObj::DataTransferObj(  HWND hwnd, int cmd ,bool cut)
:  cut_(cut)
{
    //dropEffectEvent_.subscribe(hwnd, cmd);

}



//////////////////////////////////////////////////////////////////////////////////

DataTransferObj::~DataTransferObj()
{
	ODBGS("destroyed DataTransferObj::~DataTransferObj");
	for ( std::map<CLIPFORMAT,HGLOBAL>::iterator it = v_.begin(); it != v_.end(); it++)
	{
		mol::global glob( (*it).second );
	}
}


void DataTransferObj::addData( CLIPFORMAT format, const mol::string & data, int index  )
{
	format_etc fe( format, NULL, DVASPECT_CONTENT, index, TYMED_HGLOBAL );
	StgMedium sm((mol::string &)data);
	SetData(  &fe,  &sm,  false );
}

void DataTransferObj::addData( CLIPFORMAT format, void* v, size_t size, int index  )
{
	format_etc fe( format, NULL, DVASPECT_CONTENT, index, TYMED_HGLOBAL );
	StgMedium sm(v,size);
	SetData(  &fe,  &sm,  false );
}

//////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DataTransferObj::GetData( FORMATETC * pFormatetc, STGMEDIUM * pmedium )
{
	ODBGS("DataTransferObj::GetData");
	if ( !pFormatetc || !pmedium || ! pFormatetc->tymed == TYMED_HGLOBAL)
		return E_INVALIDARG;

	for ( std::map<CLIPFORMAT,HGLOBAL>::iterator it = v_.begin(); it != v_.end(); it++)
	{
		if ( pFormatetc->cfFormat == (*it).first )
		{
			mol::global glob( (*it).second );

			char* c = glob.lock();
			mol::global copy( (void*)c, (size_t)glob.size() );
			pmedium->hGlobal = copy;
			pmedium->pUnkForRelease = 0;
			pmedium->tymed = TYMED_HGLOBAL;

			glob.unLock();
			glob.detach();
			copy.detach();
			return S_OK;
		}
	}
	//return S_FALSE;
	return DV_E_FORMATETC ;
}

//////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DataTransferObj::QueryGetData( FORMATETC * pFormatetc )
{
	ODBGS("DataTransferObj::QueryGetData");

	if ( !pFormatetc || !(pFormatetc->tymed == TYMED_HGLOBAL))
		return E_INVALIDARG;

	for ( std::map<CLIPFORMAT,HGLOBAL>::iterator it = v_.begin(); it != v_.end(); it++)
	{
		if ( pFormatetc->cfFormat == (*it).first )
			return S_OK;
	}

	return S_FALSE;
}

//////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DataTransferObj::EnumFormatEtc(  DWORD dwDirection,  IEnumFORMATETC ** ppenumFormatetc )
{
	ODBGS("DataTransferObj::EnumFormatEtc");

	com_obj<enum_format>* efi = new com_obj<enum_format>;

	for ( std::map<CLIPFORMAT,HGLOBAL>::iterator it = v_.begin(); it != v_.end(); it++)
	{
		format_etc fe( (*it).first, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL );
		efi->add( fe );
	}

	efi->QueryInterface(IID_IEnumFORMATETC,(void**)ppenumFormatetc);
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DataTransferObj::SetData(  FORMATETC * pFormatetc,  STGMEDIUM * pmedium,  BOOL fRelease )
{
	ODBGS("DataTransferObj::SetData");

	if ( pFormatetc->cfFormat  == feDe_.format() )
	{
       // dropEffectEvent_.fire((LPARAM)this);

		if ( fRelease )
			::ReleaseStgMedium(pmedium);
		return S_OK;
	}

	if ( !pFormatetc || !pmedium || !(pFormatetc->tymed == TYMED_HGLOBAL) ) 
		return E_INVALIDARG;

	if ( v_.count( pFormatetc->cfFormat ) > 0 )
	{
		mol::global glob(v_[pFormatetc->cfFormat]);
		v_.erase( pFormatetc->cfFormat );
	}

	mol::global glob(pmedium->hGlobal);

	char* s = glob.lock();
	mol::TCHAR* ts = (mol::TCHAR*)s;

	size_t len = 0;
	if ( ts != 0 )
		len = _tcslen(ts)+1;

	mol::global copy( (void*)ts,len*sizeof(mol::TCHAR));

	v_.insert( std::make_pair(pFormatetc->cfFormat, (HGLOBAL)copy) );

	glob.unLock();
	glob.detach();
	copy.detach();

	if ( fRelease )
		::ReleaseStgMedium(pmedium);

	return S_OK;
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////


ShellDataObj::ShellDataObj( std::vector<mol::string>& v ,bool cut)
: v_(v), cut_(cut)
{
}

/*
ShellDataObj::ShellDataObj(  HWND hwnd, int cmd, std::vector<mol::string>& v ,bool cut)
: v_(v), cut_(cut)
{
//    dropEffectEvent_.subscribe(hwnd, cmd);
	dropEffectEvent_ += ::event_handler();
}
*/



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
        dropEffectEvent_.fire(this);
		//return S_OK;
	}
	if ( fRelease )
		::ReleaseStgMedium(pmedium);
	return S_OK;
}

} // end namespace mol