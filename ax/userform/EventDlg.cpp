#include "StdAfx.h"
#include "UserForm.h"
#include "EventDlg.h"
#include "fm20_tlh.h" 

#include "resource.h"

//DEFINE_GUID(GUID_JSCRIPT9, 0x16d51579L, 0xa30b, 0x4c8b,
//	0xa2, 0x76, 0x0f, 0xf4, 0xdc, 0x41, 0xe7, 0x55);

///////////////////////////////////////////////////////////////////////////////


EventDlg::EventDlg( MSForms::_UserForm* f , const std::wstring& engine)
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
		wchar_t* c = (wchar_t*)list_.getData(i);
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

					std::wostringstream oss;
					oss << _T("\r\nsub ") << name.towstring() << _T("_") << mol::towstring(bstrs[0]);

					oss << _T(" {\r\n");

					for ( unsigned short int n = 1; n < nNames; n++ )
					{
						oss << _T("  my $");
						oss << mol::towstring(bstrs[n]);
						oss <<  _T(" = shift;\r\n");
					}
					oss << _T("\r\n}\r\n");

					
					list_.addString(mol::towstring(bstrs[0]));

					int index = list_.index(mol::towstring(bstrs[0]));
					if ( index != -1 )
					{
						std::wstring s = oss.str();
						wchar_t* c = new wchar_t[s.size()+1];
						memcpy( c, s.c_str(), (s.size()+1)*sizeof(wchar_t) );
						list_.setData( index, (void*)c );
					}
				}
				if ( engine_ == _T("Javascript") ) {

					std::wostringstream oss;
					oss << _T("\r\nfunction ") << name.towstring() << _T("_") << mol::towstring(bstrs[0]) << _T("( ");

					for ( unsigned short int n = 1; n < nNames; n++ )
					{
						oss << mol::towstring(bstrs[n]);
						if ( n < ( nNames-1) )
							oss <<  _T(", ");
					}

					oss << _T(")\r\n{\r\n");
					oss << _T("}\r\n");
					list_.addString(mol::towstring(bstrs[0]));

					int index = list_.index(mol::towstring(bstrs[0]));
					if ( index != -1 )
					{
						std::wstring s = oss.str();
						wchar_t* c = new wchar_t[s.size()+1];
						memcpy( c, s.c_str(), (s.size()+1)*sizeof(wchar_t) );
						list_.setData( index, (void*)c );
					}
				}
				if ( engine_ == _T("VBScript") ) {

					std::wostringstream oss;
					oss << _T("\r\nSub ") << name.towstring() << _T("_") << mol::towstring(bstrs[0]) << _T("( ");

					for ( unsigned short int n = 1; n < nNames; n++ )
					{
						oss << mol::towstring(bstrs[n]);
						if ( n < ( nNames-1) )
							oss <<  _T(", ");
					}

					oss << _T(")\r\n\r\n");
					oss << _T("End Sub\r\n");
					list_.addString(mol::towstring(bstrs[0]));

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
			tree_.addNodeParam(name.towstring(),(LPARAM)(IUnknown*)disp);
		}
	}
}

void EventDlg::copySelectionToClipboard()
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

	/*
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
	*/
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




