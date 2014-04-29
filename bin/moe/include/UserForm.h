#ifndef USERFORM_DEF_GUARD_
#define USERFORM_DEF_GUARD_

/*#include "moe.h"
#include "fm20_tlh.h"
*/
#include "commons.h"
#include "ole/SimpleHost.h"
#include "mdichild.h"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


class UserForm 
	: 
	public mol::Frame<
				UserForm,
				mol::ole::SimpleAxHost<UserForm,mol::Window>,
				WS_CAPTION |WS_POPUPWINDOW|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,0>,
	public mol::Dispatch<IMoeUserForm>,
	public mol::ProvideClassInfo<UserForm>,
	public mol::PersistStorage<UserForm>,
	public mol::interfaces< UserForm, 
			mol::implements< IDispatch, IMoeUserForm, IProvideClassInfo> >
{
public:

	UserForm();
	virtual ~UserForm();

	typedef mol::com_obj<UserForm> Instance;
	static Instance* CreateInstance( const std::wstring& p, bool designMode, bool Debug = false  );

	static REFGUID getCoClassID()
	{
		return IID_IMoeUserForm;
	}

	mol::punk<IMoeDialogView> view;

    virtual HRESULT __stdcall get_Object( IDispatch **d);    
    virtual HRESULT __stdcall get_View(  IMoeDialogView **d);    
    virtual HRESULT __stdcall get_Script(  IDispatch **s);    
    virtual HRESULT __stdcall get_FilePath(  BSTR *filename);

	// msgs
	msg_handler(WM_CLOSE,OnClose)
	LRESULT OnClose();

	msg_handler(WM_DESTROY,OnDestroy)
	void OnDestroy();

	msg_handler(WM_NCDESTROY,OnNcDestroy)
	void OnNcDestroy();

	msg_handler(WM_INITMENUPOPUP,OnMenu);
	void OnMenu( HMENU menu, LPARAM unused );

	// menu
	cmd_handler( IDM_FILE_EVENTS, OnEvents )
	void OnEvents();

	cmd_handler( IDM_FILE_MEMBERS, OnMembers )
	void OnMembers();

	cmd_handler( IDM_FORMLANG_JAVASCRIPT, OnLangJavascript )
	void OnLangJavascript();

	cmd_handler( IDM_FORMLANG_VBSCRIPT, OnLangVBScript )
	void OnLangVBScript();

	cmd_handler( IDM_FORMLANG_PERLSCRIPT, OnLangPerlScript )
	void OnLangPerlScript();

	bool isDirty() { return dirty_; }
	void setDirty(bool b) { dirty_ = b; }

	/////////////////////////////////////////////////////////////////////
	// COM
	/////////////////////////////////////////////////////////////////////

	virtual HRESULT __stdcall Close();
	virtual HRESULT __stdcall Show();
	virtual HRESULT __stdcall Hide();

    virtual HRESULT __stdcall Load( IStorage *pStg);
    virtual HRESULT __stdcall Save( IStorage* store, BOOL fSameAsLoad);      
    virtual HRESULT __stdcall InitNew(IStorage *pStg);

private:

	bool dirty_;
	std::wstring title_;
	std::wstring filename_;
	std::wstring scriptEngine_;

	ScriptingHost script;

	std::map<DWORD,IUnknown*>   sinks;
	std::map<DWORD,IUnknown*>   ctrls;
	std::map<DWORD,IID>			iids;

	bool initialize(const std::wstring& p, bool designMode, bool Debug);

	void adviseControls();
	void adviseControl(mol::bstr& name, IDispatch* disp);
	void unAdviseControls();
	void disconnectObjects();

};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#endif