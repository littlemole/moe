#ifndef MOL_FILE_ENCODING_LIB_DEF_GUARD_DEFINE_
#define MOL_FILE_ENCODING_LIB_DEF_GUARD_DEFINE_

#include "win/file.h"
#include "ole/punk.h"
#include <MLang.h>

namespace mol {

class CodePages
{
public:

	typedef std::pair<int,std::wstring> Entry;
	typedef std::map<int, Entry > Entries;
	typedef Entries::const_iterator Iterator;

	static const Entries& codePages();
	static const Entry& systemDefaultCodePage();
	static const Entry& UTF7();
	static const Entry& UTF8();
	static const Entry& UTF16();
	static const Entry& ANSI();

	static CodePages& instance();


private:

	CodePages()
	{
		::EnumSystemCodePages( codePageEnumProc,CP_INSTALLED);		
		::GetCPInfoEx(CP_ACP,0,&cpi_);
	}

	static BOOL CALLBACK codePageEnumProc( LPTSTR lpCodePageString);
	CPINFOEX cpi_;
};


class FileEncoding
{
public:

	enum eol_mode{ UNIX, DOS } eol;
	
    FileEncoding();

	int  investigate(const std::string& c);
	int  investigate(const std::string& c, const std::string& h);

	int codePage() { return codePage_; }
	std::string Encoding();

	eol_mode eolMode();
	bool isBinary();
	bool hasBOM() ;

    static bool hasUTF8_BOM(const std::string& c);
    static bool hasUTF16_BOM(const std::string& c);
    
    static const unsigned char UTF8_BOM[]; 
	static const unsigned char UTF16LE_BOM[];

	std::string convertToUTF8(const std::string& raw_bytes, long enc_hint);

private:

	int  getEncoding(const std::string& c, const std::string& h );

	eol_mode							eol_;
	bool								isBinary_;
	bool								hasBOM_;
	std::string							enc_;
	int									codePage_;
    mol::punk<IMultiLanguage2>			multiLang_;
};



}

#endif