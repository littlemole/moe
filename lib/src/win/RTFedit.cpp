#include "win/RTFEdit.h"

namespace mol  {
namespace win  {

const mol::TCHAR richedit_class[] = RICHEDIT_CLASS;

DWORD CALLBACK RichEditStreamCallBack::inStreamCallback( DWORD_PTR dwCookie, LPBYTE pbBuff, LONG cb, LONG *pcb )
{
    RichEditStreamCallBack* pThis	= (RichEditStreamCallBack*)(dwCookie);
    const mol::string& str			= pThis->ioBuf_;
	LONG toWrite					= (LONG)(str.size())*sizeof(mol::TCHAR) -  pThis->written_;

    if ( toWrite > cb )
            toWrite = cb;

    *pcb = (LONG)toWrite;

    if ( toWrite == 0 )
            return 0;

	const mol::TCHAR* p = str.c_str();
    p += pThis->written_;

    memcpy(pbBuff,p,toWrite);

    pThis->written_ += (long)toWrite;

    return 0;
}

DWORD CALLBACK RichEditStreamCallBack::outStreamCallback( DWORD_PTR dwCookie, LPBYTE pbBuff, LONG cb, LONG *pcb )
{
    RichEditStreamCallBack* pThis	= (RichEditStreamCallBack*)(dwCookie);
    const mol::string& str			= pThis->ioBuf_;

    pThis->written_ += cb;

    *pcb = cb;

    char* buf = new char[cb+1];

    memcpy(buf,pbBuff,cb);

    buf[cb]=0;

	pThis->ioBuf_ += (const mol::TCHAR*)(buf);

    delete buf;

    return 0;
}

} // end namespace mol::win

LRESULT RichEditCtrl::streamIn( const mol::string c, int type )
{
    cb_.ioBuf_					= c ;
    cb_.written_				= 0;
    cb_.editstream_.dwError		= 0;
	cb_.editstream_.dwCookie	= (DWORD_PTR)(mol::win::RichEditStreamCallBack*) &cb_;
    cb_.editstream_.pfnCallback	= &(mol::win::RichEditStreamCallBack::inStreamCallback);

    LRESULT ret=0;
    if ( c != _T("") )
            ret = sendMessage(EM_STREAMIN,type,(LPARAM)(&(cb_.editstream_)) );

    if ( cb_.editstream_.dwError != 0 )
            throw X( _T("stream E") );

    return ret;
}

LRESULT RichEditCtrl::streamOut(mol::string& out, int type )
{
    cb_.ioBuf_					= _T("") ;
    cb_.written_				= 0;
    cb_.editstream_.dwError		= 0;
    cb_.editstream_.dwCookie	= (DWORD_PTR)(mol::win::RichEditStreamCallBack*) &cb_;
    cb_.editstream_.pfnCallback	= &(mol::win::RichEditStreamCallBack::outStreamCallback);

    LRESULT ret = sendMessage(EM_STREAMOUT,type,(LPARAM)(&(cb_.editstream_)) );

    if ( cb_.editstream_.dwError != 0 )
            throw X( _T("stream out E") );

    out = cb_.ioBuf_;
    return ret;
}


LRESULT RichEditCtrl::notify(int id )
{
    return sendMessage(EM_SETEVENTMASK,0,(LPARAM)id);
}


bool RichEditCtrl::search( const mol::string& s, int options )
{
    searchText_ = s;
    return search( options );
}

bool RichEditCtrl::search( int options)
{
    FINDTEXT ft;
    CHARRANGE chrg;

    if ( nextSearchPos_ != 0 )
        if ( (lastSearchDir_ & FR_DOWN) != ( options & FR_DOWN ) )
        {
            if ( (options & FR_DOWN) == 0 )
            {
                nextSearchPos_-=2;
            }
            else
            {
                nextSearchPos_+=2;
            }
        }

    lastSearchDir_ = options;

    chrg.cpMin = nextSearchPos_;
    chrg.cpMax = -1;

    if ( 0 == (options & FR_DOWN) )
    {
        GETTEXTLENGTHEX gtl;
        gtl.codepage	= CP_ACP;
        gtl.flags		= GTL_DEFAULT;

        int len = (int)sendMessage(EM_GETTEXTLENGTHEX,WPARAM(&gtl),0);

        if ( nextSearchPos_ == 0 )
            chrg.cpMin = len-nextSearchPos_;//
        chrg.cpMax = 0;
    }

	mol::TCHAR buf[256];
	memcpy( buf,searchText_.c_str(), std::min( (int)(searchText_.size()*sizeof(mol::TCHAR)),255) );

    ft.lpstrText = buf;
    ft.chrg = chrg;

    int r = (int)sendMessage(EM_FINDTEXT , (WPARAM) options, (LPARAM)&ft );

    if ( r == -1 )
    {
        chrg.cpMin=0;
        chrg.cpMax=0;
        nextSearchPos_ =0;
        sendMessage( EM_EXSETSEL,  (WPARAM) 0, (LPARAM) &chrg );
        return false;
    }

    chrg.cpMin = r;
    chrg.cpMax = (LONG)(r + searchText_.size());

    if ( 0 == (options & FR_DOWN) )
        nextSearchPos_ =r-1;
    else
        nextSearchPos_ =chrg.cpMax+1;

    sendMessage( EM_EXSETSEL,  (WPARAM) 0, (LPARAM) &chrg );
    sendMessage( EM_HIDESELECTION, (WPARAM) 0,(LPARAM) 0 );

    return true;
}


} // end namespace mol
