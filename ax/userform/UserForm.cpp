#include "StdAfx.h"
#include "UserForm.h"
#include "CtrlWnd.h"
#include "fm20_tlh.h" 

#include "resource.h"

UserForm::UserForm( ) 
	: frame(this)
{
	dirty_ = false;
}

//////////////////////////////////////////////////////////////////////////////

UserForm::~UserForm() 
{
	ODBGS("~UserForm dies");
};


//////////////////////////////////////////////////////////////////////////////
// initialization
//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall UserForm::Load(IDispatch* disp,BSTR fp, VARIANT_BOOL vbDesign)
{
	mol::bstr filepath(fp);
	filename_ = filepath.towstring();

	std::wstring tmp = findFile(filename_);
	if (!tmp.empty()) 
	{
		filename_ = tmp;
	}

	if (mol::Path::isDir(filename_))
		return E_FAIL;


	this->frame.initialize(disp, filename_, vbDesign == VARIANT_TRUE ? true : false);

	return S_OK;
}



HRESULT __stdcall  UserForm::put_Title(BSTR t)
{
	mol::bstr s(t);
	frame.setText(s.towstring());
	return S_OK;
}

HRESULT __stdcall  UserForm::get_Title(BSTR* s)
{
	std::wstring text = frame.getText();
	*s = ::SysAllocString(text.c_str());
	return S_OK;
}

HRESULT __stdcall UserForm::Save(void)
{
	
	HRESULT hr;
	mol::punk<IStorage> dest;
	if (S_OK == ::StgCreateDocfile(filename_.c_str(), STGM_READWRITE | STGM_CREATE | STGM_SHARE_EXCLUSIVE, 0, &dest))
	{
		::WriteClassStg(dest, IID_IMoeUserForm);

		/*
		mol::punk<IStream> stream;
		hr = dest->CreateStream(L"CONTENT", STGM_READWRITE | STGM_CREATE | STGM_SHARE_EXCLUSIVE, 0, 0, &stream);
		if (S_OK == hr)
		{
			std::string s("dummy");
			DWORD size = (DWORD)s.size();
			ULONG nwritten = 0;
			hr = stream->Write(&size, sizeof(DWORD), &nwritten);
			hr = stream->Write(s.c_str(), size, &nwritten);

			size =
				stream->Commit(STGC_DEFAULT);
		}

		hr = dest->Commit(STGC_DEFAULT);
		*/
		hr = Save(dest, FALSE);
	}
	return S_OK;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

HRESULT __stdcall  UserForm::get_Controls( IDispatch **d)
{
	return frame.get_Object(d);
}


HRESULT __stdcall  UserForm::Item(VARIANT idx, IDispatch **d)
{

	mol::punk<IDispatch> disp;
	HRESULT hr = frame.get_Object(&disp);
	if (hr != S_OK) return hr;

	mol::punk<MSForms::_UserForm> form(disp);
	if (!form)
		return S_FALSE;

	mol::punk<MSForms::Controls> controls;
	if (S_OK != form->get_Controls(&controls))
		return S_FALSE;
	if (!controls)
		return S_FALSE;

	if (S_OK == controls->Item(mol::variant(idx), d))
		return S_OK;

	return S_FALSE;
}


HRESULT __stdcall  UserForm::get_Script(  IDispatch **s)
{
	return frame.script.queryInterface(s);//->QueryInterface(IID_IDispatch, (void**)s);
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
		mol::punk<IDispatch> disp;
		frame.get_Object(&disp);
		mol::punk<IPersistStorage> ps(disp);
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

		std::wstring ws = mol::towstring(frame.scriptEngine);
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

HRESULT __stdcall UserForm::get_Top(long* top)
{
	if (top)
	{
		mol::Rect r;
		frame.getWindowRect(r);
		*top = r.top;
	}
	return S_OK;
}

HRESULT __stdcall UserForm::put_Top(long top)
{
	mol::Rect r;
	frame.getWindowRect(r);
	r.bottom = r.bottom + (top - r.top);
	r.top = top;

	frame.move(r.left, r.top, r.right - r.left, r.bottom - r.top);
	return S_OK;
}

HRESULT __stdcall UserForm::get_Left(long* left)
{
	if (left)
	{
		mol::Rect r;
		frame.getWindowRect(r);
		*left = r.left;
	}
	return S_OK;
}

HRESULT __stdcall UserForm::put_Left(long left)
{
	mol::Rect r;
	frame.getWindowRect(r);
	r.right = r.right + (left - r.left);
	r.left = left;
	frame.move(r.left, r.top, r.right - r.left, r.bottom - r.top);
	return S_OK;
}


HRESULT __stdcall UserForm::get_Width(long* width)
{
	if (width)
	{
		mol::Rect r;
		frame.getWindowRect(r);
		*width = r.right - r.left;
	}
	return S_OK;
}

HRESULT __stdcall UserForm::put_Width(long width)
{
	mol::Rect r;
	frame.getWindowRect(r);
	r.right = r.left + width;
	frame.move(r.left, r.top, r.right - r.left, r.bottom - r.top);
	return S_OK;
}

HRESULT __stdcall UserForm::get_Height(long* height)
{
	if (height)
	{
		mol::Rect r;
		frame.getWindowRect(r);
		*height = r.bottom - r.top;
	}
	return S_OK;
}

HRESULT __stdcall UserForm::put_Height(long height)
{
	mol::Rect r;
	frame.getWindowRect(r);
	r.bottom = r.top + height;
	frame.move(r.left, r.top, r.right - r.left, r.bottom - r.top);
	return S_OK;
}



/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////



HRESULT __stdcall  UserForm::Close()
{
	mol::invoke( boost::bind( &FrameWindow::destroy, &frame ) );
	//frame.destroy();
	return S_OK;
}

HRESULT __stdcall UserForm::Show()
{
	frame.show(SW_SHOW);
	mol::punk<IDispatch> disp;
	frame.get_Object(&disp);
	mol::punk<MSForms::_UserForm> form(disp);
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
	frame.show(SW_HIDE);
	mol::punk<IDispatch> disp;
	frame.get_Object(&disp);
	mol::punk<MSForms::_UserForm> form(disp);
	if ( form )
	{
		form->put_ShowToolbox(MSForms::fmModeOff);
	}
	return S_OK;
}




///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

