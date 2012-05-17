#ifndef _MOL_COM_DLL_SSH_STR_DEF_DEFINE_GUARD_
#define _MOL_COM_DLL_SSH_STR_DEF_DEFINE_GUARD_

#include <util/str.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

namespace mol {
namespace ssh {

// secure strings - use as short as possible.
// secure strings will overwrite the occupied character data memory with zeros
// before releasing the memory
class string 
{
public:
	string();
	string( const string& s);
	string( string&& rhs);
	string( const char* s);
	string( const char* s, size_t size);
	~string();

	const char* data() const;
	const size_t size() const;

	void clear();
	void dispose();
	string& operator=( const string& rhs );
	string& operator=( string&& rhs );

	bool operator<(const string& compare);

private:

	void alloc( const char* data, size_t s );

	const char* data_;
	size_t      size_;
};


bool operator<(const string& src, const string& compare);

class wstring 
{
public:
	wstring();
	wstring( const wstring& s);
	wstring( wstring&& rhs);
	wstring( const wchar_t* s);
	wstring( const wchar_t* s, size_t size);
	~wstring(); 

	const wchar_t* data() const;
	const size_t size() const;

	void clear();
	void dispose();

	wstring& operator=( const wstring& rhs );
	wstring& operator=( wstring&& rhs );

private:

	void alloc( const wchar_t* data, size_t s );

	const wchar_t* data_;
	size_t      size_;
};

ssh::wstring utf82wstring( const char* in, const size_t size );
ssh::string wstring2utf8( const wchar_t* in, const size_t size);

class stringBuffer
{
public:
	stringBuffer();
	~stringBuffer();

	void clear();

	const char* data()  const;
	const size_t size() const;

	void append(char* data);
	void append(const char* data, size_t s);

private:

	stringBuffer(const stringBuffer& );
	stringBuffer& operator=(const stringBuffer& );

	char* data_;
	size_t size_;
	size_t used_;
};

} // end namespace ssh
} // end namespace mol


#endif