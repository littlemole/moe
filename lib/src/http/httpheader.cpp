#include "http/httpheader.h"
#include "util/istr.h"
#include <sstream>

namespace mol {


HttpHeaders::HttpHeaders()
{
	cmd_   = "GET";
	path_  = "/";
	proto_ = "HTTP/1.0";
}

HttpHeaders::HttpHeaders( const std::string& cmd, const std::string& path)
{
	cmd_    = cmd;
	path_   = path;
	proto_  = "HTTP/1.0";
}

HttpHeaders::HttpHeaders( const std::string& cmd, const std::string& path, const std::string& proto)
{
	cmd_    = cmd;
	path_   = path;
	proto_  = proto;
}

const std::string HttpHeaders::getCode()
{
	return code_;
}

const std::string HttpHeaders::getStatus()
{
	return status_;
}

void HttpHeaders::setStatus( const std::string& status)
{
	status_ = status;
}

void HttpHeaders::setCode( const std::string& code)
{
	code_ = code;
}

const std::string  HttpHeaders::getAction()
{
   std::string ret = cmd_ + " ";
   ret += path_ + " ";
   ret += proto_;
   return ret;
}

const std::string HttpHeaders::getCmd()
{
	return cmd_;
}

void HttpHeaders::setCmd( const std::string& str)
{
	cmd_ = str;
}

const std::string HttpHeaders::getPath()
{
	return path_;
}

void HttpHeaders::setPath( const std::string& str)
{
	path_ = str;
}

const std::string HttpHeaders::getProto()
{
	return proto_;
}
void HttpHeaders::setProto( const std::string& str)
{
	proto_ = str;
}


void HttpHeaders::setAction( const std::string& str)
{
   cmd_   = "";
   path_  = "/";
   proto_ = "HTTP/1.0";


   // get cmd string
   size_t pos = str.find(' ');
   if ( pos != std::string::npos )
   {
		cmd_ = str.substr(0,pos);
   }
   else
   {
		cmd_ = str;
		return;
   }

   pos = str.find_first_not_of( ' ', pos );
   if ( pos == std::string::npos )
		return;

   // get path string
   size_t p = str.find(' ',pos);
   if ( p != std::string::npos )
   {
		path_ = trim(str.substr(pos,p-pos)); 
   }
   else
   {
		path_ = trim(str.substr(pos));
		return;
   }

   // get proto string
   pos = str.find_first_not_of( ' ', p );
   if ( pos == std::string::npos )
		return;

   proto_ = str.substr(pos);
}

void HttpHeaders::setResponse( const std::string& str)
{
   code_   = "";
   status_ = "";
   proto_  = "HTTP";

    // PROTO
    size_t p = str.find(" ");
    if ( p == std::string::npos )
		return;
    proto_ = trim(str.substr(0,p));

    p = str.find_first_not_of(" ",p);
    // next space
    size_t pos = str.find(" ",p);
    // Code / Status
    if ( pos == std::string::npos )
    {
        code_   = trim(str.substr(p));
        status_ = "";
    }
    else
    {
        code_   = trim(str.substr(p,pos-p));
        status_ = trim(str.substr(pos+1));
    }
}


std::string HttpHeaders::Headers()
{
	if ( code_ == "" )
		return RequestHeaders();
	else
		return ResponseHeaders();
}

std::string HttpHeaders::getResponse()
{
	return getProto() + " " + getCode() + " " + getStatus();
}

std::string HttpHeaders::ResponseHeaders()
{
	return getProto() + " " + getCode() + " " + getStatus() + "\r\n" + getHeaders();
}



std::string HttpHeaders::RequestHeaders()
{
	return getAction() + "\r\n" + getHeaders();
}

std::string  HttpHeaders::getHeaders()
{
    std::string tmp = "";
    for ( HttpHiterator hit = begin(); hit != end(); hit++ )
    {
        tmp += hit->first;
        tmp += ": ";
        tmp += hit->second;
        tmp += "\r\n";
    }
    return tmp;
}

std::string HttpHeaders::getHeader( const std::string& str )
{
    std::string tmp = trim(str);
	tmp = mol::str::string2lower(str);
    for ( HttpHiterator hit = begin(); hit != end(); hit++ )
    {
        std::string s = mol::str::string2lower(hit->first);
        if ( s == tmp )
        {
            s = mol::str::string2lower(hit->second);
            return s;
        }
    }
    return "";
}

HttpHiterator HttpHeaders::iterator( const std::string& str )
{
    std::string tmp = trim(str);
	tmp = mol::str::string2lower(str);
    for ( HttpHiterator hit = begin(); hit != end(); hit++ )
    {
		std::string s = mol::str::string2lower(hit->first);
        if ( s == tmp )
        {
			return hit;
        }
    }
    return end();
}


void HttpHeaders::del( HttpHiterator hit)
{
	list_.erase(hit);
}

bool HttpHeaders::del( const std::string& str )
{
    HttpHiterator hit = iterator(str);
    if ( hit != end() )
    {
        del(hit);
        return true;
    }
    return false;
}

bool HttpHeaders::del( const std::string& str, const std::string& val )
{
	for ( HttpHiterator hit = begin(); hit != end(); hit++)
    {
        if ( strcasecmp(str.c_str(),hit->first.c_str()) == 0 )
        {
            if ( strcasecmp(val.c_str(),hit->second.c_str()) == 0 )
            {
                del(hit);
                return true;
            }
        }
    }
    return false;
}

void HttpHeaders::add( const HttpHeader& h )
{
    if ( h.first.size() > 0 )
		list_.push_back(h);
}

void HttpHeaders::add( const std::string& key, const std::string& val )
{
	add( mol::HttpHeader(key,val) );
}

void HttpHeaders::set( const std::string& key, const std::string& val )
{
    if ( key.size() > 0 )
	{
		del(key);
		add(key,val);
	}
}


HttpHiterator HttpHeaders::begin()
{
	return list_.begin();
}

HttpHiterator HttpHeaders::end()
{
	return list_.end();
}

bool HttpHeaders::isConnect()
{
    std::string tmp = getCmd();
    return strcasecmp(tmp.c_str(),"CONNECT") == 0;
}

bool HttpHeaders::contentLengthIsKnown()
{
    std::string tmp = getHeader("Content-Length");
    if ( tmp != "")
		return true;
    return false;
}


void HttpHeaders::contentLength( int len )
{
	std::ostringstream oss;
	oss << len;
	set("Content-Length",oss.str());
}

int HttpHeaders::contentLength()
{
    std::string tmp = getHeader("Content-Length");
    if ( tmp != "")
    {
        tmp = trim(tmp);
        return atoi(tmp.c_str());
    }
    return 0;
}

void HttpHeaders::contentType(const std::string& c)
{
	add( mol::HttpHeader("content-type",c));
}

std::string HttpHeaders::contentEncoding()
{
	return mol::str::string2lower(getHeader("Content-Encoding"));
}

std::string HttpHeaders::transferEncoding()
{
	return mol::str::string2lower(getHeader("Transfer-Encoding"));
}

std::string HttpHeaders::contentType()
{
	return mol::str::string2lower(getHeader("Content-Type"));
}

std::string HttpHeaders::connection()
{
	return mol::str::string2lower(getHeader("Connection"));
}

bool HttpHeaders::wantShutDown()
{
    std::string tmp = connection();
    if ( strcasecmp( tmp.c_str(), "close" ) == 0 )
		return true;
    return false;
}


bool HttpHeaders::keepAlive()
{
    std::string tmp = connection();
    if ( strcasecmp( tmp.c_str(), "keep-alive" ) == 0 )
		return true;
    return false;
}

} // end namespace mol
