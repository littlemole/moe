#include "ole/ole.h"
#include "ole/dataobj.h"
#include "ole/storage.h"
#include "ole/enum.h"

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
    dropEffectEvent_.subscribe(hwnd, cmd);
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


void DataTransferObj::addData( CLIPFORMAT format, const mol::string & data )
{
	format_etc fe( format, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL );
	StgMedium sm((mol::string &)data);
	SetData(  &fe,  &sm,  false );
}

void DataTransferObj::addData( CLIPFORMAT format, void* v, int size )
{
	format_etc fe( format, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL );
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
        dropEffectEvent_.fire((LPARAM)this);

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


} // end namespace mol