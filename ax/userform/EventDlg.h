#ifndef USERFORM_EVENT_DEF_GUARD_
#define USERFORM_EVENT_DEF_GUARD_


#include "common.h"

#include "fm20_tlh.h" 

///////////////////////////////////////////////////////////////////////////////


class EventDlg : public mol::win::Dialog
{
public:
	EventDlg(MSForms::_UserForm* f, const std::wstring& engine);
	virtual LRESULT wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	mol::punk<MSForms::_UserForm> form;

private:

	void populateControlTree(IUnknown* ctrl, HTREEITEM hit);
	void populateControlList(HTREEITEM hit);
	void copySelectionToClipboard();

	void freeTree(HTREEITEM it);
	void freeList();

	mol::TreeCtrl		tree_;
	mol::ListBox		list_;
	std::wstring		engine_;
};



///////////////////////////////////////////////////////////////////////////////

#endif