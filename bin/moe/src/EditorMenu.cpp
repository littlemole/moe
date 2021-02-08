#include "stdafx.h"
#include "EditorMenu.h"
#include "editor.h"
#include "moe.h"
//#include "xmlui.h"
#include "ribbonres.h"

EditorMenu::EditorMenu(void)
{
}

EditorMenu::EditorMenu(Editor* e)
{
	editor_ = e;
}



EditorMenu::~EditorMenu(void)
{
}

void EditorMenu::updateUI()
{
	if ( !editor_->sci )
	{
		return;
	}

	Json::Value json(Json::objectValue);
	json["doctype"] = MOE_DOCTYPE_DOC;
	json["appmode"] = "Scintilla";

	mol::bstr path;
	HRESULT hr = editor_->props_->get_Filename(&path);
	if ( hr != S_OK )
		return;

	std::wstring title = path.towstring();

	json["filename"] = mol::toUTF8(title);

	long line=0;
	editor_->line_->Current(&line);
	std::wostringstream oss;
	oss << line;

	long pos = 0;
	long linepos = 0;
	editor_->position_->get_Caret(&pos);
	editor_->line_->PosFromLine(line-1,&linepos);

	long col = pos-linepos;
	std::wostringstream oss2;
	oss2 << col << " ";

	std::wstring dirty(_T(""));
	VARIANT_BOOL vb = VARIANT_FALSE;
	hr = editor_->text_->get_Modified(&vb);
	if ( vb == VARIANT_TRUE )
	{
		dirty = _T("modified");
	}
	else
	{
		dirty = _T("not modified");
	}

	statusBar()->setText(path.towstring(), dirty, oss.str(), oss2.str());

	long encoding;
	if ( S_OK == editor_->props_->get_Encoding(&encoding) )
	{
		size_t idx = codePages()->index(encoding);
		Encodings::CodePage enc = codePages()->item((int)idx);
		std::wstring cp = enc.second;

		json["encoding"] = encoding;
		json["codepage"] = mol::toUTF8(cp);

		switch ( encoding )
		{
			case SCINTILLA_ENCODING_UTF16 :
			{
				title += _T(" - UTF16-LE");
				break;
			}
			case SCINTILLA_ENCODING_UTF8 :
			{
				title += _T(" - UTF8");
				break;
			}
			default:
			{
				title += _T(" ");
				break;
			}
		}

/*		if ( mol::Ribbon::ribbon()->enabled())
		{
			mol::Ribbon::handler(RibbonEncoding)->select((int)codePages()->index((int)encoding));
		}
*/
	}
	
	long systype;
	if ( S_OK == editor_->props_->get_SysType(&systype) )
	{
		json["systype"] = systype;
		if ( systype ==  SCINTILLA_SYSTYPE_UNIX )
		{
			title += _T(" UNIX");
/*
			if ( mol::Ribbon::ribbon()->enabled())
			{
				mol::Ribbon::handler(RibbonSelectModeUnix)->check(true); 
				mol::Ribbon::handler(RibbonSelectModeWin32)->check(false); 
			}
*/
		}
		else
		{
			title += _T(" WIN32");
/*
			if ( mol::Ribbon::ribbon()->enabled())
			{
				mol::Ribbon::handler(RibbonSelectModeUnix)->check(false); 
				mol::Ribbon::handler(RibbonSelectModeWin32)->check(true); 
			}
*/
		}
	}

	LONG type = 0;
	editor_->props_->get_Syntax(&type);
	json["syntax"] = type;

//	mol::UI().Wnd<MoeComboBox>(IDW_SYNTAX_BOX)->setCurSel(type);
	/*
	if ( mol::Ribbon::ribbon()->enabled())
	{
		mol::Ribbon::handler(RibbonSelectLanguage)->select(type);
	}
	*/
	if ( S_OK == editor_->props_->get_ReadOnly(&vb) )
	{
		if (vb == VARIANT_TRUE)
		{
			title += _T(" [ReadOnly]");
			json["readonly"] = true;
		}
		else
		{
			json["readonly"] = false;
		}
	}
	editor_->setText(title);


	//if ( mol::Ribbon::ribbon()->enabled())
	{
		if (S_OK == moe()->moeConfig->get_ShowTreeView(&vb))
		{
			json["showTreeView"] = vb == VARIANT_TRUE ? true : false;
			//mol::Ribbon::handler(RibbonTabUseTabs)->check(vb == VARIANT_TRUE ? true : false );
		}

		if ( S_OK == editor_->props_->get_TabUsage(&vb) )
		{
			json["tabUsage"] = vb == VARIANT_TRUE ? true : false;
			//mol::Ribbon::handler(RibbonTabUseTabs)->check(vb == VARIANT_TRUE ? true : false );
		}
		if ( S_OK == editor_->props_->get_TabIndents(&vb) )
		{
			json["tabIndents"] = vb == VARIANT_TRUE ? true : false;
			//mol::Ribbon::handler(RibbonTabIndents)->check(vb == VARIANT_TRUE ? true : false );
		}
		if ( S_OK == editor_->props_->get_BackSpaceUnindents(&vb) )
		{
			json["backSpaceUnindents"] = vb == VARIANT_TRUE ? true : false;
			//mol::Ribbon::handler(RibbonTabBackSpaceUnIndents)->check(vb == VARIANT_TRUE ? true : false );
		}
		long w = 0;
		if ( S_OK == editor_->props_->get_TabWidth(&w) )
		{
			json["tabWidth"] = w;
			DECIMAL d;
			::ZeroMemory(&d,sizeof(d));
			d.Lo32 = w;

			VARIANT v;
			::VariantInit(&v);
			v.vt = VT_DECIMAL;
			v.decVal = d;

			mol::variant var(v);

			//mol::Ribbon::handler(RibbonTabSize)->decimal(var);

			::VariantClear(&v);
		}
		if ( S_OK == editor_->props_->get_WriteBOM(&vb) )
		{
			json["writeBOM"] = vb == VARIANT_TRUE ? true : false;
			//mol::Ribbon::handler(RibbonWriteBOM)->check(vb == VARIANT_TRUE ? true : false );
		}
	}


	if ( S_OK != editor_->props_->get_ShowLineNumbers(&vb) )
		return;

	json["showLineNumbers"] = vb == VARIANT_TRUE ? true : false;
	/*
	if ( mol::Ribbon::ribbon()->enabled() )
	{
		bool  b = vb == VARIANT_TRUE ? true : false;
		mol::Ribbon::handler(RibbonShowLineNumbers)->check(b);
	}
	else
	*/
	/*
	{

		mol::Menu mode(mol::UI().SubMenu(IDM_MOE,IDM_MODE));

		if ( vb == VARIANT_TRUE )
			mode.checkItem( IDM_MODE_SHOW_LINE_NUMBERS );
		else
			mode.unCheckItem( IDM_MODE_SHOW_LINE_NUMBERS );
	}
	*/
	if (!editor_->debugger_)
	{		
		//mol::Ribbon::ribbon()->mode(1);		
	}
	else
	{
		json["appmode"] = "Debug";
		debugDlg()->show(SW_SHOW);
		//mol::Ribbon::ribbon()->mode(9);		
	}
	//mol::Ribbon::ribbon()->maximize();


	std::string utf8 = JSON::flatten(json);
	ribbon()->webView->PostWebMessageAsJson(mol::fromUTF8(utf8).c_str());
}

void EditorMenu::createMenuFromConf(HMENU m,HMENU popup)
{
	HMENU frameMenu = mol::UI().Menu(IDM_MOE);

	HMENU tools =   mol::UI().SubMenu(IDM_MOE,IDM_TOOLS);
	mol::Menu mode (mol::UI().SubMenu(IDM_MOE,IDM_MODE_EOL));
	mol::Menu debug(mol::UI().SubMenu(IDM_MOE,IDM_EDIT_DEBUG));

	if ( popup == mode )
	{
		updateModeMenu(mode);
		return;
	}

	if ( popup == debug )
	{
		updateDebugMenu(debug);
	}

	if ( popup != tools )
		return;

	updateToolMenu(tools);

	/*
	if ( !mol::Ribbon::ribbon()->enabled())
	*/
		::DrawMenuBar(*moe()); 
	::UpdateWindow(*moe()); 

}


void EditorMenu::updateModeMenu( mol::Menu& mode )
{
	mode.enableItem(IDM_MODE_UNIX);

	if ( !editor_->sci )
		return;

	long systype;
	if ( S_OK == editor_->props_->get_SysType(&systype) )
	{
		if ( systype == SCINTILLA_SYSTYPE_WIN32 )
		{
			mode.unCheckItem(IDM_MODE_UNIX);
			mode.checkItem(IDM_MODE_WIN32);
		}
		else
		{
			mode.unCheckItem(IDM_MODE_WIN32);
			mode.checkItem(IDM_MODE_UNIX);
		}
	}
	long encoding;
	if ( S_OK == editor_->props_->get_Encoding(&encoding) )
	{
		if ( encoding == SCINTILLA_ENCODING_UTF16 )
		{
			mode.disableItem(IDM_MODE_UNIX);
		}
	}

}

void EditorMenu::updateToolMenu( HMENU tools )
{
	int startShortCutId_ = ID_FIRST_USER_CMD;
	int startScriptId_   = ID_FIRST_USER_SCRIPT;
	int startBatchId_    = ID_FIRST_USER_BATCH;
	int startFormId_     = ID_FIRST_USER_FORM;

	editor_->shortCutMap.clear();
	editor_->scriptMap.clear();
	editor_->batchMap.clear();
	editor_->formMap.clear();

	mol::punk<ISetting> shortCuts;
	mol::punk<ISetting> scripts;
	mol::punk<ISetting> batches;
	mol::punk<ISetting> forms;

	mol::punk<IDispatch> disp;
	moe()->moeConfig->get_Settings(&disp);	
	mol::punk<ISetting> config(disp);

	if ( S_OK != config->Item(mol::variant("shortCuts"),&shortCuts) )
		return;

	if ( S_OK != config->Item(mol::variant("scripts"),&scripts) )
		return;

	if ( S_OK != config->Item(mol::variant("batches"),&batches) )
		return;

	if ( S_OK != config->Item(mol::variant("forms"),&forms) )
		return;

	int n = ::GetMenuItemCount(tools);
	for ( int j = 0; j < 4; j++ )
	{
		HMENU sub = ::GetSubMenu(tools,n-j-1);
		mol::Menu subMenu(sub);
		int nsub = ::GetMenuItemCount(sub);
		for ( int k = nsub-1; k >= 0; k-- )
		{
			subMenu.remove(k,MF_BYPOSITION);
		}
	}

	HMENU ms = mol::UI().SubMenu(IDM_MOE,IDM_USER_SCRIPT);
	populateMenuFromConf( ms, scripts, editor_->scriptMap,startScriptId_);

	HMENU mb = mol::UI().SubMenu(IDM_MOE,IDM_USER_BATCH);
	populateMenuFromConf( mb, batches, editor_->batchMap,startBatchId_);			

	HMENU mf = mol::UI().SubMenu(IDM_MOE,IDM_USER_FORM);
	populateMenuFromConf( mf, forms, editor_->formMap,startFormId_);			
	
	HMENU msc = mol::UI().SubMenu(IDM_MOE,IDM_USER_SHORTCUT);
	populateMenuFromConf( msc, shortCuts, editor_->shortCutMap,startShortCutId_);			


}

void EditorMenu::updateDebugMenu( HMENU debug )
{
	mol::Menu menu(debug);
	//menu.disableItem(IDM_EDIT_DEBUG_GO);
	menu.disableItem(IDM_EDIT_DEBUG_STEPIN);
	menu.disableItem(IDM_EDIT_DEBUG_STEPOVER);
	menu.disableItem(IDM_EDIT_DEBUG_STEPOUT);
	menu.disableItem(IDM_EDIT_DEBUG_STOP);
	menu.disableItem(IDM_EDIT_DEBUG_QUIT);
	
	if ( editor_->debugger_ && editor_->debugger_->suspended() )
	{
		menu.enableItem(IDM_EDIT_DEBUG_STEPIN);
		menu.enableItem(IDM_EDIT_DEBUG_STEPOVER);
		menu.enableItem(IDM_EDIT_DEBUG_STEPOUT);
		menu.enableItem(IDM_EDIT_DEBUG_QUIT);
		return;
	}

	if ( editor_->debugger_ )
	{
		menu.enableItem(IDM_EDIT_DEBUG_STOP);
		menu.enableItem(IDM_EDIT_DEBUG_QUIT);
		return;
	}
}

void EditorMenu::walkConf(HMENU parent, ISetting* set, std::map<int,ISetting*>& confMap, int& id)
{
    if ( !set )
		return;

    long l;
	mol::bstr key;
	if ( S_OK != set->get_Key(&key) )
		return;

	if ( S_OK != set->Count(&l) )
		return;

	if ( l <= 0 ) 
	{
		mol::win::MenuItemInfo* inf = new mol::win::MenuItemInfo(key.towstring().c_str(), false, -1, 0);
		::AppendMenu( parent, MF_OWNERDRAW, (UINT_PTR)id, (wchar_t*)inf);
		confMap[id] = (ISetting*)set;
		id++;
		return;
	}

	HMENU m = ::CreateMenu();
	mol::win::MenuItemInfo* inf = new mol::win::MenuItemInfo(key.towstring().c_str(), false, -1, 0);
	::AppendMenu( parent, MF_POPUP|MF_OWNERDRAW, (UINT_PTR)m, (wchar_t*)inf);

	for ( long i = 0; i < l; i++ )
	{
		mol::punk<ISetting> s;
		if ( S_OK != set->Item(mol::variant(i),&s) )
			continue;

		if ( !s )
			continue;

		walkConf(m,s,confMap,id);
	}
}


void EditorMenu::populateMenuFromConf( HMENU submenu, ISetting* set, std::map<int,ISetting*>& confMap, int& id)
{
	long l;
	if ( S_OK == set->Count(&l) )
	{
		for ( long i = 0; i < l; i++ )
		{
			mol::punk<ISetting> s;
			if ( S_OK == set->Item(mol::variant(i),&s) )
			{
				walkConf(submenu,s,confMap,id);
			}
		}
	}
}


void EditorMenu::onMenu(HMENU popup, LPARAM unused)
{
	HMENU frameMenu = mol::UI().Menu(IDM_MOE);

	if ( popup == mol::UI().SubMenu(IDM_MOE,IDM_MODE_EOL) )
		createMenuFromConf(frameMenu,popup);
	else
	if ( popup == mol::UI().SubMenu(IDM_MOE,IDM_TOOLS) )
		createMenuFromConf(frameMenu,popup);
	else
	if ( popup == mol::UI().SubMenu(IDM_MOE,IDM_EDIT_DEBUG) )
		createMenuFromConf(frameMenu,popup);
}