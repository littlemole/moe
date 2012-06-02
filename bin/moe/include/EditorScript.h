#pragma once

#include "shared.h"
#include "resource.h"
#include "MoeBar.h"
#include "win/io.h"

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

	void scriptThread( int line, IRemoteDebugApplicationThread* remote,IActiveScriptError* pError);
	void scriptThread2( int line, IRemoteDebugApplicationThread* remote,IActiveScriptError* pError);

	void scriptThreadDone();

private:
	Editor* editor_;
};

