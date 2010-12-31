#ifndef _MOL_DEF_GUARD_DEFINE_HTTP_READER_DEF_GUARD_
#define _MOL_DEF_GUARD_DEFINE_HTTP_READER_DEF_GUARD_

#include "http/httpheader.h"
#include "util/gzip.h"
#include <sstream>

namespace mol {

//typedef std::basic_stream< char, std::char_traits<char> > mstream;
//typedef std::basic_istream< char, std::char_traits<char> > instream;
//typedef std::basic_ostream< char, std::char_traits<char> > outstream;


template<class charT, class Traits>
std::string 
get_line_paranoid( std::basic_istream<charT,Traits>& is, const char delim = '\n' )
{
	std::ostringstream oss;

	typename std::basic_istream<charT,Traits>::char_type c = 0;

	while ( is )
	{
		c = is.get();
		if ( std::basic_istream<charT,Traits>::traits_type::eq_int_type( c, std::basic_istream<charT,Traits>::traits_type::eof() ) )
			break;
		oss << c;
		if ( c == delim )
			break;
	}
	return oss.str();
}


class AbstractBodyReader
{
public:

	AbstractBodyReader();
	AbstractBodyReader( AbstractBodyReader* chain );
	virtual ~AbstractBodyReader();

	virtual const std::string& raw() ;
	virtual size_t read( std::istream& in) = 0;
	virtual size_t read( std::stringstream& in) { return 0; }

	std::string toString() 
	{
		return body_;
	}

	
	size_t chain( std::stringstream& in)
	{
		size_t n = chain_->read(in);
		if ( n )
		{
			body_ = chain_->toString();
			return body_.size();
		}
		return 0;
	}

protected:

	std::string body_;
	AbstractBodyReader* chain_;
};


class EofBodyReader : public AbstractBodyReader
{
public:

	EofBodyReader();
	EofBodyReader(AbstractBodyReader* chain);
	virtual ~EofBodyReader();

	virtual size_t read( std::istream& in);	
	virtual const std::string& raw() ;
};


class ContentLengthBodyReader : public AbstractBodyReader
{
public:

	ContentLengthBodyReader( size_t len);
	ContentLengthBodyReader(AbstractBodyReader* chain);
	ContentLengthBodyReader(AbstractBodyReader* chain, size_t len);
	virtual ~ContentLengthBodyReader();

	virtual size_t read( std::istream& in);
	virtual const std::string& raw() ;

private:
	size_t len_;
};



class ChunkedBodyReader : public AbstractBodyReader
{
public:

	ChunkedBodyReader();
	ChunkedBodyReader(AbstractBodyReader* chain);
	virtual ~ChunkedBodyReader();

	virtual size_t read( std::istream& in);
	virtual const std::string& raw();


private:

	size_t readChunk(std::istream& in, std::ostream& out, std::ostream& raw_out);
	size_t readChunkSize(std::istream& in, std::ostream& raw_out );
	void readChunkTrailers(std::istream& in, std::ostream& raw_out);

	size_t len_;
	std::string raw_;
};


class GzipBodyReader : public AbstractBodyReader
{
public:

	GzipBodyReader(size_t s);
	GzipBodyReader();
	virtual ~GzipBodyReader();

	virtual size_t read( std::istream& in);
	virtual size_t read( std::stringstream& in);
	virtual const std::string& raw();

private:
	size_t len_;
	std::string raw_;
};


class DeflateBodyReader : public AbstractBodyReader
{
public:

	DeflateBodyReader(size_t s);
	DeflateBodyReader();
	virtual ~DeflateBodyReader();

	virtual size_t read( std::istream& in);
	virtual size_t read( std::stringstream& in);
	virtual const std::string& raw();

private:
	size_t len_;
	std::string raw_;
};

}

#endif