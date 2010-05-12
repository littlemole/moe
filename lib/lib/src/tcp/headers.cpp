#include "tcp/headers.h"
#include "util/str.h"

//! for Non-Win32 Systems, assume POSIX
#ifndef WIN32
#endif

//! Win32 Systems
#ifdef WIN32
#define strcasecmp _stricmp
#endif

namespace mol {

int Headers::read(TCPsocket& socket)
{
    action_                        = "";
    int len                        = 0;

    len = socket.readLine(action_);

    if ( len < 1 )
            return -1;

    action_ = trim(action_);

    std::string line;
    while ( (line != "\r\n") && (line != "\n") && (len > 0) )
    {
        line = "";
        len  = socket.readLine( line );
        if ( len < 0 )
                return -1;

        if ( len > 0 )
        {
            if ( strcasecmp(line.substr(0,17).c_str(),"Proxy-Connection:") == 0 )
				continue;

            int p = line.find(":");
            Header h;
            if ( p != std::string::npos )
            {
                h.first  = trim(line.substr(0,p));
                h.second = trim(line.substr(p+1));
            }
            else
            {
                h.first  = trim(line);
                h.second = "";
            }
            if ( h.first.size() > 0 )
				add(h);
        }
    }

    if ( len == 0 )
		return 0;
    return 1;
}


const std::string& Headers::getAction()
{
	return action_;
}

std::string  Headers::getHeaders()
{
    std::string tmp = "";
    for ( Hiterator hit = begin(); hit != end(); hit++ )
    {
        tmp += hit->first;
        tmp += ": ";
        tmp += hit->second;
        tmp += "\r\n";
    }
    tmp += "\r\n";
    return tmp;
}

std::string Headers::getHeader( const std::string& str )
{
    std::string tmp = trim(str);
    tmp = string2lower(str);
    for ( Hiterator hit = begin(); hit != end(); hit++ )
    {
        std::string s = string2lower(hit->first);
        if ( s == tmp )
        {
            s = string2lower(hit->second);
            return s;
        }
    }
    return "";
}

Hiterator Headers::iterator( const std::string& str )
{
    std::string tmp = trim(str);
    tmp = string2lower(str);
    for ( Hiterator hit = begin(); hit != end(); hit++ )
    {
        std::string s = string2lower(hit->first);
        if ( s == tmp )
        {
			return hit;
        }
    }
    return end();
}


void Headers::del( Hiterator hit)
{
	list_.erase(hit);
}

bool Headers::del( const std::string& str )
{
    Hiterator hit = iterator(str);
    if ( hit != end() )
    {
        del(hit);
        return true;
    }
    return false;
}

bool Headers::del( const std::string& str, const std::string& val )
{
	for ( Hiterator hit = begin(); hit != end(); hit++)
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

void Headers::add( const Header& h )
{
    if ( h.first.size() > 0 )
		list_.push_back(h);
}

Hiterator Headers::begin()
{
	return list_.begin();
}

Hiterator Headers::end()
{
	return list_.end();
}

bool Headers::contentLengthIsKnown()
{
    //return contentLength() > 0;
    std::string tmp = getHeader("Content-Length");
    if ( tmp != "")
		return true;
    return false;
}

int Headers::contentLength()
{
    std::string tmp = getHeader("Content-Length");
    if ( tmp != "")
    {
        tmp = trim(tmp);
        return atoi(tmp.c_str());
    }
    return 0;
}

void Headers::setAction( const std::string& str)
{
   action_ = str;
}

std::string Headers::contentType()
{
	return string2lower(getHeader("Content-Type"));
}

std::string Headers::connection()
{
	return string2lower(getHeader("Connection"));
}

bool Headers::wantShutDown()
{
    std::string tmp = connection();
    if ( strcasecmp( tmp.c_str(), "close" ) == 0 )
		return true;
    return false;
}


bool Headers::keepAlive()
{
    std::string tmp = string2lower(getHeader("Connection"));
    if ( strcasecmp( tmp.c_str(), "keep-alive" ) == 0 )
		return true;
    return false;
}
/////////////////////////////////////////////////////////////////

int RequestHeaders::send(TCPsocket& socket)
{
	std::string tmp = toString();
	return socket.write(tmp);
}

const std::string&  RequestHeaders::getAction()
{
   std::string ret = cmd_ + " ";
   ret += path_ + " ";
   ret += proto_;
   return action_;
}

int  RequestHeaders::read(TCPsocket& socket)
{
    port_ = 80;
    int ret = Headers::read(socket);
    if ( ret < 0 )
		return -1;

    // CMD
    int p = action_.find(" ");
    if ( p == std::string::npos )
		return -1;
    cmd_ = trim(action_.substr(0,p));

    p = action_.find_first_not_of(" ",p);
    // next space
    int pos = action_.find(" ",p);
    // PROTO & URL
    std::string url = "";
    if ( pos != std::string::npos )
    {
        proto_ = trim(action_.substr(pos+1));
		url = action_.substr(p,pos-p);
    }
    else
    {
        proto_ = "";
        url = action_.substr(p);
    }

    // HOST
    p = url.find("http://");
    if ( p != std::string::npos )
    {
        std::string s = url.substr(p+7);
        int p = s.find("/");
        if ( p != std::string::npos )
        {
            path_  = trim(s.substr(p));
            host_ = trim(s.substr(0,p));
        }
        else
        {
            path_  = "/";
            host_  = s;
        }
    }
    else
    {
        host_ = "";
        path_ = url;
    }

    // Connect?
    if ( strcasecmp(cmd_.c_str(),"CONNECT") == 0 )
    {
		host_ = path_;
    }

    // PORT
    pos = host_.find(":");
    if ( pos != std::string::npos )
    {
        std::string tmp = host_.substr(pos+1);
        port_ = atoi(tmp.c_str());
        tmp  = host_.substr(0,pos);
        host_ = tmp;
    }
    return ret;
}

const std::string RequestHeaders::getCmd()
{
	return cmd_;
}

void RequestHeaders::setCmd( const std::string& str)
{
	cmd_ = str;
}

const std::string RequestHeaders::getHost()
{
	return host_;
}

void RequestHeaders::setHost( const std::string& str)
{
	host_ = str;
}

int RequestHeaders::getPort()
{
	return port_;
}

void RequestHeaders::setPort(int p)
{
	port_ = p;
}


const std::string RequestHeaders::getPath()
{
	return path_;
}

void RequestHeaders::setPath( const std::string& str)
{
	path_ = str;
}

const std::string RequestHeaders::getProto()
{
	return proto_;
}
void RequestHeaders::setProto( const std::string& str)
{
	proto_ = str;
}

bool RequestHeaders::isConnect()
{
    std::string tmp = getCmd();
    return strcasecmp(tmp.c_str(),"CONNECT") == 0;
}

std::string RequestHeaders::toString()
{
	return getCmd() + " " + getPath() + " " + getProto() + "\r\n" + getHeaders();
}
/////////////////////////////////////////////////////////////////

int ResponseHeaders::send(TCPsocket& socket)
{
	return socket.write(toString());
}

int  ResponseHeaders::read(TCPsocket& socket)
{
    int ret = Headers::read(socket);
    if ( ret < 0 )
	   return -1;

    // PROTO
    int p = action_.find(" ");
    if ( p == std::string::npos )
		return -1;
    proto_ = trim(action_.substr(0,p));

    p = action_.find_first_not_of(" ",p);
    // next space
    int pos = action_.find(" ",p);
    // Code / Status
    if ( pos == std::string::npos )
    {
        code_   = trim(action_.substr(p));
        status_ = "";
    }
    else
    {
        code_   = trim(action_.substr(p,pos-p));
        status_ = trim(action_.substr(pos+1));
    }
    return ret;
}

const std::string ResponseHeaders::getProto()
{
	return proto_;
}


const std::string ResponseHeaders::getCode()
{
	return code_;
}

const std::string ResponseHeaders::getStatus()
{
	return status_;
}

std::string ResponseHeaders::toString()
{
	return getProto() + " " + getCode() + " " + getStatus() + "\r\n" + getHeaders();
}

} // end namespace mol