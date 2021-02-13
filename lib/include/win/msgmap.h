#ifndef _MSG_MAP_DEF_GUARD_DEFINE_
#define _MSG_MAP_DEF_GUARD_DEFINE_

#include <win/Core.h>
#include <map>
#include <commctrl.h>
#include <Richedit.h>
#include <commdlg.h>
#include "util/util.h"
#include "util/Signature.h"
#include "thread/fun.h"
#include <Windowsx.h>

namespace mol {

namespace win {

class WndProc;

} //end namespace;

///////////////////////////////////////////////////////////////////
// msg craking
///////////////////////////////////////////////////////////////////

class Crack
{
public:
        Crack( UINT msg, WPARAM wParam, LPARAM lParam)
                : msg_(msg), wParam_(wParam), lParam_(lParam)
        {}

        UINT   msg()	{ return msg_;		}
        WPARAM wparam() { return wParam_;	}
        LPARAM lparam() { return lParam_;	}

        WORD   lo()		{ return LOWORD(wParam_);	}
        WORD   hi()		{ return HIWORD(wParam_);	}
        WORD   id()		{ return lo();				}
        WORD   event()  { return hi();				}

        LPNMHDR         nmhdr()		        { return (LPNMHDR)         lParam_;	}
		LPNMHEADER      nmheader()	        { return (LPNMHEADER)      lParam_;	}
		LPNMTVDISPINFO  treeViewDispInfo()  { return (LPNMTVDISPINFO)  lParam_; }
        LPNMTREEVIEW    nmtreeview()        { return (NMTREEVIEW*)     lParam_;	}
		LPNMTOOLBAR     nmtoolbar()			{ return (NMTOOLBAR*)	   lParam_; }
        MSGFILTER*      msgfilter()         { return (MSGFILTER*)      lParam_;	}
        FINDREPLACE*    findreplace()       { return (FINDREPLACE*)    lParam_;	}
        TV_KEYDOWN*     keydown()	        { return (TV_KEYDOWN*)     lParam_;	}
        NMLISTVIEW*     listview()          { return (NMLISTVIEW*)     lParam_;	}
		NMLVDISPINFO*   listviewDispInfo()  { return (NMLVDISPINFO*)   lParam_;	}
		NMITEMACTIVATE* listActivate()      { return (NMITEMACTIVATE*) lParam_;	}
        NMTTDISPINFO*   toolTipDispInfo()   { return (NMTTDISPINFO*)   lParam_; }
		NMOBJECTNOTIFY* notifyObject()		{ return (NMOBJECTNOTIFY*) lParam_; }
		PSHNOTIFY*		propSheetNotify()   { return (PSHNOTIFY*)	   lParam_; }
		POINT wPoint()
		{
			return mol::Point( LOWORD(wParam_),HIWORD(wParam_));
		}

		POINT lPoint()
		{
			return mol::Point( GET_X_LPARAM(lParam_),GET_Y_LPARAM(lParam_));
		}

private:
        UINT    msg_;
        WPARAM	wParam_;
        LPARAM	lParam_;
};

/////////////////////////////////////////////////////////////////
// Msg Map implementation template
/////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////

class IMsgMapHandler
{
public:
	LRESULT virtual operator()( mol::win::WndProc* This, UINT msg, WPARAM wParam, LPARAM lParam) = 0;

	void virtual connect_msg( int did )		  = 0;
	void virtual connect_cmd( int id )		  = 0;
	void virtual connect_notify_id( int id )  = 0;
	void virtual connect_notify_code( int id ) = 0;
};

/////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////


template <class WND,class BASE>
class MsgMap
{
public:

	virtual ~MsgMap()
	{
		mol::clear(msgMap_);
		mol::clear(cmdMap_);
		mol::clear(notifyCodeMap_);
		mol::clear(notifyIdMap_);
	}

    LRESULT call( WND* wnd, UINT msg, WPARAM wParam, LPARAM lParam )
    {
		// NOTIFICATION MSG by CMD?
        if ( msg == WM_NOTIFY )
        {
            LPNMHDR pnmhdr = (LPNMHDR) lParam;
			if ( pnmhdr)
            if ( notifyIdMap_.count((UINT)(pnmhdr->idFrom)) > 0 )
            {
				IMsgMapHandler* handler = notifyIdMap_[(UINT)(pnmhdr->idFrom)];
				return (*handler)( wnd, msg, wParam, lParam );
            } 
        }
		// NOTIFICATION MSG by ID?
        if ( msg == WM_NOTIFY )
        {
            LPNMHDR pnmhdr = (LPNMHDR) lParam;
			if ( pnmhdr)
            if ( notifyCodeMap_.count((UINT)(pnmhdr->code)) > 0 )
            {
                IMsgMapHandler* handler = notifyCodeMap_[(UINT)(pnmhdr->code)];
				return (*handler)( wnd, msg, wParam, lParam );
            } 
        }

		// COMMAND MSG?
		//if ( HIWORD(wParam) <= 1 )
        if ( msg == WM_COMMAND )
        {
            if ( cmdMap_.count(LOWORD(wParam)) > 0 )
            {
                IMsgMapHandler* handler = cmdMap_[LOWORD(wParam)];
				return (*handler)( wnd, msg, wParam, lParam );
            }
        }

		// ALL OTHER WINDOWS MSGS
        if ( msgMap_.count(msg) > 0 )
        {
            IMsgMapHandler* handler = msgMap_[msg];
			return (*handler)( wnd, msg, wParam, lParam );

        }
		// route through base class
		else 
		{
			BASE* b = static_cast<BASE*>(wnd);
            return b->BASE::wndProc( *wnd, msg, wParam, lParam );
		}
    }

	LRESULT callIf( WND* wnd, UINT msg, WPARAM wParam, LPARAM lParam, bool& handled )
    {
		handled = true;
		// NOTIFICATION MSG identified by Ctrl ID?
        if ( msg == WM_NOTIFY )
        {
            LPNMHDR pnmhdr = (LPNMHDR) lParam;
			if ( pnmhdr)
            if ( notifyIdMap_.count((UINT)(pnmhdr->idFrom)) > 0 )
            {
				IMsgMapHandler* handler = notifyIdMap_[(UINT)(pnmhdr->idFrom)];
				return (*handler)( wnd, msg, wParam, lParam );
            } 
        }
		// NOTIFICATION MSG by Notify Code?
        if ( msg == WM_NOTIFY )
        {
            LPNMHDR pnmhdr = (LPNMHDR) lParam;
			if ( pnmhdr)
            if ( notifyCodeMap_.count((UINT)(pnmhdr->code)) > 0 )
            {
				IMsgMapHandler* handler = notifyCodeMap_[(UINT)(pnmhdr->code)];
				return (*handler)( wnd, msg, wParam, lParam );
            } 
        }

		// COMMAND MSG?
		//if ( HIWORD(wParam) <= 1 )
        if ( msg == WM_COMMAND )
        {
            if ( cmdMap_.count(LOWORD(wParam)) > 0 )
            {
				IMsgMapHandler* handler = cmdMap_[LOWORD(wParam)];
				return (*handler)( wnd, msg, wParam, lParam );
            }
        }

		// ALL OTHER WINDOWS MSGS
        if ( msgMap_.count(msg) > 0 )
        {
			IMsgMapHandler* handler = msgMap_[msg];
			return (*handler)( wnd, msg, wParam, lParam );
        }
		handled = false;
		return 0;
    }

    void addMsgHandler(UINT i, IMsgMapHandler* fp)
    {
		msgMap_.insert(std::make_pair(i, fp));
    }

    void addCmdHandler(UINT i, IMsgMapHandler* fp)
    {
        cmdMap_.insert(std::make_pair(i, fp));
    }

    void addNotifyIdHandler(UINT i, IMsgMapHandler* fp)
    {
		notifyIdMap_.insert(std::make_pair(i, fp));
    }

	void addNotifyCodeHandler(UINT i, IMsgMapHandler* fp)
    {
		notifyCodeMap_.insert(std::make_pair(i, fp));
    }

protected:

    std::map<UINT,IMsgMapHandler*>	msgMap_;
    std::map<UINT,IMsgMapHandler*>	cmdMap_;
    std::map<UINT,IMsgMapHandler*>	notifyCodeMap_;
	std::map<UINT,IMsgMapHandler*>	notifyIdMap_;

};




/////////////////////////////////////////////////////////////////

template<class T>
MsgMap<T,typename T::BaseWindowType>& msgMap()
{
	return mol::singleton<MsgMap<T,typename T::BaseWindowType>>();
}


} //end namespace mol

#endif