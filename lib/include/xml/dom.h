#ifndef MOL_DOM_PAT_DEF
#define MOL_DOM_PAT_DEF

#include <map>
#include <vector>
#include <list>
#include <string>
#include "util/str.h"
#include "util/x.h"

namespace mol {

///////////////////////////////////////////////////////////////////////////////

class Node;
class Attr;
class Element;
class Document;
enum  DocumentType { XML, HTML };
class NodeList;
class NamedNodeMap;

///////////////////////////////////////////////////////////////////////////////

class DOMException : public mol::X {};

///////////////////////////////////////////////////////////////////////////////

class NamedNodeMap
{
friend class Document;
public:
	NamedNodeMap(mol::Node* p);
    ~NamedNodeMap();

    int length();
	Attr* item(const std::string& index, const std::string& ns);
    Attr* item(const std::string& index);
    Attr* item(int index);
    Attr* operator[](const std::string& index);
    void add(const std::string& name, const std::string& value );
    void add(const std::string& name);
    void erase( const std::string& name );
    void erase( int index );
    void clear ();

private:
	NamedNodeMap(const NamedNodeMap&);				//njet
	NamedNodeMap& operator=(const NamedNodeMap&);	//njet
	
    std::list<Attr*>                    attributes_;
	Node*								parent_;
};

///////////////////////////////////////////////////////////////////////////////

class NodeList
{
friend class Document;
friend class Node;
friend class Element;
public:
	NodeList() : bDetach_(false){};
    NodeList(const NodeList& n);
    virtual ~NodeList();

    void clear();
    Node* item(int index);
    int length() const;
    Node* operator[](int index)	;
    void add(Node* n);
    void erase(Node* n );
	void detach() { bDetach_ = true; }

	Element*			 getChildByName(const std::string& name );
	NodeList			 getChildrenByName(const std::string& name );
	Element*			 getChildByNameNS(const std::string& name, const std::string& ns );
	NodeList			 getChildrenByNameNS(const std::string& name, const std::string& ns );


	NodeList& operator=(const NodeList&);

private:

    std::vector<Node*>	nodes_;
	bool				bDetach_;
};

///////////////////////////////////////////////////////////////////////////////

class Node {
friend class Document;
friend class Nodelist;
friend class NamedNodeMap;

public:
	virtual ~Node() {};
    enum NodeType { UNDEFINED = 0,
					ELEMENT   = 1,
                    ATTRIBUTE = 2,
                    TEXT      = 3,
                    CDATA     = 4,	
                    ENTITYREF = 5,	// not implemented
					ENTITY	  = 6,	// not implemented
                    PI		  = 7,	// not implemented
					COMMENT   = 8,
					DOCUMENT  = 9,	// not implemented
					DOCTYPE   = 10,	// not implemented
					DOCFRAG   = 11,	// not implemented
					NOTATION  = 12,	// not implemented
					SCRIPT    = 13  // mol extension for HTML parsing
					};

	virtual Node* cloneNode();

    // DOM methods
    virtual NodeType	nodeType();
    virtual void		nodeType( NodeType t);
    virtual const		std::string&	nodeName();
    virtual void		nodeName(const std::string& s );
    virtual 			std::string	nodeValue();
    virtual void		nodeValue(const std::string& s );

	template<class T>
	T get()
	{
		T t;
		std::istringstream iss(nodeValue());
		iss >> t;
		return t;
	}

	//namespace support
	virtual std::string	prefix();
	virtual std::string	localname();
	virtual std::string	namespaceURI();

	// NS extensions
	virtual std::string  getNSfromPrefix(const std::string& prefix);
	virtual	std::string  getPrefixFromNS(const std::string& ns);
	virtual std::string  defaultNamespace();

	// DOM lookup
    virtual Document*	 ownerDocument();
	virtual Node*		 parentNode();

	// children_
	virtual	void		clear();
    virtual	bool		hasChildNodes();
    virtual Node*		nextSibling();
    virtual Node*		previousSibling();
    virtual Node*		firstChild()	;
    virtual Node*		lastChild();
    virtual NodeList*	childNodes();

    virtual void		appendChild( Node* n );
    virtual void		removeChild( Node* n );
    virtual void		replaceChild( Node* oldElement, Node* newElement );
    virtual void		insertBefore(  Node* beforeElement, Node* n );
	virtual void		insertAfter( Node* afterElement, Node* n );

    // Attributes
	virtual bool			hasAttributes();
    virtual NamedNodeMap*	attributes();

	// has endtag?
    virtual bool	  	 isAlone(); 
	virtual void	  	 isAlone(bool b); 

protected:
    // Construction/Destruction
	Node  () : attribs_(this) {	init(); };
	Node  (Document* pD, mol::Node* parent_, mol::Node::NodeType t, const std::string& name, const std::string& value);
	Node& operator=( Node& n );

    void init();
	void getElementsByTagNameWalker(const std::string& tag, mol::NodeList& nodes_ );
	void getElementsByTagNameWalkerQ(const std::string& tag, const std::string& ns , mol::NodeList& nodes_ );

	NodeType		type_;
    std::string		nodename_;
    std::string		nodevalue_;

	Node*			parent_;
    Document*		document_;
	NamedNodeMap	attribs_;
    NodeList		children_;
    bool			isalone_;
};

///////////////////////////////////////////////////////////////////////////////

class Attr : public Node
{
friend class NamedNodeMap;
public:
    Attr();
    Attr( const std::string& name, const std::string& value );
    virtual ~Attr();

	virtual Node*  cloneNode();
    Attr& operator=( const Attr& a );
	bool specified();

	Element* ownerElement();

    std::string text();

    char quote;
};

///////////////////////////////////////////////////////////////////////////////

class Element : public Node
{
friend class Document;
friend class NodeList;
public:
    virtual				~Element ();
    Element&			 operator=( Element& n );

	virtual				 Node* cloneNode();
    Attr*				 getAttribute(int index);
    Attr*				 getAttribute( const std::string& name );
    Attr*				 getAttributeNS( const std::string& name, const std::string& ns );
    void				 setAttribute(const std::string& key, const std::string& value );
    void				 setAttributeNS(const std::string& key, const std::string& ns, const std::string& value );
    void				 removeAttribute(const std::string& a );
	std::string			 attr(const std::string& key);

	//helpers
	Element*			 getElementById( const std::string& id );
	Element*			 getElementById( const std::string& key, const std::string& id );
	Element*			 getElementByName( const std::string& name );
    NodeList			 getElementsByTagName(const std::string& tag);
	NodeList			 getElementsByTagNameQ(const std::string& tag, const std::string& ns );
    Element*			 getElementByTagName(const std::string& tag);
	Element*			 getElementByTagNameQ(const std::string& tag, const std::string& ns );

	virtual std::string  getNSfromPrefix(const std::string& prefix);
	virtual	std::string  getPrefixFromNS(const std::string& ns);
	virtual std::string  defaultNamespace();

    // text helpers
    std::string			 atts();
    std::string			 startTag();
    std::string			 endTag();

	// modifiers
    std::string innerXml();
    void		innerXml(const std::string& s);
    std::string outerXml();
    void		outerXml(const std::string& s);

protected:
  	// Construction/Destruction
    Element  ();
	Element  (Document* pD, const std::string& name);
	Element  (Document* pD, mol::Element* parent_, const std::string& name);
	Element  (Document* pD, mol::Element* parent_, mol::Node::NodeType t, const std::string& name);

};

///////////////////////////////////////////////////////////////////////////////

class Text : public Node
{
	friend class Document;
public:
	virtual				~Text () {};

protected:
  	// Construction/Destruction
    Text  ();
	Text  (Document* pD, const std::string& value);
	Text  (Document* pD, mol::Element* parent_, const std::string& value);	
};

///////////////////////////////////////////////////////////////////////////////

} // end namespace mole

#endif

