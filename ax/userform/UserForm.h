#ifndef USERFORM_DEF_GUARD_
#define USERFORM_DEF_GUARD_


#include "common.h"
#include "CtrlWnd.h"

///////////////////////////////////////////////////////////////////////////////


class UserForm 
	: 
	public mol::com_registerobj< UserForm, CLSID_UserFormRunner, CLSCTX_ALL>,
	public mol::Dispatch<IMoeUserForm>,
	public mol::ProvideClassInfo<UserForm>,
	public mol::PersistStorage<UserForm>,
	public mol::interfaces< UserForm, 
			mol::implements< IDispatch, IMoeUserForm, IProvideClassInfo> >
{
public:

	FrameWindow  frame;

	UserForm();
	virtual ~UserForm();

	static REFGUID getCoClassID()
	{
		return CLSID_UserFormRunner;
	}

	virtual HRESULT __stdcall Load(IDispatch*,BSTR, VARIANT_BOOL);
	virtual HRESULT __stdcall Item(VARIANT index,IDispatch **d);
    virtual HRESULT __stdcall get_Controls( IDispatch **d);    
    virtual HRESULT __stdcall get_Script(  IDispatch **s);    
    virtual HRESULT __stdcall get_FilePath(  BSTR *filename);

	virtual HRESULT __stdcall get_Top(long* top);
	virtual HRESULT __stdcall put_Top(long top);
	virtual HRESULT __stdcall get_Left(long* left);
	virtual HRESULT __stdcall put_Left(long left);
	virtual HRESULT __stdcall get_Width(long* width);
	virtual HRESULT __stdcall put_Width(long width);
	virtual HRESULT __stdcall get_Height(long* height);
	virtual HRESULT __stdcall put_Height(long height);

	virtual HRESULT __stdcall put_Title(BSTR);
	virtual HRESULT __stdcall get_Title(BSTR*);
	virtual HRESULT __stdcall Save(void);

	bool isDirty() { return dirty_; }
	void setDirty(bool b) { dirty_ = b; }

	/////////////////////////////////////////////////////////////////////
	// COM
	/////////////////////////////////////////////////////////////////////

	virtual HRESULT __stdcall Close();
	virtual HRESULT __stdcall Show();
	virtual HRESULT __stdcall Hide();

    virtual HRESULT __stdcall Load( IStorage *pStg);
    virtual HRESULT __stdcall Save( IStorage* store, BOOL fSameAsLoad);      
    virtual HRESULT __stdcall InitNew(IStorage *pStg);

private:

	bool dirty_;
	std::wstring title_;
	std::wstring filename_;

	bool initialize(const std::wstring& p, bool designMode, bool Debug);
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////

#endif