#include "stdafx.h"
#include "rtf.h"
#include "moe.h"
#include "docs.h"
#include "MoeBar.h"

#include "xmlui.h"
#include "ribbonres.h"


REFIID mol::uuid_info<IRichEditOleCallback>::uuidof = IID_IRichEditOleCallback;


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

RTFEditor::RTFEditor()
{
	wndClass().setIcon(moe()->icon); 
	wndClass().hIconSm(moe()->icon); 

	findText_.chrg.cpMin = 0;
	findText_.chrg.cpMax = -1;
	findText_.lpstrText = 0;

	shuttingDown_ = false;

	rtfDocument_.QueryInterface(IID_IUnknown,(void**)&oleObject);
}

RTFEditor::~RTFEditor() 
{
	ODBGS("~RTFedit dead");	
};

RTFEditor::Instance* RTFEditor::CreateInstance( const std::wstring& file )
{
	Instance* iv = new Instance;
	iv->AddRef();

	iv->initializeMoeChild(file);
	if ( !iv->load(file) )
	{
		iv->Release();
		return 0;
	}
	statusBar()->status(100);
	return iv;
}

handle_msg(&RTFEditor::OnCreate,WM_CREATE)
void RTFEditor::OnCreate()
{
	RECT r;
	getClientRect(r);

	rtf_.create(0,r,hWnd_);
	rtf_.show(SW_SHOW);

	rtf_.notify(ENM_CHANGE|ENM_LINK|ENM_SELCHANGE|ENM_MOUSEEVENTS|ENM_KEYEVENTS);
	rtf_.sendMessage(EM_AUTOURLDETECT,TRUE,0);

	rtf_.sendMessage(EM_SETOLECALLBACK,0,(LPARAM)(IRichEditOleCallback*)&reolecb_);

	rtf_.sendMessage(EM_GETOLEINTERFACE, 0, (LPARAM)(IRichEditOle**)(&richEditOle));

}
//////////////////////////////////////////////////////////////////////////////

handle_msg(&RTFEditor::OnClose, WM_CLOSE)
LRESULT RTFEditor::OnClose()
{
	if ( moe()->activeObject )
	{
		if ( richEditOle )
		{
			richEditOle->InPlaceDeactivate();
			return 1;
		}
	}
	this->destroy();
	return 0;
}


handle_msg(&RTFEditor::OnDestroy, WM_DESTROY)
LRESULT RTFEditor::OnDestroy()
{
	shuttingDown_ = true;
	return 0;
}


handle_msg(&RTFEditor::OnNcDestroy, WM_NCDESTROY)
LRESULT RTFEditor::OnNcDestroy()
{
	oleObject.release();
	richEditOle.release();

	docs()->remove(this);
	thumb.destroy();
	::CoDisconnectObject(((IMoeDocument*)this),0);
	((IMoeDocument*)this)->Release();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////


handle_msg(&RTFEditor::OnPaint, WM_PAINT)
void RTFEditor::OnPaint()
{
	mol::PaintDC dc(*this);

	RECT r;
	getClientRect(r);
	dc.fillRect(r,(HBRUSH)::GetStockObject(BLACK_BRUSH));
}


handle_msg(&RTFEditor::OnSize, WM_SIZE)
LRESULT RTFEditor::OnSize(UINT msg, WPARAM wParam, LPARAM lParam)
{
	mol::Crack message(msg,wParam,lParam) ;
	rtf_.move(0,0,message.lPoint().x,message.lPoint().y);
	return BaseWindowType::OnSize(msg,wParam,lParam);
}

//////////////////////////////////////////////////////////////////////////////

handle_msg(&RTFEditor::OnMDIActivate, WM_MDIACTIVATE)
void RTFEditor::OnMDIActivate( WPARAM unused, HWND activated)
{
	if ( activated != *this )
	{
		if ( moe()->activeObject )
			moe()->activeObject->OnDocWindowActivate(false);

		
		mol::punk<IOleInPlaceFrame> frame;
		moe()->axFrameSite.queryInterface(&frame);
		if ( frame )
		{
			frame->SetBorderSpace(0);
		}
		
		if ( richEditOle )
		{
			richEditOle->InPlaceDeactivate();
		}
		
		ribbon()->setAppMode("Rtf");
	}
	else 
	{
		if (!shuttingDown_)
		{
			tab()->select( *this );

			ribbon()->setAppMode("Rtf");
		}
	}
}

handle_cmd(&RTFEditor::OnSave, IDM_FILE_SAVE)
void RTFEditor::OnSave()
{
	std::string tmp;
	rtf_.streamOut(tmp,SF_RTF);

	mol::filestream fs;

	if ( fs.open( mol::tostring(filename_)) )
	{
		fs.write( tmp.c_str(), tmp.size() );
		fs.flush();
		fs.close();
	}

	statusBar()->status(_T("saved file"));
}

handle_cmd(&RTFEditor::OnSaveAs, IDM_FILE_SAVE_AS)
void RTFEditor::OnSaveAs()
{
	mol::bstr p;

	static wchar_t  OutFilesFilter[] = _T("save as rtf *.rtf\0*.rtf\0save as file*.*\0*.*\0\0");


	mol::FilenameDlg ofn(*this);
	ofn.setFilter( OutFilesFilter );		
	ofn.fileName(filename_);

	if ( ofn.dlgSave( OFN_OVERWRITEPROMPT| OFN_NOTESTFILECREATE| OFN_NOVALIDATE) )
	{	
		filename_ = ofn.fileName();
		if ( ofn.index() == 1 )
		{
			
			OnSave();
		}
		else
		{
			std::string tmp;
			rtf_.streamOut(tmp);

			mol::filestream fs;

			if ( fs.open( mol::tostring(filename_)) )
			{
				fs.write( tmp.c_str(), tmp.size() );
				fs.flush();
				fs.close();
			}
			
			setText(filename_);
			statusBar()->status(_T("saved file"));
		}

		std::wostringstream oss;
		oss << "saved as " << filename_;
		statusBar()->status(oss.str());
		
	}
}

handle_cmd(&RTFEditor::OnCut, IDM_EDIT_CUT)
void RTFEditor::OnCut()
{
	rtf_.sendMessage(WM_CUT,0,0);
}

handle_cmd(&RTFEditor::OnCopy, IDM_EDIT_COPY)
void RTFEditor::OnCopy()
{
	rtf_.sendMessage(WM_COPY,0,0);
}

handle_cmd(&RTFEditor::OnPaste, IDM_EDIT_PASTE)
void RTFEditor::OnPaste()
{
	rtf_.sendMessage(WM_PASTE,0,0);
}

handle_cmd(&RTFEditor::OnUndo, IDM_EDIT_UNDO)
void RTFEditor::OnUndo()
{
	rtf_.sendMessage(EM_UNDO,0,0);
}

handle_cmd(&RTFEditor::OnRedo, IDM_EDIT_REDO)
void RTFEditor::OnRedo()
{
	rtf_.sendMessage(EM_REDO,0,0);
}

handle_cmd(&RTFEditor::OnPrint, IDM_FILE_PRINT)
void RTFEditor::OnPrint()
{
	rtf_.PrintRTF();
}

handle_cmd(&RTFEditor::OnSelectAll, IDM_EDIT_SELECT)
void RTFEditor::OnSelectAll()
{
	CHARRANGE rg;
	rg.cpMin = 0;
	rg.cpMax = -1;
	rtf_.sendMessage(EM_EXSETSEL,0,(LPARAM)&rg);
}

handle_cmd(&RTFEditor::OnFont, IDM_RIBBON_FONT_CTRL)
void RTFEditor::OnFont()
{
//	CHARFORMAT2& c2 = mol::Ribbon::handler(RibbonFontControl)->font();
//	rtf_.sendMessage( EM_SETCHARFORMAT, (WPARAM) SCF_SELECTION, (LPARAM)&c2);
}

handle_notify_code(&RTFEditor::OnFont, EN_SELCHANGE)
void RTFEditor::OnSelectionChange(SELCHANGE * selc)
{
	if ( !selc )
		return;

	int start = selc->chrg.cpMin;
	int end   = selc->chrg.cpMax;

	CHARFORMAT2 c2;
	::ZeroMemory(&c2,sizeof(c2));
	c2.cbSize = sizeof(c2);

	rtf_.sendMessage(EM_GETCHARFORMAT,(WPARAM)SCF_SELECTION,(LPARAM)&c2);
//	mol::Ribbon::handler(RibbonFontControl)->font() = c2;
	//mol::Ribbon::ribbon()->update(RibbonFontControl);
}

handle_cmd(&RTFEditor::OnInsertColorDialog, IDM_EDIT_COLOR)
void RTFEditor::OnInsertColorDialog(  )
{
	mol::punk<IColorPicker> col;
	col.createObject(CLSID_ColorDialog);

	if ( !col ) 
		return;

	VARIANT_BOOL vb = VARIANT_FALSE;
	if ( S_OK != col->Show( &vb) )
		return;

	if ( vb != VARIANT_TRUE )
		return;

	mol::bstr hex;
	if ( S_OK != col->get_HexColor(&hex) || hex.bstr_ == 0)
		return;

	std::wstring tmp = hex.towstring();
	rtf_.sendMessage(EM_REPLACESEL,(WPARAM)TRUE,(LPARAM) (tmp.c_str()) );

}

handle_msg(&RTFEditor::OnSearch, WM_SEARCH_MSG)
void RTFEditor::OnSearch( FINDREPLACE* find )
{
	CHARRANGE cr;
	rtf_.sendMessage( EM_EXGETSEL, 0 ,(LPARAM)&cr);

	if ( find->Flags & FR_DOWN )
	{
		int d = cr.cpMax;
		if ( cr.cpMax == -1 )
		{
			d = cr.cpMin;
		}

		findText_.chrg.cpMin = d;
		findText_.chrg.cpMax = -1;
	}
	else 
	{
		findText_.chrg.cpMin = cr.cpMin;
		findText_.chrg.cpMax = 0;

		if ( findText_.chrg.cpMin == 0 )
		{
			int w = (int)rtf_.sendMessage(WM_GETTEXTLENGTH,0,0);
			findText_.chrg.cpMin = w;
		}
	}

	findText_.lpstrText = find->lpstrFindWhat;

    if ( (find->Flags) & FR_FINDNEXT )
    {
		LRESULT r = rtf_.sendMessage( EM_FINDTEXT, find->Flags, (WPARAM)&findText_);
		if ( r == -1 )
		{
			statusBar()->status(_T("Search: not found"));

			CHARRANGE cr;
			int d = -1;
			if ( find->Flags & FR_DOWN )
			{
				d = 0;
			}

			cr.cpMin = d;
			cr.cpMax = d;
			rtf_.sendMessage( EM_EXSETSEL, 0 ,(LPARAM)&cr);
		}
		else 
		{
			CHARRANGE cr;
			cr.cpMin = (LONG)r;
			cr.cpMax = (LONG)(cr.cpMin + wcslen(find->lpstrFindWhat));
			rtf_.sendMessage( EM_EXSETSEL, 0 ,(LPARAM)&cr);
		}
    }
    if ( (find->Flags) & FR_REPLACE )
    {
		findText_.lpstrText = find->lpstrFindWhat;
		LRESULT r = rtf_.sendMessage( EM_FINDTEXT, find->Flags, (WPARAM)&findText_);
		if ( r == -1 )
		{
			statusBar()->status(_T("Search: not found"));

			CHARRANGE cr;
			int d = -1;
			if ( find->Flags & FR_DOWN )
			{
				d = 0;
			}

			cr.cpMin = d;
			cr.cpMax = d;
			rtf_.sendMessage( EM_EXSETSEL, 0 ,(LPARAM)&cr);
		}
		else 
		{
			CHARRANGE cr;
			cr.cpMin = (LONG)(findText_.chrg.cpMin + r);
			cr.cpMax = (LONG)(cr.cpMin + wcslen(find->lpstrFindWhat));
			rtf_.sendMessage( EM_EXSETSEL, 0 ,(LPARAM)&cr);
			rtf_.sendMessage(EM_REPLACESEL,(WPARAM)TRUE,(LPARAM) (find->lpstrReplaceWith) );
		}
    }
    if ( (find->Flags) & FR_REPLACEALL )
    {
		findText_.lpstrText = find->lpstrFindWhat;
		findText_.chrg.cpMin = 0;
		findText_.chrg.cpMax = -1;

		LRESULT r = 0 ;

		int i = 0;
		while ( r != -1 )
		{
			r = rtf_.sendMessage( EM_FINDTEXT, find->Flags, (WPARAM)&findText_);
			if ( r == -1 )
			{
				statusBar()->status(_T("Search: not found"));
				break;
			}

			i++;
			CHARRANGE cr;
			cr.cpMin = (LONG)(findText_.chrg.cpMin + r);
			cr.cpMax = (LONG)(cr.cpMin + wcslen(find->lpstrFindWhat));
			rtf_.sendMessage( EM_EXSETSEL, 0 ,(LPARAM)&cr);
			rtf_.sendMessage(EM_REPLACESEL,(WPARAM)TRUE,(LPARAM) (find->lpstrReplaceWith) );

		}

		std::wostringstream oss;
		oss << _T("Replace All: ") << i << _T(" replaces");
		statusBar()->status(oss.str());
    }

}

handle_notify_code(&RTFEditor::OnLink, EN_LINK)
void RTFEditor::OnLink(ENLINK* link)
{
	int start = link->chrg.cpMin;
	int end   = link->chrg.cpMax;

	mol::wbuff buf(end-start+2);
	buf[0] = 0;
	TEXTRANGE tr;
	tr.chrg = link->chrg;
	tr.lpstrText = buf;
	rtf_.sendMessage(EM_GETTEXTRANGE,0,(LPARAM)&tr);
	std::wstring tmp(buf.toString());

	statusBar()->status(mol::towstring(tmp));
	
	if (::GetAsyncKeyState(VK_SHIFT) && link->msg  == WM_LBUTTONDBLCLK )
	{
		mol::io::execute_shell(tmp);
	}
}


handle_notify_code(&RTFEditor::OnFilter, EN_MSGFILTER)
void RTFEditor::OnFilter(MSGFILTER* filter)
{
	if ( filter->msg ==  WM_RBUTTONDOWN )
	{
		POINT pt;
		::GetCursorPos(&pt);
//		mol::Ribbon::ribbon()->showContextualUI(RibbonRTFDocumentContextMap,pt.x,pt.y);
	}

}

handle_cmd(&RTFEditor::OnReload, IDM_EDIT_UPDATE)
void RTFEditor::OnReload()
{
	load(filename_);
}

handle_cmd(&RTFEditor::OnCloseAll, IDM_VIEW_CLOSEALL)


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// helpers
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

bool RTFEditor::load(const std::wstring& p)
{
	filename_ = p;

	if ( mol::Path::exists(p) )
	{
		mol::filestream fs;

		if ( fs.open( mol::tostring(p)) )
		{
			std::string tmp = fs.readAll();

			if (!tmp.empty())
			{
				rtf_.streamIn( tmp,SF_RTF );

			}
		}
	}	

	return true;
}


//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall RTFEditor::get_Object( IDispatch **d)
{
	if ( !d )
		return E_INVALIDARG;
	*d = 0;

	return rtfDocument_.QueryInterface(IID_IDispatch,(void**)d);
}

//////////////////////////////////////////////////////////////////////////////

HRESULT __stdcall RTFEditor::RTFDocument::get_Text( IDispatch** d)
{
	if (!d )
		return E_INVALIDARG;

	*d = 0;

	if ( This()->richEditOle )
	{
		mol::punk<ITextDocument> textDoc(This()->richEditOle);
		if ( textDoc )
		{
			mol::punk<ITextRange> range;
			long start = 0;
			long end = 0;
			HRESULT hr = textDoc->Range( start,start,&range);
			if ( range)
			{
				hr = range->Expand(tomStory,NULL);
				hr = range->GetEnd(&end);
				return range.queryInterface(d);				
			}		
		}
	}
	return S_OK;
}

HRESULT __stdcall RTFEditor::RTFDocument::get_Length( long* d)
{
	if (!d )
		return E_INVALIDARG;

	*d = 0;

	if ( This()->richEditOle )
	{
		mol::punk<ITextDocument> textDoc(This()->richEditOle);
		if ( textDoc )
		{
			mol::punk<ITextRange> range;
			long start = 0;
			long end = 0;
			HRESULT hr = textDoc->Range( start,start,&range);
			if ( range)
			{
				hr = range->Expand(tomStory,NULL);
				hr = range->GetEnd(&end);
				*d = end;
			}		
		}
	}
	return S_OK;
}

HRESULT __stdcall RTFEditor::RTFDocument::Range( long start, long end,  IDispatch** d)
{
	if (!d )
		return E_INVALIDARG;

	*d = 0;

	if ( This()->richEditOle )
	{
		mol::punk<ITextDocument> textDoc(This()->richEditOle);
		if ( textDoc )
		{
			mol::punk<ITextRange> range;
			HRESULT hr = textDoc->Range( start,end,&range);
			if ( range)
			{
				return range.queryInterface(d);				
			}		
		}
	}
	return S_OK;
}

HRESULT __stdcall RTFEditor::RTFDocument::get_Selection( IDispatch** d)
{
	if (!d )
		return E_INVALIDARG;

	*d = 0;

	if ( This()->richEditOle )
	{
		mol::punk<ITextDocument> textDoc(This()->richEditOle);
		if ( textDoc )
		{
			mol::punk<ITextSelection> selection;
			HRESULT hr = textDoc->GetSelection(&selection);
			if ( selection)
			{
				return selection.queryInterface(d);
			}		
		}
	}
	return S_OK;
}

HRESULT __stdcall RTFEditor::RichEditOleCallback::QueryAcceptData(LPDATAOBJECT lpdataobj, CLIPFORMAT FAR * lpcfFormat, DWORD reco,BOOL fReally, HGLOBAL hMetaPict)
{
	static CLIPFORMAT cf_DATAOBJ = ::RegisterClipboardFormat(_T("DataObject"));
	mol::punk<IEnumFORMATETC> enumFormat;

	if ( fReally == false )
	{
		return S_OK;
	}

	if ( !This()->richEditOle )
		return S_OK;

	LPSTORAGE store = 0;
	HRESULT hr = this->GetNewStorage(&store);
	if (FAILED(hr))
	{
		return S_OK;
	}
	

	FORMATETC formatEtc;
	formatEtc.cfFormat = 0;
	formatEtc.ptd = NULL;
	formatEtc.dwAspect = DVASPECT_CONTENT;
	formatEtc.lindex = -1;
	formatEtc.tymed = TYMED_NULL;

	mol::punk<IOleClientSite>	pClientSite;
	hr = This()->richEditOle->GetClientSite(&pClientSite);
	if (FAILED(hr))
	{
		return S_OK;
	}

	mol::punk<IUnknown> pUnk;
	CLSID clsid = CLSID_NULL;

	hr = ::OleCreateFromData( lpdataobj,IID_IUnknown,OLERENDER_DRAW,&formatEtc,pClientSite, store, (void**)&pUnk);					
	if (FAILED(hr))
	{
		return S_OK;
	}

	mol::punk<IOleObject> oleObject;
	hr = pUnk->QueryInterface(IID_IOleObject, (void**)&oleObject);
	if (FAILED(hr))
	{
		return S_OK;
	}

	::OleSetContainedObject(oleObject, TRUE);
	REOBJECT reobject = { sizeof(REOBJECT)};
	hr = oleObject->GetUserClassID(&clsid);
	if (FAILED(hr))
	{
		return S_OK;
	}

	reobject.clsid = clsid;
	reobject.cp = REO_CP_SELECTION;
	reobject.dvaspect = DVASPECT_CONTENT;
	reobject.dwFlags = REO_RESIZABLE | REO_BELOWBASELINE;
	reobject.dwUser = 0;
	reobject.poleobj = oleObject;
	reobject.polesite = pClientSite;
	reobject.pstg = store;
	SIZEL sizel = { 0 };
	reobject.sizel = sizel;

	This()->rtf_.sendMessage( EM_REPLACESEL, TRUE, (WPARAM)L"\n"); 
	hr = This()->richEditOle->InsertObject(&reobject);
	if (FAILED(hr))
	{
		return S_OK;
	}
    
	return S_FALSE;
}

HRESULT __stdcall RTFEditor::RichEditOleCallback::GetInPlaceContext(LPOLEINPLACEFRAME* lplpFrame, LPOLEINPLACEUIWINDOW* lplpDoc, LPOLEINPLACEFRAMEINFO lpFrameInfo)
{
	mol::punk<IOleClientSite>	pClientSite;
	HRESULT hr = This()->richEditOle->GetClientSite(&pClientSite);

	if ( lplpFrame )
	{
		moe()->axFrameSite->QueryInterface(IID_IOleInPlaceFrame,(void**)lplpFrame);
	}
	if ( lplpDoc )
	{
		pClientSite->QueryInterface(IID_IOleInPlaceUIWindow,(void**)lplpDoc);
	}
	if ( lpFrameInfo)
	{
		lpFrameInfo->cAccelEntries = 0;
		lpFrameInfo->fMDIApp = TRUE;
		lpFrameInfo->haccel = 0;
		lpFrameInfo->hwndFrame = *moe();
	}
	return S_OK;
}

HRESULT __stdcall RTFEditor::RichEditOleCallback::ShowContainerUI(BOOL fShow)
{
	if ( fShow)
	{
		
		mol::punk<IOleInPlaceFrame> frame;
		if ( moe()->axFrameSite )
		{
			moe()->axFrameSite.queryInterface(&frame);
			if ( frame )
			{
				frame->SetBorderSpace(0);
			}
		}

		ribbon()->setAppMode("Rtf");
		This()->rtf_.redraw();
	}
	else
	{
		ribbon()->setAppMode("Scintilla");
		if (!This()->shuttingDown_)
		{
			This()->rtf_.redraw();
		}
	}
	return S_OK;
}