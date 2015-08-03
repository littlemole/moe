#include "win/enc.h"
#include "util/regex.h"
#include "ole/bstr.h"

///////////////////////////////////////////////////////////////////////
//
// encoding
//
///////////////////////////////////////////////////////////////////////

namespace mol {

CodePages::Entries codePages_;

const CodePages::Entries& CodePages::codePages()
{
	return codePages_;
}

const CodePages::Entry& CodePages::systemDefaultCodePage()
{
	static Entry entry(std::make_pair(instance().cpi_.CodePage, instance().cpi_.CodePageName));
	return entry;
}

const CodePages::Entry& CodePages::UTF7()
{
	return codePages_[CP_UTF7];
}

const CodePages::Entry& CodePages::UTF8()
{
	return codePages_[CP_UTF8];
}

const CodePages::Entry& CodePages::UTF16()
{
	static Entry entry(CP_WINUNICODE, L"1200 (Unicode utf-16)");
	return entry;
}

const CodePages::Entry& CodePages::ANSI()
{
	static Entry entry(CP_WINANSI, L"Ansi (Windows Default)");
	return entry;
}


CodePages& CodePages::instance()
{
	static CodePages cp;
	return cp;
}


BOOL CALLBACK CodePages::codePageEnumProc( LPTSTR lpCodePageString)
{
	int cp = _wtoi(lpCodePageString);

	CPINFOEX cpi;
	if ( ::GetCPInfoEx(cp,0,&cpi) )
	{
		std::wstring s(cpi.CodePageName);
		codePages_.insert( std::make_pair(cp,std::make_pair(cp,s)) );
	}
	return TRUE;
}


const unsigned char FileEncoding::UTF8_BOM[]    = { 0xef, 0xbb, 0xbf };
const unsigned char FileEncoding::UTF16LE_BOM[] = { 0xff, 0xfe, 0x00 };

FileEncoding::FileEncoding()
{
	eol_ = UNIX;
	enc_ = "Unknown";
	hasBOM_ = false;
	isBinary_ = false;
	mol::punk<IMultiLanguage> ml;
    if ( S_OK == ml.createObject(CLSID_CMultiLanguage))
    {
        if ( S_OK == ml.queryInterface(IID_IMultiLanguage2,(void**)&multiLang_) )
            return;
    }
}

bool FileEncoding::hasUTF8_BOM(const std::string& c)
{
	if ( c.size() < 3 )
		return false;
    if ( (unsigned char)c[0] == UTF8_BOM[0] )
        if ( (unsigned char)c[1] == UTF8_BOM[1] )
            if ( (unsigned char)c[2] == UTF8_BOM[2] )
			{
                return true;
			}
    return false;
}

bool FileEncoding::hasUTF16_BOM(const std::string& c)
{
	if ( c.size() < 2 )
		return false;
    if ( (unsigned char)c[0] == UTF16LE_BOM[0] )
        if ( (unsigned char)c[1] == UTF16LE_BOM[1] )
			{
                return true;
			}
    return false;
}

std::string FileEncoding::Encoding()
{
	return enc_;
}

bool FileEncoding::hasBOM()
{
	return hasBOM_;
}

bool FileEncoding::isBinary()
{
	return isBinary_;
}

FileEncoding::eol_mode FileEncoding::eolMode()
{
	return eol_;
}

int  FileEncoding::investigate(const std::string& c)
{
	return investigate(c,"");
}

int  FileEncoding::investigate(const std::string& c, const std::string& h )
{
	// get encoding
	getEncoding(c,h);

	// check eol mode 
	size_t p = c.find_first_of("\r\n");
	if ( p != std::string::npos )
	{
		if ( c[p] == 0x0a )
			eol_ = UNIX;
		else
			eol_ = DOS;
	}

	// check for binaries
	isBinary_ = false;
	p = 0;
	while ( (c[p]) && (p < c.size()) )
		p++;

	if ( p < c.size() )
	{
		switch ( codePage_ )
		{
			case CP_WINUNICODE :
			{
				//TODO: smell
				if ( (p != c.size()) && ((p+1)%2 != 0) )
					isBinary_ = true;
				break;
			}
			case CP_UTF8    :
			default		 :
			{
				if ( p != c.size() )
					isBinary_ = true;
				break;
			}
		}
	}
    return codePage_;
}

int  FileEncoding::getEncoding(const std::string& c, const std::string& h )
{
	enc_ = "UNKNOWN";

	// first look for supported ByteOrder4marks
	if ( hasUTF8_BOM(c) == true )
	{
		hasBOM_ = true;
		enc_ = "UTF-8";
		codePage_ = CP_UTF8;
		return CP_UTF8;
	}

	if ( hasUTF16_BOM(c) == true )
	{
		hasBOM_ = true;
		enc_ = "UTF-16";
		codePage_ = CP_WINUNICODE;
        return CP_WINUNICODE;
	}

	// second check headers for charset specs in content-type
	if ( !h.empty() )
	{
		mol::RegExp rgxp(PCRE_CASELESS,"content-type.*:(.*);.*charset.*=(.*)");

		if ( rgxp.match(h) )
		{
			std::wstring s = mol::towstring(rgxp(h,2));
			s = mol::trim(s);

			mol::bstr bstr(s);
			MIMECSETINFO minfo;

			HRESULT hr = multiLang_->GetCharsetInfo(bstr,&minfo);
			if ( hr == S_OK )
			{
				enc_ = mol::tostring(minfo.wszCharset);
				codePage_ = minfo.uiInternetEncoding;
				return minfo.uiInternetEncoding;
			}
		}
	}

	// third, try to find xml decl
	//	<?xml version="1.0" encoding="ISO-8859-1" ?>
	mol::RegExp reg_xml(PCRE_CASELESS,"<?xml +version *= *('|\")[^'\"]*('|\") +encoding *= *('|\")([^'\"]*)('|\")");
	if ( reg_xml.match(c) )
	{
		//std::string s = reg_xml(c,4);

		std::wstring s = mol::towstring(reg_xml(c,4));
		s = mol::trim(s);

		mol::bstr b(s);
		MIMECSETINFO minfo;

		HRESULT hr = multiLang_->GetCharsetInfo(b,&minfo);
		if ( hr == S_OK )
		{
			enc_ = mol::tostring(minfo.wszCharset);
			codePage_ = minfo.uiInternetEncoding;
			return minfo.uiInternetEncoding;
		}
	}

	// forth, search body for meta-tag
	// caseless match <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
	mol::RegExp reg_con(PCRE_CASELESS,"<meta[^>'\"]*http-equiv *= *('|\")content-type('|\") *content *= *('|\")[^'\"]*charset[^'\"=]*=([^'\"]*)('|\") */? *>");
	if ( reg_con.match(c) )
	{
		std::string s = mol::tostring(reg_con(c,4));
		s = mol::trim(s);

		// can't be UTF-16 - if we matched the *ASCII* string "UTF-16", then encoding is broken!
		if ( s != "UTF-16" ) 
		{
			mol::bstr b(s);
			MIMECSETINFO minfo;

			HRESULT hr = multiLang_->GetCharsetInfo(b,&minfo);
			if ( hr == S_OK )
			{
				enc_ = mol::tostring(minfo.wszCharset);
				codePage_ = minfo.uiInternetEncoding;
				return minfo.uiInternetEncoding;
			}
		}
	}

	// no result yet? start start guessing with IMultiLang
    const int dEncInfoSize = 10;
    int s = dEncInfoSize;
    int l = (int)c.size();
    DetectEncodingInfo dEncInf[dEncInfoSize];
    HRESULT hr = multiLang_->DetectInputCodepage(  MLDETECTCP_HTML, 0,(char*) c.c_str(),&l, dEncInf, &s );

	if ( s )
	{
		DetectEncodingInfo dei = dEncInf[s-1];
		while ( s )
		{
			if ( dEncInf[s-1].nConfidence > 100 )
				if ( dEncInf[s-1].nConfidence >= dei.nConfidence )
					dei = dEncInf[s-1];
			s--;
		}
		MIMECPINFO minfo;
		hr = multiLang_->GetCodePageInfo(dei.nCodePage,dei.nLangID,&minfo);
		if ( hr == S_OK )
		{
			enc_ = mol::tostring(minfo.wszWebCharset);
		}
		codePage_ = dei.nCodePage;
		return dei.nCodePage;
	}	
    return 0;
}

std::string FileEncoding::convertToUTF8(const std::string& raw_bytes, long enc_hint)
{
	DWORD cp = investigate(raw_bytes);

	codePage_ = CP_UTF8;
	switch(cp)
	{
		case CP_UTF8:
		{
			break;
		}
		case CP_WINUNICODE:
		{
			codePage_ = CP_WINUNICODE;
			break;
		}
		case -1:
		{
			codePage_ = enc_hint;
			break;
		}
		default:
		{
			if ( enc_hint == CP_UTF8 )
				codePage_ = CP_UTF8;
			else
				codePage_ = cp;
		}
	}

	if ( isBinary() )
	{
		return "";
	}

	switch ( codePage_ )
	{
		case CP_WINUNICODE :
		{
			// jump over BOM
			std::string s2(raw_bytes);
			if ( raw_bytes.substr(0,2) == std::string((char*)mol::FileEncoding::UTF16LE_BOM,2) )
				s2 = std::string(raw_bytes.data()+2,raw_bytes.size()-2);

			// it really is a UCS-2 string, so cast to wchar_t (WIN32)
			std::wstring ws((wchar_t*)(s2.data()),s2.size()/sizeof(wchar_t));

			// now convert UTF16-LE to UTF-8
			std::string u = mol::toUTF8(ws);
			return mol::unix2dos(u);
		}
		case CP_UTF8 :
		{
			std::string s2;
			if ( raw_bytes.substr(0,3) == std::string((char*)mol::FileEncoding::UTF8_BOM,3) )
				s2 = std::string(raw_bytes.c_str()+3,raw_bytes.size()-3);
			else
				s2 = raw_bytes;

			s2 = mol::unix2dos(s2);
			return s2;
		}
		default:
		{
			std::string s2(mol::toUTF8(raw_bytes,codePage_));
			s2 = mol::unix2dos(s2);
			return s2;
		}
	}

	return "";
}


}

