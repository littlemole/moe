#pragma once

#include "shared.h"
#include "resource.h"
#include "MoeBar.h"
#include "win/io.h"

class Editor;

class EditorMenu
{
public:
	EditorMenu(void);
	EditorMenu(Editor* e);
	~EditorMenu(void);

	void updateUI();		
	void createMenuFromConf(HMENU m,HMENU popup);
	void onMenu(HMENU popup, LPARAM unused);

private:

	void walkConf(HMENU parent, ISetting* set, std::map<int,ISetting*>& confMap, int& id);
	void updateModeMenu( mol::Menu& mode );
	void updateToolMenu( HMENU tools );
	void updateDebugMenu( HMENU debug );
	void populateMenuFromConf( HMENU submenu, ISetting* set, std::map<int,ISetting*>& confMap, int& id);

	Editor* editor_;
};

