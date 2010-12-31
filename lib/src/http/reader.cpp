#include "http/reader.h"

namespace mol {

AbstractBodyReader::AbstractBodyReader()
	:chain_(0)
{}

AbstractBodyReader::AbstractBodyReader( AbstractBodyReader* chain )
	:chain_(chain)
{}

AbstractBodyReader::~AbstractBodyReader()
{
	delete chain_;
}

const std::string& AbstractBodyReader::raw()
{
	return body_;
}


EofBodyReader::EofBodyReader()
	:AbstractBodyReader(0)
{}

EofBodyReader::EofBodyReader(AbstractBodyReader* chain)
	:AbstractBodyReader(chain)
{}

EofBodyReader::~EofBodyReader()
{}

const std::string& EofBodyReader::raw() 
{
	if ( chain_ )
		return chain_->raw();
	return body_;
}

size_t EofBodyReader::read( std::istream& in)
{
	std::stringstream oss;

	const int BUFSIZE = 1024;
	char buf[BUFSIZE];

	size_t have = 0;
	while(in)
	{
		in.read(buf,BUFSIZE);
		size_t s = (size_t)in.gcount();
		oss.write(buf,s);
		have += s;
		if ( in.eof() )
			break;
	}

	if ( chain_ )
	{
		return chain( oss ); 
	}

	body_ = oss.str();
	return body_.size();
}



ContentLengthBodyReader::ContentLengthBodyReader( size_t len)
	: len_(len)
{}

ContentLengthBodyReader::ContentLengthBodyReader(AbstractBodyReader* chain)
	:AbstractBodyReader(chain),len_(0)
{}

ContentLengthBodyReader::ContentLengthBodyReader(AbstractBodyReader* chain, size_t len)
	:AbstractBodyReader(chain),len_(len)
{}

ContentLengthBodyReader::~ContentLengthBodyReader()
{}

const std::string& ContentLengthBodyReader::raw() 
{
	if ( chain_ )
		return chain_->raw();
	return body_;
}


size_t ContentLengthBodyReader::read( std::istream& in)
{
	std::stringstream oss;
	const int BUFSIZE = 1024;
	char buf[BUFSIZE];

	size_t have = 0;
	while(in && (have<len_) )
	{
		size_t want = (len_-have) > BUFSIZE ? BUFSIZE : len_ - have;

		in.read(buf,want);
		size_t s = (size_t)in.gcount();
		have += s;
		oss.write(buf,s);
		if ( in.eof() )
			break;
	}

	if ( chain_ )
	{
		return chain(oss);
	}
	body_ = oss.str();
	return body_.size();
}




ChunkedBodyReader::ChunkedBodyReader()
	:AbstractBodyReader(0)
{}

ChunkedBodyReader::ChunkedBodyReader(AbstractBodyReader* chain)
	: AbstractBodyReader(chain)
{}

ChunkedBodyReader::~ChunkedBodyReader()
{}

const std::string& ChunkedBodyReader::raw()
{
	return raw_;
}

size_t ChunkedBodyReader::read( std::istream& in)
{
	std::stringstream out;
	std::ostringstream raw_out;

	size_t have = 0;
	size_t s = 1;
	while (s)
	{
		s = readChunk(in,out,raw_out);
		have += s;
	}

	readChunkTrailers(in,raw_out);

	raw_ = raw_out.str();
	if ( chain_ )
	{
		return chain(out);
	}

	body_ = out.str();
	return body_.size();
}




size_t ChunkedBodyReader::readChunk(std::istream& in, std::ostream& out, std::ostream& raw_out)
{
	size_t len = readChunkSize(in,raw_out);

	if ( !len )
		return 0;

	const int BUFSIZE = 1024;
	char buf[BUFSIZE];

	size_t have = 0;
	while(in && (have < len) )
	{
		size_t want = (len-have) > BUFSIZE ? BUFSIZE : len - have;

		in.read(buf,want);
		size_t s = (size_t)in.gcount();
		have += s;
		out.write(buf,s);
		raw_out.write(buf,s);
		if ( in.eof() )
			break;
	}
	//swallow newline \r\n
	in.read(buf,2);
	raw_out.write(buf,2);
	return len;
}

size_t ChunkedBodyReader::readChunkSize(std::istream& in, std::ostream& raw_out )
{
	std::string line = get_line_paranoid(in);
	//std::getline(in,line);

	raw_out << line;

	std::string tmp;
	size_t pos = line.find(';');
	if ( pos == std::string::npos )
	{
		tmp = line;
	}
	else
	{
		tmp = line.substr(0,pos);
	}

	std::istringstream iss(tmp);
	size_t s;
	iss >> std::hex >> s;
	return s;
}

void ChunkedBodyReader::readChunkTrailers(std::istream& in, std::ostream& raw_out)
{
	std::string line;
	while ( 1 )
	{
		//std::getline(in,line);
		line = get_line_paranoid(in);
		if ( line.empty() )
			return;

		raw_out << line;

		if ( line == "\r\n" )
			return;
	}
}



GzipBodyReader::GzipBodyReader(size_t s)
	:len_(s)
{}


GzipBodyReader::GzipBodyReader()
	:len_(0)
{}

GzipBodyReader::~GzipBodyReader()
{}


const std::string& GzipBodyReader::raw()
{
	return raw_;
}


size_t GzipBodyReader::read( std::stringstream& in)
{
	raw_ = in.str();
	body_ = gunzip( raw_ );
	return body_.size();
}

size_t GzipBodyReader::read( std::istream& in)
{
	std::ostringstream raw_out;

	const int BUFSIZE = 1024;
	char buf[BUFSIZE];
	while(in)
	{
		in.read(buf,BUFSIZE);
		size_t s = (size_t) in.gcount();
		raw_out.write(buf,s);

		if ( in.eof() )
			break;
	}
	raw_ = raw_out.str();
	body_ = gunzip( raw_ );
	return body_.size();
}


DeflateBodyReader::DeflateBodyReader(size_t s)
	:len_(s)
{}


DeflateBodyReader::DeflateBodyReader()
	:len_(0)
{}

DeflateBodyReader::~DeflateBodyReader()
{}

const std::string& DeflateBodyReader::raw()
{
	return raw_;
}



size_t DeflateBodyReader::read( std::stringstream& in)
{
	raw_ = in.str();
	
	body_ = inflate( raw_ );
	if ( body_.empty() )
		body_ = inflate( raw_,15 );

	return body_.size();
}

size_t DeflateBodyReader::read( std::istream& in)
{
	std::ostringstream raw_out;

	const int BUFSIZE = 1024;
	char buf[BUFSIZE];
	while(in)
	{
		in.read(buf,BUFSIZE);
		size_t s = (size_t) in.gcount();
		raw_out.write(buf,s);
		if ( in.eof() )
			break;
	}

	raw_ = raw_out.str();

	body_ = inflate( raw_ );
	if ( body_.empty() )
	{
		body_ = inflate( raw_,15 );
	}
	return body_.size();
}


}
