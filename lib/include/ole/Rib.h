#ifndef MOL_LIB_DEFINE_MAC_RIB_DEFINITION_GUARD_DEF_
#define MOL_LIB_DEFINE_MAC_RIB_DEFINITION_GUARD_DEF_


#include "ole/ole.h"
#include "ole/obj.h"
#include "ole/aut.h"
#include "win/RTFedit.h"
#include <UIRibbon.h>

namespace mol
{

namespace Ribbon
{


/////////////////////////////////////////////////////

class PropertySet
	: 
	public IUISimplePropertySet,
	public 	mol::interfaces<PropertySet,
					mol::implements<IUISimplePropertySet> 
				>
{
public:
    PropertySet();
    ~PropertySet();

	void dispose() {}

	typedef mol::com_obj<PropertySet> Instance;
	static Instance* CreateInstance();

    void InitializeCommandProperties(int categoryId, int commandId, UI_COMMANDTYPE commandType);
    void InitializeItemProperties(IUIImage *image, PCWSTR label, int categoryId);
    void InitializeCategoryProperties(PCWSTR label, int categoryId);
	void InitializeRecentItem( PCWSTR label, bool pinned);

    HRESULT virtual __stdcall GetValue( REFPROPERTYKEY key, PROPVARIANT *ppropvar);

private:

	std::wstring label_;
    int commandId_;
    int categoryId_;
	bool pinned_;
	mol::punk<IUIImage> pimgItem_;
    UI_COMMANDTYPE commandType_; 

};

class HandlerBase : 
	public IUICommandHandler
{
public:

	virtual ~HandlerBase();

	virtual void callback(int id);

	bool minimized();
	int cmd();
	std::wstring value();
	std::wstring label();
	bool enabled();
	int index();
	bool checked();
	int decimalPlaces();
	mol::variant decimal();
	std::vector<std::wstring> items();
	std::vector<std::pair<std::wstring, bool> > recent_items();
	CHARFORMAT2& font();


	void minimize(bool);
	void checked(bool b);
	void select(int index);
	void value(const std::wstring& v);
	void label(const std::wstring& l);
	void bValue( bool b);
	void check( bool b);
	void enable( bool b);
	void decimalPlaces(int);
	void decimal(mol::variant& v);
	void items(const std::vector<std::wstring>& items, int index = 0);
	void recent_item(const std::pair<std::wstring, bool>& item);

    HRESULT virtual __stdcall Execute( UINT nCmdID, UI_EXECUTIONVERB verb, const PROPERTYKEY* key, const PROPVARIANT* ppropvarValue, IUISimplePropertySet* pCommandExecutionProperties);
    HRESULT virtual __stdcall UpdateProperty( UINT nCmdID, REFPROPERTYKEY key, const PROPVARIANT* ppropvarCurrentValue, PROPVARIANT* ppropvarNewValue);

protected:

	HandlerBase();

	int id_;
	std::vector<std::wstring> items_;
	std::vector<std::pair<std::wstring, bool> > recent_items_;
	std::wstring value_;
	std::wstring label_;
	bool bValue_;
	bool enabled_;
	bool minimized_;
	int decimalPlaces_;
	mol::variant decimal_;
	int index_;
	CHARFORMAT2 charFormat_;
};

/////////////////////////////////////////////////////

template<class T>
class Handler : 	
	
	public 	mol::interfaces<
					Handler<T>,
					mol::implements<
						IUICommandHandler
					> 
			>,
	public HandlerBase
{
public:

	typedef void (T::*func)(int id);
	typedef mol::com_obj<Handler> Instance;

	static Instance* CreateHandler( int id, T* t, func f)
	{
		Instance* i = new Instance();
		i->id_ = id;
		i->f_ = f;
		i->t_  = t;
		return i;
	}

	void callback(int id)
	{
		if ( t_ && f_ )
			(t_->*f_)(id);
	}

protected:

	Handler()
	{}

	~Handler()
	{
	}
	
	Handler(const Handler&)
	{}

	void dispose() 
	{
	}

private:

	T* t_;
	func f_;
};

/////////////////////////////////////////////////////

class HandlerRegistry :
	public IUnknown,
	public mol::interfaces< HandlerRegistry,
			mol::implements<IUnknown> 
		   >
{
friend mol::NonCreatableCOMSingleton<HandlerRegistry>; 
friend mol::com_obj<HandlerRegistry>;
friend class Ribbon;
public:


	typedef mol::com_obj<HandlerRegistry> Instance;

	void dispose();

	template<class T>
	bool RegisterHandler( int id, T* t, typename Handler<T>::func f)
	{
		typename Handler<T>::Instance* i = Handler<T>::CreateHandler(id,t,f);
		if ( !i ) return false;
		registry_[id] = i;
		i->AddRef();
		return true;
	}

	HandlerBase* handler(int id)
	{
		if ( registry_.count(id) == 0 ) 
		{
			return &dummy_;
		}
		return registry_[id];
	}

private:

	HandlerRegistry()
	{}

	~HandlerRegistry()
	{
	}

	HandlerRegistry(const HandlerRegistry&)
	{}

	std::map<int,HandlerBase*> registry_;
	mol::stack_obj<Handler<HandlerRegistry> > dummy_;
};

inline HandlerRegistry::Instance* registry() 
{ 
	return mol::nonCreatableCOMSingleton<HandlerRegistry::Instance>();
}

inline HandlerBase* handler(int id)
{
	return registry()->handler(id);
}

/////////////////////////////////////////////////////

class RibbonCommand
{
public:

	RibbonCommand(HWND wnd, int i, int c);
	virtual ~RibbonCommand();
	virtual void handler(int id);

protected:

	void notify(int id, int code);
	void command(int id);

	HWND wnd_;
	int rid_;
	int cid_;
};

class RibbonNotify : public RibbonCommand
{
public:

	RibbonNotify(HWND wnd, int i, int c, int n);
	~RibbonNotify();

	virtual void handler(int id);
	
protected:

	int nid_;
};

/////////////////////////////////////////////////////

class Ribbon :
	public IUIApplication,
	public mol::interfaces< Ribbon,
			mol::implements<IUIApplication> 
		   >
{
friend mol::NonCreatableCOMSingleton<Ribbon>; 
friend mol::com_obj<Ribbon>;
friend class HandlerRegistry;
friend class RibbonWnd;
public:

	typedef mol::com_obj<Ribbon> Instance;

    // IUIApplication methods
	HRESULT virtual __stdcall OnCreateUICommand(UINT nCmdID, UI_COMMANDTYPE typeID, IUICommandHandler** ppCommandHandler);
    HRESULT virtual __stdcall OnViewChanged(UINT viewId,UI_VIEWTYPE typeId, IUnknown* pView, UI_VIEWVERB verb, INT uReasonCode);
    HRESULT virtual __stdcall OnDestroyUICommand(UINT32 commandId, UI_COMMANDTYPE typeID, IUICommandHandler* commandHandler);

	void mode(int i);
	void update(int id, UI_INVALIDATIONS what = UI_INVALIDATIONS_VALUE);
	void flush();

	UINT height();
	bool enabled();
	bool show(HWND wnd);
	void dispose();

	void updateRecentDocs(int id);
	void addRecentDoc(int id, const std::wstring& path);

	void registerCommand( HWND w,int rid, int cmd)
	{
		handlers_.insert(
			std::make_pair(
				rid,
				new RibbonCommand(w,rid,cmd)
			)
		);
	}

	void registerNotification( HWND w,int rid, int cmd, int notify)
	{
		handlers_.insert(
			std::make_pair(
				rid,
				new RibbonNotify(w,rid,cmd,notify)
			)
		);
	}

	void minimize();
	void maximize();
	bool showContextualUI(int id, int x, int y);

	bool load(IStorage* s);
	bool save(IStorage* s);

	bool tearDown();

	void setColorHSV( UI_HSBCOLOR foreGround, UI_HSBCOLOR backGround, UI_HSBCOLOR text);
	void setColor( COLORREF fore, COLORREF back, COLORREF text);
	void setDefaultColor();

private :

	mol::punk<IUIFramework> ribbon;


	Ribbon();
    ~Ribbon();

	Ribbon(const Ribbon& )
	{}

	HWND wnd_;

	std::map<int,RibbonCommand*> handlers_;

};

inline Ribbon::Instance* ribbon()
{
	return mol::nonCreatableCOMSingleton<Ribbon::Instance>();
}


} // end namespace Ribbon
} // end namespace mol


#endif