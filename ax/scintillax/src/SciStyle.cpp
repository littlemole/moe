#include "stdafx.h"
#include "SciStyle.h"

 const COLORREF black = RGB(0,0,0);
 const COLORREF white = RGB(0xff,0xff,0xff);
 const COLORREF red = RGB(0xFF, 0, 0);
 const COLORREF offWhite = RGB(0xF0, 0xF0, 0xF0);
 const COLORREF offGrey =  RGB(0xE2, 0xE2, 0xE2);
 const COLORREF lightGreen = RGB(5, 0x90, 5);
 const COLORREF green = RGB(0, 0x90, 0);
 const COLORREF darkGreen = RGB(0, 0x60, 0);
 const COLORREF darkblue = RGB(0, 0, 0x80);
 const COLORREF blue = RGB(0x15, 0x25, 0xA0);
 const COLORREF lightblue = RGB(0x30, 0x50, 0xC0);
 const COLORREF grey = RGB(0x70, 0x70, 0x70);
 const COLORREF orange = RGB(0xFF, 0x80, 0x00);
 const COLORREF brown = RGB(0x80, 0x40, 0x00);

 const std::string htmlKeyWords = 
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

const std::string jsKeyWords = 
	"break case catch continue default "
	"do else for function if return throw try var while";

const std::string vbsKeyWords = 
	"and as byref byval case call const is"
	"continue dim do each else elseif end error exit false for function global "
	"goto if in loop me new next not nothing on optional or private public "
	"redim rem resume select set sub then to true type while with "
	"boolean byte currency date double integer long object single string type "
	"variant";

const std::string phpKeyWords = 
	"and argv as argc break case cfunction class continue declare default do "
	"die echo else elseif empty enddeclare endfor endforeach endif endswitch "
	"endwhile e_all e_parse e_error e_warning eval exit extends false for "
	"foreach function global http_cookie_vars http_get_vars http_post_vars "
	"http_post_files http_env_vars http_server_vars if include include_once "
	"list new not null old_function or parent php_os php_self php_version "
	"print require require_once return static switch stdclass this true var "
	"xor virtual while __file__ __line__ __sleep __wakeup";

const std::string perlKeyWords = 
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

const std::string cppKeyWords = 
"and and_eq asm auto bitand bitor bool break "
"case catch char class compl const const_cast continue "
"default delete do double dynamic_cast else enum explicit export extern false float for "
"friend goto if inline int long mutable namespace new not not_eq "
"operator or or_eq private protected public "
"register reinterpret_cast return short signed sizeof static static_cast struct switch "
"template this throw true try typedef typeid typename union unsigned using "
"virtual void volatile wchar_t while xor xor_eq";

const std::string javaKeywords = 
"abstract assert boolean break byte case catch char class "
"const continue default do double else extends final finally float for future "
"generic goto if implements import inner instanceof int interface long "
"native new null outer package private protected public rest "
"return short static super switch synchronized this throw throws "
"transient try var void volatile while";

const std::string css1Keywords = 
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

const std::string css2Keywords = 
"first-letter first-line active link visited";

const std::string sqlKeywords = 
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

const std::string csharpKeywords = 
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


 std::string font = "Courier New";

	// Style(WPARAM style, bool bold, bool italic, bool eol,const char* font, long size, COLORREF fore, COLORREF back, const char* desc) 

#define STYLE(style,bold,italic,eol,font,size,fore,back) \
	{ style, bold, italic, eol, font.c_str(), size, fore, back, #style }

static Style plainStyles[] = { 
	STYLE(STYLE_DEFAULT, 0, 0, 0, font, 10, black, white),
	STYLE(STYLE_LINENUMBER, 0, 0, 0, font, 10, black, white)
};

static Style htmlStyles[] = { 
	STYLE(STYLE_DEFAULT, 0, 0, 0, font, 10, black, white),
	STYLE(STYLE_LINENUMBER, 0, 0, 0, font, 10, black, white),
	STYLE(STYLE_BRACELIGHT, 1, 0, 0, font, 10, black, white),
	STYLE(SCE_H_DEFAULT, 0, 0, 0, font, 10, darkblue, white),
	STYLE(SCE_H_TAG, 1, 0, 0, font, 10, darkblue, white),
	STYLE(SCE_H_TAGUNKNOWN, 1, 0, 0, font, 10, blue, white),
	STYLE(SCE_H_ATTRIBUTE, 1, 0, 0, font, 10, darkblue, white),
	STYLE(SCE_H_ATTRIBUTEUNKNOWN, 1, 0, 0, font, 10, blue, white),
	STYLE(SCE_H_NUMBER, 0, 0, 0, font, 10, lightblue, white),
	STYLE(SCE_H_DOUBLESTRING, 0, 0, 0, font, 10, darkGreen, white),
	STYLE(SCE_H_SINGLESTRING, 0, 0, 0, font, 10, darkGreen, white),
	STYLE(SCE_H_OTHER, 0, 0, 0, font, 10, RGB(0x80,0,0x80), white),
	STYLE(SCE_H_COMMENT, 0, 1, 0, font, 10, grey, white),
	STYLE(SCE_H_ENTITY, 0, 0, 0, font, 10, brown, white),
	STYLE(SCE_H_TAGEND, 0, 0, 0, font, 10, darkblue, white),
	STYLE(SCE_H_XMLSTART, 0, 0, 0, font, 10, darkblue, white),
	STYLE(SCE_H_XMLEND, 0, 0, 0, font, 10, darkblue, white),
	STYLE(SCE_H_SCRIPT, 0, 0, 0, font, 10, darkblue, white),
	STYLE(SCE_H_ASP, 0, 0, 0, font, 10, RGB(0x4F, 0x4F, 0), offWhite),
	STYLE(SCE_H_ASPAT, 0, 0, 0, font, 10, RGB(0x4F, 0x4F, 0), offWhite),
	STYLE(SCE_H_CDATA,0,0,0,font,10,black,white),
	STYLE(SCE_H_QUESTION,0,0,0,font,10,black,white),
	STYLE(SCE_H_VALUE,0,0,0,font,10,black,white),
	STYLE(SCE_H_XCCOMMENT,0,0,0,font,10,black,white),
	STYLE(SCE_HB_START, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HB_DEFAULT, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HB_COMMENTLINE, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HB_NUMBER, 0, 0, 1, font, 10, RGB(0,0x80,0x80), offWhite),
	STYLE(SCE_HB_WORD, 1, 0, 1, font, 10, darkblue, offWhite),
	STYLE(SCE_HB_STRING, 0, 0, 1, font, 10, RGB(0x80,0,0x80), offWhite),
	STYLE(SCE_HB_IDENTIFIER, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HB_STRINGEOL, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HBA_START, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HBA_DEFAULT, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HBA_COMMENTLINE, 0, 0, 1, font, 10, darkGreen, offWhite),
	STYLE(SCE_HBA_NUMBER, 0, 0, 1, font, 10, RGB(0,0x80,0x80), offWhite),
	STYLE(SCE_HBA_WORD, 1, 0, 1, font, 10, darkblue, offWhite),
	STYLE(SCE_HBA_STRING, 0, 0, 1, font, 10, RGB(0x80,0,0x80), offWhite),
	STYLE(SCE_HBA_IDENTIFIER, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HBA_STRINGEOL, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HJ_START, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HJ_DEFAULT, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HJ_COMMENT, 0, 1, 1, font, 10, grey, offWhite),
	STYLE(SCE_HJ_COMMENTLINE, 0, 1, 1, font, 10, grey, offWhite),
	STYLE(SCE_HJ_COMMENTDOC, 0, 1, 1, font, 10, grey, offWhite),
	STYLE(SCE_HJ_NUMBER, 0, 0, 1, font, 10, lightblue, offWhite),
	STYLE(SCE_HJ_WORD, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HJ_KEYWORD, 1, 0, 1, font, 10, darkblue, offWhite),
	STYLE(SCE_HJ_DOUBLESTRING, 0, 0, 1, font, 10, darkGreen, offWhite),
	STYLE(SCE_HJ_SINGLESTRING, 0, 0, 1, font, 10, brown, offWhite),
	STYLE(SCE_HJ_SYMBOLS, 0, 0, 1, font, 10, brown, offWhite),
	STYLE(SCE_HJA_START, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HJA_DEFAULT, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HJA_COMMENT, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HJA_COMMENTLINE, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HJA_COMMENTDOC, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HJA_NUMBER, 0, 0, 1, font, 10, lightblue, offWhite),
	STYLE(SCE_HJA_WORD, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HJA_KEYWORD, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HJA_DOUBLESTRING, 0, 0, 1, font, 10, darkGreen, offWhite),
	STYLE(SCE_HJA_SINGLESTRING, 0, 0, 1, font, 10, brown, offWhite),
	STYLE(SCE_HJA_SYMBOLS, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HJA_STRINGEOL, 0, 0, 1, font, 10, black, offWhite),
	STYLE(SCE_HJA_REGEX, 0, 0, 1, font, 10, black, offWhite),
};	

static Style perlStyles[] = { 
	STYLE(STYLE_DEFAULT, 0, 0, 0, font, 10, black, white),
	STYLE(STYLE_LINENUMBER, 0, 0, 0, font, 10, black, white),
	STYLE(STYLE_BRACELIGHT, 1, 0, 0, font, 10, black, white),
	STYLE(SCE_PL_DEFAULT, 0, 0, 0, font, 10, black, white),
	STYLE(SCE_PL_ERROR, 0, 0, 0, font, 10, red, white),
	STYLE(SCE_PL_COMMENTLINE, 0, 0, 0, font, 10, grey, white),
	STYLE(SCE_PL_POD, 0, 0, 0, font, 10, brown, white),
	STYLE(SCE_PL_NUMBER, 0, 0, 0, font, 10, lightblue, white),
	STYLE(SCE_PL_WORD, 0, 0, 0, font, 10, darkblue, white),
	STYLE(SCE_PL_STRING, 0, 0, 0, font, 10, darkGreen, white),
	STYLE(SCE_PL_CHARACTER, 0, 0, 0, font, 10, green, white),
	STYLE(SCE_PL_PUNCTUATION, 0, 0, 0, font, 10, black, white),
	STYLE(SCE_PL_PREPROCESSOR, 0, 0, 0, font, 10, grey, white),
	STYLE(SCE_PL_OPERATOR, 1, 0, 0, font, 10, black, white),
	STYLE(SCE_PL_IDENTIFIER, 0, 0, 0, font, 10, black, white),
	STYLE(SCE_PL_SCALAR, 1, 0, 0, font, 10, darkblue, white),
	STYLE(SCE_PL_ARRAY, 1, 0, 0, font, 10, lightblue, white),
	STYLE(SCE_PL_HASH, 1, 0, 0, font, 10, lightblue, white),
	STYLE(SCE_PL_SYMBOLTABLE, 0, 0, 0, font, 10, lightblue, white),
	STYLE(SCE_PL_REGEX, 0, 0, 0, font, 10, green, white),
	STYLE(SCE_PL_REGSUBST, 0, 0, 0, font, 10, green, white),
	STYLE(SCE_PL_LONGQUOTE, 0, 0, 0, font, 10, green, white),
	STYLE(SCE_PL_BACKTICKS, 0, 0, 0, font, 10, red, white),
	STYLE(SCE_PL_DATASECTION, 0, 0, 0, font, 10, grey, white),
	STYLE(SCE_PL_HERE_DELIM, 0, 0, 0, font, 10, orange, white),
	STYLE(SCE_PL_HERE_Q, 0, 0, 1, font, 10, darkGreen, offWhite),
	STYLE(SCE_PL_HERE_QQ, 0, 0, 1, font, 10, green, offWhite),
	STYLE(SCE_PL_HERE_QX, 0, 0, 1, font, 10, orange, offWhite),
	STYLE(SCE_PL_STRING_Q, 0, 0, 0, font, 10, green, white),
	STYLE(SCE_PL_STRING_QQ, 0, 0, 0, font, 10, green, white),
	STYLE(SCE_PL_STRING_QX, 0, 0, 0, font, 10, green, white),
	STYLE(SCE_PL_STRING_QR, 0, 0, 0, font, 10, green, white),
	STYLE(SCE_PL_STRING_QW, 0, 0, 0, font, 10, green, white),
	STYLE(SCE_PL_POD_VERB,0,0,0,font,10,black,white),
	STYLE(SCE_PL_SUB_PROTOTYPE,0,0,0,font,10,black,white),
	STYLE(SCE_PL_FORMAT_IDENT,0,0,0,font,10,black,white),
	STYLE(SCE_PL_FORMAT,0,0,0,font,10,black,white)

};

static Style cppStyles[] = { 
	STYLE(STYLE_DEFAULT, 0, 0, 0, font, 10, black, white),
	STYLE(STYLE_LINENUMBER, 0, 0, 0, font, 10, black, white),
	STYLE(STYLE_BRACELIGHT, 1, 0, 0, font, 10, black, white),
	STYLE(SCE_C_DEFAULT,0,0,0,font,10,black,white),
	STYLE(SCE_C_COMMENT, 0, 0, 0, font, 10, grey, white),
	STYLE(SCE_C_COMMENTLINE, 0, 0, 0, font, 10, grey, white),
	STYLE(SCE_C_COMMENTDOC, 0, 0, 0, font, 10, grey, white),
	STYLE(SCE_C_NUMBER, 0, 0, 0, font, 10, lightblue, white),
	STYLE(SCE_C_WORD, 1, 0, 0, font, 10, blue, white),
	STYLE(SCE_C_STRING, 0, 0, 0, font, 10, darkGreen, white),
	STYLE(SCE_C_CHARACTER, 0, 0, 0, font, 10, brown, white),
	STYLE(SCE_C_UUID, 0, 0, 0, font, 10, red, white),
	STYLE(SCE_C_PREPROCESSOR, 0, 0, 0, font, 10, darkGreen, white),
	STYLE(SCE_C_OPERATOR, 0, 0, 0, font, 10, black, white),
	STYLE(SCE_C_IDENTIFIER, 0, 0, 0, font, 10, black, white),
	STYLE(SCE_C_STRINGEOL, 0, 0, 0, font, 10, red, white),
	STYLE(SCE_C_VERBATIM, 0, 0, 0, font, 10, black, orange),
	STYLE(SCE_C_REGEX, 0, 0, 0, font, 10, black, orange),
	STYLE(SCE_C_COMMENTLINEDOC, 0, 0, 0, font, 10, grey, white),
	STYLE(SCE_C_WORD2, 0, 0, 0, font, 10, blue, white),
	STYLE(SCE_C_COMMENTDOCKEYWORD, 0, 0, 0, font, 10, orange, white),
	STYLE(SCE_C_COMMENTDOCKEYWORDERROR, 0, 0, 0, font, 10, orange, white),
	STYLE(SCE_C_GLOBALCLASS, 0, 0, 0, font, 10, black, white)

};

static Style vbStyles[] = { 
	STYLE(STYLE_DEFAULT, 0, 0, 0, font, 10, black, white),
	STYLE(STYLE_LINENUMBER, 0, 0, 0, font, 10, black, white),
	STYLE(SCE_B_OPERATOR, 1, 0, 0, font, 10, darkblue, white),
	STYLE(SCE_B_COMMENT, 0, 0, 0, font, 10, blue, white),
	STYLE(SCE_B_KEYWORD, 1, 0, 0, font, 10, black, white),
	STYLE(SCE_B_STRING, 0, 0, 0, font, 10, darkGreen, white),
	STYLE(SCE_B_DATE, 0, 0, 0, font, 10, orange, white)
};

static Style jsStyles[] = { 
	STYLE(STYLE_DEFAULT, 0, 0, 0, font, 10, black, white),
	STYLE(STYLE_LINENUMBER, 0, 0, 0, font, 10, black, white),
	STYLE(STYLE_BRACELIGHT, 1, 0, 0, font, 10, black, white),
	STYLE(SCE_C_OPERATOR, 0, 0, 0, font, 10, black, white),
	STYLE(SCE_C_DEFAULT, 0, 0, 0, font, 10, black, white),
	STYLE(SCE_C_COMMENT, 0, 0, 0, font, 10, grey, white),
	STYLE(SCE_C_COMMENTLINE, 0, 0, 0, font, 10, grey, white),
	STYLE(SCE_C_COMMENTDOC, 0, 0, 0, font, 10, grey, white),
	STYLE(SCE_C_NUMBER, 0, 0, 0, font, 10, lightblue, white),
	STYLE(SCE_C_WORD, 0, 0, 0, font, 10, blue, white),
	STYLE(SCE_C_STRING, 0, 0, 0, font, 10, darkGreen, white),
	STYLE(SCE_C_CHARACTER, 0, 0, 0, font, 10, brown, white),
	STYLE(SCE_C_UUID, 0, 0, 0, font, 10, red, white),
	STYLE(SCE_C_PREPROCESSOR, 0, 0, 0, font, 10, lightGreen, white),
	STYLE(SCE_C_OPERATOR, 0, 0, 0, font, 10, black, white),
	STYLE(SCE_C_IDENTIFIER, 0, 0, 0, font, 10, black, white),
	STYLE(SCE_C_STRINGEOL, 1, 0, 0, font, 10, red, white),
	STYLE(SCE_C_VERBATIM, 0, 0, 0, font, 10, orange, white),
	STYLE(SCE_C_REGEX, 0, 0, 0, font, 10, orange, white),
	STYLE(SCE_C_COMMENTLINEDOC, 0, 0, 0, font, 10, grey, white),
	STYLE(SCE_C_WORD2, 0, 1, 0, font, 10, blue, white),
	STYLE(SCE_C_COMMENTDOCKEYWORD, 0, 0, 0, font, 10, orange, white),
	STYLE(SCE_C_COMMENTDOCKEYWORDERROR, 0, 0, 0, font, 10, orange, white),
	STYLE(SCE_C_GLOBALCLASS, 0, 0, 0, font, 10, black, white),
};

 
static Style cssStyles[] = { 
	STYLE(STYLE_DEFAULT, 0, 0, 0, font, 10, black, white),
	STYLE(STYLE_LINENUMBER, 0, 0, 0, font, 10, black, white),
	STYLE(STYLE_BRACELIGHT, 1, 0, 0, font, 10, black, white),
	STYLE(SCE_CSS_TAG, 1, 0, 0, font, 10, black, white),
	STYLE(SCE_CSS_CLASS, 1, 0, 0, font, 10, darkblue, white),
	STYLE(SCE_CSS_PSEUDOCLASS, 1, 0, 0, font, 10, blue, white),
	STYLE(SCE_CSS_UNKNOWN_PSEUDOCLASS, 0, 0, 0, font, 10, orange, white),
	STYLE(SCE_CSS_UNKNOWN_IDENTIFIER, 0, 0, 0, font, 10, red, white),
	STYLE(SCE_CSS_OPERATOR, 1, 0, 0, font, 10, darkblue, white),
	STYLE(SCE_CSS_IDENTIFIER, 1, 0, 0, font, 10, lightblue, white),
	STYLE(SCE_CSS_DIRECTIVE, 0, 0, 0, font, 10, brown, white),
	STYLE(SCE_CSS_DOUBLESTRING, 0, 0, 0, font, 10, green, white),
	STYLE(SCE_CSS_SINGLESTRING, 0, 0, 0, font, 10, lightGreen, white)
};

AxStyleSets::Instance* AxStyleSets::CreateInstance()
{
	Instance* d = new Instance; 
	d->AddRef();
	return d;
}


HRESULT __stdcall  AxStyleSets::_NewEnum(IEnumVARIANT** newEnum)
{
	mol::punk<mol::com_obj<mol::enum_variant> > ev = new mol::com_obj<mol::enum_variant>;
	for ( std::vector<mol::variant>::iterator it = collection_.begin(); it != collection_.end(); it++)
	{
		ev->add((*it));
	}
	return ev->QueryInterface(IID_IEnumVARIANT,(void**)newEnum);
}

HRESULT __stdcall  AxStyleSets::get_Count( long* cnt)
{
	if (!cnt)
		return E_INVALIDARG;

	*cnt = collection_.size();
	return S_OK;
}


HRESULT __stdcall  AxStyleSets::Item( VARIANT index, IScintillAxStyleSet** item)
{
	if ( !item )
		return E_INVALIDARG;

	*item = 0;
	mol::variant v(index);
	v.changeType(VT_I4);

	long i = v.lVal;
	if ( i < 0 || i >= collection_.size() ) {
		return E_INVALIDARG;
	}

	if ( collection_[i].vt != VT_DISPATCH || !collection_[i].pdispVal )
		return E_FAIL;

	return collection_[i].pdispVal->QueryInterface(IID_IScintillAxStyleSet, (void**)item);
}



HRESULT __stdcall AxStyleSets::Load( LPSTREAM pStm)
{
	if (!pStm)
		return E_INVALIDARG;

	long cnt = 0;
	pStm >> mol::property(&cnt);
	if(cnt>0)
	{
		for ( long i = 0; i < cnt; i++)
		{
			long id = 0;
//			pStm >> mol::property(&id);

			mol::punk<IScintillAxStyleSet> styleSet = AxStyleSet::CreateInstance(id);
			mol::punk<IPersistStream> ps(styleSet);
			if(ps)
			{
				ps->Load(pStm);
			}
			collection_.push_back(mol::variant(styleSet));
		}
	}

	return S_OK;
}

HRESULT __stdcall AxStyleSets::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	long cnt = collection_.size();
	pStm << mol::property(&cnt);

	for ( long i = 0; i < cnt; i++)
	{
		mol::variant item(collection_[i]);
		if(item.vt == VT_DISPATCH)
		{
			mol::punk<IScintillAxStyleSet> styleSet(item.pdispVal);
			if(styleSet)
			{
//				long id = 0;
	//			hr = styleSet->get_Id(&id);
		//		if (hr == S_OK )
				{
					mol::punk<IPersistStream> ps(styleSet);
					if(ps)
					{
						//pStm << mol::property(&id);
						ps->Save(pStm,fClearDirty);
					}
				}
			}
		}
	}

	return S_OK;
}

HRESULT __stdcall AxStyleSets::GetClassID( CLSID *pClassID) 
{
	if (!pClassID)
	{
		return E_INVALIDARG;
	}
	*pClassID = CLSID_ScintillAxStyleSets;
	return S_OK;
}

HRESULT __stdcall AxStyleSets::IsDirty( )
{
	return S_OK;
}

HRESULT __stdcall AxStyleSets::GetSizeMax( ULARGE_INTEGER* ui ) 
{
	return S_OK;
}

const char* rgb2hex( COLORREF col )
{
    static char ret[12];
    char buf[12];

    wsprintfA(buf,"%06X",col);

    ret[0] = '#';
    (ret[1]) = (buf[4]);
    (ret[2]) = (buf[5]);
    (ret[3]) = (buf[2]);
    (ret[4]) = (buf[3]);
    (ret[5]) = (buf[0]);
    (ret[6]) = (buf[1]);
    ret[7] = 0;
    return ret;
}


HRESULT make_style( Style& style, AxStyle** result)
{
	*result = AxStyle::CreateInstance();
	(*result)->put_Bold(style.bold_ ? VARIANT_TRUE : VARIANT_FALSE);
	(*result)->put_Italic(style.italic_ ? VARIANT_TRUE : VARIANT_FALSE);
	(*result)->put_Eol(style.eol_ ? VARIANT_TRUE : VARIANT_FALSE);
	(*result)->put_Fontname(mol::bstr(style.font_));
	(*result)->put_Fontsize(style.size_);
	(*result)->put_Forecolor(mol::bstr(rgb2hex(style.foreColor_)));
	(*result)->put_Backcolor(mol::bstr(rgb2hex(style.backColor_)));
	(*result)->desc_ = style.description_;
	(*result)->id_ = style.style_;
	return S_OK;
}

HRESULT make_set( long id, Style* styles, int nStyles, AxStyleSet** result)
{
	*result = AxStyleSet::CreateInstance(id);

	for ( int i = 0; i < nStyles; i++)
	{
		AxStyle* style = 0;
		make_style(styles[i],&style);
		//(*result)->collection_.Insert( mol::variant((LONG)styles[i].style_), mol::variant((IScintillAxStyle*)style) );
		(*result)->collection_.push_back( mol::variant((IScintillAxStyle*)style) );
		((IScintillAxStyle*)style)->Release();
	}
	return S_OK;
}

#define MAKE_STYLE(set,mode,lex,styles,keywords)											\
	AxStyleSet* set = 0;																	\
	make_set(lex,styles,sizeof(styles)/sizeof(*(styles)),&set);								\
	set->AddKeyWords( mol::bstr(##keywords) );												\
	collection_.push_back( mol::variant((IScintillAxStyleSet*)set) );						\
	((IScintillAxStyleSet*)set)->Release();													\



HRESULT __stdcall AxStyleSets::InitNew()
{
	// plain

	mol::variant v;
	mol::variant v0(0);
	collection_.clear();

	AxStyleSet* plainSet = 0;
	make_set(SCLEX_NULL,plainStyles,sizeof(plainStyles)/sizeof(*(plainStyles)),&plainSet);
	collection_.push_back(  mol::variant((IScintillAxStyleSet*)plainSet) );
	((IScintillAxStyleSet*)plainSet)->Release();
	// HTML

	AxStyleSet* htmlSet = 0;
	make_set(SCLEX_HTML,htmlStyles,sizeof(htmlStyles)/sizeof(*(htmlStyles)),&htmlSet);
	htmlSet->AddKeyWords( mol::bstr(htmlKeyWords) );
	htmlSet->AddKeyWords( mol::bstr(jsKeyWords) );
	htmlSet->AddKeyWords( mol::bstr(vbsKeyWords) );
	htmlSet->AddKeyWords( mol::bstr(phpKeyWords) );
	collection_.push_back(  mol::variant((IScintillAxStyleSet*)htmlSet) );
	((IScintillAxStyleSet*)htmlSet)->Release();

	// SCLEX_CSS

	AxStyleSet* cssSet = 0;
	make_set(SCLEX_CSS,cssStyles,sizeof(cssStyles)/sizeof(*(cssStyles)),&cssSet);
	cssSet->AddKeyWords( mol::bstr(css1Keywords) );
	cssSet->AddKeyWords( mol::bstr(css2Keywords) );
	collection_.push_back(  mol::variant((IScintillAxStyleSet*)cssSet) );
	((IScintillAxStyleSet*)cssSet)->Release();


	MAKE_STYLE(vbSet,SCINTILLA_SYNTAX_VB,SCLEX_VB,vbStyles,vbsKeyWords);
	MAKE_STYLE(jsSet,SCINTILLA_SYNTAX_JS,SCLEX_CPP,jsStyles,jsKeyWords);
	MAKE_STYLE(sqlSet,SCINTILLA_SYNTAX_SQL,SCLEX_SQL,cppStyles,cppKeyWords);
	MAKE_STYLE(bashSet,SCINTILLA_SYNTAX_SHELL,SCLEX_BASH,cppStyles,cppKeyWords);
	MAKE_STYLE(perlSet,SCINTILLA_SYNTAX_PERL,SCLEX_PERL,perlStyles,perlKeyWords);
	MAKE_STYLE(cppSet,SCINTILLA_SYNTAX_CPP,SCLEX_CPP,cppStyles,cppKeyWords);
	MAKE_STYLE(javaSet,SCINTILLA_SYNTAX_JAVA,SCLEX_CPP,cppStyles,javaKeywords);
	MAKE_STYLE(csharpSet,SCINTILLA_SYNTAX_CSHARP,SCLEX_CPP,cppStyles,csharpKeywords);

	return S_OK;
}

/////////////////////////////////////////////////////////////////

AxStyleSet::Instance* AxStyleSet::CreateInstance(long id)
{
	Instance* d = new Instance; 
	d->AddRef();
	d->id_ = id;
	return d;
}


HRESULT __stdcall  AxStyleSet::_NewEnum(IEnumVARIANT** newEnum)
{
	mol::punk<mol::com_obj<mol::enum_variant> > ev = new mol::com_obj<mol::enum_variant>;
	for ( std::vector<mol::variant>::iterator it = collection_.begin(); it != collection_.end(); it++)
	{
		ev->add((*it));
	}
	return ev->QueryInterface(IID_IEnumVARIANT,(void**)newEnum);
}

HRESULT __stdcall  AxStyleSet::get_Count( long* cnt)
{
	*cnt = collection_.size();
	return S_OK;
}


HRESULT __stdcall  AxStyleSet::Item( VARIANT index, IScintillAxStyle** item)
{
	if ( !item )
		return E_INVALIDARG;

	*item = 0;
	mol::variant v(index);
	v.changeType(VT_I4);

	long i = v.lVal;
	if ( i < 0 || i >= collection_.size() ) {
		return E_INVALIDARG;
	}

	if ( collection_[i].vt != VT_DISPATCH || !collection_[i].pdispVal )
		return E_FAIL;

	return collection_[i].pdispVal->QueryInterface(IID_IScintillAxStyle, (void**)item);
}


HRESULT __stdcall  AxStyleSet::get_Id(  long *id)
{
	if(!id)
		return E_INVALIDARG;
	*id = id_;
	return S_OK;
}


HRESULT __stdcall AxStyleSet::CountKeyWords(long* cnt)
{
	if (!cnt)
		return E_INVALIDARG;

	*cnt = keyWords_.size();
	return S_OK;
}

HRESULT __stdcall AxStyleSet::GetKeyWord(long index, BSTR* words)
{
	if (!words)
		return E_INVALIDARG;

	*words = 0;

	if (index <0 || index >= keyWords_.size())
	{
		return E_INVALIDARG;
	}

	*words = ::SysAllocString(keyWords_[index].bstrVal);
	return S_OK;
}


HRESULT __stdcall AxStyleSet::AddKeyWords( BSTR words)
{
	keyWords_.push_back(mol::variant(words));
	return S_OK;
}


HRESULT __stdcall AxStyleSet::Load( LPSTREAM pStm)
{
	long cnt = 0;
	pStm >> mol::property(&cnt);
	if(cnt>0)
	{
		for ( long i = 0; i < cnt; i++)
		{
			mol::punk<IScintillAxStyle> style = AxStyle::CreateInstance();
			mol::punk<IPersistStream> ps(style);
			if(ps)
			{
				ps->Load(pStm);
			}
			long id = 0;
			style->get_Id(&id);
			collection_.push_back(mol::variant(style));
		}
	}

	cnt = 0;
	pStm >> mol::property(&cnt);
	if(cnt>0)
	{
		for ( long i = 0; i < cnt; i++)
		{
			mol::bstr keywords;
			pStm >> mol::property(keywords);
			if ( keywords.bstr_ )
			{
				keyWords_.push_back(mol::variant(keywords));
			}
		}
	}
	return S_OK;
}

HRESULT __stdcall AxStyleSet::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	long cnt = collection_.size();
	pStm << mol::property(&cnt);

	for ( long i = 0; i < cnt; i++)
	{
		mol::variant item(collection_[i]);
		//hr = collection_.Item(mol::variant(i),&item);
		if( collection_[i].vt == VT_DISPATCH)
		{
			mol::punk<IPersistStream> ps(collection_[i].pdispVal);
			if(ps)
			{
				ps->Save(pStm,fClearDirty);
			}
		}
	}

	//hr = keyWords_.Count(&v);
	//if(hr != S_OK)
	//	return hr;

	cnt = keyWords_.size();
	pStm << mol::property(&cnt);
	for ( long i = 0; i < cnt; i++)
	{
//		mol::variant item(keyWords_[i]);
		//hr = keyWords_.Item(mol::variant(i),&item);
		if( keyWords_[i].vt == VT_BSTR)
		{
			pStm << mol::property(mol::bstr(keyWords_[i].bstrVal));
		}
	}
	return S_OK;
}

HRESULT __stdcall AxStyleSet::GetClassID( CLSID *pClassID) 
{
	if (!pClassID)
	{
		return E_INVALIDARG;
	}
	*pClassID = IID_IScintillAxStyleSet;
	return S_OK;
}

HRESULT __stdcall AxStyleSet::IsDirty( )
{
	return S_OK;
}

HRESULT __stdcall AxStyleSet::GetSizeMax( ULARGE_INTEGER* ui ) 
{
	return S_OK;
}

HRESULT __stdcall AxStyleSet::InitNew()
{
	return S_OK;
}


/////////////////////////////////////////////////////////////////

AxStyle::Instance* AxStyle::CreateInstance()
{
	Instance* d = new Instance; 
	d->AddRef();
	return d;
}

HRESULT __stdcall  AxStyle::get_Id(  long *id)
{
	if(!id)
		return E_INVALIDARG;
	*id = id_;
	return S_OK;
}

HRESULT __stdcall  AxStyle::get_Description(  BSTR *desc)
{
	if(!desc)
		return E_INVALIDARG;
	*desc = ::SysAllocString(desc_);
	return S_OK;
}

HRESULT __stdcall  AxStyle::get_Bold(  VARIANT_BOOL *vb)
{
	if (!vb)
		return E_INVALIDARG;
	*vb = bold_ ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

HRESULT __stdcall  AxStyle::put_Bold(  VARIANT_BOOL vb)
{
	bold_ = vb == VARIANT_TRUE ? true : false;
	return S_OK;
}

HRESULT __stdcall  AxStyle::get_Italic(  VARIANT_BOOL *vb)
{
	if (!vb)
		return E_INVALIDARG;
	*vb = italic_ ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

HRESULT __stdcall  AxStyle::put_Italic(  VARIANT_BOOL vb)
{
	italic_ = vb == VARIANT_TRUE ? true : false;
	return S_OK;
}

HRESULT __stdcall  AxStyle::get_Eol(  VARIANT_BOOL *vb)
{
	if (!vb)
		return E_INVALIDARG;
	*vb = eol_ ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

HRESULT __stdcall  AxStyle::put_Eol(  VARIANT_BOOL vb)
{
	eol_ = vb == VARIANT_TRUE ? true : false;
	return S_OK;
}

HRESULT __stdcall  AxStyle::get_Fontname(  BSTR *f)
{
	if (!f)
		return E_INVALIDARG;

	*f = ::SysAllocString(fontname_);
	return S_OK;
}

HRESULT __stdcall  AxStyle::put_Fontname(  BSTR f)
{
	if (!f)
		return E_INVALIDARG;
	fontname_ = f;
	return S_OK;
}
HRESULT __stdcall  AxStyle::get_Fontsize( long *id)
{
	if (!id)
		return E_INVALIDARG;
	*id = fontsize_;
	return S_OK;
}

HRESULT __stdcall  AxStyle::put_Fontsize( long id)
{
	fontsize_ = id;
	return S_OK;
}

HRESULT __stdcall  AxStyle::get_Forecolor( BSTR *col)
{
	if (!col)
		return E_INVALIDARG;

	*col = ::SysAllocString(foreColor_);
	return S_OK;
}

HRESULT __stdcall  AxStyle::put_Forecolor( BSTR col)
{
	if (!col)
		return E_INVALIDARG;

	foreColor_ = col;
	return S_OK;
}

HRESULT __stdcall  AxStyle::get_Backcolor( BSTR *col)
{
	if (!col)
		return E_INVALIDARG;

	*col = ::SysAllocString(backColor_);
	return S_OK;
}

HRESULT __stdcall  AxStyle::put_Backcolor(BSTR col)
{
	if (!col)
		return E_INVALIDARG;

	backColor_ = col;
	return S_OK;
}



HRESULT __stdcall AxStyle::Load( LPSTREAM pStm)
{
	pStm 
		>> mol::property( &id_ )
		>> mol::property( desc_ )
		>> mol::property( &bold_ )
		>> mol::property( &italic_ )
		>> mol::property( fontname_ )
		>> mol::property( &fontsize_ )
		>> mol::property( foreColor_ )
		>> mol::property( backColor_ );
	return S_OK;
}

HRESULT __stdcall AxStyle::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	pStm 
		<< mol::property( &id_ )
		<< mol::property( desc_ )
		<< mol::property( &bold_ )
		<< mol::property( &italic_ )
		<< mol::property( fontname_ )
		<< mol::property( &fontsize_ )
		<< mol::property( foreColor_ )
		<< mol::property( backColor_ );
	return S_OK;
}

HRESULT __stdcall AxStyle::GetClassID( CLSID *pClassID) 
{
	if (!pClassID)
	{
		return E_INVALIDARG;
	}
	*pClassID = IID_IScintillAxStyle;
	return S_OK;
}

HRESULT __stdcall AxStyle::IsDirty( )
{
	return S_OK;
}

HRESULT __stdcall AxStyle::GetSizeMax( ULARGE_INTEGER* ui ) 
{
	return S_OK;
}

HRESULT __stdcall AxStyle::InitNew()
{
	return S_OK;
}


