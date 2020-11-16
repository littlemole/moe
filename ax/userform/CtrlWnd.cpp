#include "StdAfx.h"
#include "UserForm.h"
#include "CtrlWnd.h"
#include "Handler.h"
#include "EventDlg.h"
#include "MemberDlg.h"
#include "fm20_tlh.h" 
#include "win/shell.h"
#include "resource.h"

///////////////////////////////////////////////////////////////////////////////

FrameWindow::FrameWindow(UserForm* f)
{
	form = f;
	scriptEngine = _T("Javascript");

	menu.load(IDM_MENU_DESIGNFORM);
	icon.load(IDI_USERFORM, 32, 32);

	wndClass().setIcon(icon);
	wndClass().hIconSm(icon);
}

FrameWindow::~FrameWindow() {

	ODBGS("framewindow dead");
}



HRESULT __stdcall  FrameWindow::get_Object(IDispatch **d)
{
	if (!d)
		return E_INVALIDARG;

	*d = 0;
	return oleObject->QueryInterface(IID_IDispatch, (void**)d);
}


//////////////////////////////////////////////////////////////////////////////


void FrameWindow::OnEvents()
{
	mol::punk<MSForms::_UserForm> form(oleObject);
	if (form)
	{
		EventDlg dlg(form, scriptEngine);
		dlg.doModal(IDD_DIALOG_EVENTS, *this);
	}
}


void FrameWindow::OnMembers()
{
	mol::punk<MSForms::_UserForm> form(oleObject);
	if (form)
	{
		FuncDlg dlg(form, scriptEngine);
		dlg.doModal(IDD_DIALOG_EVENTS, *this);
	}
}


LRESULT FrameWindow::OnSave()
{
	form->Save();
	return 0;
}

LRESULT FrameWindow::OnClose()
{
	destroy();
	return 0;
}


void FrameWindow::OnDestroy()
{
	dispatch(L"Form_Close");

	setMenu(0);
	unAdviseControls();
	disconnectObjects();
}

void FrameWindow::OnNcDestroy()
{
	::CoDisconnectObject(((IMoeUserForm*)form), 0);
}

void FrameWindow::OnLangJavascript()
{
	scriptEngine = _T("Javascript");
}

void FrameWindow::OnLangVBScript()
{
	scriptEngine = _T("VBScript");
}


void FrameWindow::OnLangPerlScript()
{
	scriptEngine = _T("PerlScript");
}

void FrameWindow::OnMenu(HMENU popup, LPARAM unused)
{
	mol::Menu m = menu.getSubMenu(2);
	HMENU frameMenu = mol::UI().Menu(IDM_MENU_DESIGNFORM);

	if (popup == m )
	{
		mol::Menu m(popup);

		if (scriptEngine == _T("Javascript"))
		{
			m.checkItem(IDM_FORMLANG_JAVASCRIPT);
		}
		else
		{
			m.unCheckItem(IDM_FORMLANG_JAVASCRIPT);
		}

		if (scriptEngine == _T("VBScript"))
		{
			m.checkItem(IDM_FORMLANG_VBSCRIPT);
		}
		else
		{
			m.unCheckItem(IDM_FORMLANG_VBSCRIPT);
		}

		if (scriptEngine == _T("PerlScript"))
		{
			m.checkItem(IDM_FORMLANG_PERLSCRIPT);
		}
		else
		{
			m.unCheckItem(IDM_FORMLANG_PERLSCRIPT);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////


bool FrameWindow::initialize_existing(IStorage* store,const std::wstring& p, bool designMode) {

	DWORD formStyle = 0;

	mol::punk<IStorage> formStore;
	HRESULT hr = store->OpenStorage(L"FORM", 0, STGM_READ | STGM_SHARE_EXCLUSIVE, 0, 0, &formStore);
	if (hr != S_OK)
	{
		return false;
	}

	CLSID clsid;
	::ReadClassStg(store, &clsid);

	// create window
	if (designMode)
	{
		formStyle = WS_SYSMENU | WS_CAPTION | WS_THICKFRAME | WS_CAPTION | WS_POPUPWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
		createFrame(p, menu, formStyle);
	}
	else
	{
		formStyle = WS_SYSMENU | WS_CAPTION | WS_BORDER | WS_CAPTION | WS_POPUP | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
		createFrame(p, 0, formStyle);
	}

	loadObject(MSForms::CLSID_UserForm, formStore);
	adjustExtent(formStyle, designMode);
	adjustObjectRects();

	mol::punk<MSForms::_UserForm> form(oleObject);
	if (form)
	{
		form->Repaint();
		form->put_DesignMode(designMode ? MSForms::fmModeOn : MSForms::fmModeOff);

		mol::punk<IStream> stream;

		hr = store->OpenStream(L"SCRIPTENGINE", 0, STGM_READ | STGM_SHARE_EXCLUSIVE, 0, &stream);
		if (hr == S_OK)
		{
			DWORD size = 0;
			ULONG nread = 0;
			hr = stream->Read(&size, sizeof(DWORD), &nread);
			if (S_OK == hr)
			{
				mol::wbuff buf(size);
				ULONG cb = size * sizeof(wchar_t);
				hr = stream->Read(buf, cb, &nread);
				if (S_OK == hr)
				{
					std::wstring ws = buf.toString(nread / sizeof(wchar_t));
					scriptEngine = mol::towstring(ws);
				}
			}
		}

		if (!designMode)
		{
			adviseControls();
			dispatch(L"Form_Load");
			/*
			DISPID dispid;
			std::wstring ws = mol::towstring("Form_Load");
			mol::bstr func(ws);
			DISPPARAMS dispparams;
			memset(&dispparams, 0, sizeof dispparams);
			HRESULT hr = script->GetIDsOfNames(IID_NULL, &(func), 1, 0, &dispid);
			if (hr == S_OK)
			{
				EXCEPINFO excepInfo;
				memset(&excepInfo, 0, sizeof excepInfo);
				UINT nArgErr = (UINT)-1;
				mol::variant varResult;
				script->Invoke(dispid, IID_NULL,
					LOCALE_SYSTEM_DEFAULT,
					DISPATCH_METHOD,
					&dispparams,
					&varResult, &excepInfo, &nArgErr
				);
			}
			*/

		}		
	}
	return true;
}


bool FrameWindow::initialize_new(const std::wstring& p, bool designMode) {

	if (designMode == false)
		return false;

	createFrame(p, menu, WS_SYSMENU | WS_CAPTION | WS_THICKFRAME | WS_CAPTION | WS_POPUPWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);


	wchar_t  path[MAX_PATH];
	wchar_t  file[MAX_PATH];
	::GetTempPath(255, path);
	::GetTempFileName(path, _T("pf_"), 0, file);

	mol::punk<IStorage> store;
	if (S_OK == ::StgCreateDocfile(mol::towstring(file).c_str(), STGM_CREATE | STGM_READWRITE | STGM_SHARE_EXCLUSIVE | STGM_DELETEONRELEASE, 0, &store))
	{
		initObject(MSForms::CLSID_UserForm, store);

		mol::punk<MSForms::_UserForm> form(oleObject);
		if (form)
		{
			setExtent();
			adjustObjectRects();

			form->put_DesignMode(MSForms::fmModeOn);
			form->Repaint();
			::DrawMenuBar(*this);
		}
	}
	return true;
}


bool FrameWindow::initialize(IDispatch* disp,const std::wstring& p,bool designMode)
{
	script = disp;

	RECT moer = { 100,100,400,400 };
	DWORD formStyle = 0;

	mol::punk<IStorage> store;

	HRESULT hr = ::StgOpenStorage(
		mol::towstring(p).c_str(),
		NULL,
		STGM_READ | STGM_SHARE_EXCLUSIVE,
		0,
		0,
		&store);

	if (store)
	{
		return initialize_existing(store, p, designMode);
	}
	else
	{
		return initialize_new(p, designMode);
	}
	return true;
}

////////////////////////////////////////////////////////////////////////


void FrameWindow::adviseControls()
{
	mol::punk<MSForms::_UserForm> form(oleObject);
	if (!form)
		return;

	mol::punk<MSForms::Controls> controls;
	if (S_OK != form->get_Controls(&controls))
		return;
	if (!controls)
		return;

	long n = 0;
	if (S_OK != controls->get_Count(&n))
		return;

	for (long i = 0; i < n; i++)
	{
		mol::punk<IDispatch> disp;
		if (S_OK != controls->Item(mol::variant(i), &disp))
			continue;

		mol::punk<MSForms::IControl> c(disp);
		if (!c)
			continue;

		mol::bstr name;
		if ((S_OK == c->get_Name(&name)) && name)
		{
			adviseControl(name, disp);
		}
	}
}

void FrameWindow::adviseControl(mol::bstr& name, IDispatch* disp)
{
	IID iid;
	mol::punk<IUnknown> unk(disp);
	if (S_OK == mol::findSourceOnCP(unk, &iid))
	{
		DWORD cookie;
		mol::com_obj<FormScriptEventHandler>* handler = new mol::com_obj<FormScriptEventHandler>;
		handler->AddRef();

		//TODO: assure only to advis IF script handler present
		// use static factory func pattern
		handler->init(script, iid, name.towstring());

		mol::punk<IConnectionPointContainer>	icPc(disp);
		mol::punk<IConnectionPoint>			icP;
		HRESULT hr = icPc->FindConnectionPoint(iid, &icP);
		if (S_OK == hr)
		{
			hr = icP->Advise(handler, &cookie);
		}

		sinks[cookie] = handler;
		disp->AddRef();
		ctrls[cookie] = disp;
		iids[cookie] = iid;
	}
}

void FrameWindow::unAdviseControls()
{
	for (std::map<DWORD, IUnknown*>::iterator it = ctrls.begin(); it != ctrls.end(); it++)
	{
		mol::punk<IConnectionPointContainer>	icPc((*it).second);
		if (icPc)
		{
			mol::punk<IConnectionPoint>			icP;

			HRESULT hr = icPc->FindConnectionPoint(iids[(*it).first], &icP);
			if (S_OK == hr)
			{
				hr = icP->Unadvise((*it).first);
			}
			if (sinks.count((*it).first) > 0)
			{
				sinks[(*it).first]->Release();
				(*it).second->Release();
			}
		}
	}
	sinks.clear();
	ctrls.clear();
	disconnectObjects();
}

void FrameWindow::disconnectObjects()
{
	mol::punk<MSForms::_UserForm> f(oleObject);
	if (!f)
		return;

	mol::punk<MSForms::Controls> controls;
	if (S_OK != f->get_Controls(&controls))
		return;
	if (!controls)
		return;

	long n = 0;
	if (S_OK != controls->get_Count(&n))
		return;

	for (long i = 0; i < n; i++)
	{
		mol::punk<IDispatch> disp;
		if (S_OK == controls->Item(mol::variant(i), &disp))
		{
			if (disp)
			{
				::CoDisconnectObject(disp, 0);
				disp.release();
			}
		}
	}
}



///////////////////////////////////////////////////////////////////////////////



void FrameWindow::createFrame(std::wstring p, HMENU menu, DWORD formStyle) {

	create(p, menu, mol::Rect(100, 100, 400, 400), 0);
	::SetWindowLong(*this, GWL_STYLE, formStyle);
	::SetForegroundWindow(*this);
	this->show(SW_SHOW);
} 

void FrameWindow::setExtent() {

	RECT clientRect;
	getClientRect(clientRect);

	SIZEL l;
	l.cx = clientRect.right;
	l.cy = clientRect.bottom;

	mol::ole::PixeltoHIMETRIC(&l);
	oleObject->SetExtent(DVASPECT_CONTENT, &l);
}

void FrameWindow::adjustExtent(DWORD formStyle, bool designMode) {

	SIZEL l;
	RECT  r = { 100,100,400,400 };

	oleObject->GetExtent(DVASPECT_CONTENT, &l);

	// adjust size
	mol::ole::HIMETRICtoPixel(&l);

	r.right = r.left + l.cx;
	r.bottom = r.top + l.cy;
	AdjustWindowRect(&r, formStyle, designMode);
	move(r.left, r.top, r.right - r.left, r.bottom - r.top);
}

void FrameWindow::adjustObjectRects() {

	RECT clientRect;
	getClientRect(clientRect);

	mol::punk<IOleInPlaceObject> oip(oleObject);
	oip->SetObjectRects(&clientRect, &clientRect);
}



///////////////////////////////////////////////////////////////////////////////


bool FrameWindow::loadObject(REFCLSID clsid, IStorage* store)
{
	HRESULT hr = createEmbeddedObject(clsid, store);
	if (hr != S_OK)
		return false;

	mol::punk<IPersistStorage> ps(oleObject);
	if (!ps)
		return false;

	mol::punk<IStorage> s;
	hr = mol::ole::copyStorageTemp(store, &s);
	if (hr != S_OK)
		return false;

	hr = ps->Load(s);
	if (hr != S_OK)
		return false;

	hr = showEmbeddedObject(clsid, store);
	if (hr != S_OK)
	{
		return true;
	}
	return true;
}


HRESULT FrameWindow::createEmbeddedObject(REFCLSID clsid, IStorage* store)
{
	if (oleObject)
	{
		oleObject->Close(OLECLOSE_NOSAVE);
		oleObject.release();
	}

	HRESULT hr = oleObject.createObject(clsid);
	if (hr != S_OK)
	{
		std::wstring p = L"";
		if (mol::Path::exists(L"C:\\\\Program Files (x86)\\Microsoft Office\\root\\VFS\\SystemX86\\FM20.dll")) {
			p = L"\"C:\\\\Program Files (x86)\\Microsoft Office\\root\\VFS\\SystemX86\\FM20.dll\"";
		}
		if (mol::Path::exists(L"C:\\\\Program Files\\Microsoft Office\\root\\VFS\\SystemX86\\FM20.dll")) {
			p = L"\"C:\\\\Program Files\\Microsoft Office\\root\\VFS\\SystemX86\\FM20.dll\"";
		}
		if (p != L"") {

			int r = ::MessageBox(0, L"FM20.dll avail but not registered. register now?", L"register FM20.dll?", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2 | MB_SYSTEMMODAL);
			if (r == IDYES)
			{
				mol::io::execute_shell_admin(L"C:\\Windows\\System32\\regsvr32", p);
			}
		}
		return hr;
	}

	mol::punk<IOleClientSite> cs(clientSite);
	hr = oleObject->SetClientSite(cs);

	return hr;
}


void FrameWindow::dispatch(const std::wstring& ws)
{
	DISPID dispid;
	mol::bstr func(ws);
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof dispparams);
	HRESULT hr = script->GetIDsOfNames(IID_NULL, &(func), 1, 0, &dispid);
	if (hr == S_OK)
	{
		EXCEPINFO excepInfo;
		memset(&excepInfo, 0, sizeof excepInfo);
		UINT nArgErr = (UINT)-1;
		mol::variant varResult;
		script->Invoke(dispid, IID_NULL,
			LOCALE_SYSTEM_DEFAULT,
			DISPATCH_METHOD,
			&dispparams,
			&varResult, &excepInfo, &nArgErr
		);
	}
}
