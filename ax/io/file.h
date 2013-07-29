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
#include "dtl/dtl.hpp"
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

class UniDiffObj : 
	public mol::com_registerobj<UniDiffObj,CLSID_UniDiff,CLSCTX_INPROC_SERVER,
						PROGRAMMABLE|APARTMENT|DLL_SURROGATE|CAN_ELEVATE>,
	public mol::Dispatch<IUniDiff>,
	public mol::interfaces< UniDiffObj,
			mol::implements<
				IUniDiff,
				IDispatch > >
{
public:

	typedef std::string elem;
	typedef std::vector<std::string> sequence;

	HRESULT virtual __stdcall Diff( BSTR a, BSTR b, BSTR* f )
	{
		if ( !a || !b || !f )
			return E_INVALIDARG;

		typedef std::string elem;
		typedef std::vector<std::string> sequence;

		std::string ua = mol::toUTF8( a );
		std::string ub = mol::toUTF8( b );

		ua = mol::dos2unix(ua);
		ub = mol::dos2unix(ub);

		sequence sa = mol::split(ua,"\n");
		sequence sb = mol::split(ub,"\n");

		dtl::Diff< elem, sequence > diff(sa,sb);
		diff.compose();
		diff.composeUnifiedHunks();

		std::ostringstream oss;
		diff.printUnifiedFormat(oss);

//		diff.composeUnichunkFromStream(

		*f = ::SysAllocString(mol::fromUTF8(oss.str()).c_str());

		return S_OK;
	}

	HRESULT virtual __stdcall Patch( BSTR original, BSTR patch, BSTR* f )
	{
		if ( !original || !patch || !f )
			return E_INVALIDARG;

		std::string soriginal = mol::toUTF8( original );
		soriginal = mol::dos2unix(soriginal);

		std::string spatch = mol::toUTF8( patch );
		spatch = mol::dos2unix(spatch);
		
		dtl::Diff< elem, sequence > diff = parseUnihunkFile(std::istringstream(spatch));

		sequence source = mol::split(soriginal,"\n");
		sequence result = diff.uniPatch(source);

		std::ostringstream oss;
		for ( sequence::iterator it = result.begin(); it != result.end(); it++)
		{
			oss << (*it) << std::endl;
		}

		*f = ::SysAllocString( mol::fromUTF8( oss.str() ).c_str() );
		return S_OK;
	}

private:

	dtl::Diff< elem, sequence > parseUnihunkFile(std::istream& is) 
	{
		dtl::Diff< elem, sequence > result;

		while(!is.eof())
		{
			char c = is.peek();
			if( c == '@' ) 
			{
				result.composeUnichunkFromStream(is);
				break;
			}
			else 
			{
				elem line;
				std::getline(is,line);
			}
		}
		return result;
	}

};

#endif


