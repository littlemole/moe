#include "win/RTFEdit.h"

namespace mol  {
namespace win  {

const mol::TCHAR richedit_class[] = RICHEDIT_CLASS;

DWORD CALLBACK RichEditStreamCallBack::inStreamCallback( DWORD_PTR dwCookie, LPBYTE pbBuff, LONG cb, LONG *pcb )
{
    RichEditStreamCallBack* pThis	= (RichEditStreamCallBack*)(dwCookie);
    const std::string& str			= pThis->ioBuf_;
	LONG toWrite					= (LONG)(str.size())*sizeof(char) -  pThis->written_;

    if ( toWrite > cb )
            toWrite = cb;

    *pcb = (LONG)toWrite;

    if ( toWrite == 0 )
            return 0;

	const char* p = str.c_str();
    p += pThis->written_;

    memcpy(pbBuff,p,toWrite);

    pThis->written_ += (long)toWrite;

    return 0;
}

DWORD CALLBACK RichEditStreamCallBack::outStreamCallback( DWORD_PTR dwCookie, LPBYTE pbBuff, LONG cb, LONG *pcb )
{
    RichEditStreamCallBack* pThis	= (RichEditStreamCallBack*)(dwCookie);
    const std::string& str			= pThis->ioBuf_;

    pThis->written_ += cb;

    *pcb = cb;

    char* buf = new char[cb+1];

    memcpy(buf,pbBuff,cb);

    buf[cb]=0;

	pThis->ioBuf_ += (const char*)(buf);

    delete buf;

    return 0;
}

} // end namespace mol::win

LRESULT RichEditCtrl::streamIn( const std::string c, int type )
{
    cb_.ioBuf_					= c ;
    cb_.written_				= 0;
    cb_.editstream_.dwError		= 0;
	cb_.editstream_.dwCookie	= (DWORD_PTR)(mol::win::RichEditStreamCallBack*) &cb_;
    cb_.editstream_.pfnCallback	= &(mol::win::RichEditStreamCallBack::inStreamCallback);

    LRESULT ret=0;
    if ( c != "" )
            ret = sendMessage(EM_STREAMIN,type,(LPARAM)(&(cb_.editstream_)) );

    if ( cb_.editstream_.dwError != 0 )
	{
		cry();
            throw X( _T("stream E") );
	}

    return ret;
}

LRESULT RichEditCtrl::streamOut(std::string& out, int type )
{
    cb_.ioBuf_					= "" ;
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


bool RichEditCtrl::search( const std::string& s, int options )
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

HDC choosePrinterDC(HWND owner, int& copies, bool& collate)
{
	PRINTDLG pd;

	// Initialize PRINTDLG
	ZeroMemory(&pd, sizeof(pd));
	pd.lStructSize = sizeof(pd);
	pd.hwndOwner   = owner;
	pd.hDevMode    = NULL;     // Don't forget to free or store hDevMode
	pd.hDevNames   = NULL;     // Don't forget to free or store hDevNames
	pd.Flags       = PD_USEDEVMODECOPIESANDCOLLATE | PD_RETURNDC |PD_NOPAGENUMS|PD_NOSELECTION; 
	pd.nCopies     = 1;
	pd.nFromPage   = 0xFFFF; 
	pd.nToPage     = 0xFFFF; 
	pd.nMinPage    = 1; 
	pd.nMaxPage    = 0xFFFF; 

	copies = 0;
	collate = false;
	if (PrintDlg(&pd)==TRUE) 
	{
		collate = (pd.Flags & PD_COLLATE) != 0;
		copies  = pd.nCopies;
		return pd.hDC;
	}
	return 0;
}

BOOL RichEditCtrl::PrintRTF()
{
	static DOCINFO di = { sizeof(DOCINFO), _T("mol scintilla print job") };

	int copies = 0;
	bool collate = false;
	HDC hdcPrinter = mol::choosePrinterDC(*this,copies,collate);
	if ( NULL == hdcPrinter )
		return FALSE;
    
    if (!StartDoc(hdcPrinter, &di))
    {
        return FALSE;
    }

    int cxPhysOffset = GetDeviceCaps(hdcPrinter, PHYSICALOFFSETX);
    int cyPhysOffset = GetDeviceCaps(hdcPrinter, PHYSICALOFFSETY);
    
    int cxPhys = GetDeviceCaps(hdcPrinter, PHYSICALWIDTH);
    int cyPhys = GetDeviceCaps(hdcPrinter, PHYSICALHEIGHT);

    // Create "print preview". 
    SendMessage(*this, EM_SETTARGETDEVICE, (WPARAM)hdcPrinter, cxPhys/2);

    FORMATRANGE fr;
    
    fr.hdc       = hdcPrinter;
    fr.hdcTarget = hdcPrinter;
    fr.rc.left   = cxPhysOffset;
    fr.rc.right  = cxPhysOffset + cxPhys;
    fr.rc.top    = cyPhysOffset;
    fr.rc.bottom = cyPhysOffset + cyPhys;

    SendMessage(*this, EM_SETSEL, 0, (LPARAM)-1);          // Select the entire contents.
    SendMessage(*this, EM_EXGETSEL, 0, (LPARAM)&fr.chrg);  // Get the selection into a CHARRANGE.

    BOOL fSuccess = TRUE;

    // Use GDI to print successive pages.
    while (fr.chrg.cpMin < fr.chrg.cpMax && fSuccess) 
    {
        fSuccess = StartPage(hdcPrinter) > 0;
        
        if (!fSuccess) break;
        
        int cpMin = SendMessage(*this, EM_FORMATRANGE, TRUE, (LPARAM)&fr);
        
        if (cpMin <= fr.chrg.cpMin) 
        {
            fSuccess = FALSE;
            break;
        }
        
        fr.chrg.cpMin = cpMin;
        fSuccess = EndPage(hdcPrinter) > 0;
    }
    
    SendMessage(*this, EM_FORMATRANGE, FALSE, 0);
    
    if (fSuccess)
    {
        EndDoc(hdcPrinter);
    } 
    
    else 
    
    {
        AbortDoc(hdcPrinter);
    }
    
    return fSuccess;
    
}

} // end namespace mol
