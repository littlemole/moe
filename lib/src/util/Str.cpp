
#include "util/str.h"
#include <sstream>
#include <iostream>

namespace mol {

std::string unix2dos( const std::string& in )
{
	std::ostringstream out;
	if ( in[0] == '\n' )
		out << "\r";

	out << in[0];

	size_t p = 1;
	size_t len = in.size();

	while( ( p < len ) )
	{
		if ( in[p] == '\n' )

			if ( in[p-1] != '\r' )
			{
				out << "\r";
			}

		out << in[p];
		p++;
	}
	return out.str();
}

std::string dos2unix( const std::string& in )
{
    std::ostringstream out;
    size_t p = 0;
    size_t len = in.size();

    while( ( p < len ) )
    {
        if ( in[p] == '\r' )

            if ( p+1 < len )

                if ( in[p+1] == '\n' )
                {
                    p++;
                    continue;
                }

        out << in[p];
        p++;
    }
    return out.str();
}

std::wstring unix2dos( const std::wstring& in )
{
	std::wostringstream out;
	if ( in[0] == L'\n' )
		out << L"\r";
	out << in[0];
	size_t p = 1;
	size_t len = in.size();
	while( ( p < len ) )
	{
		if ( in[p] == L'\n' )
			if ( in[p-1] != L'\r' )
			{
				out << L"\r";
			}
		out << in[p];
		p++;
	}
	return out.str();
}

std::wstring dos2unix( const std::wstring& in )
{
    std::wostringstream out;
    size_t p = 0;
    size_t len = in.size();
    while( ( p < len ) )
    {
        if ( in[p] == L'\r' )
            if ( p+1 < len )
                if ( in[p+1] == L'\n' )
                {
                    p++;
                    continue;
                }
        out << in[p];
        p++;
    }
    return out.str();
}

std::string trim ( const std::string& in )
{
    size_t first = in.find_first_not_of(" \r\n\t");
    size_t last  = in.find_last_not_of(" \r\n\t");
    if ( (first == mol::string::npos) && (last == mol::string::npos) )
            return "";
    size_t from  = ( first != mol::string::npos ) ? first : 0 ;
    size_t to    = ( last  != mol::string::npos ) ? last-from+1  : in.size()-from ;
    return in.substr(from,to);
}


std::wstring trim ( const std::wstring& in )
{
    size_t first = in.find_first_not_of(L" \r\n\t");
    size_t last  = in.find_last_not_of(L" \r\n\t");
    if ( (first == mol::string::npos) && (last == mol::string::npos) )
            return L"";
    size_t from  = ( first != mol::string::npos ) ? first : 0 ;
    size_t to    = ( last  != mol::string::npos ) ? last-from+1  : in.size()-from ;
    return in.substr(from,to);
}

std::string xmlentities_encode(const std::string& in )
{
    std::ostringstream out;
    size_t p = 0;
    size_t len = in.size();
    while( ( p < len ) )
    {
        switch ( in[p] )
        {
            case '&' :
            {
                out << "&amp;";
                break;
            }
            case '<' :
            {
                out << "&lt;";
                break;
            }
            case '>' :
            {
                out << "&gt;";
                break;
            }
            default :
            {
                out << in[p];
                break;
            }
        }
        p++;
    }
    return out.str();
}

std::string xmlentities_decode( const std::string& str )
{
    std::ostringstream out;
    size_t len = str.size();
    for ( size_t i = 0; i < len; i++ )
    {
        if ( str[i] == '&' )
        {
			if ( str.substr(i,4) == "&lt;" )
            {
				out << "<";
                i+=3;
            }
            else
			if ( str.substr(i,4) == "&gt;" )
            {
                out << ">";
                i+=3;
            }
            else
	        if ( str.substr(i,5) == "&amp;" )
            {
                out << "&";
                i+=4;
            }
		}
        else
        {
			out << str[i];
        }
    }
    return out.str();
}





std::wstring xmlentities_encode(const std::wstring& in )
{
    std::wostringstream out;
    size_t p = 0;
    size_t len = in.size();
    while( ( p < len ) )
    {
        switch ( in[p] )
        {
            case L'&' :
            {
                out << L"&amp;";
                break;
            }
            case L'<' :
            {
                out << L"&lt;";
                break;
            }
            case L'>' :
            {
                out << L"&gt;";
                break;
            }
            default :
            {
                out << in[p];
                break;
            }
        }
        p++;
    }
    return out.str();
}

std::wstring xmlentities_decode( const std::wstring& str )
{
    std::wostringstream out;
    size_t len = str.size();
    for ( size_t i = 0; i < len; i++ )
    {
        if ( str[i] == L'&' )
        {
			if ( str.substr(i,4) == L"&lt;" )
            {
				out << L"<";
                i+=3;
            }
            else
			if ( str.substr(i,4) == L"&gt;" )
            {
                out << L">";
                i+=3;
            }
            else
	        if ( str.substr(i,5) == L"&amp;" )
            {
                out << L"&";
                i+=4;
            }
		}
        else
        {
			out << str[i];
        }
    }
    return out.str();
}

std::string str2rtf( const std::string& in )
{
    std::ostringstream out;
    size_t p = 0;
    size_t len = in.size();
    while( ( p < len ) )
    {
        if ( (in[p] == '\\') || (in[p] == '{') || (in[p] == '}') )
        {
                out << "\\";
        }
        out << in[p];
        p++;
    }
    return out.str();
}


std::wstring str2rtf( const std::wstring& in )
{
    std::wostringstream out;
    size_t p = 0;
    size_t len = in.size();
    while( ( p < len ) )
    {
        if ( (in[p] == L'\\') || (in[p] == L'{') || (in[p] == L'}') )
        {
                out << L"\\";
        }
        out << in[p];
        p++;
    }
    return out.str();
}

std::wstring nl2rtf( const std::wstring& in )
{
    std::wostringstream out;

	size_t p = 0;
    size_t len = in.size();
    while( ( p < len ) )
    {
        if ( in[p] == L'\n' )
        {
                out << L"\\par";
        }
        out << in[p];
        p++;
    }
    return out.str();
}

std::string nl2rtf( const std::string& in )
{
    std::ostringstream out;

    size_t p = 0;
    size_t len = in.size();
    while( ( p < len ) )
    {
        if ( in[p] == '\n' )
        {
                out << "\\par";
        }
        out << in[p];
        p++;
    }
    return out.str();
}

mol::string tab2space( const mol::string& in )
{
    mol::ostringstream out;
    size_t p = 0;
    size_t len = in.size();
    while( ( p < len ) )
    {
        if ( in[p] == _T('\t') )
        {
                out << _T(" ");
        }
        else
        {
                out << in[p];
        }
        p++;
    }
    return out.str();
}

mol::string skip2spaces( const mol::string& in )
{
    mol::ostringstream out;
    size_t p = 0;
    size_t len = in.size();
    while( ( p < len ) )
    {
		if ( in[p] == _T(' ') )
			if ( p+1 < len )
				if ( in[p+1] == _T(' ') )
                {
					p++;
                    continue;
                }
        out << in[p];
        p++;
    }
    return out.str();
}

mol::string skipNewLines( const mol::string& in )
{
    mol::ostringstream out;
    size_t p = 0;
    size_t len = in.size();
    while( ( p < len ) )
    {
        if ( in[p] != _T('\n') )
        {
			out << in[p];
        }
        p++;
	}
    return out.str();
}

void htmlWrap(mol::string& str, int wrap )
{
    size_t pos = 0;
    size_t p   = 0;

    str += _T(" ");

    while ( (p = str.find_first_of(_T(" "),pos)) != mol::string::npos )
    {
        size_t len = p - pos;
        if ( (int)len > wrap )
        {
            str.insert(p,_T("<br>"));
            pos = p+4;
        }
        else
            pos = p+1;

        if (pos >= str.size() )
            break;
    }
	if ( (!str.empty()) && (str[str.size()-1] == ' ' ) )
		str.erase(str.size()-1,1);
}

mol::string nl2br( const mol::string& in )
{
    mol::ostringstream out;
    size_t p = 0;
    size_t len = in.size();
    while( ( p < len ) )
    {
        if ( in[p] == _T('\n') )
        {
            out << _T("<br>\n");
        }
        else
        {
            out << in[p];
        }
        p++;
    }
    return out.str();
}


// URLencode helpers
inline char c2x(const char &x) {         return x > 9 ? x + 55: x + 48; }

inline char x2c ( unsigned char* in)
{
	register char digit;
	digit = ( (*in) >= 'A' ? (((*in) & 0xdf) - 'A')+10 : ((*in) - '0'));
	digit *= 16;
	in++;
	digit += ((*in) >= 'A' ? (((*in) & 0xdf) - 'A')+10 : ((*in) - '0'));
	return(digit);
}

std::string URLencode(const std::string& in)
{
    std::string out("");
    const size_t nLen = in.size() + 1;

    unsigned char* pInBuf  =(unsigned char*)in.data();
    unsigned char* pOutTmp = NULL;
    unsigned char* pInTmp  = NULL;

	mol::cbuff buf(nLen  * 3 - 2);

    pInTmp  = pInBuf;
    pOutTmp = (unsigned char*)(char*)buf;
    while (*pInTmp)
    {
        unsigned char c = *((unsigned char*)pInTmp);
        int i = 0;
        i += c;
        if( (isalnum(i)))
        *pOutTmp++ = *pInTmp;
        else
        if( isspace(i) && ((i!='\n') && (i!='\r')) )
			*pOutTmp++ = '+';
        else
        {
            *pOutTmp++ = '%';
            *pOutTmp++ = c2x(*pInTmp>>4);
            *pOutTmp++ = c2x(*pInTmp%16);
        }
        pInTmp++;
    }
    *pOutTmp = '\0';
	out = buf.toString();
    return out;
}

std::string URLdecode( const std::string& in )
{
	size_t len = in.size();
	unsigned char* inBuff = (unsigned char*)(in.c_str());

	mol::cbuff buf(len+1);
	unsigned char* outBuff = (unsigned char*)(char*)buf;

    while( *inBuff )
    {
	    if ( *inBuff == '%' )
        {
            inBuff++;
			*outBuff = x2c(inBuff);
            inBuff++;
        }
        else
        {
			*outBuff=*inBuff;
        }
        outBuff++;
        inBuff++;
    }
    *outBuff =0;
	return buf.toString();
}

static const std::string base64_chars = 
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";


static inline bool is_base64(unsigned char c) 
{
  return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) 
{
  std::string ret;
  int i = 0;
  int j = 0;
  unsigned char char_array_3[3];
  unsigned char char_array_4[4];

  while (in_len--) {
    char_array_3[i++] = *(bytes_to_encode++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for(i = 0; (i <4) ; i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }

  if (i)
  {
    for(j = i; j < 3; j++)
      char_array_3[j] = '\0';

    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;

    for (j = 0; (j < i + 1); j++)
      ret += base64_chars[char_array_4[j]];

    while((i++ < 3))
      ret += '=';

  }

  return ret;

}

std::string base64_decode(std::string const& encoded_string) {

  size_t in_len = encoded_string.size();
  size_t i = 0;
  size_t j = 0;
  size_t in_ = 0;

  unsigned char char_array_4[4], char_array_3[3];
  std::string ret;

  while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
    char_array_4[i++] = encoded_string[in_]; in_++;
    if (i ==4) {
      for (i = 0; i <4; i++)
        char_array_4[i] = (unsigned char)base64_chars.find(char_array_4[i]);

      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

      for (i = 0; (i < 3); i++)
        ret += char_array_3[i];
      i = 0;
    }
  }

  if (i) {
    for (j = i; j <4; j++)
      char_array_4[j] = 0;

    for (j = 0; j <4; j++)
      char_array_4[j] = (unsigned char)base64_chars.find(char_array_4[j]);

    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

    for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
  }

  return ret;
}

COLORREF hex2rgb( const mol::string& h )
{
	if ( h.empty())
		return 0;

	mol::string in(h);

	if ( in.size() < 6 )
	{
		in.append( mol::string(6-in.size(),'0') );
	}

	if ( in[0] != '#' )
	{
		mol::string tmp(_T("#"));
		tmp.append(in);
		in = tmp;
	}

	std::string hex(mol::tostring(in));
    char buf[3];
    buf[2]=0;

    int r,g,b;
    r = g = b = 0;

    buf[0] = hex[1];
    buf[1] = hex[2];
    sscanf( buf, "%x", &r );

    buf[0] = hex[3];
    buf[1] = hex[4];
    sscanf( buf, "%x", &g );

    buf[0] = hex[5];
    buf[1] = hex[6];
    sscanf( buf, "%x", &b );

    return RGB(r,g,b);
}

mol::string rgb2hex( COLORREF col )
{
    static char ret[12];
    char buf[12];

    wsprintfA(buf,"%06X",col);

    ret[0] = '#';
    (ret[1]) = (buf[4]);
    (ret[2]) = (buf[5]);
    (ret[3]) = (buf[2]);
    (ret[4]) = (buf[3]);
    (ret[5]) = (buf[0]);
    (ret[6]) = (buf[1]);
    ret[7] = 0;
    return mol::toString(ret);
}

} //end namespace mol
