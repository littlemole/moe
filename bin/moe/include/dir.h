#ifndef DIRLIST_DEF_GUARD_
#define DIRLIST_DEF_GUARD_

#include "shared.h"
#include "resource.h"

using namespace mol;

///////////////////////////////////////////////////////////////////////////////

class DirChild 
: 
	public MdiChildFrame<DirChild,mol::AxWnd<DirChild,MdiChild,&CLSID_ShellList>>,
	public DispatchMidiWindow<DirChild,IDoc>,
	public ProvideClassInfo<DirChild>,
	public interfaces< DirChild, 
			implements< IDispatch, IDoc, IProvideClassInfo> >
{
public:

	DirChild();
	virtual ~DirChild();


	static Instance* CreateInstance( const mol::string& p );

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

	mol::punk<IShellList> list;

private:

	// directory events sink
    class DirChild_sink : public stack_obj<ShellListEvents>
    {
        public : outer_this(DirChild,sink); 
		virtual HRESULT __stdcall OnListSelection(BSTR filename);
		virtual HRESULT __stdcall OnListDblClick(BSTR filename);
		virtual HRESULT __stdcall OnListOpen(BSTR filename);
		virtual HRESULT __stdcall OnDirChanged(BSTR filename);
    } sink;

	bool initialize(const mol::string& p);



	mol::string filename_;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#endif