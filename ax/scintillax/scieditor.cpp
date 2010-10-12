#include "StdAfx.h"
#include "scieditor.h"
#include <richedit.h>
#include "util/Str.h"
#include "util/iStr.h"
#include "win/path.h"
#include <winspool.h>

const mol::TCHAR scintilla[] = _T("Scintilla");

const std::string ScEdMode::htmlKeyWords = 
	"a abbr acronym address applet area b base basefont "
	"bdo big blockquote body br button caption center "
	"cite code col colgroup dd del dfn dir div dl dt em "
	"fieldset font form frame frameset h1 h2 h3 h4 h5 h6 "
	"head hr html i iframe img input ins isindex kbd label "
	"legend li link map menu meta noframes noscript "
	"object ol optgroup option p param pre q s samp "
	"script select small span strike strong style sub sup "
	"table tbody td textarea tfoot th thead title tr tt u ul "
	"var xmlns "
	"abbr accept-charset accept accesskey action align alink "
	"alt archive axis background bgcolor border "
	"cellpadding cellspacing char charoff charset checked cite "
	"class classid clear codebase codetype color cols colspan "
	"compact content coords "
	"data datafld dataformatas datapagesize datasrc datetime "
	"declare defer dir disabled enctype "
	"face for frame frameborder "
	"headers height href hreflang hspace http-equiv "
	"id ismap label lang language link longdesc "
	"marginwidth marginheight maxlength media method multiple "
	"name nohref noresize noshade nowrap "
	"object onblur onchange onclick ondblclick onfocus "
	"onkeydown onkeypress onkeyup onload onmousedown "
	"onmousemove onmouseover onmouseout onmouseup "
	"onreset onselect onsubmit onunload "
	"profile prompt readonly rel rev rows rowspan rules "
	"scheme scope shape size span src standby start style "
	"summary tabindex target text title type usemap "
	"valign value valuetype version vlink vspace width "
	"text password checkbox radio submit reset "
	"file hidden image "
	"public !doctype xml";

const std::string ScEdMode::jsKeyWords = 
	"break case catch continue default "
	"do else for function if return throw try var while";

const std::string ScEdMode::vbsKeyWords = 
	"and as byref byval case call const is"
	"continue dim do each else elseif end error exit false for function global "
	"goto if in loop me new next not nothing on optional or private public "
	"redim rem resume select set sub then to true type while with "
	"boolean byte currency date double integer long object single string type "
	"variant";

const std::string ScEdMode::phpKeyWords = 
	"and argv as argc break case cfunction class continue declare default do "
	"die echo else elseif empty enddeclare endfor endforeach endif endswitch "
	"endwhile e_all e_parse e_error e_warning eval exit extends false for "
	"foreach function global http_cookie_vars http_get_vars http_post_vars "
	"http_post_files http_env_vars http_server_vars if include include_once "
	"list new not null old_function or parent php_os php_self php_version "
	"print require require_once return static switch stdclass this true var "
	"xor virtual while __file__ __line__ __sleep __wakeup";

const std::string ScEdMode::perlKeyWords = 
"NULL __FILE__ __LINE__ __PACKAGE__ __DATA__ __END__ AUTOLOAD "
"BEGIN CORE DESTROY END EQ GE GT INIT LE LT NE CHECK abs accept "
"alarm and atan2 bind binmode bless caller chdir chmod chomp chop "
"chown chr chroot close closedir cmp connect continue cos crypt "
"dbmclose dbmopen defined delete die do dump each else elsif endgrent "
"endhostent endnetent endprotoent endpwent endservent eof eq eval "
"exec exists exit exp fcntl fileno flock for foreach fork format "
"formline ge getc getgrent getgrgid getgrnam gethostbyaddr gethostbyname "
"gethostent getlogin getnetbyaddr getnetbyname getnetent getpeername "
"getpgrp getppid getpriority getprotobyname getprotobynumber getprotoent "
"getpwent getpwnam getpwuid getservbyname getservbyport getservent "
"getsockname getsockopt glob gmtime goto grep gt hex if index "
"int ioctl join keys kill last lc lcfirst le length link listen "
"local localtime lock log lstat lt m map mkdir msgctl msgget msgrcv "
"msgsnd my ne next no not oct open opendir or ord our pack package "
"pipe pop pos print printf prototype push q qq qr quotemeta qu "
"qw qx rand read readdir readline readlink readpipe recv redo "
"ref rename require reset return reverse rewinddir rindex rmdir "
"s scalar seek seekdir select semctl semget semop send setgrent "
"sethostent setnetent setpgrp setpriority setprotoent setpwent "
"setservent setsockopt shift shmctl shmget shmread shmwrite shutdown "
"sin sleep socket socketpair sort splice split sprintf sqrt srand "
"stat study sub substr symlink syscall sysopen sysread sysseek "
"system syswrite tell telldir tie tied time times tr truncate "
"uc ucfirst umask undef unless unlink unpack unshift untie until "
"use utime values vec wait waitpid wantarray warn while write "
"x xor y ";

const std::string ScEdMode::cppKeyWords = 
"and and_eq asm auto bitand bitor bool break "
"case catch char class compl const const_cast continue "
"default delete do double dynamic_cast else enum explicit export extern false float for "
"friend goto if inline int long mutable namespace new not not_eq "
"operator or or_eq private protected public "
"register reinterpret_cast return short signed sizeof static static_cast struct switch "
"template this throw true try typedef typeid typename union unsigned using "
"virtual void volatile wchar_t while xor xor_eq";

const std::string ScEdMode::javaKeywords = 
"abstract assert boolean break byte case catch char class "
"const continue default do double else extends final finally float for future "
"generic goto if implements import inner instanceof int interface long "
"native new null outer package private protected public rest "
"return short static super switch synchronized this throw throws "
"transient try var void volatile while";

const std::string ScEdMode::css1Keywords = 
"left right top bottom position "
"font-family font-style font-variant font-weight font-size font "
"color background-color background-image background-repeat background-attachment background-position background "
"word-spacing letter-spacing text-decoration vertical-align text-transform text-align text-indent line-height "
"margin-top margin-right margin-bottom margin-left margin "
"padding-top padding-right padding-bottom padding-left padding "
"border-top-width border-right-width border-bottom-width border-left-width border-width "
"border-top border-right border-bottom border-left border "
"border-color border-style width height float clear scrollbar-base-color scrollbar-track-color"
"display white-space list-style-type list-style-image list-style-position list-style";

const std::string ScEdMode::css2Keywords = 
"first-letter first-line active link visited";

const std::string ScEdMode::sqlKeywords = 
"absolute action add admin after aggregate "
"alias all allocate alter and any are array as asc "
"assertion at authorization "
"before begin binary bit blob boolean both breadth by "
"call cascade cascaded case cast catalog char character "
"check class clob close collate collation column commit "
"completion connect connection constraint constraints "
"constructor continue corresponding create cross cube current "
"current_date current_path current_role current_time current_timestamp "
"current_user cursor cycle "
"data date day deallocate dec decimal declare default "
"deferrable deferred delete depth deref desc describe descriptor "
"destroy destructor deterministic dictionary diagnostics disconnect "
"distinct domain double drop dynamic "
"each else end end-exec equals escape every except "
"exception exec execute external "
"false fetch first float for foreign found from free full "
"function "
"general get global go goto grant group grouping "
"having host hour "
"identity if ignore immediate in indicator initialize initially "
"inner inout input insert int integer intersect interval "
"into is isolation iterate "
"join "
"key "
"language large last lateral leading left less level like "
"limit local localtime localtimestamp locator "
"map match minute modifies modify module month "
"names national natural nchar nclob new next no none "
"not null numeric "
"object of off old on only open operation option "
"or order ordinality out outer output "
"pad parameter parameters partial path postfix precision prefix "
"preorder prepare preserve primary "
"prior privileges procedure public "
"read reads real recursive ref references referencing relative "
"restrict result return returns revoke right "
"role rollback rollup routine row rows "
"savepoint schema scroll scope search second section select "
"sequence session session_user set sets size smallint some| space "
"specific specifictype sql sqlexception sqlstate sqlwarning start "
"state statement static structure system_user "
"table temporary terminate than then time timestamp "
"timezone_hour timezone_minute to trailing transaction translation "
"treat trigger true "
"under union unique unknown "
"unnest update usage user using "
"value values varchar variable varying view "
"when whenever where with without work write "
"year "
"zone";

const std::string ScEdMode::csharpKeywords = 
"abstract event new struct " 
"as explicit null switch " 
"base extern object this " 
"bool false operator throw " 
"break finally out true " 
"byte fixed override try " 
"case float params typeof " 
"catch for private uint " 
"char foreach protected ulong " 
"checked goto public unchecked " 
"class if readonly unsafe " 
"const implicit ref ushort " 
"continue in return using " 
"decimal int sbyte virtual " 
"default interface sealed volatile " 
"delegate internal short void " 
"do is sizeof while " 
"double lock stackalloc "   
"else long static "   
"enum namespace string //@ref //@lang ";

 const COLORREF ScEdMode::black = RGB(0,0,0);
 const COLORREF ScEdMode::white = RGB(0xff,0xff,0xff);
 const COLORREF ScEdMode::red = RGB(0xFF, 0, 0);
 const COLORREF ScEdMode::offWhite = RGB(0xF0, 0xF0, 0xF0);
 const COLORREF ScEdMode::offGrey =  RGB(0xE2, 0xE2, 0xE2);
 const COLORREF ScEdMode::lightGreen = RGB(5, 0x90, 5);
 const COLORREF ScEdMode::green = RGB(0, 0x90, 0);
 const COLORREF ScEdMode::darkGreen = RGB(0, 0x60, 0);
 const COLORREF ScEdMode::darkblue = RGB(0, 0, 0x80);
 const COLORREF ScEdMode::blue = RGB(0x15, 0x25, 0xA0);
 const COLORREF ScEdMode::lightblue = RGB(0x30, 0x50, 0xC0);
 const COLORREF ScEdMode::grey = RGB(0x70, 0x70, 0x70);
 const COLORREF ScEdMode::orange = RGB(0xFF, 0x80, 0x00);
 const COLORREF ScEdMode::brown = RGB(0x80, 0x40, 0x00);

	void ScEdMode::initPlain(Scintilla* sced)
	{
		sced->setLexer(SCLEX_NULL);
		sced->setStyleBits(7);
		sced->setStyle(STYLE_DEFAULT, black, white, size, font.c_str());//"Courier New");	
		//sced->styleSetBold(STYLE_BRACELIGHT,1);
		sced->styleClearAll();
		sced->colorize(0);
	}

	void ScEdMode::initHtml(Scintilla* sced)
	{
		sced->setLexer(SCLEX_HTML);
		sced->setStyleBits(7);
		sced->setKeywords(0,htmlKeyWords);
		sced->setKeywords(1,jsKeyWords);
		sced->setKeywords(2,vbsKeyWords);
		sced->setKeywords(4,phpKeyWords);

		// Unknown tags and attributes are highlighed in red. 
		// If a tag is actually OK, it should be added in lower case to the htmlKeyWords string.
		sced->setStyle(STYLE_DEFAULT, black, white, size, font.c_str() );//10, "Courier New");	
		sced->styleClearAll();

		sced->styleSetBold(STYLE_BRACELIGHT,1);

		sced->setStyle(SCE_H_TAG, darkblue);
		sced->styleSetBold(SCE_H_TAG, 1);
		sced->setStyle(SCE_H_TAGUNKNOWN, blue);
		sced->styleSetBold(SCE_H_TAGUNKNOWN, 1);
		sced->setStyle(SCE_H_ATTRIBUTE, darkblue);
		sced->styleSetBold(SCE_H_ATTRIBUTE, 1);
		sced->setStyle(SCE_H_ATTRIBUTEUNKNOWN, blue);
		sced->styleSetBold(SCE_H_ATTRIBUTEUNKNOWN, 1);
		sced->setStyle(SCE_H_NUMBER, lightblue);
		sced->setStyle(SCE_H_DOUBLESTRING, darkGreen);
		sced->setStyle(SCE_H_SINGLESTRING, darkGreen);
		sced->setStyle(SCE_H_OTHER, RGB(0x80,0,0x80));
		sced->setStyle(SCE_H_COMMENT, grey);
		sced->styleSetItalic(SCE_H_COMMENT, 1 );
		sced->setStyle(SCE_H_ENTITY, brown );

		sced->setStyle(SCE_H_TAGEND, darkblue);
		sced->setStyle(SCE_H_XMLSTART, darkblue);	// <?
		sced->setStyle(SCE_H_XMLEND, darkblue);		// ?>
		sced->setStyle(SCE_H_SCRIPT, darkblue);		// <script
		sced->setStyle(SCE_H_ASP, RGB(0x4F, 0x4F, 0), offWhite);	// <% ... %>
		sced->setStyle(SCE_H_ASPAT, RGB(0x4F, 0x4F, 0), offWhite);	// <%@ ... %>

		// VBScript 
		sced->setStyle(SCE_HB_DEFAULT, black);
		sced->setStyle(SCE_HB_COMMENTLINE, darkGreen);
		sced->setStyle(SCE_HB_NUMBER, RGB(0,0x80,0x80));
		sced->setStyle(SCE_HB_WORD, darkblue);
		sced->styleSetBold(SCE_HB_WORD, 1);
		sced->setStyle(SCE_HB_STRING, RGB(0x80,0,0x80));
		sced->setStyle(SCE_HB_IDENTIFIER, black);

		for (int bstyle=SCE_HB_DEFAULT; bstyle<=SCE_HB_STRINGEOL; bstyle++) 
		{
			sced->styleSetBack( bstyle, offWhite);
			sced->styleSetEolFilled( bstyle, 1);
		}
		sced->styleSetBack(SCE_HB_STRINGEOL, offWhite);
		sced->setStyle(SCE_HBA_DEFAULT, black);
		sced->setStyle(SCE_HBA_COMMENTLINE, darkGreen);
		sced->setStyle(SCE_HBA_NUMBER, RGB(0,0x80,0x80));
		sced->setStyle(SCE_HBA_WORD, darkblue);
		sced->styleSetBold(SCE_HBA_WORD, 1);
		sced->setStyle(SCE_HBA_STRING, RGB(0x80,0,0x80));
		sced->setStyle(SCE_HBA_IDENTIFIER, black);
		
		for (int bastyle=SCE_HBA_DEFAULT; bastyle<=SCE_HBA_STRINGEOL; bastyle++) {
			sced->styleSetBack( bastyle, offWhite);
			sced->styleSetEolFilled(bastyle, 1);
		}
		sced->styleSetBack(SCE_HBA_STRINGEOL, offWhite);
			
		// If there is no need to support embedded Javascript, the following code can be dropped.
		// Javascript will still be correctly processed but will be displayed in just the default style.
		
		sced->setStyle(SCE_HJ_START, black);
		sced->setStyle(SCE_HJ_DEFAULT, black);
		sced->setStyle(SCE_HJ_COMMENT, grey);
		sced->styleSetItalic(SCE_HJ_COMMENT,1);
		sced->setStyle(SCE_HJ_COMMENTLINE, grey);
		sced->styleSetItalic(SCE_HJ_COMMENTLINE,1);
		sced->setStyle(SCE_HJ_COMMENTDOC, grey);
		sced->styleSetItalic(SCE_HJ_COMMENTDOC,1);
		
		sced->setStyle(SCE_HJ_NUMBER, lightblue );
		sced->setStyle(SCE_HJ_WORD, black);
		sced->setStyle(SCE_HJ_KEYWORD, darkblue);
		sced->styleSetBold(SCE_HJ_KEYWORD, 1);
		sced->setStyle(SCE_HJ_DOUBLESTRING, darkGreen);
		sced->setStyle(SCE_HJ_SINGLESTRING, brown);
		sced->setStyle(SCE_HJ_SYMBOLS, black);

		sced->setStyle(SCE_HJA_START, black);
		sced->setStyle(SCE_HJA_DEFAULT, black);
		sced->setStyle(SCE_HJA_COMMENT, black);
		sced->setStyle(SCE_HJA_COMMENTLINE, black);
		sced->setStyle(SCE_HJA_COMMENTDOC, black);
		sced->setStyle(SCE_HJA_NUMBER, lightblue);
		sced->setStyle(SCE_HJA_WORD, black);
		sced->setStyle(SCE_HJA_KEYWORD, black);
		sced->setStyle(SCE_HJA_DOUBLESTRING, darkGreen);
		sced->setStyle(SCE_HJA_SINGLESTRING, brown);
		sced->setStyle(SCE_HJA_SYMBOLS, black);

		// Show the whole section of Javascript with off white background
		for (int jstyle=SCE_HJ_DEFAULT; jstyle<=SCE_HJ_REGEX; jstyle++) 
		{
			sced->styleSetBack( jstyle, offGrey);
			sced->styleSetEolFilled( jstyle, 1);
		}

		// server side
		// Show the whole section of Javascript with brown background
		for (int jastyle=SCE_HJA_START; jastyle<=SCE_HJA_REGEX; jastyle++) {
			sced->styleSetBack(jastyle, offWhite);
			sced->styleSetEolFilled( jastyle, 1);
		}

		//php
		sced->setStyle( SCE_HPHP_DEFAULT, black );
		sced->setStyle( SCE_HPHP_HSTRING, darkGreen);
		sced->setStyle( SCE_HPHP_SIMPLESTRING , green);
		sced->setStyle( SCE_HPHP_WORD, darkblue );
		sced->styleSetBold(SCE_HPHP_WORD, 1);
		sced->setStyle( SCE_HPHP_NUMBER , lightblue);
		sced->setStyle( SCE_HPHP_VARIABLE , brown );
		sced->styleSetBold(SCE_HPHP_VARIABLE, 1);
		sced->setStyle( SCE_HPHP_COMMENT, darkGreen);
		sced->setStyle( SCE_HPHP_COMMENTLINE, darkGreen);
		sced->setStyle( SCE_HPHP_HSTRING_VARIABLE, orange );
		sced->setStyle( SCE_HPHP_OPERATOR, black);
		for (int pstyle=SCE_HPHP_DEFAULT; pstyle<=SCE_HPHP_OPERATOR; pstyle++) {
			sced->styleSetBack(pstyle, offWhite);
			sced->styleSetEolFilled( pstyle, 1);
		}
		sced->colorize(0);
	}

	void ScEdMode::initPerl(Scintilla* sced)
	{
		sced->setLexer(SCLEX_PERL);
		sced->setStyleBits(7);
		sced->setKeywords(0,perlKeyWords);

		//sced->setStyle(STYLE_DEFAULT, black, white, 10, "Courier New");	
		sced->setStyle(STYLE_DEFAULT, black, white, size, font.c_str());//"Courier New");	
		sced->styleClearAll();

		sced->styleSetBold(STYLE_BRACELIGHT,1);
		
        sced->setStyle(  SCE_PL_DEFAULT, black );
        sced->setStyle(  SCE_PL_ERROR, red );
        sced->setStyle(  SCE_PL_COMMENTLINE, grey );
		sced->styleSetBold(SCE_PL_COMMENTLINE, 0);
        sced->setStyle(  SCE_PL_POD, brown );
        sced->setStyle(  SCE_PL_NUMBER, lightblue );
        sced->setStyle(  SCE_PL_WORD , darkblue );

        sced->setStyle(  SCE_PL_STRING, darkGreen );
        sced->setStyle(  SCE_PL_CHARACTER, green );

        sced->setStyle(  SCE_PL_PUNCTUATION, black );
        sced->setStyle(  SCE_PL_PREPROCESSOR, grey );
        sced->setStyle(  SCE_PL_OPERATOR, black );
		sced->styleSetBold(SCE_PL_OPERATOR, 0);

        sced->setStyle(  SCE_PL_IDENTIFIER, black);
		sced->styleSetBold(SCE_PL_IDENTIFIER, 0);

        sced->setStyle(  SCE_PL_SCALAR, darkblue );
		sced->styleSetBold(SCE_PL_SCALAR, 1);
        sced->setStyle(  SCE_PL_ARRAY, blue );
		sced->styleSetBold(SCE_PL_ARRAY, 1);
        sced->setStyle(  SCE_PL_HASH, lightblue);
		sced->styleSetBold(SCE_PL_HASH, 1);
        sced->setStyle(  SCE_PL_SYMBOLTABLE, lightblue );

        sced->setStyle(  SCE_PL_REGEX, green );
        sced->setStyle(  SCE_PL_REGSUBST, green );
        sced->setStyle(  SCE_PL_LONGQUOTE, green );
        sced->setStyle(  SCE_PL_BACKTICKS, red );
        sced->setStyle(  SCE_PL_DATASECTION, grey );

        sced->setStyle(  SCE_PL_HERE_DELIM, orange );
        sced->setStyle(  SCE_PL_HERE_Q, darkGreen );
		sced->styleSetBack(SCE_PL_HERE_Q, offWhite);
		sced->styleSetEolFilled( SCE_PL_HERE_Q, 1);
        sced->setStyle(  SCE_PL_HERE_QQ, green );
		sced->styleSetBack(SCE_PL_HERE_QQ, offWhite);
		sced->styleSetEolFilled( SCE_PL_HERE_QQ, 1);
        sced->setStyle(  SCE_PL_HERE_QX, orange );
		sced->styleSetBack(SCE_PL_HERE_QX, offWhite);
		sced->styleSetEolFilled( SCE_PL_HERE_QX, 1);

        sced->setStyle(  SCE_PL_STRING_Q, green );
        sced->setStyle(  SCE_PL_STRING_QQ, green );
        sced->setStyle(  SCE_PL_STRING_QX, green );
        sced->setStyle(  SCE_PL_STRING_QR, green );
        sced->setStyle(  SCE_PL_STRING_QW, green );
		sced->colorize(0);
	}

	void ScEdMode::initCpp(Scintilla* sced)
	{
		sced->setLexer(SCLEX_CPP);
		sced->setStyleBits(7);
		sced->setKeywords(0,cppKeyWords);

		sced->setStyle(STYLE_DEFAULT, black, white, size, font.c_str());//"Courier New");	
		//sced->setStyle(STYLE_DEFAULT, black, white, 10, "Courier New");	
		sced->styleClearAll();		
		sced->styleSetBold(STYLE_BRACELIGHT,1);

        sced->setStyle( SCE_C_DEFAULT, black );
        sced->setStyle( SCE_C_COMMENT, grey );
		sced->styleSetBold(SCE_C_COMMENT, 0);
        sced->setStyle( SCE_C_COMMENTLINE, grey );
		sced->styleSetBold(SCE_C_COMMENTLINE, 0);
		sced->styleSetItalic(SCE_C_COMMENTLINE,0);
        sced->setStyle( SCE_C_COMMENTDOC, grey );
		sced->styleSetBold(SCE_C_COMMENTLINE, 0);
        sced->setStyle( SCE_C_NUMBER, lightblue);
        sced->setStyle( SCE_C_WORD, blue );
		sced->styleSetBold(SCE_C_WORD, 1);
        sced->setStyle( SCE_C_STRING, darkGreen );
        sced->setStyle( SCE_C_CHARACTER, brown );
        sced->setStyle( SCE_C_UUID, red );
        sced->setStyle( SCE_C_PREPROCESSOR, darkGreen );
		sced->styleSetBold(SCE_C_PREPROCESSOR, 0);
		sced->styleSetItalic(SCE_C_PREPROCESSOR,0);
        sced->setStyle( SCE_C_OPERATOR, black );
		sced->styleSetBold(SCE_C_OPERATOR, 0);
        sced->setStyle( SCE_C_IDENTIFIER, black );		
        sced->setStyle( SCE_C_STRINGEOL, red );
		sced->styleSetBold(SCE_C_STRINGEOL, 1);
        sced->setStyle( SCE_C_VERBATIM, orange );
        sced->setStyle( SCE_C_REGEX, orange );
        sced->setStyle( SCE_C_COMMENTLINEDOC, grey );
		sced->setStyle( SCE_C_WORD2, blue );
		sced->styleSetItalic(SCE_C_WORD2,1);
        sced->setStyle( SCE_C_COMMENTDOCKEYWORD, orange );
        sced->setStyle( SCE_C_COMMENTDOCKEYWORDERROR, orange );
        sced->setStyle( SCE_C_GLOBALCLASS, black );
		sced->colorize(0);
	}

	void ScEdMode::initCsharp(Scintilla* sced)
	{
		sced->setLexer(SCLEX_CPP);
		sced->setStyleBits(7);
		sced->setKeywords(0,csharpKeywords);

		sced->setStyle(STYLE_DEFAULT, black, white, size, font.c_str());//"Courier New");	
		//sced->setStyle(STYLE_DEFAULT, black, white, 10, "Courier New");	
		sced->styleClearAll();		
		sced->styleSetBold(STYLE_BRACELIGHT,1);

        sced->setStyle( SCE_C_DEFAULT, black );
        sced->setStyle( SCE_C_COMMENT, grey );
		sced->styleSetBold(SCE_C_COMMENT, 0);
        sced->setStyle( SCE_C_COMMENTLINE, grey );
		sced->styleSetBold(SCE_C_COMMENTLINE, 0);
		sced->styleSetItalic(SCE_C_COMMENTLINE,0);
        sced->setStyle( SCE_C_COMMENTDOC, grey );
		sced->styleSetBold(SCE_C_COMMENTLINE, 0);
        sced->setStyle( SCE_C_NUMBER, lightblue);
        sced->setStyle( SCE_C_WORD, blue );
		sced->styleSetBold(SCE_C_WORD, 1);
        sced->setStyle( SCE_C_STRING, darkGreen );
        sced->setStyle( SCE_C_CHARACTER, brown );
        sced->setStyle( SCE_C_UUID, red );
        sced->setStyle( SCE_C_PREPROCESSOR, darkGreen );
		sced->styleSetBold(SCE_C_PREPROCESSOR, 0);
		sced->styleSetItalic(SCE_C_PREPROCESSOR,0);
        sced->setStyle( SCE_C_OPERATOR, black );
		sced->styleSetBold(SCE_C_OPERATOR, 0);
        sced->setStyle( SCE_C_IDENTIFIER, black );		
        sced->setStyle( SCE_C_STRINGEOL, red );
		sced->styleSetBold(SCE_C_STRINGEOL, 1);
        sced->setStyle( SCE_C_VERBATIM, orange );
        sced->setStyle( SCE_C_REGEX, orange );
        sced->setStyle( SCE_C_COMMENTLINEDOC, grey );
		sced->setStyle( SCE_C_WORD2, blue );
		sced->styleSetItalic(SCE_C_WORD2,1);
        sced->setStyle( SCE_C_COMMENTDOCKEYWORD, orange );
        sced->setStyle( SCE_C_COMMENTDOCKEYWORDERROR, orange );
        sced->setStyle( SCE_C_GLOBALCLASS, black );
		sced->colorize(0);
	}

	void ScEdMode::initJava(Scintilla* sced)
	{
		this->initCpp(sced);
		sced->setLexer(SCLEX_CPP);
		sced->setKeywords(0,javaKeywords);
		//sced->styleSetBold(STYLE_BRACELIGHT,1);
		//sced->styleSetBold(SCE_C_OPERATOR , 0);
		sced->colorize(0);
	}

	void ScEdMode::initVb(Scintilla* sced)
	{
		//this->initCpp(sced);
		sced->setLexer(SCLEX_VB);
		sced->setKeywords(0,vbsKeyWords);
		sced->setStyle(STYLE_DEFAULT, black, white, size, font.c_str());//"Courier New");	
		//sced->setStyle(STYLE_DEFAULT, black, white, 10, "Courier New");	
		sced->styleClearAll();
		sced->styleSetBold(SCE_B_OPERATOR , 1);
		sced->setStyle(SCE_B_OPERATOR,darkblue);
		sced->styleSetBold(SCE_B_OPERATOR , 1);
		sced->setStyle(SCE_B_COMMENT,grey);
		sced->setStyle(SCE_B_NUMBER,blue);
		sced->setStyle(SCE_B_KEYWORD,black);
		sced->styleSetBold(SCE_B_KEYWORD , 1);
		sced->setStyle(SCE_B_STRING,darkGreen);
		sced->setStyle(SCE_B_DATE,orange);
		sced->colorize(0);    
    }

	void ScEdMode::initShell(Scintilla* sced)
	{
		this->initCpp(sced);
		sced->setLexer(SCLEX_BASH);
		sced->colorize(0);    
    }
	void ScEdMode::initSql(Scintilla* sced)
	{
		this->initCpp(sced);
		sced->setLexer(SCLEX_SQL);
		sced->setKeywords(0,sqlKeywords);
		sced->colorize(0);    
    }

	void ScEdMode::initJs(Scintilla* sced)
	{
		//this->initCpp(sced);
		sced->setLexer(SCLEX_CPP);
		sced->setKeywords(0,jsKeyWords);
		sced->setStyle(STYLE_DEFAULT, black, white, size, font.c_str());//"Courier New");	
		//sced->setStyle(STYLE_DEFAULT, black, white, 10, "Courier New");	
		sced->styleClearAll();
		sced->styleSetBold(STYLE_BRACELIGHT,1);
		sced->styleSetBold(SCE_C_OPERATOR , 0);
        sced->setStyle( SCE_C_DEFAULT, black );
        sced->setStyle( SCE_C_COMMENT, grey );
		sced->styleSetBold(SCE_C_COMMENT, 0);
        sced->setStyle( SCE_C_COMMENTLINE, grey );
		sced->styleSetBold(SCE_C_COMMENTLINE, 0);
		sced->styleSetItalic(SCE_C_COMMENTLINE,0);
        sced->setStyle( SCE_C_COMMENTDOC, grey );
		sced->styleSetBold(SCE_C_COMMENTLINE, 0);
        sced->setStyle( SCE_C_NUMBER, lightblue);
        sced->setStyle( SCE_C_WORD, blue );
		sced->styleSetBold(SCE_C_WORD, 1);
        sced->setStyle( SCE_C_STRING, darkGreen );
        sced->setStyle( SCE_C_CHARACTER, brown );
        sced->setStyle( SCE_C_UUID, red );
        sced->setStyle( SCE_C_PREPROCESSOR, lightGreen );
		sced->styleSetBold(SCE_C_PREPROCESSOR, 1);
		sced->styleSetItalic(SCE_C_PREPROCESSOR,0);
        sced->setStyle( SCE_C_OPERATOR, black );
		sced->styleSetBold(SCE_C_OPERATOR, 0);
        sced->setStyle( SCE_C_IDENTIFIER, black );		
        sced->setStyle( SCE_C_STRINGEOL, red );
		sced->styleSetBold(SCE_C_STRINGEOL, 1);
        sced->setStyle( SCE_C_VERBATIM, orange );
        sced->setStyle( SCE_C_REGEX, orange );
        sced->setStyle( SCE_C_COMMENTLINEDOC, grey );
		sced->setStyle( SCE_C_WORD2, blue );
		sced->styleSetItalic(SCE_C_WORD2,1);
        sced->setStyle( SCE_C_COMMENTDOCKEYWORD, orange );
        sced->setStyle( SCE_C_COMMENTDOCKEYWORDERROR, orange );
        sced->setStyle( SCE_C_GLOBALCLASS, black );
		sced->colorize(0);
	}

	void ScEdMode::initCss(Scintilla* sced)
	{
		sced->setLexer(SCLEX_CSS);
		sced->setStyleBits(7);
		sced->setKeywords(0,css1Keywords);
		sced->setKeywords(1,css2Keywords);
		sced->setStyle(STYLE_DEFAULT, black, white, size, font.c_str());//"Courier New");	
		//sced->setStyle(STYLE_DEFAULT, black, white, 10, "Courier New");	
		sced->styleClearAll();
		sced->styleSetBold(STYLE_BRACELIGHT,0);
		sced->styleSetBold(SCE_CSS_TAG, 1);
		sced->styleSetBold(SCE_CSS_CLASS, 1);
		sced->setStyle(SCE_CSS_CLASS, darkblue);
		sced->styleSetBold(SCE_CSS_PSEUDOCLASS, 1);
		sced->setStyle(SCE_CSS_PSEUDOCLASS, blue);

		sced->setStyle(SCE_CSS_UNKNOWN_PSEUDOCLASS, orange);
		sced->setStyle(SCE_CSS_UNKNOWN_IDENTIFIER, red);

		sced->setStyle(SCE_CSS_OPERATOR, darkblue);
		sced->styleSetBold(SCE_CSS_OPERATOR, 1);

		sced->setStyle(SCE_CSS_IDENTIFIER, lightblue);
		sced->styleSetBold(SCE_CSS_IDENTIFIER, 1);

		sced->setStyle(SCE_CSS_DIRECTIVE, brown);
		sced->setStyle(SCE_CSS_DOUBLESTRING, green);
		sced->setStyle(SCE_CSS_SINGLESTRING, lightGreen );

		sced->colorize(0);
	}



void ScEdMode::init ( const mol::string& p, const mol::string& ext )
{
	//mol::ci_string cis(ext.c_str());
	mol::string p2(mol::toString(p));

	if ( mol::icmp( ext, _T("htm")) == 0 ||
		 mol::icmp( ext, _T("html")) == 0 ||
		 mol::icmp( ext, _T("jsp")) == 0 ||
		 mol::icmp( ext, _T("php")) == 0 ||
		 mol::icmp( ext, _T("shtml")) == 0 ||
		 mol::icmp( ext, _T("mhtml")) == 0 ||
		 mol::icmp( ext, _T("mc")) == 0 ||
		 mol::icmp( ext, _T("htm")) == 0 ||
		 mol::icmp( mol::Path::filename(p2), _T("autohandler")) == 0 ||
		 mol::icmp( mol::Path::filename(p2), _T("dhandler"))  == 0
		)
	{
		modes = SCINTILLA_SYNTAX_HTML;
		return;
	}
	if ( mol::icmp( ext, _T("h"))  == 0||
		 mol::icmp( ext, _T("hpp"))  == 0||
		 mol::icmp( ext, _T("c"))  == 0||
		 mol::icmp( ext, _T("cpp"))  == 0||
		 mol::icmp( ext, _T("cxx")) == 0 
	    )
	{
		modes = SCINTILLA_SYNTAX_CPP;
		return;
	}
	if ( mol::icmp( ext, _T("java") ) == 0 )
	{
		modes = SCINTILLA_SYNTAX_JAVA;
		return;
	}
	if ( mol::icmp( ext, _T("cs")  ) == 0 )
	{
		modes = SCINTILLA_SYNTAX_CSHARP;
		return;
	}
	if ( mol::icmp( ext, _T("pl")) == 0 ||
		 mol::icmp( ext, _T("pm")) == 0 ||
		 mol::icmp( ext, _T("cgi")) == 0 ||
		 mol::icmp( ext, _T("pls")) == 0 
		)
	{
		modes = SCINTILLA_SYNTAX_PERL;
		return;
	}
	if ( mol::icmp( ext, _T("js") ) == 0 )
	{
		modes = SCINTILLA_SYNTAX_JS;
		return;
	}
	if ( mol::icmp( ext, _T("css") ) == 0 )
	{
		modes = SCINTILLA_SYNTAX_CSS;
		return;
	}

	if ( mol::icmp( ext, _T("bas"))  == 0||
		 mol::icmp( ext, _T("vbs"))  == 0
		 )
	{
		modes = SCINTILLA_SYNTAX_VB;
		return;
	}
    if ( mol::icmp( ext, _T("sh") )  == 0)
    {
        modes = SCINTILLA_SYNTAX_SHELL;
        return;
    }
    if ( mol::icmp( ext, _T("sql") ) == 0 )
    {
        modes = SCINTILLA_SYNTAX_SQL;
        return;
    }
	modes = SCINTILLA_SYNTAX_PLAIN;
}

 void ScEdMode::init(Scintilla* sced)
{
	switch ( modes )
	{
		case SCINTILLA_SYNTAX_PLAIN:
			return initPlain(sced);
		case SCINTILLA_SYNTAX_HTML:
			return initHtml(sced);
		case SCINTILLA_SYNTAX_PERL:
			return initPerl(sced);
		case SCINTILLA_SYNTAX_CPP:
			return initCpp(sced);
		case SCINTILLA_SYNTAX_JAVA:
			return initJava(sced);
		case SCINTILLA_SYNTAX_JS:
			return initJs(sced);
		case SCINTILLA_SYNTAX_VB:
			return initVb(sced);
		case SCINTILLA_SYNTAX_CSS:
			return initCss(sced);			
		case SCINTILLA_SYNTAX_SQL:
			return initSql(sced);			
		case SCINTILLA_SYNTAX_SHELL:
			return initShell(sced);			
		case SCINTILLA_SYNTAX_CSHARP:
			return initCsharp(sced);	
	}
}

ScintillaEditor::ScintillaEditor()
{
}

ScintillaEditor::~ScintillaEditor()
{}

SCINTILLA_SYNTAX ScintillaEditor::mode() 
{ 
    return mod_.modes ; 
}

SCINTILLA_SYNTAX ScintillaEditor::mode( SCINTILLA_SYNTAX m, int s, const mol::string& f  ) 
{ 
    SCINTILLA_SYNTAX ret = mod_.modes ; 
	mod_.modes = m; 
	mod_.size = s;
	mod_.font = mol::tostring(f);
	init(); 
	return ret; 
}

SCINTILLA_SYNTAX ScintillaEditor::mode( const mol::string& path, const mol::string& ext ) 
{ 
    SCINTILLA_SYNTAX ret = mod_.modes ; 
	mod_.init(path,ext); 
	init(); 
	return ret; 
}




void ScintillaEditor::init()
{
	mod_.init(this);

	this->setStyle(SCI_ANNO_ERRORSTYLE,ScEdMode::red,ScEdMode::offGrey);
	showAnnotations(2);
}


HWND ScintillaEditor::createWindow( const mol::string& windowName, HMENU hMenu, const mol::Rect& r, HWND parent )
{
    hWnd_ = ::CreateWindowEx ( exstyle(),wndClassName().c_str(),
                               windowName.c_str(), style(),
                               r.left, r.top, r.right, r.bottom,
							   parent, (HMENU)hMenu, mol::hinstance(),(PVOID)this );
    subClass();
	init();
    this->OnCtrlCreated();
    return hWnd_;
}

void ScintillaEditor::print()
{
	static DOCINFO di = { sizeof(DOCINFO), _T("mol scintilla print job") };
	BOOL bSuccess = TRUE;
	HDC hdcPrinter;
	int xPage,yPage;

	//hdcPrinter = getPrinterDC();
	int copies = 0;
	bool collate = false;
	hdcPrinter = choosePrinterDC(*this,copies,collate);
	if ( NULL == hdcPrinter )
		return;

	int copies1 = collate ? 1 : copies ;
	int copies2 = collate ? copies : 1 ;
	for ( int  i = 0; i < copies1; i++ )
	{
		xPage = ::GetDeviceCaps( hdcPrinter, HORZRES );
		yPage = ::GetDeviceCaps( hdcPrinter, VERTRES );

		RangeToFormat rtf;
		rtf.hdc = hdcPrinter;
		rtf.hdcTarget = hdcPrinter;
		rtf.chrg.cpMin = 0;
		rtf.chrg.cpMax = this->getLength();
		rtf.rc.left = 0;
		rtf.rc.top = 0;
		rtf.rc.right = xPage-1;
		rtf.rc.bottom = yPage-1;
		rtf.rcPage = rtf.rc;
		rtf.rc.left += 130;
		rtf.rc.top  += 130;
		rtf.rc.right -= 260;
		rtf.rc.bottom -=260;

		if ( ::StartDoc( hdcPrinter, &di ) )
		{
			while ( rtf.chrg.cpMin < rtf.chrg.cpMax )
			{
				if ( ::StartPage( hdcPrinter ) > 0 )
				{
					RangeToFormat r = rtf;

					for ( int j = 0; j < copies2; j++ )
					{
						rtf.chrg.cpMin = this->printPage(true,&r);
					}
					if ( ::EndPage(hdcPrinter) <= 0 )
						break;
				}
			}
			::EndDoc(hdcPrinter);
		}
	}
	::DeleteDC(hdcPrinter);
}

HDC getPrinterDC()
{
	DWORD dwNeeded, dwReturned;
	HDC hdc;
	PRINTER_INFO_5* pinfo5;

	if ( ::GetVersion() & 0x80000000 ) // win98
	{
		::EnumPrinters(PRINTER_ENUM_DEFAULT,NULL,5,NULL,0,&dwNeeded,&dwReturned);
		pinfo5 = (PRINTER_INFO_5*)malloc(dwNeeded);
		::EnumPrinters(PRINTER_ENUM_DEFAULT,NULL,5,(PBYTE)pinfo5,dwNeeded,&dwNeeded,&dwReturned);
		hdc = ::CreateDC( 0, pinfo5->pPrinterName,0,0);
		free(pinfo5);
	}
	else
	{
		DWORD len = 256;
		mol::TCHAR buf[256];
		::GetDefaultPrinter(buf,&len);
		hdc = ::CreateDC( 0, buf,0,0);
	}
	return hdc;
}

HDC choosePrinterDC(HWND owner, int& copies, bool& collate)
{
	PRINTDLG pd;

	// Initialize PRINTDLG
	ZeroMemory(&pd, sizeof(pd));
	pd.lStructSize = sizeof(pd);
	pd.hwndOwner   = owner;
	pd.hDevMode    = NULL;     // Don't forget to free or store hDevMode
	pd.hDevNames   = NULL;     // Don't forget to free or store hDevNames
	pd.Flags       = PD_USEDEVMODECOPIESANDCOLLATE | PD_RETURNDC |PD_NOPAGENUMS|PD_NOSELECTION; 
	pd.nCopies     = 1;
	pd.nFromPage   = 0xFFFF; 
	pd.nToPage     = 0xFFFF; 
	pd.nMinPage    = 1; 
	pd.nMaxPage    = 0xFFFF; 

	copies = 0;
	collate = false;
	if (PrintDlg(&pd)==TRUE) 
	{
		collate = (pd.Flags & PD_COLLATE) != 0;
		copies  = pd.nCopies;
		return pd.hDC;
	}
	return 0;
}

void ScintillaEditor::setFont(int size, const mol::string& font)
{
	setStyle(STYLE_DEFAULT, ScEdMode::black, ScEdMode::white, size, mol::tostring(font).c_str() );	
}


mol::string ScintillaEditor::SyntaxDisplayName()
{
	return SyntaxDisplayName(mod_.modes);
}

bool ScintillaEditor::showLineNumbers()
{
	int w = sendMessage( SCI_GETMARGINWIDTHN, (WPARAM)0 , (LPARAM)0 );
	return w != 0;
}

void ScintillaEditor::showLineNumbers(bool b)
{
	if ( b == false )
	{
		sendMessage( SCI_SETMARGINWIDTHN, (WPARAM)(0), (LPARAM)(0) );
		sendMessage( SCI_SETMARGINWIDTHN, (WPARAM)(1), (LPARAM)(0) );
		return;
	}

	int lines = getLineCount();
	std::ostringstream oss;
	oss << "_" << lines;

	int w = sendMessage( SCI_TEXTWIDTH, (WPARAM)STYLE_LINENUMBER, (LPARAM)(oss.str().c_str()) );
	sendMessage( SCI_SETMARGINWIDTHN, (WPARAM)(0), (LPARAM)(w) );
	sendMessage( SCI_SETMARGINWIDTHN, (WPARAM)(1), (LPARAM)(4) );
}



mol::string ScintillaEditor::SyntaxDisplayName(int syntax)
{
	switch ( syntax )
	{
		case SCINTILLA_SYNTAX_HTML:
			return _T("html");
		case SCINTILLA_SYNTAX_PERL:
			return _T("perl");
		case SCINTILLA_SYNTAX_CPP:
			return _T("cpp");
		case SCINTILLA_SYNTAX_JAVA:
			return _T("java");
		case SCINTILLA_SYNTAX_JS:
			return _T("js");
		case SCINTILLA_SYNTAX_VB:
			return _T("vb");
		case SCINTILLA_SYNTAX_CSS:
			return _T("css");
		case SCINTILLA_SYNTAX_SQL:
			return _T("sql");
		case SCINTILLA_SYNTAX_SHELL:
			return _T("shell");
		case SCINTILLA_SYNTAX_CSHARP:
			return _T("c#");
	}
	return _T("txt");
}
