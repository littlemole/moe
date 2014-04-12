#ifndef MOL_TCP_STREAM_BUF_DEF_GUARD_DEF_
#define MOL_TCP_STREAM_BUF_DEF_GUARD_DEF_

#include <iostream>
#include <algorithm>


namespace mol {

/////////////////////////////////////////////////////////////////////////
// Unbuffered StreamBuf
/////////////////////////////////////////////////////////////////////////

template<class charT, class charTraits = std::char_traits<charT> >
class UnbufferedStreamBuf 
	: public std::basic_streambuf< charT, std::char_traits<charT> >	
{
public:

    typedef std::basic_streambuf< charT, std::char_traits<charT> >	base_type;

	UnbufferedStreamBuf() 
		: takeFromBuf_(false)
	{}

protected:

	// IOStream implementation
	int sync()
	{
		return std::basic_streambuf< charT, std::char_traits<charT> >::sync();
	}

	typename base_type::int_type overflow(typename base_type::int_type c )
	{
		if (!base_type::traits_type::eq_int_type(c, base_type::traits_type::eof()))
		{
			if (this->unbuffered_write(base_type::traits_type::to_char_type(c)) < 0 )
				return base_type::traits_type::eof();
			else
				return c;
		}
		
		return base_type::traits_type::not_eof(c);
	}

	typename base_type::int_type uflow()
	{
		if ( takeFromBuf_ )
		{        
			takeFromBuf_ = false;
			return base_type::traits_type::to_int_type(charBuf_);
		}        
		else
		{
			typename base_type::char_type c;

			if ( this->unbuffered_read(&c) < 0 )
				return base_type::traits_type::eof();
			else
			{
				charBuf_ = c;
				return base_type::traits_type::to_int_type(c);
			}        
		}        
	}

	typename base_type::int_type underflow()
	{
		if ( takeFromBuf_ )
		{        
			return base_type::traits_type::to_int_type(charBuf_);
		}        
		else
		{
			typename base_type::char_type c;

			if ( this->unbuffered_read(&c) < 0 )
				return base_type::traits_type::eof();
			else
			{
				takeFromBuf_ = true;
				charBuf_ = c;
				return base_type::traits_type::to_int_type(c);
			}
		}        
	}

	typename base_type::int_type pbackfail(typename base_type::int_type c)
	{
		if ( !takeFromBuf_ )
		{     
			if (!base_type::traits_type::eq_int_type(c, base_type::traits_type::eof()))
				charBuf_ = base_type::traits_type::to_char_type(c);

			takeFromBuf_ = false;
			return base_type::traits_type::to_int_type(charBuf_);
		}        
		else
		{
			return base_type::traits_type::eof();
		}        
	}

protected:

	// Unbuffered read / write
	virtual int unbuffered_read (char * c) = 0;
	virtual int unbuffered_write(char c) = 0;

private:
	
	// prohibit copying and assingment
    UnbufferedStreamBuf(const UnbufferedStreamBuf&);
    UnbufferedStreamBuf& operator = (const UnbufferedStreamBuf&);

    typename base_type::char_type charBuf_;
    bool takeFromBuf_;
};

/////////////////////////////////////////////////////////////////////////
// buffered StreamBuf
/////////////////////////////////////////////////////////////////////////

template<class charT, class charTraits = std::char_traits<charT> >
class BufferedStreamBuf 
	: public std::basic_streambuf< charT, std::char_traits<charT> >	
{
public:

    typedef std::basic_streambuf< charT, std::char_traits<charT> >	base_type;

	BufferedStreamBuf() 
	{
		// set output buffer
		this->setp(buffer_,buffer_+bufSize_);
		// set input buffer
		this->setg(buffer_+pbSize_,buffer_+pbSize_,buffer_+pbSize_);
	}

	~BufferedStreamBuf() 
	{}

protected:

	// IOStream implementation
	
	std::streamsize xsputn( const typename base_type::char_type * s, std::streamsize n)
	{
		if ( n < base_type::epptr() - base_type::pptr() )
		{
			size_t len = (size_t)(n*sizeof(typename base_type::char_type));
			memcpy(base_type::pptr(),s,len);
			base_type::pbump((int)n);
			return n;
		}
		for ( std::streamsize i=0; i<n; i++ )
		{
			if ( base_type::traits_type::eq_int_type( base_type::sputc(s[i]), base_type::traits_type::eof() ) )
				return i;
		}
		return n;
	}

	int sync()
	{
		return buf_out();
	}

	typename base_type::int_type overflow(typename base_type::int_type c = base_type::traits_type::eof() )
	{
		if ( buf_out() < 0 )
			return base_type::traits_type::eof();

		if (!base_type::traits_type::eq_int_type(c, base_type::traits_type::eof()))
			return base_type::sputc(c);

		return base_type::traits_type::not_eof(c);
	}

	typename base_type::int_type underflow()
	{
		if ( base_type::gptr() < base_type::egptr() )
			return base_type::traits_type::to_int_type(*base_type::gptr());

		if ( buf_in() < 0 )
			return base_type::traits_type::eof();

		return base_type::traits_type::to_int_type(*base_type::gptr());

	}

	typename base_type::int_type pbackfail(typename base_type::int_type c)
	{
		if ( base_type::gptr() != base_type::eback() )
		{     
			base_type::gbump(-1);
			
			if (!base_type::traits_type::eq_int_type(c, base_type::traits_type::eof()))
				*base_type::gptr() = base_type::traits_type::to_char_type(c);

			return base_type::traits_type::not_eof(c);
		}        
		return base_type::traits_type::eof();
	}

protected:

	// buffered read / write
	virtual int buffered_read (char* c, int n) { return 0; }
	virtual int buffered_write(char* c, int n) { return 0; }

private:

	// prohibit copying and assingment
    BufferedStreamBuf(const BufferedStreamBuf&);
    BufferedStreamBuf& operator = (const BufferedStreamBuf&);

	int buf_out()
	{
		int cnt = (int)(base_type::pptr() - base_type::pbase());
		int retval = buffered_write(buffer_,cnt);
		base_type::pbump(-cnt);
		return retval;
	}

	int buf_in()
	{
		std::streamsize numPutbacks = std::min( (int)(base_type::gptr()-base_type::eback()),pbSize_);

		memcpy( buffer_ + (pbSize_-numPutbacks) * sizeof(typename base_type::char_type),
			    base_type::gptr() - numPutbacks * sizeof(typename base_type::char_type),
				(size_t)(numPutbacks * sizeof(typename base_type::char_type)) );

		int retval = buffered_read( buffer_ + pbSize_ * sizeof(typename base_type::char_type), bufSize_ - pbSize_ );

		if ( retval <= 0 )
		{
			base_type::setg(0,0,0);
			return -1;
		}
		base_type::setg( buffer_ + pbSize_ - numPutbacks,
			  buffer_ + pbSize_, buffer_ + pbSize_ + retval );
		return retval;
	}

	static const int bufSize_ = 1024;
	static const int pbSize_;//  = 4;
	typename base_type::char_type buffer_[bufSize_];

    typename base_type::char_type charBuf_;
    bool takeFromBuf_;
};
/*
template<class charT, class charTraits>
const int BufferedStreamBuf<charT, charTraits>::bufSize_ = 1024;
*/
template<class charT, class charTraits>
const int BufferedStreamBuf<charT, charTraits>::pbSize_ = 4;

/////////////////////////////////////////////////////////////////////////

} // end namespace mol

#endif

