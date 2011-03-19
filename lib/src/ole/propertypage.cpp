#include "ole/propertypage.h"

namespace mol {
namespace ole {

///////////////////////////////////////////////////////////
// Property Page Impl
///////////////////////////////////////////////////////////

PropertyPageBase::PropertyPageBase()
{
	bDirty_ = FALSE;
	size_.cx = size_.cy = 0;
	title_  = _T("p.r.o.p.e.r.t.i.e.s.");
}

PropertyPageBase::~PropertyPageBase()
{
	for ( unsigned int i = 0; i < objects_.size(); i++ )
	{
		objects_[i]->Release();
	}
	objects_.clear();
}

HRESULT __stdcall PropertyPageBase::SetPageSite( IPropertyPageSite *pPageSite) 
{
	pageSite_ = pPageSite;
	return S_OK;
}

HRESULT __stdcall PropertyPageBase::Activate( HWND hWndParent,LPCRECT pRect,BOOL bModal) 
{
	return S_OK;
}

HRESULT __stdcall PropertyPageBase::Deactivate( void) 
{
	//destroy();
	return S_OK;
}

HRESULT __stdcall PropertyPageBase::GetPageInfo( PROPPAGEINFO *pPageInfo)
{
	std::wstring ws = mol::towstring(title_);

	pPageInfo->pszTitle = (OLECHAR*)::CoTaskMemAlloc( (ws.size()+1)*sizeof(wchar_t));
	wcsncpy( pPageInfo->pszTitle, ws.c_str(), ws.size()+1 );

	pPageInfo->size          = size_;
	pPageInfo->pszHelpFile   = 0;
	pPageInfo->pszDocString  = 0;
	pPageInfo->dwHelpContext = 0;

	return S_OK;
}

HRESULT __stdcall PropertyPageBase::SetObjects( ULONG cObjects,IUnknown **ppUnk)
{
	for ( ULONG u = 0; u < cObjects; u++ )
	{
		ppUnk[u]->AddRef();
		objects_.push_back(ppUnk[u]);
	}
	return S_OK;
}

HRESULT __stdcall PropertyPageBase::Show( UINT nCmdShow)
{
	//show(nCmdShow);
	return S_OK;
}

HRESULT __stdcall PropertyPageBase::Move( LPCRECT pRect)
{
	//move(*pRect);
	return S_OK;
}

HRESULT __stdcall PropertyPageBase::IsPageDirty( void)
{
	if ( bDirty_ )
		return S_OK;
	return S_FALSE;
}

HRESULT __stdcall PropertyPageBase::Apply( void)
{
	return S_OK;
}

HRESULT __stdcall PropertyPageBase::Help( LPCOLESTR pszHelpDir)
{
	pszHelpDir = 0;
	return S_OK;
}

HRESULT __stdcall PropertyPageBase::TranslateAccelerator( MSG *pMsg)
{
	return E_NOTIMPL;
}

void PropertyPageBase::setDirty()
{
	bDirty_ = TRUE;
	if ( pageSite_ )
		pageSite_->OnStatusChange(PROPPAGESTATUS_DIRTY);
}

//////////////////////////////////////////////////////////////////////////////////////////////


OlePropPage::OlePropPage()
{
	deleteOnNCDestroy_ = true;
}


void OlePropPage::create( mol::PropSheet* ps, const mol::string& tab, REFCLSID clsid, int id,int flags )
{
	mol::win::PropPage::create(ps,tab,id,flags);

	prop_.createObject(clsid);
	
}
void OlePropPage::init()
{
	prop_->SetPageSite(&propertyPageSite_);
	RECT r;
	::GetClientRect( *this,&r );

	this->setObjects();

	prop_->Activate( *this, &r, TRUE );
	prop_->Show(SW_SHOW);

}

void OlePropPage::setObjects()
{
}

int OlePropPage::apply()
{
	prop_->Apply();
	return PSNRET_NOERROR;
}

void OlePropPage::reset()
{
	prop_->Deactivate();
	prop_->SetObjects(0,0);
	prop_.release();
	ODBGS(_T("OlePropPage::reset()"));
}


int  OlePropPage::translateAccel( LPMSG msg)
{
	if ( prop_ )
	{
		HRESULT hr = prop_->TranslateAcceleratorW(msg);
		if ( hr == S_OK )
			return PSNRET_MESSAGEHANDLED;
	}
	return PSNRET_NOERROR ;
}

HRESULT STDMETHODCALLTYPE OlePropPage::PropertyPageSite::OnStatusChange( DWORD dwFlags)
{
	if ( dwFlags == PROPPAGESTATUS_DIRTY )
	{
		HWND hwnd = (HWND)*(This());
		PropSheet_Changed( ::GetParent(hwnd), hwnd );
	}

	if ( dwFlags == PROPPAGESTATUS_VALIDATE )
	{
		This()->apply();
	}
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE OlePropPage::PropertyPageSite::GetLocaleID( LCID *pLocaleID)
{
	return LOCALE_USER_DEFAULT;
}
        
HRESULT STDMETHODCALLTYPE OlePropPage::PropertyPageSite::GetPageContainer( IUnknown **ppUnk)
{
	return E_NOTIMPL;
}
        
HRESULT STDMETHODCALLTYPE OlePropPage::PropertyPageSite::TranslateAccelerator( MSG* pMsg)
{
	return E_NOTIMPL;
}


} // end namespace mol::win::ole
} // end namespace mol