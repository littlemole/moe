#include "xml/html.h"
#include "util/istr.h"

namespace mol {

///////////////////////////////////////////////////////////////////////////////

namespace html {

StackNode::StackNode()
: node(0), type(mol::Node::UNDEFINED), tag(""),noCount(false)
{
}

StackNode::StackNode( mol::Node* n )
: node(n), type(n->nodeType()), tag(n->nodeName()),noCount(false)
{
    if ( tag.size() > 0 )
        tag = mol::str::tolower(tag);
}
///////////////////////////////////////////////////////////////////////////////

class HtmlScript
{
public:
    static size_t isScriptStart       ( const std::string& input, size_t& pos );
    static std::string fetchScript    ( size_t script, const std::string& input, size_t& pos );

private:
    static size_t getScriptEnd        ( size_t script, const std::string& input, size_t pos );
};


///////////////////////////////////////////////////////////////////////////////

// script[0] actually is comment,
// script[1] actually is cdata

char* molscripts[]     = { "<!--", "<[[CDATA", "<?php", "<?", 
                           "<&", "<@", "<%init", "<%perl", 
                           "<%args", "<%flags", "<%cleanup", "<%once", 
                           "<%shared", "<%attr", "<%filter", "<%text", 
                           "<%doc", "<% ", "%" } ;

char* molscriptsends[] = { "-->", "]]>", "?>", "?>", 
                           "&>", "@>", "</%init>", "</%perl>", 
                           "</%args>", "</%flags>", "</%cleanup>", "</%once>", 
                           "</%shared>", "</%attr>", "</%filter>", "</%text", 
                           "</%doc>", " %>", "\n" };

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

size_t HtmlScript::isScriptStart( const std::string& input, size_t& pos )
{
    char c = input[pos];
    if ( (c == '<') && (pos+1 < input.size()) )
    {
        char d = input[pos+1];
	    for ( int i = 0; i < 18; i++ )
	    {                
            if ( d == molscripts[i][1] )
            {
                size_t len = strlen(molscripts[i]);
                if ( pos + len < input.size() )
                    if ( strncmp(input.c_str()+pos,molscripts[i],len) == 0 )
			            return i+1;
            }
	    }
    }
	if ( c == '%' )
	{
		if ( (pos == 0) || (input[pos-1] == '\n') )
			return 19;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////

size_t HtmlScript::getScriptEnd( size_t script, const std::string& input, size_t pos )
{
    if ( !script )
        return input.size()-1;

    size_t len = strlen(molscriptsends[script-1]);
    std::string test = molscriptsends[script-1];
    while ( pos + len < input.size() )
    {
        if ( input[pos] == molscriptsends[script-1][0] )
        {
            if ( input.substr(pos,len) == molscriptsends[script-1] )
            {
                pos += len;
                return pos;
            }
        }
        pos++;
    }
    pos=input.size();
    return pos;
}

///////////////////////////////////////////////////////////////////////////////

std::string HtmlScript::fetchScript(size_t script, const std::string& input, size_t& pos)
{
    size_t end = getScriptEnd(script,input,pos);
    size_t p   = pos;

    pos = end;
    return input.substr(p,end-p);
}

} // end namespace html

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

HtmlParser::HtmlParser()
: ihsh_(0)
{
}

///////////////////////////////////////////////////////////////////////////////

HtmlParser::HtmlParser(IHtmlSaxHandler* ihsh)
:ihsh_(ihsh)
{
}

///////////////////////////////////////////////////////////////////////////////

void HtmlParser::setHandler(IHtmlSaxHandler* ihsh)
{
    ihsh_ = ihsh;
}

///////////////////////////////////////////////////////////////////////////////

bool HtmlParser::parse ( const std::string& input )
{
    if (!ihsh_)
        return false;

    state_      = TXT;
    size_t size = input.size();
    size_t pos  = 0;

    while ( pos < size )
    {
        switch ( state_ )
        {
            case ERR :
            {
                break;
            }
            case START  :
            {
                parseStartTag(input,pos);
                break;
            }
            case END :
            {
                parseEndTag(input,pos);
                break;
            }
            case TXT :
            {
                parseText(input,pos);
                break;
            }
            case SCRIPT :
            {
                parseScript(input,pos);
                break;
            }
        }
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////

bool HtmlParser::parseStartTag( const std::string& input, size_t& pos )
{
    // check for end tag
    if ( pos < input.size()-1 )
    {
        if ( input[pos+1] == '/' )
        {
            state_ = END;
            return true;
        }
    }

    mol::html::VATT vatt;

    // now fetch tag name
    std::string tag;
    size_t p = pos;
    while ( p < input.size() )
    {
        char c = input[p];
        // check for server side scripts
        if ( c == '<' )
        {
            size_t script = mol::html::HtmlScript::isScriptStart(input,p);
            if ( script )
            {
                // end of text - keep start of tagname
                if ( p > pos )
                    tag += input.substr(pos,p-pos-1);

                // now get the script
                tag += mol::html::HtmlScript::fetchScript(script,input,p);
                pos = p-1;
                continue;
            }
        }
        // end of tag?
        if ( c == '>' )
        {
            tag += input.substr(pos+1,p-pos-1);
            if ( tag.size() > 0 )
                ihsh_->start_tag( tag, vatt );
            pos = p+1;

            state_ = TXT;
            if ( _stricmp(tag.substr(0,6).c_str(),"script") == 0 )
                state_ = SCRIPT;
            return true;
        }
        // check for start of attributes
        if ( c == ' ' || c == '/' )
        {
            tag+= input.substr(pos+1,p-pos-1);
            pos = p;
            // go for attributes
            parseKey(input,pos,vatt);
            break;
        }
        p++;
    }
    // dont forget eof
    if ( p == input.size() )
    {
        if ( p > pos )
        {
            tag+= input.substr(pos,p-pos);
            pos = p;
        }
    }
    // reset state
    state_ = TXT;
    if(tag.size()>0)
        ihsh_->start_tag( tag, vatt );    

    if ( _stricmp(tag.substr(0,6).c_str(),"script") == 0 )
        state_ = SCRIPT;
    return true;
}

///////////////////////////////////////////////////////////////////////////////

bool HtmlParser::parseKey( const std::string& input, size_t& pos, mol::html::VATT& vatt )
{
    size_t p = pos;
    std::string key = "";
    while ( p < input.size() )
    {
        char c = input[p];

        // check for server side scripts
        if ( c == '<' )
        {
            size_t script = mol::html::HtmlScript::isScriptStart(input,p);
            if ( script )
            {
                // end of text - keep start of tagname
                if ( p > pos )
                    key += input.substr(pos,p-pos);

                // now get the script
                key += mol::html::HtmlScript::fetchScript(script,input,p);
                pos = p;
                continue;
            }
        }
        // next attribute?
        if ( c == ' ' )
        {
            mol::html::ATT att;
            if ( p > pos )
                key += input.substr(pos,p-pos);
            att.key = mol::trim(key);
            if ( att.key.size() > 0 )
                vatt.push_back(att);
            // next key
            key = "";
            p++;
            pos = p;
            continue;
        }
        // end of attributes?
        if ( c == '>' )
        {
            mol::html::ATT att;
            if ( p > pos )
                key += input.substr(pos,p-pos);
            att.key = mol::trim(key);

            if ( att.key.size() > 0 )
                vatt.push_back(att);

            pos = p+1;
            // end of attributes
            return true;
        }      
        // start value?
        if ( c == '=' )
        {
            mol::html::ATT att;
            if ( p > pos )
            {
                // fetch key
                key += input.substr(pos,p-pos);
                att.key = mol::trim(key);

                //skip over '='
                p++;
                if ( att.key.size() > 0 )
                {
                    // go for key value
                    bool b = parseVal( input, p, att );
                    vatt.push_back(att);
                    if ( !b )
                    {
                        // end of keys/values
                        pos = p;
                        return false;
                    }
                }
                // next key
                key = "";
                pos = p;
                continue;
            }
        }
        p++;
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////
bool HtmlParser::parseVal( const std::string& input, size_t& pos, mol::html::ATT& att )
{

    //skip whitespace
    while( isspace(input[pos]) )
    {
        pos++;
        if ( pos >= input.size() )
            return false;
    }
    //quote_   = 0;
    size_t p = pos;

    // check quoted
    char c = input[pos];
    if ( c == '\'' || c == '"' )
    {
        return parseQuotedVal(input, pos, att );
    }

    // fetch unquoted val
    while ( p < input.size() )
    {
        char c = input[p];

        // check for comments and server side scripts
        if ( c == '<' )
        {
            size_t script = mol::html::HtmlScript::isScriptStart(input,p);
            if ( script )
            {
                // end of text - keep start of tagname
                if ( p > pos )
                {
                    att.val += input.substr(pos,p-pos);
                }

                // now get the script
                att.val += mol::html::HtmlScript::fetchScript(script,input,p);
                pos = p;
                continue;
            }
        }
        // dont follow value over newline
/*        if ( input[p] == '\n'  )
        {
            /// return everyting from start as value
            att.val += input.substr(pos,p-pos-1);
            pos = p;
            return false;
        }
		*/
        // check of end of value if not quoted
		if ( input[p] == '>' || 
			 input[p] == ' ' || 
			 input[p] == '/' ||
			 input[p] == '\r' ||
			 input[p] == '\n' ||
			 input[p] == '\t'  
		    )
        {
                att.val += input.substr(pos,p-pos);
                pos = p;
                return true;
        }
        p++;
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////
bool HtmlParser::parseQuotedVal( const std::string& input, size_t& pos, mol::html::ATT& att )
{
    att.quote = input[pos];

    size_t p = pos+1;
    while ( p < input.size() )
    {
        char c = input[p];
        // end of quote?
        if ( c == att.quote )
        {
            if ( p - pos > 1 )
                att.val += input.substr(pos+1,p-pos-1);
            pos = p+1;
            break;
        }
        // dont follow quote over newlibe
 /*       if ( input[p] == '\n'  )
        {
            /// return everyting from start as value
            if ( p-pos > 0 )
                att.val += input.substr(pos,p-pos);
            pos = p+1;
            att.quote=0;
            return false;
        }
		*/
        // check for comments and server side scripts
        if ( c == '<' )
        {
            size_t script = mol::html::HtmlScript::isScriptStart(input,p);
            if ( script )
            {
                // end of text - keep start of tagname
                if ( p > pos )
                {
                    att.val += input.substr(pos,p-pos);
                }

                // now get the script
                att.val += mol::html::HtmlScript::fetchScript(script,input,p);
                pos = p;
                continue;
            }
        }
        p++;
    }
    return pos < input.size();
}


///////////////////////////////////////////////////////////////////////////////

bool HtmlParser::parseEndTag( const std::string& input, size_t& pos )
{
    size_t p = input.find('>',pos);
    if ( p != input.npos )
    {
        if ( p-pos > 1 )
            ihsh_->end_tag(input.substr(pos+1,p-pos-1));

        pos = p+1;
    }
    state_ = TXT;
    return true;
}

///////////////////////////////////////////////////////////////////////////////

bool HtmlParser::parseText( const std::string& input, size_t& pos )
{
    // find next tag
    size_t p = pos;
    while ( p < input.size()  )
    {
        char c = input[p];
        // check for comments and server side scripts
        if ( c == '<' || c == '%' )
        {
            size_t script = mol::html::HtmlScript::isScriptStart(input,p);
            if ( script )
            {
                // end of text - handle that first
                if ( p > pos )
                {
                    ihsh_->text(input.substr(pos,p-pos) );
                }

                // now get the script
                std::string s = mol::html::HtmlScript::fetchScript(script,input,p);
                switch ( (int)script )
                {
                    case 0:  break;
                    case 1:  ihsh_->comment( s ); break;
                    case 2:  ihsh_->cdata  ( s ); break;
                    default: ihsh_->script ( s ); break;
                }   
                pos = p;
                state_ = TXT;
                return true;
            }
        }
        if ( input[p] == '<' )
        {
            // end of text - handle that first
            if ( p > pos )
            {
                ihsh_->text(input.substr(pos,p-pos));
            }

            pos = p;
            state_ = START;
            return true;
        }
        p++;
    }

    // end of input, no tag found so fetch as txt
    ihsh_->text(input.substr(pos));
    pos = input.size();
    state_ = TXT;
    return true;
}

///////////////////////////////////////////////////////////////////////////////

bool HtmlParser::parseScript( const std::string& input, size_t& pos )
{
    size_t p = pos;
    while ( p < input.size() )
    {
        if ( input[p] == '<' )
        {
            if ( p+8 < input.size() )
            {
                if ( _stricmp( input.substr(p,9).c_str(), "</script>" ) == 0 )
                {
                    if ( p-pos > 1 )
                        ihsh_->script(input.substr(pos,p-pos-1));

                    pos = p;
                    state_ = END;
                    return true;
                }
                p++;
                continue;
            } 
            break;
        }
        p++;
    }

    // no end script tag found, treat all up to eof as script
    ihsh_->script(input.substr(pos));
    pos = input.size();
    state_ = TXT;
    return true;
}




///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

HtmlDomParser::HtmlDomParser()
{
    parser_.setHandler(this);
}

void HtmlDomParser::push(mol::html::StackNode& sn)
{
    if ( sn.type == mol::Node::UNDEFINED )
        return;

    // push node on stack
    stack_.push_back(sn);

    // see if we want to map this for closing tags
    if ( sn.tag.size() == 0 )
        return;
    if ( sn.tag[0] == '/' )
        return;
    if ( sn.noCount )
        return;

    // assure we have maping for this tag
    if ( count_.count(sn.tag) == 0 )
    {
        std::vector<int> v;
        count_[sn.tag] = v;
    }
    // map this occurence of a start tag
    count_[sn.tag].push_back((int)stack_.size()-1);
}

///////////////////////////////////////////////////////////////////////////////

void HtmlDomParser::start_tag (const std::string& tag, const mol::html::VATT& attr)
{
    size_t s = stack_.size();
    
    mol::Element* el = doc_->createElement(tag);
    el->isAlone(true);
    mol::html::StackNode sn(el);

    for ( size_t i = 0; i < attr.size(); i++ )
    {
		if ( attr[i].key == "/" )
		{
			sn.noCount = true;
			continue;
		}
		//	std::cout << "cry!" << std::endl;
        el->setAttribute(attr[i].key,"");
        mol::Attr* at = el->getAttribute(attr[i].key);

        at->nodeValue(attr[i].val);
        at->quote = attr[i].quote;
    }

    push(sn);
}

///////////////////////////////////////////////////////////////////////////////

void HtmlDomParser::end_tag   (const std::string& tag)
{
    std::string s = (tag.substr(1)); 
    s = mol::str::tolower(s);

    size_t size = stack_.size();
    if ( size > 0 )
    {
        if ( count_.count(s) > 0 )
        {
            int index = count_[s].back();
            mol::html::StackNode& sn = stack_[index];

			// dont as we stay on stack!
            count_[s].pop_back();
            if ( count_[s].size() == 0 )
                count_.erase(s);
			sn.noCount = true;

            sn.node->isAlone(false);
            for (  unsigned int i = index+1; i < size; i++ )
            {
                mol::html::StackNode& n = stack_[i];
                sn.node->appendChild(n.node);
                
				if ( !n.noCount )
                if ( count_.count(n.tag) > 0 )
                {
                    count_[n.tag].pop_back();
                    if ( count_[n.tag].size() == 0 )
                        count_.erase(n.tag);
                }
            }
            for (  unsigned int i = index+1; i < size; i++ )
            {
                stack_.pop_back();
            }
            return;
        }
    }

    // not found
    mol::Element* el = doc_->createElement(tag);
    mol::html::StackNode sn(el);
    sn.noCount = true;
    push(sn);
}

///////////////////////////////////////////////////////////////////////////////

void HtmlDomParser::text      (const std::string& tag)
{
    size_t size = stack_.size();
    if ( size > 0 )
    {
        mol::html::StackNode sn = stack_[size-1];
        if ( sn.type == mol::Node::TEXT )
        {
            sn.node->nodeValue() == sn.node->nodeValue() + tag;
            return;
        }
    }
    mol::Text* txt = doc_->createTextNode(tag);

    mol::html::StackNode sn(txt);
    push(sn);
}

///////////////////////////////////////////////////////////////////////////////

void HtmlDomParser::comment   (const std::string& tag ) 
{
    mol::Node* n = doc_->createNode( mol::Node::COMMENT, 0, "", tag );
    mol::html::StackNode sn(n);
    push(sn);
}

///////////////////////////////////////////////////////////////////////////////

void HtmlDomParser::script    (const std::string& tag) 
{
    mol::Node* n = doc_->createNode( mol::Node::SCRIPT, 0, "", tag );
    mol::html::StackNode sn(n);
    push(sn);
}

///////////////////////////////////////////////////////////////////////////////

void HtmlDomParser::cdata    (const std::string& tag) 
{
    mol::Node* n = doc_->createNode( mol::Node::CDATA, 0, "", tag );
    mol::html::StackNode sn(n);
    push(sn);
}

//////////////////////////////////////////////////////////////////////
// parse function
//////////////////////////////////////////////////////////////////////
mol::Element* HtmlDomParser::parse( mol::Document* doc_, const std::string& input_ )
{
   return parse( doc_, doc_->documentElement(), input_ );
}

//////////////////////////////////////////////////////////////////////
// workhorse
//////////////////////////////////////////////////////////////////////

mol::Element* HtmlDomParser::parse( mol::Document* d, mol::Element* r, const std::string& in )
{
    doc_  = d;
    root_ = r;
    stack_.clear();
	count_.clear();

    parser_.parse(in);

    size_t s = stack_.size();
    for ( unsigned int i = 0; i < s; i++ )
    {
        mol::Node* n = stack_[i].node ;
        root_->appendChild(n);
    }

    return root_;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

HtmlDocument::HtmlDocument()
{
	docType_ = mol::HTML;
	root_.nodeType(mol::Node::ELEMENT);
}

///////////////////////////////////////////////////////////////////////////////

HtmlDocument::~HtmlDocument()
{

}

///////////////////////////////////////////////////////////////////////////////

mol::Element* HtmlDocument::parse( const std::string& src )
{
    clear();
    return parser_.parse(this,src);
}

///////////////////////////////////////////////////////////////////////////////

mol::Element* HtmlDocument::parse( mol::Element* root, const std::string& src )
{
    clear();
    return parser_.parse(this,root,src);
}
} // end namespace mol