#include "stdafx.h"
#include "form.h"
#include "app.h"
#include "xmlui.h"
#include "ax/jre/jre_i.c"

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

MoeFormWnd::MoeFormWnd(  )
{
	domain_   = 0;
    eraseBackground_ = 1;
	wndClass().setIcon(moe()->icon); 
	wndClass().hIconSm(moe()->icon); 
}


MoeFormWnd::~MoeFormWnd()
{
	if ( domain_ && compiler_)
	{
//		punk<IUnknown> unk(compiler_);
//		compilerSink_.UnAdvise(unk.interface_);
//		compiler_->Unload(VARIANT_TRUE);
//		delete domain_;
	}

	ODBGS("~MoeFormWnd() dropped dead");
}


MoeFormWnd::Instance* MoeFormWnd::CreateInstance( const mol::string& loc, int left, int top, int width, int height, int style )
{
	mol::string tmp = loc;
	size_t pos = loc.find_first_of( _T("#?"));
	if ( pos != std::string::npos )
		tmp = loc.substr(0,pos);

	mol::string f = findFile(tmp);

	if ( !mol::Path::exists(f) )
		return 0;

	Instance* form = new Instance;
	form->AddRef();

	form->location_ = f;
	form->load( bstr(f).toString(), style, mol::Rect( left, top, width, height)  );

	return form;
}


void MoeFormWnd::load( const mol::string& loc, int s, Rect& r )
{
	mol::string l = loc;

	size_t pos = loc.find_first_of( _T("#?"));
	if ( pos != std::string::npos )
		l = loc.substr(0,pos);

	if ( !mol::Path::exists(l) )
	{
		l = mol::Path::pathname(mol::app<MoeApp>().getModulePath()) + _T("\\");
		l += loc;

		if ( !mol::Path::exists(l) )
		{
			l = mol::Path::pathname(mol::app<MoeApp>().getModulePath()) + _T("\\forms\\") + loc;
			if ( !mol::Path::exists(l) )
				return;
		}
	}

	style_	  = s;

	if ( style_ & MoeFormWnd::STANDALONE )
		create(  0, r ,  (HWND)0 );
	else
		create( 0, r ,  (HWND)(*moe()) );

	show(SW_SHOW);

	if ( pos != std::string::npos )
		l.append(loc.substr(pos));

	setLocation( l );
	advise(htmlSink_);
}


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////



void MoeFormWnd::OnClose()
{
	ODBGS("MoeFormWnd::OnClose");
	unAdvise(htmlSink_);
}

void MoeFormWnd::OnNcDestroy()
{
	ODBGS("MoeFormWnd::OnNcDestroy");
	if ( codeBehind_ )
		codeBehind_.release();

	::CoDisconnectObject(((IExternalMoe*)&external_),0);

	// trigger the missing WM_MDIACTIVATE as we broke MDI handling
	// by showing this form. note we don't call m->activate but
	// post the message directly; this is due the MDI def impl
	// would swallow it in this case :-)
	HWND active = moe()->getActive();
	mol::MdiChild* m = mol::wndFromHWND<mol::MdiChild>(active);
	if ( m )
	{
		::PostMessage( active, WM_MDIACTIVATE, 0,(LPARAM)(HWND)(active));
	}
	
	((IMoeFrame*)this)->Release();

	ODBGS("~MoeFormWnd()OnNcDestroy --");
}

/////////////////////////////////////////////////////////////////////////////////////////////


int MoeFormWnd::style() 
{ 
	static int s = WS_CLIPSIBLINGS|WS_CLIPCHILDREN;

	if ( style_ & MoeFormWnd::TITLE )
		return WS_OVERLAPPEDWINDOW|WS_CLIPSIBLINGS|WS_CLIPCHILDREN; 
	else
		return WS_POPUP|WS_CLIPSIBLINGS|WS_CLIPCHILDREN; 
} 

/////////////////////////////////////////////////////////////////////////////////////////////

DWORD MoeFormWnd::UIflags()						
{
	DWORD d = DOCHOSTUIFLAG_NO3DBORDER;
	if ( style_ & MoeFormWnd::DIALOG )
		d = d | DOCHOSTUIFLAG_DIALOG;
	if ( style_ & MoeFormWnd::NOSCROLL )
		d = d | DOCHOSTUIFLAG_SCROLL_NO;
	
	return d;
}

HRESULT MoeFormWnd::hideContextMenu() 
{ 
	return S_FALSE; 
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
// COM section
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeFormWnd::Eval( BSTR src, BSTR scrptLanguage )
{
	punk<IDispatch> disp;
	if ( S_OK == get_Document(&disp) && disp )
	{
		punk<IHTMLDocument2> doc(disp);

		if (doc )
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
HRESULT __stdcall MoeFormWnd::get_Document( IDispatch** disp)
{
	if (!disp)
		return E_INVALIDARG;
	*disp = 0;
	return this->doc(disp);
}

/////////////////////////////////////////////////////////////////////

HRESULT __stdcall MoeFormWnd::put_Title( BSTR title)
{
	if ( title )
	{
		setText( bstr(title).toString() );
	}
	return S_OK;
}

HRESULT __stdcall MoeFormWnd::get_Title( BSTR* title)
{
	if ( !title )
		return E_INVALIDARG;

	*title = ::SysAllocString( mol::towstring( getText() ).c_str() );
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeFormWnd::Close()
{
	postMessage(WM_CLOSE,0,0);
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeFormWnd::get_Scripts( IDispatch** s)
{
	if (!s)
		return E_INVALIDARG;

	*s = 0;
	
	punk<IDispatch> disp;
	if ( S_OK == get_Document( &disp ) && disp )
	{
		punk<IHTMLDocument2> doc2(disp);
		if ( doc2 )
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
HRESULT __stdcall MoeFormWnd::put_CodeBehind( IDispatch* code)
{
	codeBehind_ = code;
	return S_OK;
}


/////////////////////////////////////////////////////////////////////
HRESULT __stdcall MoeFormWnd::OleCmd( long cmd)
{
	execWb((OLECMDID)cmd);
	return S_OK;
}


HRESULT __stdcall MoeFormWnd::IDocHostUIHandler_GetExternal( IDispatch **ppDispatch)
{
	ODBGS("MoeFormWnd::IDocHostUIHandler_GetExternal");
	return external_.QueryInterface(IID_IDispatch, (void**)ppDispatch);
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
// webbrowser events
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
// external events called from script inside MoeWnd
/////////////////////////////////////////////////////////////////////////////////////////////

MoeFormWnd::ExternalMoe::ExternalMoe()
{
}

MoeFormWnd::ExternalMoe::~ExternalMoe()
{
	ODBGS("ExternalMoe ~");
}

HRESULT __stdcall MoeFormWnd::ExternalMoe::get_Moe(IDispatch** disp)
{
	if ( !disp )
		return E_INVALIDARG;

	HRESULT hr = ((IXmoe*)(moe()))->QueryInterface(IID_IDispatch, (void**)disp );
	if ( hr != S_OK )
		*disp = 0;

	return hr;
}

HRESULT __stdcall MoeFormWnd::ExternalMoe::Close()
{
	ODBGS("MoeFormWnd::ExternalMoe::Close()");
	This()->postMessage(WM_CLOSE,0,0);
	return S_OK;
}

HRESULT __stdcall MoeFormWnd::ExternalMoe::CreateObject( BSTR progId, IDispatch** disp)
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

HRESULT __stdcall MoeFormWnd::ExternalMoe:: get_Frame( IMoeFrame** f)
{
	if (!f) 
		return E_INVALIDARG;
	return ((IMoeFrame*)This())->QueryInterface( IID_IMoeFrame, (void**) f );
}


HRESULT __stdcall MoeFormWnd::ExternalMoe::CodeBehind( BSTR fname )
{
	mol::string p(bstr(fname).toString());
	mol::string l(This()->location_);
	mol::string s = mol::Path::parentDir(l);

	moe()->SetStatus(fname);

	if ( mol::Path::ext(p) == _T(".class") )
	{
		/*
		mol::string classfile = p.substr(0,p.size()-6);
		HRESULT hr = This()->jvm_.createObject(CLSID_JRE,CLSCTX_LOCAL_SERVER);
		if ( hr != S_OK )
			return hr;

		mol::string module = mol::Path::pathname(mol::app<MoeApp>().getModulePath());
		mol::string libpath = module + _T("\\com4j.jar;");
		libpath += module + _T("\\jmoe.jar;");
		libpath += s ;

		hr = This()->jvm_->put_Classpath( mol::bstr(libpath) );
		if ( hr != S_OK )
			return hr;

		hr = This()->jvm_->Extension( mol::bstr(classfile), (IXmoe*)(moe()), (IMoeFrame*)(This()) );
		if ( hr!= S_OK )
			return hr;
*/
		return S_OK;
	} 
	
	if ( !mol::Path::exists(p) )
	{

		s += _T("\\");
		s += p;
		p = s;
		if ( !mol::Path::exists(p) )
			return S_OK;
	}


	mol::string assembly = p;
	size_t pos = 0;
	if (  (pos = assembly.find_last_of(_T("."))) != mol::string::npos )
		assembly = assembly.substr(0,pos);

/*
	This()->domain_ = new Domain();
	This()->domain_->CreateInstance<ICompiler>( _T("JIT"), _T("mol.JIT"), &(This()->compiler_) );

	assembly += _T(".exe");

	This()->compiler_->Start();
	This()->compiler_->put_AssemblyName(bstr(assembly));
	This()->compiler_->AddDirectory(bstr(mol::Path::pathname(p)));
	This()->compiler_->AddSourceFile(bstr(mol::Path::filename(p)));

	This()->compiler_->AddDirectory(bstr(mol::Path::pathname(mol::app<MoeApp>().getModulePath())));
	This()->compiler_->AddReference(bstr(L"System.Web.dll"));
	This()->compiler_->AddReference(bstr(L"moe.dll"));
	This()->compiler_->AddReference(bstr(L"Interop.Moe.dll"));
	This()->compiler_->AddReference(bstr(L"Interop.Scintilla.dll"));
	This()->compiler_->AddReference(bstr(L"Interop.ShellCtrls.dll"));
	This()->compiler_->AddObject(bstr("moe"),variant((IDispatch*)(IXmoe*)(moe())));
	This()->compiler_->AddObject(bstr("frame"),variant((IDispatch*)(IMoeFrame*)(This())));

	punk<IUnknown> unk(This()->compiler_);
	This()->compilerSink_.Advise(unk.interface_);

	This()->compiler_->Run();
		*/
	return S_OK;
}

HRESULT __stdcall MoeFormWnd::ExternalMoe::get_Code( IDispatch** code )
{
	if ( !code )
		return E_INVALIDARG;

	*code = 0;
	if ( ! (This()->codeBehind_) )
		return E_FAIL;

	mol::disp_invoke(This()->codeBehind_,2);

	This()->codeBehind_->AddRef();
	*code = This()->codeBehind_;
	
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// webbrowser events
//////////////////////////////////////////////////////////////////////////////


HRESULT __stdcall MoeFormWnd::MoeFormWnd_htmlSink::BeforeNavigate2(IDispatch* pDisp, VARIANT* URL, VARIANT* Flags, VARIANT* TargetFrameName, VARIANT* PostData, VARIANT* Headers, VARIANT_BOOL* Cancel)
{
	static std::wstring ws(L"moe://close/");
	if ( ws == bstr(URL->bstrVal).towstring() )
	{
		This()->postMessage(WM_CLOSE,0,0);
		*Cancel = VARIANT_TRUE;
	}
	return S_OK;
}

HRESULT __stdcall MoeFormWnd::MoeFormWnd_htmlSink::WindowClosing( VARIANT_BOOL isChildWindow, VARIANT_BOOL* vbCancel )
{
ODBGS("MoeFormWnd::MoeFormWnd_htmlSink::WindowClosing");

	if ( vbCancel )
		*vbCancel = VARIANT_FALSE;

	if ( (isChildWindow == VARIANT_FALSE) )
	{
		This()->codeBehind_.release();
		This()->codeBehind_ = 0;
	}
	return S_OK;
}

HRESULT __stdcall MoeFormWnd::MoeFormWnd_htmlSink::DocumentComplete( IDispatch* pDisp,  VARIANT* URL)
{
	punk<IWebBrowser2> ie(pDisp);
	if (!ie )
		return S_OK;

	punk<IDispatch> docDisp;

	if ( S_OK != ie->get_Document(&docDisp) )
		return S_OK;

	if ( !docDisp )
		return S_OK;

	statusBar()->status(_T("form document complete"));

	punk<IHTMLDocument2> doc(docDisp);
	if ( doc )
	{
		bstr title;
		if ( S_OK == doc->get_title(&title) && title )
		{
			This()->setText( title.toString() );
		}

		punk<IHTMLElement> body;
		if ( S_OK == doc->get_body(&body) && body )
		{
			// check for C# syntax first
			mol::string codebase   =  mol::Path::pathname(This()->location_);
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
			if ( !codebehind.empty() )
			{
/*				statusBar()->status( mol::string(_T("CODEBEHIND: ")) + codebehind );

				mol::string assembly = codebehind;
				size_t pos = 0;
				if (  (pos = assembly.find_last_of(_T("."))) != mol::string::npos )
					assembly = assembly.substr(0,pos);


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
				This()->compiler_->AddObject(bstr("frame"),variant((IDispatch*)(IMoeFrame*)(This())));

				punk<IUnknown> unk(This()->compiler_);
				This()->compilerSink_.Advise(unk.interface_);

				statusBar()->status( mol::string(_T("run CODEBEHIND: ")) + codebehind );

				This()->compiler_->Run();
*/
				return S_OK;
			}

/*
			// check JAVA syntax now
			mol::string classpath  =  mol::Path::pathname(This()->location_);
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
			mol::variant vClassbehind;
			if ( S_OK == body->getAttribute(mol::bstr("CLASSBEHIND"),0,&vClassbehind) )
			{
				if ( vClassbehind.vt == VT_BSTR && vClassbehind.bstrVal != 0 )
				{
					classbehind = vClassbehind.toString();
				}
			}
			if ( !classbehind.empty() )
			{
				statusBar()->status( mol::string(_T("CLASSBEHIND: ")) + codebehind );
				if ( This()->jvm_ )
					This()->jvm_.release();

				HRESULT hr = This()->jvm_.createObject(CLSID_JRE,CLSCTX_LOCAL_SERVER);
				if ( hr != S_OK )
					return hr;

				mol::string module = mol::Path::pathname(mol::app<MoeApp>().getModulePath());
				mol::string libpath = module + _T("\\com4j.jar;");
				libpath += module + _T("\\jmoe.jar;");
				libpath += classpath ;

				hr = This()->jvm_->put_Classpath( mol::bstr(libpath) );
				if ( hr != S_OK )
					return hr;

				statusBar()->status( mol::string(_T("run CLASSBEHIND: ")) + codebehind );

				hr = This()->jvm_->Extension( mol::bstr(classbehind), (IXmoe*)(moe()), (IMoeFrame*)(This()) );
				if ( hr!= S_OK )
					return hr;

				return S_OK;
			}
			*/
		}
	}
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/*
HRESULT __stdcall MoeFormWnd::MoeFormWnd_compilerSink::ErrorMsg(BSTR error)
{
	::MessageBox( *This(),bstr(error).toString().c_str(),_T("error:"),0);
	return S_OK;
}


HRESULT __stdcall MoeFormWnd::MoeFormWnd_compilerSink::Success()
{
	statusBar()->status(_T("JIT success"));
	return S_OK;
}

*/
