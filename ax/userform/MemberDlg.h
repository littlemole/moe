#ifndef USERFORM_MEMBER_DEF_GUARD_
#define USERFORM_MEMBER_DEF_GUARD_


#include "common.h"
#include "fm20_tlh.h" 

///////////////////////////////////////////////////////////////////////////////




class FuncDlg : public mol::win::Dialog
{
public:
	FuncDlg(MSForms::_UserForm* f, const std::wstring& engine);
	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	mol::punk<MSForms::_UserForm> form;

private:
	void populateControlTree(IUnknown* ctrl, HTREEITEM hit);
	void populateControlList(HTREEITEM hit);
	HRESULT addTypeInfo(ITypeInfo* typInf, mol::bstr& name);
	void copySelectionToClipboard();

	void freeTree(HTREEITEM it);
	void freeList();

	mol::TreeCtrl		tree_;
	mol::ListBox		list_;
	std::wstring			engine_;
};

///////////////////////////////////////////////////////////////////////////////

#endif