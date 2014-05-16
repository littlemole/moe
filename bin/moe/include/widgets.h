#ifndef MOE_DIALOGS_DEF_GUARD_
#define MOE_DIALOGS_DEF_GUARD_

#include "shared.h"
#include "win/v7.h"

extern wchar_t  InFilesFilter[];

/////////////////////////////////////////////////////////////////////////////////////////////
// widgets for moe
/////////////////////////////////////////////////////////////////////////////////////////////

class MoeWnd;

std::wstring findFile(const std::wstring& f);
std::wstring engineFromPath(const std::string& path);
std::string resolvePath(const std::string& p);

/////////////////////////////////////////////////////////////////////
// tree events sink
/////////////////////////////////////////////////////////////////////

class TreeWndSink : public ShellTreeEvents
{
public :

	typedef mol::stack_obj<TreeWndSink> Instance;

	HRESULT virtual __stdcall OnTreeSelection(BSTR filename);
	HRESULT virtual __stdcall OnTreeDblClick(BSTR filename,VARIANT_BOOL vb);
	HRESULT virtual __stdcall OnTreeOpen(BSTR filename,VARIANT_BOOL vb); 
	HRESULT virtual __stdcall OnContextMenu(BSTR filename,VARIANT_BOOL vb); 
};

/////////////////////////////////////////////////////////////////////
// Drag&Drop COM Callback
/////////////////////////////////////////////////////////////////////

class MoeDrop : public mol::stack_obj<mol::ole::DropTargetBase>
{
public : 
	HRESULT virtual __stdcall Drop( IDataObject* pDataObject, DWORD keyState, POINTL pt , DWORD* pEffect);
	HRESULT virtual __stdcall DragEnter( IDataObject*, DWORD, POINTL, DWORD* );
	HRESULT virtual __stdcall DragOver( DWORD, POINTL, DWORD* );
	HRESULT virtual __stdcall DragLeave();
	MoeDrop() {}
	~MoeDrop() {}
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
public:

	UrlDlg();
	~UrlDlg() {};

	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	std::wstring url;

    virtual HRESULT __stdcall Load( LPSTREAM pStm);
    virtual HRESULT __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);
	virtual HRESULT __stdcall GetSizeMax( ULARGE_INTEGER *pCbSize);

private:
	UrlBox urlBox_;
};


/////////////////////////////////////////////////////////////////////////////////////////////
// Status Bar
/////////////////////////////////////////////////////////////////////////////////////////////


class MoeStatusBar : public mol::StatusBarEx 
{
public:

	void status(int i);
	void status( const std::wstring& txt );
};





/////////////////////////////////////////////////////////////////////////////////////////////

class Encodings
{
public:

  	 Encodings();

	 typedef std::pair<int,std::wstring> CodePage;
	 typedef std::vector<CodePage>::iterator Iterator;

	 Iterator begin()
	 {
		 return codePages_.begin();
	 }

	 Iterator end()
	 {
		 return codePages_.end();
	 }

	 CodePage& item (int index)
	 {
		 return codePages_[index];
	 }

	 size_t index( int cp )
	 {
		 for ( size_t i = 0; i < codePages_.size(); i++)
		 {
			 if ( codePages_[i].first == cp )
			 {
				 return i;
			 }
		 }
		 return -1;
	 }

private:
	 	std::vector<CodePage> codePages_;
};

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

	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	void update_variables(IEnumDebugStackFrames* frames);

private:
	HRESULT addPropertyToList(HWND tree, TV_INSERTSTRUCTW *insertStruct, IDebugProperty *debugProperty, int level = 0);

};

/////////////////////////////////////////////////////////////////////////////////////////////
// Simple Script Host (not the debug version, see ThreadScript.h for the full blown one)
/////////////////////////////////////////////////////////////////////////////////////////////


class Script;

/////////////////////////////////////////////////////////////////////

class FormScriptEventHandler : public IDispatch
{
public:
	~FormScriptEventHandler();

	void init(Script* s, REFIID iid, const std::wstring& on);
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
	std::wstring objname;
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

	HWND parent_;
	long encoding_;
	bool readOnly_;
	UINT type_;
	UINT nFilters_;
	std::wstring path_;
	std::vector<std::wstring> paths_;
	COMDLG_FILTERSPEC* filter_;
};

MOE_DOCTYPE index2type(int index);

class MoeScriptObject : public IDispatchEx,
	 	public mol::interfaces< MoeScriptObject, mol::implements< IDispatch, IDispatchEx >>
{
public:
public:

	typedef mol::com_obj<MoeScriptObject> Instance;
	static HRESULT CreateInstance(IDispatch** d, const std::wstring& progid);

	void virtual dispose() {};

	HRESULT virtual __stdcall GetTypeInfoCount (unsigned int FAR*  pctinfo ) { *pctinfo = 0; return S_OK; }
    HRESULT virtual __stdcall GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo )  { *ppTInfo = 0; return E_NOTIMPL; }
    HRESULT virtual __stdcall GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId );
    HRESULT virtual __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i);

    HRESULT virtual __stdcall GetDispID( BSTR bstrName, DWORD grfdex, DISPID *pid);
    HRESULT virtual __stdcall InvokeEx( DISPID id,LCID lcid, WORD wFlags, DISPPARAMS *pdp, VARIANT *pvarRes, EXCEPINFO *pei, IServiceProvider *pspCaller);
    HRESULT virtual __stdcall DeleteMemberByName( BSTR bstrName, DWORD grfdex);        
    HRESULT virtual __stdcall DeleteMemberByDispID( DISPID id);    
    HRESULT virtual __stdcall GetMemberProperties( DISPID id, DWORD grfdexFetch, DWORD *pgrfdex);       
    HRESULT virtual __stdcall GetMemberName( DISPID id, BSTR *pbstrName);       
    HRESULT virtual __stdcall GetNextDispID( DWORD grfdex, DISPID id, DISPID *pid);       
    HRESULT virtual __stdcall GetNameSpaceParent( IUnknown **ppunk);

private:

	std::wstring progId_;
};

class MoeImport : 
 	public mol::Dispatch<IMoeImport>,
 	public mol::interfaces< MoeImport, 
 				mol::implements< IDispatch, IMoeImport> >
{
public:
 
 	typedef mol::com_obj<MoeImport> Instance;
 	typedef mol::com_obj<mol::ScriptHost> Host;
 
 	void dispose();
 
 	static Instance* CreateInstance(Host* host);
 
 	virtual HRESULT __stdcall  Import(BSTR filename);
 	virtual HRESULT __stdcall  Sleep(long ms);
 	virtual HRESULT __stdcall  Wait(long ms,VARIANT_BOOL* vb);
 	virtual HRESULT __stdcall  Quit();
	virtual HRESULT __stdcall  get_Dispatch(IDispatch** disp);
	virtual HRESULT __stdcall  Callback(BSTR name,IDispatch** disp);
	virtual HRESULT __stdcall  setTimeout( VARIANT f, VARIANT d, VARIANT* retval);
	virtual HRESULT __stdcall  clearTimeout( VARIANT t);

private:
 	mol::punk<Host> host_;
	HANDLE stop_;
};



class EventWrapper : 
	public IDispatch, 
	public mol::interfaces<
				EventWrapper,
				mol::implements<IDispatch>>
{
public:

	typedef mol::com_obj<EventWrapper> Instance;
	static HRESULT CreateInstance(IDispatch* disp, BSTR handler, IDispatch** d);

	void virtual dispose() {};

	HRESULT virtual __stdcall GetTypeInfoCount (unsigned int FAR*  pctinfo ) 
    { 
        *pctinfo = 0;
        return S_OK; 
    }

    HRESULT virtual __stdcall GetTypeInfo ( unsigned int  iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo ) 
    { 
		*ppTInfo = 0;
        return E_NOTIMPL; 
    }

    HRESULT virtual __stdcall GetIDsOfNames( REFIID  riid, OLECHAR FAR* FAR*  rgszNames, unsigned int  cNames, LCID   lcid, DISPID FAR*  rgDispId );

    HRESULT virtual __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD w, DISPPARAMS *pDisp, VARIANT* pReturn, EXCEPINFO * ex, UINT * i);

private:

	IDispatch* handler_;
	mol::bstr callback_;
};



#endif