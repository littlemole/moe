#include "xml/document.h"


//////////////////////////////////////////////////////////////////////
//Document impl
//////////////////////////////////////////////////////////////////////

namespace mol {

Document::Document()
{
	root_.document_ = this;
	root_.parent_   = 0;

//	encoding      = "UTF-8";
//	version       = "1.0";
//	standalone    = "no";
}

Document::~Document()
{
}

DocumentType Document::doctype()
{
	return docType_;
}

Element*  Document::documentElement()
{
    return &root_;
}

void  Document::documentElement(Element* r)
{
	root_ = *r;
}

std::string Document::toString()
{
	//std::string ret = "<?xml version=\"" + version + "\" encoding=\"" + encoding + "\" standalone=\"" + standalone + "\" ?>\r\n";
	return root_.innerXml();
}

Element* Document::parse( const std::string& src )
{
    return 0;
}

Element* Document::parse( Element* root_, const std::string& src )
{
    return 0;
}

Node* Document::createNode( mol::Node::NodeType t, mol::Node* parent, const std::string& name, const std::string& value )
{
    if ( name.size() == 0 && value.size() == 0)
        return 0;
	return new mol::Node( this, parent, t, name, value);
}

Element* Document::createElement( const std::string& name)
{
    if ( name.size() == 0 )
        return 0;
	return new mol::Element( this, name );
}

Element* Document::createElementNS( const std::string& name, const std::string& ns)
{
    if ( name.size() == 0 )
        return 0;
	mol::Element* e = new mol::Element( this, name );
	e->setAttribute("xmlns",ns);
	return e;
}

Text* Document::createTextNode( const std::string& value)
{
    if ( value.size() == 0 )
        return 0;
	return new mol::Text( this, value );
}

void Document::clear()
{
	root_.clear();
}

void Document::clear( Element* el)
{
	el->childNodes()->nodes_.clear();
}

}

