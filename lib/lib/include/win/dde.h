#ifndef _MOL_DDEX_DEF_
#define _MOL_DDEX_DEF_

#include "util/uni.h"
#include <windows.h>
#include <dde.h>
#include <string>

namespace mol  {

namespace win  {

class dde
{
public:
    static bool bDontRespond_;
};

class dde_init : public dde
{
public:
    dde_init( HWND hWnd, WPARAM wParam, LPARAM lParam);
    ~dde_init();

    void ack( const mol::string& app, const mol::string& topic );

    bool  dontRespond();
    const mol::string& app();
    const mol::string& topic();

private:

    HWND		hWnd_;
    HWND		hWndClient_;
    mol::string	inApp_;
    mol::string	intopic_;
    ATOM		aOutApp_;
    ATOM		aOutTopic_;
};


class dde_exec : public dde
{
public:
    dde_exec( HWND hWnd, WPARAM wParam, LPARAM lParam);
    ~dde_exec();

    int parse( );
    void ack(int i);
    void execute(const mol::string& path, const mol::string & clss, const mol::string& verb , int mask);

    const mol::string& getCmdLine();
    const mol::string& getCmd();
    const mol::string& getPath();

private:
    mol::string	    cmdLine_;
    mol::string     cmd_;
    mol::string     path_;

    int  getCommandTypeFromDDEString();
    bool getPathFromDDEString();

    HWND		hWnd_;
    LPARAM		lParam_;
    HWND		hWndClient_;
    UINT_PTR	uLo_;
    HGLOBAL		hgMem_;
    DDEACK		ddeAck_;
};

class dde_terminate : public dde
{
public:
    dde_terminate( HWND wnd, WPARAM wParam )
    {
        hWnd_	    = wnd;
        hWndClient_ = (HWND) wParam;
    }

    ~dde_terminate( )
    {
        PostMessage( hWndClient_, WM_DDE_TERMINATE, (WPARAM)hWnd_, 0);
    }

private:
    HWND		hWnd_;
    HWND		hWndClient_;
};

} // endnamespace mol::win
} // endnamespace mol

#endif

