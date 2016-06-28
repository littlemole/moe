#ifndef USERFORM_WND_DEF_GUARD_
#define USERFORM_WND_DEF_GUARD_


#include "common.h"

class UserForm;

class FrameWindow : public mol::Frame<
		FrameWindow,
		mol::ole::SimpleAxHost<FrameWindow, mol::Window>,
		WS_CAPTION | WS_POPUPWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0> 
{
public:

	std::wstring scriptEngine;
	mol::punk<IDispatch> script;

	FrameWindow(UserForm* form);
	~FrameWindow();

	bool initialize(IDispatch* disp,const std::wstring& p, bool designMode);

	HRESULT __stdcall  get_Object(IDispatch **d);

	// msgs

	cmd_handler(IDM_FILE_SAVE, OnSave)
		LRESULT OnSave();

	msg_handler(WM_CLOSE, OnClose)
	cmd_handler(IDM_FILE_CLOSE, OnClose)
		LRESULT OnClose();

	msg_handler(WM_DESTROY, OnDestroy)
		void OnDestroy();

	msg_handler(WM_NCDESTROY, OnNcDestroy)
		void OnNcDestroy();

	msg_handler(WM_INITMENUPOPUP, OnMenu);
	void OnMenu(HMENU menu, LPARAM unused);

	// menu
	cmd_handler(IDM_FILE_EVENTS, OnEvents)
		void OnEvents();

	cmd_handler(IDM_FILE_MEMBERS, OnMembers)
		void OnMembers();

	cmd_handler(IDM_FORMLANG_JAVASCRIPT, OnLangJavascript)
		void OnLangJavascript();

	cmd_handler(IDM_FORMLANG_VBSCRIPT, OnLangVBScript)
		void OnLangVBScript();

	cmd_handler(IDM_FORMLANG_PERLSCRIPT, OnLangPerlScript)
		void OnLangPerlScript();

protected:

	HRESULT createEmbeddedObject(REFCLSID clsid, IStorage* store);

	bool loadObject(REFCLSID clsid, IStorage* store);

private:

	bool initialize_existing(IStorage* store,const std::wstring& p, bool designMode);
	bool initialize_new(const std::wstring& p, bool designMode);

	void adjustObjectRects();
	void setExtent();
	void adjustExtent(DWORD formStyle, bool desginMode);
	void createFrame(std::wstring p, HMENU menu, DWORD formStyle);

	void adviseControls();
	void adviseControl(mol::bstr& name, IDispatch* disp);
	void unAdviseControls();
	void disconnectObjects();

	void dispatch(const std::wstring& ws);

	std::map<DWORD, IUnknown*>   sinks;
	std::map<DWORD, IUnknown*>   ctrls;
	std::map<DWORD, IID>			iids;

	mol::Menu menu;
	mol::Icon icon;

	UserForm* form;
};

///////////////////////////////////////////////////////////////////////////////

#endif