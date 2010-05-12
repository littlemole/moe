#ifndef MOL_XML_DOM_PARSER_DEF
#define MOL_XML_DOM_PARSER_DEF

#include "document.h"
#include "patex.h"

namespace mol {

class XMLParser : public Expat
{
//	friend class mol::XMLDocument;

//private:
public:
    XMLParser();
    ~XMLParser();
    Element* parse( Document* doc_, const std::string& input );
    Element* parse(Document* doc_, Element* root, const std::string& input);

	// handlers

	virtual void character (const XML_Char *s, int len);
	virtual void start(const XML_Char* el, const XML_Char **attr);
	virtual void end(const XML_Char* el);


	mol::Element*				parent_;
	mol::Document*				doc_;
	//std::string					input;

};

class XMLDocument : public mol::Document 
{
friend class XMLParser;
public:
	    XMLDocument();
		virtual ~XMLDocument();
		Element* parse( const std::string& src );
		Element* parse( Element* root, const std::string& src );

private:
        XMLDocument& operator=( XMLDocument& p );				//nada
		XMLParser parser_;
};


}

#endif

