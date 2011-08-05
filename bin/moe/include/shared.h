#ifndef MOE_COM_COMWNDIMPL_DEF_GUARD_
#define MOE_COM_COMWNDIMPL_DEF_GUARD_

#include "commons.h"
#include "Docs.h"
#include "win/TaskBar.h"
#include "ole/cp.h"
#include "mdichild.h"

/////////////////////////////////////////////////////////////////////
// moe view sub obj
/////////////////////////////////////////////////////////////////////

class MoeView : 
	public mol::Dispatch<IMoeView>,
	public mol::ProvideClassInfo<MoeView>,
	public mol::interfaces< MoeView, 
			mol::implements< 
				IDispatch, 
				IMoeView, 
				IProvideClassInfo> >
{

private:

	WINDOWPLACEMENT					wpPrev_;
	void fullScreen(HWND hwnd);

public:

	virtual ~MoeView();

	typedef mol::com_obj<MoeView> Instance;

	virtual void dispose();

	static REFGUID getCoClassID();

	/////////////////////////////////////////////////////////////////////

	virtual HRESULT __stdcall get_Top( long* top);
	virtual HRESULT __stdcall put_Top( long top);
	virtual HRESULT __stdcall get_Left( long* left);
	virtual HRESULT __stdcall put_Left( long left);
	virtual HRESULT __stdcall get_Width( long* width);
	virtual HRESULT __stdcall put_Width( long width);
	virtual HRESULT __stdcall get_Height( long* height);
	virtual HRESULT __stdcall put_Height( long height);

	/////////////////////////////////////////////////////////////////////

	virtual HRESULT __stdcall Show();
	virtual HRESULT __stdcall Hide();
	virtual HRESULT __stdcall Minimize();
	virtual HRESULT __stdcall Maximize();
	virtual HRESULT __stdcall Restore();
	virtual HRESULT __stdcall Tile();
	virtual HRESULT __stdcall Cascade();
	virtual HRESULT __stdcall get_ShowTreeView( VARIANT_BOOL* vb );
	virtual HRESULT __stdcall put_ShowTreeView( VARIANT_BOOL vb );
	virtual HRESULT __stdcall put_Fullscreen( VARIANT_BOOL vb );
	virtual HRESULT __stdcall get_Fullscreen( VARIANT_BOOL* vb );
	virtual HRESULT __stdcall get_TreeView( IDispatch** tv);
};


/////////////////////////////////////////////////////////////////////
// moe script sub object
/////////////////////////////////////////////////////////////////////

class MoeScript 
	:
	public mol::Dispatch<IMoeScript>,
	public mol::ProvideClassInfo<MoeScript>,
	public mol::interfaces< MoeScript, 
			mol::implements< 
				IDispatch, 
				IMoeScript, 
				IProvideClassInfo> >
{
public:

	virtual ~MoeScript();

	typedef mol::com_obj<MoeScript> Instance;

	virtual void dispose();

	static REFGUID getCoClassID();

	virtual HRESULT __stdcall Run( BSTR f, BSTR engine );
	virtual HRESULT __stdcall Eval( BSTR scrpt, BSTR scrptLanguage);
	virtual HRESULT __stdcall Debug( BSTR scrpt, BSTR scrptLanguage);
	virtual HRESULT __stdcall CreateObjectAdmin( BSTR progid, IDispatch** disp);
	virtual HRESULT __stdcall ShowHtmlForm( BSTR src, long l, int t, int w, int h, int formStyle );
	virtual HRESULT __stdcall ShowUserForm( BSTR pathname, IMoeUserForm** form );
	virtual HRESULT __stdcall DebugUserForm( BSTR pathname, IMoeUserForm** form );
	virtual HRESULT __stdcall System( BSTR f);

};

/////////////////////////////////////////////////////////////////////
// moe config sub object
/////////////////////////////////////////////////////////////////////

#define DISPID_MOECONF_SYSTYPE 3
#define DISPID_MOECONF_ENCODING 4
#define DISPID_MOECONF_TABUSAGE 5
#define DISPID_MOECONF_TABINDENTS 6
#define DISPID_MOECONF_BACKSPACEUNINDENTS 7
#define DISPID_MOECONF_TABWIDTH 8
#define DISPID_MOECONF_LINENUMBERS 9

class MoeConfig 
	:
	public mol::Dispatch<IMoeConfig>,
	public mol::PersistStream<MoeConfig>,
	public mol::ProvideClassInfo<MoeConfig>,
	public mol::interfaces< MoeConfig, 
			mol::implements< 
				IDispatch, 
				IMoeConfig, 
				mol::interface_ex<IPersist,IPersistStreamInit>,
				mol::interface_ex<IPersistStream,IPersistStreamInit>,
				IPersistStreamInit,
				IProvideClassInfo> >
{
private:

	typedef MoeConfig com_creatable_type;

	long							systype_;
	long							encoding_;
	long							tabwidth_;
	VARIANT_BOOL					tabUsage_;
	VARIANT_BOOL					tabIndents_;
	VARIANT_BOOL					fullScreen_;
	VARIANT_BOOL					backSpaceUnIndents_;
	VARIANT_BOOL					showLineNumbers_;

public:

	MoeConfig();
	virtual ~MoeConfig();

	typedef mol::com_obj<MoeConfig> Instance;
	
	virtual void dispose();

	static REFGUID getCoClassID();

	virtual HRESULT __stdcall get_ConfigPath( BSTR* fPath);
	virtual HRESULT __stdcall get_ModulePath(  BSTR* fPath);

	virtual HRESULT __stdcall put_SysType( long typ);
	virtual HRESULT __stdcall get_SysType( long* typ);

	virtual HRESULT __stdcall put_Encoding( long typ);
	virtual HRESULT __stdcall get_Encoding( long* typ);

	virtual HRESULT __stdcall put_TabUsage( VARIANT_BOOL vbTabUsage);
	virtual HRESULT __stdcall get_TabUsage( VARIANT_BOOL* vbTabUsage);

	virtual HRESULT __stdcall put_TabIndents( VARIANT_BOOL vbTabIndents);
	virtual HRESULT __stdcall get_TabIndents( VARIANT_BOOL* vbTabIndents);

	virtual HRESULT __stdcall put_BackSpaceUnindents( VARIANT_BOOL vbBackSpaceIndents);
	virtual HRESULT __stdcall get_BackSpaceUnindents(  VARIANT_BOOL* vbBackSpaceIndents);

	virtual HRESULT __stdcall put_TabWidth( long width);
	virtual HRESULT __stdcall get_TabWidth(  long* width);

	virtual HRESULT __stdcall put_ShowLineNumbers( VARIANT_BOOL vb);
	virtual HRESULT __stdcall get_ShowLineNumbers(  VARIANT_BOOL* vb);

	virtual HRESULT __stdcall EditPreferences( );
	virtual HRESULT __stdcall EditSettings( );
	virtual HRESULT __stdcall ExportSettings( BSTR f );
	virtual HRESULT __stdcall ImportSettings( BSTR f );
	virtual HRESULT __stdcall InitializeEditorFromPreferences( IMoeDocument* d );

	virtual HRESULT __stdcall Load( LPSTREAM pStm);
	virtual HRESULT __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);

	void setDirty(bool b);
	bool isDirty();
};

/////////////////////////////////////////////////////////////////////
// moe dialog child object view impl
/////////////////////////////////////////////////////////////////////

class MoeDialogView : 
	public mol::Dispatch<IMoeDialogView>,
	public mol::ProvideClassInfo<MoeDialogView>,
	public mol::interfaces< MoeDialogView, 
			mol::implements< 
				IDispatch, 
				IMoeDialogView, 
				IProvideClassInfo> >
{
private:

	mol::win::WndProc* wnd_;

public:

	virtual ~MoeDialogView();

	typedef mol::stack_obj<MoeDialogView> Instance;

	static Instance* CreateInstance(  mol::win::WndProc* wnd )
	{
		Instance* i = new Instance;
		i->wnd_ = wnd;
		return i;
	}

	virtual void dispose();

	static REFGUID getCoClassID();

	/////////////////////////////////////////////////////////////////////

	virtual HRESULT __stdcall get_Top( long* top);
	virtual HRESULT __stdcall put_Top( long top);
	virtual HRESULT __stdcall get_Left( long* left);
	virtual HRESULT __stdcall put_Left( long left);
	virtual HRESULT __stdcall get_Width( long* width);
	virtual HRESULT __stdcall put_Width( long width);
	virtual HRESULT __stdcall get_Height( long* height);
	virtual HRESULT __stdcall put_Height( long height);


	virtual HRESULT __stdcall Show();
	virtual HRESULT __stdcall Hide();
	virtual HRESULT __stdcall Close();
	virtual HRESULT __stdcall get_Title( BSTR* title );
	virtual HRESULT __stdcall put_Title( BSTR title );
};


/////////////////////////////////////////////////////////////////////
// moe dialogs subobject
/////////////////////////////////////////////////////////////////////

class MoeDialogs 
	:
	public mol::Dispatch<IMoeDialogs>,
	public mol::ProvideClassInfo<MoeDialogs>,
	public mol::interfaces< MoeDialogs, 
			mol::implements< 
				IDispatch, 
				IMoeDialogs, 
				IProvideClassInfo> >
{

public:

	virtual ~MoeDialogs();

	typedef mol::com_obj<MoeDialogs> Instance;

	virtual void dispose();

	static REFGUID getCoClassID();

	virtual HRESULT __stdcall MsgBox( BSTR text, BSTR title, long flags, long* result);
	virtual HRESULT __stdcall Open(IMoeDocument** d);
	virtual HRESULT __stdcall OpenDir( IMoeDocument** d);
	virtual HRESULT __stdcall ChooseFile( BSTR* f );
	virtual HRESULT __stdcall ChooseDir( BSTR* d );
	virtual HRESULT __stdcall Help();
	virtual HRESULT __stdcall Print();
};



#endif

