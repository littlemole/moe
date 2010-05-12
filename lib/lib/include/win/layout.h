#ifndef MOL_DEF_GUARD_LAYOUT_DEF_H_
#define MOL_DEF_GUARD_LAYOUT_DEF_H_

#pragma once

#include "win/coctrl.h"
#include <vector>

namespace mol {
namespace win {

//////////////////////////////////////////////////////////////////////
// layoutable Widget Adapter
//////////////////////////////////////////////////////////////////////

class Widget
{
public:
	Widget() : wnd(0) {};
	virtual ~Widget() {};
	void virtual layout( mol::Rect& r ) = 0;

	HWND wnd;
	mol::Rect padding;

	unsigned int widgets();

	Widget* widget(unsigned int index);

	void remove(HWND w);

protected:
	std::vector<Widget*>	widgets_;
};

} // end namespace win

//////////////////////////////////////////////////////////////////////
// LayoutMgr
//////////////////////////////////////////////////////////////////////

class LayoutMgr : public win::Widget
{
public:

	LayoutMgr();
	virtual ~LayoutMgr();

	LRESULT OnSize( UINT msg, WPARAM wParam, LPARAM lParam);
	void virtual layout( mol::Rect& r );

	template<class T>
	T* addLayout( T* layout )
	{
		widgets_.push_back( layout );
		return layout;
	}

	void addToolBar( mol::ToolBar* tb );
	void addRebar( mol::ReBar* rb );
	void addStatusBar( mol::StatusBar * sb );

	void resize(WPARAM wParam, LPARAM lParam);

	mol::Rect& clientRect()
	{
		return clientRect_;
	}

	mol::Rect availClientRect(mol::Rect& r);
	mol::Rect availBorderRect(mol::Rect& r);

protected:
	mol::ToolBar*          toolbar_;
	mol::StatusBar*        statusbar_;
	mol::ReBar*			   rebar_;
	mol::Rect		  	   clientRect_;
};

//////////////////////////////////////////////////////////////////////
// Border Layout
//////////////////////////////////////////////////////////////////////

class BorderLayout : public LayoutMgr
{
public:
	enum BORDER { FILL, NORTH, EAST, SOUTH, WEST } ;

	void add( HWND w, BORDER b, mol::Rect padding = mol::Rect(0,0,0,0) );

protected:

	class BorderLayoutWidget : public Widget
	{
		public:
			BorderLayoutWidget( HWND w, BORDER b, mol::Rect p);

			void virtual layout( mol::Rect& r );	

			BORDER border;
	};

};

//////////////////////////////////////////////////////////////////////
// Row Layout
//////////////////////////////////////////////////////////////////////

class RowLayout : public LayoutMgr
{
public:
	enum TYPE  { HORIZONTAL, VERTICAL } ;
	enum STYLE { FILL, CENTER } ;

	RowLayout( TYPE t )
		: type(t)
	{}

	void virtual layout( mol::Rect& r );

	void add( HWND w, STYLE s, mol::Rect padding = mol::Rect(0,0,0,0) );

protected:

	TYPE type;

	class RowLayoutWidget : public Widget
	{
		public:
			RowLayoutWidget( HWND w, STYLE s, mol::Rect p);
			void virtual layout( mol::Rect& r );
		
			STYLE style;	
	};
};

//////////////////////////////////////////////////////////////////////
// FillLayout
//////////////////////////////////////////////////////////////////////

class FillLayout : public BorderLayout
{
public:
	virtual void layout( mol::Rect& r );

	void add( HWND w,  mol::Rect padding  = mol::Rect(0,0,0,0) );

protected:
	class FillLayoutWidget : public BorderLayoutWidget
	{
		public:
			FillLayoutWidget( HWND w, mol::Rect p);

			void virtual layout( mol::Rect& r );	

			BORDER border;
	};
};


} // end namespace mol

#endif