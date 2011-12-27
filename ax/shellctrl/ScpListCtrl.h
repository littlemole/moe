#ifndef MOL_DEF_SCPSHELLDIR_VIEW_DEF_GUARDING_
#define MOL_DEF_SCPSHELLDIR_VIEW_DEF_GUARDING_

#pragma once
#include "win/IO.h"
#include "win/file.h"
#include "win/CoCtrl.h"
#include "win/MsgMap.h"
#include "ole/DragDrop.h"
#include "ole/Ctrl.h"
#include "shellCtrl_h.h"
#include "win/msghandler.h"
#include "win/msg_macro.h"
#include "win/dlg.h"
#include "ssh/sftp.h"
#include "tcp/sockets.h"

///////////////////////////////////////////////////////////////////////////////

class ScpListCtrl;

struct ScpListEntry
{
	ScpListEntry(const mol::string& fn, const mol::sftp::RemoteFile& rf, int index )
		: filename(fn), fileinfo(rf), iconindex(index), isParsed(false) 
    {}
	
	mol::string				filename;
    int						iconindex;
    bool					isParsed;
	mol::sftp::RemoteFile	fileinfo;

	bool isDir()
	{
		return fileinfo.isDir();
	}

	mol::string getName()
	{
		return fileinfo.getName();
	}
};

///////////////////////////////////////////////////////////////////////////////

class ScpListCtrl;

class ScpDirQueueAction
{
public:
		virtual void operator()() = 0;
};

class ScpDirQueueLoadAction : public ScpDirQueueAction
{
public:
	ScpDirQueueLoadAction( const mol::string& p, ScpListCtrl* dl );

	virtual void operator()();

	mol::string		    path;
	ScpListCtrl*		scpList;
};


class ScpDirQueueRenameAction : public ScpDirQueueAction
{
public:
	ScpDirQueueRenameAction( const mol::string& oldp, const mol::string& newp,ScpListCtrl* dl );

	virtual void operator()();

	mol::string		    oldpath;
	mol::string		    newpath;
	ScpListCtrl*		scpList;
};

class ScpCreateDirQueueAction : public ScpDirQueueAction
{
public:
	ScpCreateDirQueueAction( ScpListCtrl* dl );

	virtual void operator()();

	ScpListCtrl*		scpList;
};


class ScpUnlinkQueueAction : public ScpDirQueueAction
{
public:
	ScpUnlinkQueueAction( const std::vector<mol::string>& v, ScpListCtrl* dl );

	virtual void operator()();

	std::vector<mol::string> v;
	ScpListCtrl*		scpList;
};



class ScpPushFileQueueAction : public ScpDirQueueAction
{
public:
	ScpPushFileQueueAction( const mol::string& p, const std::vector<mol::string>& v, ScpListCtrl* dl );

	virtual void operator()();

	mol::string		    path;
	std::vector<mol::string> v;
	ScpListCtrl*		scpList;
};
///////////////////////////////////////////////////////////////////////////////


class ScpListCtrl: 
	public mol::ax_ctrl<ScpListCtrl,CLSID_ScpList,false,mol::Window,WS_BORDER|WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,0>,
	public mol::Dispatch<IScpList>,
	public mol::CtrlConnectionPoint<ScpListCtrl,_IShellListEvents,mol::ole::ConnectionPointAdviseMultiThreadPolicy<_IShellListEvents> >,
	public mol::ProvideClassInfo<ScpListCtrl>,
	public mol::interfaces< ScpListCtrl, 
				mol::implements<
						IDispatch,
						IScpList,
						IOleObject,
						IDataObject,
						mol::interface_ex<IPersist,IPersistStreamInit>,
						mol::interface_ex<IPersistStream,IPersistStreamInit>,
						IPersistStreamInit,
						IPersistStorage,
						IPersistPropertyBag,
						IRunnableObject,
						IViewObject,
						IViewObject2,
						mol::interface_ex<IOleWindow,IOleInPlaceObjectWindowless>,
						mol::interface_ex<IOleInPlaceObject,IOleInPlaceObjectWindowless>,
						IOleControl,
						IConnectionPointContainer,
						IProvideClassInfo> >
{
public:

    ScpListCtrl(void);
    ~ScpListCtrl();

	void load( const mol::string& uri );
	void load_async( const mol::string& uri );
	void mkdir();
	void unlink( const std::vector<mol::string>& v);
	void put( std::vector<mol::string>& v, const mol::string& path);

	void EndRename(const mol::string& oldpath, const mol::string& newpath);

	// COM properties

	HRESULT virtual __stdcall get_CredentialProvider	( IDispatch** provider );
	HRESULT virtual __stdcall put_CredentialProvider	( IDispatch* provider );

	HRESULT virtual __stdcall get_Location		( BSTR* dirname );
	HRESULT virtual __stdcall put_Location		( BSTR dirname );

	HRESULT virtual __stdcall get_Selection		( BSTR* dirname );

	HRESULT virtual __stdcall get_HasFocus		( VARIANT_BOOL* vbHasFocus);

	// COM methods

	HRESULT virtual __stdcall Update			();
	HRESULT virtual __stdcall Cut				();
	HRESULT virtual __stdcall Copy				();
	HRESULT virtual __stdcall Paste				();
	HRESULT virtual __stdcall Rename			();
	HRESULT virtual __stdcall Delete			();
	HRESULT virtual __stdcall Properties		();
	HRESULT virtual __stdcall Execute			();
	HRESULT virtual __stdcall CreateDir     	();
	HRESULT virtual __stdcall UpDir		     	();
	HRESULT virtual __stdcall CopyTo(BSTR dir);

	HRESULT virtual __stdcall Load( LPSTREAM pStm);
	HRESULT virtual __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);

	HRESULT virtual __stdcall Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog);
	HRESULT virtual __stdcall Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties);
  
	virtual void initAmbientProperties( IDispatch* disp)
	{
		HIMAGELIST himl = ListView_GetImageList(list_,TVSIL_NORMAL);
		COLORREF col;
		mol::variant v(bgCol_);
		if ( S_OK == get(disp,DISPID_AMBIENT_BACKCOLOR,&v) )
		{
			bgCol_ = v.lVal;			
			::OleTranslateColor(bgCol_,0,&col);
			ListView_SetBkColor(list_,col);
			ImageList_SetBkColor(himl,CLR_NONE );
			ListView_SetTextBkColor(list_,col);
		}

		if ( S_OK == get(disp,DISPID_AMBIENT_FORECOLOR,&v) )
		{
			foreCol_ = v.lVal;
			::OleTranslateColor(foreCol_,0,&col);
			ListView_SetTextColor(list_,col);			
		}
	}



protected:

	msg_handler( WM_CREATE,	OnCreate ) 
		LRESULT virtual OnCreate( UINT, WPARAM, LPARAM );

	msg_handler( WM_SIZE,OnSize )
		LRESULT virtual OnSize( UINT, WPARAM, LPARAM );

	msg_handler( WM_DESTROY, OnDestroy )
		LRESULT virtual OnDestroy( UINT, WPARAM, LPARAM );


    notify_code_handler( LVN_BEGINLABELEDIT , OnBeginLabelEdit )
		LRESULT virtual OnBeginLabelEdit( UINT, WPARAM, LPARAM );

    notify_code_handler( LVN_ENDLABELEDIT , OnEndRename )
		LRESULT virtual OnEndRename( UINT, WPARAM, LPARAM );

    notify_code_handler( LVN_KEYDOWN, OnKeyDown )
		LRESULT virtual OnKeyDown( UINT, WPARAM, LPARAM );

    notify_code_handler( NM_RCLICK, OnContext )
		LRESULT virtual OnContext( UINT, WPARAM, LPARAM );

	notify_code_handler( NM_CLICK, OnClick )
		LRESULT virtual OnClick( UINT, WPARAM, LPARAM );

    notify_code_handler( LVN_COLUMNCLICK, OnColumn )
		LRESULT virtual OnColumn( UINT, WPARAM, LPARAM );

    notify_code_handler( NM_DBLCLK, OnDblClick )
		LRESULT virtual OnDblClick( UINT, WPARAM, LPARAM );

    notify_code_handler( LVN_BEGINDRAG, OnBeginDrag )
		LRESULT virtual OnBeginDrag( UINT, WPARAM, LPARAM );

	void clear();
	mol::string getPath();
    void setPath(const mol::string& path);

	virtual int listStyle()   { return WS_CHILD|LVS_REPORT|LVS_SHAREIMAGELISTS|LVS_EDITLABELS|WS_VSCROLL ; }
	virtual int listExStyle() { return WS_EX_RIGHTSCROLLBAR; }

    std::vector<mol::string>   selectionPaths();
    std::vector<int>           selectionIndexes();
    std::vector<ScpListEntry*> selectionEntries();

	ScpListEntry* getItemEntry(int i );
	mol::string getItemPath(int i);
    int getItemByPath(const mol::string& path);

	bool  doHitTest();

	//bool connect();


//    virtual int compare(LPARAM lParam1, LPARAM lParam2);
//    static int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);

	class ShellList : 
		public mol::ListCtrl
	{
	    public:
		outer_this(ScpListCtrl,list_);
		
		virtual int style()   { return This()->listStyle(); }
		virtual int exstyle() { return This()->listExStyle(); }

	} list_;

	
	class Credentials : public mol::ssh::CredentialCallback
	{
		public: 
		outer_this(ScpListCtrl,credentials_);

		virtual bool getCredentials(const std::string& host, int port,mol::ssh::string& user, mol::ssh::string& pwd);
		virtual bool promptCredentials(const std::string& host, int port,const std::string& prompt, const std::string& desc,char** value,bool echo);
		virtual bool acceptHost(const std::string& host, int port, const std::string& hash);
		virtual bool rememberHostCredentials(const std::string& host, int port, const mol::ssh::string& user, const mol::ssh::string& pwd);
		virtual bool deleteHostCredentials(const std::string& host, int port);

	} credentials_;
	

    class ShellListCtrl_Drop : public mol::DropTarget
    {
    public : 
		ShellListCtrl_Drop(ScpListCtrl* l) : list_(l) {}
		HRESULT virtual __stdcall Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect);
		HRESULT virtual __stdcall DragEnter( IDataObject*, DWORD, POINTL, DWORD* );
		HRESULT virtual __stdcall DragOver( DWORD, POINTL, DWORD* );
		HRESULT virtual __stdcall DragLeave();
	protected:
			ScpListCtrl* list_;
    };
	
	mol::punk<ShellListCtrl_Drop>		Drop;
	mol::punk<IScpCredentialProvider>	provider_;

	mol::Uri							uri_;
    mol::string							path_;

	mol::punk<ISSH>						ssh_;
	//mol::punk<ISSHConnection>			conn_;

	OLE_COLOR							bgCol_;
	OLE_COLOR							foreCol_;
	mol::Menu							listMenu_;
	RECT								clientRect_;

	class ThreadStartPolicy 
	{
	public:
		void operator()(){ ::CoInitialize(0); };
	};

	class ThreadShutdownPolicy 
	{
	public:
		void operator()(){ ::CoUninitialize(); };
	};

	DWORD gitCookie_;
	DWORD gitSSHCookie_;
	//DWORD gitConnectionCookie_;

	mol::ThreadQueue<
			ScpDirQueueAction,
			true,
			ThreadStartPolicy,
			ThreadShutdownPolicy>			
	queue_;

	bool ScpListCtrl::connect(DWORD cookie, ISSHConnection** con );
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////




#endif