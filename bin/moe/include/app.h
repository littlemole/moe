#ifndef MOL_MOE_DEF_GUARD_
#define MOL_MOE_DEF_GUARD_

#include "win/msgloop.h"
#include "win/gdiplus.h"
#include "moe.h"


class MoeLoop: public mol::win::MdiLoop
{
public:
	int operator() ( mol::win::AppBase& app );
};




class MoeApp : 
	public mol::local_server<MoeLoop>,
	public mol::exports< MoeApp, MoeWnd >
{
friend mol::Singleton<MoeApp>; 
public:

    virtual int run(const mol::string& cmdline);
	virtual int runEmbedded(const mol::string& cmdline);
	virtual int runStandalone(const mol::string& cmdline);

private:

	MoeApp ();
	~MoeApp();

	// windows libraries
    mol::ole_init       oi_;
    mol::comm_ctrl_init cci_;
	mol::GdiPlusUser    gdip_;

	void init_extensions_if();
	bool enableExtensions_;

	void openDocsFromCommandLine( IDispatch* m, mol::string cmdline );
};



#endif