#include "stdafx.h"
#include "UserForm.h"
#include "shared.h"
#include "moe.h"
#include "app.h"
#include "form.h"
#include "xmlui.h"

MoeChildView::~MoeChildView()
{
	ODBGS("~MoeChildView dies ...");
}


bool MoeChildView::CreateInstance( mol::MdiChild* wnd, IMoeDocumentView** v )
{
	if (!v)
		return false;

	*v = 0;

	Instance* i = new Instance;
	i->wnd_ = wnd;

	HRESULT hr = i->QueryInterface( IID_IMoeDocumentView, (void**) v);
	if ( S_OK == hr )
		return true;

	*v = 0;
	delete i;
	return false;
}

void MoeChildView::dispose() 
{

}

REFGUID MoeChildView::getCoClassID()
{
	return IID_IMoeDocumentView;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeChildView::get_Top( long* top)
{
	if ( top )
	{
		RECT r;
		wnd_->getWindowRect(r);
		mol::Point p(r.left,r.top);
		::ScreenToClient( wnd_->mdiClient(), &p);
		*top = p.y;
	}
	return S_OK;
}

HRESULT __stdcall MoeChildView::put_Top( long top)
{
	RECT r;
	wnd_->getWindowRect(r);
	int w = r.right-r.left;
	int h = r.bottom-r.top;

	mol::Point p(r.left,r.top);
	::ScreenToClient(wnd_->mdiClient(), &p);

	p.y = top;
	h  += top-p.y;

	wnd_->move(p.x,p.y,w,h);
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeChildView::get_Left( long* left)
{
	if ( left )
	{
		RECT r;
		wnd_->getWindowRect(r);
		mol::Point p(r.left,r.top);
		::ScreenToClient( wnd_->mdiClient(), &p);
		*left = p.x;
	}
	return S_OK;
}

HRESULT __stdcall MoeChildView::put_Left( long left)
{
	RECT r;
	wnd_->getWindowRect(r);
	int w = r.right-r.left;
	int h = r.bottom-r.top;

	mol::Point p(r.left,r.top);
	::ScreenToClient(wnd_->mdiClient(), &p);

	p.x = left;
	w += left-p.x;

	wnd_->move(p.x,p.y,w,h);
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeChildView::get_Width( long* width)
{
	if ( width )
	{
		RECT r;
		wnd_->getWindowRect(r);
		mol::Point p(r.left,r.top);
		*width = r.right -r.left;
	}
	return S_OK;
}

HRESULT __stdcall MoeChildView::put_Width( long width)
{
	RECT r;
	wnd_->getWindowRect(r);
	int w = width;
	int h = r.bottom-r.top;

	mol::Point p(r.left,r.top);
	::ScreenToClient(wnd_->mdiClient(), &p);

	wnd_->move(p.x, p.y, w, h);
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeChildView::get_Height( long* height)
{
	if ( height )
	{
		RECT r;
		wnd_->getWindowRect(r);
		mol::Point p(r.left,r.top);
		*height = r.bottom -r.top;
	}
	return S_OK;
}

HRESULT __stdcall MoeChildView::put_Height( long height)
{
	RECT r;
	wnd_->getWindowRect(r);
	int w = r.right-r.left;
	int h = height;

	mol::Point p(r.left,r.top);
	::ScreenToClient(wnd_->mdiClient(), &p);

	wnd_->move(p.x, p.y, w, h);
	return S_OK;
}

HRESULT __stdcall MoeChildView::Show()
{
	wnd_->show(SW_SHOW);
	return S_OK;
}

HRESULT __stdcall MoeChildView::Hide()
{
	wnd_->show(SW_HIDE);
	return S_OK;
}

HRESULT __stdcall MoeChildView::Close()
{
	wnd_->postMessage(WM_CLOSE,0,0);
	return S_OK;
}

HRESULT __stdcall MoeChildView::Minimize()
{
	wnd_->minimize();
	return S_OK;
}

HRESULT __stdcall MoeChildView::Maximize()
{
	wnd_->maximize();
	return S_OK;
}

HRESULT __stdcall MoeChildView::Restore()
{
	wnd_->restore();
	return S_OK;
}

HRESULT __stdcall MoeChildView::Activate()
{
	moe()->restore();
	wnd_->activate();
	return S_OK;
}

/////////////////////////////////////////////////////////////////////


MoeDialogView::~MoeDialogView()
{
	ODBGS("~MoeDialogView dies ...");
}



void MoeDialogView::dispose() 
{}

REFGUID MoeDialogView::getCoClassID()
{
	return IID_IMoeDialogView;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeDialogView::get_Top( long* top)
{
	if ( top )
	{
		RECT r;
		wnd_->getWindowRect(r);
		*top = r.top;
	}
	return S_OK;
}

HRESULT __stdcall MoeDialogView::put_Top( long top)
{
	RECT r;
	wnd_->getWindowRect(r);
	r.bottom = r.bottom + ( top - r.top );
	r.top = top;

	wnd_->move(r.left,r.top,r.right-r.left,r.bottom-r.top);
	return S_OK;
}
/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeDialogView::get_Left( long* left)
{
	if ( left )
	{
		RECT r;
		wnd_->getWindowRect(r);
		*left = r.left;
	}
	return S_OK;
}

HRESULT __stdcall MoeDialogView::put_Left( long left)
{
	RECT r;
	wnd_->getWindowRect(r);
	r.right = r.right + ( left - r.left );
	r.left = left;
	wnd_->move(r.left,r.top,r.right-r.left,r.bottom-r.top);
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeDialogView::get_Width( long* width)
{
	if ( width )
	{
		RECT r;
		wnd_->getWindowRect(r);
		*width = r.right -r.left;
	}
	return S_OK;
}

HRESULT __stdcall MoeDialogView::put_Width( long width)
{
	RECT r;
	wnd_->getWindowRect(r);
	r.right = r.left + width;
	wnd_->move(r.left,r.top,r.right-r.left,r.bottom-r.top);
	return S_OK;
}
/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeDialogView::get_Height( long* height)
{
	if ( height )
	{
		RECT r;
		wnd_->getWindowRect(r);
		*height = r.bottom -r.top;
	}
	return S_OK;
}

HRESULT __stdcall MoeDialogView::put_Height( long height)
{
	RECT r;
	wnd_->getWindowRect(r);
	r.bottom = r.top + height;
	wnd_->move(r.left,r.top,r.right-r.left,r.bottom-r.top);
	return S_OK;
}


HRESULT __stdcall MoeDialogView::Show()
{
	wnd_->show(SW_SHOW);
	return S_OK;
}

HRESULT __stdcall MoeDialogView::Hide()
{
	wnd_->show(SW_HIDE);
	return S_OK;
}

HRESULT __stdcall MoeDialogView::Close()
{
	wnd_->postMessage(WM_CLOSE,0,0);
	return S_OK;
}

HRESULT __stdcall MoeDialogView::get_Title( BSTR* title )
{
	if ( !title )
		return E_INVALIDARG;

	mol::string t = wnd_->getText();
	*title = ::SysAllocString( mol::towstring(t).c_str() );
	return S_OK;
}


HRESULT __stdcall MoeDialogView::put_Title( BSTR title )
{
	if ( !title )
		return S_FALSE;

	wnd_->setText( mol::bstr(title).toString() );
	return S_OK;
}


/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


MoeView::~MoeView()
{
	ODBGS("~MoeView dies ...");
}


void MoeView::dispose() 
{}

REFGUID MoeView::getCoClassID()
{
	return IID_IMoeView;
}

HRESULT __stdcall MoeView::get_Top( long* top)
{
	if ( top )
	{
		RECT r;
		moe()->getWindowRect(r);
		*top = r.top;
	}
	return S_OK;
}

HRESULT __stdcall MoeView::put_Top( long top)
{
	RECT r;
	moe()->getWindowRect(r);
	r.bottom = r.bottom + ( top - r.top );
	r.top = top;

	moe()->move(r.left,r.top,r.right-r.left,r.bottom-r.top);
	return S_OK;
}
/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeView::get_Left( long* left)
{
	if ( left )
	{
		RECT r;
		moe()->getWindowRect(r);
		*left = r.left;
	}
	return S_OK;
}

HRESULT __stdcall MoeView::put_Left( long left)
{
	RECT r;
	moe()->getWindowRect(r);
	r.right = r.right + ( left - r.left );
	r.left = left;
	moe()->move(r.left,r.top,r.right-r.left,r.bottom-r.top);
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeView::get_Width( long* width)
{
	if ( width )
	{
		RECT r;
		moe()->getWindowRect(r);
		*width = r.right -r.left;
	}
	return S_OK;
}

HRESULT __stdcall MoeView::put_Width( long width)
{
	RECT r;
	moe()->getWindowRect(r);
	r.right = r.left + width;
	moe()->move(r.left,r.top,r.right-r.left,r.bottom-r.top);
	return S_OK;
}
/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeView::get_Height( long* height)
{
	if ( height )
	{
		RECT r;
		moe()->getWindowRect(r);
		*height = r.bottom -r.top;
	}
	return S_OK;
}

HRESULT __stdcall MoeView::put_Height( long height)
{
	RECT r;
	moe()->getWindowRect(r);
	r.bottom = r.top + height;
	moe()->move(r.left,r.top,r.right-r.left,r.bottom-r.top);
	return S_OK;
}


HRESULT __stdcall MoeView::Show()
{
	moe()->show(SW_SHOW);
	::SetForegroundWindow(*moe());
	return S_OK;
}

HRESULT __stdcall MoeView::Hide()
{
	moe()->show(SW_HIDE);
	return S_OK;
}

HRESULT __stdcall MoeView::Minimize()
{
	moe()->minimize();
	return S_OK;
}

HRESULT __stdcall  MoeView::Maximize()
{
	moe()->maximize();
	return S_OK;
}

HRESULT __stdcall MoeView::Restore()
{
	moe()->restore();
	return S_OK;
}

HRESULT __stdcall MoeView::Tile()
{
	moe()->OnTileHorizontal(0,0,0);
	return S_OK;
}

HRESULT __stdcall MoeView::Cascade()
{
	moe()->OnCascade(0,0,0);
	return S_OK;
}

HRESULT __stdcall MoeView::get_ShowTreeView( VARIANT_BOOL* vb )
{
	if ( vb )
	{
		if ( treeWnd()->isVisible() )
			*vb = VARIANT_TRUE;
		else
			*vb = VARIANT_FALSE;
	}
	return S_OK;
}


HRESULT __stdcall MoeView::put_ShowTreeView( VARIANT_BOOL vb )
{
	if ( vb == VARIANT_TRUE )
	{
		treeWnd()->show(SW_SHOW);
		::InvalidateRect(moe()->mdiClient(),0,TRUE);
		statusBar()->status(_T("Tree view visible"));
	}
	if ( vb == VARIANT_FALSE )
	{
		treeWnd()->show(SW_HIDE);
		statusBar()->status(_T("Tree view hidden"));
	}

	moe()->OnLayout(0,0,0);
	return S_OK;
}

void MoeView::fullScreen(HWND hwnd)
{
	DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);

	if (dwStyle & WS_OVERLAPPEDWINDOW) 
	{
		MONITORINFO mi = { sizeof(mi) };

		if ( GetWindowPlacement(hwnd, &wpPrev_) &&
			 GetMonitorInfo(MonitorFromWindow(hwnd,
					   MONITOR_DEFAULTTOPRIMARY), &mi)) 
		{
			  SetWindowLong(hwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
			  SetWindowPos(hwnd, HWND_TOP,
					   mi.rcMonitor.left, mi.rcMonitor.top,
					   mi.rcMonitor.right - mi.rcMonitor.left,
					   mi.rcMonitor.bottom - mi.rcMonitor.top,
					   SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
		}
	} 
	else 
	{
		SetWindowLong(hwnd, GWL_STYLE,
					  dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(hwnd, &wpPrev_);
		SetWindowPos(hwnd, NULL, 0, 0, 0, 0,
					 SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
					 SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
	}
}

HRESULT __stdcall MoeView::put_Fullscreen( VARIANT_BOOL vb )
{
	//TODO: toggle vs set ????
	fullScreen( *moe() );
	return S_OK;
}

HRESULT __stdcall MoeView::get_Fullscreen( VARIANT_BOOL* vb )
{
	if (!vb)
		return E_INVALIDARG;

	//TODO : FIX dummy
	*vb = VARIANT_TRUE;//fullscreen( *moe());// ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

HRESULT __stdcall MoeView::get_TreeView( IDispatch** tv)
{
	if (!tv)
		return E_INVALIDARG;

	*tv = 0;

	if ( treeWnd()  )
	{
		return treeWnd()->oleObject.queryInterface(IID_IDispatch,(void**)tv);
	}
	return S_OK;
}


/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


MoeDialogs::~MoeDialogs()
{
	ODBGS("~MoeDialogs dies ...");
}

void MoeDialogs::dispose() 
{}

REFGUID MoeDialogs::getCoClassID()
{
	return IID_IMoeDialogs;
}

HRESULT __stdcall MoeDialogs::MsgBox( BSTR text, BSTR title, long flags, long* result)
{
	((IMoe*)moe())->AddRef();
	mol::string txt = text  ? mol::toString(text)  : _T("");
	mol::string ttl = title ? mol::toString(title) : _T("");

	long res = ::MessageBox(*moe(),txt.c_str(),ttl.c_str(),flags);
	if ( result )
		*result = res;
	((IMoe*)moe())->Release();
	return S_OK;
}

HRESULT __stdcall MoeDialogs::Open(IMoeDocument** d)
{
	
	static mol::TCHAR  InFilesFilter[] = _T("open text files *.*\0*.*\0open UTF-8 text files *.*\0*.*\0open HTML files *.*\0*.*\0open file in hexviewer *.*\0*.*\0\0");

	mol::FilenameDlg ofn(*moe());
	ofn.setFilter( InFilesFilter );			

	if ( ofn.dlgOpen( OFN_NOVALIDATE | OFN_ALLOWMULTISELECT | OFN_EXPLORER ) )
	{
		// open html
		if ( ofn.index() == 3 )
		{
			for ( int i = 0; i < ofn.selections(); i++ )
			{
				ODBGS(ofn.fileName(i).c_str());
				bool result = docs()->open( 0, ofn.fileName(i), Docs::PREF_HTML,ofn.readOnly(), 0);
				if (!result)
				{
					::MessageBox(*moe(),ofn.fileName(i).c_str(),_T("failed to load"),MB_ICONERROR);
				}
				statusBar()->status(ofn.fileName(i));
			}
		}
		// open hex
		else if ( ofn.index() == 4 )
		{
			for ( int i = 0; i < ofn.selections(); i++ )
			{
				bool result = docs()->open( 0, ofn.fileName(i), Docs::PREF_HEX, ofn.readOnly(), 0);
				if (!result)
				{
					::MessageBox(*moe(),ofn.fileName(i).c_str(),_T("failed to load"),MB_ICONERROR);
				}
				statusBar()->status(ofn.fileName(i));
			}
		}
		// open text
		else
		{
			for ( int i = 0; i < ofn.selections(); i++ )
			{
				bool result = docs()->open( 0, ofn.fileName(i), ofn.index() == 2 ? Docs::PREF_UTF8 : Docs::PREF_TXT, ofn.readOnly(), 0);

				ODBGS1("OPEN FILE RESULT: [[[ ",(int)result);
				if (!result)
				{
					statusBar()->status(ofn.fileName(i) + _T(" failed to load") );
					//::MessageBox(*this,ofn.fileName(i).c_str(),_T("failed to load"),MB_ICONERROR);
					return E_FAIL;
				}
				statusBar()->status(ofn.fileName(i));
			}
		}
	}	
	return S_OK;
}

HRESULT __stdcall MoeDialogs::OpenDir( IMoeDocument** d)
{
	mol::bstr dir;
	if ( S_OK == ChooseDir(&dir) && dir)
	{
		mol::string s = dir.toString();
		if ( s != _T("") )
		{
			if ( mol::Path::exists(s) )
				docs()->open( 0, s, Docs::PREF_TXT, false, d);
		}

	}
	return S_OK;
}


HRESULT __stdcall MoeDialogs::ChooseFile( BSTR* f )
{
	if (!f)
		return E_INVALIDARG;

	*f = 0;

	mol::FilenameDlg ofn(*moe());
	if ( ofn.dlgOpen( OFN_NOVALIDATE | OFN_EXPLORER ) )
	{
		mol::string fn = ofn.fileName();
		*f = ::SysAllocString( mol::towstring(fn).c_str() );
	}
	return S_OK;
}

HRESULT __stdcall MoeDialogs::ChooseDir( BSTR* d )	
{
	if (!d)
		return E_INVALIDARG;

	*d = 0;

	mol::string dir = mol::io::browseForFolder( *moe() );
	if ( !dir.empty() )
	{
		*d = ::SysAllocString( mol::towstring(dir).c_str() );
	}
	return S_OK;
}

HRESULT __stdcall MoeDialogs::Help()
{
	moe()->postMessage( WM_COMMAND, IDM_HELP_ABOUT, 0 );
	return S_OK;
}

HRESULT __stdcall MoeDialogs::Print()
{
	::PostMessage( moe()->getActive(), WM_COMMAND, IDM_FILE_PRINT, 0 );
	return S_OK;
}



MoeScript::~MoeScript()
{
	ODBGS("~MoeScript dies ...");
}


void MoeScript::dispose() 
{}

REFGUID MoeScript::getCoClassID()
{
	return IID_IMoeScript;
}

HRESULT __stdcall MoeScript::Run( BSTR f, BSTR engine )
{
	statusBar()->status(mol::bstr(f).toString());
	mol::string s = findFile(mol::bstr(f).toString());
	if ( s == _T("") )
		return E_FAIL;

	mol::filestream fi;
	if ( fi.open( mol::tostring(s), GENERIC_READ ) )
	{
		std::string txt = fi.readAll();
		fi.close();
		return Eval(mol::bstr(txt),engine);
	}
	return S_OK;
}

HRESULT __stdcall MoeScript::Eval( BSTR scrpt, BSTR scrptLanguage)
{
	if ( !scrpt || !scrptLanguage )
		return E_INVALIDARG;

	statusBar()->status( mol::string( _T("evaluating ")) + mol::bstr(scrptLanguage).toString() );

	mol::string e = mol::bstr(scrptLanguage).toString();
	if ( e == _T("cs") )
	{
//		return evalute_csharp(scrpt);
	}

	scriptlet()->eval( mol::toString(scrptLanguage),mol::toString(scrpt) );
	return S_OK;
}

HRESULT __stdcall MoeScript::Debug( BSTR scrpt, BSTR scrptLanguage)
{
	if ( !scrpt || !scrptLanguage )
		return E_INVALIDARG;

	statusBar()->status( mol::string( _T("evaluating ")) + mol::bstr(scrptLanguage).toString() );

	mol::string e = mol::bstr(scrptLanguage).toString();
	if ( e == _T("cs") )
	{
//		return evalute_csharp(scrpt);
	}

	scriptlet()->debug( mol::toString(scrptLanguage),mol::toString(scrpt) );
	return S_OK;
}

HRESULT __stdcall MoeScript::CreateObjectAdmin( BSTR progid, IDispatch** disp)
{
	if (!disp )
		return E_INVALIDARG;

	*disp = 0;

	if ( !progid )
		return E_INVALIDARG;

	mol::punk<IUnknown> unk;
	HRESULT hr = mol::CreateObjectAdmin( *moe(), progid, &unk );
	if ( hr != S_OK )
		return hr;

	return unk->QueryInterface( IID_IDispatch, (void**)disp );
}

HRESULT __stdcall MoeScript::ShowHtmlForm( BSTR src, long l, int t, int w, int h, int formStyle )
{
	statusBar()->status(mol::bstr(src).toString());

	typedef mol::com_obj<MoeFormWnd> form;
	form* f = MoeFormWnd::CreateInstance( 
							mol::bstr(src).toString(),
							l,t,w,h, 
							formStyle 
						);
	return S_OK;
}


HRESULT __stdcall MoeScript::ShowUserForm( BSTR pathname, IMoeUserForm** form )
{
	if ( form )
		*form = 0;

	UserForm::Instance* userForm = UserForm::CreateInstance( mol::bstr(pathname).toString(), false );
	if ( !userForm )
		return E_FAIL;

	if ( !form )
		return S_OK;

	HRESULT hr = userForm->QueryInterface( IID_IDispatch, (void**)form );
	return hr;
}

HRESULT __stdcall MoeScript::DebugUserForm(  BSTR pathname, IMoeUserForm** form )
{
	// TODO - really use debug mode !
	if ( form )
		*form = 0;

	UserForm::Instance* userForm = UserForm::CreateInstance( mol::bstr(pathname).toString(), false );
	if ( !userForm )
		return E_FAIL;

	if ( !form )
		return S_OK;

	HRESULT hr = userForm->QueryInterface( IID_IDispatch, (void**)form );
	return hr;
}

HRESULT __stdcall MoeScript::System( BSTR f)
{
	statusBar()->status(bstr(f).toString());
	mol::string s = findFile(bstr(f).toString());
	if ( s == _T("") )
		return E_FAIL;

	mol::io::exec_cmdline( s );
	return S_OK;
}



MoeConfig::MoeConfig()
{
	systype_			= SCINTILLA_SYSTYPE_WIN32;
	encoding_			= SCINTILLA_ENCODING_ANSI;
	tabwidth_			= 4;
	tabUsage_			= VARIANT_TRUE;
	tabIndents_			= VARIANT_TRUE;
	backSpaceUnIndents_	= VARIANT_FALSE;
	fullScreen_			= VARIANT_FALSE;
}

MoeConfig::~MoeConfig()
{
	ODBGS("~MoeConfig dies ...");
}


void MoeConfig::dispose() 
{}

REFGUID MoeConfig::getCoClassID()
{
	return IID_IMoeConfig;
}

HRESULT __stdcall MoeConfig::get_ConfigPath( BSTR* fPath)
{
	if ( !fPath ) 
		return E_POINTER;
	mol::string tmp( mol::Path::parentDir(mol::App().getAppPath()));
	*fPath = ::SysAllocString(mol::towstring(tmp).c_str());
	return S_OK;
}

HRESULT __stdcall MoeConfig::get_ModulePath(  BSTR* fPath) 
{
	if ( !fPath ) 
		return E_POINTER;
	mol::string tmp( mol::Path::parentDir(mol::App().getModulePath()));
	*fPath = ::SysAllocString(mol::towstring(tmp).c_str());
	return S_OK;
}

HRESULT __stdcall MoeConfig::put_SysType( long typ)
{
	systype_ = typ;

	if ( typ == 0 )
		statusBar()->status(_T("new sysmode: UNIX"));	
	else
		statusBar()->status(_T("new sysmode: Windows"));
	return S_OK;
}

HRESULT __stdcall MoeConfig::get_SysType( long* typ)
{
	if ( typ )
		*typ = systype_;
	return S_OK;
}

HRESULT __stdcall MoeConfig::put_Encoding( long enc)
{
	encoding_ = enc;
	switch ( enc )
	{
		case SCINTILLA_ENCODING_ANSI :
		{
			statusBar()->status(_T("new encoding: ANSI"));	
			break;
		}
		case SCINTILLA_ENCODING_UTF8 :
		{
			statusBar()->status(_T("new encoding: UTF8"));	
			break;
		}
		case SCINTILLA_ENCODING_UTF16 :
		{
			statusBar()->status(_T("new encoding: UTF16"));	
			break;
		}
	}
	return S_OK;
}

HRESULT __stdcall MoeConfig::get_Encoding( long* enc)
{
	if ( enc )
		*enc = encoding_;
	return S_OK;
}

HRESULT __stdcall MoeConfig::put_TabUsage( VARIANT_BOOL vbTabUsage)
{
	tabUsage_ = vbTabUsage;
	if ( vbTabUsage == VARIANT_TRUE )
		statusBar()->status(_T("use tabs"));	
	else
		statusBar()->status(_T("convert tabs to spaces"));
	return S_OK;
}

HRESULT __stdcall MoeConfig::get_TabUsage( VARIANT_BOOL* vbTabUsage)
{
	if ( vbTabUsage )
		*vbTabUsage = tabUsage_;
	return S_OK;
}

HRESULT __stdcall MoeConfig::put_TabIndents( VARIANT_BOOL vbTabIndents)
{
	tabIndents_ = vbTabIndents;
	if ( vbTabIndents == VARIANT_TRUE )
		statusBar()->status(_T("tab indents"));	
	else
		statusBar()->status(_T("tab doesn't indent"));
	return S_OK;
}

HRESULT __stdcall MoeConfig::get_TabIndents( VARIANT_BOOL* vbTabIndents)
{
	if ( vbTabIndents )
		*vbTabIndents = tabIndents_;
	return S_OK;
}

HRESULT __stdcall MoeConfig::put_BackSpaceUnindents( VARIANT_BOOL vbBackSpaceIndents)
{
	backSpaceUnIndents_ = vbBackSpaceIndents;
	if ( vbBackSpaceIndents == VARIANT_TRUE )
		statusBar()->status(_T("backspace unindents"));	
	else
		statusBar()->status(_T("backspace doesn't unindent"));
	return S_OK;
}

HRESULT __stdcall MoeConfig::get_BackSpaceUnindents(  VARIANT_BOOL* vbBackSpaceIndents)
{
	if ( vbBackSpaceIndents )
		*vbBackSpaceIndents = backSpaceUnIndents_;
	return S_OK;
}

HRESULT __stdcall MoeConfig::put_TabWidth( long width)
{
	tabwidth_ = width;
	return S_OK;
}

HRESULT __stdcall MoeConfig::get_TabWidth(  long* width)
{
	if ( width )
	{
		*width = tabwidth_;
	}
	return S_OK;
}

HRESULT __stdcall MoeConfig::EditPreferences( )
{
	statusBar()->status(_T("edit preferences for new documents"));
	mol::string p( mol::app<MoeApp>().getModulePath() );
	mol::string prefs = mol::Path::parentDir(p) + _T("\\forms\\prefs.html");

	long left, top;
	moe()->moeView->get_Left(&left);
	moe()->moeView->get_Top(&top);

	moe()->moeScript->ShowHtmlForm( bstr(prefs) ,left+225,top+225,450,190,6);
	
	return S_OK;
}	

HRESULT __stdcall MoeConfig::EditSettings( )
{
	statusBar()->status(_T("edit user settings"));

	LPUNKNOWN punks[] = { config() };
	CLSID pages[]     = { CLSID_SettingProperties };
	::OleCreatePropertyFrame(*moe(),100,100,L"Moe",1,punks,1,pages,0,0,0);

	return S_OK;
}


HRESULT __stdcall MoeConfig::ExportSettings( BSTR f )
{
	if ( f )
	{
		config()->Save(f);
		statusBar()->status(_T("exported custom user settings"));
	}	
	return S_OK;
}

HRESULT __stdcall MoeConfig::ImportSettings( BSTR f )
{
	if ( f )
	{
		config()->Load(f);
		statusBar()->status(_T("imported custom user settings"));
	}	
	return S_OK;
}

HRESULT __stdcall MoeConfig::InitializeEditorFromPreferences( IMoeDocument* d )
{
	if (!d )
		return E_INVALIDARG;

	long type = 0;
	HRESULT hr = d->get_Type(&type);
	if ( hr != S_OK )
		return hr;

	if ( ! (type == MOE_DOCTYPE_DOC || type == MOE_DOCTYPE_FORM ) )
	{
		return E_FAIL;
	}

	mol::punk<IDispatch> disp;

	hr = d->get_Object(&disp);
	if ( hr != S_OK )
		return hr;

	mol::punk<IScintillAx> sci(disp);

	if (!sci )
		return E_FAIL;

	hr = sci->put_SysType(systype_);
	if ( hr != S_OK )
		return hr;

	hr = sci->put_Encoding(encoding_);
	if ( hr != S_OK )
		return hr;

	hr = sci->put_TabWidth(tabwidth_);
	if ( hr != S_OK )
		return hr;

	hr = sci->put_TabUsage(tabUsage_);
	if ( hr != S_OK )
		return hr;

	hr = sci->put_TabIndents(tabIndents_);
	if ( hr != S_OK )
		return hr;

	hr = sci->put_BackSpaceUnindents(backSpaceUnIndents_);
	if ( hr != S_OK )
		return hr;

	return S_OK;
}


