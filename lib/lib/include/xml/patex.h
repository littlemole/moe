#ifndef MOL_PATEX_EXPAT_DEF
#define MOL_PATEX_EXPAT_DEF

#ifndef XML_DYNAMIC
#define XML_STATIC
#endif

#include <expat.h>

namespace mol {

class Expat
{
public:
	// con-/destruct
	Expat()
	{
		p_ = XML_ParserCreate(NULL);
		XML_SetElementHandler( p_, startHandler, endHandler);
		XML_SetCharacterDataHandler( p_, charHandler);
		XML_SetUserData( p_, (void*)this);
	}
	virtual ~Expat()
	{
		XML_ParserFree(p_);
	}
	// use again
	bool reset()
	{
		bool ret = (XML_ParserReset( p_, 0 )) == 0 ? false : true;
		XML_SetElementHandler( p_, startHandler, endHandler);
		XML_SetCharacterDataHandler( p_, charHandler);
		XML_SetUserData( p_, (void*)this);
		return ret;
	}
	// parse it!
	bool parse( const char* what, int len, int isFinal = true )
	{
		return (XML_Parse( p_, what, len, isFinal )) == 0 ? false : true;
	}
	// info
	int line()
	{
		return XML_GetCurrentLineNumber(p_);
	}

	const XML_Char* err()
	{
		return XML_ErrorString(XML_GetErrorCode(p_));
	}

	// handlers

	virtual void character (const XML_Char *s, int len)=0;
	virtual void start(const XML_Char* el, const XML_Char **attr)=0;
	virtual void end(const XML_Char* el)=0;

	// handler-imp
	static void charHandler (void *userData, const XML_Char *s, int len)
	{
		((Expat*)userData)->character(  s, len);
	}
	static void startHandler(void *userData, const XML_Char *el, const XML_Char **attr)
	{
		((Expat*)userData)->start(el, attr);
	}
	static void endHandler(void *userData, const XML_Char *el)
	{
		((Expat*)userData)->end(el);
	}

protected:
	// the expat object
	XML_Parser p_;
};

}

#endif

