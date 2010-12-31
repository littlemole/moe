#ifndef _MOL_DEF_GUARD_PROPWND_DEF_GUARD_DEFINE_
#define _MOL_DEF_GUARD_PROPWND_DEF_GUARD_DEFINE_


#include "ole/ole.h"
#include "ole/ole.h"
#include "ole/obj.h"
#include "ole/cp.h"
#include "ole/Bstr.h"
#include "ole/typeinfo.h"
#include "ole/Factory.h"
#include "ole/aut.h"
#include "win/path.h"
#include "win/file.h"
#include "util/istr.h"
#include <list>
#include <map>
#include <set>
#include <vector>
#include "win/wnd.h"
#include "win/msghandler.h"
#include "win/msgmap.h"
#include "win/layout.h"
#include "win/msg_macro.h"
#include "util/util.h"
#include "util/str.h"
#include "util/regex.h"

#define IDM_EDIT_DONE 101
#define IDC_PROP_EDIT 102

namespace mol  {

class PropWindow;

namespace prop {

class Category;

// base class for properties

class AbstractProp
{
public:

	AbstractProp( const mol::string& n, PropWindow* propWnd  )
		:name_(n), propWnd_(propWnd)
	{}

	virtual ~AbstractProp()
	{}
	
	virtual void startEdit(HWND parent)
	{}

	virtual void stopEdit()
	{}

	virtual mol::string getValueAsString()
	{
		return _T("");
	}

	virtual void setValueFromString(const mol::string& s)
	{}

	virtual const mol::string& name()
	{
		return name_;
	}

	virtual void draw( mol::win::DCbase& dc, RECT& r, int& offset );

	virtual int cnt()
	{
		return 1;
	}


	virtual AbstractProp* hitTest( POINT& pos, HWND parent )
	{
		return ::PtInRect(&rValue_,pos) ? this : 0 ;
	}

protected:

	mol::Rect rName_;
	mol::Rect rValue_;
	mol::string name_;
	PropWindow* propWnd_;
};


// vector simplification for properties

template<class T>
class SelectVectorBase
{
public:
	
	typedef std::pair<T,mol::string> Property;

	size_t size() 
	{ 
		return v_.size(); 
	}

	void add( const Property& p)
	{
		v_.push_back(p);
	}

	void addProperty( T t, const mol::string& n)
	{
		v_.push_back( std::make_pair(t,n) );
	}

	Property& operator[](size_t idx)
	{
		return v_[idx];
	}

protected:
	std::vector<Property> v_;
};


template<class T>
class SelectVector : public SelectVectorBase<T>
{
public:
	
	void add( T t)
	{
		std::ostringstream oss;
		oss << t;
		v_.push_back( std::make_pair( t, oss.str() ) );
	}
};


template<>
class SelectVector<mol::string> : public SelectVectorBase<mol::string>
{
public:
	
	void add( const mol::string& t)
	{
		v_.push_back( std::make_pair( t,t ) );
	}
};



template<class T>
class Selection
{
public:
	typedef std::pair<T,mol::string> Property;
	typedef SelectVector<T> SelectPropVector;
};

} // end namespace prop


class PropWindow : public mol::ChildFrame<PropWindow,mol::ScrollWnd > 
{
public:

	typedef std::map<mol::string,prop::AbstractProp*> PropMap;
	typedef PropMap::iterator PropIter;

	PropWindow();
	~PropWindow();

	msg_handler(WM_CREATE,OnCreate)
	void OnCreate();

	msg_handler(WM_PAINT,OnPaint)
	void OnPaint();

	msg_handler(WM_LBUTTONDOWN,OnClick)
	LRESULT OnClick(mol::Crack& msg);

	msg_handler(WM_LBUTTONUP,OnUp)
	LRESULT OnUp(mol::Crack& msg);

	cmd_handler(IDM_EDIT_DONE, OnEditDone)
	void OnEditDone();

	virtual LRESULT OnSize(UINT msg, WPARAM wParam, LPARAM lParam);

	template<class T>
	prop::Category& addProperty( const mol::string& cat, const mol::string& n, T& t)
	{
		static std::string empty("");
		prop::Category& c = category(cat);
		c.add( new prop::Prop<T>(n,this,t,empty)  );
		return c;
	}

	template<class T>
	prop::Category& addProperty( const mol::string& cat, const mol::string& n, T& t, const std::string& v )
	{
		prop::Category& c = category(cat);
		c.add( new prop::Prop<T>(n,this,t,v)  );
		return c;
	}

	template<class T>
	prop::Category& addProperty( const mol::string& cat,  const mol::string& n, T& t, typename prop::Selection<T>::SelectPropVector& v )
	{
		static std::string empty("");
		prop::Category& c = category(cat);
		c.add( new prop::SelectProp<T>(n,this,t,v,empty)  );
		return c;
	}

	prop::Category& addVBProperty( const mol::string& cat, const mol::string& n, VARIANT_BOOL& t);
	prop::Category& addProperty( const mol::string& cat, const mol::string& n, mol::bstr& t);
	prop::Category& addProperty( const mol::string& cat, const mol::string& n, mol::bstr& t, const std::string& v);

	prop::AbstractProp* inEdit();

	int cnt();
	int spin();
	int rowHeight();
	int borderWidth();

	COLORREF backgroundColor();
	HBRUSH   backgroundBrush();
	HBRUSH   blackBrush();

	HFONT font()   { return font_; }
	HFONT bfont()  { return bfont_; }

private:

	prop::Category& category(const mol::string& cat);
	void add( prop::AbstractProp* prop);
	
	int borderWidth_;
	int rowHeight_;
	int spin_;

	HCURSOR cur_;
	HFONT font_;
	HFONT bfont_;
	HBRUSH backgroundBrush_;

	prop::AbstractProp* inEdit_;
	bool dragging_;

	PropMap props_;
};



namespace prop {

class EditProp : public AbstractProp
{
public:

	EditProp( const mol::string& n, PropWindow* propWnd, const std::string& validate );

	virtual void startEdit(HWND parent);
	virtual void stopEdit();

protected:

	std::string validator_;
	mol::Control<mol::ReditBox<IDM_EDIT_DONE>,WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL,0> edit_;
};


template<class T>
class Prop : public EditProp
{
public:

	Prop( const mol::string& n, PropWindow* propWnd,  T& t, const std::string& validate )
		: EditProp( n, propWnd, validate ), value_(t)
	{}

	virtual mol::string getValueAsString()
	{
		mol::ostringstream oss;
		oss << value_;
		return oss.str();
	}

	virtual void setValueFromString(const mol::string& s)
	{
		if ( !validator_.empty() )
		{
			mol::RegExp regex( validator_);

			if ( !regex.match( mol::tostring(s)  ) )
			{
				return;
			}
		}
		mol::istringstream iss(s);
		iss >> value_;
	}

protected:

	T& value_;
};


template<>
class Prop<mol::string> : public EditProp
{
public:

	Prop( const mol::string& n, PropWindow* propWnd, mol::string& t, const std::string& validate )
		:EditProp( n, propWnd, validate), value_(t)
	{}


	virtual mol::string getValueAsString()
	{
		return value_;
	}

	virtual void setValueFromString(const mol::string& s)
	{
		if ( !validator_.empty() )
		{
			mol::RegExp regex( validator_);

			if ( !regex.match( mol::tostring(s)  ) )
			{
				return;
			}
		}
		value_ = s;
	}

protected:

	mol::string& value_;
};

template<>
class Prop<mol::bstr> : public EditProp
{
public:

	Prop( const mol::string& n, PropWindow* propWnd, mol::bstr& t, const std::string& validate )
		:EditProp( n, propWnd, validate), value_(t)
	{}


	virtual mol::string getValueAsString()
	{
		return value_.toString();
	}

	virtual void setValueFromString(const mol::string& s)
	{
		if ( !validator_.empty() )
		{
			mol::RegExp regex( validator_);

			if ( !regex.match( mol::tostring(s)  ) )
			{
				return;
			}
		}
		value_ = mol::bstr(s);
	}

protected:

	mol::bstr& value_;
};


template<>
class Prop<mol::variant> : public EditProp
{
public:
	
	Prop( const mol::string& n, PropWindow* propWnd,  mol::variant& t, const std::string& validate )
		:EditProp(n, propWnd, validate ), value_(t)
	{}

	virtual mol::string getValueAsString()
	{
		mol::ostringstream oss;

		mol::variant v(value_);
		v.changeType(VT_BSTR);	

		oss << mol::toString(v.bstrVal);
		return oss.str();
	}

	virtual void setValueFromString(const mol::string& s)
	{
		if ( !validator_.empty() )
		{
			mol::RegExp regex( validator_);

			if ( !regex.match( mol::tostring(s)  ) )
			{
				return;
			}
		}

		mol::variant v(s);
		v.changeType(value_.vt);

		if ( v.vt == value_.vt )
			value_ = v;
	}

protected:

	mol::variant& value_;
};


template<class T>
class SelectProp : public Prop<T>
{
public:

	SelectProp( const mol::string& n, PropWindow* propWnd, T& t,  const std::string& validate )
		:Prop<T>(n,propWnd,t,validate)
	{
		
	}

	SelectProp( const mol::string& n, PropWindow* propWnd, T& t, typename Selection<T>::SelectPropVector& values, const std::string& validate )
		:Prop<T>(n,propWnd,t,validate)
	{
		values_ = values;
	}

	virtual void startEdit(HWND parent)
	{
		int h = propWnd_->rowHeight();
		int o = propWnd_->borderWidth();

		mol::Rect r(rValue_.left+1, rValue_.top+1, rValue_.right-rValue_.left-2, h-2+100);
		box_.create((HMENU)IDC_PROP_EDIT,r,parent);

		for ( size_t i = 0; i < values_.size(); i++ )
		{
			box_.addString( values_[i].second );
		}

		int idx = getValueIndex(value_);
		if ( idx != -1 )
			box_.setCurSel(idx);

		box_.show(SW_SHOW);
		box_.setFocus();
	}


	virtual void stopEdit()
	{
		box_.show(SW_HIDE);

		int cursel = box_.getCurSel();
		if ( cursel != -1 )
		{

			mol::string tmp = box_.getString(cursel);
			setValueFromString(tmp);
		}

		box_.destroy();
	}

	int getValueIndex(T& t)
	{
		for ( size_t i = 0; i < values_.size(); i++ )
		{
			if ( t == values_[i].first )
			{
				return i;
			}
		}
		return -1;
	}

protected:

	mol::Control<mol::ComboBox,WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST|CBS_AUTOHSCROLL,0> box_;
	typename Selection<T>::SelectPropVector values_; 
};

class BoolProp : public SelectProp<bool>
{
public:

	BoolProp( const mol::string& n, PropWindow* propWnd, bool& t, const std::string& validate )
		:SelectProp<bool>(n,propWnd,t,validate)
	{
		values_.addProperty( false, _T("false") ); 
		values_.addProperty( true, _T("true") );
	}
};


class VariantBoolProp : public SelectProp<short>
{
public:

	VariantBoolProp( const mol::string& n, PropWindow* propWnd, short& t, const std::string& validate )
		:SelectProp<short>(n,propWnd,t,validate)
	{
		values_.addProperty( VARIANT_FALSE, _T("false") ); 
		values_.addProperty( VARIANT_TRUE, _T("true") );
	}
};

class Category: public AbstractProp
{
public:

	Category( PropWindow* propWnd, const mol::string& n);

	void add( AbstractProp* p)
	{
		props_.insert( std::make_pair(p->name(),p) );
	}

	virtual void startEdit(HWND parent)
	{
		collapsed_ = !collapsed_;
		::InvalidateRect(parent,0,TRUE);
	}

	virtual void stopEdit()
	{
		collapsed_ = !collapsed_;
	}

	virtual int cnt()
	{
		return props_.size() + 1;
	}

	virtual int markerWidth()
	{
		return w_;
	}

	virtual void draw( mol::win::DCbase& dc, RECT& r, int& offset );

	virtual AbstractProp* hitTest( POINT& pos, HWND parent );

private:

	int w_;
	bool collapsed_;
	mol::Rect rMarker_;
	std::map<mol::string,AbstractProp*> props_;
};

} // end namespace prop
} // end namespace mol

#undef IDM_EDIT_DONE
#undef IDC_PROP_EDIT

#endif