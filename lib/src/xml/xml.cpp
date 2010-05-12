#include "xml/xml.h"

namespace mol {

XMLDocument::XMLDocument()
{
	docType_ = mol::XML;
	root_.nodeType(mol::Node::ELEMENT);
}

XMLDocument::~XMLDocument()
{

}

Element* XMLDocument::parse( const std::string& src )
{
    clear();
    return parser_.parse(this,src);
}

Element* XMLDocument::parse( Element* root, const std::string& src )
{
    return parser_.parse(this,root,src);
}


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// XMLParser Impl
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

XMLParser::XMLParser()
{}

XMLParser::~XMLParser()
{
}

//////////////////////////////////////////////////////////////////////
// parse function
//////////////////////////////////////////////////////////////////////
Element* XMLParser::parse( Document* doc, const std::string& input )
{
   return parse( doc, doc->documentElement(), input );
}

//////////////////////////////////////////////////////////////////////
// workhorse
//////////////////////////////////////////////////////////////////////

Element* XMLParser::parse( Document* d, Element* root, const std::string& input )
{
	doc_    = d;
	parent_ = root;
	if ( !Expat::parse( input.c_str(), (int)(input.size()) ) )
		return 0;
	return root;
}

void XMLParser::character (const XML_Char *s, int len)
{	
	std::string t = mol::trim ( std::string( s,len) );
	if ( t.size() == 0 )
		return;

	mol::Node* c = parent_->lastChild();
	if ( c && ( c->nodeType() == mol::Node::TEXT ) )
	{
		std::string txt = parent_->lastChild()->nodeValue();
		parent_->lastChild()->nodeValue(txt + t);
	}
	else
	{
		mol::Text* t = doc_->createTextNode( std::string(s,len) );
		parent_->appendChild(t);
	}
}

void XMLParser::start(const XML_Char* el, const XML_Char **attr)
{
	mol::Element* e = doc_->createElement( el );
	parent_->appendChild(e);
	const XML_Char** c = attr;
	while ( *c )
	{
		std::string key((char*)(*c));
		std::string val((char*)(*(c+1)));

		e->setAttribute( key,val );
		c+=2;
	}
	parent_ = e;
}

void XMLParser::end(const XML_Char* el)
{
	if ( parent_->hasChildNodes() )
		parent_->isAlone(false);
	parent_ = (Element*)(parent_->parentNode());
}


}

