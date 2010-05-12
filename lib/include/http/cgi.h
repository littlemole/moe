#ifndef DEF_MOL_CGI_VARS_DEF_GUARD_
#define DEF_MOL_CGI_VARS_DEF_GUARD_

#include <iostream>
#include <map>

namespace mol {

#ifndef WIN32

//! CGI class. construct one instance at program
//! startup and input will be gathered
class Cgi
{
public:
    //! constructor will gather CGI input
    Cgi();

    //! Method of HTTP Request (GET,POST)
    std::string method;
    //! Content Type of HTTP Request
    std::string contentType;
    //! raw POST input, if any
    std::string input;

    //! get environment variable (eg HTTP_USER_AGENT)
    std::string env( const std::string& key );

	//! input vars
	std::map<std::string,std::string> map;
    const std::string& operator[] (const std::string& indx);

private:
    const std::string& getInput();
    void makeMap();
};

#endif

} // end namespace mol

#endif
