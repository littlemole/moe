#ifndef MOE_COMMONS_DEF_GUARD_DEFINE_
#define MOE_COMMONS_DEF_GUARD_DEFINE_

#include <set>
#include <fstream>
#include <sstream>


// mol libs
#include "util/istr.h"
#include "xml/html.h"

#include "win/app.h"
#include "win/wnd.h"
#include "win/mdi.h"
#include "win/res.h"
#include "win/dlg.h"
#include "win/enc.h"
#include "win/codlg.h"
#include "win/coctrl.h"
#include "win/core.h"
#include "win/layout.h"
#include "win/shell.h"
#include "win/folder.h"
#include "win/path.h"
#include "win/file.h"
#include "win/TaskBar.h"
#include "win/msgloop.h"
#include "win/msghandler.h"
#include "win/msg_macro.h"
#include "win/gdiplus.h"
#include "win/clipboard.h"
#include "win/RTFedit.h"

#include "ole/aut.h"
#include "ole/obj.h"
#include "ole/host.h"
#include "ole/punk.h"
#include "ole/bstr.h"
#include "ole/persist.h"
#include "ole/variant.h"
#include "ole/factory.h"
#include "ole/dragdrop.h"
#include "ole/scripting.h"
#include "ole/ie.h"
#include "ole/bookmark.h"
#include "ole/img.h"
#include "ole/cp.h"
#include "ole/propertypage.h"
//#include "ole/Rib.h"
#include "ole/enum.h"

#include <activdbg.h>
#include <Prsht.h>
#include <mshtml.h>

#include "ChromeEdge.h"

// ax impl
#include "ax/setting/setting_h.h"
#include "ax/shellctrl/ShellListEvents.h"
#include "ax/shellctrl/ShellFolderEvents.h"
#include "ax/shellctrl/ShellTreeEvents.h"
#include "ax/shellctrl/HexCtrlEvents.h"
#include "ax/ScintillAx/include/ScintillaxEvents.h"
//#include "ax/shellctrl/ScpListCtrl_h.h"

// moe idl
#include "moe_h.h"

// resource identifiers defines //BAD BAD BAD
//#include "resource.h"

#include <memory>
#include <functional>

#include "json/json.h" 

enum LogLevel { LOGERROR, LOGWARN, LOGINFO, LOGDEBUG };

class Appender
{
public:

	virtual ~Appender()
	{}

	virtual void write(const std::string& str) = 0;
};

class FileAppender : public Appender
{
public:

	FileAppender(const std::string& path);
	virtual ~FileAppender();

	virtual void write(const std::string& str);

private:
	mol::filestream fs_;
};


class DebugAppender : public Appender
{
public:

	DebugAppender() {};
	virtual ~DebugAppender() {};

	virtual void write(const std::string& str);

private:
};

class Logger
{
friend class Log;
public:

   virtual ~Logger();

   template<class T>
   Logger& operator<<( const T& rhs )
   {
	   oss_ << rhs;
	   return *this;
   }

private:
   Logger(LogLevel level);
   Logger(const Log&);
   Logger& operator =(const Log&);

   LogLevel logLevel_;
   std::ostringstream oss_;
};

typedef std::shared_ptr<Appender> appender;

class Log
{
friend class Logger;
public:

	Log();
	~Log();

	void level( LogLevel l);
	LogLevel level();

	Logger getLogger(LogLevel l);

	void add( Appender* appender);

private:

	void write(const std::string& str);


	mol::filestream fs_;
	LogLevel logLevel_;

	std::vector< appender > appenders_;
};

Log& log();

Logger logger(LogLevel level);

namespace JSON {

	class ParseEx : public std::exception
	{
	public:
		ParseEx(const std::string& s)
			: msg(s)
		{}

		const char* what() const noexcept
		{
			return msg.c_str();
		}

		std::string msg;
	};

	//////////////////////////////////////////////////////////////

	//! parse string containing JSON 
	//! \ingroup json
	inline Json::Value parse(const std::string& txt)
	{
		Json::Value json;

		Json::CharReaderBuilder rbuilder;
		std::string errs;
		std::istringstream iss(txt);
		bool ok = Json::parseFromStream(rbuilder, iss, &json, &errs);
		if (!ok)
		{
			throw ParseEx(errs);
		}
		return json;
	}

	//////////////////////////////////////////////////////////////

	//! serialize JSON structure into plaintext
	//! \ingroup json

	inline const std::string stringify(Json::Value value)
	{
		Json::StreamWriterBuilder wbuilder;
		return Json::writeString(wbuilder, value);

	}

	//! flatten a JSON structure removing whitespace and newlines
	//! \ingroup json
	inline const std::string flatten(Json::Value value)
	{
		Json::StreamWriterBuilder wbuilder;
		wbuilder["commentStyle"] = "None";
		wbuilder["indentation"] = "";
		return Json::writeString(wbuilder, value);
	}

} // end namespace JSON


inline std::string slurp(const std::string& path)
{
	std::ostringstream oss;
	std::ifstream ifs;
	ifs.open(path);
	if (ifs)
	{
		while (ifs)
		{
			char buf[4096];
			ifs.read(buf, 4096);
			oss.write(buf, ifs.gcount());
		}
		ifs.close();
	}
	return oss.str();
}

template<class MFP>
int make_msg_handlers(MFP mfp)
{
	return 0;
}

template<class MFP, class ... Args>
int make_msg_handlers(MFP mfp, int msg, Args ... args)
{
	mol::IMsgMapHandler* handler = mol::make_handler(mfp);				
	handler->connect_msg(msg);									
	return make_msg_handlers(mfp, args...);
}

template<class MFP>
int make_cmd_handlers(MFP mfp)
{
	return 0;
}

template<class MFP, class ... Args>
int make_cmd_handlers(MFP mfp, int cmd, Args ... args)
{
	mol::IMsgMapHandler* handler = mol::make_handler(mfp);
	handler->connect_cmd(cmd);
	return make_cmd_handlers(mfp, args...);
}

#define CONCAT_(a, b) a ## b




#define handle_msg_impl(mfp,line, ...)							\
static  int CONCAT_(mol_connect_msgs,line) = []()				\
{																\
	return make_msg_handlers(mfp,__VA_ARGS__);					\
}();

#define handle_msg(mfp,...)									\
handle_msg_impl(mfp,__LINE__,__VA_ARGS__)



#define handle_msg_range_impl(mfp,i,j,line)						\
static int CONCAT_(mol_connect_msg_range,line) = []()			\
{																\
	for( UINT msg = i; msg  < j+1; msg++)						\
	{															\
		mol::IMsgMapHandler* handler = mol::make_handler(mfp);	\
		handler->connect_msg(msg);								\
	}															\
	return 0;													\
}();

#define handle_msg_range(mfp,i,j)								\
handle_msg_range_impl(mfp,i,j,__LINE)





#define handle_cmd_impl(mfp,line,...)							\
static int CONCAT_(mol_connect_cmds,line) = []()				\
{																\
	return make_cmd_handlers(mfp,__VA_ARGS__);					\
}();

#define handle_cmd(mfp,...)										\
handle_cmd_impl(mfp,__LINE__,__VA_ARGS__)



#define handle_cmd_range_impl(mfp,i,j,line)						\
static int CONCAT_(mol_connect_cmd_range,line) = []()			\
{																\
	for( UINT cmd = i; cmd  < j+1; cmd++)						\
	{															\
		mol::IMsgMapHandler* handler = mol::make_handler(mfp);	\
		handler->connect_cmd(cmd);								\
	}															\
	return 0;													\
}();

#define handle_cmd_range(mfp,i,j)								\
handle_cmd_range_impl(mfp,i,j,__LINE__)



#define handle_notify_id_impl(mfp,id,line)						\
static int CONCAT_(mol_connect_notify_id,line) = []()			\
{																\
	mol::IMsgMapHandler* handler = mol::make_handler(mfp);		\
	handler->connect_notify_id(id);								\
	return 0;													\
}();

#define handle_notify_id(mfp,id)								\
handle_notify_id_impld(mfp,id,__LINE__)



#define handle_notify_code_impl(mfp,code,line)					\
static  int CONCAT_(mol_connect_notify_code,line) = []()		\
{																\
	mol::IMsgMapHandler* handler = mol::make_handler(mfp);		\
	handler->connect_notify_code(code);							\
	return 0;													\
}();

#define handle_notify_code(mfp,code)							\
handle_notify_code_impl(mfp,code,__LINE__)





#define handle_ole_cmd_impl(clazz,cmd,mfp,line)							\
static int CONCAT_(mol_connect_ole_cmd,line) = []()						\
{																		\
	mol::IMsgMapHandler* handler = mol::make_ole_handler<clazz>(mfp);	\
	handler->connect_cmd(cmd);											\
	return 0;															\
}();

#define handle_ole_cmd(clazz,cmd,mfp)									\
handle_ole_cmd_impl(clazz,cmd,mfp,__LINE__)



#endif

