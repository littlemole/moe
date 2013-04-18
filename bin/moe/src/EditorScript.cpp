#include "stdafx.h"
#include "EditorScript.h"
#include "editor.h"
#include "moe.h"
#include "Docs.h"
#include "xmlui.h"
#include "ribbonres.h"

EditorScript::EditorScript(void)
	:editor_(0),debugger_(0)
{
}

EditorScript::EditorScript(Editor* e)
	:editor_(e),debugger_(0)
{
	editor_ = e;
	debugger_ = e->debugger_;
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

	//moe()->scriptHost->eval(engine,script.toString(),editor_->sci);
	Script::CreateInstance()->eval(engine,script.toString(),editor_->sci);

	mol::bstr out;
	moe()->stdOut(&out);
	if(out)
	{
		editor_->annotation_->SetText(0,out);
	}
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

	if ( debugger_&& debugger_->suspended())
	{		
		mol::Ribbon::ribbon()->mode(8);
		debugger_->resume();
		return;
	}

	if (debugger_)
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

	debugger_= ScriptDebugger::CreateInstance( *moe(), script.toString(), filename.toString() );
	debugger_->addNamedObject((IMoe*)moe(), _T("moe"),SCRIPTITEM_ISVISIBLE | SCRIPTITEM_GLOBALMEMBERS | SCRIPTITEM_ISSOURCE);
	debugger_->update_breakpoints(s);
	debugger_->OnScriptThread = mol::events::event_handler(&Editor::OnScriptThread,editor_);
	debugger_->OnScriptThreadDone = mol::events::event_handler(&Editor::OnScriptThreadDone,editor_);
	debugger_->execute( SCRIPTTEXT_ISVISIBLE);
	editor_->debugger_= debugger_;

	mol::Ribbon::ribbon()->mode(8);
}

void EditorScript::debugScriptStepIn()
{
	if ( !debugger_)
		return;

	editor_->line_->Highlite(-1);
	editor_->annotation_->ClearAll();

	if ( !debugger_->suspended())
		return;

	debugger_->resume(BREAKRESUMEACTION_STEP_INTO);

	mol::Ribbon::ribbon()->mode(9);
}

void EditorScript::debugScriptStepOver()
{
	if ( !debugger_)
		return;

	editor_->line_->Highlite(-1);
	editor_->annotation_->ClearAll();

	if ( !debugger_->suspended())
		return;

	debugger_->resume(BREAKRESUMEACTION_STEP_OVER);

	mol::Ribbon::ribbon()->mode(9);
}

void EditorScript::debugScriptStepOut()
{
	if ( !debugger_)
		return;

	editor_->line_->Highlite(-1);
	editor_->annotation_->ClearAll();

	if ( !debugger_->suspended())
		return;

	debugger_->resume(BREAKRESUMEACTION_STEP_OUT);

	mol::Ribbon::ribbon()->mode(9);
}

void EditorScript::debugScriptStop()
{
	if ( !debugger_)
		return;

	editor_->line_->Highlite(-1);
	editor_->annotation_->ClearAll();

	debugger_->cause_break();

	mol::Ribbon::ribbon()->mode(9);
}

void EditorScript::debugScriptQuit()
{
	if ( !debugger_)
		return;

	debugDlg()->show(SW_HIDE);

	editor_->line_->Highlite(-1);

	mol::bstr out;
	moe()->stdOut(&out);
	if(out)
	{
		editor_->annotation_->SetText(0,out);
	}

	mol::Ribbon::ribbon()->mode(1);

	if ( debugger_->suspended())
	{
		debugger_->resume(BREAKRESUMEACTION_ABORT);
	}

	debugger_->import->Quit();
	debugger_= 0;
}


void EditorScript::onDebugExpressionEval( mol::string result)
{
	debugDlg()->setDlgItemText(IDC_EDIT_DEBUG_RESULT,result.c_str());
}

void EditorScript::debugScriptEval()
{
	if(!debugger_)
		return;
	
	debugger_->OnExpressionEvaluated = mol::events::event_handler(&EditorScript::onDebugExpressionEval);

	mol::string code;
	debugDlg()->getDlgItemText(IDC_EDIT_DEBUG_EXP,code);

	if ( code.empty() )
		return;

	if ( !debugger_)
		return;

	debugger_->eval_expression(code);				
}



void EditorScript::scriptThread( int line, mol::string error )
{
	mol::punk<IEnumDebugStackFrames> frames;
	if( S_OK == debugger_->frames(&frames) && frames )
	{
		// update variable window
		debugDlg()->update_variables(frames);
	}

	mol::ostringstream oss;
	if ( !error.empty() )
	{
		oss << _T("line: ") << (line+1) << _T(" ");
		oss << error;
		oss << std::endl;
	}

	mol::invoke( boost::bind( &Editor::OnScriptThread, editor_, line, oss.str() ) );
	return;
	
}


void EditorScript::scriptThread2( int line, mol::string error )
{
	if ( !editor_->sci )
		return;

	ODBGS1("OnScriptThread:",line);

	debugDlg()->show( editor_->debugger_->suspended() ? SW_SHOW : SW_HIDE );

	editor_->annotation_->ClearAll();
	if ( !error.empty() && line >= 0 )
	{
		editor_->annotation_->SetText( line, mol::bstr(error) );
	}

	editor_->line_->Goto(line);
	editor_->line_->Highlite(line);

	mol::Ribbon::ribbon()->mode(9);
	ODBGS1("Leaving OnScriptThread:",line);
}



void EditorScript::scriptThreadDone()
{
	editor_->debugger_= 0;

	if ( editor_->sci)
		editor_->line_->Highlite(-1);

	mol::bstr out;
	moe()->stdOut(&out);
	if(out)
	{
		editor_->annotation_->SetText(0,out);
	}

	mol::Ribbon::ribbon()->mode(1);
}
