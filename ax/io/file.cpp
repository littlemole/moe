#include "StdAfx.h"
#include "file.h"

using namespace mol;

FileObj::FileObj()
{
	eol_		= IO_SYSTYPE_WIN32;
	codePage_	= CP_ACP;
	useBOM_		= VARIANT_FALSE;
}

HRESULT __stdcall FileObj::get_Filename( BSTR* f)
{
	if ( *f )
		return E_INVALIDARG;

	*f = 0;

	if (!stream_)
		return S_OK;

	*f = ::SysAllocString( mol::towstring(stream_.path()).c_str());
	return S_OK;
}

HRESULT __stdcall FileObj::put_EoL( long t)
{
	if (!stream_)
		return S_OK;

	if ( t == 0 )
		this->eol_ = IO_SYSTYPE_UNIX;
	else
		this->eol_ = IO_SYSTYPE_WIN32;

	return S_OK;
}

HRESULT __stdcall FileObj::get_EoL( long* t)
{
	if (!t)
		return E_INVALIDARG;

	if ( this->eol_ == IO_SYSTYPE_WIN32 )
		*t = IO_SYSTYPE_WIN32;
	else
		*t = IO_SYSTYPE_UNIX;
	return S_OK;
}

HRESULT __stdcall FileObj::put_Encoding( long cp)
{
	this->codePage_ = cp;
	return S_OK;
}

HRESULT __stdcall FileObj::get_Encoding( long* cp)
{
	if ( !cp )
		return E_INVALIDARG;
	*cp = this->codePage_;
	return S_OK;
}

HRESULT __stdcall FileObj::put_UseBOM( VARIANT_BOOL vb)
{
	this->useBOM_ = vb;
	return S_OK;
}

HRESULT __stdcall FileObj::get_UseBOM( VARIANT_BOOL* vb)
{
	if ( !vb )
		return E_INVALIDARG;
	*vb = this->useBOM_;
	return S_OK;
}

HRESULT __stdcall FileObj::get_EoF( VARIANT_BOOL* vb)
{
	if ( !vb )
		return E_INVALIDARG;

	*vb = VARIANT_TRUE;

	if (!stream_)
		return S_OK;

	*vb = stream_.eof() ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

HRESULT __stdcall FileObj::get_Size( long* s)
{
	if ( !s )
		return E_INVALIDARG;

	*s = 0;
	if (!stream_)
		return S_OK;
	return S_OK;

	mol::FileInfo& fi = stream_.fileInfo();
	*s = fi.fileSizeLow();
	return S_OK;
}

HRESULT __stdcall FileObj::Open( BSTR file, VARIANT_BOOL* vb )
{
	if ( !vb )
		return E_INVALIDARG;

	*vb = VARIANT_FALSE;

	stream_.close();
	if ( stream_.open( mol::bstr(file).tostring() ) )
	{
		*vb = VARIANT_TRUE;
	}
	return S_OK;
}


HRESULT __stdcall FileObj::Create( BSTR file, VARIANT_BOOL* vb )
{
	if ( !vb )
		return E_INVALIDARG;

	*vb = VARIANT_FALSE;

	stream_.close();
	if ( stream_.create( mol::bstr(file).tostring() ) )
	{
		*vb = VARIANT_TRUE;
	}
	return S_OK;
}

HRESULT __stdcall FileObj::OpenReadOnly( BSTR file, VARIANT_BOOL* vb )
{
	if ( !vb )
		return E_INVALIDARG;

	*vb = VARIANT_FALSE;

	stream_.close();
	if ( stream_.openReadOnly( bstr(file).tostring() ) )
	{
		*vb = VARIANT_TRUE;
	}
	return S_OK;
}

HRESULT __stdcall FileObj::OpenAppend( BSTR file, VARIANT_BOOL* vb )
{
	if ( !vb )
		return E_INVALIDARG;

	*vb = VARIANT_FALSE;

	stream_.close();
	if ( stream_.append( bstr(file).tostring() ) )
	{
		*vb = VARIANT_TRUE;
	}
	return S_OK;
}

HRESULT __stdcall FileObj::Close()
{
	stream_.close();
	return S_OK;
}

HRESULT __stdcall FileObj::Read( long cnt, BSTR* file)
{
	if ( !file )
		return E_INVALIDARG;

	*file = 0;
	if (!stream_)
		return S_OK;

	size_t sg = (size_t)stream_.tellg();

	mol::cbuff buf(cnt+1);
	stream_.read(buf,cnt);
	buf[stream_.gcount()] = 0;

	mol::FileEncoding fe;
	fe.investigate( std::string(buf,(unsigned int)(stream_.gcount())) );

	if ( this->codePage_ == CP_UTF8 )
	{
		std::wstring ws = mol::fromUTF8( buf.toString() );

		if ( sg == 0 && fe.hasBOM() )
		{
			ws = mol::fromUTF8( std::string( buf+3, (unsigned int)(stream_.gcount()-3)) );
			this->useBOM_ = VARIANT_TRUE;
			this->eol_ = (IO_SYSTYPE)fe.eolMode();
		}
		else
			ws = mol::fromUTF8( buf.toString() );

		if ( this->eol_ == IO_SYSTYPE_UNIX )
			ws = mol::unix2dos(ws);

		*file = ::SysAllocString( ws.c_str() );
	}
	else
	if ( this->codePage_ == CP_WINUNICODE )
	{
		std::wstring ws = std::wstring( (wchar_t*)(char*)buf, (unsigned int)(stream_.gcount()/sizeof(wchar_t)) );

		if ( sg == 0 && mol::FileEncoding::hasUTF16_BOM(buf.toString()) )
		{
			ws = std::wstring( (wchar_t*)(buf+2), (unsigned int)((stream_.gcount()/sizeof(wchar_t))-1) );
			this->useBOM_ = VARIANT_TRUE;
			this->eol_ = (IO_SYSTYPE)fe.eolMode();
		}
		else
			ws = std::wstring( (wchar_t*)(char*)buf, (unsigned int)(stream_.gcount()/sizeof(wchar_t)) );

		if ( this->eol_ == IO_SYSTYPE_UNIX )
			ws = mol::unix2dos(ws);

		*file = ::SysAllocString( ws.c_str() );
	}
	else
	{
		if ( sg == 0 )
			this->eol_ = (IO_SYSTYPE)fe.eolMode();

		std::wstring ws = mol::towstring( buf.toString() );
		if ( this->eol_ == IO_SYSTYPE_UNIX )
			ws = mol::unix2dos(ws);

		*file = ::SysAllocString( ws.c_str() );
	}
	return S_OK;
}

HRESULT __stdcall FileObj::ReadText( BSTR* file)
{
	if ( !file )
		return E_INVALIDARG;

	*file = 0;
	if (!stream_)
		return S_OK;

	std::string s = stream_.readAll();
	mol::FileEncoding enc;
	this->codePage_ = enc.investigate(s);
	this->eol_      = (IO_SYSTYPE) enc.eolMode();
	this->useBOM_   = enc.hasBOM() ? VARIANT_TRUE : VARIANT_FALSE;

	if ( codePage_ == CP_UTF8 )
	{
		if ( enc.hasBOM() )
			s = s.substr(3,s.size()-3);
		if ( this->eol_ == IO_SYSTYPE_UNIX )
			s = mol::unix2dos(s);
		*file = ::SysAllocString( mol::fromUTF8( s ).c_str() );
		return S_OK;
	}
	if ( codePage_ == CP_WINUNICODE )
	{
		if ( enc.hasBOM() )
			s = s.substr(2,s.size()-2);

		std::wstring ws = std::wstring( (wchar_t*)(s.c_str()),s.size()/2 );

		if ( this->eol_ == IO_SYSTYPE_UNIX )
			ws = mol::unix2dos(ws);

		*file = ::SysAllocString( ws.c_str() );
		return S_OK;
	}

	if ( this->eol_ == IO_SYSTYPE_UNIX )
		s = mol::unix2dos(s);

	*file = ::SysAllocString( mol::towstring( s ).c_str() );
	return S_OK;
}

HRESULT __stdcall FileObj::Seek( long pos)
{
	if (!stream_)
		return S_OK;

	stream_.seekg(pos);
	stream_.seekp(pos);
	return S_OK;
}

HRESULT __stdcall FileObj::Write( BSTR file, long len, long* s )
{
	if ( !s )
		return E_INVALIDARG;

	*s = 0;
	if (!file )
		return S_OK;

	if (!stream_)
		return S_OK;

	size_t sp = (size_t)stream_.tellp();

	std::wstring ws = bstr(file).towstring();
	if ( !ws.empty() )
	{
		std::string c;
		if ( this->eol_ == IO_SYSTYPE_UNIX )
			ws = mol::dos2unix(ws);

		if ( this->codePage_ == CP_UTF8 )
		{
			if ( sp == 0 )
				if ( this->useBOM_ == VARIANT_TRUE )
					stream_.write( (char*)mol::FileEncoding::UTF8_BOM , 3 );

			c = mol::toUTF8(ws);
		}
		else 
		if ( this->codePage_ == CP_WINUNICODE )
		{
			if ( sp == 0 )
				if ( this->useBOM_ == VARIANT_TRUE )
					stream_.write( (char*)mol::FileEncoding::UTF16LE_BOM , 2 );

			c = std::string( (char*)(ws.c_str()), ws.size()*sizeof(wchar_t) );
		}
		else
		{
			c = mol::tostring(ws);
		}

		stream_.write( c.c_str(), len );
		*s = (long)stream_.gcount();
	}
	return S_OK;
}

HRESULT __stdcall FileObj::WriteText( BSTR txt, long* s )
{
	ODBGS("WriteText 1");
	if ( !s )
		return E_INVALIDARG;

	*s = 0;

	ODBGS("WriteText 2");

	if (!txt )
		return S_OK;

	ODBGS("WriteText 3");

	if (!stream_)
		return S_OK;

	ODBGS("WriteText 4");

	size_t sp = (size_t)stream_.tellp();

	std::wstring ws = bstr(txt).towstring();

	if ( this->eol_ == IO_SYSTYPE_UNIX )
		ws = mol::dos2unix(ws);

	if ( !ws.empty() )
	{
		std::string c;
		if ( this->eol_ == IO_SYSTYPE_UNIX )
			ws = mol::dos2unix(ws);

		if ( this->codePage_ == CP_UTF8 )
		{
			c = mol::toUTF8(ws);

			if ( sp == 0 )
				if ( this->useBOM_ == VARIANT_TRUE )
					stream_.write( (char*)mol::FileEncoding::UTF8_BOM , 3 );		
		}
		else 
		if ( this->codePage_ == CP_WINUNICODE )
		{
			c = std::string( (char*)(ws.c_str()), ws.size()*sizeof(wchar_t) );

			if ( sp == 0 )
				if ( this->useBOM_ == VARIANT_TRUE )
					stream_.write( (char*)mol::FileEncoding::UTF16LE_BOM , 2 );
		}
		else
		{
			c = mol::tostring(ws);
		}

		ODBGS(c);
		stream_.put(c);
		*s = (long)stream_.gcount();
	}
	return S_OK;
}

