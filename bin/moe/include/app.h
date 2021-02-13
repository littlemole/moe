#ifndef MOL_MOE_DEF_GUARD_
#define MOL_MOE_DEF_GUARD_

#include "moe.h"
#include "commons.h"
#include "ssh/ssh.h"
#include "tcp/sockets.h"

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

class MoeLoop: public mol::win::MdiLoop
{
public:
	int operator() ( mol::win::AppBase& app );
};


/////////////////////////////////////////////////////////////////////////

class moeCliType
{
public:
	virtual ~moeCliType()
	{}

	virtual bool open(IDispatch* docs, IDispatch* dialogs, std::string p) = 0;

};

/////////////////////////////////////////////////////////////////////////

class MoeApp : 
	public mol::local_server<MoeLoop>,
	public mol::exports< MoeApp, MoeWnd >
{
friend mol::Singleton<MoeApp>; 
public:

	virtual int runEmbedded(const std::wstring& cmdline);
	virtual int runStandalone(const std::wstring& cmdline);

private:

	MoeApp ();
	~MoeApp();

	// windows libraries
    mol::ole::ole_init       oi_;
    mol::comm_ctrl_init cci_;
	mol::GdiPlusUser    gdip_;
	mol::richedit_init  rei_;
	mol::ssh::Init      si_;
	mol::WinSockUser    wsu_;

//	void init_extensions_if();
//	bool enableExtensions_;

	void openDocsFromCommandLine( IDispatch* m, std::wstring cmdline );
	void openMoeDocument(IDispatch* docs, IDispatch* dialogs,const std::string& s);

	std::vector<moeCliType*> moeCliTypes;
};

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

#endif