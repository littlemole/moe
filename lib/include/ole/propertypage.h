#ifndef MOL_PROPERTY_PAGE_DEF_GUARD_
#define MOL_PROPERTY_PAGE_DEF_GUARD_

#pragma once
#include "util/uni.h"
#include "win/pp.h"
#include "ole/com.h"
#include "ole/punk.h"
#include "ole/obj.h"
#include <ocidl.h>

namespace mol {
namespace ole {

///////////////////////////////////////////////////////////
// Property Page Support
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// Property Page Impl
///////////////////////////////////////////////////////////

class PropertyPageBase: 
	public IPropertyPage
{
public:
	PropertyPageBase();
	virtual ~PropertyPageBase();

	//IPropertyPage
    virtual HRESULT __stdcall SetPageSite( IPropertyPageSite *pPageSite);
    virtual HRESULT __stdcall Activate( HWND hWndParent,LPCRECT pRect,BOOL bModal);
    virtual HRESULT __stdcall Deactivate( void);
    virtual HRESULT __stdcall GetPageInfo( PROPPAGEINFO *pPageInfo);
    virtual HRESULT __stdcall SetObjects( ULONG cObjects,IUnknown **ppUnk);
    virtual HRESULT __stdcall Show( UINT nCmdShow);
	virtual HRESULT __stdcall Move( LPCRECT pRect);
    virtual HRESULT __stdcall IsPageDirty( void);
    virtual HRESULT __stdcall Apply( void);
    virtual HRESULT __stdcall Help( LPCOLESTR pszHelpDir);
    virtual HRESULT __stdcall TranslateAccelerator( MSG *pMsg);

	//helper
	void setDirty();

protected:

	SIZE size_;
	BOOL bDirty_;
	std::wstring title_;
	punk<IPropertyPageSite> pageSite_;

	std::vector<IUnknown*> objects_;
};


class OlePropPage : 
	public ::mol::win::PropPage
{
friend class mol::PropSheet;
public:

	OlePropPage();

	virtual void init();
	virtual void setObjects();
	virtual void reset();
	virtual int apply();
	virtual int translateAccel( LPMSG msg);

private:

	void create( mol::PropSheet* ps, const std::wstring& tab, REFCLSID clsid , int id,int flags = PSP_DEFAULT|PSP_USETITLE);

	class PropertyPageSite :
		public IPropertyPageSite,
		public mol::interfaces< PropertyPageSite, mol::implements<IPropertyPageSite> >
	{
		public: outer_this( OlePropPage, propertyPageSite_); 

			void dispose() {};
			
			virtual HRESULT STDMETHODCALLTYPE OnStatusChange( DWORD dwFlags);
			virtual HRESULT STDMETHODCALLTYPE GetLocaleID( LCID *pLocaleID);
			virtual HRESULT STDMETHODCALLTYPE GetPageContainer( IUnknown **ppUnk);
			virtual HRESULT STDMETHODCALLTYPE TranslateAccelerator( MSG* pMsg);
	};


	mol::stack_obj<PropertyPageSite> propertyPageSite_;
	
protected:

	mol::punk<IPropertyPage> prop_;

};


} // end namespace mol::win::ole


///////////////////////////////////////////////////////////
// Property Page 
///////////////////////////////////////////////////////////

template<class T, int DlgId>
class PropertyPage: 
	public mol::ole::PropertyPageBase,
	public mol::Dlg<T>
{
public:

    virtual HRESULT __stdcall Activate( HWND hWndParent,LPCRECT pRect,BOOL bModal) 
	{
		T* t = (T*)this;
		HINSTANCE hinst = (HINSTANCE)::GetModuleHandle(0);
		t->doModeless( DlgId, hWndParent );
		t->move(*pRect);
		return S_OK;
	}

	HRESULT __stdcall Deactivate( void) 
	{
		this->destroy();
		return S_OK;
	}

	HRESULT __stdcall Show( UINT nCmdShow)
	{
		this->show(nCmdShow);
		return S_OK;
	}

	HRESULT __stdcall Move( LPCRECT pRect)
	{
		this->move(*pRect);
		return S_OK;
	}
};

class PropSheet
{
public:

	typedef PropSheet BaseWindowType;

	PropSheet(HWND owner, const std::wstring& title, int flags = PSH_NOCONTEXTHELP | PSH_PROPTITLE | PSH_USEPSTARTPAGE | PSH_NOAPPLYNOW | PSH_USECALLBACK);

	template<class T>
	void addPage(const std::wstring& tab, int id)
	{
		mol::win::PropPage* page = new T;
		page->create(this, tab, id);
		addPage(page);
	}

	template<class T>
	void addPage(const std::wstring& tab, REFCLSID clsid, int id)
	{
		mol::ole::OlePropPage* page = new T;
		page->create(this, tab, clsid, id);
		addPage(page);
	}

	INT_PTR create();

	static int CALLBACK PropSheetProc(HWND hwndDlg, UINT uMsg, LPARAM lParam);

	void center(HWND hwnd);
protected:

	HPROPSHEETPAGE addPage(mol::win::PropPage* page);

	bool centered_;
	int startPage_;
	int	nPages_;
	std::vector<HPROPSHEETPAGE> pages_;
	PROPSHEETHEADER ph_;
	std::wstring title_;
};

} // end namespace mol

#endif