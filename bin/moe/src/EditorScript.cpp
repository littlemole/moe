#include "stdafx.h"
#include "EditorScript.h"
#include "editor.h"
#include "moe.h"
#include "widgets.h"
#include "Docs.h"
#include "moebar.h"
#include "xmlui.h"
#include "ribbonres.h"
#include "ThreadScript.h"
#include "ActivDbg.h"

EditorScript::EditorScript(void)
{
}

EditorScript::EditorScript(Editor* e)
{
	editor_ = e;
}


EditorScript::~EditorScript(void)
{
}

void EditorScript::execScript()
{
	if ( !editor_->sci )
		return;

	mol::bstr filename;
	if ( S_OK != editor_->props_->get_Filename(&filename) )
		return ;

	mol::string engine = engineFromPath(filename.tostring());
	if ( engine == _T("") )
		return ;

	mol::bstr script;
	if ( S_OK != editor_->text_->GetText(&script) )
		return ;

	scriptlet()->eval(engine,script.toString(),editor_->sci);

	mol::bstr stdOut;
	moe()->stdOut(&stdOut);
	long lines = 0;
	editor_->line_->get_Count(&lines);
	lines = lines == 0 ? 0 : lines -1;
	editor_->annotation_->SetText(lines,stdOut);
}


void EditorScript::execForm(  )
{
	if ( !editor_->sci )
		return;

	mol::bstr filename;
	editor_->props_->get_Filename(&filename);

	editor_->saving_ = true;
	editor_->sci->Save();
	editor_->lastWriteTime_ = getLastWriteTime( filename.toString() );
	editor_->saving_ = false;

	mol::punk<IMoeDocument> doc;
	docs()->OpenHtmlFrame(filename,&doc);
}

void EditorScript::debugScriptGo()
{
	if ( !editor_->sci )
		return;

	debugDlg()->show(SW_HIDE);

	editor_->line_->Highlite(-1);
	editor_->annotation_->ClearAll();

	if ( editor_->remote_ )
	{		
		mol::Ribbon::ribbon()->mode(8);
	
		mol::punk<IRemoteDebugApplication> app;

		HRESULT hr = editor_->remote_->GetApplication(&app);
		if ( hr == S_OK && app ) 
		{
			hr = app->ResumeFromBreakPoint( editor_->remote_, BREAKRESUMEACTION_CONTINUE, ERRORRESUMEACTION_AbortCallAndReturnErrorToCaller );
		}

		editor_->remote_.release();
		return;
	}

	if (editor_-> ts_ )
	{
		::MessageBox( *moe(), _T("Script running already!"), _T("warning!"), MB_ICONERROR );
		return;
	}

	mol::bstr filename;
	if ( S_OK != editor_->props_->get_Filename(&filename) )
		return ;

	mol::bstr script;
	if ( S_OK != editor_->text_->GetText(&script) )
		return ;

	mol::string engine = engineFromPath(filename.tostring());
	if ( engine == _T("") )
		return ;

	mol::SafeArray<VT_I4> sf;
	std::set<int> s;

	if ( S_OK == editor_->markers_->GetMarkers(&sf) )
	{
		mol::SFAccess<long> sfa(sf);
		for ( int i = 0; i < sfa.size(); i++ )
		{
			s.insert(sfa[i]);
		}
	}

	editor_->ts_ = ThreadScript::CreateInstance( *moe(), script.toString(), filename.toString() );
	editor_->ts_->addNamedObject((IMoe*)moe(), _T("moe"),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_GLOBALMEMBERS | SCRIPTITEM_ISSOURCE);
	editor_->ts_->update_breakpoints(s);
	editor_->ts_->OnScriptThread = mol::events::event_handler(&Editor::OnScriptThread,editor_);
	editor_->ts_->OnScriptThreadDone = mol::events::event_handler(&Editor::OnScriptThreadDone,editor_);
	editor_->ts_->execute( SCRIPTTEXT_ISVISIBLE);

	mol::Ribbon::ribbon()->mode(8);

}

void EditorScript::debugScriptStepIn()
{
	if ( !editor_->sci )
		return;

	editor_->line_->Highlite(-1);
	editor_->annotation_->ClearAll();

	if ( !editor_->remote_)
		return;

	mol::punk<IRemoteDebugApplication> app;

	HRESULT hr = editor_->remote_->GetApplication(&app);
	if ( hr == S_OK && app ) 
	{
		hr = app->ResumeFromBreakPoint( editor_->remote_, BREAKRESUMEACTION_STEP_INTO, ERRORRESUMEACTION_AbortCallAndReturnErrorToCaller );
	}

	editor_->remote_.release();

	mol::Ribbon::ribbon()->mode(9);

}

void EditorScript::debugScriptStepOver()
{
	if ( !editor_->sci )
		return;

	editor_->line_->Highlite(-1);
	editor_->annotation_->ClearAll();

	if ( !editor_->remote_)
		return;

	mol::punk<IRemoteDebugApplication> app;

	HRESULT hr = editor_->remote_->GetApplication(&app);
	if ( hr == S_OK && app ) 
	{
		hr = app->ResumeFromBreakPoint( editor_->remote_, BREAKRESUMEACTION_STEP_OVER, ERRORRESUMEACTION_AbortCallAndReturnErrorToCaller );
	}

	editor_->remote_.release();

	mol::Ribbon::ribbon()->mode(9);
}

void EditorScript::debugScriptStepOut()
{
	if ( !editor_->sci )
		return;

	editor_->line_->Highlite(-1);
	editor_->annotation_->ClearAll();

	if ( !editor_->remote_)
		return;

	mol::punk<IRemoteDebugApplication> app;

	HRESULT hr = editor_->remote_->GetApplication(&app);
	if ( hr == S_OK && app ) 
	{
		hr = app->ResumeFromBreakPoint( editor_->remote_, BREAKRESUMEACTION_STEP_OUT, ERRORRESUMEACTION_AbortCallAndReturnErrorToCaller );
	}

	editor_->remote_.release();

	mol::Ribbon::ribbon()->mode(9);
}

void EditorScript::debugScriptStop()
{
	if ( !editor_->sci )
		return;

	editor_->line_->Highlite(-1);
	editor_->annotation_->ClearAll();

	if ( !editor_->ts_ )
		return;

	editor_->ts_->cause_break();

	mol::Ribbon::ribbon()->mode(9);
}

void EditorScript::debugScriptQuit()
{
	if ( !editor_->sci )
		return;

	debugDlg()->show(SW_HIDE);

	editor_->line_->Highlite(-1);

	mol::Ribbon::ribbon()->mode(1);

	if ( !editor_->remote_)
		return;


	mol::punk<IRemoteDebugApplication> app;

	HRESULT hr = editor_->remote_->GetApplication(&app);
	if ( hr == S_OK && app ) 
	{
		hr = app->ResumeFromBreakPoint( editor_->remote_, BREAKRESUMEACTION_ABORT, ERRORRESUMEACTION_AbortCallAndReturnErrorToCaller );
	}

	editor_->remote_.release();
}

void EditorScript::scriptThread( int line, IRemoteDebugApplicationThread* remote, IActiveScriptError* pError )
{
	editor_->lasterror_ = _T("");

	// get stack frame
	DebugStackFrameDescriptor	desc;
	::ZeroMemory(&desc,sizeof(DebugStackFrameDescriptor));

	mol::punk<IEnumDebugStackFrames> frames;
	if ( remote )
	{
		HRESULT hr = remote->EnumStackFrames( &frames );
		if ( S_OK == hr && frames )
		{
			// update variable window
			debugDlg()->update_variables(frames);
		}
	}
	mol::ostringstream oss;
	if ( pError )
	{
		oss << _T("line: ") << (line+1) << _T(" ");

		EXCEPINFO ex;
		pError->GetExceptionInfo(&ex);

		DWORD context;
		ULONG line;
		LONG pos;
		pError->GetSourcePosition(&context,&line,&pos);
		
		mol::punk<IActiveScriptErrorDebug> de(pError);
		if ( de )
		{
			mol::punk<IDebugStackFrame> f;
			de->GetStackFrame(&f);

			if ( f )
			{
				mol::bstr e;
				f->GetDescriptionString(TRUE,&e);

				if ( e )
					oss << e.toString() << std::endl;
			}
		}

		if ( ex.bstrDescription )
		{
			oss << mol::bstr(ex.bstrDescription).toString();
		}
		oss << std::endl;
		editor_->lasterror_ = oss.str();
	}

	if ( remote )
		remote->Release();
	if ( pError)
		pError->Release();

	mol::invoke( boost::bind( &Editor::OnScriptThread, editor_, line, remote, pError ) );
	return;
	
}


void EditorScript::scriptThread2( int line, IRemoteDebugApplicationThread* remote, IActiveScriptError* pError )
{
	if ( !editor_->sci )
		return;

	ODBGS1("OnScriptThread:",line);

	editor_->remote_.release();
	editor_->remote_ = remote;

	debugDlg()->remote = remote;
	debugDlg()->show( remote ? SW_SHOW : SW_HIDE );

	editor_->annotation_->ClearAll();
	if ( !editor_->lasterror_.empty() && line >= 0 )
	{
		editor_->annotation_->SetText( line, mol::bstr(editor_->lasterror_) );
	}

	editor_->line_->Goto(line);
	editor_->line_->Highlite(line);

	mol::Ribbon::ribbon()->mode(9);
	ODBGS1("Leaving OnScriptThread:",line);
}



void EditorScript::scriptThreadDone()
{
	debugDlg()->remote.release();
	debugDlg()->show(SW_HIDE);
	editor_->ts_ = 0;

	if ( editor_->sci)
		editor_->line_->Highlite(-1);

	mol::Ribbon::ribbon()->mode(1);
}
