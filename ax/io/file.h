#ifndef MOL_DEF_FILE_IO_DEF_GUARDING_
#define MOL_DEF_FILE_IO_DEF_GUARDING_

#include "ole/aut.h"
#include "ole/factory.h"
#include "ole/bstr.h"
#include "ole/dll.h"
#include "win/file.h"
#include "win/enc.h"
#include "util/uni.h"
#include "io_h.h"

#include "resource.h"

using namespace mol;

class FileObj : 
	public mol::com_registerobj<FileObj,CLSID_File,CLSCTX_INPROC_SERVER,
						PROGRAMMABLE|APARTMENT|DLL_SURROGATE|CAN_ELEVATE>,
	public mol::Dispatch<IFile>,
	public mol::interfaces< FileObj,
			mol::implements<
				IFile,
				IDispatch > >
{
public:

	FileObj();

	HRESULT __stdcall get_Filename( BSTR* f);

	HRESULT __stdcall put_EoL( long t);
	HRESULT __stdcall get_EoL( long* t);

	HRESULT __stdcall put_Encoding( long cp);
	HRESULT __stdcall get_Encoding( long* cp);

	HRESULT __stdcall put_UseBOM( VARIANT_BOOL cp);
	HRESULT __stdcall get_UseBOM( VARIANT_BOOL* cp);

	HRESULT __stdcall get_EoF( VARIANT_BOOL* vb);

	HRESULT __stdcall get_Size( long* s);

	HRESULT __stdcall Create( BSTR file, VARIANT_BOOL* vb );

	HRESULT __stdcall Open( BSTR file, VARIANT_BOOL* vb );

	HRESULT __stdcall OpenReadOnly( BSTR file, VARIANT_BOOL* vb );

	HRESULT __stdcall OpenAppend( BSTR file, VARIANT_BOOL* vb );

	HRESULT __stdcall Close();

	HRESULT __stdcall Read( long cnt, BSTR* file);

	HRESULT __stdcall ReadText( BSTR* file);

	HRESULT __stdcall Seek( long pos);

	HRESULT __stdcall Write( BSTR file, long len, long* s );

	HRESULT __stdcall WriteText( BSTR txt, long* s );

private:

	mol::filestream stream_;
	IO_SYSTYPE eol_;
	DWORD	codePage_;
	VARIANT_BOOL useBOM_;
};

#endif
