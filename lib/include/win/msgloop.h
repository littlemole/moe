#ifndef MOL_MSG_MSGLOOP_DEF_DEFINE_GUARD_DEFINE_
#define MOL_MSG_MSGLOOP_DEF_DEFINE_GUARD_DEFINE_


////////////////////////////////////////////////////////////////////////////////////////////
namespace mol {
namespace win {


////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

class Accelerators
{
friend class mol::Singleton<Accelerators>;
public:

	bool translate( MSG& msg )
	{
		for ( 
				std::map<HWND,HACCEL>::iterator it = accellerators_.begin();
				it != accellerators_.end();
				it++
			 )
		{
			if ( ::TranslateAccelerator( (*it).first, (*it).second, &msg ) )
				return true;
		}
		return false;
	}

	HACCEL load(int n, HWND hWnd)
	{
		HACCEL hAccel = ::LoadAccelerators( hinstance(), MAKEINTRESOURCE(n) );
		accellerators_.insert( std::make_pair(hWnd,hAccel) );
		return hAccel;
	}

private:

	Accelerators() {}
	~Accelerators() {}

	std::map<HWND,HACCEL> accellerators_;
};

inline Accelerators& accelerators()
{
	return mol::Singleton<Accelerators>::instance();
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////


class Dialogs
{
friend class mol::Singleton<Dialogs>;
public:

	bool isDialogMessage( MSG& msg )
	{
		for ( 
				std::set<HWND>::iterator it = dialogs_.begin();
				it != dialogs_.end();
				it++
			 )
		{
			if ( ::IsDialogMessage( *it, &msg) )
				return true;
		}
		return false;
	}

	void registerDialog(HWND dlg)
	{
		dialogs_.insert(dlg);
	}

	void unregisterDialog(HWND dlg)
	{
		if ( dialogs_.count(dlg) > 0 )
		{
			dialogs_.erase(dlg);
		}
	}

private:

	Dialogs() {}
	~Dialogs() {}

	std::set<HWND> dialogs_;
};

inline Dialogs& dialogs()
{
	return mol::Singleton<Dialogs>::instance();
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////


class TabToolTips
{
friend class mol::Singleton<TabToolTips>;
public:

	bool tabToolNotify( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
	{
		if ( tabs_.count(hWnd) > 0 )
		{
			::SendMessage( tabs_[hWnd],msg,wParam,lParam );
			return true;
		}
		return false;
	}

	void registerTab(HWND tool,HWND tab)
	{
		tabs_.insert( std::make_pair(tool,tab) );
	}

	void unregisterTab(HWND tool)
	{
		if ( tabs_.count(tool) > 0 )
		{
			tabs_.erase(tool);
		}
	}

private:

	TabToolTips() {}
	~TabToolTips() {}

	std::map<HWND,HWND>	tabs_;
};

inline TabToolTips& tabToolTips()
{
	return mol::Singleton<TabToolTips>::instance();
}

} // end namespace win
} // end namespace mol

#endif