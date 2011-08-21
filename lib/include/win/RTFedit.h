#ifndef MOL_RICHEDITCTRL_DEF_
#define MOL_RICHEDITCTRL_DEF_

#include "win/Ctrl.h"
#include <Richedit.h>
#include <Commdlg.h>

////////////////////////////////////////////////////////////////////////////
// Richeditcrtl
////////////////////////////////////////////////////////////////////////////

namespace mol  {


class richedit_init
{
public:
  richedit_init()
  {
    ::LoadLibrary(_T("Riched20.dll"));
  }
};

namespace win  {

class RichEditStreamCallBack
{
public:
    static DWORD CALLBACK inStreamCallback( DWORD_PTR dwCookie, LPBYTE pbBuff, LONG cb, LONG *pcb );
    static DWORD CALLBACK outStreamCallback( DWORD_PTR dwCookie, LPBYTE pbBuff, LONG cb, LONG *pcb );

    std::string		ioBuf_;
    EDITSTREAM		editstream_;
    long			written_;
};

extern const mol::TCHAR richedit_class[];

} // end namespace win

class RichEditCtrl : public mol::win::CtrlClass<mol::win::richedit_class>
{
public:
    RichEditCtrl()
    {
		nextSearchPos_=0;
    }

    // styles
    virtual int style()   { return WS_CHILD|WS_VISIBLE|ES_MULTILINE; }

    LRESULT streamIn(  const std::string c, int type = SF_TEXT);
    LRESULT streamOut( std::string&, int type = SF_TEXT);
    LRESULT notify(int id );

    bool search ( const std::string& s , int options = FR_DOWN);
    bool search(int options );

    const std::string& getSearchText() { return searchText_; };

	BOOL PrintRTF();

private:
	mol::win::RichEditStreamCallBack	cb_;

    std::string				searchText_;
    int						nextSearchPos_;
    int						lastSearchDir_;
};


} // endnamespace mol

#endif


