#include "stdafx.h"
#include "EditorMenu.h"
#include "editor.h"
#include "moe.h"

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

		json["encoding"] = (int)encoding;
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
	}
	
	long systype;
	if ( S_OK == editor_->props_->get_SysType(&systype) )
	{
		json["systype"] = (int)systype;
		if ( systype ==  SCINTILLA_SYSTYPE_UNIX )
		{
			title += _T(" UNIX");
		}
		else
		{
			title += _T(" WIN32");
		}
	}

	LONG type = 0;
	editor_->props_->get_Syntax(&type);
	json["syntax"] = (int)type;

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


	if (S_OK == moe()->moeConfig->get_ShowTreeView(&vb))
	{
		json["showTreeView"] = vb == VARIANT_TRUE ? true : false;
	}

	if ( S_OK == editor_->props_->get_TabUsage(&vb) )
	{
		json["tabUsage"] = vb == VARIANT_TRUE ? true : false;
	}

	if ( S_OK == editor_->props_->get_TabIndents(&vb) )
	{
		json["tabIndents"] = vb == VARIANT_TRUE ? true : false;
	}

	if ( S_OK == editor_->props_->get_BackSpaceUnindents(&vb) )
	{
		json["backSpaceUnindents"] = vb == VARIANT_TRUE ? true : false;
	}

	long w = 0;
	if ( S_OK == editor_->props_->get_TabWidth(&w) )
	{
		json["tabWidth"] = (int)w;
		DECIMAL d;
		::ZeroMemory(&d,sizeof(d));
		d.Lo32 = w;

		VARIANT v;
		::VariantInit(&v);
		v.vt = VT_DECIMAL;
		v.decVal = d;

		mol::variant var(v);
		::VariantClear(&v);
	}

	if ( S_OK == editor_->props_->get_WriteBOM(&vb) )
	{
		json["writeBOM"] = vb == VARIANT_TRUE ? true : false;
	}

	if ( S_OK != editor_->props_->get_ShowLineNumbers(&vb) )
		return;

	json["showLineNumbers"] = vb == VARIANT_TRUE ? true : false;

	if (!editor_->debugger_)
	{		
	}
	else
	{
		json["appmode"] = "Debug";
		debugDlg()->show(SW_SHOW);
	}

	std::string utf8 = JSON::flatten(json);
	ribbon()->webView->PostWebMessageAsJson(mol::fromUTF8(utf8).c_str());
}

