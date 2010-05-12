#ifndef _DEF_MOL_SELECTOR_DEF_
#define _DEF_MOL_SELECTOR_DEF_

#include "tcp/sockets.h"

namespace mol {

class Select
{
public:
    //! contructor resets FD_SETS
    Select()
    {
        FD_ZERO(&fd_read_);
        FD_ZERO(&fd_write_);
        FD_ZERO(&fd_ex_);
        n_ = 0;
    }

    //! call select with mil.sec (and seconds) to wait
    //! for any number of sockets to go
    int select( int usec = 0, int sec = 0 )
    {
		if ( (usec == 0) && (sec == 0) )
			return ::select( (int)n_, &fd_read_, &fd_write_, &fd_ex_, 0);
		timeout_.tv_sec=sec;
		timeout_.tv_usec=usec;
		return ::select( (int)n_, &fd_read_, &fd_write_, &fd_ex_, &timeout_);
    }

    //! set which Sockets to wait for an read event
    void setRead( SOCKET s)
    {
        FD_SET(s,&fd_read_);
        n_ = (unsigned int)s+1 > n_ ? s+1 : n_;
    }

    //! set which Sockets to wait for an write event
    void setWrite( SOCKET s)
    {
        FD_SET(s,&fd_write_);
        n_ = (unsigned int)s+1 > n_ ? s+1 : n_;
    }
    //! set which Sockets to wait for an exception event
    void setEx( SOCKET s)
    {
        FD_SET(s,&fd_ex_);
        n_ = (unsigned int)s+1 >n_ ? s+1 : n_;
    }

    //! check if socket is ready to read
    bool isReadSet( SOCKET s)
    {
	    return FD_ISSET(s,&fd_read_) != 0;
    }
    //! check if socket is ready to write
    bool isWriteSet( SOCKET s)
    {
        return FD_ISSET(s,&fd_write_) != 0;
    }
    //! check if socket got exception
    bool isExSet( SOCKET s)
    {
        return FD_ISSET(s,&fd_ex_) != 0;
    }

private:
    fd_set                fd_read_;
    fd_set                fd_write_;
    fd_set                fd_ex_;
    timeval               timeout_;
    unsigned long long    n_;
};

} // end namespace mol

#endif

