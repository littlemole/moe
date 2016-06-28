#include "StdAfx.h"
#include "UserForm.h"
#include "MemberDlg.h"
#include "fm20_tlh.h" 

#include "resource.h"

//DEFINE_GUID(GUID_JSCRIPT9, 0x16d51579L, 0xa30b, 0x4c8b,
//	0xa2, 0x76, 0x0f, 0xf4, 0xdc, 0x41, 0xe7, 0x55);

///////////////////////////////////////////////////////////////////////////////


FuncDlg::FuncDlg( MSForms::_UserForm* f, const std::wstring& engine )
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
		wchar_t* c = (wchar_t*)list_.getData(i);
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
						std::wstring func( mol::towstring(bstrs[0]) );						

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
									std::wstring tmp = _T("my $var = $");
									tmp += name.towstring();
									tmp += _T("{");
									tmp += func;
									tmp += _T("};");
									list_.addString(func + _T(" (GET)") );
									func = tmp;									
								}
								else if ( funcdesc->invkind & DISPATCH_PROPERTYPUT )
								{
									std::wstring tmp = _T("$");
									tmp += name.towstring();
									tmp +=_T("{");
									tmp += func;
									tmp +=_T("} = $var;");
									list_.addString(func + _T(" (PUT)") );
									func = tmp;									
								}
								else if ( funcdesc->invkind == DISPATCH_METHOD )
								{
									list_.addString(func);
									func = name.towstring() + _T(".") + func;
									if ( funcdesc->elemdescFunc.tdesc.vt != VT_VOID)
									{
										func = _T("my $retval = ") + func;
									}
									func += _T("( ");
									for ( unsigned short int n = 1; n < nNames-1; n++ )
									{
										func += _T("$");
										func += mol::towstring(bstrs[n]);
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
								

								int index = list_.index(mol::towstring(bstrs[0]));
								if ( index != -1 )
								{
									std::wstring s = func;
									wchar_t* c = new wchar_t[s.size()+1];
									memcpy( c, s.c_str(), (s.size()+1)*sizeof(wchar_t) );
									list_.setData( index, (void*)c );
								}
							}
							if ( engine_ == _T("Javascript")) {

								std::wostringstream oss;
								if ( funcdesc->invkind & DISPATCH_PROPERTYGET )
								{
									oss << _T("\r\nvar value = ");
									oss << name.towstring();
									oss << _T(".");
									oss << func;
									oss << _T(";\r\n");
									list_.addString(func + _T(" (GET)") );
								}
								else if ( funcdesc->invkind & DISPATCH_PROPERTYPUT )
								{
									oss << _T("\r\n");
									oss << name.towstring();
									oss << _T(".");
									oss << func;
									oss << _T(" = value;\r\n");
									list_.addString(func + _T(" (PUT)") );
								}
								else if ( funcdesc->invkind == DISPATCH_METHOD )
								{
									list_.addString(func);
									if ( funcdesc->elemdescFunc.tdesc.vt != VT_VOID)
									{
										oss << _T("\r\nvar retval = ");
									}
									oss << name << _T(".") << func << _T("( ");
									for ( unsigned short int n = 1; n < nNames-1; n++ )
									{
										func += mol::towstring(bstrs[n]);
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

								int index = list_.index(mol::towstring(bstrs[0]));
								if ( index != -1 )
								{
									std::wstring s = oss.str();
									wchar_t* c = new wchar_t[s.size()+1];
									memcpy( c, s.c_str(), (s.size()+1)*sizeof(wchar_t) );
									list_.setData( index, (void*)c );
								}
							}
							if ( engine_ == _T("VBScript")) {

								std::wostringstream oss;
								if ( funcdesc->invkind & DISPATCH_PROPERTYGET )
								{
									oss << _T("\r\nvalue = ");
									oss << name.towstring();
									oss << _T(".");
									oss << func;
									oss << _T("\r\n");
									list_.addString(func + _T(" (GET)") );
								}
								else if ( funcdesc->invkind & DISPATCH_PROPERTYPUT )
								{
									oss << _T("\r\n");
									oss << name.towstring();
									oss << _T(".");
									oss << func;
									oss << _T(" = value\r\n");
									list_.addString(func + _T(" (PUT)") );
								}
								else if ( funcdesc->invkind == DISPATCH_METHOD )
								{
									list_.addString(func);
									if ( funcdesc->elemdescFunc.tdesc.vt != VT_VOID)
									{
										oss << _T("\r\n retval = ");
									}
									oss << name << _T(".") << func << _T("( ");
									for ( unsigned short int n = 1; n < nNames-1; n++ )
									{
										func += mol::towstring(bstrs[n]);
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

								int index = list_.index(mol::towstring(bstrs[0]));
								if ( index != -1 )
								{
									std::wstring s = oss.str();
									wchar_t* c = new wchar_t[s.size()+1];
									memcpy( c, s.c_str(), (s.size()+1)*sizeof(wchar_t) );
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
			tree_.addNodeParam(name.towstring(),(LPARAM)(IUnknown*)disp);
		}
	}
}

void FuncDlg::copySelectionToClipboard()
{
	int pos = list_.getCurSel();
	wchar_t* handler = (wchar_t*)list_.getData(pos);
	if (!handler)
		return;

	mol::win::ClipBoard cb;
	cb.clear();

	cb.setAnsiText( mol::tostring(handler) );
	cb.setUnicodeText( mol::towstring(handler) );

//	::PostMessage(moe()->getActive(),WM_COMMAND,IDM_EDIT_PASTE,0);

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
