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
	ScpListEntry(const std::wstring& fn, const mol::sftp::RemoteFile& rf, int index )
		: filename(fn), fileinfo(rf), iconindex(index), isParsed(false) 
    {}
	
	std::wstring				filename;
    int						iconindex;
    bool					isParsed;
	mol::sftp::RemoteFile	fileinfo;

	bool isDir()
	{
		return fileinfo.isDir();
	}

	std::wstring getName()
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
	ScpDirQueueLoadAction( const std::wstring& p, ScpListCtrl* dl );

	virtual void operator()();

	std::wstring		    path;
	ScpListCtrl*		scpList;
};


class ScpDirQueueRenameAction : public ScpDirQueueAction
{
public:
	ScpDirQueueRenameAction( const std::wstring& oldp, const std::wstring& newp,ScpListCtrl* dl );

	virtual void operator()();

	std::wstring		    oldpath;
	std::wstring		    newpath;
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
	ScpUnlinkQueueAction( const std::vector<std::wstring>& v, ScpListCtrl* dl );

	virtual void operator()();

	std::vector<std::wstring> v;
	ScpListCtrl*		scpList;
};



class ScpPushFileQueueAction : public ScpDirQueueAction
{
public:
	ScpPushFileQueueAction( const std::wstring& p, const std::vector<std::wstring>& v, ScpListCtrl* dl );

	virtual void operator()();

	std::wstring		    path;
	std::vector<std::wstring> v;
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

	void load( const std::wstring& uri );
	void load_async( const std::wstring& uri );
	void mkdir();
	void unlink( const std::vector<std::wstring>& v);
	void put( std::vector<std::wstring>& v, const std::wstring& path);

	void EndRename(const std::wstring& oldpath, const std::wstring& newpath);

	// COM properties

	HRESULT virtual __stdcall get_Location		( BSTR* dirname );
	HRESULT virtual __stdcall put_Location		( BSTR dirname );
	HRESULT virtual __stdcall get_Selection		( BSTR* dirname );
	HRESULT virtual __stdcall get_HasFocus		( VARIANT_BOOL* vbHasFocus);
	HRESULT virtual __stdcall get_Connection	( IDispatch** conn );
	HRESULT virtual __stdcall put_Connection	( IDispatch* conn );
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
  
	virtual void initAmbientProperties( IDispatch* disp);

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


	virtual int listStyle()   { return WS_CHILD|LVS_REPORT|LVS_SHAREIMAGELISTS|LVS_EDITLABELS|WS_VSCROLL ; }
	virtual int listExStyle() { return WS_EX_RIGHTSCROLLBAR; }

    std::vector<std::wstring>   selectionPaths();
    std::vector<int>           selectionIndexes();
    std::vector<ScpListEntry*> selectionEntries();

	ScpListEntry* getItemEntry(int i );
	std::wstring getItemPath(int i);
    int getItemByPath(const std::wstring& path);

	bool doHitTest();
	void clear();
	std::wstring getPath();
    void setPath(const std::wstring& path);
	bool connect(ISSHConnection** con );

	class ShellList : 
		public mol::ListCtrl
	{
	    public:
		outer_this(ScpListCtrl,list_);
		
		virtual int style()   { return This()->listStyle(); }
		virtual int exstyle() { return This()->listExStyle(); }

	} list_;


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
	
	mol::punk<ISSHConnection>			conn_;
	mol::punk<ShellListCtrl_Drop>		Drop;
	mol::Uri							uri_;
    std::wstring							path_;
	mol::punk<ISSH>						ssh_;
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

	mol::ThreadQueue<
			ScpDirQueueAction,
			true,
			ThreadStartPolicy,
			ThreadShutdownPolicy>			
	queue_;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////




#endif