#include "stdafx.h"
#include "UserForm.h"
#include "shared.h"
#include "tree.h"
#include "moe.h"
#include "app.h"
#include "form.h"
#include "xmlui.h"
#include "moe_dispid.h"

/////////////////////////////////////////////////////////////////////
//
//  moe child dialog view sub obj
//
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
//
// moe view sub obj
//
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
	if ( moe()->isIconic() )
	{
		moe()->restore();
	}
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
	}
	if ( vb == VARIANT_FALSE )
	{
		treeWnd()->show(SW_HIDE);
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
		return treeWnd()->oleObject.queryInterface(tv);
	}
	return S_OK;
}


/////////////////////////////////////////////////////////////////////
//
// moe dialogs sub obj
//
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


HRESULT __stdcall MoeDialogs::Open(BSTR path,IMoeDocument** d)
{

	static mol::TCHAR  InFilesFilter[] = _T("open text files *.*\0*.*\0open HTML files *.*\0*.*\0open rtf files *.*\0*.rtf\0open file in hexviewer *.*\0*.*\0tail log file *.*\0*.*\0\0");

	if ( mol::Ribbon::ribbon()->enabled() )
	{
		const mol::v7::COMDLG_FILTERSPEC c_rgSaveTypes[] =
		{
			{ L"open text files",       L"*.*"},
			{ L"open HTML files",	    L"*.*"},
			{ L"open RTF  files",	    L"*.*"},
			{ L"hexviewer",			    L"*.*"},
			{ L"tail logfile",          L"*.*"}
		};

		MoeVistaFileDialog fd(*moe());
		fd.setFilter((mol::v7::COMDLG_FILTERSPEC*)&c_rgSaveTypes,ARRAYSIZE(c_rgSaveTypes));
		if ( path )
		{
			std::wstring p = mol::towstring(path);
			if ( !p.empty())
			{
				fd.path(p);
			}
		}
		HRESULT hr = fd.open(mol::v7::FOS_ALLOWMULTISELECT  | mol::v7::FOS_NOVALIDATE | mol::v7::FOS_ALLNONSTORAGEITEMS);
		if ( hr != S_OK )
			return hr;

		MOE_DOCTYPE docType = index2type(fd.type());
		std::vector<std::wstring> paths = fd.paths();
		for ( size_t i = 0; i < paths.size(); i++)
		{
			bool result = docs()->open( paths[i], docType,fd.encoding(),fd.readOnly(), d);
		}

		return S_OK;
	}

	//mol::FilenameDlg ofn(*moe());
	MolFileFialog ofn(*moe());
	ofn.setFilter( InFilesFilter );			
	if ( path )
	{
		mol::string p = mol::toString(path);
		ofn.fileName(p);
	}

	if ( ofn.dlgOpen( OFN_NOVALIDATE | OFN_ALLOWMULTISELECT | OFN_EXPLORER  | OFN_NOTESTFILECREATE | OFN_ENABLEHOOK | OFN_ENABLETEMPLATE ) )
	{
		// open rtf
		if ( ofn.index() == 3 )
		{
			for ( int i = 0; i < ofn.selections(); i++ )
			{
				ODBGS(ofn.fileName(i).c_str());
				bool result = docs()->open( ofn.fileName(i), MOE_DOCTYPE_RTF,-1,ofn.readOnly(), 0);
			}
		}
		// open html
		else if ( ofn.index() == 2 )
		{
			for ( int i = 0; i < ofn.selections(); i++ )
			{
				ODBGS(ofn.fileName(i).c_str());
				bool result = docs()->open( ofn.fileName(i), MOE_DOCTYPE_HTML,-1,ofn.readOnly(), 0);
			}
		}
		// open hex
		else if ( ofn.index() == 4 )
		{
			for ( int i = 0; i < ofn.selections(); i++ )
			{
				bool result = docs()->open( ofn.fileName(i), MOE_DOCTYPE_HEX,-1, ofn.readOnly(), 0);
			}
		}
		// open log
		else if ( ofn.index() == 5 )
		{
			for ( int i = 0; i < ofn.selections(); i++ )
			{
				bool result = docs()->open( ofn.fileName(i), MOE_DOCTYPE_TAIL,-1, TRUE, 0);
			}
		}
		// open text
		else
		{
			for ( int i = 0; i < ofn.selections(); i++ )
			{
				bool result = docs()->open(ofn.fileName(i),MOE_DOCTYPE_DOC, ofn.codePage(), ofn.readOnly(), 0);
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
			//if ( mol::Path::exists(s) )
				docs()->open( s, MOE_DOCTYPE_DIR,-1, false, d);
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
	if ( ofn.dlgOpen( OFN_NOVALIDATE | OFN_EXPLORER | OFN_NOTESTFILECREATE ) )
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

/////////////////////////////////////////////////////////////////////
//
// moe script sub obj
//
/////////////////////////////////////////////////////////////////////

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

	mol::string e = mol::bstr(scrptLanguage).toString();
	if ( e == _T("cs") )
	{
//		return evalute_csharp(scrpt);
	}

	scriptlet()->eval( mol::toString(scrptLanguage),mol::toString(scrpt),0 );
	return S_OK;
}

HRESULT __stdcall MoeScript::Debug( BSTR scrpt, BSTR scrptLanguage)
{
	if ( !scrpt || !scrptLanguage )
		return E_INVALIDARG;

	mol::string e = mol::bstr(scrptLanguage).toString();
	if ( e == _T("cs") )
	{
//		return evalute_csharp(scrpt);
	}

	scriptlet()->debug( mol::toString(scrptLanguage),mol::toString(scrpt),0 );
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

HRESULT __stdcall MoeScript::Picture( BSTR f, IDispatch** disp )
{
	if ( !disp ) 
		return E_INVALIDARG;
	*disp = 0;

	mol::Picture pic;
	HRESULT hr = pic.load( mol::toString(f) );
	if ( hr != S_OK )
		return S_OK;

	mol::punk<IPictureDisp> p;
	hr = pic.copy(&p);
	if ( hr != S_OK )
		return S_OK;

	return p.queryInterface(disp);
}

/////////////////////////////////////////////////////////////////////
//
// moe config sub obj
//
/////////////////////////////////////////////////////////////////////

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

HRESULT __stdcall MoeConfig::put_ShowLineNumbers( VARIANT_BOOL vb)
{
	showLineNumbers_ = vb;
	return S_OK;
}

HRESULT __stdcall MoeConfig::get_ShowLineNumbers(  VARIANT_BOOL* vb)
{
	if ( vb )
	{
		*vb = showLineNumbers_;
	}
	return S_OK;
}

HRESULT __stdcall  MoeConfig::get_Settings( IDispatch** settings)
{
	return config()->QueryInterface(IID_IDispatch,(void**)settings);
}


HRESULT __stdcall MoeConfig::EditPreferences( )
{
	PropSheet ps( *moe(), _T("Moe"));

	ps.addPage<TabPage>		(	_T("new doc prefs"), IDD_DIALOG_TAB );
	ps.addPage<ExportPage>	(	_T("export/import"), IDD_DIALOG_EXPORT );
	ps.addPage<PrefPage>	(	_T("user settings"), CLSID_SettingProperties, IDD_DIALOG_SETWRAPPER );

	INT_PTR r = ps.create( );

	// use custom html dialog for settings:

	//mol::string p( mol::app<MoeApp>().getModulePath() );
	//mol::string prefs = mol::Path::parentDir(p) + _T("\\forms\\prefs.html");

	//long left, top;
	//moe()->moeView->get_Left(&left);
	//moe()->moeView->get_Top(&top);

	//moe()->moeScript->ShowHtmlForm( bstr(prefs) ,left+225,top+225,450,217,6);
	
	return S_OK;
}	

HRESULT __stdcall MoeConfig::EditSettings( )
{
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
	}	
	return S_OK;
}

HRESULT __stdcall MoeConfig::ImportSettings( BSTR f )
{
	if ( f )
	{
		config()->Load(f);
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

	mol::punk<IScintillAxProperties> props;
	sci->get_Properties(&props);

	props->put_StyleSets(styles());

	hr = props->put_SysType(systype_);
	if ( hr != S_OK )
		return hr;

	hr = props->put_Encoding(encoding_);
	if ( hr != S_OK )
		return hr;

	hr = props->put_TabWidth(tabwidth_);
	if ( hr != S_OK )
		return hr;

	hr = props->put_TabUsage(tabUsage_);
	if ( hr != S_OK )
		return hr;

	hr = props->put_TabIndents(tabIndents_);
	if ( hr != S_OK )
		return hr;

	hr = props->put_BackSpaceUnindents(backSpaceUnIndents_);
	if ( hr != S_OK )
		return hr;

	hr = props->put_ShowLineNumbers(showLineNumbers_);
	if ( hr != S_OK )
		return hr;

	// use ribbon context menue if avail
	if ( mol::Ribbon::ribbon()->enabled() )
	{
		hr = props->put_UseContext(VARIANT_FALSE);
		if ( hr != S_OK )
			return hr;
	}

	props->put_Syntax(SCINTILLA_SYNTAX_PLAIN);

	return S_OK;
}


HRESULT  __stdcall MoeConfig::get_StyleSets( IDispatch** s)
{
	if (!s)
		return E_INVALIDARG;

	return styles()->QueryInterface(IID_IDispatch,(void**)s);
}


HRESULT  __stdcall MoeConfig::ResetStyles()
{
	mol::punk<IPersistStreamInit> psi(styles());
	if(psi)
		psi->InitNew();
	return S_OK;
}

void MoeConfig::setDirty(bool b)
{

}

bool MoeConfig::isDirty()
{
	return false;
}

/////////////////////////////////////////////////////////////////////
// config persistence
/////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeConfig::Load( LPSTREAM pStm)
{
	pStm >> mol::property( mol::DispId(this,DISPID_IMOECONFIG_SYSTYPE, VT_I4) )
		 >> mol::property( mol::DispId(this,DISPID_IMOECONFIG_ENCODING, VT_I4) )
		 >> mol::property( mol::DispId(this,DISPID_IMOECONFIG_TABUSAGE,VT_BOOL) )
		 >> mol::property( mol::DispId(this,DISPID_IMOECONFIG_TABINDENTS,VT_BOOL) )
		 >> mol::property( mol::DispId(this,DISPID_IMOECONFIG_BACKSPACEUNINDENTS,VT_BOOL) )
		 >> mol::property( mol::DispId(this,DISPID_IMOECONFIG_TABWIDTH, VT_I4) )
		 >> mol::property( mol::DispId(this,DISPID_IMOECONFIG_SHOWLINENUMBERS,VT_BOOL) );

	return S_OK;
}

HRESULT __stdcall MoeConfig::Save( LPSTREAM pStm,BOOL fClearDirty)
{
	pStm << mol::property( mol::DispId(this,DISPID_IMOECONFIG_SYSTYPE, VT_I4) )
		 << mol::property( mol::DispId(this,DISPID_IMOECONFIG_ENCODING, VT_I4) )
		 << mol::property( mol::DispId(this,DISPID_IMOECONFIG_TABUSAGE,VT_BOOL) )
		 << mol::property( mol::DispId(this,DISPID_IMOECONFIG_TABINDENTS,VT_BOOL) )
		 << mol::property( mol::DispId(this,DISPID_IMOECONFIG_BACKSPACEUNINDENTS,VT_BOOL) )
		 << mol::property( mol::DispId(this,DISPID_IMOECONFIG_TABWIDTH, VT_I4) )
		 << mol::property( mol::DispId(this,DISPID_IMOECONFIG_SHOWLINENUMBERS,VT_BOOL) );


	return S_OK;
}


std::string now()
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );

  strftime (buffer,80,"%Y-%m-%d %H:%M:%S",timeinfo);
  return std::string(buffer);
}


///////////////////////////////////////////////////////////////


Log::Log()
{
	logLevel_ = LOGINFO;
//	mol::string path = appPath() + _T("\\moe.log");
//	fs_.open( mol::tostring(path), GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS );
}

Log::~Log()
{
	
}

void Log::write(const std::string& str)
{
	for ( auto it = appenders_.begin(); it != appenders_.end(); it++)
	{
		(*it)->write(str);
	}
}

void Log::level( LogLevel l)
{
	logLevel_ = l;
}

LogLevel Log::level()
{
	return logLevel_;
}

void Log::add( Appender* a)
{
	appenders_.push_back( appender(a) );
}

Logger Log::getLogger(LogLevel level)
{
	return Logger(level);
}

Log& log()
{
	return mol::singleton<Log>();
}

///////////////////////////////////////////////////////////////

Logger::Logger(LogLevel level)
	: logLevel_(level)
{
   oss_ << now() << " [" << level << "] : ";
}

Logger::~Logger()
{
   if (logLevel_ >= log().level())
   {
	   log().write(oss_.str());
   }
}

Logger logger(LogLevel level)
{
	return log().getLogger(level);
}


//	mol::string path = appPath() + _T("\\moe.log");

///////////////////////////////////////////////////////////////

FileAppender::FileAppender(const std::string& path)
{
	fs_.open( mol::tostring(path), GENERIC_WRITE, FILE_SHARE_WRITE|FILE_SHARE_READ, NULL, CREATE_ALWAYS );
}

FileAppender::~FileAppender()
{
	fs_.close();
}

void FileAppender::write(const std::string& str)
{
	fs_ << str << std::endl;
	fs_.flush();
}



void DebugAppender::write(const std::string& str)
{
	ODBGS(str);
}