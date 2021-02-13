#ifndef DIRLIST_DEF_GUARD_
#define DIRLIST_DEF_GUARD_

#include "shared.h"
#include "mdichild.h"
//#include "resource.h"



///////////////////////////////////////////////////////////////////////////////

class DirChild 
	: public MoeAxChild<
				DirChild,
				MOE_DOCTYPE_DIR,
				&CLSID_ShellPane,
				IDM_MOE_DIR
			>
{
public:

	DirChild();
	virtual ~DirChild();

	static Instance* CreateInstance( const std::wstring& p );

	void OnMDIActivate(HWND activated);
	void OnNcDestroy();
	void OnDestroy();
	LRESULT OnCloseAll();

    virtual HRESULT __stdcall get_FilePath( BSTR *fname);

private:

	std::wstring	location_;
	mol::punk<IShellPane> list;

	// directory events sink
    class DirChild_Events : 
		public mol::stack_obj<ShellFolderEvents>
    {
        public : outer_this(DirChild,events); 
		virtual HRESULT __stdcall OnListSelection(BSTR filename);
		virtual HRESULT __stdcall OnListDblClick(BSTR filename);
		virtual HRESULT __stdcall OnListOpen(BSTR filename);
		virtual HRESULT __stdcall OnDirChanged(BSTR filename);
    } events;

	bool initialize(const std::wstring& p);

};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#endif