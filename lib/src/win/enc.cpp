#include "win/enc.h"
#include "util/regex.h"
#include "ole/bstr.h"

///////////////////////////////////////////////////////////////////////
//
// encoding
//
///////////////////////////////////////////////////////////////////////

namespace mol {

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
			mol::string s = mol::toString(rgxp(h,2));
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

		mol::string s = mol::toString(reg_xml(c,4));
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



}

