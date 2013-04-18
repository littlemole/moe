#pragma once

#include "shared.h"
#include "ThreadScript.h"

class Editor;

class EditorScript
{
public:
	EditorScript(void);
	EditorScript(Editor* e);
	~EditorScript(void);

	void execScript();
	void execForm(  );

	void debugScriptGo();
	void debugScriptStepIn();
	void debugScriptStepOver();
	void debugScriptStepOut();
	void debugScriptStop();
	void debugScriptQuit();
	void debugScriptEval();

	void scriptThread( int line, mol::string error);
	void scriptThread2( int line, mol::string error);

	void scriptThreadDone();


private:
	Editor* editor_;
	ScriptDebugger::Instance* debugger_;
	static void onDebugExpressionEval(mol::string result);

};

