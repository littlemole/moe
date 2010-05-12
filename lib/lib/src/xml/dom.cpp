#include "xml/dom.h"
#include <sstream>
#include "xml/document.h"
#include "util/x.h"
#include "util/str.h"

namespace mol {


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Node
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

Node::Node  (Document* pD,  mol::Node* p, mol::Node::NodeType t, const std::string& name, const std::string& value)
    : attribs_(this)
{
    init();
    parent_    = p;
    document_  = pD;
    nodename_  = name;
    nodevalue_ = xmlentities_encode(value);
    type_      = t;
}

Node* Node::cloneNode()
{
    Node* n = new Node;
    *n = *this;
    return n;
}

Node& Node::operator=( Node& n )
{
    clear();

    // NO! Doc stays intact
    //_pDoc		= n._pDoc;
    //_parent	= n._parent;
    nodevalue_  = n.nodevalue_;
    type_	   = n.type_;
    nodename_   = n.nodename_;
    isalone_	   = n.isalone_;

    for ( int i = 0; i < n.childNodes()->length(); i++)
    {
        Node* c = n.childNodes()->item(i)->cloneNode();
        appendChild(c);
    }
    for ( int i = 0; i < n.attributes()->length(); i++)
    {
        Node* a = n.attributes()->item(i);
        attributes()->add( a->nodeName(), a->nodeValue() );
    }
    return *this;
}

// erases children_
void Node::clear()
{
    children_.clear();
}

void Node::init()
{
    isalone_	= true;
    document_	= 0;
    parent_		= 0;
    nodename_	= "";
    nodevalue_	= "";
}

Document*  Node::ownerDocument()
{
    return document_;
}



const std::string& Node::nodeName()
{
    return nodename_;
}

void Node::nodeName(const std::string& s )
{
    nodename_ = s;
}

std::string Node::nodeValue()
{
    return xmlentities_decode(nodevalue_);
}

void Node::nodeValue(const std::string& s )
{
    nodevalue_ = xmlentities_encode(s);
}

Node::NodeType Node::nodeType()
{
    return type_;
}

void Node::nodeType(NodeType t)
{
    type_ = t;
}

bool Node::isAlone()
{
    return isalone_;
}

void Node::isAlone(bool b)
{
    isalone_ = b;
}
std::string	Node::prefix()
{
    size_t pos = nodename_.find(":");
    if ( (pos != std::string::npos ) && ( pos > 0) )
        return nodename_.substr(0,pos);
    return "";
}

std::string	Node::localname()
{
    size_t pos = nodename_.find(":");
    if ( (pos != std::string::npos ) && ( pos > 0) )
        return nodename_.substr(pos+1);
    return nodename_;
}

std::string	Node::namespaceURI()
{
    if ( prefix() == "" )
        return defaultNamespace();
    return getNSfromPrefix(prefix());
}

Node*  Node::parentNode()
{
    return parent_;
}

std::string  Node::getNSfromPrefix(const std::string& prefix)
{
    mol::Node* parent_ = parentNode();
    if ( parent_ )
        return parent_->getNSfromPrefix(prefix);
    return "";
}

std::string  Node::getPrefixFromNS(const std::string& ns)
{
    mol::Node* parent_ = parentNode();
    if ( parent_ )
        return parent_->getPrefixFromNS(ns);
    return "";
}
std::string  Node::defaultNamespace()
{
    mol::Node* parent_ = parentNode();
    if ( parent_ )
        return parent_->defaultNamespace();
    return "";
}



/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Attr
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


Attr::Attr()
{
    type_		 = Node::ATTRIBUTE;
    nodename_    = "";
    nodevalue_	 = "";
    quote        = 0;
}

Attr::Attr( const std::string& name, const std::string& value )
{
    type_		 = Node::ATTRIBUTE;
    nodename_    = name;
    nodevalue_	 = xmlentities_encode(value);
    quote        = 0;
}

Attr::~Attr()
{}

Node* Attr::cloneNode()
{
    Attr* attribute = new Attr;
    *attribute = *this;
    return attribute;
}


Attr& Attr::operator=( const Attr& a )
{
    nodename_    = a.nodename_;
    nodevalue_	 = a.nodevalue_;
    type_		 = a.type_;
    quote        = a.quote;
    return *this;
}

std::string Attr::text()
{
    std::string ret = nodename_;
    if ( (nodevalue_ != "") || quote )
    {
        ret += "=";
    }
    if ( quote )
        ret += quote;
    ret += nodevalue_;
    if ( quote )
        ret += quote;
    return ret;
}


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// NamedNodeMap
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

NamedNodeMap::NamedNodeMap(mol::Node* p) : parent_(p) {};

NamedNodeMap::~NamedNodeMap()
{
    clear();
}

void NamedNodeMap::clear ()
{
    for ( std::list<Attr*>::iterator it = attributes_.begin();
        it != attributes_.end(); it++)
    {
        delete *it;
    }
    attributes_.clear();
}

Attr* NamedNodeMap::item( const std::string& index, const std::string& ns )
{
    for ( std::list<Attr*>::iterator it = attributes_.begin();
        it != attributes_.end(); it++)
    {
        if ( (*it)->localname() == index )
            if ( parent_->getNSfromPrefix((*it)->prefix()) == ns )
                return (*it);
    }
    return 0;
}

Attr* NamedNodeMap::item(const std::string& index)
{
    for ( std::list<Attr*>::iterator it = attributes_.begin();
        it != attributes_.end(); it++)
    {
        if ( (*it)->nodeName() == index )
            return (*it);
    }
    return 0;
}

Attr* NamedNodeMap::item(int index)
{
    int i = 0;
    for ( std::list<Attr*>::iterator it = attributes_.begin();
        it != attributes_.end(); it++)
    {
        if ( i == index )
            return (*it);
        i++;
    }
    return 0;
}

int NamedNodeMap::length()
{
    return (int)attributes_.size();
}

Attr* NamedNodeMap::operator[](const std::string& index)
{
    return item(index);
}

void NamedNodeMap::add(const std::string& name, const std::string& value )
{
    Attr* att = new Attr(name,value);
    attributes_.push_back(att);
}

void NamedNodeMap::add(const std::string& name)
{
    add( name, "");
}

void NamedNodeMap::erase( const std::string& name )
{
    for ( std::list<Attr*>::iterator it = attributes_.begin();
        it != attributes_.end(); it++)
    {
        if ( (*it)->nodeName() == name )
        {
            delete *it;
            attributes_.erase(it);
            return;
        }
    }
}

void NamedNodeMap::erase( int index )
{
    int i = 0;
    for ( std::list<Attr*>::iterator it = attributes_.begin();
        it != attributes_.end(); it++)
    {
        if ( i == index )
        {
            delete *it;
            attributes_.erase(it);
            return;
        }
        i++;
    }
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Element
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


Element::Element  () 
{
    init(); 
}

Element::Element  (Document* pD, const std::string& name)
{
    init();
    document_  = pD;
    nodename_  = name;
    nodevalue_ = "";
    type_      = Node::ELEMENT;
}

Element::Element  (Document* pD,  mol::Element* p, const std::string& name)
{
    init();
    parent_    = p;
    document_  = pD;
    nodename_  = name;
    nodevalue_ = "";
    type_      = Node::ELEMENT;
}

Element::Element  (Document* pD,  mol::Element* p, mol::Node::NodeType t, const std::string& name)
{
    init();
    parent_    = p;
    document_  = pD;
    nodename_  = name;
    nodevalue_ = "";
    type_      = t;
}

Element::~Element ()
{
}

Node* Element::cloneNode()
{
    Element* element = new Element;
    *element = *this;
    return element;
}

Element& Element::operator=(  Element& n )
{
    clear();

    // NO! Doc stays intact
    //_pDoc		= n._pDoc;
    //_parent	= n._parent;
    nodevalue_  = n.nodevalue_;
    type_	   = n.type_;
    nodename_   = n.nodename_;
    isalone_	   = n.isalone_;

    for ( int i = 0; i < n.childNodes()->length(); i++)
    {
        Node* c = n.childNodes()->item(i)->cloneNode();
        appendChild(c);
    }
    for ( int i = 0; i < n.attributes()->length(); i++)
    {
        Node* a = n.attributes()->item(i);
        attributes()->add( a->nodeName(), a->nodeValue() );
    }
    return *this;
}


bool Node::hasChildNodes()
{
    return children_.length() > 0;
}

bool Node::hasAttributes()
{
    return attribs_.length() > 0;
}

Node*  Node::nextSibling()
{
    if (!parent_)
        return 0;
    NodeList* nodes_ = ((Element*)(parent_))->childNodes();
    if ( !nodes_ )
        return 0;
    int len = nodes_->length();
    for ( int i = 0; i < len; i++)
    {
        if ( nodes_->item(i) == this )
        {
            if ( i+1 < len )
            {
                return nodes_->item(i+1);
            }
        }
    }
    return 0;
}

Node*  Node::previousSibling()
{
    if (!parent_)
        return 0;
    NodeList* nodes_ = ((Element*)(parent_))->childNodes();
    if (!nodes_)
        return 0;

    if ( nodes_->item(0) == this )
        return 0;
    int len = nodes_->length();
    for ( int i = 1; i < len; i++)
    {
        if ( nodes_->item(i) == this )
        {
            return nodes_->item(i-1);
        }
    }
    return 0;
}

Node*  Node::firstChild()
{
    if ( children_.length() == 0 )
        return 0;
    return children_.item(0);
}

Node*  Node::lastChild()
{
    if ( children_.length() == 0 )
        return 0;	
    return children_.item(children_.length()-1);
}

NodeList* Node::childNodes()
{
    return &children_;
}

void Node::appendChild( Node* n )
{

    if ( n->nodeType() == mol::Node::UNDEFINED )
        return;

    n->document_  = document_;
    n->parent_    = this;
    children_.add(n);
}

void Node::removeChild(  Node* n )
{
    children_.erase(n);
}

void Node::replaceChild( Node* oldElement,Node* newElement )
{
    int len = children_.length();
    for ( int i = 0; i < len ; i++ )
    {
        if ( children_.item(i) == oldElement )
        {
            *oldElement = *newElement;
        }
    }
}

void Node::insertBefore( Node* beforeElement, Node* n )
{
    std::vector<Node*>::iterator element = children_.nodes_.begin();
    std::vector<Node*>::iterator it = element;
    it++;
    for ( it; it != children_.nodes_.end(); it++ )
    {
        if ( *it == beforeElement )
        {
            n->document_ = document_;
            n->parent_   = this;
            children_.nodes_.insert(it, n );
            return;
        }
        element++;
    }
}

void Node::insertAfter( Node* afterElement, Node* n )
{
    std::vector<Node*>::iterator it = children_.nodes_.begin();
    for ( it; it != children_.nodes_.end(); it++ )
    {
        if ( *it == afterElement )
        {
            it++;
            n->document_ = document_;
            n->parent_   = this;
            children_.nodes_.insert(it, n );
            return;
        }
    }
}
void  Element::removeAttribute(const std::string& a )
{
    attribs_.erase(a);
}

void Element::setAttribute(const std::string& key, const std::string& value )
{
    Attr* att = attribs_.item(key);
    if ( !att )
	{
        attribs_.add(key,value);		
	}
    else
        att->nodeValue(value);
	attribs_.item(key)->quote = '"';
}

std::string Element::attr(const std::string& key)
{
    Attr* att = attribs_.item(key);
    if ( !att )
        return "";
    else
        return att->nodeValue();
}

NamedNodeMap* Node::attributes()
{
    return &attribs_;
}

Attr* Element::getAttribute(int index)
{
    return attribs_.item(index);
}

Attr* Element::getAttribute( const std::string& name )
{
    return attribs_.item(name);
}

std::string Element::atts()
{
    std::string ret = "";
    int len = this->attributes()->length();
    for ( int i = 0; i< len; i++ )
    {
        Attr* att = this->attributes()->item(i);
        ret += " " + att->text();
    }
    return ret;
}

std::string Element::innerXml()
{
    std::string ret = "";
    int len = children_.length();
    for ( int i = 0 ; i < len; i++ )
    {
        Node* n = children_.item(i);
        if ( n->nodeType() == mol::Node::ELEMENT )
        {
            Element* e = (Element*)n;
            ret += e->outerXml();
        }
        else
        {
            ret += n->nodeValue();
        }
    }
    return ret;
}

void Element::innerXml(const std::string& s)
{
    if ( document_ )
    {
        children_.clear();
        Element* root = document_->parse( this, s);
    }
}

std::string Element::outerXml()
{
    std::string ret = "";
    if ( (type_ == Node::ELEMENT) )//|| (type_ == Node::SCRIPT) )
    {
        ret += "<" + nodename_;
        std::string as = atts();
        if ( as != "" )
        {
            ret += as;
        }
        bool b = true;
        if ( nodename_.size() > 0 && nodename_[0] == '/' )
            b = false;
        if ( (!hasChildNodes()) && (isAlone()) && b )//&& (document_->doctype() != mol::HTML) )
            ret += " /";
        ret += ">";
    }
    if ( (type_ == Node::TEXT)    || (type_ == Node::SCRIPT) || 
        (type_ == Node::COMMENT) || (type_ == Node::CDATA) )
    {
        ret += nodevalue_ ;
    }
    int len = children_.length();
    for ( int i = 0; i < len; i++)
    {
        ret += ((Element*)(children_.item(i)))->outerXml();
    }
    if ( hasChildNodes() || (!isAlone()) )
    {
        ret += "</" + nodename_ + ">";
    }
    return ret;
}

void Element::outerXml(const std::string& s)
{
    if ( document_ )
    {
        clear();
        Element* root = document_->parse( this, s);

        for ( int i = 0; i < children_.length(); i++ )
        {
            ((Element*)(parent_))->insertBefore(this,children_.item(i));
        }

        ((Element*)(parent_))->removeChild(this);
    }
}

std::string	Element::startTag()
{
    std::string ret = "<" + nodename_;
    ret += atts() + ">";
    return ret;
}

std::string	Element::endTag()
{
    std::string ret = "";
    if ( isAlone() )
        return ret;
    ret = "</"+nodename_+">";
    return ret;
}

Element*  Element::getElementById(const std::string& id )
{
    return getElementById("id",id);
}

Element*  Element::getElementById(const std::string& idKey, const std::string& idValue )
{
    int l = children_.length();
    for ( int i = 0; i < l; i++ )
    {
        mol::Element* n = (Element*)(children_.item(i));
        mol::Attr* att = n->getAttribute(idKey);
        if (att)
        {
            if ( att->nodeValue() == idValue )
                return n;
        }
    }
    for ( int i = 0; i < l; i++ )
    {
        mol::Node* n =  children_.item(i);
        if ( n->nodeType() == Node::ELEMENT )
        {
            mol::Element* el =  (Element*)n;
            Element* e = el->getElementById(idKey, idValue);
            if (e)
                return e;
        }
    }
    return 0;	
}

Element*  Element::getElementByName(const std::string& name)
{
    return getElementById("name",name);
}

NodeList  Element::getElementsByTagName(const std::string& tag)
{
    NodeList nodes_;
    nodes_.bDetach_ =true;
    getElementsByTagNameWalker(tag,nodes_);
    return nodes_;
}

NodeList Element::getElementsByTagNameQ(const std::string& tag, const std::string& ns )
{
    NodeList nodes_;
    nodes_.bDetach_ =true;
    getElementsByTagNameWalkerQ(tag,ns,nodes_);
    return nodes_;
}

Element*  Element::getElementByTagName(const std::string& tag)
{
    NodeList nodes_;
    nodes_.bDetach_ =true;
    getElementsByTagNameWalker(tag,nodes_);
    if ( nodes_.length() > 0 )
        return (mol::Element*)(nodes_.item(0));
    return 0;
}

Element* Element::getElementByTagNameQ(const std::string& tag, const std::string& ns )
{
    NodeList nodes_;
    nodes_.bDetach_ =true;
    getElementsByTagNameWalkerQ(tag,ns,nodes_);
    if ( nodes_.length() > 0 )
        return (mol::Element*)(nodes_.item(0));
    return 0;
}
void  Node::getElementsByTagNameWalker(const std::string& tag, mol::NodeList& nodes_ )
{
    int l = children_.length();
    for ( int i = 0; i < l; i++ )
    {
        mol::Node* n = children_.item(i);
        if ( n->nodeType() == mol::Node::ELEMENT || n->nodeType() == mol::Node::SCRIPT  )
        {
            mol::Element* e = (Element*)n;
            if ( e->nodeName() == tag )
                nodes_.add(e);
            if ( e->hasChildNodes() )
                e->getElementsByTagNameWalker(tag,nodes_);
        }
    }
}

void  Node::getElementsByTagNameWalkerQ(const std::string& tag, const std::string& ns, mol::NodeList& nodes_ )
{
    int l = children_.length();
    for ( int i = 0; i < l; i++ )
    {
        mol::Node* n = children_.item(i);
        if ( n->nodeType() == mol::Node::ELEMENT )
        {
            mol::Element* e = (Element*)n;
            std::string name = e->localname();
            if ( (e->localname() == tag) && (e->namespaceURI() == ns) )
                nodes_.add(e);
            if ( e->hasChildNodes() )
                e->getElementsByTagNameWalkerQ(tag,ns,nodes_);
        }
    }
}

std::string  Element::getNSfromPrefix(const std::string& prefix)
{
    std::string lookup = "xmlns";
    if ( prefix != "" )
    {
        lookup += ":";
        lookup += prefix;
    }

    mol::Attr* att = getAttribute(lookup);
    if ( att )
    {
        return att->nodeValue();
    }
    mol::Node* parent_ = parentNode();
    if ( parent_ )
        return parent_->getNSfromPrefix(prefix);
    return "";
}

std::string  Element::getPrefixFromNS(const std::string& ns)
{
    for ( int i = 0; i < attribs_.length(); i++)
    {
        mol::Attr* att = attribs_.item(i);
        std::string name =  att->nodeName();
        if ( name.size() > 5 )
            if ( name.substr(0,6) == "xmlns:" )
            {
                if ( att->nodeValue() == ns )
                {
                    return name.substr(6);
                }
            }
    }
    mol::Node* parent_ = parentNode();
    if ( parent_ )
        return parent_->getPrefixFromNS(ns);
    return "";
}
std::string  Element::defaultNamespace()
{
    mol::Attr* att = getAttribute("xmlns");
    if ( att )
    {
        return att->nodeValue();
    }
    mol::Node* parent_ = parentNode();
    if ( parent_ )
        return parent_->defaultNamespace();
    return "";
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Node Collection
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

NodeList::NodeList(const NodeList& n)
    : bDetach_ (false)
{
    *this = n;
}

NodeList::~NodeList()
{
    if ( bDetach_ )
        return;
    clear();
}

NodeList& NodeList::operator=(const NodeList& nl) 
{
    nodes_   = nl.nodes_;
	bDetach_ = nl.bDetach_;	
	return *this;
}

void NodeList::clear()
{
    for ( std::vector<Node*>::iterator it = nodes_.begin();
        it != nodes_.end(); it++)
    {
        delete *it;
    }
    nodes_.clear();
}


Node* NodeList::item(int index)
{
    return (Element*)(nodes_[index]);
}

int   NodeList::length() const
{
    return (int)nodes_.size();
}

Node* NodeList::operator[](int index)
{
    return item(index);
}

void  NodeList::add   (Node* n)
{
    nodes_.push_back(n);
}

void NodeList::erase(Node* n )
{
    for ( std::vector<Node*>::iterator it = nodes_.begin(); it != nodes_.end(); it++ )
    {
        if ( *it == n )
        {
            delete *it;
            nodes_.erase(it);
            return;
        }
    }
}

Element*  NodeList::getChildByName(const std::string& name )
{
    int l = length();
    for ( int i = 0; i < l; i++ )
    {
        mol::Node* n = item(i);
        if ( n->localname() == name )
        {
            if ( n->nodeType() == Node::ELEMENT )
                return (Element*)n;
        }
    }
    return 0;
}

NodeList  NodeList::getChildrenByName(const std::string& name )
{
    NodeList nodes_;
    nodes_.bDetach_ =true;
    int l = length();
    for ( int i = 0; i < l; i++ )
    {
        mol::Node* n = item(i);
        if ( n->nodeType() == mol::Node::ELEMENT )
        {
            if ( n->localname() == name )
                nodes_.add(n);
        }
    }
    return nodes_;
}

Element*  NodeList::getChildByNameNS(const std::string& name, const std::string& ns )
{
    int l = length();
    for ( int i = 0; i < l; i++ )
    {
        mol::Node* n = item(i);
        if ( (n->localname() == name) && (n->getNSfromPrefix(n->prefix()) == ns) )
        {
            if ( n->nodeType() == Node::ELEMENT )
                return (Element*)n;
        }
    }
    return 0;
}

NodeList  NodeList::getChildrenByNameNS(const std::string& name, const std::string& ns )
{
    NodeList nodes_;
    nodes_.bDetach_ =true;
    int l = length();
    for ( int i = 0; i < l; i++ )
    {
        mol::Node* n = item(i);
        if ( n->nodeType() == mol::Node::ELEMENT )
        {
            if ( (n->localname() == name) && (n->getNSfromPrefix(n->prefix()) == ns) )
                nodes_.add(n);
        }
    }
    return nodes_;
}


//////////////////////////////////////////////////////////////////////
//  TEXT
//////////////////////////////////////////////////////////////////////

// Construction/Destruction
Text::Text  ()
{
    type_  = mol::Node::TEXT;
    document_  = 0;
    parent_    = 0;
    nodevalue_ = "";
}

Text::Text  (Document* pD, const std::string& value)
{
    type_  = mol::Node::TEXT;
    document_  = pD;
    parent_    = 0;
    nodevalue_ = xmlentities_encode(value);
}

Text::Text  (Document* pD, mol::Element* parent_, const std::string& value)
{
    type_  = mol::Node::TEXT;
    document_  = pD;
    parent_    = parent_;
    nodevalue_ = xmlentities_encode(value);
}


} //end namespace mol
