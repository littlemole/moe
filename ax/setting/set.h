#ifndef MOL_DEF_SETTING_VIEW_DEF_GUARDING_
#define MOL_DEF_SETTING_VIEW_DEF_GUARDING_

#include "win/CoCtrl.h"
#include "win/MsgMap.h"
#include "win/MsgHandler.h"
#include "win/msg_macro.h"
#include "ole/punk.h"
#include "ole/factory.h"
#include "ole/bstr.h"
#include "ole/persist.h"
#include "ole/cp.h"
#include "ole/propertypage.h"

#include <fstream>
#include "Setting_h.h"
#include "resource.h"

using namespace mol;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define DISPID_SETTING_KEY 1
#define DISPID_SETTING_VALUE 2
#define DISPID_SETTING_PARENT 3
#define DISPID_SETTING_CHILDREN_ALLOWED 4
#define DISPID_SETTING_KEY_READONLY 5
#define DISPID_SETTING_VALUE_READONLY 6

///////////////////////////////////////////////////////////////////////////////

class Setting : 
	public com_registerobj<Setting,CLSID_Setting>,
	public Dispatch<ISetting>,
	public PersistStream<Setting>,
	public PersistStorage<Setting>,
	public PersistFile<Setting>,
	public ISpecifyPropertyPages,
	public mol::ConnectionPointContainer<Setting>,
	public mol::ConnectionPoint<
					Setting,
					_ISettingChanged,
					mol::ole::ConnectionPointAdviseMultiThreadPolicy<_ISettingChanged>
				>,
	public interfaces< Setting, 
				implements< 	IDispatch,
								ISetting,
								interface_ex<IPersist,IPersistStreamInit>,
								interface_ex<IPersistStream,IPersistStreamInit>,
								IPersistStreamInit,
								IPersistStorage,
								IPersistFile,
								IProvideClassInfo,
								IConnectionPointContainer ,
								ISpecifyPropertyPages >
						   >
{
public:

    Setting(void);
    ~Setting();

	// COM properties

		HRESULT virtual __stdcall get_Key	( BSTR* key );
		HRESULT virtual __stdcall put_Key	( BSTR key  );

		HRESULT virtual __stdcall get_Value	( BSTR* value );
		HRESULT virtual __stdcall put_Value	( BSTR value );

		HRESULT virtual __stdcall get_Parent ( ISetting** parent );
		HRESULT virtual __stdcall put_Parent ( ISetting* parent );

		HRESULT virtual __stdcall get_ChildrenAllowed	( VARIANT_BOOL* vb );
		HRESULT virtual __stdcall put_ChildrenAllowed	( VARIANT_BOOL vb );

		HRESULT virtual __stdcall get_KeyReadOnly		( VARIANT_BOOL* vb );
		HRESULT virtual __stdcall put_KeyReadOnly		( VARIANT_BOOL vb );

		HRESULT virtual __stdcall get_ValueReadOnly		( VARIANT_BOOL* vb );
		HRESULT virtual __stdcall put_ValueReadOnly		( VARIANT_BOOL vb );

		HRESULT virtual __stdcall get_IsDirty		( VARIANT_BOOL* vb );
		HRESULT virtual __stdcall put_IsDirty		( VARIANT_BOOL  vb );

	// COM methods

		HRESULT virtual __stdcall _NewEnum			(IEnumVARIANT** newEnum);
		HRESULT virtual __stdcall Item				(VARIANT index, ISetting** item);
		HRESULT virtual __stdcall Count				(long* cnt);
		HRESULT virtual __stdcall Root				(ISetting** root);
		HRESULT virtual __stdcall KeyName			(BSTR* keyname);
		HRESULT virtual __stdcall Add				(ISetting* set);
		HRESULT virtual __stdcall New				(BSTR key, BSTR value,ISetting** set);
		HRESULT virtual __stdcall Remove			();
		HRESULT virtual __stdcall Clear				();
		HRESULT virtual __stdcall Load				( BSTR filename);
		HRESULT virtual __stdcall Save				( BSTR filename);
		HRESULT virtual __stdcall RemoveItem		( VARIANT index);
		HRESULT virtual __stdcall Clone				( ISetting** clone);

        HRESULT virtual __stdcall GetPages			( CAUUID *pPages );

		HRESULT virtual __stdcall Save(	 IStorage * pStgSave, BOOL fSameAsLoad );
		HRESULT virtual __stdcall Load(	 IStorage * pStgLoad);

		HRESULT virtual __stdcall Load( LPSTREAM pStm);
		HRESULT virtual __stdcall Save( LPSTREAM pStm,BOOL fClearDirty);


	//helpers
	BOOL isDirty()			{ return bDirty_; }
	void setDirty(BOOL d)	{ if ( d == TRUE ) { this->fire(1); } bDirty_ = d; }


protected:

	HRESULT makeKey(std::wstring key, ISetting* parent, ISetting** newKey);
	std::wstring getSingleKey(const std::wstring& key, size_t pos);
	HRESULT getKey(const std::wstring& key, ISetting** newKey);
	void saveWalker(ISetting* set, std::ofstream& ofs );


	BOOL						bDirty_;

	bstr						key_;
	bstr						val_;

	ISetting*					parent_;
	std::list<ISetting*>		entries_;
	
	VARIANT_BOOL				vbChildrenAllowed_;
	VARIANT_BOOL				vbKeyReadOnly_;
	VARIANT_BOOL				vbValueReadOnly_;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////

class ValueDialog :	public mol::win::Dialog
{
public:
	mol::string value;
	mol::string title;

	LRESULT wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

protected:
	mol::EditBox edit_;
};

///////////////////////////////////////////////////////////

class KeyDialog : public mol::win::Dialog
{
public:
	mol::string key;

	LRESULT wndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

protected:
	mol::EditBox edit_;
};

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

class SettingProperties : 
	public com_registerobj<SettingProperties,CLSID_SettingProperties>,
	public PropertyPage<SettingProperties,IDD_PROP_DIALOG>,
	public interfaces< SettingProperties, implements<IPropertyPage> >
{
public:
	SettingProperties()
	{
		title_  = _T("Edit Settings");
	}

	msg_handler(WM_INITDIALOG, OnInitDialog )
		LRESULT OnInitDialog(UINT msg, WPARAM wParam, LPARAM lParam);

	notify_code_handler(NM_DBLCLK, OnDblClick )
		LRESULT OnDblClick  (UINT msg, WPARAM wParam, LPARAM lParam);

	notify_code_handler( NM_RCLICK, OnContext )
		LRESULT OnContext   (UINT msg, WPARAM wParam, LPARAM lParam);

    virtual HRESULT __stdcall Apply( void);

protected:
	void initWalker(HTREEITEM parent, ISetting* set);
	bool editValue(HTREEITEM hit);

	mol::TreeCtrl			tree_;
	punk<ISetting>			clone_;
};




#endif