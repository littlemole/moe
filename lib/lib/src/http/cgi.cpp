#include "http/cgi.h"
#include <vector>
#include "util/str.h"

namespace mol {

#ifndef WIN32

Cgi::Cgi()
{
    method = env("REQUEST_METHOD");
    contentType = env("CONTENT_TYPE");
    getInput();
    if ( method == "GET" || method == "HEAD" || contentType == "application/x-www-form-urlencoded" )
    {
        makeMap();
    }
}

std::string Cgi::env (const std::string& key)
{
    std::string val = "";
    char* c = getenv(key.c_str());
    if (c)
            val = c;
    return val;
}

const std::string& Cgi::getInput()
{
    int content_length;
    if ( (method == "GET") || (method == "HEAD") )
    {
         input = env("QUERY_STRING");
    }
    else if ( method =="POST" )
    {
        if ( (content_length = atoi(env("CONTENT_LENGTH").c_str())) < 1 )
			return input;

        char* buf = new char[content_length+1];
        std::cin.read(buf,content_length);
        buf[content_length]='\0';
        input.assign(buf);
        delete buf;
    }
    return input;
}

void Cgi::makeMap()
{
    std::vector <std::string> v_tmp;

    int newPos, oldPos = 0;

    while ( (newPos = input.find('&', oldPos )) != std::string::npos )
    {
        v_tmp.push_back( input.substr( oldPos, newPos-oldPos ));
        oldPos = newPos+1;
    }
    v_tmp.push_back( input.substr( oldPos ));

    for ( std::vector<std::string>::iterator it = v_tmp.begin(); it != v_tmp.end(); it++)
    {
        int pos = 0;
        while ( (pos = it->find('=', pos )) != std::string::npos )
        {
            std::string key = it->substr(0,pos);
            std::string val = it->substr(pos);
            key = URLdecode(key);
            val = URLdecode(val);
            map[ key  ] = val;
            pos++;
        }
    }
}

#endif

}
