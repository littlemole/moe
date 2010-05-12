#include "stdafx.h"
#include "html.h"
#include "app.h"
#include "xmlui.h"
#include "ole/Rib.h"
#include "MoeBar.h"

MoeHtmlWnd::MoeHtmlWnd( )
{
	domain_   = 0;
    eraseBackground_ = 1;
	wndClass().setIcon(moe()->icon); 
	wndClass().hIconSm(moe()->icon); 
}

MoeHtmlWnd::~MoeHtmlWnd()
{
	ODBGS("~MoeHtmlWnd dead");

	if ( domain_ && compiler_)
	{
//		punk<IUnknown> unk(compiler_);
//		compilerSink_.UnAdvise(unk.interface_);
//		compiler_->Unload(VARIANT_TRUE);
//		delete domain_;
	}
}

MoeHtmlWnd::Instance* MoeHtmlWnd::CreateInstance( const mol::string& loc)
{
	statusBar()->status(20);

	Instance* form = new Instance;
	form->AddRef();

	if (!form->load( bstr(loc).toString() ))
	{
		form->destroy();
		form->Release();
		return 0;
	}

	form->maximize();

	mol::string tmp = loc;
	size_t pos = 0;
	while ( (pos = tmp.find( _T("\\"), pos)) != std::string::npos ) 
	{
		tmp.replace(pos,1,_T("/"));
	}

	if ( (tmp.substr(0,4) != _T("file")) &&
		 (tmp.substr(0,4) != _T("http"))    )
	{
		tmp = _T("file://") + tmp;
	}

	form->frame_.Release();
	::SetFocus(*form);	
    return form;
}

void MoeHtmlWnd::OnMDIActivate( HWND activated )
{
	if ( mol::Ribbon::ribbon()->enabled())
	{
		tab()->select( location );
		statusBar()->status( location );
		mol::Ribbon::ribbon()->maximize();
		Ribbon::ribbon()->mode(5);
	}
}

/////////////////////////////////////////////////////////////////////
// COM section
/////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeHtmlWnd::get_Filename( BSTR* filename)
{
	if ( filename )
	{
		if ( !location.empty() )
			*filename = ansi2BSTR(mol::tostring(location));
	}
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeHtmlWnd::get_Path( BSTR* p)
{			
	if ( p )
	{
		*p = 0;
		if ( !location.empty() )
		{
			mol::string dir = mol::Path::pathname(location);
			*p = ansi2BSTR(mol::tostring(dir));
		}
	}
	return S_OK;
}

/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeHtmlWnd::get_Type(  long* type)
{
	if ( type )
	{
		*type = XMOE_DOCTYPE_HTML;
	}
	return S_OK;
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  MoeHtmlWnd::Close()
{
	destroy();
	return S_OK;
}


HRESULT __stdcall  MoeHtmlWnd::Activate()
{
	activate();
	return S_OK;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

MoeHtmlWnd::MoeFrame::MoeFrame(  )
{
}


MoeHtmlWnd::MoeFrame::~MoeFrame()
{

    ODBGS("~MoeHtmlWnd::MoeFrame() dropped dead");
}


/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeHtmlWnd::MoeFrame::get_Top( long* top)
{
	return This()->get_Top(top);
}

HRESULT __stdcall MoeHtmlWnd::MoeFrame::put_Top( long top)
{
	return This()->put_Top(top);
}
/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeHtmlWnd::MoeFrame::get_Left( long* left)
{
	return This()->get_Left(left);
}

HRESULT __stdcall MoeHtmlWnd::MoeFrame::put_Left( long left)
{
	return This()->put_Left(left);
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeHtmlWnd::MoeFrame::get_Width( long* width)
{
	return This()->get_Width(width);
}

HRESULT __stdcall MoeHtmlWnd::MoeFrame::put_Width( long width)
{
	return This()->put_Width(width);
}
/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeHtmlWnd::MoeFrame::get_Height( long* height)
{
	return This()->get_Height(height);
}

HRESULT __stdcall MoeHtmlWnd::MoeFrame::put_Height( long height)
{
	return This()->put_Height(height);
}
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeHtmlWnd::MoeFrame::Eval( BSTR src, BSTR scrptLanguage )
{
	punk<IDispatch> disp;
	
	if ( S_OK == get_Document(&disp) && disp )
	{
		punk<IHTMLDocument2> doc(disp);
		if ( doc )
		{
			punk<IHTMLWindow2> window;
			if ( S_OK == doc->get_parentWindow(&window) && window )
			{
				variant var;
				return window->execScript( src, scrptLanguage, &var );
			}
		}
	}
	return E_FAIL;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeHtmlWnd::MoeFrame::get_Document( IDispatch** disp)
{
	if (!disp)
		return E_INVALIDARG;

	*disp = 0;
	return This()->doc(disp);
}


/////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeHtmlWnd::MoeFrame::put_Title( BSTR title)
{
	if ( title )
	{
		This()->setText( bstr(title).toString() );
	}
	return S_OK;
}

HRESULT __stdcall MoeHtmlWnd::MoeFrame::get_Title( BSTR* title)
{
	if ( !title )
		return E_INVALIDARG;

	*title = ::SysAllocString( mol::towstring( This()->getText() ).c_str() );
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeHtmlWnd::MoeFrame::Close()
{
	This()->postMessage(WM_CLOSE,0,0);
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeHtmlWnd::MoeFrame::get_Scripts( IDispatch** s)
{
	if (!s)
		return E_INVALIDARG;

	*s = 0;
	punk<IDispatch> disp;
	
	if ( S_OK == get_Document( &disp ) && disp )
	{
		punk<IHTMLDocument2> doc2(disp);
		if ( doc2)
		{
			punk<IHTMLDocument> doc(doc2);
			if ( doc )
			{
				return doc->get_Script(s);
			}
		}
	}
	return E_FAIL;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeHtmlWnd::MoeFrame::put_CodeBehind( IDispatch* code)
{
	This()->codeBehind_ = code;
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeHtmlWnd::MoeFrame::OleCmd( long cmd)
{
	This()->execWb((OLECMDID)cmd);
	return S_OK;
}



/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////







/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

bool MoeHtmlWnd::load( const mol::string& loc )
{
	location = loc;
	mol::string l = loc;
	mol::string d = _T("");

	size_t pos = loc.find_first_of( _T("#?") );

	if ( pos != std::string::npos )
	{
		l = loc.substr(0,pos);
		d = loc.substr(pos);
	}

	pos = 0;
	while ( (pos = l.find( _T("/"), pos)) != std::string::npos ) 
	{
		l.replace(pos,1, _T("\\") );
	}

	if ( (l.substr(0,4) != _T("file")) &&
		 (l.substr(0,4) != _T("http"))    )
	{
		if ( !mol::Path::exists(l) )
		{
			l = mol::Path::pathname(mol::app<MoeApp>().getModulePath()) + _T("\\");
			l += loc;

			if ( !mol::Path::exists(l) )
			{
				l = mol::Path::pathname(mol::app<MoeApp>().getModulePath()) + _T("\\forms\\") + loc;
				if ( !mol::Path::exists(l) )
					return false;
			}
		}
		l = _T("file://") + l;
	}

	pos = 0;
	while ( (pos = l.find(_T("\\"),pos)) != std::string::npos ) 
	{
		l.replace(pos,1,_T("/"));
	}

	statusBar()->status(30);

	// determine window menu

	windowMenu_ = mol::UI().SubMenu( IDM_MOE_HTML, IDM_VIEW_WINDOWS );
	create( loc.c_str(), (HMENU)mol::UI().Menu(IDM_MOE_HTML), mol::stdRect ,  *moe() );//hWnd() );
	statusBar()->status(40);

	show(SW_SHOW);
	setLocation( l + d );

	advise(htmlSink);

	statusBar()->status(50);

	return true;
}


void MoeHtmlWnd::OnClose()
{
	ODBGS("MoeHtmlWndImpl::OnClose");
}

void MoeHtmlWnd::OnDestroy()
{
	ODBGS("MoeHtmlWndImpl::OnDestroy");

	mol::bstr filename;
	if ( S_OK == get_Filename(&filename) )
	{
		mol::variant v(filename);
		docs()->Remove(v);
	}

	if ( codeBehind_ )
		codeBehind_.release();

	::CoDisconnectObject(((IDispatch*)codeBehind_),0);
	::CoDisconnectObject(((IExternalMoe*)&external_),0);

	unAdvise(htmlSink);
}

void MoeHtmlWnd::OnNcDestroy()
{
	ODBGS("MoeHtmlWndImpl::OnNcDestroy");
	((IDoc*)this)->Release();
}

void MoeHtmlWnd::OnSearch(FINDREPLACE* fi)
{
	find(fi->lpstrFindWhat,fi->Flags);
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

DWORD MoeHtmlWnd::UIflags()						
{
	DWORD d = 0;
	return d;
}

HRESULT MoeHtmlWnd::hideContextMenu() 
{ 
	return S_FALSE; 
}

HRESULT __stdcall MoeHtmlWnd::IDocHostUIHandler_GetExternal( IDispatch **ppDispatch)
{
	return external_.QueryInterface(IID_IDispatch, (void**)ppDispatch);
}

/////////////////////////////////////////////////////////////////////////////////////////////
// webbrowser events
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
// external events called from script inside MoeWnd
/////////////////////////////////////////////////////////////////////////////////////////////

MoeHtmlWnd::ExternalMoe::ExternalMoe()
{}

MoeHtmlWnd::ExternalMoe::~ExternalMoe()
{
	ODBGS("ExternalMoe ~");
}

HRESULT __stdcall MoeHtmlWnd::ExternalMoe::get_Moe(IDispatch** disp)
{
	if ( !disp )
		return E_INVALIDARG;

	HRESULT hr = ((IXmoe*)(moe()))->QueryInterface(IID_IDispatch, (void**)disp );
	if ( hr != S_OK )
		*disp = 0;

	return hr;
}

HRESULT __stdcall MoeHtmlWnd::ExternalMoe::Close()
{
	This()->postMessage(WM_CLOSE,0,0);
	return S_OK;
}

HRESULT __stdcall MoeHtmlWnd::ExternalMoe::CreateObject( BSTR progId, IDispatch** disp)
{
	if (!disp) 
		return E_INVALIDARG;

	*disp = 0;
	CLSID clsid;

	if ( S_OK == ::CLSIDFromProgID( progId, &clsid ) )
	{
		if ( S_OK == ::CoCreateInstance( clsid, NULL, CLSCTX_INPROC|CLSCTX_LOCAL_SERVER, IID_IDispatch, (void**) disp ) )
			return S_OK;
	}
	return E_FAIL;
}

HRESULT __stdcall MoeHtmlWnd::ExternalMoe:: get_Frame( IMoeFrame** f)
{
	if (!f) 
		return E_INVALIDARG;
	return ((IMoeFrame*)This())->QueryInterface( IID_IMoeFrame, (void**) f );
}


HRESULT __stdcall MoeHtmlWnd::ExternalMoe::CodeBehind( BSTR fname )
{
/*	This()->domain_ = new Domain();
	This()->domain_->CreateInstance<ICompiler>( _T("JIT"), _T("mol.JIT"), &(This()->compiler_) );

	mol::string p(bstr(fname).toString());
	if ( !mol::Path::exists(p) )
	{
		mol::string l = This()->location;
		mol::string s = mol::Path::parentDir(l);
		s += _T("\\");
		s += p;
		p = s;
		if ( !mol::Path::exists(p) )
			return S_OK;
	}

	statusBar()->status( mol::string( _T("codebehind ") + p) );

	mol::string an = p;
	size_t pos = 0;
	if (  (pos = an.find_last_of(_T("."))) != mol::string::npos )
		an = an.substr(0,pos);
	an += _T(".exe");

	This()->compiler_->Start();
	This()->compiler_->put_AssemblyName(bstr(an));
	This()->compiler_->AddSourceFile(bstr(mol::Path::filename(p)));

	This()->compiler_->AddDirectory(bstr(mol::Path::pathname(mol::app<MoeApp>().getModulePath())));
	This()->compiler_->AddReference(bstr(L"System.Web.dll"));
	This()->compiler_->AddReference(bstr(L"moe.dll"));
	This()->compiler_->AddReference(bstr(L"Interop.Moe.dll"));
	This()->compiler_->AddReference(bstr(L"Interop.Scintilla.dll"));
	This()->compiler_->AddReference(bstr(L"Interop.ShellCtrls.dll"));
	This()->compiler_->AddObject(bstr("moe"),variant((IDispatch*)(IXmoe*)(moe())));

	mol::punk<IDispatch> disp((IDispatch*)(IMoeFrame*)(&(This()->frame_)));
	mol::variant v(disp);
	This()->compiler_->AddObject(bstr("frame"),v);
	
	punk<IUnknown> unk(This()->compiler_);
	This()->compilerSink_.Advise(unk.interface_);

	statusBar()->status( mol::string( _T("CODEBEHIND run ")) + p );

	This()->compiler_->Run();
		*/
	return S_OK;
}

HRESULT __stdcall MoeHtmlWnd::ExternalMoe::get_Code( IDispatch** code )
{
	if ( !code )
		return E_INVALIDARG;

	*code = 0;
	if ( ! (This()->codeBehind_) )
		return E_FAIL;

	return This()->codeBehind_->QueryInterface( IID_IDispatch, (void**)code );
}

//////////////////////////////////////////////////////////////////////////////
// webbrowser events
//////////////////////////////////////////////////////////////////////////////


HRESULT __stdcall MoeHtmlWnd::MoeHtmlWnd_htmlSink::BeforeNavigate2(IDispatch* pDisp, VARIANT* URL, VARIANT* Flags, VARIANT* TargetFrameName, VARIANT* PostData, VARIANT* Headers, VARIANT_BOOL* Cancel)
{
	static std::wstring ws(L"moe://close/");
	if ( ws == bstr(URL->bstrVal).towstring() )
	{
		This()->postMessage(WM_CLOSE,0,0);
		*Cancel = VARIANT_TRUE;
	}

	return S_OK;
}


HRESULT __stdcall MoeHtmlWnd::MoeHtmlWnd_htmlSink::WindowClosing( VARIANT_BOOL isChildWindow, VARIANT_BOOL* vbCancel )
{
	if ( vbCancel )
		*vbCancel = VARIANT_FALSE;

	if ( (isChildWindow == VARIANT_FALSE) && This()->codeBehind_ )
	{
		This()->codeBehind_->Release();
		This()->codeBehind_ = 0;
	}
	return S_OK;
}

HRESULT __stdcall MoeHtmlWnd::MoeHtmlWnd_htmlSink::DocumentComplete( IDispatch* pDisp,  VARIANT* URL)
{
	statusBar()->status(60);

	punk<IWebBrowser2> ie(pDisp);
	if (!ie )
	{
		statusBar()->status(_T(""));	
		return S_OK;
	}

	punk<IDispatch> docDisp;

	if ( S_OK != ie->get_Document(&docDisp) )
	{
		statusBar()->status(_T(""));	
		return S_OK;
	}

	if ( !docDisp )
	{
		statusBar()->status(_T(""));	
		return S_OK;
	}

	punk<IHTMLDocument2> doc(docDisp);
	if ( doc )
	{
		bstr title;
		if ( S_OK == doc->get_title(&title) && title )
		{
			This()->setText( title.toString() );
		}

		statusBar()->status(70);

		punk<IHTMLElement> body;
		if ( S_OK == doc->get_body(&body) && body )
		{
			// check for C# syntax first
			mol::string codebase   =  mol::Path::pathname(This()->location);
			mol::string codebehind = _T(""); 

			mol::variant vCodebase;
			if ( S_OK == body->getAttribute( mol::bstr("CODEBASE"),0,&vCodebase) )
			{
				if ( vCodebase.vt == VT_BSTR && vCodebase.bstrVal != 0 )
				{
					mol::string p = vCodebase.toString();
					if (!mol::Path::exists(p))
					{
						p = codebase + _T("\\") + p;
					}
					if ( mol::Path::exists(p) )
						codebase = p;
				}
			}
			mol::variant vCodebehind;
			if ( S_OK == body->getAttribute(mol::bstr("CODEBEHIND"),0,&vCodebehind) )
			{
				if ( vCodebehind.vt == VT_BSTR && vCodebehind.bstrVal != 0 )
				{
					codebehind = vCodebehind.toString();
				}
			}
			statusBar()->status(80);

			if ( !codebehind.empty() )
			{
				mol::string assembly = codebehind;
				size_t pos = 0;
				if (  (pos = assembly.find_last_of(_T("."))) != mol::string::npos )
					assembly = assembly.substr(0,pos);
/*

				This()->domain_ = new Domain();
				This()->domain_->CreateInstance<ICompiler>( _T("JIT"), _T("mol.JIT"), &(This()->compiler_) );

				assembly += _T(".exe");

				This()->compiler_->Start();
				This()->compiler_->put_AssemblyName(bstr(assembly));
				This()->compiler_->AddDirectory(bstr(codebase));
				This()->compiler_->AddSourceFile(bstr(codebehind));

				This()->compiler_->AddDirectory(bstr(mol::Path::pathname(mol::app<MoeApp>().getModulePath())));
				This()->compiler_->AddReference(bstr(L"System.Web.dll"));
				This()->compiler_->AddReference(bstr(L"moe.dll"));
				This()->compiler_->AddReference(bstr(L"Interop.Moe.dll"));
				This()->compiler_->AddReference(bstr(L"Interop.Scintilla.dll"));
				This()->compiler_->AddReference(bstr(L"Interop.ShellCtrls.dll"));
				This()->compiler_->AddObject(bstr("moe"),variant((IDispatch*)(IXmoe*)(moe())));
				This()->compiler_->AddObject(bstr("frame"),variant((IDispatch*)(IMoeFrame*)&(This()->frame_)));

				punk<IUnknown> unk(This()->compiler_);
				This()->compilerSink_.Advise(unk.interface_);

				statusBar()->status(90);

				This()->compiler_->Run();

				statusBar()->status(100);

				statusBar()->status(_T(""));	
				*/
				return S_OK;
			}

/*
			// check JAVA syntax now
			mol::string classpath  =  mol::Path::pathname(This()->location);
			mol::string classbehind = _T(""); 

			mol::variant vClasspath;
			if ( S_OK == body->getAttribute( mol::bstr("CLASSPATH"),0,&vClasspath) )
			{
				if ( vClasspath.vt == VT_BSTR && vClasspath.bstrVal != 0 )
				{
					mol::string p = vClasspath.toString();
					if (!mol::Path::exists(p))
					{
						p = classpath + _T("\\") + p;
					}
					if ( mol::Path::exists(p) )
						classpath = p;
						
				}
			}
			statusBar()->status(80);

			mol::variant vClassbehind;
			if ( S_OK == body->getAttribute(mol::bstr("CLASSBEHIND"),0,&vClassbehind) )
			{
				if ( vClassbehind.vt == VT_BSTR && vClassbehind.bstrVal != 0 )
				{
					classbehind = vClassbehind.toString();
				}
			}
			statusBar()->status(90);	

			if ( !classbehind.empty() )
			{
				if ( This()->jvm_ )
					This()->jvm_.release();

				HRESULT hr = This()->jvm_.createObject(CLSID_JRE,CLSCTX_LOCAL_SERVER);
				if ( hr != S_OK )
				{
					statusBar()->status(_T(""));	
					return hr;
				}

				mol::string module = mol::Path::pathname(mol::app<MoeApp>().getModulePath());
				mol::string libpath = module + _T("\\com4j.jar;");
				libpath += module + _T("\\jmoe.jar;");
				libpath += classpath ;

				hr = This()->jvm_->put_Classpath( mol::bstr(libpath) );
				if ( hr != S_OK )
				{
					statusBar()->status(_T(""));	
					return hr;
				}

				statusBar()->status(80);

				hr = This()->jvm_->Extension( mol::bstr(classbehind), (IXmoe*)(moe()), (IMoeFrame*)&(This()->frame_) );

				statusBar()->status(100);

				statusBar()->status(_T(""));	
				if ( hr!= S_OK )
				{
					return hr;
				}

				return S_OK;
			}
*/
		}
	}
	
	statusBar()->status(100);

	mol::punk<IOleCommandTarget> oct(This()->oleObject);
	if ( oct)
	{
		oct->Exec(0,OLECMDID_HIDETOOLBARS,1,0,0);
	}
	statusBar()->status(_T(""));	
	return S_OK;
}

/*
HRESULT __stdcall MoeHtmlWnd::MoeHtmlWnd_compilerSink::ErrorMsg(BSTR error)
{
	::MessageBox( *This(),bstr(error).toString().c_str(),_T("error:"),0);
	return S_OK;
}


HRESULT __stdcall MoeHtmlWnd::MoeHtmlWnd_compilerSink::Success()
{
	statusBar()->status( _T("jit successfull"));
	return S_OK;
}

*/