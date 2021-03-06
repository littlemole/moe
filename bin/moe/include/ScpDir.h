#ifndef SCPDIRLIST_DEF_GUARD_
#define SCPDIRLIST_DEF_GUARD_

#include "mdichild.h"
#include "resource.h"


///////////////////////////////////////////////////////////////////////////////

class ScpDirChild 
 
	: public MoeAxChild<
				ScpDirChild,
				MOE_DOCTYPE_SFTP,
				&CLSID_ScpList,
				IDM_MOE_DIR
			>
{
public:

	ScpDirChild();
	virtual ~ScpDirChild();


	static Instance* CreateInstance( ISSHConnection* conn, const std::wstring& p );

	void OnMDIActivate(HWND activated);
    void OnClose();
	void OnDestroy();
	void OnNcDestroy();

public:

	/////////////////////////////////////////////////////////////////////
	// COM
	/////////////////////////////////////////////////////////////////////

	virtual HRESULT __stdcall get_Filename( BSTR* filename);
	virtual HRESULT __stdcall get_Path( BSTR* dirpath);
	virtual HRESULT __stdcall get_Type( long* type);
	virtual HRESULT __stdcall Close();
	virtual HRESULT __stdcall Activate();

	mol::punk<IScpList> list;

private:

	// directory events sink
    class DirChild_sink : public mol::stack_obj<ShellListEvents>
    {
        public : outer_this(ScpDirChild,sink); 
		virtual HRESULT __stdcall OnListSelection(BSTR filename,VARIANT_BOOL vb);
		virtual HRESULT __stdcall OnListDblClick(BSTR filename,VARIANT_BOOL vb);
		virtual HRESULT __stdcall OnListOpen(BSTR filename,VARIANT_BOOL vb);
		virtual HRESULT __stdcall OnDirChanged(BSTR filename);
    } sink;

	bool initialize(const std::wstring& p);

	std::wstring filename_;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#endif