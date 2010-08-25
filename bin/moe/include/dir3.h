#ifndef DIRLIST_DEF_GUARD_
#define DIRLIST_DEF_GUARD_

#include "shared.h"
#include "resource.h"



///////////////////////////////////////////////////////////////////////////////

class DirChild 
	: 
	public mol::MdiChildFrame<DirChild,mol::AxWnd<DirChild,mol::MdiChild,&CLSID_ShellPane>>,
	public DispatchMidiWindow<DirChild,IMoeDocument,MOE_DOCTYPE_DIR>,
	public mol::ProvideClassInfo<DirChild>,
	public mol::interfaces< DirChild, 
			mol::implements< IDispatch, IMoeDocument, IProvideClassInfo> >
{
public:

	DirChild();
	virtual ~DirChild();

	static Instance* CreateInstance( const mol::string& p );

	LRESULT OnMDIActivate(HWND activated);

    void OnClose();
	void OnDestroy();
	void OnNcDestroy();

private:

	mol::punk<IShellPane> list;

	// directory events sink
    class DirChild_Events : public mol::stack_obj<ShellFolderEvents>
    {
        public : outer_this(DirChild,events); 
		virtual HRESULT __stdcall OnListSelection(BSTR filename);
		virtual HRESULT __stdcall OnListDblClick(BSTR filename);
		virtual HRESULT __stdcall OnListOpen(BSTR filename);
		virtual HRESULT __stdcall OnDirChanged(BSTR filename);
    } events;

	bool initialize(const mol::string& p);
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#endif