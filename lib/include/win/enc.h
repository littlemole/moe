#ifndef MOL_FILE_ENCODING_LIB_DEF_GUARD_DEFINE_
#define MOL_FILE_ENCODING_LIB_DEF_GUARD_DEFINE_

#include "win/file.h"
#include "ole/punk.h"
#include <MLang.h>

namespace mol {

class FileEncoding
{
public:

	enum eol_mode{ UNIX, DOS } eol;
	
    FileEncoding();

	int  investigate(const std::string& c);
	int  investigate(const std::string& c, const std::string& h);

	std::string Encoding();

	eol_mode eolMode();
	bool isBinary();
	bool hasBOM() ;

    static bool hasUTF8_BOM(const std::string& c);
    static bool hasUTF16_BOM(const std::string& c);
    
    static const unsigned char UTF8_BOM[]; 
	static const unsigned char UTF16LE_BOM[];

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