#ifndef MOL_DEF_SHELLDIR_VIEW_DEF_GUARDING_
#define MOL_DEF_SHELLDIR_VIEW_DEF_GUARDING_

#pragma once
#include "win/IO.h"
#include "win/file.h"
#include "win/CoCtrl.h"
#include "win/MsgMap.h"
#include "ole/DragDrop.h"
#include "ole/Ctrl.h"
#include "shellCtrl_h.h"
#include "resource.h"
#include "win/msghandler.h"
#include "win/msg_macro.h"

using namespace mol;
using namespace mol::io;
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

class ShellListCtrl;

///////////////////////////////////////////////////////////////////////////////


struct DirListEntry
{
	DirListEntry(const mol::string& fn, mol::FileInfo& fi, int index )
		: filename(fn), fileinfo(fi), iconindex(index), isParsed(false) 
    {}
	
	mol::string				filename;
	mol::FileInfo			fileinfo;
    int						iconindex;
    bool					isParsed;

	bool isDir()
	{
		return (fileinfo.attributes() & FILE_ATTRIBUTE_DIRECTORY) != 0;
	}
};

///////////////////////////////////////////////////////////////////////////////

class DirQueueAction
{
public:
	DirQueueAction( const mol::string& p, ShellListCtrl* dl )
		: path(p), dirlist(dl)
	{}

	void operator()();

	mol::string		    path;
	ShellListCtrl*		dirlist;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//#define SHELL_LIST_CTRL_ID_DIRMON       101


#define ShellListCtrl_Dispatch_DisplayFiles 1
#define ShellListCtrl_Dispatch_Selection 2

class ShellListCtrl: 
	public ax_ctrl<ShellListCtrl,CLSID_ShellList,false,mol::Window,WS_BORDER|WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,0>,
	public Dispatch<IShellList>,
	public ctrl_events<ShellListCtrl,_IShellListEvents>,
	public ProvideClassInfo<ShellListCtrl>,
	public interfaces< ShellListCtrl, 
				implements<
						IDispatch,
						IShellList,
						IOleObject,
						IDataObject,
						interface_ex<IPersist,IPersistStreamInit>,
						interface_ex<IPersistStream,IPersistStreamInit>,
						IPersistStreamInit,
						IPersistStorage,
						IPersistPropertyBag,
						IRunnableObject,
						IViewObject,
						IViewObject2,
						interface_ex<IOleWindow,IOleInPlaceObjectWindowless>,
						interface_ex<IOleInPlaceObject,IOleInPlaceObjectWindowless>,
						IOleControl,
						IConnectionPointContainer,
						IProvideClassInfo> >
{
friend class DirQueueAction;
public:

    ShellListCtrl(void);
    ~ShellListCtrl();

	//mol::sendcmd_pubsub pathEvent;


	// COM properties

	HRESULT virtual __stdcall get_DisplayFiles	( VARIANT_BOOL* vb );
	HRESULT virtual __stdcall put_DisplayFiles	( VARIANT_BOOL vb  );

	HRESULT virtual __stdcall get_Selection		( VARIANT* dirname );
	HRESULT virtual __stdcall put_Selection		( VARIANT dirname );

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

	HRESULT virtual __stdcall Load( LPSTREAM pStm);
	HRESULT virtual __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);

	HRESULT virtual __stdcall Load( IPropertyBag *pPropBag,IErrorLog *pErrorLog);
	HRESULT virtual __stdcall Save( IPropertyBag *pPropBag,BOOL fClearDirty,BOOL fSaveAllProperties);
  
	virtual void initAmbientProperties( IDispatch* disp)
	{
		HIMAGELIST himl = ListView_GetImageList(list_,TVSIL_NORMAL);
		COLORREF col;
		variant v(bgCol_);
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

 //   cmd_handler( SHELL_LIST_CTRL_ID_DIRMON, OnDirMon )
        LRESULT virtual OnDirMon( UINT, WPARAM, LPARAM );


	//persist_member(cs_,sizel);

    void setPath(const mol::string& path);
    mol::string getPath();

	void refresh( mol::io::DirMon* dirmon = 0);
    BOOL sort(int c);
	bool doHitTest();

    std::vector<mol::string>   selectionPaths();
    std::vector<int>           selectionIndexes();
    std::vector<DirListEntry*> selectionEntries();

	DirListEntry* getItemEntry(int i );
	mol::string getItemPath(int i);
    int getItemByPath(const mol::string& path);

    virtual int listStyle()   { return WS_VISIBLE|WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN|LVS_REPORT|LVS_SHAREIMAGELISTS|LVS_EDITLABELS; }
    virtual int listExStyle() { return 0; }

    void clear();

	void run(const mol::string& s);

    virtual int compare(LPARAM lParam1, LPARAM lParam2);
    static int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);

	class ShellList : 
		public mol::ListCtrl
	{
	    public:
		outer_this(ShellListCtrl,list_);
		
		virtual int style()   { return This()->listStyle(); }
		virtual int exstyle() { return This()->listExStyle(); }

	} list_;

    class ShellListCtrl_Drop : public DropTarget
    {
    public : 
		ShellListCtrl_Drop(ShellListCtrl* l) : list_(l) {}
		HRESULT virtual __stdcall Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect);
		HRESULT virtual __stdcall DragEnter( IDataObject*, DWORD, POINTL, DWORD* );
		HRESULT virtual __stdcall DragOver( DWORD, POINTL, DWORD* );
		HRESULT virtual __stdcall DragLeave();
	protected:
			ShellListCtrl* list_;
    };
	
	punk<ShellListCtrl_Drop> Drop;

	mol::io::DirMon 		dirMon_;

    int						sortCol_;
	int						sortDir_;
    mol::string				path_;
    BOOL					bCancel_;
	RECT					clientRect_;

	mol::ThreadQueue<DirQueueAction>			queue_;

    bool										displayFiles_;
	OLE_COLOR									bgCol_;
	OLE_COLOR									foreCol_;
	mol::Menu									listMenu_;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////




#endif