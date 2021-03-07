#ifndef MOL_DEF_SETTING_VIEW_DEF_GUARDING_
#define MOL_DEF_SETTING_VIEW_DEF_GUARDING_

#include "ole/aut.h"
#include "ole/factory.h"
#include "ole/bstr.h"
#include "ole/dll.h"
#include "ole/factory.h"
#include "win/file.h"

#include "io_h.h"

#include "resource.h"

///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


class PathObj : 
	public mol::com_registerobj<
		PathObj,
		CLSID_Path, 
		CLSCTX_INPROC_SERVER, 
		mol::PROGRAMMABLE | mol::APARTMENT| mol::CAN_ELEVATE| mol::DLL_SURROGATE>,
	public mol::Dispatch<IPath>,
	public mol::interfaces< PathObj,
			mol::implements<
				IPath,
				IDispatch > >
{
public:

	HRESULT __stdcall Extension( BSTR f,  BSTR* ret);
	HRESULT __stdcall Filename( BSTR f, BSTR* ret);
	HRESULT __stdcall Path( BSTR f,  BSTR* ret);
	HRESULT __stdcall StripRoot( BSTR f,  BSTR* ret);
	HRESULT __stdcall Root( BSTR f,  BSTR* ret);
	HRESULT __stdcall AddBackSlash( BSTR f,  BSTR* ret);
	HRESULT __stdcall RemoveBackSlash( BSTR f,  BSTR* ret);
	HRESULT __stdcall AddExtension( BSTR f,  BSTR e,  BSTR* ret);
	HRESULT __stdcall IsSubPath( BSTR p1,  BSTR p2,  VARIANT_BOOL* ret);
	HRESULT __stdcall Exists( BSTR f,  VARIANT_BOOL* ret);
	HRESULT __stdcall IsDir( BSTR f,  VARIANT_BOOL* ret);
	HRESULT __stdcall IsRoot( BSTR f,  VARIANT_BOOL* ret);
	HRESULT __stdcall IsUNC( BSTR f,  VARIANT_BOOL* ret);
	HRESULT __stdcall IsNetDrive( BSTR f,  VARIANT_BOOL* ret);
	HRESULT __stdcall ParentDir( BSTR f,  BSTR* ret);
	HRESULT __stdcall OpenDir( BSTR f,  IDir** ret);
	HRESULT __stdcall OpenFile( BSTR f,  IFile** ret);
	HRESULT __stdcall ChooseDir( BSTR* ret);
	HRESULT __stdcall FileOpenDlg( BSTR* ret);
	HRESULT __stdcall FileSaveDlg( BSTR* ret);
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////




#endif