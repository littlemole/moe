#ifndef MOL_LIB_DATAOBJ_DEF_GUARD_DEFINE_
#define MOL_LIB_DATAOBJ_DEF_GUARD_DEFINE_

#include "util/uni.h"
#include "win/Wnd.h"
#include "ole/obj.h"
#include "ole/punk.h"
#include "ole/storage.h"
#include <vector>

namespace mol {

//////////////////////////////////////////////////////////////////////////////////
// Data Object 
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////

std::vector<mol::string> vectorFromDataObject(IDataObject* ido);

namespace ole {

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
// IDataObject
/////////////////////////////////////////////////////////////////////

class DataObjBase : 
	public IDataObject
{
public:
	DataObjBase() {};
	virtual ~DataObjBase() {};

	virtual void dispose() {}

    HRESULT virtual __stdcall GetData( FORMATETC * pFormatetc, STGMEDIUM * pmedium );
	HRESULT virtual __stdcall GetDataHere( FORMATETC * pFormatetc, STGMEDIUM * pmedium  );
	HRESULT virtual __stdcall QueryGetData( FORMATETC * pFormatetc );
	HRESULT virtual __stdcall GetCanonicalFormatEtc( FORMATETC * pFormatetcIn, FORMATETC * pFormatetcOut );
	HRESULT virtual __stdcall SetData(  FORMATETC * pFormatetc,  STGMEDIUM * pmedium,  BOOL fRelease );
	HRESULT virtual __stdcall EnumFormatEtc(  DWORD dwDirection,  IEnumFORMATETC ** ppenumFormatetc );
	HRESULT virtual __stdcall DAdvise( FORMATETC * pFormatetc,  DWORD advf, IAdviseSink * pAdvSink, DWORD * pdwConnection );
	HRESULT virtual __stdcall DUnadvise( DWORD dwConnection );
	HRESULT virtual __stdcall EnumDAdvise( IEnumSTATDATA ** ppenumAdvise );
};

} // end namespace mol

// for standalone usage, provide QI implementation
class DataObj : 
	public mol::ole::DataObjBase,
	public interfaces< DataObj, implements<IDataObject> >
{
public:
	DataObj() {};
	virtual ~DataObj() {};
};

//////////////////////////////////////////////////////////////////////////////////
// Shell integration capable DataObj
//////////////////////////////////////////////////////////////////////////////////

class ShellDataObj : public com_obj<DataObj>
{
public:
	ShellDataObj( std::vector<mol::string>& v, bool cut = false );
    ShellDataObj( HWND hwnd, int cmd, std::vector<mol::string>& v, bool cut = false );
	virtual ~ShellDataObj();

	HRESULT virtual __stdcall GetData( FORMATETC * pFormatetc, STGMEDIUM * pmedium );
	HRESULT virtual __stdcall QueryGetData( FORMATETC * pFormatetc );
	HRESULT virtual __stdcall EnumFormatEtc(  DWORD dwDirection,  IEnumFORMATETC ** ppenumFormatetc );
	HRESULT virtual __stdcall SetData(  FORMATETC * pFormatetc,  STGMEDIUM * pmedium,  BOOL fRelease );

protected:

	std::vector<mol::string>		v_;
	bool							cut_;

	format_etc_text					feText_;
	format_etc_unicodetext			feUnicodeText_;
	format_etc_dropfile				feDrop_;
	format_etc_dropeffect			feDe_;
	format_etc_pref_dropeffect		fepDe_;

	mol::sendcmd_pubsub		        dropEffectEvent_;
};

//////////////////////////////////////////////////////////////////////////////////
// General DataTransferObject 
//////////////////////////////////////////////////////////////////////////////////

class DataTransferObj: public com_obj<DataObj>
{
public:
	DataTransferObj(bool cut = false);
	DataTransferObj(HWND hwnd, int cmd, bool cut = false);
    virtual ~DataTransferObj();

	void addData( CLIPFORMAT format, const mol::string & data ); 
	void addData( CLIPFORMAT format, void* vv, int size );
/*	template<class T>
	void addData( CLIPFORMAT format, T& t )
	{
		format_etc fe( format, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL );
		StgMedium sm(t);
		SetData(  &fe,  &sm,  false );
	}
*/
	HRESULT virtual __stdcall GetData( FORMATETC * pFormatetc, STGMEDIUM * pmedium );
	HRESULT virtual __stdcall QueryGetData( FORMATETC * pFormatetc );
	HRESULT virtual __stdcall EnumFormatEtc(  DWORD dwDirection,  IEnumFORMATETC ** ppenumFormatetc );
	HRESULT virtual __stdcall SetData(  FORMATETC * pFormatetc,  STGMEDIUM * pmedium,  BOOL fRelease );

protected:

	std::map<CLIPFORMAT,HGLOBAL>		v_;
	bool								cut_;

	mol::sendcmd_pubsub					dropEffectEvent_;
	format_etc_dropeffect				feDe_;
};


} // end namespace mol

#endif