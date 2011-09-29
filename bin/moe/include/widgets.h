#ifndef MOE_DIALOGS_DEF_GUARD_
#define MOE_DIALOGS_DEF_GUARD_

#include "shared.h"

extern mol::TCHAR  InFilesFilter[];

/////////////////////////////////////////////////////////////////////////////////////////////
// widgets for moe
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeWnd;

mol::string findFile(const mol::string& f);
mol::string engineFromPath(const std::string& path);
std::string resolvePath(const std::string& p);

int msgbox( const mol::string& txt, const mol::string& title, const mol::string& detail );

void unlockInternetExplorer();

/////////////////////////////////////////////////////////////////////////////////////////////
// Status Bar
/////////////////////////////////////////////////////////////////////////////////////////////


class MoeStatusBar : public mol::StatusBarEx 
{
public:

	void status(int i);
	void status( const mol::string& txt );
};


/////////////////////////////////////////////////////////////////////////////////////////////
// the url box
/////////////////////////////////////////////////////////////////////////////////////////////


class UrlBox : public mol::Control< mol::RcomboBox,
                      WS_CHILD|WS_VISIBLE|CBS_DROPDOWN|
					  CBS_AUTOHSCROLL,
					  WS_EX_ACCEPTFILES|
					  CBS_DISABLENOSCROLL>
{
public:

	UrlBox();
	~UrlBox();

    void go( const std::string location );
	void updateGUI();

    virtual HRESULT __stdcall Load( LPSTREAM pStm) ;
    virtual HRESULT __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);
    virtual HRESULT __stdcall GetSizeMax( ULARGE_INTEGER *pCbSize);
   
private:
	
				
	std::list<std::string>  history_;

 };


/////////////////////////////////////////////////////////////////////////////////////////////
// URL Dialog
/////////////////////////////////////////////////////////////////////////////////////////////

class UrlDlg  : public mol::win::Dialog
{
friend mol::Singleton<UrlDlg>; 
friend mol::stack_obj<UrlDlg>;
public:
	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	mol::string url;

    virtual HRESULT __stdcall Load( LPSTREAM pStm);
    virtual HRESULT __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);
	virtual HRESULT __stdcall GetSizeMax( ULARGE_INTEGER *pCbSize);

private:
	UrlBox urlBox_;

	UrlDlg();
	~UrlDlg() {};
};


/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
// poor info dlg
/////////////////////////////////////////////////////////////////////////////////////////////

class InfoDlg  : public mol::win::Dialog
{
public:
	InfoDlg();
	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
private:
	mol::Icon icon_;
};

/////////////////////////////////////////////////////////////////////////////////////////////
// poor debugger dlg
/////////////////////////////////////////////////////////////////////////////////////////////

class DebugDlg  : public mol::win::Dialog
{
public:
	DebugDlg();
	~DebugDlg();

	mol::punk<IRemoteDebugApplicationThread> remote;

	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	class ExpCallback :
		public IDebugExpressionCallBack,
		public mol::interfaces< ExpCallback, mol::implements<IDebugExpressionCallBack> >
	{
		public: outer_this(DebugDlg,expCallback); 
			
				HRESULT virtual __stdcall onComplete();
	};

	void update_variables(IEnumDebugStackFrames* frames);

private:
	HRESULT addPropertyToList(HWND tree, TV_INSERTSTRUCTW *insertStruct, IDebugProperty *debugProperty, int level = 0);

	mol::stack_obj<ExpCallback> expCallback;
	mol::punk<IDebugExpression> exp_;
};

/////////////////////////////////////////////////////////////////////////////////////////////
// Simple Script Host (not the debug version, see ThreadScript.h for the full blown one)
/////////////////////////////////////////////////////////////////////////////////////////////


class Script : public mol::com_obj<mol::ScriptHost>
{
public:

	Script();
	~Script();

	void eval ( const mol::string& engine, const mol::string& script, IScintillAx* sci );
	void debug( const mol::string& engine, const mol::string& script, IScintillAx* sci );
	void call ( const mol::string& engine, const mol::string& func, const mol::string& script );

	void formscript( const mol::string& engine, const mol::string& script, IDispatch* form );
	void formdebug( const mol::string& engine, const mol::string& script, IDispatch* form );
	void formcontrols( IUnknown* form );

    virtual HRESULT  __stdcall OnScriptError( IActiveScriptError *pscripterror);
	virtual HRESULT  __stdcall GetWindow(HWND *phwnd );

private:
	 IScintillAx* sci_;
};

/////////////////////////////////////////////////////////////////////

typedef mol::punk<Script>		ScriptingHost;

/////////////////////////////////////////////////////////////////////

class FormScriptEventHandler : public IDispatch
{
public:
	~FormScriptEventHandler();

	void init(Script* s, REFIID iid, const mol::string& on);
	virtual void dispose() {}

	HRESULT virtual __stdcall QueryInterfaceImpl(REFIID iid , LPVOID* ppv) ;              
    HRESULT virtual __stdcall GetTypeInfoCount (unsigned int FAR*  pctinfo );
    HRESULT virtual __stdcall GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo );
    HRESULT virtual __stdcall GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId );
    HRESULT virtual __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i);

private:
	IID riid;
	Script* script;
	mol::punk< ITypeInfo> info;
	mol::string objname;
};



/////////////////////////////////////////////////////////////////////
// Drag&Drop COM Callback
/////////////////////////////////////////////////////////////////////

class MoeDrop : public mol::stack_obj<mol::ole::DropTargetBase>
{
friend mol::Singleton<MoeDrop>; 
friend mol::stack_obj<MoeDrop>;
public : 
	HRESULT virtual __stdcall Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect);
	HRESULT virtual __stdcall DragEnter( IDataObject*, DWORD, POINTL, DWORD* );
	HRESULT virtual __stdcall DragOver( DWORD, POINTL, DWORD* );
	HRESULT virtual __stdcall DragLeave();
private:
	MoeDrop() {}
	~MoeDrop() {}
};


/////////////////////////////////////////////////////////////////////
// Property Sheet
/////////////////////////////////////////////////////////////////////

class TabPage  : public mol::win::PropPage
{
public:
	TabPage();

	virtual void init();
	virtual int apply();
};

/////////////////////////////////////////////////////////////////////

class ExportPage  : public mol::win::PropPage
{
public:

	virtual void command(int c);
};

/////////////////////////////////////////////////////////////////////

class PrefPage  : public mol::ole::OlePropPage
{
public:

	PrefPage()
	{
		hbrushBackground_ = (HBRUSH)::GetStockObject(WHITE_BRUSH);
	}
	virtual void setObjects();
};

/////////////////////////////////////////////////////////////////////


class PasteAs
{
public:
	PasteAs();
	~PasteAs();

	std::wstring get();

private:

	mol::win::ClipBoard clipboard_;
};



class MolFileFialog : public mol::FilenameDlg
{
public:

	typedef std::pair<int,std::wstring> CodePage;

	MolFileFialog( HWND parent );

	virtual void OnCustomize();
	virtual void OnInit();
	virtual void OnDestroy();

	int codePage();
	void codePage(int cp);
private:
	int index_;
	mol::ComboBox combo_;
};


MIDL_INTERFACE("b4db1657-70d7-485e-8e3e-6fcb5a5c1802")
IModalWindow : public IUnknown
{
public:
    virtual /* [local] */ HRESULT STDMETHODCALLTYPE Show( 
        /* [annotation][unique][in] */ 
        __in_opt  HWND hwndOwner) = 0;
        
};

enum _FILEOPENDIALOGOPTIONS
    {	FOS_OVERWRITEPROMPT	= 0x2,
	FOS_STRICTFILETYPES	= 0x4,
	FOS_NOCHANGEDIR	= 0x8,
	FOS_PICKFOLDERS	= 0x20,
	FOS_FORCEFILESYSTEM	= 0x40,
	FOS_ALLNONSTORAGEITEMS	= 0x80,
	FOS_NOVALIDATE	= 0x100,
	FOS_ALLOWMULTISELECT	= 0x200,
	FOS_PATHMUSTEXIST	= 0x800,
	FOS_FILEMUSTEXIST	= 0x1000,
	FOS_CREATEPROMPT	= 0x2000,
	FOS_SHAREAWARE	= 0x4000,
	FOS_NOREADONLYRETURN	= 0x8000,
	FOS_NOTESTFILECREATE	= 0x10000,
	FOS_HIDEMRUPLACES	= 0x20000,
	FOS_HIDEPINNEDPLACES	= 0x40000,
	FOS_NODEREFERENCELINKS	= 0x100000,
	FOS_DONTADDTORECENT	= 0x2000000,
	FOS_FORCESHOWHIDDEN	= 0x10000000,
	FOS_DEFAULTNOMINIMODE	= 0x20000000,
	FOS_FORCEPREVIEWPANEON	= 0x40000000
    } ;
typedef DWORD FILEOPENDIALOGOPTIONS;

typedef /* [v1_enum] */ 
enum FDAP
{	FDAP_BOTTOM	= 0,
	FDAP_TOP	= 1
} 	FDAP;


typedef struct _COMDLG_FILTERSPEC
{
    LPCWSTR pszName;
    LPCWSTR pszSpec;
} 	COMDLG_FILTERSPEC;

MIDL_INTERFACE("42f85136-db7e-439c-85f1-e4075d135fc8")
IFileDialog : public IModalWindow
{
public:
    virtual HRESULT STDMETHODCALLTYPE SetFileTypes( 
        /* [in] */ UINT cFileTypes,
        /* [size_is][in] */ __RPC__in_ecount_full(cFileTypes) const COMDLG_FILTERSPEC *rgFilterSpec) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetFileTypeIndex( 
        /* [in] */ UINT iFileType) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE GetFileTypeIndex( 
        /* [out] */ __RPC__out UINT *piFileType) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE Advise( 
        /* [in] */ __RPC__in_opt IFileDialogEvents *pfde,
        /* [out] */ __RPC__out DWORD *pdwCookie) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE Unadvise( 
        /* [in] */ DWORD dwCookie) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetOptions( 
        /* [in] */ FILEOPENDIALOGOPTIONS fos) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE GetOptions( 
        /* [out] */ __RPC__out FILEOPENDIALOGOPTIONS *pfos) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetDefaultFolder( 
        /* [in] */ __RPC__in_opt IShellItem *psi) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetFolder( 
        /* [in] */ __RPC__in_opt IShellItem *psi) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE GetFolder( 
        /* [out] */ __RPC__deref_out_opt IShellItem **ppsi) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE GetCurrentSelection( 
        /* [out] */ __RPC__deref_out_opt IShellItem **ppsi) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetFileName( 
        /* [string][in] */ __RPC__in_string LPCWSTR pszName) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE GetFileName( 
        /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *pszName) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetTitle( 
        /* [string][in] */ __RPC__in_string LPCWSTR pszTitle) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetOkButtonLabel( 
        /* [string][in] */ __RPC__in_string LPCWSTR pszText) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetFileNameLabel( 
        /* [string][in] */ __RPC__in_string LPCWSTR pszLabel) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE GetResult( 
        /* [out] */ __RPC__deref_out_opt IShellItem **ppsi) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE AddPlace( 
        /* [in] */ __RPC__in_opt IShellItem *psi,
        /* [in] */ FDAP fdap) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetDefaultExtension( 
        /* [string][in] */ __RPC__in_string LPCWSTR pszDefaultExtension) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE Close( 
        /* [in] */ HRESULT hr) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetClientGuid( 
        /* [in] */ __RPC__in REFGUID guid) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE ClearClientData( void) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetFilter( 
        /* [in] */ __RPC__in_opt IShellItemFilter *pFilter) = 0;
        
};

typedef /* [v1_enum] */ 
enum CDCONTROLSTATEF
    {	CDCS_INACTIVE	= 0,
	CDCS_ENABLED	= 0x1,
	CDCS_VISIBLE	= 0x2,
	CDCS_ENABLEDVISIBLE	= 0x3
    } 	CDCONTROLSTATEF;

DEFINE_ENUM_FLAG_OPERATORS(CDCONTROLSTATEF)

MIDL_INTERFACE("e6fdd21a-163f-4975-9c8c-a69f1ba37034")
IFileDialogCustomize : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE EnableOpenDropDown( 
        /* [in] */ DWORD dwIDCtl) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE AddMenu( 
        /* [in] */ DWORD dwIDCtl,
        /* [string][in] */ __RPC__in_string LPCWSTR pszLabel) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE AddPushButton( 
        /* [in] */ DWORD dwIDCtl,
        /* [string][in] */ __RPC__in_string LPCWSTR pszLabel) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE AddComboBox( 
        /* [in] */ DWORD dwIDCtl) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE AddRadioButtonList( 
        /* [in] */ DWORD dwIDCtl) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE AddCheckButton( 
        /* [in] */ DWORD dwIDCtl,
        /* [string][in] */ __RPC__in_string LPCWSTR pszLabel,
        /* [in] */ BOOL bChecked) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE AddEditBox( 
        /* [in] */ DWORD dwIDCtl,
        /* [string][in] */ __RPC__in_string LPCWSTR pszText) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE AddSeparator( 
        /* [in] */ DWORD dwIDCtl) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE AddText( 
        /* [in] */ DWORD dwIDCtl,
        /* [string][in] */ __RPC__in_string LPCWSTR pszText) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetControlLabel( 
        /* [in] */ DWORD dwIDCtl,
        /* [string][in] */ __RPC__in_string LPCWSTR pszLabel) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE GetControlState( 
        /* [in] */ DWORD dwIDCtl,
        /* [out] */ __RPC__out CDCONTROLSTATEF *pdwState) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetControlState( 
        /* [in] */ DWORD dwIDCtl,
        /* [in] */ CDCONTROLSTATEF dwState) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE GetEditBoxText( 
        /* [in] */ DWORD dwIDCtl,
        /* [string][out] */ __RPC__deref_out_opt_string WCHAR **ppszText) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetEditBoxText( 
        /* [in] */ DWORD dwIDCtl,
        /* [string][in] */ __RPC__in_string LPCWSTR pszText) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE GetCheckButtonState( 
        /* [in] */ DWORD dwIDCtl,
        /* [out] */ __RPC__out BOOL *pbChecked) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetCheckButtonState( 
        /* [in] */ DWORD dwIDCtl,
        /* [in] */ BOOL bChecked) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE AddControlItem( 
        /* [in] */ DWORD dwIDCtl,
        /* [in] */ DWORD dwIDItem,
        /* [in] */ __RPC__in LPCWSTR pszLabel) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE RemoveControlItem( 
        /* [in] */ DWORD dwIDCtl,
        /* [in] */ DWORD dwIDItem) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE RemoveAllControlItems( 
        /* [in] */ DWORD dwIDCtl) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE GetControlItemState( 
        /* [in] */ DWORD dwIDCtl,
        /* [in] */ DWORD dwIDItem,
        /* [out] */ __RPC__out CDCONTROLSTATEF *pdwState) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetControlItemState( 
        /* [in] */ DWORD dwIDCtl,
        /* [in] */ DWORD dwIDItem,
        /* [in] */ CDCONTROLSTATEF dwState) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE GetSelectedControlItem( 
        /* [in] */ DWORD dwIDCtl,
        /* [out] */ __RPC__out DWORD *pdwIDItem) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetSelectedControlItem( 
        /* [in] */ DWORD dwIDCtl,
        /* [in] */ DWORD dwIDItem) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE StartVisualGroup( 
        /* [in] */ DWORD dwIDCtl,
        /* [string][in] */ __RPC__in_string LPCWSTR pszLabel) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE EndVisualGroup( void) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE MakeProminent( 
        /* [in] */ DWORD dwIDCtl) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE SetControlItemText( 
        /* [in] */ DWORD dwIDCtl,
        /* [in] */ DWORD dwIDItem,
        /* [string][in] */ __RPC__in_string LPCWSTR pszLabel) = 0;
        
};

MIDL_INTERFACE("d57c7288-d4ad-4768-be02-9d969532d960")
IFileOpenDialog : public IFileDialog
{
public:
    virtual HRESULT STDMETHODCALLTYPE GetResults( 
        /* [out] */ __RPC__deref_out_opt IShellItemArray **ppenum) = 0;
        
    virtual HRESULT STDMETHODCALLTYPE GetSelectedItems( 
        /* [out] */ __RPC__deref_out_opt IShellItemArray **ppsai) = 0;
        
};

#define CONTROL_GROUP           2000
#define CONTROL_COMBOBOX        2001

#define OPENCHOICES					0
#define OPENCHOICES_OPEN			0
#define OPENCHOICES_OPEN_READONLY	1

class MoeVistaFileDialog
{
public:

	MoeVistaFileDialog(HWND parent);

	void setFilter(COMDLG_FILTERSPEC* filter, int size);

	HRESULT open(int options);
	HRESULT save(int options);

	long encoding();
	long type();
	bool readOnly();

	void encoding(long enc);

	const std::vector<std::wstring>& paths();
	const std::wstring& path();

	void path(const std::wstring& path);
private:

	HRESULT addEncodingComboBox();
	HRESULT init(int options, REFCLSID clsid);

	mol::punk<IFileDialog> fd_;
	mol::punk<IFileDialogCustomize> fdc_;

	long encoding_;
	bool readOnly_;
	UINT type_;
	std::vector<std::wstring> paths_;
	HWND parent_;
	COMDLG_FILTERSPEC* filter_;
	UINT nFilters_;
	std::wstring path_;
};

MOE_DOCTYPE index2type(int index);


#endif