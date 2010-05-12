#ifndef MOL_ICONV_WRAPPER
#define MOL_ICONV_WRAPPER

#include <string>
//#include <wstring>
#include "iconv.h"

namespace std {
typedef std::basic_string <wchar_t> wstring;
};

namespace mol {

// encapsulates iconv API
// expects To and From Policy Classes to be like
// ICONV_DECLARE_CHARSET impl

template<class To, class From>
class IConv
{
public:
    typedef To   to;
    typedef From from;

    IConv ()
    {
		ict_ = iconv_open( To::code, From::code );
    }

    ~IConv()
    {
		iconv_close(ict_);
    }

    size_t conv( const char** in, size_t* s, char** out, size_t* l )
    {

#ifdef _WIN32
		const char** c = in;
#else
		char** c = (char**)in;
#endif

        return ::iconv( ict_, c, s, out, l );
     }

private:
     iconv_t                ict_;
};

// Converter Object for a specific Conversion
template<class ICONV>
class ICStr
{
public:
    typedef typename ICONV::to   to;
    typedef typename ICONV::from from;

    // raw constructor - expects pointer to src and size fo src
    ICStr ( typename from::type* input, int size )
		:buffer_(0)
    {
		convert(input,size);
    }

    // generic copy-from-other-ICStr constructor
    template<class I>
    ICStr ( I& icv )
            :buffer_(0)
	{
        typename I::to::type* input = icv.get();
        int size = icv.size();

        convert(input,size);
    }

    // use const char* as src and determine size with strlen
    ICStr ( const char* str )
		:buffer_(0)
    {
        typename from::type* input = (typename from::type*) (str);
        int size = strlen(str);

        convert(input,size);
    }

    // use const char* as src and determine size with wcslen
    ICStr ( const wchar_t* str )
		:buffer_(0)
    {
        typename from::type* input = (typename from::type*)(str);
        int size = wcslen(str)*sizeof(wchar_t);

        convert(input,size);
    }

    // use std::string as src
    ICStr ( const std::string& str )
		:buffer_(0)
    {
        typename from::type* input = (typename from::type*) (str.c_str());
        int size = str.size();

        convert(input,size);
	}

    // use std::wstring as src
    ICStr ( const std::wstring& str )
		:buffer_(0)
	{
        typename from::type* input = (typename from::type*)(str.c_str());
        int size = str.size()*sizeof(wchar_t);

        convert(input,size);
    }

	// destructor
    ~ICStr()
    {
        if (buffer_)
			delete[] buffer_;
	}

    // access converted buffer
    const typename to::type* get() const
    {
		return (typename to::type*)(buffer_);
    }

    // size in bytes
    const int size() const
    {
        return size_;
    }

    // convert to dest type
    operator typename to::type* ()
    {
		return this->get();
    }
    bool operator!()
    {
        return (buffer_ == 0);
    }

private:
    void convert ( typename from::type* input, int size )
    {
        // allocate enough mem for max size explosion
        // and add max size of terminating zero(s)
        // note that memset actually pre-terminates the string
        size_ = (size * 4) + sizeof(to::type);
        buffer_ = new char[size_];

        size_t s       = size;
        size_t l       = size_;

        const char* in = (const char*) input;

        char* out      = buffer_;
        size_t r       = icv_.conv( &in,&s, &out,&l );

        if ( r == -1 )
        {
            delete[] buffer_;
            buffer_ = 0;
        }
        size_ = out-buffer_;
        ::memset((void*)out,0,sizeof(to::type));
    }

	IConv<to,from>	icv_;
    char*           buffer_;
    int             size_;
};

//////////////////////////////////////////////////////////

// to declare a named charset in a header file
// ie: ICONV_DECLARE_CHARSET(utf8,const char)
#define ICV_DECLARE_CHARSET(name,typ) \
struct name \
{  \
    typedef typ type;   \
    static  const char code[]; \
}; \

//////////////////////////////////////////////////////////

// once in your source implement the declared charset,
// specifing encoding string
// ie: ICONV_IMPLEMENT_CHARSET(utf8,"UTF-8")
#define ICV_IMPLEMENT_CHARSET(name,c) const char name::code[]  = c;

//////////////////////////////////////////////////////////


// define String Converters from one to another encoding
// ie: ICONV_VONVERTER(utf8,utf16)
//
// gives you utf8_from_utf16 and utf16_from_uft8 classes
//

#define ICV_CONVERTER(to,from) \
typedef ICStr< IConv<to,from> > to##_from_##from; \
typedef ICStr< IConv<from,to> > from##_from_##to;


} // end namespace mol

#endif
