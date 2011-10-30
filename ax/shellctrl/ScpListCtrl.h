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



///////////////////////////////////////////////////////////////////////////////

class ScpPasswordCredentials : 
	public mol::com_registerobj<ScpPasswordCredentials,CLSID_ScpPasswordCredentials>,
	public mol::Dispatch<IScpPasswordCredentials>,
	public mol::interfaces< ScpPasswordCredentials, mol::implements< IDispatch, IScpPasswordCredentials> >
{
public:
		HRESULT virtual __stdcall put_Username( BSTR user)
		{
			if ( user )
			{
				user_ = user;
			}
			return S_OK;
		}

		HRESULT virtual __stdcall get_Username( BSTR* user)
		{
			if ( !user )
				return E_INVALIDARG;

			*user = ::SysAllocString( user_.bstr_ );			
			return S_OK;
		}

		HRESULT virtual __stdcall put_Password( BSTR pwd)
		{
			if ( pwd )
			{
				pwd_ = pwd;
			}
			return S_OK;
		}

		HRESULT virtual __stdcall get_Password( BSTR* pwd)
		{
			if ( !pwd )
				return E_INVALIDARG;

			*pwd = ::SysAllocString( pwd_.bstr_ );			
			return S_OK;
		}

private:

	mol::bstr user_;
	mol::bstr pwd_;
};

///////////////////////////////////////////////////////////////////////////////
struct Credentials
{
	Credentials( const mol::string& h, int p, const mol::string& u, const mol::string& pass)
		: host(h),port(p),user(u),pwd(pass)
	{}
	mol::string host;
	int port;
	mol::string user;
	mol::string pwd;
};

class ScpCredentialProvider : 
	public mol::com_registerobj<ScpCredentialProvider,CLSID_DefaultScpCredentialProvider>,
	public mol::Dispatch<IScpCredentialProvider>,
	public mol::interfaces< ScpCredentialProvider, mol::implements< IDispatch, IScpCredentialProvider> >
{
public:

	void dispose()
	{
		for ( std::map<mol::string,Credentials*>::iterator it = credentials_.begin(); it!=credentials_.end();it++)
		{
			delete (*it).second;
		}
		credentials_.clear();
	}

	HRESULT virtual __stdcall getCredentials( BSTR host, long port, IScpPasswordCredentials** credentials);

	HRESULT virtual __stdcall promptCredentials( BSTR prompt,BSTR description,VARIANT_BOOL echo, VARIANT* value)
	{
		if (!value)
			return E_INVALIDARG;

		value->vt = VT_EMPTY;
		return S_OK;
	}

	HRESULT virtual __stdcall acceptHost( BSTR host, long port, BSTR hash, VARIANT_BOOL* accept);

	HRESULT virtual __stdcall remberSessionCredentials( BSTR host, long port, IScpPasswordCredentials* credentials)
	{
		if (credentials == 0 )
			return E_INVALIDARG;

		mol::bstr user;
		credentials->get_Username(&user);

		mol::bstr pwd;
		credentials->get_Password(&pwd);

		Credentials* creds = new Credentials( mol::toString(host), port, mol::toString(user), mol::toString(pwd) );
		credentials_.insert( std::make_pair( mol::toString(host), creds) );
		return S_OK;
	}


	HRESULT virtual __stdcall removeSessionCredentials( BSTR host, long port)
	{
		bool go = true;
		while(go)
		{
			go = false;
			for ( std::map<mol::string,Credentials*>::iterator it = credentials_.begin(); it!=credentials_.end();it++)
			{
				if ( (*it).first == mol::toString(host) && (*it).second->port == port )
				{
					delete (*it).second;
					credentials_.erase(it);
					go = true;
					break;
				}
			}
		}
		return S_OK;
	}

private:
	std::map<mol::string,Credentials*> credentials_;
};

///////////////////////////////////////////////////////////////////////////////

class ScpListCtrl;

struct ScpListEntry
{
	ScpListEntry(const mol::string& fn, mol::sftp::RemoteFile rf, int index )
		: filename(fn), fileinfo(rf), iconindex(index), isParsed(false) 
    {}
	
	mol::string				filename;
	mol::sftp::RemoteFile	fileinfo;
    int						iconindex;
    bool					isParsed;

	bool isDir()
	{
		return fileinfo.isDir();
	}
};

///////////////////////////////////////////////////////////////////////////////


class ScpListCtrl: 
	public mol::ax_ctrl<ScpListCtrl,CLSID_ScpList,false,mol::Window,WS_BORDER|WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,0>,
	public mol::Dispatch<IScpList>,
	public mol::ctrl_events<ScpListCtrl,_IShellListEvents>,
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


	// COM properties

	HRESULT virtual __stdcall get_CredentialProvider	( IScpCredentialProvider** provider );
	HRESULT virtual __stdcall put_CredentialProvider	( IScpCredentialProvider* provider );

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

	void load( const mol::string& uri );

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

		virtual bool getCredentials(const std::string& host, int port,std::string& user, std::string& pwd);
		virtual bool promptCredentials(const std::string& host, int port,const std::string& prompt, const std::string& desc,std::string& value,bool echo);
		virtual bool acceptHost(const std::string& host, int port, const std::string& hash);
		virtual bool rememberHostCredentials(const std::string& host, int port, const std::string& user, const std::string& pwd);
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
	
	mol::punk<ShellListCtrl_Drop> Drop;
	mol::punk<IScpCredentialProvider> provider_;


    mol::string				path_;
	RECT					clientRect_;

	OLE_COLOR				bgCol_;
	OLE_COLOR				foreCol_;
	mol::Menu				listMenu_;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////




#endif