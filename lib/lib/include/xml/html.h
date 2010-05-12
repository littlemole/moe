#ifndef MOL_HTML_SCRIPT_PARSER_DEF_GUARD_DEFINE_
#define MOL_HTML_SCRIPT_PARSER_DEF_GUARD_DEFINE_

#pragma once

#include "xml/Document.h"

namespace mol {

///////////////////////////////////////////////////////////////////////////////
// lazy HTML Sax-Style and DOM Parsers
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Attribute struct for HTML SAX Parser
///////////////////////////////////////////////////////////////////////////////

namespace html {

struct ATT
{
    ATT() : quote(0)
    {}
    std::string val;
    std::string key;
    char quote;
};


///////////////////////////////////////////////////////////////////////////////
// typedefs
///////////////////////////////////////////////////////////////////////////////

// vector container w key/value pairs for html attr
typedef std::vector<ATT> VATT;

} // end namespace html

///////////////////////////////////////////////////////////////////////////////
// Sax style HTML parser Event handler interface
///////////////////////////////////////////////////////////////////////////////


class IHtmlSaxHandler
{
public:
    // the parser will call these interface handlers during parsing
	void virtual start_tag (const std::string& tag, const mol::html::VATT& attr) = 0;
    void virtual end_tag   (const std::string& tag)  = 0;
    void virtual text      (const std::string& tag ) = 0;
    void virtual comment   (const std::string& tag ) = 0;
    void virtual cdata     (const std::string& tag ) = 0;
    void virtual script    (const std::string& tag ) = 0;
};

///////////////////////////////////////////////////////////////////////////////
// the sax-style HTML parser
///////////////////////////////////////////////////////////////////////////////

class HtmlParser
{
public:
    HtmlParser();
    HtmlParser(IHtmlSaxHandler* ihsh);

    // set HTML parse event handlers
    void setHandler(IHtmlSaxHandler* ihsh);

    // parse some txt
    bool parse ( const std::string& input );

protected:

    // states of parser engine
    enum states { ERR, START, END, TXT, KEY, VAL, COMM, SCRIPT };

    // parse subroutines
    bool parseStartTag( const std::string& input, size_t& pos ); 
    bool parseKey( const std::string& input, size_t& pos, mol::html::VATT& att );
    bool parseVal( const std::string& input, size_t& pos, mol::html::ATT& att );
    bool parseQuotedVal( const std::string& input, size_t& pos, mol::html::ATT& att );
    bool parseEndTag( const std::string& input, size_t& pos );
    bool parseText( const std::string& input, size_t& pos );
    bool parseScript( const std::string& input, size_t& pos );

    // state of parser engine
    states state_;

    // pointer to HTML Parse Event Handler
    IHtmlSaxHandler* ihsh_;
};

///////////////////////////////////////////////////////////////////////////////

namespace html {

///////////////////////////////////////////////////////////////////////////////
// internal helper - the DOM Parser puts this tag info on a stack while parsing
///////////////////////////////////////////////////////////////////////////////

struct StackNode {
    StackNode();
    StackNode( mol::Node* n );

    mol::Node* node;                // pointer to DOM node on stack
    mol::Node::NodeType type;       // type of Node
    std::string tag;                // tagname of Node
    bool noCount;                   // indicator wether tag stands alone
};

} // end namespace html

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//  the HTML DOM parser 
///////////////////////////////////////////////////////////////////////////////

class HtmlDomParser : public IHtmlSaxHandler 
{
public:

    HtmlDomParser();

    // parse funtions
    mol::Element* parse( mol::Document* doc_, const std::string& input_ );
    mol::Element* parse( mol::Document* doc_, mol::Element* root, const std::string& input_);

private:
	void virtual start_tag (const std::string& tag, const mol::html::VATT& attr);
    void virtual end_tag   (const std::string& tag);
    void virtual text      (const std::string& tag);
    void virtual comment   (const std::string& tag);
    void virtual cdata     (const std::string& tag);
    void virtual script    (const std::string& tag);

    void push(mol::html::StackNode& sn);

private:

    // parse stack for tree building
    typedef std::vector<mol::html::StackNode>    Stack;
    // map for quickly matching open tags on stack for closing tags
    typedef std::map<std::string,std::vector<int> > StackCount;

    HtmlParser                  parser_;
    mol::Document*              doc_;
    mol::Element*               root_;
    Stack                       stack_;
    StackCount                  count_;
};




///////////////////////////////////////////////////////////////////////////////
// the HTML Document - end user interface
///////////////////////////////////////////////////////////////////////////////

class HtmlDocument : public mol::Document 
{
friend class HtmlDomParser;
public:
	    HtmlDocument();
		virtual ~HtmlDocument();

        // parse functions
        mol::Element* parse( const std::string& src );
		mol::Element* parse( mol::Element* root, const std::string& src );

private:
        HtmlDocument& operator=( HtmlDocument& p );				//nada
		HtmlDomParser parser_;
};

} // end namespace mol

#endif
