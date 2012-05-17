#include "ssh/str.h"

namespace mol {
namespace ssh {

bool operator<(const string& src, const string& compare)
{
	return strcmp(src.data(),compare.data()) < 0;
}

ssh::wstring utf82wstring( const char* in, const size_t size )
{
	int len = ::MultiByteToWideChar( CP_UTF8, 0, in, (int)size, 0, 0 );
	wchar_t* buf = new wchar_t[len];
	int r = ::MultiByteToWideChar( CP_UTF8, 0, in, (int)in, buf, len );
	ssh::wstring out(buf,len);
	::ZeroMemory((void*)buf,len*sizeof(wchar_t));
	delete[] buf;
	return out;
}


ssh::string wstring2utf8( const wchar_t* in, const size_t size)
{
	int len = ::WideCharToMultiByte( CP_UTF8, 0, in, (int)size, 0, 0,0,0 );
	char* buf = new char[len];
	int r = ::WideCharToMultiByte( CP_UTF8, 0, in,(int)size, buf, len,0,0 );
	ssh::string out(buf,len);
	::ZeroMemory((void*)buf,len);
	delete[] buf;
	return out;
}

/////////////////////////////////////////////////////////////////////

string::string() 
	: data_(0), size_(0)
{}

string::string( const string& s) 
	: data_(0),size_(0) 
{ 
	alloc(s.data(),s.size());
}

string::string( string&& rhs) 
	: data_(rhs.data_),size_(rhs.size_) 
{ 
	rhs.data_ = 0;
	rhs.size_ = 0;
}

string::string( const char* s) 
	: data_(0),size_(0) 
{
	alloc(s,strlen(s));
}

string::string( const char* s, size_t size) 
	: data_(0),size_(size) 
{
	alloc(s,size);
}

string::~string() 
{ 
	dispose();
}

const char* string::data() const { return data_; }
const size_t string::size() const { return size_; };

void string::clear()
{
	if ( data_ && size_ )
	{
		::ZeroMemory((void*)data_,size_+1);
	}
}

void string::dispose()
{
	clear();
	if(data_)
	{
		delete[] data_;
	}
	data_ = 0;
	size_ = 0;
}

string& string::operator=( const string& rhs )
{
	if ( this == &rhs )
	{
		return *this;
	}

	dispose();

	size_ = rhs.size();
	alloc(rhs.data(),rhs.size());

	return *this;
}


string& string::operator=( string&& rhs )
{
	if ( this == &rhs )
	{
		return *this;
	}

	dispose();

	size_ = rhs.size_;
	data_ = rhs.data_;

	rhs.size_ = 0;
	rhs.data_ = 0;
	return *this;
}

bool string::operator<(const string& compare)
{
	return strcmp(data_,compare.data()) != 0;
}

void string::alloc( const char* data, size_t s )
{
	size_ = s;
	if ( data && size_ )
	{
		data_ = new char[size_+1];
		clear();
		memcpy((void*)data_,(void*)data,size_);
	}
}


bool operator<(const string& src, const string& compare);

/////////////////////////////////////////////////////////////////////

wstring::wstring() 
	: data_(0), size_(0) 
{}

wstring::wstring( const wstring& s) 
	: data_(0), size_(0) 
{ 
	alloc(s.data(),s.size());
}


wstring::wstring( wstring&& rhs) 
	: data_(rhs.data_), size_(rhs.size_) 
{ 
	rhs.data_ = 0;
	rhs.size_ = 0;
}

wstring::wstring( const wchar_t* s) 
	: data_(0),size_(0) 
{
	alloc(s,wcslen(s));
}

wstring::wstring( const wchar_t* s, size_t size) 
	: data_(0),size_(0) 
{
	alloc(s,size);
}

wstring::~wstring() 
{ 
	dispose();
}

const wchar_t* wstring::data() const { return data_; }
const size_t wstring::size() const { return size_; };

void wstring::clear()
{
	if ( data_ && size_ )
	{
		::ZeroMemory((void*)data_,size_+1);
	}
}

void wstring::dispose()
{
	clear();
	delete[] data_;
	data_ = 0;
	size_ = 0;
}

wstring& wstring::operator=( const wstring& rhs )
{
	if ( this == &rhs )
	{
		return *this;
	}

	dispose();

	size_ = rhs.size();
	alloc(rhs.data(),rhs.size());

	return *this;
}


wstring& wstring::operator=( wstring&& rhs )
{
	if ( this == &rhs )
	{
		return *this;
	}

	dispose();

	size_ = rhs.size_;
	data_ = rhs.data_;

	rhs.size_ = 0;
	rhs.data_ = 0;
	return *this;
}

void wstring::alloc( const wchar_t* data, size_t s )
{
	size_ = s;
	if ( data && size_ )
	{
		data_ = new wchar_t[size_+1];
		clear();
		memcpy((void*)data_,(void*)data,size_*sizeof(wchar_t));
	}
}


stringBuffer::stringBuffer()
	:data_(0),size_(512),used_(0)
{
	data_ = new char[size_+1];
	clear();
}

stringBuffer::~stringBuffer()
{
	clear();
	delete[] data_;
}

void stringBuffer::clear()
{
	::ZeroMemory((void*)data_,size_+1);
}

const char* stringBuffer::data()  const { return data_; }
const size_t stringBuffer::size() const { return used_; };

void stringBuffer::append(char* data)
{
	size_t s = strlen(data);
	append(data,s);
}

void stringBuffer::append(const char* data, size_t s)
{
	if ( used_ + s > size_ )
	{
		size_t newsize = ((used_ + s ) / 512) +512;
		char* tmp = new char[newsize+1];
		::ZeroMemory((void*)tmp,newsize+1);
		memcpy(tmp,data_,used_);		
		memcpy(tmp+used_,data,s);
		clear();
		delete[] data_;
		data_ = tmp;
		size_ = newsize;
		used_ = used_ + s;
	}
	else
	{
		memcpy(data_+used_,data,s);
		used_ = used_ + s;
	}
}

stringBuffer::stringBuffer(const stringBuffer& ) 
{
}

stringBuffer& stringBuffer::operator=(const stringBuffer& )
{
	return *this;
}


} // end namespace ssh
} // end namespace mol

