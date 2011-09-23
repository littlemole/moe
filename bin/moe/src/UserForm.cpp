#include "StdAfx.h"
#include "UserForm.h"
#include "moe.h"
#include "Docs.h"
#include "MoeBar.h"
#include "xmlui.h"

///////////////////////////////////////////////////////////////////////////////

class EventDlg  : public mol::win::Dialog
{
public:
	EventDlg(MSForms::_UserForm* f, const mol::string& engine );
	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	mol::punk<MSForms::_UserForm> form;

private:

	void populateControlTree(IUnknown* ctrl , HTREEITEM hit);
	void populateControlList(HTREEITEM hit);
	void copySelectionToClipboard();
	
	void freeTree(HTREEITEM it );
	void freeList();

	mol::TreeCtrl		tree_;
	mol::ListBox		list_;
	mol::string			engine_;
};

///////////////////////////////////////////////////////////////////////////////

class FuncDlg  : public mol::win::Dialog
{
public:
	FuncDlg(MSForms::_UserForm* f, const mol::string& engine);
	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	mol::punk<MSForms::_UserForm> form;

private:
	void populateControlTree(IUnknown* ctrl , HTREEITEM hit);
	void populateControlList(HTREEITEM hit);
	HRESULT addTypeInfo(ITypeInfo* typInf,mol::bstr& name );
	void copySelectionToClipboard();
	
	void freeTree(HTREEITEM it );
	void freeList();

	mol::TreeCtrl		tree_;
	mol::ListBox		list_;
	mol::string			engine_;
};


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

using namespace mol::io;

UserForm::UserForm( ) 
{
	wndClass().setIcon(moe()->icon); 
	wndClass().hIconSm(moe()->icon); 
	scriptEngine_ = _T("Javascript");
	dirty_ = false;

	this->script = new Script;
}

//////////////////////////////////////////////////////////////////////////////

UserForm::~UserForm() 
{
	ODBGS("~UserForm dies");
};

void UserForm::OnEvents()
{
	mol::punk<MSForms::_UserForm> form(oleObject);
	if ( form )
	{
		EventDlg dlg(form,scriptEngine_);
		dlg.doModal(IDD_DIALOG_EVENTS,*moe());
	}
}


void UserForm::OnMembers()
{
	mol::punk<MSForms::_UserForm> form(oleObject);
	if ( form )
	{
		FuncDlg dlg(form,scriptEngine_);
		dlg.doModal(IDD_DIALOG_EVENTS,*moe());
	}
}

//////////////////////////////////////////////////////////////////////////////
// initialization
//////////////////////////////////////////////////////////////////////////////

UserForm::Instance* UserForm::CreateInstance( const mol::string& dir, bool designMode, bool Debug )
{
	Instance* doc = 0;

	if ( dir.size() < 1 )
		return doc;

	mol::string p(dir);

	if ( mol::Path::isDir(p) )
		return doc;

	
	doc = new Instance;
	if (!doc->initialize(p, designMode, Debug))
	{
		doc->destroy();
		doc->Release();
		return 0;
	}


	return doc;
}

bool UserForm::initialize(const mol::string& p, bool designMode, bool Debug)
{
	filename_ = p;

	// initial Addref
	((IMoeUserForm*)this)->AddRef();

	mol::punk<IStorage> store;
	mol::punk<IStorage> formStore;

	HRESULT hr = ::StgOpenStorage( 
					mol::towstring(p).c_str(), 
					NULL,
					STGM_READ|STGM_SHARE_EXCLUSIVE,
					0,
					0,
					&store);
	if ( hr == S_OK )
	{
		hr = store->OpenStorage( L"FORM",0,STGM_READ|STGM_SHARE_EXCLUSIVE,0,0,&formStore);
	}

	RECT moer;
	::GetWindowRect(*moe(),&moer);

	DWORD formStyle = 0;

	if ( formStore )
	{
		// create window
		if ( designMode )
		{
			HMENU m = mol::UI().Menu(IDM_MENU_DESIGNFORM);
			moer.left = moer.right-400;
			moer.top += 100;
			create(p,m,mol::Rect(moer.left,moer.top,500,500),*moe());	
			formStyle = WS_SYSMENU|WS_CAPTION|WS_THICKFRAME|WS_CAPTION |WS_POPUPWINDOW|WS_CLIPSIBLINGS|WS_CLIPCHILDREN;
			::SetWindowLong(*this,GWL_STYLE,formStyle);//WS_OVERLAPPEDWINDOW );
		}
		else
		{
			moer.left = moer.left+400;
			moer.top += 200;
			create( p, (HMENU)IDW_EDITOR_VIEW, mol::Rect(moer.left,moer.top,300,400),*moe() );
			formStyle = WS_SYSMENU|WS_CAPTION|WS_BORDER|WS_CAPTION |WS_POPUP|WS_CLIPSIBLINGS|WS_CLIPCHILDREN;
			::SetWindowLong(*this,GWL_STYLE,formStyle);//WS_OVERLAPPEDWINDOW );
			::EnableWindow( *moe(), FALSE);
		}

		view = MoeDialogView::CreateInstance(this);
		show(SW_SHOW);

		SIZEL l;
		RECT  r;
		CLSID clsid;

		::ReadClassStg(store,&clsid);

		loadObject(MSForms::CLSID_UserForm,formStore);
		oleObject->GetExtent(DVASPECT_CONTENT,&l);

		// adjust size
		mol::ole::HIMETRICtoPixel(&l);
		r = moer;
//		r.left = r.top = 100;
		r.right=r.left+l.cx;
		r.bottom=r.top+l.cy;
		AdjustWindowRect(&r,formStyle,designMode);
		move(r.left,r.top,r.right-r.left,r.bottom-r.top );

		getClientRect(r);

		r.left -=4;
		r.top -=4;

		mol::punk<IOleInPlaceObject>	inplace(oleObject);
		inplace->SetObjectRects(&r, &r);


		mol::punk<MSForms::_UserForm> form(oleObject);
		if ( form )
		{
			form->Repaint();
			form->put_DesignMode( designMode ? MSForms::fmModeOn : MSForms::fmModeOff);

			mol::punk<IStream> stream;

			hr = store->OpenStream( L"SCRIPTENGINE",0,STGM_READ|STGM_SHARE_EXCLUSIVE,0,&stream);
			if ( hr == S_OK )
			{
				DWORD size = 0;
				ULONG nread = 0;
				hr = stream->Read( &size, sizeof(DWORD), &nread);
				if ( S_OK == hr )
				{
					wchar_t* buf = new wchar_t[size];
					ULONG cb = size*sizeof(wchar_t);
					hr = stream->Read( buf, cb, &nread);
					if ( S_OK == hr )
					{
						std::wstring ws = std::wstring( buf, nread/sizeof(wchar_t) );
						scriptEngine_ = mol::toString(ws);
					}
					delete[] buf;
				}
			}

			if ( !designMode )
			{
				hr = store->OpenStream( L"CONTENT",0,STGM_READ|STGM_SHARE_EXCLUSIVE,0,&stream);
				if ( hr == S_OK )
				{
					ULONG nread = 0;
					DWORD size = 0;

					hr = stream->Read( &size, sizeof(DWORD), &nread);
					if ( hr == S_OK )
					{
						wchar_t* buf = new wchar_t[size+1];

						ULONG cb = size*sizeof(wchar_t);
						hr = stream->Read( buf, cb, &nread);
						std::wstring ws = std::wstring( buf, nread/sizeof(wchar_t) );
						delete[] buf;

						stream.release();


						if ( !Debug )
							script->formscript( scriptEngine_, mol::toString(ws), (IMoeUserForm*)this);
						else
							script->formdebug( scriptEngine_, mol::toString(ws), (IMoeUserForm*)this);

						script->formcontrols(form);
					}					
				}
			}
			else 
			{
			}
			adviseControls();
		}
	}
	else
	{
		if ( designMode == false )
			return false;

		create(p,(HMENU)(mol::UI().Menu(IDM_MENU_DESIGNFORM)),mol::Rect(moer.left+moer.right-400,moer.top+100,400,400),*moe());	
		::SetWindowLong(*this,GWL_STYLE,WS_SYSMENU|WS_CAPTION|WS_THICKFRAME|WS_CAPTION |WS_POPUPWINDOW|WS_CLIPSIBLINGS|WS_CLIPCHILDREN);//WS_OVERLAPPEDWINDOW );

		view = MoeDialogView::CreateInstance(this);
		this->show(SW_SHOW);

		mol::TCHAR  path[MAX_PATH];
		mol::TCHAR  file[MAX_PATH];
		::GetTempPath(255,path);
		::GetTempFileName( path, _T("pf_"), 0, file );

		RECT clientRect_;
		getClientRect(clientRect_);

		mol::punk<IStorage> store;
		if ( S_OK == ::StgCreateDocfile( mol::towstring(file).c_str(),STGM_CREATE|STGM_READWRITE|STGM_SHARE_EXCLUSIVE|STGM_DELETEONRELEASE,0,&store) )
		{
			initObject(MSForms::CLSID_UserForm,store);

			mol::punk<MSForms::_UserForm> form(oleObject);
			if ( form )
			{
				form->put_DesignMode(MSForms::fmModeOn);
				SIZEL l;
				l.cx = clientRect_.right;
				l.cy = clientRect_.bottom;

				mol::ole::PixeltoHIMETRIC(&l);
				oleObject->SetExtent(DVASPECT_CONTENT,&l);
				getClientRect(clientRect_);
				
				mol::punk<IOleInPlaceObject> oip(oleObject);
				oip->SetObjectRects(&clientRect_,&clientRect_);
				form->Repaint();		
				::DrawMenuBar(*this);
			}			
		}	
	}
	return true;
}


//////////////////////////////////////////////////////////////////////////////
//
// Close & Destroy 
//
//////////////////////////////////////////////////////////////////////////////

LRESULT UserForm::OnClose()
{
	mol::punk<MSForms::_UserForm> form(oleObject);
	if ( form )
	{
		MSForms::fmMode mode;
		HRESULT hr = form->get_DesignMode(&mode);
		if ( hr == S_OK )
		{
			if ( mode == MSForms::fmModeOn )
			{
				Hide();
				return 0;
			}
		}
	}
	this->destroy();
	return 0;
}


void UserForm::OnDestroy()
{
	setMenu(0);
	script->close();
	script.release();
	unAdviseControls();
	disconnectObjects();
}

void UserForm::OnNcDestroy()
{
	::CoDisconnectObject(((IMoeUserForm*)this),0);
	((IMoeUserForm*)this)->Release();
	::EnableWindow( *moe(), TRUE);
	::SetActiveWindow( *moe() );
}

void UserForm::OnLangJavascript()
{
	scriptEngine_ = _T("Javascript");
}

void UserForm::OnLangVBScript()
{
	scriptEngine_ = _T("VBScript");
}


void UserForm::OnLangPerlScript()
{
	scriptEngine_ = _T("PerlScript");
}

void UserForm::OnMenu(HMENU popup, LPARAM unused)
{
	HMENU frameMenu = mol::UI().Menu(IDM_MENU_DESIGNFORM);

	if ( popup == mol::UI().SubMenu(IDM_MENU_DESIGNFORM,IDM_FORMLANG) )
	{
		mol::Menu m(popup);

		if ( scriptEngine_ == _T("Javascript") ) 
		{
			m.checkItem(IDM_FORMLANG_JAVASCRIPT );
		}
		else 
		{
			m.unCheckItem(IDM_FORMLANG_JAVASCRIPT );
		}

		if ( scriptEngine_ == _T("VBScript") ) 
		{
			m.checkItem(IDM_FORMLANG_VBSCRIPT );
		}
		else 
		{
			m.unCheckItem(IDM_FORMLANG_VBSCRIPT );
		}

		if ( scriptEngine_ == _T("PerlScript") ) 
		{
			m.checkItem(IDM_FORMLANG_PERLSCRIPT );
		}
		else 
		{
			m.unCheckItem(IDM_FORMLANG_PERLSCRIPT );
		}
	}
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  UserForm::get_Object( IDispatch **d)
{
	if (!d)
		return E_INVALIDARG;
	*d=0;

	return oleObject->QueryInterface( IID_IDispatch, (void**)d );
}

HRESULT __stdcall  UserForm::get_View(  IMoeDialogView **d)
{
	if (!d)
		return E_INVALIDARG;
	*d=0;

	return view->QueryInterface( IID_IMoeDialogView, (void**)d);
}

HRESULT __stdcall  UserForm::get_Script(  IDispatch **s)
{
	mol::punk<IDispatch> disp;
	if ( (S_OK == script->getScript(_T(""),&disp)) )
	{
		return disp->QueryInterface(IID_IDispatch, (void**)s);
	}

	return S_OK;
}

HRESULT __stdcall  UserForm::get_FilePath(  BSTR *filename)
{
	if (!filename)
		return E_INVALIDARG;
	*filename=0;

	*filename = ::SysAllocString( mol::towstring(filename_).c_str() );
	return S_OK;
}



HRESULT __stdcall UserForm::Load( IStorage *pStg) 
{
	return E_NOTIMPL;
}

HRESULT __stdcall UserForm::Save( IStorage* store, BOOL fSameAsLoad)
{
	mol::punk<IStorage> formStore;
	if ( S_OK == store->CreateStorage( L"FORM",STGM_READWRITE|STGM_CREATE|STGM_SHARE_EXCLUSIVE,0,0,&formStore ) )
	{

		mol::punk<IPersistStorage> ps(oleObject);
		if ( ps )
		{
			::WriteClassStg(store,MSForms::CLSID_UserForm);
			HRESULT hr = ps->Save(formStore,FALSE);
			hr = ps->SaveCompleted(formStore);
			hr = formStore->Commit( STGC_DEFAULT  );
		}
	}

	mol::punk<IStream> stream;
	if ( S_OK == store->CreateStream( L"SCRIPTENGINE", STGM_READWRITE|STGM_CREATE|STGM_SHARE_EXCLUSIVE,0,0,&stream ) )
	{
		DWORD size = 0;
		ULONG nwritten = 0;

		std::wstring ws = mol::towstring(scriptEngine_);
		size = (DWORD)ws.size();

		if ( S_OK == stream->Write( &size, sizeof(DWORD), &nwritten ) )
		{
			if ( S_OK == stream->Write( ws.c_str(), size*sizeof(wchar_t),&nwritten))
			{
				stream->Commit(0);
			}
		}
	}
	return S_OK;
}
    
HRESULT __stdcall UserForm::InitNew(IStorage *pStg) 
{
	setDirty(false);
	return S_OK;
}

/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////



HRESULT __stdcall  UserForm::Close()
{
//	mol::invoke<UserForm,BOOL>( *this, &UserForm::destroy );
	mol::invoke( boost::bind( &UserForm::destroy, this ) );
	/*
	run_on_gui_thread({

		this->destroy();

	});
	*/
	return S_OK;
}

HRESULT __stdcall UserForm::Show()
{
	show(SW_SHOW);
	mol::punk<MSForms::_UserForm> form(oleObject);
	if ( form )
	{
		form->put_ShowToolbox(MSForms::fmModeOn);
	}
	else 
	{
		
	}
	return S_OK;
}

HRESULT __stdcall UserForm::Hide()
{
	show(SW_HIDE);
	mol::punk<MSForms::_UserForm> form(oleObject);
	if ( form )
	{
		form->put_ShowToolbox(MSForms::fmModeOff);
	}
	return S_OK;
}


void UserForm::adviseControls(  )
{
	mol::punk<MSForms::_UserForm> form(oleObject);
	if ( !form )
		return;

	mol::punk<MSForms::Controls> controls;
	if ( S_OK != form->get_Controls(&controls) )
		return;
	if ( !controls )
		return;

	long n = 0;
	if ( S_OK != controls->get_Count(&n) )
		return;

	for ( long i = 0; i < n; i++ )
	{
		mol::punk<IDispatch> disp;
		if ( S_OK != controls->Item(mol::variant(i),&disp) )
			continue;

		mol::punk<MSForms::IControl> c(disp);
		if ( !c )
			continue;

		mol::bstr name;
		if ( (S_OK == c->get_Name(&name)) && name )
		{
			IID iid;
			if ( S_OK == findSourceOnCP(disp,&iid) )
			{
				DWORD cookie;
				mol::com_obj<FormScriptEventHandler>* handler = new mol::com_obj<FormScriptEventHandler>;
				handler->AddRef();

				//TODO: assure only to advis IF script handler present
				// use static factory func pattern
				handler->init(script,iid,name.toString());

				mol::punk<IConnectionPointContainer>	icPc(disp);
				mol::punk<IConnectionPoint>			icP;
				HRESULT hr = icPc->FindConnectionPoint( iid, &icP);
				if( S_OK == hr )
				{
					hr = icP->Advise( handler,&cookie);
				}
				sinks[cookie] = handler;
				disp->AddRef();
				ctrls[cookie] = disp;
				iids[cookie] = iid;
			}
		}
	}	
}

void UserForm::unAdviseControls()
{
	for ( std::map<DWORD,IUnknown*>::iterator it = ctrls.begin(); it != ctrls.end(); it++ )
	{
		mol::punk<IConnectionPointContainer>	icPc((*it).second);
		if ( icPc )
		{
			mol::punk<IConnectionPoint>			icP;

			HRESULT hr = icPc->FindConnectionPoint( iids[ (*it).first ], &icP);
			if( S_OK == hr )
			{
				hr = icP->Unadvise( (*it).first );
			}
			if ( sinks.count( (*it).first ) > 0 )
			{
				sinks[ (*it).first ]->Release();
				(*it).second->Release();
			}
		}
	}
	sinks.clear();
	ctrls.clear();
	disconnectObjects();
}

void UserForm::disconnectObjects()
{
	mol::punk<MSForms::_UserForm> f(oleObject);
	if ( !f )
		return;

	mol::punk<MSForms::Controls> controls;
	if ( S_OK != f->get_Controls(&controls) )
		return;
	if ( !controls )
		return;

	long n = 0;
	if ( S_OK != controls->get_Count(&n) )
		return;

	for ( long i = 0; i < n; i++ )
	{
		mol::punk<IDispatch> disp;
		if ( S_OK == controls->Item(mol::variant(i),&disp) )
		{
			if ( disp )
			{
				::CoDisconnectObject(disp,0);
				disp.release();
			}
		}
	}
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

EventDlg::EventDlg( MSForms::_UserForm* f , const mol::string& engine)
{
	form = f;
	engine_ = engine;
}

void EventDlg::freeTree(HTREEITEM it )
{
	while (HTREEITEM i = tree_.getChildItem(it))
	{
        freeTree(i);
	}
	if ( it != TVI_ROOT )
	{
		IUnknown* unk = (IUnknown*)tree_.getLPARAM(it);
		if ( unk ) 
			unk->Release();
	}
	tree_.deleteNode(it);
}

void EventDlg::freeList( )
{
	for ( int i = 0; i < list_.count(); i++ )
	{
		mol::TCHAR* c = (mol::TCHAR*)list_.getData(i);
		if ( c )
		{
			list_.setData(i,0);
			delete[] c;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////
void EventDlg::populateControlList(HTREEITEM hit)
{
	freeList();
	list_.resetContent();

	IUnknown* unk = (IUnknown*)tree_.getLPARAM(hit);
	if ( !unk )
		return;

	mol::bstr name(L"control");
	mol::punk<MSForms::IControl> ctrl(unk);
	if ( ctrl )
	{		
		ctrl->get_Name(&name);
	}

	IID iid;
	if ( S_OK != mol::findSourceOnCP( unk, &iid ) )
		return;

	mol::punk<ITypeInfo> typInf;
	HRESULT hr = mol::typeInfoForInterface(iid,&typInf);							
	if ( hr != S_OK )
		return;

	TYPEATTR* ta = NULL;
	if ( S_OK != typInf->GetTypeAttr(&ta) && ta )
		return;

	unsigned short int cFuncs = ta->cFuncs;
	for ( unsigned short int j = 0; j < cFuncs; j++ )
	{
		FUNCDESC* funcdesc;
		if ( S_OK != typInf->GetFuncDesc(j,&funcdesc) && funcdesc )
			continue;

		MEMBERID memid = funcdesc->memid;
		unsigned int nNames;
		short int cParams = funcdesc->cParams;

		mol::bstr* bstrs = new mol::bstr[cParams+1];
		if ( S_OK == typInf->GetNames(memid,(BSTR*)bstrs,cParams+1,&nNames) )
		{
			if ( nNames > 0 )
			{
				if ( engine_ == _T("PerlScript") ) {

					mol::ostringstream oss;
					oss << _T("\r\nsub ") << name.toString() << _T("_") << mol::toString(bstrs[0]);

					oss << _T(" {\r\n");

					for ( unsigned short int n = 1; n < nNames; n++ )
					{
						oss << _T("  my $");
						oss << mol::toString(bstrs[n]);
						oss <<  _T(" = shift;\r\n");
					}
					oss << _T("\r\n}\r\n");

					
					list_.addString(mol::toString(bstrs[0]));

					int index = list_.index(mol::toString(bstrs[0]));
					if ( index != -1 )
					{
						mol::string s = oss.str();
						mol::TCHAR* c = new mol::TCHAR[s.size()+1];
						memcpy( c, s.c_str(), (s.size()+1)*sizeof(mol::TCHAR) );
						list_.setData( index, (void*)c );
					}
				}
				if ( engine_ == _T("Javascript") ) {

					mol::ostringstream oss;
					oss << _T("\r\nfunction ") << name.toString() << _T("_") << mol::toString(bstrs[0]) << _T("( ");

					for ( unsigned short int n = 1; n < nNames; n++ )
					{
						oss << mol::toString(bstrs[n]);
						if ( n < ( nNames-1) )
							oss <<  _T(", ");
					}

					oss << _T(")\r\n{\r\n");
					oss << _T("}\r\n");
					list_.addString(mol::toString(bstrs[0]));

					int index = list_.index(mol::toString(bstrs[0]));
					if ( index != -1 )
					{
						mol::string s = oss.str();
						mol::TCHAR* c = new mol::TCHAR[s.size()+1];
						memcpy( c, s.c_str(), (s.size()+1)*sizeof(mol::TCHAR) );
						list_.setData( index, (void*)c );
					}
				}
				if ( engine_ == _T("VBScript") ) {

					mol::ostringstream oss;
					oss << _T("\r\nSub ") << name.toString() << _T("_") << mol::toString(bstrs[0]) << _T("( ");

					for ( unsigned short int n = 1; n < nNames; n++ )
					{
						oss << mol::toString(bstrs[n]);
						if ( n < ( nNames-1) )
							oss <<  _T(", ");
					}

					oss << _T(")\r\n\r\n");
					oss << _T("End Sub\r\n");
					list_.addString(mol::toString(bstrs[0]));

					int index = list_.index(mol::toString(bstrs[0]));
					if ( index != -1 )
					{
						mol::string s = oss.str();
						mol::TCHAR* c = new mol::TCHAR[s.size()+1];
						memcpy( c, s.c_str(), (s.size()+1)*sizeof(mol::TCHAR) );
						list_.setData( index, (void*)c );
					}
				}
			}
		}
		delete[] bstrs;
		typInf->ReleaseFuncDesc(funcdesc);
	}
	typInf->ReleaseTypeAttr(ta);
}

void EventDlg::populateControlTree(IUnknown* ctrl, HTREEITEM hit)
{
	mol::punk<MSForms::_UserForm> f(ctrl);
	if ( !f )
		return;

	mol::punk<MSForms::Controls> controls;
	if ( S_OK != f->get_Controls(&controls) )
		return;
	if ( !controls )
		return;

	long n = 0;
	if ( S_OK != controls->get_Count(&n) )
		return;

	for ( long i = 0; i < n; i++ )
	{
		mol::punk<IDispatch> disp;
		if ( S_OK != controls->Item(mol::variant(i),&disp) )
			continue;
		if ( !disp )
			continue;

		mol::punk<MSForms::IControl> c(disp);
		if ( !c )
			continue;

		mol::bstr name;
		if ( (S_OK == c->get_Name(&name)) && name )
		{
			disp->AddRef();
			tree_.addNodeParam(name.toString(),(LPARAM)(IUnknown*)disp);
		}
	}
}

void EventDlg::copySelectionToClipboard()
{
	int pos = list_.getCurSel();
	mol::TCHAR* handler = (mol::TCHAR*)list_.getData(pos);
	if (!handler)
		return;

	if ( ::OpenClipboard( *this )	)
	{
		::EmptyClipboard();

		std::string s = mol::tostring(handler);
		mol::global glob(s,GMEM_MOVEABLE);
		::SetClipboardData(CF_TEXT,glob);
		glob.detach();

		std::wstring ws = mol::towstring(handler);
		mol::global glob2(ws,GMEM_MOVEABLE);
		::SetClipboardData(CF_UNICODETEXT,glob2);
		glob2.detach();

		::CloseClipboard();
		::PostMessage(moe()->getActive(),WM_COMMAND,IDM_EDIT_PASTE,0);
	}
}

LRESULT EventDlg::wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
    {
		case WM_INITDIALOG:
		{
			tree_.attach(getDlgItem(IDC_TREE_EVENTS));
			list_.attach(getDlgItem(IDC_LIST_EVENTS));
			populateControlTree(form,TVI_ROOT);
			//
			return FALSE; // note: false! look into PSDK!
		}
        case WM_COMMAND:
		{
			if (LOWORD(wParam) == IDOK )
			{
				copySelectionToClipboard();
				return FALSE;
			}
			if (LOWORD(wParam) == IDCANCEL )
			{
				freeList();
				freeTree(TVI_ROOT);
				endDlg(LOWORD(wParam));
				return FALSE;
			}
			if ( (HIWORD(wParam)==LBN_DBLCLK) && (LOWORD(wParam)==IDC_LIST_EVENTS) )
			{
				copySelectionToClipboard();
				return FALSE;				
			}
		}
		case WM_NOTIFY:
		{
			mol::Crack msg(message,wParam,lParam);
			if ( wParam == IDC_TREE_EVENTS )
			if ( msg.nmhdr()->code == NM_CLICK )
			{
				TVHITTESTINFO&	thi = tree_.hitTest();
				if ( thi.hItem )
				{
					tree_.setSelection(thi.hItem);
					populateControlList(thi.hItem);
				}
			}
			if ( wParam == IDC_LIST_EVENTS )
			{

			}
		}
    }
	return mol::win::Dialog::wndProc(hDlg, message, wParam, lParam);
}





//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////



FuncDlg::FuncDlg( MSForms::_UserForm* f, const mol::string& engine )
{
	engine_ = engine;
	form = f;
}

void FuncDlg::freeTree(HTREEITEM it )
{
	while (HTREEITEM i = tree_.getChildItem(it))
	{
        freeTree(i);
	}
	if ( it != TVI_ROOT )
	{
		IUnknown* unk = (IUnknown*)tree_.getLPARAM(it);
		if ( unk ) 
			unk->Release();
	}
	tree_.deleteNode(it);
}


void FuncDlg::freeList( )
{
	for ( int i = 0; i < list_.count(); i++ )
	{
		mol::TCHAR* c = (mol::TCHAR*)list_.getData(i);
		if ( c )
		{
			list_.setData(i,0);
			delete[] c;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////
void FuncDlg::populateControlList(HTREEITEM hit)
{
	freeList();
	list_.resetContent();

	IUnknown* unk = (IUnknown*)tree_.getLPARAM(hit);
	if ( !unk )
		return;

	mol::bstr name(L"control");
	mol::punk<MSForms::IControl> ctrl(unk);
	if ( ctrl )
	{		
		ctrl->get_Name(&name);
		mol::punk<IDispatch> obj;
		if ( S_OK == ctrl->get_Object(&obj) )
		{
			unk = obj;
		}
	}

	mol::punk<IDispatch> d(unk);
	if (!d)
		return;

	mol::punk<ITypeInfo> typInf;
	if ( S_OK == d->GetTypeInfo(0,0,&typInf) )
	{
		addTypeInfo(typInf,name);
	}
}


HRESULT FuncDlg::addTypeInfo(ITypeInfo* typInf, mol::bstr& name )
{
	TYPEATTR* ta = NULL;
	if ( S_OK != typInf->GetTypeAttr(&ta) && ta )
		return E_FAIL;

	if ( ::IsEqualGUID(ta->guid,IID_IDispatch) )
		return S_OK;
	if ( ::IsEqualGUID(ta->guid,IID_IUnknown) )
		return S_OK;

	HREFTYPE reftype;
	if ( S_OK == typInf->GetRefTypeOfImplType(0,&reftype) )
	{
		mol::punk<ITypeInfo> ti;
		if ( S_OK == typInf->GetRefTypeInfo(reftype,&ti) )
		{			
			addTypeInfo(ti,name);

			unsigned short int cFuncs = ta->cFuncs;
			for ( unsigned short int j = 0; j < cFuncs; j++ )
			{
				FUNCDESC* funcdesc;
				if ( S_OK != typInf->GetFuncDesc(j,&funcdesc) && funcdesc )
					continue;

				MEMBERID memid = funcdesc->memid;
				unsigned int nNames;
				short int cParams = funcdesc->cParams;

				mol::bstr* bstrs = new mol::bstr[cParams+1];
				if ( S_OK == typInf->GetNames(memid,(BSTR*)bstrs,cParams+1,&nNames) )
				{
					if ( nNames > 0 )
					{
						mol::string func( mol::toString(bstrs[0]) );						

						if ( 
							 ( func[0] != '_' ) &&
							 ( mol::icmp( func, _T("AddRef")) != 0 ) &&
							 ( mol::icmp( func, _T("Release")) != 0 ) &&
							 ( mol::icmp( func, _T("QueryInterface")) != 0 ) &&
							 ( mol::icmp( func, _T("GetTypeInfoCount")) != 0 ) &&
							 ( mol::icmp( func, _T("GetTypeInfo")) != 0 ) &&
							 ( mol::icmp( func, _T("GetIDsOfNames")) != 0 ) &&
							 ( mol::icmp( func, _T("Invoke")) != 0 ) 
						   )
						{
							if ( engine_ == _T("PerlScript")) {
								if ( funcdesc->invkind & DISPATCH_PROPERTYGET )
								{
									mol::string tmp = _T("my $var = $");
									tmp += name.toString();
									tmp += _T("{");
									tmp += func;
									tmp += _T("};");
									func = tmp;
								}
								else if ( funcdesc->invkind & DISPATCH_PROPERTYPUT )
								{
									mol::string tmp = _T("$");
									tmp += name.toString();
									tmp +=_T("{");
									tmp += func;
									tmp +=_T("} = $var;");
									func = tmp;
								}
								else if ( funcdesc->invkind == DISPATCH_METHOD )
								{
									func = name.toString() + _T(".") + func;
									if ( funcdesc->elemdescFunc.tdesc.vt != VT_VOID)
									{
										func = _T("my $retval = ") + func;
									}
									func += _T("( ");
									for ( unsigned short int n = 1; n < nNames-1; n++ )
									{
										func += _T("$");
										func += mol::toString(bstrs[n]);
										if ( n < nNames-1 )
										{
											func += _T(", ");
										}
									}
									func += _T(" );");
								}
								else 
								{
									continue;
								}
								list_.addString(mol::toString(bstrs[0]));

								int index = list_.index(mol::toString(bstrs[0]));
								if ( index != -1 )
								{
									mol::string s = func;
									mol::TCHAR* c = new mol::TCHAR[s.size()+1];
									memcpy( c, s.c_str(), (s.size()+1)*sizeof(mol::TCHAR) );
									list_.setData( index, (void*)c );
								}
							}
							if ( engine_ == _T("Javascript")) {

								mol::ostringstream oss;
								if ( funcdesc->invkind & DISPATCH_PROPERTYGET )
								{
									oss << _T("\r\nvar value = ");
									oss << name.toString();
									oss << _T(".");
									oss << func;
									oss << _T(";\r\n");
								}
								else if ( funcdesc->invkind & DISPATCH_PROPERTYPUT )
								{
									oss << _T("\r\n");
									oss << name.toString();
									oss << _T(".");
									oss << func;
									oss << _T(" = value;\r\n");
								}
								else if ( funcdesc->invkind == DISPATCH_METHOD )
								{
									if ( funcdesc->elemdescFunc.tdesc.vt != VT_VOID)
									{
										oss << _T("\r\nvar retval = ");
									}
									oss << name << _T(".") << func << _T("( ");
									for ( unsigned short int n = 1; n < nNames-1; n++ )
									{
										func += mol::toString(bstrs[n]);
										if ( n < nNames-1 )
										{
											func += _T(", ");
										}
									}
									func += _T(" );\r\n");
								}
								else 
								{
									continue;
								}
								list_.addString(mol::toString(bstrs[0]));

								int index = list_.index(mol::toString(bstrs[0]));
								if ( index != -1 )
								{
									mol::string s = oss.str();
									mol::TCHAR* c = new mol::TCHAR[s.size()+1];
									memcpy( c, s.c_str(), (s.size()+1)*sizeof(mol::TCHAR) );
									list_.setData( index, (void*)c );
								}
							}
							if ( engine_ == _T("VBScript")) {

								mol::ostringstream oss;
								if ( funcdesc->invkind & DISPATCH_PROPERTYGET )
								{
									oss << _T("\r\nvalue = ");
									oss << name.toString();
									oss << _T(".");
									oss << func;
									oss << _T("\r\n");
								}
								else if ( funcdesc->invkind & DISPATCH_PROPERTYPUT )
								{
									oss << _T("\r\n");
									oss << name.toString();
									oss << _T(".");
									oss << func;
									oss << _T(" = value\r\n");
								}
								else if ( funcdesc->invkind == DISPATCH_METHOD )
								{
									if ( funcdesc->elemdescFunc.tdesc.vt != VT_VOID)
									{
										oss << _T("\r\n retval = ");
									}
									oss << name << _T(".") << func << _T("( ");
									for ( unsigned short int n = 1; n < nNames-1; n++ )
									{
										func += mol::toString(bstrs[n]);
										if ( n < nNames-1 )
										{
											func += _T(", ");
										}
									}
									func += _T(" )\r\n");
								}
								else 
								{
									continue;
								}
								list_.addString(mol::toString(bstrs[0]));

								int index = list_.index(mol::toString(bstrs[0]));
								if ( index != -1 )
								{
									mol::string s = oss.str();
									mol::TCHAR* c = new mol::TCHAR[s.size()+1];
									memcpy( c, s.c_str(), (s.size()+1)*sizeof(mol::TCHAR) );
									list_.setData( index, (void*)c );
								}
							}
						}
					}
				}
				delete[] bstrs;
				typInf->ReleaseFuncDesc(funcdesc);
			}
		}
	}
	typInf->ReleaseTypeAttr(ta);
	return S_OK;
}


void FuncDlg::populateControlTree(IUnknown* ctrl, HTREEITEM hit)
{
	mol::punk<MSForms::_UserForm> f(ctrl);
	if ( !f )
		return;

	mol::punk<MSForms::Controls> controls;
	if ( S_OK != f->get_Controls(&controls) )
		return;

	if ( !controls )
		return;

	long n = 0;
	if ( S_OK != controls->get_Count(&n) )
		return;

	for ( long i = 0; i < n; i++ )
	{
		mol::punk<IDispatch> disp;
		if ( S_OK != controls->Item(mol::variant(i),&disp) )
			continue;
		if ( !disp )
			continue;

		mol::punk<MSForms::IControl> c(disp);
		if ( !c )
			continue;

		mol::bstr name;
		if ( (S_OK == c->get_Name(&name)) && name )
		{
			disp->AddRef();
			tree_.addNodeParam(name.toString(),(LPARAM)(IUnknown*)disp);
		}
	}
}

void FuncDlg::copySelectionToClipboard()
{
	int pos = list_.getCurSel();
	mol::TCHAR* handler = (mol::TCHAR*)list_.getData(pos);
	if (!handler)
		return;

	if ( ::OpenClipboard( *this )	)
	{
		::EmptyClipboard();

		std::string s = mol::tostring(handler);
		mol::global glob(s,GMEM_MOVEABLE);
		::SetClipboardData(CF_TEXT,glob);
		glob.detach();

		std::wstring ws = mol::towstring(handler);
		mol::global glob2(ws,GMEM_MOVEABLE);
		::SetClipboardData(CF_UNICODETEXT,glob2);
		glob2.detach();

		::CloseClipboard();
		::PostMessage(moe()->getActive(),WM_COMMAND,IDM_EDIT_PASTE,0);
	}
}

LRESULT FuncDlg::wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
    {
		case WM_INITDIALOG:
		{
			setText(_T("Members"));
			tree_.attach(getDlgItem(IDC_TREE_EVENTS));
			list_.attach(getDlgItem(IDC_LIST_EVENTS));
			populateControlTree(form,TVI_ROOT);
			//
			return FALSE; // note: false! look into PSDK!
		}
        case WM_COMMAND:
		{
			if (LOWORD(wParam) == IDOK )
			{
				copySelectionToClipboard();
				return FALSE;
			}
			if (LOWORD(wParam) == IDCANCEL )
			{
				freeList();
				freeTree(TVI_ROOT);
				endDlg(LOWORD(wParam));
				return FALSE;
			}
			if ( (HIWORD(wParam)==LBN_DBLCLK) && (LOWORD(wParam)==IDC_LIST_EVENTS) )
			{
				copySelectionToClipboard();
				return FALSE;				
			}
		}
		case WM_NOTIFY:
		{
			mol::Crack msg(message,wParam,lParam);
			if ( wParam == IDC_TREE_EVENTS )
			if ( msg.nmhdr()->code == NM_CLICK )
			{
				TVHITTESTINFO&	thi = tree_.hitTest();
				if ( thi.hItem )
				{
					tree_.setSelection(thi.hItem);
					populateControlList(thi.hItem);
				}
			}
			if ( wParam == IDC_LIST_EVENTS )
			{

			}
		}
    }
	return mol::win::Dialog::wndProc(hDlg, message, wParam, lParam);
}





